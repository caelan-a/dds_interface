#ifndef OMG_DDS_CORE_QOS_TPROVIDER_HPP_
#define OMG_DDS_CORE_QOS_TPROVIDER_HPP_


/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Inc.
 * Copyright 2010, Real-Time Innovations, Inc.
 * All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/Reference.hpp>

#include <dds/domain/qos/DomainParticipantQos.hpp>

#include <dds/topic/qos/TopicQos.hpp>

#include <dds/sub/qos/SubscriberQos.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>

#include <dds/pub/qos/PublisherQos.hpp>
#include <dds/pub/qos/DataWriterQos.hpp>

namespace dds {
  namespace core {
    template <typename DELEGATE>
    class TQosProvider;
  }
}

/**
 * @RTI_class_definition class dds::core::QosProvider
 * @ingroup NDDSXmlConfigurationModule
 * @headerfile dds/core/QosProvider.hpp
 *
 * @brief @st_ref_type The QosProvider class provides a way for a user to control and
 * access the XML QoS profiles that are loaded by @ndds
 *
 * A QosProvider is created with a URI that identifies a file location
 * containing QoS profiles, a string representation of the QoS profiles that
 * you want the QosProvider to load, or a URL group that has a combination of
 * files and strings from which to load profiles. For more information on the
 * correct format of these URIs and URL groups, please see the
 * [URL Groups section](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds/html_files/RTI_ConnextDDS_CoreLibraries_UsersManual/index.htm#UsersManual/URL_Groups.htm?Highlight=url%20groups)
 * in the User's Manual.
 *
 * A number of QosProvider member functions receive a profile name with the format
 * `"library_name::profile_name"` to retrieve the Qos definitions.
 *
 * The following example loads the Qos profiles from a file called `"MyProfiles.xml"`.
 * Then it retrives the `DataReaderQos` from a profile library called `"MyLibrary"`
 * and a profile called `"MyProfile"` to create a `DataReader`.
 *
 * \code
 * dds::core::QosProvider my_qos_provider("MyProfiles.xml");
 *
 * dds::sub::DataReader<Foo> my_reader(
 *         my_subscriber,
 *         my_topic,
 *         my_qos_provider.datareader_qos("MyLibrary::MyProfile"));
 * \endcode
 *
 * The profile name argument is optional. When omitted, the QosProvider looks for
 * a profile with the attribute `is_default_qos=true`. Alternatively, the
 * functions default_library() and default_profile() can set the default profile.
 *
 * More information about QoS Profiles can be found in the
 * [QoS Profiles section](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds/html_files/RTI_ConnextDDS_CoreLibraries_UsersManual/index.htm#UsersManual/QoS_Profiles.htm?Highlight=Qos%20Profiles), 
 * in the User's Manual.
 *
 * A QosProvider also allows loading dds::core::xtypes::DynamicType definitions
 * from XML. See the QosProvider::type() extension function.
 *
 * @section DefaultQosProvider The Default QosProvider
 *
 * A special QosProvider, QosProvider::Default() is always available to obtain
 * the Qos profiles from the default locations, such as the file USER_QOS_PROFILES.xml
 * in the current directory. For example, the following code obtains the default
 * DataReader qos:
 *
 * \code
 * dds::sub::qos::DataReaderQos default_reader_qos =
 *         dds::core::QosProvider::Default().datareader_qos();
 * \endcode
 *
 *
 * [This section](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds/html_files/RTI_ConnextDDS_CoreLibraries_UsersManual/index.htm#UsersManual/How_to_Load_XML_Specified_QoS_Settings.htm#xmlconfiguration_1275484337_316960%3FTocPath%3DPart%25203%253A%2520Advanced%2520Concepts%7C18.%2520Configuring%2520QoS%2520with%2520XML%7C18.5%2520How%2520to%2520Load%2520XML-Specified%2520QoS%2520Settings%7C_____0)
 * in the User's Manual explains which profiles are automatically loaded by the
 * default QosProvider.
 *
 * @section BuiltinProfiles Built-in Qos Profiles
 *
 * Any QosProvider, including the default QosProvider, has access to the \ref DDSBuiltinQosProfilesModule.
 * For example, to obtain the `DataWriterQos` from the "strict reliable" built-in profile:
 *
 * \code
 * auto strict_reliable_writer_qos = dds::core::QosProvider::Default().datawriter_qos(
 *         rti::core::builtin_profiles::qos_lib_exp::generic_strict_reliable());
 * \endcode
 *
 * @section TopicFilters Specifying a Topic Filter
 * XML Qos definitions can specify a `topic_filter` attribute.
 * Several functions (such as datareader_qos_w_topic_name()) receive
 * a `topic_name` argument. When these functions look for the Qos, they will try
 * to match the `topic_name` against the `topic_filter`s, if they are used.
 * See the [Topic Filters section](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds/html_files/RTI_ConnextDDS_CoreLibraries_UsersManual/index.htm#UsersManual/Topic_Filters.htm)
 * in the User's Manual.
 *
 * @see For more examples, see \ref DDSQosProviderExampleModule
 */
