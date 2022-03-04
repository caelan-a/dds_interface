/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.7a,03mar14,eam Created
============================================================================= */

#ifndef RTI_DDS_CORE_QOS_PROVIDER_HPP_
#define RTI_DDS_CORE_QOS_PROVIDER_HPP_

#include "dds_c/dds_c_xml.h"
#include "dds_c/dds_c_xml_impl.h"

#include <string>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/ref_traits.hpp>

#include <dds/core/corefwd.hpp>

#include <dds/domain/qos/DomainParticipantQos.hpp>
#include <dds/pub/qos/PublisherQos.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>
#include <dds/topic/qos/TopicQos.hpp>

#include <rti/core/QosProviderParams.hpp>

#include <rti/core/OptionalValue.hpp>
#include <rti/core/Exception.hpp>
#include <rti/core/LockGuard.hpp>
#include <rti/domain/DomainParticipantConfigParams.hpp>
#include <rti/domain/FactoryPluginSupport.hpp>

namespace rti { namespace core {

/**
 * @relatesalso dds::core::QosProvider
 *
 * @brief @extension Get the rti::core::QosProviderParams for the default
 * QosProvider
 *
 * @namespace_note rti::core
 *
 * @return rti::core::QosProviderParams
 */
OMG_DDS_API QosProviderParams default_qos_provider_params();

/**
 * @relatesalso dds::core::QosProvider
 *
 * @brief @extension Set the rti::core::QosProviderParams for the
 * default QosProvider
 *
 * @namespace_note rti::core
 *
 * Use this function to configure the profiles that
 * `dds::core::QosProvider::Default()` loads.
 *
 * ```
 * rti::core::QosProviderParams params;
 * params.url_profile({"my_profiles.xml"});
 * rti::core::default_qos_provider_params(params);
 *
 * auto participant_qos =
 *     dds::core::QosProvider::Default().participant_qos("my_library::my_profile");
 * ```
 *
 * @param params The QosProviderParams to set
 */
OMG_DDS_API void default_qos_provider_params(
        const rti::core::QosProviderParams& params);

namespace detail {

inline const char * empty_string_to_NULL(const std::string& my_string) {
    return (my_string.length() == 0 ? NULL : my_string.c_str());
}

// For the DefaultQosProvider, it uses the DPF lock; for any user-created
// QosProvider it uses a new semaphore and takes ownership of it.
class QosProviderMutex {
public:
    // Leaves the semaphore set to NULL, meaning that the DPF lock will be used.
    // QosProviderResourceManager will create a new semaphore if needed.
    QosProviderMutex() : native_semaphore_(NULL)
    {
    }

    ~QosProviderMutex();

    void take();
    void give();

    RTIOsapiSemaphore *native_semaphore_;
};

// Manage the QosProvider Resources -------------------------------------------
class QosProviderResourceManager {
public:
    QosProviderResourceManager(bool default_provider = false);

    ~QosProviderResourceManager();

    DDS_QosProvider* get() const;
    QosProviderMutex& mutex() const
    {
        return mutex_;
    }

    bool is_default_provider() const
    {
        return default_provider_;
    }

    void finalize_provider();

private:
    DDS_QosProvider *native_provider_;
    mutable QosProviderMutex mutex_;
    bool default_provider_;
};

}

/**
 * @relatesalso dds::core::QosProvider
 * @brief Special value to select the default QoS profile
 */
extern OMG_DDS_API_VARIABLE const char* USE_DDS_DEFAULT_QOS_PROFILE;

/** @RTI_class_definition NA */
class OMG_DDS_API QosProviderImpl {
public:
    typedef dds::core::smart_ptr_traits<QosProviderImpl>::ref_type
        ref_type;
    typedef dds::core::smart_ptr_traits<QosProviderImpl>::weak_ref_type
        weak_ref_type;

public:
    QosProviderImpl(const std::string& uri, const std::string& profile);

    QosProviderImpl(const std::string& uri);

    QosProviderImpl(const char* uri);

    QosProviderImpl(const rti::core::QosProviderParams& params);

