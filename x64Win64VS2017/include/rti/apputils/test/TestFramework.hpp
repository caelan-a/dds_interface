/*
 (c) Copyright, Real-Time Innovations, 2016-.
 All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef HPP_APPUTILS_FRAMEWORK_HPP_
#define HPP_APPUTILS_FRAMEWORK_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <exception>
#include <ctime>
#include <list>

#include "test/test_setting.h"
#include "osapi/osapi_heap.h"
#include "osapi/osapi_process.h"
#ifndef property_propertyNames_h
  #include "property/property_propertyNames.h"
#endif
#include "pres/pres_common.h"

#include <string>

#include "rti/test/generic_tests.hpp"
#include "rti/test/AbstractDomainTester.hpp"
#include "rti/test/Tester.hpp"
#include "rti/test/utilities.hpp"
#include "rti/apputils/util/Path.hpp"
#include "rti/apputils/util/Utils.hpp"
#include "dds/core/Time.hpp"

#include "dds/dds.hpp"

#include "dds/pub/DataWriter.hpp"
#include "dds/sub/DataReader.hpp"
#include "dds/pub/Publisher.hpp"
#include "rti/core/ListenerBinder.hpp"

namespace rti { namespace apputils { namespace test {

/**
 * A set of utility functions to use in the tests.
 */
class TestUtils {
public:

    static std::string get_executable_path(const RTITestSetting *settings) {
        char path[RECORDER_FILE_PATH_MAX_LENGTH] = "";

        RTI_TEST_ASSERT(
                RTIOsapiUtility_getExecutablePath(
                        path,
                        RECORDER_FILE_PATH_MAX_LENGTH,
                        settings->execPath));

        return std::string(path);
    }

    static std::string get_resource_path(
            const RTITestSetting *settings,
            const std::string& file)
    {
        char resource_path[RECORDER_FILE_PATH_MAX_LENGTH] = "";

        RTI_TEST_ASSERT(
                RTITestSetting_getFullResourcePathFileName(
                        settings,
                        resource_path,
                        file.c_str()));

        return std::string(resource_path);
    }

    /**
     * Build a multi-file string, prepending the default DDS QoS file to the
     * file name passed as a parameter. Recall that files are separated by the
     * ';' character.
     */
    static const std::string build_config_file(
            const RTITestSetting *settings,
            const std::string& config_file_name)
    {
        std::stringstream config_file_stream;
        config_file_stream << get_resource_path(
                settings,
                "/xml/USER_QOS_PROFILES.xml");
        config_file_stream << ";";
        config_file_stream << get_resource_path(settings, config_file_name);
        return config_file_stream.str();
    }

};

class ParticipantBuiltinTopicListener :
        public dds::all::NoOpDataReaderListener<
                dds::topic::ParticipantBuiltinTopicData>
{
public:
    ParticipantBuiltinTopicListener() { }

    void on_data_available(
            dds::sub::DataReader<dds::topic::ParticipantBuiltinTopicData>& reader)
    {
        dds::sub::LoanedSamples<
                dds::topic::ParticipantBuiltinTopicData> samples = reader.read();
        dds::domain::DomainParticipant local_participant =
                reader.subscriber().participant();

        char current_process_id_as_string[64] = {0};
        RTIOsapiUtility_snprintf(
                current_process_id_as_string,
                64,
                "%llu",
                RTIOsapiProcess_getId());
        dds::sub::LoanedSamples<
                dds::topic::ParticipantBuiltinTopicData>::iterator sample_it =
                        samples.begin();
        const std::string property_key(PROPERTY_NAME_DDS_SYS_INFO_PROCESS_ID);
        for (; sample_it != samples.end(); ++sample_it) {
            if (sample_it->info().valid()
                    && sample_it->info().state().instance_state()
                            == dds::sub::status::InstanceState::alive()
                    && sample_it->info().state().view_state()
                            == dds::sub::status::ViewState::new_view()) {
                /*
                 * Juanlu: if we don't check the existence of the property first
                 * then the get() method will throw, printing the message:
                 * on_data_available:!property does not exist
                 */
                if (sample_it->data()->property().exists(property_key)) {
                    std::string process_property =
                            sample_it->data()->property().get(property_key);
                    if (!process_property.empty()
                            && process_property != current_process_id_as_string) {
                        dds::domain::ignore(
                                local_participant,
                                sample_it->info().instance_handle());
                    }
                } else {
                    /* Participants that do not contain this property are not
                     * part of the test */
                    dds::domain::ignore(
                            local_participant,
                            sample_it->info().instance_handle());
                }
            }
        }
    }
};

/**
 * Utility class wrapping random number generation. Currently based on std::rand
 * and a seed, that is output to a file on error. This allows for repeatability
 * of the execution.
 * The seed used to execute will be stored in a file called .seed, in the
 * current working directory. This file will be looked for upon construction and
 * if present, the value of the seed will be used as a seed to the std::rand
 * function.
 * Manually delete the .seed file if you want to resume non-repeatable
 * execution.
 * In the future, when we integrate with newer C++ standards, explore the
 * possiblity of using std::random_device instead.
 */
class RandGenerator {
public:

    static const std::string& seed_file_name()
    {
        static std::string SEED_FILE_NAME_STR(".seed");
        return SEED_FILE_NAME_STR;
    }