template <typename DELEGATE>
class dds::core::TQosProvider : public dds::core::Reference<DELEGATE> {
public:
  OMG_DDS_REF_TYPE(TQosProvider, dds::core::Reference, DELEGATE)

protected:
    // Spec error CPPPSM-168: need this constructor
    explicit TQosProvider(const DELEGATE_REF_T& ref)
        : dds::core::Reference<DELEGATE>(ref)
    {
    }

public:
    /**
    * @brief Create a QosProvider fetching QoS configuration from
    * the specified URI.
    *
    * For instance, the following code:
    * \code
    * dds::core::QosProvider xml_file_provider(
    *     "file:///somewhere/on/disk/qos-config.xml", "MyLibrary::MyProfile");
    * \endcode
    * will create a QosProvider which loads all of the QoS profiles from
    * qos-config.xml and uses "MyLibrary::MyProfile" as the default profile.
    *
    * @param uri The URI describing the location of the QoS profiles to load.
    * @param profile The QoS profile to set as the default, overriding any
    * is_default_qos tag in the loaded XML file.
    */
    TQosProvider(const std::string& uri, const std::string& profile)
      : dds::core::Reference<DELEGATE>(new DELEGATE(uri, profile))
    {
    }

    /**
    * @brief Create a QosProvider fetching QoS configuration from
    * the specified URI.
    *
    *  For instance, the following code:
    * \code
    *    QosProvider xml_file_provider("file:///somewhere/on/disk/qos-config.xml");
    * \endcode
    * will create a QosProvider which loads all of the QoS profiles from
    * qos-config.xml and will only have a default profile if one of the
    * profiles in qos-config.xml is marked with the is_default_qos set to true.
    *
    * @param uri The URI describing the location of the QoS profiles to load.
    * If no is_default_qos tag is found in the QoS profiles, then no profile
    * will be set as default. Instead, the QosProvider will be associated with
    * the DDS default QoS values until a default profile is set using the
    * default_library and default_profile methods.
    */
    explicit TQosProvider(const std::string& uri)
    : dds::core::Reference<DELEGATE>(new DELEGATE(uri))
    {
    }

    explicit TQosProvider(const char* uri)
    : dds::core::Reference<DELEGATE>(new DELEGATE(uri))
    {
    }

    /**
    * @brief Get the dds::domain::qos::DomainParticipantQos currently
    *        associated with this QosProvider
    *
    * @return The DomainParticipantQos
    */
    dds::domain::qos::DomainParticipantQos
    participant_qos()
    {
      return this->delegate()->participant_qos();
    }

    /**
     * @brief Set the dds::domain::qos::DomainParticipantQos that this
     * QosProvider is currently associated with
     *
     * @param profile The profile from which to get the DomainParticipantQos,
     * for example `"MyLibrary::MyProfile"`
     *
     * @return The DomainParticipantQos that is located in the specified profile
     */
      dds::domain::qos::DomainParticipantQos
      participant_qos(const std::string& profile)
      {
          return this->delegate()->participant_qos(profile);
      }

      /**
      * @brief Get the dds::topic::qos::TopicQos currently
      *        associated with this QosProvider
      *
      * @return The TopicQos
      */
      dds::topic::qos::TopicQos
      topic_qos()
      {
          return this->delegate()->topic_qos();
      }

      /**
       * @brief Set the dds::topic::qos::TopicQos that this QosProvider is
       * currently associated with
       *
       * @param profile The profile from which to get the TopicQos,
       * for example `"MyLibrary::MyProfile"`
       *
       * @return The TopicQos that is located in the specified profile
       */
      dds::topic::qos::TopicQos
      topic_qos(const std::string& profile)
      {
          return this->delegate()->topic_qos(profile);
      }