    QosProviderImpl(
        const rti::core::QosProviderParams& params, bool default_provider);

    ~QosProviderImpl();

public:
    static ref_type Default();
    static void reset_default();

    void reset_provider();

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension (deprecated) Get the rti::core::QosProviderParams for the default
     * QosProvider
     *
     * @deprecated Use rti::core::default_qos_provider_params()
     *
     * @return rti::core::QosProviderParams
     */
    static rti::core::QosProviderParams default_provider_params();

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension (deprecated) Set the rti::core::QosProviderParams for
     * the default QosProvider
     *
     * @deprecated Use rti::core::default_qos_provider_params()
     *
     * @param params The QosProviderParams to set
     */
    static void default_provider_params(
        const rti::core::QosProviderParams& params);

    // Getters
    dds::domain::qos::DomainParticipantQos participant_qos() const;
    dds::domain::qos::DomainParticipantQos participant_qos(
        const std::string& profile) const;

    dds::topic::qos::TopicQos topic_qos() const;
    dds::topic::qos::TopicQos topic_qos(const std::string& profile) const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the dds::topic::qos::TopicQos for a topic name
     * in a given profile.
     *
     * @extension_member_note
     *
     *  The TopicQos will be found based on the given profile name and
     * topic name.
     *
     * @param profile The profile where the QosProvider should look for the
     * TopicQos
     * @param topic_name The topic name used to select a qos within the profile,
     * if the `topic_filter` attribute is used
     *
     * @return dds::topic::qos::TopicQos The TopicQos that is located
     * in the specified profile
     */
    const dds::topic::qos::TopicQos topic_qos_w_topic_name(
       const std::string& profile, const std::string& topic_name) const; // Extension

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the dds::topic::qos::TopicQos for a topic name in
     * the default profile.
     *
     * @extension_member_note
     *
     * The TopicQos will be found based on the given topic name and
     * must be located in the default profile (see \ref SelectingQosProfile
     * for information on how the default profile is determined).
     *
     * @param topic_name The topic name used to select a qos within the profile,
     * if the `topic_filter` attribute is used
     *
     * @return dds::topic::qos::TopicQos The TopicQos that is located
     * in the specified profile
     */
    const dds::topic::qos::TopicQos topic_qos_w_topic_name(
       const std::string& topic_name) const; // Extension

    dds::sub::qos::SubscriberQos subscriber_qos() const;
    dds::sub::qos::SubscriberQos subscriber_qos(const std::string& profile) const;

    dds::sub::qos::DataReaderQos datareader_qos() const;
    dds::sub::qos::DataReaderQos datareader_qos(const std::string& profile) const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the dds::sub::qos::DataReaderQos for a topic name
     * in a given profile.
     *
     * @extension_member_note
     *
     * The DataReaderQos will be found based on the given profile
     * name and topic name.
     *
     * @param profile The profile where the QosProvider should look for the
     * DataReaderQos
     * @param topic_name The topic name used to select a qos within the profile,
     * if the `topic_filter` attribute is used
     *
     * @return dds::sub::qos::DataReaderQos The DataReaderQos that is located
     * in the specified profile
     */
    const dds::sub::qos::DataReaderQos datareader_qos_w_topic_name(
       const std::string& profile, const std::string& topic_name) const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the dds::sub::qos::DataReaderQos for a topic name
     * in the default profile.
     *
     * @extension_member_note
     *
     * The DataReaderQos will be found based on the given topic name
     * and must be located in the default profile (see \ref SelectingQosProfile
     * for information on how the default profile  can is determined).
     *
     * @param topic_name The topic name used to select a qos within the profile,
     * if the `topic_filter` attribute is used
     *
     * @return dds::sub::qos::DataReaderQos The DataReaderQos that is located
     * in the specified profile
     */
    const dds::sub::qos::DataReaderQos datareader_qos_w_topic_name(
       const std::string& topic_name) const;

    dds::pub::qos::PublisherQos publisher_qos() const;
    dds::pub::qos::PublisherQos publisher_qos(const std::string& profile) const;