    RandGenerator() : seed_(std::time(NULL)), error_(true)
    {
        rti::apputils::util::Path seed_file(seed_file_name());
        if (seed_file.exists()) {
            std::ifstream seed_f_stream((const char *) seed_file);
            seed_f_stream >> seed_;
        }
        RTIOsapiUtility_srandWithSeed(seed_);
    }

    ~RandGenerator()
    {
        rti::apputils::util::Path seed_file(seed_file_name());
        if (!seed_file.exists()) {
            if (error_) {
                std::ofstream seed_f_stream((const char *) seed_file);
                seed_f_stream << seed_;
                seed_f_stream.close();
            }
        }
    }

    int32_t next(int32_t max) {
        int32_t random = RTIOsapiUtility_rand();
        return random % max;
    }

    int32_t next(int32_t min, int32_t max) {
        int32_t random = RTIOsapiUtility_rand();
        return min + random % (max - min + 1);
    }

    void set_error(bool error)
    {
        error_ = error;
    }

private:

    uint32_t seed_;

    bool error_;

};

/**
 * Utility class designed to make sure that we remove test files after a test is
 * executed. This substitutes the old pattern using explicit calls to
 * RTIOsapi_removeFile() at the end of the test, that are not reached when the
 * test exits abnormally (fails).
 *
 * This class is supposed to be used with the following pattern:
 * 1) Create the TestFileSet object at the beginning of the test.
 * 2) Add the files and directories for which we want to link destruction to the
 *    destruction of the object itself.
 * 3) Add a call to set_remove(true). If this call is added at the end of the
 *    test code, then if the test fails no files are deleted. This allows for
 *    inspection to determine the cause of the error. If added at any other
 *    point in the code, the files and directories will be deleted even if any
 *    test code after that point fails.
 *    We generally add calls to set_remove(true) when
 */
class TestFileSet {
public:

    TestFileSet() : remove_(false)
    {
    }

    ~TestFileSet()
    {
        if (remove_) {
            std::list<rti::apputils::util::Path>::iterator it = files_.begin();
            for (; it != files_.end(); it++) {
                if (it->exists()) {
                    RTIOsapi_removeFile(*it);
                }
            }
            it = directories_.begin();
            for (; it != directories_.end(); it++) {
                if (it->exists()) {
                    rti::apputils::util::Path::remove_directory(*it);
                }
            }
        }
    }

    void add_file(const rti::apputils::util::Path& file)
    {
        files_.push_back(file);
    }

    /**
     * Important note: when adding directories and one contains the other or
     * others, add the deeper directories first.
     */
    void add_directory(const rti::apputils::util::Path& directory)
    {
        directories_.push_back(directory);
    }

    /**
     * @brief Set or unset the boolean flag controlling the deletion of
     *        directories and files associated with this TestFileSet.
     *
     * @param remove The value of the remove flag. This flag is false when the
     *               TestFileSet object is created. Setting it to true will
     *               enable automatic deletion of the associated directories and
     *               files.
     */
    void set_remove(bool remove)
    {
        remove_ = remove;
    }

private:

    std::list<rti::apputils::util::Path> files_;
    std::list<rti::apputils::util::Path> directories_;
    bool remove_;
};

#define TEST_TYPES_FILE_NAME "RecorderServiceTestTypes.xml"

/**
 * A singleton abstraction that generates a new directory (in most platforms,
 * inside the OS's temporary directory) for the tests to create by-products
 * during their execution.
 * If the tests pass, the directory will be deleted before the instance is
 * destroyed.
 */
class TestWorkspaceProvider {
public:

    static TestWorkspaceProvider& init(RTITestSetting& setting)
    {
        static TestWorkspaceProvider singleton_(setting);
        return singleton_;
    }

    static const std::string& get()
    {
        /*
         * The recording service tests generate byproducts in the form of
         * database files. This can be problematic when running, for example,
         * the tester application from the same tree, at the same time. We're
         * going to provide a mechanism here where all the by-product files will
         * be created inside a temporary working directory. We'll modify all the
         * test configurations so that they define filenames based on an
         * environment variable defining a directory that will be unique per
         * execution.
         */
        static std::string WORKSPACE_DIR;
        if (WORKSPACE_DIR.empty()) {
    #ifdef RTI_WIN32
            std::string placeholder;
    #include "windows.h"
            char placeholder_str[MAX_PATH];
            RTINtpTime now;
            RTIOsapiUtility_getTime(&now);
            DDS_Duration_t duration;
            DDS_Duration_from_ntp_time(&duration, &now);
            dds::core::Duration cpp_duration(duration.sec, duration.nanosec);
            char temp_path[MAX_PATH];
            // Get the temporary directory
            uint32_t size = GetTempPath(MAX_PATH, temp_path);
            RTI_TEST_ASSERT(size <= MAX_PATH && size != 0);
            placeholder.append(temp_path);
            placeholder.append("Recorder4Tester_");
            std::ostringstream int_str;
            int_str << cpp_duration.to_millisecs();
            placeholder.append(int_str.str());
            RTI_TEST_ASSERT(CreateDirectory(placeholder.c_str(), NULL));
            RTI_TEST_ASSERT(RTIOsapiUtility_normalizePath(
                    placeholder_str,
                    MAX_PATH,
                    placeholder.c_str()));
            WORKSPACE_DIR.append(placeholder_str);
    #elif defined RTI_QNX
    #include <stdlib.h>
            /*
             * Because we must use the NFS until we have local memory in place,
             * we need the full path of the current directory. To get it, we
             * use the getcwd function. The max_path_size is set to 1024, as
             * the QNX documentation says: www.qnx.com/developers/docs/7.0.0/#com.qnx.doc.neutrino.user_guide/topic/limits_NFS2.html
             * The tmpl_size variable sets the maximum size of the temporary
             * directory string. Given that the template of the path requires
             * 37 characters, we must save 38 characters from the max size
             * to append the temporary directory.
             */
            const int tmplt_size = 38;
            int max_path_size = 1024;
            char tmpdir[] = "/recorder_tmp/";
            char tmplt[] = "Recorder4Tester_XXXXXXX";
            char current_dir[max_path_size-tmplt_size];
            char tmplt_full_path[max_path_size]="";
            char *tmp_dirname;
            getcwd(current_dir,max_path_size-tmplt_size);
            RTI_TEST_ASSERT(current_dir != NULL);
            strcat(tmplt_full_path,current_dir);
            strcat(tmplt_full_path,tmpdir);
            mkdir(tmplt_full_path, S_IRWXU | S_IRWXG | S_IRWXO);
            RTI_TEST_ASSERT(tmplt_full_path != NULL);
            strcat(tmplt_full_path,tmplt);
            tmp_dirname = mkdtemp(tmplt_full_path);
            RTI_TEST_ASSERT(tmp_dirname != NULL);
            WORKSPACE_DIR.append(tmp_dirname);
    #else
    #include <stdlib.h>
            char tmplt[] = "/tmp/Recorder4Tester_XXXXXX";
            char *tmp_dirname = mkdtemp(tmplt);
            RTI_TEST_ASSERT(tmp_dirname != NULL);
            WORKSPACE_DIR.append(tmp_dirname);
    #endif
        }
        return WORKSPACE_DIR;
    }