      /**
      * @brief Get the dds::sub::qos::SubscriberQos currently associated
      * with this QosProvider
      *
      * @return The SubscriberQos
      */
      dds::sub::qos::SubscriberQos
      subscriber_qos()
      {
          return this->delegate()->subscriber_qos();
      }

      /**
       * @brief Set the dds::sub::qos::SubscriberQos that this QosProvider
       * is currently associated with
       *
       * @param profile The profile from which to get the SubscriberQos,
       * for example `"MyLibrary::MyProfile"`
       *
       * @return The SubscriberQos that is located
       * in the specified profile
       */
      dds::sub::qos::SubscriberQos
      subscriber_qos(const std::string& profile)
      {
          return this->delegate()->subscriber_qos(profile);
      }

      /**
      * @brief Get the dds::sub::qos::DataReaderQos currently associated with
      * this QosProvider
      *
      * @return The DataReaderQos
      */
      dds::sub::qos::DataReaderQos
      datareader_qos()
      {
          return this->delegate()->datareader_qos();
      }

      /**
       * @brief Set the dds::sub::qos::DataReaderQos that this QosProvider is
       * currently associated with
       *
       * @param profile The profile from which to get the DataReaderQos,
       * for example `"MyLibrary::MyProfile"`
       *
       * @return The DataReaderQos that is located in the specified profile
       */
      dds::sub::qos::DataReaderQos
      datareader_qos(const std::string& profile)
      {
          return this->delegate()->datareader_qos(profile);
      }

      /**
      * @brief Get the dds::pub::qos::PublisherQos currently associated with
      * this QosProvider
      *
      * @return The PublisherQos
      */
      dds::pub::qos::PublisherQos
      publisher_qos()
      {
          return this->delegate()->publisher_qos();
      }

      /**
       * @brief Set the dds::pub::qos::PublisherQos that this QosProvider is
       * currently associated with
       *
       * @param profile The profile from which to get the PublisherQos,
       * for example `"MyLibrary::MyProfile"`
       *
       * @return The PublisherQos that is located
       * in the specified profile
       */
      dds::pub::qos::PublisherQos
      publisher_qos(const std::string& profile)
      {
          return this->delegate()->publisher_qos(profile);
      }

      /**
      * @brief Get the dds::pub::qos::DataWriterQos currently associated with
      * this QosProvider
      *
      * @return The DataWriterQos
      */
      dds::pub::qos::DataWriterQos
      datawriter_qos()
      {
          return this->delegate()->datawriter_qos();
      }

     /**
      * @brief Set the dds::pub::qos::DataWriterQos that this QosProvider is
      * currently associated with
      *
      * @param profile The profile from which to get the DataWriterQos,
      * for example `"MyLibrary::MyProfile"`
      *
      * @return The DataWriterQos that is located
      * in the specified profile
      */
      dds::pub::qos::DataWriterQos
      datawriter_qos(const std::string& profile)
      {
          return this->delegate()->datawriter_qos(profile);
      }

public:
    /**
     * @brief Get the default QosProvider.
     *
     * The default QosProvider is a singleton that represents the Qos profiles
     * that the DDS entities will be implicitly created with if the Qos parameter
     * is omitted in their constructors. By modifying the default QosProvider
     * you are altering the QoS settings that entities will be created with by default.
     *
     * The default QosProvider automatically loads XML Qos, types and application
     * profiles from several predetermined locations, such as the file USER_QOS_PROFILES.xml
     * in the current working directory.
     *
     * @return The Default QosProvider
     *
     * @see \ref Entity_default_qos
     * @see \ref DDSQosProviderExampleModule_default_provider "Default QosProvider Use Cases"
     */
    static TQosProvider Default() {
        return TQosProvider(DELEGATE::Default());
    }

    /**
     * @brief Reset the default settings of the default QosProvider.
     *
     *  If you change the default library or profile associated with
     * the default QosProvider, calling reset_default will set the library and
     * profile back to the default values.
     */
    static void reset_default(){
        DELEGATE::reset_default();
    }

};

#endif /* OMG_DDS_CORE_QOS_TPROVIDER_HPP_ */