    dds::pub::qos::DataWriterQos datawriter_qos() const;
    dds::pub::qos::DataWriterQos datawriter_qos(const std::string& profile) const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the dds::pub::qos::DataWriterQos for a topic name.
     *
     * @extension_member_note
     *
     * The DataWriterQos will be found based on the given profile
     * name and topic name.
     *
     * @param profile The profile where the QosProvider should look for the
     * DataWriterQos
     * @param topic_name The topic name used to select a qos within the profile,
     * if the `topic_filter` attribute is used
     *
     * @return dds::pub::qos::DataWriterQos The DataWriterQos that is located
     * in the specified profile
     */
    const dds::pub::qos::DataWriterQos datawriter_qos_w_topic_name(
       const std::string& profile, const std::string& topic_name) const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the dds::pub::qos::DataWriterQos for a topic name.
     *
     * @extension_member_note
     *
     * The DataWriterQos will be found based on the given topic name
     * and  must be located in the current default profile associated with the
     * QosProvider.
     *
     * @param topic_name The topic name used to select a qos within the profile,
     * if the `topic_filter` attribute is used
     *
     * @return dds::pub::qos::DataWriterQos The DataWriterQos that is located
     * in the specified profile
     */
    const dds::pub::qos::DataWriterQos datawriter_qos_w_topic_name(
       const std::string& topic_name) const;

public:
    // --- RTI extensions: ----------------------------------------------------
    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Set the default library for this QosProvider.
     *
     * @extension_member_note
     *
     * After a default library is set, the functions that expect a `profile`
     * argument don't need the library name prefix. For example:
     *
     * \code
     * auto reader_qos = qos_provider.datareader_qos("MyLibrary::MyProfile");
     *
     * // This has the same effect:
     * qos_provider.extensions().default_library("MyLibrary");
     * reader_qos = qos_provider.datareader_qos("MyProfile");
     * \endcode
     *
     * @param library_name The library to set as the default, or
     * `rti::core::USE_DDS_DEFAULT_QOS_PROFILE` to unset the default library and
     * use the system default.
     */
    void default_library(const std::string& library_name);

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Set the default profile for this QosProvider.
     *
     * @extension_member_note
     *
     * When a default profile is set, the getters that don't receive
     * a profile argument retrieve the QoS object from this profile
     * (see \ref SelectingQosProfile).
     *
     * The profile must be located in the current default library
     * unless the library is also specified in the name.
     *
     * @param profile_name The profile to set as the default in the form
     * `"MyLibrary::MyProfile"`, or if the default_library() is also set,
     * `"MyProfile"`. The special value `rti::core::USE_DDS_DEFAULT_QOS_PROFILE`
     * unsets a previously set default profile.
     */
    void default_profile(const std::string& profile_name);


    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the default library associated with this
     * QosProvider.
     *
     * @extension_member_note
     *
     * There may not be a default library set. The default library is
     * the library that is checked in when setting the default profile if no
     * library name is explicitly given. The default library is configurable.
     *
     * @return rti::core::optional_value<std::string> The default library.
     */
    rti::core::optional_value<std::string> default_library() const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the default profile associated with this
     * QosProvider.
     *
     * @extension_member_note
     *
     * There may not be a default profile set.
     * @return rti::core::optional_value<std::string> The default profile.
     */
    rti::core::optional_value<std::string> default_profile() const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the default profile library associated with this
     * QosProvider.
     *
     * @extension_member_note
     *
     * There may not be a default profile library set. The default
     * profile library is the library in which the default profile resides and
     * is not necessarily the same library as the one returned from
     * default_library(). The default profile library is not configurable.
     *
     * @return rti::core::optional_value<std::string> The default profile
     * library.
     */
    rti::core::optional_value<std::string> default_profile_library() const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get a list of the QoS profile libraries loaded by this
     * QosProvider.
     *
     * @extension_member_note
     *
     * @return dds::core::StringSeq A list of the currently loaded QoS profile
     * libraries.
     */
    dds::core::StringSeq qos_profile_libraries() const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get a list of the QoS profiles located in the default
     * library of this QosProvider.
     *
     * @return dds::core::StringSeq A list of profiles.
     */
    dds::core::StringSeq qos_profiles(const std::string& library_name) const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Check if the profiles are loaded by this QosProvider
     *
     * @extension_member_note
     *
     * @return bool false if the profiles are not loaded, true otherwise.
     */
    bool profiles_loaded() const;