    static const std::string& resource_path_var_name()
    {
        static const std::string RESOURCE_PATH_VAR_NAME(
                "RTI_RECORDING_RESOURCE_DIR");
        return RESOURCE_PATH_VAR_NAME;
    }

    static const std::string& working_dir_var_name()
    {
        static const std::string WORKING_DIR_VAR_NAME(
                "RTI_RECORDING_WORKING_DIR");
        return WORKING_DIR_VAR_NAME;
    }

    static const std::string& exec_dir_var_name()
    {
        static const std::string EXEC_DIR_VAR_NAME("RTI_RECORDING_EXEC_DIR");
        return EXEC_DIR_VAR_NAME;
    }

    static const std::string& file_expr_var_name()
    {
        static const std::string FILE_EXPR_VAR_NAME("RTI_RECORDING_FILE_EXPR");
        return FILE_EXPR_VAR_NAME;
    }

    static const std::string& rollover_enabled_var_name()
    {
        static const std::string ROLLOVER_VAR_NAME(
                "RTI_RECORDING_ROLLOVER_ENABLED");
        return ROLLOVER_VAR_NAME;
    }

    static const std::string& storage_format_var_name()
    {
        static const std::string STORAGE_FORMAT_VAR_NAME(
                "RTI_RECORDING_STORAGE_FORMAT");
        return STORAGE_FORMAT_VAR_NAME;
    }

    static const std::string& out_storage_format_var_name()
    {
        static const std::string OUT_STORAGE_FORMAT_VAR_NAME(
                "RTI_RECORDING_OUT_STORAGE_FORMAT");
        return OUT_STORAGE_FORMAT_VAR_NAME;
    }

    static const std::string& cdr_representation_var_name()
    {
        static const std::string CDR_REPRESENTATION_VAR_NAME(
                "RTI_RECORDING_CDR_REPRESENTATION");
        return CDR_REPRESENTATION_VAR_NAME;
    }

    static const std::string& overwrite_policy_var_name()
    {
        static const std::string OVERWRITE_POLICY_VAR_NAME(
                "RTI_RECORDING_OVERWRITE_POLICY");
        return OVERWRITE_POLICY_VAR_NAME;
    }

    static const std::string& instance_indexing_kind_var_name()
    {
        static const std::string INSTANCE_INDEXING_VAR_NAME(
                "RTI_RECORDING_INSTANCE_INDEX_TIMESTAMP_KIND");
        return INSTANCE_INDEXING_VAR_NAME;
    }

    static const std::string& instance_indexing_enabled_var_name()
    {
        static const std::string INSTANCE_INDEXING_ENABLED_VAR_NAME(
                "RTI_RECORDING_INSTANCE_INDEX_ENABLED");
        return INSTANCE_INDEXING_ENABLED_VAR_NAME;
    }

    static const std::string& range_start_sec_var_name()
    {
        static const std::string RANGE_START_SEC_VAR_NAME(
                "RTI_RECORDING_RANGE_START_SEC");
        return RANGE_START_SEC_VAR_NAME;
    }

    static const std::string& range_start_nanosec_var_name()
    {
        static const std::string RANGE_START_NANOSEC_VAR_NAME(
                "RTI_RECORDING_RANGE_START_NANOSEC");
        return RANGE_START_NANOSEC_VAR_NAME;
    }

    static const std::string& range_end_sec_var_name()
    {
        static const std::string RANGE_END_SEC_VAR_NAME(
                "RTI_RECORDING_RANGE_END_SEC");
        return RANGE_END_SEC_VAR_NAME;
    }

    static const std::string& range_end_nanosec_var_name()
    {
        static const std::string RANGE_END_NANOSEC_VAR_NAME(
                "RTI_RECORDING_RANGE_END_NANOSEC");
        return RANGE_END_NANOSEC_VAR_NAME;
    }

    static const std::string& playback_sample_order_var_name()
    {
        static const std::string PLAYBACK_SAMPLE_ORDER(
                "RTI_RECORDING_PLAYBACK_SAMPLE_ORDER");
        return PLAYBACK_SAMPLE_ORDER;
    }

    static const std::string& allow_topic_filter_var_name()
    {
        static const std::string ALLOW_TOPIC_FILTER_VAR_NAME(
                "RTI_RECORDING_ALLOW_TOPIC_FILTER");
        return ALLOW_TOPIC_FILTER_VAR_NAME;
    }

    static const std::string& deny_topic_filter_var_name()
    {
        static const std::string DENY_TOPIC_FILTER_VAR_NAME(
                "RTI_RECORDING_DENY_TOPIC_FILTER");
        return DENY_TOPIC_FILTER_VAR_NAME;
    }

    static const std::string& input_sql_init_var_name()
    {
        static const std::string INPUT_SQL_INIT_VAR_NAME(
                "RTI_RECORDING_INPUT_SQL_INIT");
        return INPUT_SQL_INIT_VAR_NAME;
    }

    static const std::string& output_sql_init_var_name()
    {
        static const std::string OUTPUT_SQL_INIT_VAR_NAME(
                "RTI_RECORDING_OUTPUT_SQL_INIT");
        return OUTPUT_SQL_INIT_VAR_NAME;
    }

    /**
     * Copy a file into the current test workspace directory.
     *
     * @param origin Path to the original file to be copied. Can be relative or
     *               absolute.
     * @param destination_relative The destination file, relative to the current
     *               test workspace directory.
     */
    static void copy_file(
            const std::string& origin,
            const std::string& destination_relative)
    {
        rti::apputils::util::Path origin_path(origin);
        rti::apputils::util::Path destination_abs_path(get());
        destination_abs_path += destination_relative;
        origin_path.copy_to(destination_abs_path);
    }

    /**
     * Copy a file into the current working directory.
     *
     * @param origin Path to the origin file to be copied.
     * @param destination_filename The name of the origin file in the current
     *               working directory after being copied.
     */
#if !defined(RTI_INTY)
    static rti::apputils::util::Path copy_file_to_cwd(
            const std::string& origin,
            const std::string& destination_filename)
    {
        rti::apputils::util::Path destination(
                rti::apputils::util::Path::cwd());
        destination += destination_filename;
        rti::apputils::util::Path origin_path(origin);
        origin_path.copy_to(destination);
        return destination;
    }
#endif

    static std::string go_to()
    {
#ifdef RTI_WIN32
        char current_wd[MAX_PATH] = "";
        RTI_TEST_ASSERT(GetCurrentDirectory(MAX_PATH, current_wd));
        RTI_TEST_ASSERT(SetCurrentDirectory(get().c_str()));
#else
        char current_wd[PATH_MAX] = "";
        RTI_TEST_ASSERT(getcwd(current_wd, sizeof(current_wd)) != NULL);
        RTI_TEST_ASSERT(chdir(get().c_str()) == 0);
#endif
        return std::string(current_wd);
    }

    static void come_back(const std::string& current_working_dir)
    {
#ifdef RTI_WIN32
        RTI_TEST_ASSERT(SetCurrentDirectory(current_working_dir.c_str()));
#else
        RTI_TEST_ASSERT(chdir(current_working_dir.c_str()) == 0);
#endif
    }

    void remove_dir(bool remove)
    {
        remove_dir_ = remove;
    }

private:

    bool remove_dir_;

    /**
     * Initialize the environment variables needed in the XML files we load.
     * They are necessary even if we're not using them directly in the
     * configuration we're loading but are defined in the file.
     * Note for Windows platforms: internally, the OSAPI function to set an
     * environment variable uses putenv(). On Windows, this function will delete
     * the environment variable if an empty string is passed as its value (the
     * right side of the <NAME>=<VALUE> expression). Thus, we cannot use an
     * empty string for environment variables that are to be 'empty'. We're
     * using a whitespace character instead.
     */
    TestWorkspaceProvider(RTITestSetting& setting) :
        remove_dir_(false)
    {
        /* Set resource path environment variable */
        char resource_path_c_str[RTI_TEST_MAX_FILE_NAME_LENGTH + 1] = "";
        RTI_TEST_ASSERT(RTITestSetting_getFullResourcePathFileName(
                &setting,
                resource_path_c_str,
                ""));
        rti::apputils::util::Path resource_path(resource_path_c_str);
        RTITestLog_freeForm(
                RTI_LOG_BIT_EXCEPTION,
                "Working directory for the tests: %s\n", get().c_str());
        /* Copy the types XML file to the working directory */
        rti::apputils::util::Path types_file_path(resource_path);
        types_file_path += "xml/" TEST_TYPES_FILE_NAME;
        RTI_TEST_ASSERT(types_file_path.exists());
        copy_file(types_file_path, TEST_TYPES_FILE_NAME);
    }

    ~TestWorkspaceProvider()
    {
        if (remove_dir_) {
            rti::apputils::util::Path::remove_directory(
                    TestWorkspaceProvider::get());
        }
    }
};

/**
 * This class is used to change the current working directory to the test
 * workspace. It ensures that when it gets out of scope, the app returns to the
 * previous working directory.
 */
class TestDirectoryChangeGuard {
public:

    TestDirectoryChangeGuard()
    {
        cwd_ = TestWorkspaceProvider::go_to();
    }

    ~TestDirectoryChangeGuard()
    {
        TestWorkspaceProvider::come_back(cwd_);
    }

private:

    std::string cwd_;
};

/**
 * Utility class designed to make sure that we remove test directory after a test is
 * executed. This substitutes the old pattern using explicit calls to
 * RTIOsapi_removeFile() at the end of the test, that are not reached when the
 * test exits abnormally (fails)
 */
class TestScopedDirectory {
public:

    TestScopedDirectory()
    {
    }

    void set(const std::string& directory)
    {
        directory_ = directory;
    }

    ~TestScopedDirectory() {
        if (directory_.length() != 0) {
            RTIOsapiUtility_deleteDirectory(directory_.c_str());
        }
    }

private:
    std::string directory_;
};

/**
 * A utility function to be used with shared pointers that hold pointers to
 * arrays
 */
template <typename T>
struct ArrayDeleter {
    void operator ()(T *array) {
        delete[] array;
    }
};


#define DEFAULT_TEST_TIMEOUT_SEC 60

// Common setup for many tests: participant, topic, reader, writer
// Uses QoS from AbstractDomainTester, but does not inherit, since the
// AbstractDomainTester doesn't provide virtual methods other than the
// destructor.
Package
class TestSystem {
public:

    typedef std::pair<dds::domain::DomainParticipant,
            rti::core::ListenerBinder<
                    dds::sub::DataReader<
                            dds::topic::ParticipantBuiltinTopicData> > >
                                    Participant;

    TestSystem()
    {
    }