    const dds::core::xtypes::DynamicType& type(
        const std::string& type_library_name,
        const std::string& type_name) const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Load a type
     *
     * @extension_member_note
     *
     * @param type_name The name of the type
     *
     * This function loads a type from its XML definition under the tags
     * `<dds><types>`.
     *
     * @see \ref DDSXTypesExampleModule_dynamic_type_creation_xml "Example".
     *
     */
    const dds::core::xtypes::DynamicType& type(
        const std::string& type_name) const;

    dds::core::StringSeq type_libraries() const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Get the QosProvider params for this QosProvider.
     *
     * @extension_member_note
     *
     * @return rti::core::QosProviderParams The QosProviderParams for this
     * QosProvider.
     */
    rti::core::QosProviderParams provider_params() const;

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Set the rti::core::QosProviderParams for this
     * QosProvider.
     *
     * @extension_member_note
     *
     * @param provider_params The QosProviderParams to set.
     */
    void provider_params(const rti::core::QosProviderParams& provider_params);

    // Loading
    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Load the XML QoS profiles.
     *
     * @extension_member_note
     *
     * The XML QoS profiles are loaded implicitly after the first
     * dds::domain::DomainParticipant is created or explicitly, after a call
     * to this function.
     * This method has the same effect as reload_profiles().
     */
    void load_profiles();

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Reload the XML QoS profiles.
     *
     * @extension_member_note
     *
     * The XML QoS profiles are loaded implicitly after the first
     * DomainParticipant is created or explicitly, after a call to this
     * function.
     * This method has the same effect as load_profiles().
     */
    void reload_profiles();

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Unload the XML QoS profiles.
     *
     * @extension_member_note
     *
     * The resources associated with the XML QoS profiles are freed.
     * Any reference to the profiles after calling this function will fail
     * with an Exception.
     */
    void unload_profiles();

    /**
     * @memberof dds::core::QosProvider
     * @brief @extension Creates a dds::domain::DomainParticipant given its
     * configuration name from a description provided in an XML configuration
     * file that has been loaded by this QosProvider.
     *
     * @extension_member_note
     *
     * \dref_details_DomainParticipantFactory_create_participant_from_config
     *
     * @param config_name Name of the participant configuration in the XML file.
     * @param params input parameters that allow changing some properties of
     * the configuration referred to by \p config_name. Specifically, \p params
     * allows overriding the domain ID, participant name, and entities
     * QoS specified in the XML configuration.
     *
     * @see XMLAppCreationExampleModule
     */
    dds::domain::DomainParticipant
    create_participant_from_config(
        const std::string& config_name,
        const rti::domain::DomainParticipantConfigParams& params =
            rti::domain::DomainParticipantConfigParams());

private:

    void init(const std::string& uri, const rti::core::QosProviderParams& provider_params);

    static std::pair<std::string, std::string>
        split_profile_name(const std::string &profile);

private:
    detail::QosProviderResourceManager native_provider_;
/** @RTI_remove_lines 1 */
};

// DefaultQosProvider ---------------------------------------------------------
class DefaultQosProvider {
public:
    typedef dds::core::smart_ptr_traits<QosProviderImpl>::ref_type ref_type;

    static ref_type& get_instance();
    static void reset_instance();

    // Anywhere this is called should be protected with the
    // DefaultQosProvider's mutex
    static void finalize();
    static Semaphore& mutex();
    static void params(const QosProviderParams& params);
    static QosProviderParams params();

private:
    static ref_type& get_instance(const rti::core::QosProviderParams& params);

    static ref_type instance_;
};

} } // namespace rti::core

#endif // RTI_DDS_CORE_QOS_PROVIDER_HPP_