    // Uses the DomainParticipantQoS from AbstractDomainTester as a starting
    // point (so we can pick up changes if that changes), and then adds
    // additional QoS to test types with larger sized type code / type objects
    static const dds::domain::qos::DomainParticipantQos& test_qos(
            bool use_domain_tag = true)
    {
        using namespace dds::core;
        /*
         * [Juanlu]: we were originally providing no value for the boolean flag
         * in the rti::test::AbstractDomainTester::test_qos() method below.
         * This was causing us to use the low-memory generic built-in profile.
         * The loading of a generic QoS profile causes our participants to lack
         * the system info properties ('dds.sys_info.process_id', etc).
         * When our extremely isolated participants detect the absence of this
         * property in the participant properties, they ignore it. This was
         * causing our tests to fail.
         */
        static dds::domain::qos::DomainParticipantQos qos(
                rti::test::AbstractDomainTester::test_qos(false));
        // override initial peers
        StringSeq initial_peers_list;
        initial_peers_list.push_back("8@localhost");
        initial_peers_list.push_back("8@udpv4://127.0.0.1");
        qos->discovery.initial_peers(initial_peers_list);

        StringSeq multicast_receive_addr_list;
        qos->discovery.multicast_receive_addresses(multicast_receive_addr_list);

        qos->discovery.accept_unknown_peers(true);

        // Use UDPv4 only
        qos->transport_builtin.mask(
                rti::core::policy::TransportBuiltinMask::udpv4());

        qos << rti::core::policy::DomainParticipantResourceLimits()
                .type_code_max_serialized_length(complex_typecode_size())
                .type_object_max_serialized_length(complex_typecode_size())
                .serialized_type_object_dynamic_allocation_threshold(complex_typecode_size());

        if (use_domain_tag) {
            // Use our Domain Tag to ensure isolation of the tests
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    domain_tag_property(),
                    domain_tag_value()));
            qos << value;
        }

        return qos;
    }

    // Returmns default test writer qos
    static const dds::pub::qos::DataWriterQos writer_qos()
    {
        using namespace dds::pub;
        using namespace dds::core::policy;
        using namespace rti::core::policy;

        dds::pub::qos::DataWriterQos qos;
        make_transient_local(qos);
        // set unbounded support
        rti::core::policy::Property value;
        value.set(rti::core::policy::Property::Entry(
                writer_buffer_pool_property(),
                buffer_pool_max_size()));
        qos << value;

        return qos;
    }

    // Returns default test reader qos
    static const dds::sub::qos::DataReaderQos reader_qos()
    {
        using namespace dds::sub;
        using namespace dds::core::policy;
        using namespace rti::core::policy;

        dds::sub::qos::DataReaderQos qos;
        make_transient_local(qos);
        // set unbounded support
        rti::core::policy::Property value;
        value.set(rti::core::policy::Property::Entry(
                reader_buffer_pool_property(),
                buffer_pool_max_size()));
        qos << value;
        qos << DataReaderResourceLimits().dynamically_allocate_fragmented_samples(
                true);

        return qos;
    }

    static dds::sub::qos::DataReaderQos& make_xcdr2(
            dds::sub::qos::DataReaderQos& qos)
    {
        using namespace dds::core::policy;

        DataRepresentationIdSeq data_vector;
        data_vector.push_back(DataRepresentation::xcdr2());
        qos.policy<DataRepresentation>().value(
                data_vector.begin(),
                data_vector.end());
        return qos;
    }

    static dds::pub::qos::DataWriterQos& make_xcdr2(
            dds::pub::qos::DataWriterQos& qos)
    {
        using namespace dds::core::policy;

        DataRepresentationIdSeq data_vector;
        data_vector.push_back(DataRepresentation::xcdr2());
        qos.policy<DataRepresentation>().value(
                data_vector.begin(),
                data_vector.end());
        return qos;
    }

    // Create a DomainParticipant with QoS specific to Recording Service
    static std::pair<dds::domain::DomainParticipant,
            rti::core::ListenerBinder<
                    dds::sub::DataReader<
                            dds::topic::ParticipantBuiltinTopicData> > >
    create_participant(
            int32_t domain_id,
            const dds::domain::qos::DomainParticipantQos& qos = test_qos())
    {
        dds::domain::qos::DomainParticipantFactoryQos factory_qos;
        factory_qos << dds::core::policy::EntityFactory::ManuallyEnable();
        dds::domain::DomainParticipant::participant_factory_qos(factory_qos);

        dds::domain::DomainParticipant participant =
                dds::domain::DomainParticipant(domain_id, qos);

        dds::sub::Subscriber builtin_subscriber = dds::sub::builtin_subscriber(
                participant);

        // Access the built-in DataReader for ParticipantBuiltinTopicData
        std::vector<dds::sub::DataReader<
                dds::topic::ParticipantBuiltinTopicData> > participant_reader;
        dds::sub::find<
                dds::sub::DataReader<dds::topic::ParticipantBuiltinTopicData> >(
                        builtin_subscriber,
                        dds::topic::participant_topic_name(),
                        std::back_inserter(participant_reader));
        rti::core::ListenerBinder<
                dds::sub::DataReader<dds::topic::ParticipantBuiltinTopicData> >
                        participant_listener =
                                rti::core::bind_and_manage_listener(
                                        participant_reader[0],
                                        new ParticipantBuiltinTopicListener,
                                        dds::core::status::StatusMask::data_available());

        participant.enable();

        factory_qos << dds::core::policy::EntityFactory::AutoEnable();
        dds::domain::DomainParticipant::participant_factory_qos(factory_qos);

        return std::make_pair(participant, participant_listener);
    }

    // Look up whether a Topic exists.  If yes, return it.  If not, create it
    template<class T>
    static dds::topic::Topic<T> create_topic(
            dds::domain::DomainParticipant& participant,
            const std::string& topic_name = "Default")
    {
        dds::topic::Topic<T> topic =
                dds::topic::find<dds::topic::Topic<T> >(
                        participant,
                        topic_name);
        if (topic != dds::core::null) {
            return topic;
        }
        return dds::topic::Topic<T>(participant, topic_name);
    }

    template<class T>
    static dds::topic::Topic<T> create_topic(
            dds::domain::DomainParticipant& participant,
            const std::string& topic_name,
            const std::string& type_name)
    {
        dds::topic::Topic<T> topic =
                dds::topic::find<dds::topic::Topic<T> >(
                        participant,
                        topic_name);
        if (topic != dds::core::null) {
            return topic;
        }
        return dds::topic::Topic<T>(participant, topic_name, type_name);
    }

    // Create a DataReader with transient local QoS
    template<class T>
    static dds::sub::DataReader<T> create_transient_local_reader(
            dds::domain::DomainParticipant& participant,
            dds::topic::Topic<T>& topic,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        using namespace dds::sub;
        using namespace dds::core::policy;
        using namespace rti::core::policy;

        qos::DataReaderQos qos;
        make_transient_local(qos);
        if (unbounded) {
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    reader_buffer_pool_property(),
                    buffer_pool_max_size()));
            qos << value;
            qos << DataReaderResourceLimits().dynamically_allocate_fragmented_samples(
                    true);
        }
        if (use_xcdr_2) {
            make_xcdr2(qos);
        }
        return dds::sub::DataReader<T>(Subscriber(participant), topic, qos);
    }

    // Create a DataReader with transient local QoS
    template<class T>
    static dds::sub::DataReader<T> create_transient_local_reader(
            dds::sub::Subscriber& subscriber,
            dds::topic::Topic<T>& topic,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        using namespace dds::sub;
        using namespace dds::core::policy;
        using namespace rti::core::policy;

        qos::DataReaderQos qos;
        make_transient_local(qos);
        if (unbounded) {
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    reader_buffer_pool_property(),
                    buffer_pool_max_size()));
            qos << value;
            qos << DataReaderResourceLimits().dynamically_allocate_fragmented_samples(
                    true);
        }
        if (use_xcdr_2) {
            make_xcdr2(qos);
        }
        return dds::sub::DataReader<T>(subscriber, topic, qos);
    }

    // Create a DataReader with transient local QoS
    template<class T>
    static dds::sub::DataReader<T> create_transient_local_reader(
            dds::domain::DomainParticipant& participant,
            dds::topic::Topic<T>& topic,
            const dds::sub::qos::DataReaderQos& suggested_qos,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        using namespace dds::sub;
        using namespace dds::core::policy;
        using namespace rti::core::policy;

        qos::DataReaderQos qos(suggested_qos);
        make_transient_local(qos);
        if (unbounded) {
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    reader_buffer_pool_property(),
                    buffer_pool_max_size()));
            qos << value;
            qos << DataReaderResourceLimits().dynamically_allocate_fragmented_samples(
                    true);
        }
        if (use_xcdr_2) {
            make_xcdr2(qos);
        }
        return dds::sub::DataReader<T>(Subscriber(participant), topic, qos);
    }

    // Create a  DataReader with specified qos
    template<class T>
    static dds::sub::DataReader<T> create_reader(
            dds::domain::DomainParticipant& participant,
            dds::topic::Topic<T>& topic,
            dds::sub::qos::DataReaderQos& qos,
            const std::string& filter_expression = "",
            const bool use_xcdr_2 = false)
    {
        using namespace dds::sub;

        if (use_xcdr_2) {
            make_xcdr2(qos);
        }
        dds::topic::TopicDescription<T> topic_desc = topic;
        if (filter_expression.length() != 0) {
            // Create the ContentFilteredTopic
            dds::topic::ContentFilteredTopic<T> cft =
                    dds::topic::ContentFilteredTopic<T>(
                        topic, // related topic
                        topic.name() + "CFT" + filter_expression,
                        dds::topic::Filter(filter_expression));
            return dds::sub::DataReader<T>(Subscriber(participant), cft, qos);
        } else {
            return dds::sub::DataReader<T>(Subscriber(participant), topic, qos);
        }
    }

      // Create a reliable DataReader with Recording-Service friendly buffer pool size
    template<class T>
    static dds::sub::DataReader<T> create_reader(
            dds::domain::DomainParticipant& participant,
            dds::topic::Topic<T> topic,
            const bool unbounded = true,
            const std::string& filter_expression = "",
            const bool use_xcdr_2 = false)
    {
        using namespace dds::sub;
        using namespace dds::core::policy;
        using namespace rti::core::policy;

        qos::DataReaderQos qos;
        if (unbounded) {
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    reader_buffer_pool_property(),
                    buffer_pool_max_size()));
            qos << value;
            qos << DataReaderResourceLimits().dynamically_allocate_fragmented_samples(
                    true);
        }
        if (use_xcdr_2) {
            make_xcdr2(qos);
        }
        return create_reader(participant, topic, qos, filter_expression);
    }

    // Create a DataWriter with suggested QoS and make it transient local
    template<class T>
    static dds::pub::DataWriter<T> create_transient_local_writer(
            dds::domain::DomainParticipant& participant,
            dds::topic::Topic<T>& topic,
            const dds::pub::qos::DataWriterQos& suggested_qos,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        using namespace dds::pub;

        qos::DataWriterQos adjusted_qos(suggested_qos);
        make_transient_local(adjusted_qos);
        if (unbounded) {
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    writer_buffer_pool_property(),
                    buffer_pool_max_size()));
            adjusted_qos << value;
        }
        if (use_xcdr_2) {
            make_xcdr2(adjusted_qos);
        }
        return dds::pub::DataWriter<T>(
                Publisher(participant),
                topic,
                adjusted_qos);
    }

    // Create a DataWriter with suggested QoS and make it transient local,
    // also including an already existing publisher
    template<class T>
    static dds::pub::DataWriter<T> create_transient_local_writer(
            dds::pub::Publisher& publisher,
            dds::topic::Topic<T>& topic,
            dds::pub::qos::DataWriterQos suggested_qos,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        using namespace dds::pub;

        qos::DataWriterQos adjusted_qos(suggested_qos);
        make_transient_local(adjusted_qos);
        if (unbounded) {
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    writer_buffer_pool_property(),
                    buffer_pool_max_size()));
            adjusted_qos << value;
        }
        if (use_xcdr_2) {
            make_xcdr2(adjusted_qos);
        }
        return dds::pub::DataWriter<T>(
                publisher,
                topic,
                adjusted_qos);
    }

    // Create a DataWriter with transient local QoS
    template<class T>
    static dds::pub::DataWriter<T> create_transient_local_writer(
            dds::domain::DomainParticipant& participant,
            dds::topic::Topic<T> topic,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        dds::pub::qos::DataWriterQos qos;
        return create_transient_local_writer(
                participant,
                topic,
                qos,
                unbounded,
                use_xcdr_2);
    }

    // Create a DataWriter with transient local QoS and external Publisher
    template<class T>
    static dds::pub::DataWriter<T> create_transient_local_writer(
            dds::pub::Publisher& publisher,
            dds::topic::Topic<T> topic,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        dds::pub::qos::DataWriterQos qos;
        return create_transient_local_writer(
                publisher,
                topic,
                qos,
                unbounded,
                use_xcdr_2);
    }

    // Create a DataWriter with transient local QoS
    template<class T>
    static dds::pub::DataWriter<T> create_writer(
            dds::domain::DomainParticipant& participant,
            dds::topic::Topic<T>& topic,
            const bool unbounded = true,
            const bool use_xcdr_2 = false)
    {
        using namespace dds::pub;

        qos::DataWriterQos qos;
        if (unbounded) {
            rti::core::policy::Property value;
            value.set(rti::core::policy::Property::Entry(
                    writer_buffer_pool_property(),
                    buffer_pool_max_size()));
            qos << value;
        }
        if (use_xcdr_2) {
            make_xcdr2(qos);
        }
        return dds::pub::DataWriter<T>(Publisher(participant), topic, qos);
    }

    template <class T>
    static bool wait_for_readers(
            dds::pub::DataWriter<T>& writer,
            int32_t num_readers,
            int32_t timeout_sec = DEFAULT_TEST_TIMEOUT_SEC)
    {
        try {
            RTI_TEST_WAIT_FOR_EQUALS_INT(
                    num_readers,
                    writer.publication_matched_status().current_count(),
                    timeout_sec);
        } catch (...) {
            return false;
        }

        return true;
    }

    template <class T>
    static bool wait_for_writers(
            dds::sub::DataReader<T>& reader,
            int32_t num_writers,
            int32_t timeout_sec = DEFAULT_TEST_TIMEOUT_SEC)
    {
        try {
            RTI_TEST_WAIT_FOR_EQUALS_INT(
                    num_writers,
                    reader.subscription_matched_status().current_count(),
                    timeout_sec);
        } catch (...) {
            return false;
        }
        return true;
    }

    template <class T>
    static bool check_num_writers_invariant(
            dds::sub::DataReader<T>& reader,
            int32_t num_writers,
            int32_t for_seconds = DEFAULT_TEST_TIMEOUT_SEC)
    {
        const struct RTINtpTime sleepTime = {0,429496730};
        int sleeps = 0;
        int32_t writer_current_count =
                reader.subscription_matched_status().current_count();
        bool result = (num_writers == writer_current_count);
        while(result && sleeps < (static_cast<int32_t>(for_seconds)) * 10) {
            RTIOsapiThread_sleep(&sleepTime);
            ++sleeps;
            writer_current_count =
                    reader.subscription_matched_status().current_count();
            result = (num_writers == writer_current_count);
        }
        if (!result) {
            print_assert_equals_failure(num_writers, writer_current_count);
        }
        return result;
    }

    template <class T>
    static bool wait_for_received_sample_state(
            dds::sub::DataReader<T>& reader,
            int32_t received_total_count,
            int32_t cache_sample_count,
            int32_t timeout_sec = DEFAULT_TEST_TIMEOUT_SEC)
    {
        try {
            RTI_TEST_WAIT_FOR_EQUALS_INT(
                    received_total_count,
                    reader->datareader_protocol_status().received_sample_count().total(),
                    timeout_sec);
            RTI_TEST_WAIT_FOR_EQUALS_INT(
                    cache_sample_count,
                    reader->datareader_cache_status().sample_count(),
                    timeout_sec);
        } catch (...) {
            return false;
        }
        return true;
    }

    template <class T>
    static bool wait_for_read_count(
            dds::sub::DataReader<T>& reader,
            int32_t read_count,
            int32_t timeout_sec = DEFAULT_TEST_TIMEOUT_SEC)
    {
        try {
            RTI_TEST_WAIT_FOR_EQUALS_INT(
                    read_count,
                    (int32_t) reader.read().length(),
                    timeout_sec);
        } catch (...) {
            return false;
        }
        return true;
    }

    template <class T>
    static bool wait_for_read_count(
            typename dds::sub::DataReader<T>::Selector selector,
            int32_t read_count,
            int32_t timeout_sec = DEFAULT_TEST_TIMEOUT_SEC)
    {
        try {
            RTI_TEST_WAIT_FOR_EQUALS_INT(
                    read_count,
                    (int32_t) selector.read().length(),
                    timeout_sec);
        } catch (...) {
            return false;
        }
        return true;
    }


    template <class T>
    static void wait_for_dispose(
            typename dds::sub::DataReader<T> reader,
            const dds::core::InstanceHandle& handle,
            int32_t timeout_sec = DEFAULT_TEST_TIMEOUT_SEC)
    {
        RTI_TEST_WAIT_FOR(
                reader.select()
                .state(dds::sub::status::InstanceState::not_alive_mask())
                        .instance(handle).read().length() > 0,
                timeout_sec);
    }

    static const std::string domain_tag_property()
    {
        return PRES_PARTICIPANT_DOMAIN_TAG_PROPERTY_NAME;
    }

    static const std::string domain_tag_value()
    {
        return "rti.recording.test.DOMAIN_TAG";
    }

private:

    static dds::sub::qos::DataReaderQos& make_transient_local(
            dds::sub::qos::DataReaderQos& qos)
    {
        using namespace dds::core::policy;

        qos.policy<Durability>().kind(DurabilityKind::TRANSIENT_LOCAL);
        qos.policy<Reliability>().kind(ReliabilityKind::RELIABLE);
        qos.policy<History>().kind(HistoryKind::KEEP_ALL);

        return qos;
    }

    static dds::pub::qos::DataWriterQos& make_transient_local(
            dds::pub::qos::DataWriterQos& qos)
    {
        using namespace dds::core::policy;

        qos.policy<Durability>().kind(DurabilityKind::TRANSIENT_LOCAL);
        qos.policy<Reliability>().kind(ReliabilityKind::RELIABLE);
        qos.policy<History>().kind(HistoryKind::KEEP_ALL);
        qos << WriterDataLifecycle::ManuallyDisposeUnregisteredInstances();

        return qos;
    }

    // Note:  The following constants are encapsulated in static methods rather
    // than private constant static members to avoid creating a .cxx file just
    // to initialize static constant variables.

    // We test with some data types that are complex enough to need larger-than-
    // default type code (and type object) sizes, and we would like to still
    // discover the data types when feasible.
    //
    static int complex_typecode_size()
    {
        return 8192;
    }

    static const std::string buffer_pool_max_size()
    {
        return "16384";
    }

    static const std::string writer_buffer_pool_property()
    {
        return PROPERTY_NAME_DDS_DATA_WRITER_HISTORY_MEMORY_MANAGER_FAST_POOL_POOL_BUFFER_MAX_SIZE;
    }

    static const std::string reader_buffer_pool_property()
    {
        return PROPERTY_NAME_DDS_DATA_READER_HISTORY_MEMORY_MANAGER_FAST_POOL_POOL_BUFFER_MAX_SIZE;
    }

};

} } } /* namespace rti::apputils::test */

#endif  /* HPP_APPUTILS_FRAMEWORK_HPP_ */
// --------------------------------------------------------------------

/* End $Id$ */
