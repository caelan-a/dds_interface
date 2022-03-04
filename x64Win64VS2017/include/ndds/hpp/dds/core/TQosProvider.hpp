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
   * @brief @st_ref_type The QosProvider class provides a way for a user to
   * control and access the XML QoS profiles that are loaded by @ndds
   *
   * A QosProvider is created with a URI that identifies a resource from where
   * to load the definition of:
   * - QoS profiles
   * - Type definitions
   * - Full XML-defined DDS systems
   *
   * The URI can be:
   * - An XML file
   * - A string representation of an XML document `str://"..."`
   * - A group of several files and strings (see [URL Groups](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/index.htm#users_manual/URL_Groups.htm?Highlight=url%20groups)
   * in the User's Manual)
   *
   * The following example loads a file named `"MyProfiles.xml"` in the current
   * directory. Then it retrieves the `DataReaderQos` from a `<qos_profile>`
   * named `"MyProfile"` under a `<qos_library>` named `"MyLibrary"` to create a
   * `DataReader`:
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
   * To load type definitions, see QosProvider::type().
   *
   * To create a `DomainParticipant` and its contained entities, see
   * QosProvider::create_participant_from_config().
   *
   * @section SelectingQosProfile Selecting a QoS profile
   *
   * The profile name argument is optional:
   *
   * \code
   * auto reader_qos = my_qos_provider.datareader_qos();
   * \endcode
   *
   * When omitted, the QosProvider looks for a profile as follows (in order of
   * precedence):
   * - The profile set with default_profile()
   * - The profile set in the constructor (an optional argument)
   * - The `<qos_profile>` identified as the default profile with the attribute
   * `is_default_qos=true`
   * - If none of the above methods have been used, a QoS object with the
   * documented default values is returned
   *
   * A QosProvider can be used in combination with functions such as
   * dds::pub::Publisher::default_datawriter_qos() or
   * dds::sub::Subscriber::default_datareader_qos() to set the profile
   * that entities are created with by default:
   *
   * \code
   * subscriber.default_datareader_qos(
   *         my_qos_provider.datareader_qos("MyLibrary::MyProfile"));
   *
   * // reader created with the QoS in the profile "MyLibrary::MyProfile"
   * dds::sub::DataReader<Foo> reader(subscriber, topic);
   * \endcode
   *
   * More information about QoS Profiles can be found in the
   * [QoS Profiles
   * section](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/index.htm#users_manual/QoS_Profiles.htm?Highlight=Qos%20Profiles),
   * in the User's Manual.
   *
   * @section DefaultQosProvider The Default QosProvider
   *
   * A special QosProvider, QosProvider::Default() is always available to obtain
   * the QoS profiles from the default locations, such as the file
   * USER_QOS_PROFILES.xml in the current directory. For example, the following
   * code obtains the default `DataReaderQos`:
   *
   * \code
   * dds::sub::qos::DataReaderQos default_reader_qos =
   *         dds::core::QosProvider::Default().datareader_qos();
   * \endcode
   *
   * [This section](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/index.htm#users_manual/How_to_Load_XML_Specified_QoS_Settings.htm#xmlconfiguration_1275484337_316960%3FTocPath%3DPart%25203%253A%2520Advanced%2520Concepts%7C18.%2520Configuring%2520QoS%2520with%2520XML%7C18.5%2520How%2520to%2520Load%2520XML-Specified%2520QoS%2520Settings%7C_____0)
   * in the User's Manual explains which profiles are automatically loaded by
   * the default QosProvider.
   *
   * The profiles that QosProvider::Default() loads can be configured
   * with rti::core::default_qos_provider_params().
   *
   * QosProvider::Default() also determines the default values for
   * `<participant_factory_qos>`, which can be used to configure logging.
   *
   * @section BuiltinProfiles Built-in QoS Profiles
   *
   * Any QosProvider, including the default QosProvider, has access to the \ref DDSBuiltinQosProfilesModule
   * For example, to obtain the `DataWriterQos` from the "strict reliable" built-in profile:
   *
   * \code
   * auto strict_reliable_writer_qos =
   *     dds::core::QosProvider::Default().datawriter_qos(
   *         rti::core::builtin_profiles::qos_lib::generic_strict_reliable());
   * \endcode
   *
   * @section TopicFilters Specifying a Topic Filter
   * XML QoS definitions can specify a `topic_filter` attribute.
   * Several functions (such as datareader_qos_w_topic_name()) receive
   * a `topic_name` argument. When these functions look for the QoS, they will
   * try to match the `topic_name` against the `topic_filter`s, if they are
   * used. See the [Topic Filters section](https://community.rti.com/static/documentation/connext-dds/current/doc/manuals/connext_dds_professional/users_manual/index.htm#users_manual/Topic_Filters.htm)
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
    * @brief Get the dds::domain::qos::DomainParticipantQos in
    * the default profile.
    * 
    * See \ref SelectingQosProfile for information on how the default profile is chosen.
    *
    * @return The DomainParticipantQos
    */
    const dds::domain::qos::DomainParticipantQos participant_qos()
    {
      return this->delegate()->participant_qos();
    }

    /**
     * @brief Get the DomainParticipantQos from a QoS profile
     *
     * @param profile The profile from which to get the DomainParticipantQos,
     * for example `"MyLibrary::MyProfile"`
     *
     * @return The DomainParticipantQos that is located in the specified profile
     */
    const dds::domain::qos::DomainParticipantQos participant_qos(const std::string& profile)
    {
        return this->delegate()->participant_qos(profile);
    }

    /**
     * @brief Get the dds::topic::qos::TopicQos in the default profile.
     *
     * See \ref SelectingQosProfile for information on how the default profile is chosen.
     * 
     * @return The TopicQos
     */
    const dds::topic::qos::TopicQos topic_qos()
    {
        return this->delegate()->topic_qos();
    }

    /**
     * @brief Get the dds::topic::qos::TopicQos from a QoS profile
     *
     * @param profile The profile from which to get the TopicQos,
     * for example `"MyLibrary::MyProfile"`
     *
     * @return The TopicQos that is located in the specified profile
     */
    const dds::topic::qos::TopicQos topic_qos(const std::string& profile)
    {
        return this->delegate()->topic_qos(profile);
    }

    /**
     * @brief Get the dds::sub::qos::SubscriberQos in the default profile.
     *
     * See \ref SelectingQosProfile for information on how the default profile
     * is chosen.
     *
     * @return The SubscriberQos
     */
    const dds::sub::qos::SubscriberQos subscriber_qos()
    {
        return this->delegate()->subscriber_qos();
    }

    /**
     * @brief Get the dds::sub::qos::SubscriberQos from a QoS profile
     *
     * @param profile The profile from which to get the SubscriberQos,
     * for example `"MyLibrary::MyProfile"`
     *
     * @return The SubscriberQos that is located
     * in the specified profile
     */
    const dds::sub::qos::SubscriberQos subscriber_qos(
            const std::string& profile)
    {
        return this->delegate()->subscriber_qos(profile);
    }

    /**
     * @brief Get the dds::sub::qos::DataReaderQos in the default profile.
     *
     * See \ref SelectingQosProfile for information on how the default profile
     * is chosen.
     *
     * @note This function doesn't take into account the `topic_filter` used
     * in the profile, if any. See datareader_qos_w_topic_name().
     *
     * @return The DataReaderQos
     */
    const dds::sub::qos::DataReaderQos datareader_qos()
    {
        return this->delegate()->datareader_qos();
    }

    /**
     * @brief Get the dds::sub::qos::DataReaderQos from a QoS profile
     *
     * @note This function doesn't take into account the `topic_filter` used
     * in the profile, if any. See datareader_qos_w_topic_name().
     *
     * @param profile The profile from which to get the DataReaderQos,
     * for example `"MyLibrary::MyProfile"`
     *
     * @return The DataReaderQos that is located in the specified profile
     */
    const dds::sub::qos::DataReaderQos datareader_qos(
            const std::string& profile)
    {
        return this->delegate()->datareader_qos(profile);
    }

    /**
     * @brief Get the dds::pub::qos::PublisherQos in the default profile.
     *
     * See \ref SelectingQosProfile for information on how the default profile
     * is chosen.
     *
     * @return The PublisherQos
     */
    const dds::pub::qos::PublisherQos publisher_qos()
    {
        return this->delegate()->publisher_qos();
    }

    /**
     * @brief Get the dds::pub::qos::PublisherQos from a QoS profile
     *
     * @param profile The profile from which to get the PublisherQos,
     * for example `"MyLibrary::MyProfile"`
     *
     * @return The PublisherQos that is located
     * in the specified profile
     */
    dds::pub::qos::PublisherQos publisher_qos(const std::string& profile)
    {
        return this->delegate()->publisher_qos(profile);
    }

    /**
     * @brief Get the dds::pub::qos::DataWriterQos from the default profile.
     *
     * See \ref SelectingQosProfile for information on how the default profile
     * is chosen.
     *
     * @note This function doesn't take into account the `topic_filter` used
     * in the profile, if any. See datawriter_qos_w_topic_name().
     *
     * @return The DataWriterQos
     */
    const dds::pub::qos::DataWriterQos datawriter_qos()
    {
        return this->delegate()->datawriter_qos();
    }

    /**
     * @brief Get the dds::pub::qos::DataWriterQos from a QoS profile
     *
     * @note This function doesn't take into account the `topic_filter` used
     * in the profile, if any. See datawriter_qos_w_topic_name().
     *
     * @param profile The profile from which to get the DataWriterQos,
     * for example `"MyLibrary::MyProfile"`
     *
     * @return The DataWriterQos that is located
     * in the specified profile
     */
    const dds::pub::qos::DataWriterQos datawriter_qos(
            const std::string& profile)
    {
        return this->delegate()->datawriter_qos(profile);
    }

    /**
     * @brief Get the default QosProvider.
     *
     * The default QosProvider automatically loads XML QoS, types and application
     * profiles from several predetermined locations, such as the file USER_QOS_PROFILES.xml
     * in the current working directory.
     *
     * @return The Default QosProvider
     *
     * @see \ref DefaultQosProvider
     * @see \ref Entity_default_qos
     * @see \ref DDSQosProviderExampleModule_default_provider "Default QosProvider Use Cases"
     */
    static TQosProvider Default()
    {
        return TQosProvider(DELEGATE::Default());
    }

    /**
     * @brief Reset the default settings of the default QosProvider.
     *
     *  If you change the default library or profile associated with
     * the default QosProvider, calling reset_default will set the library and
     * profile back to the default values.
     */
    static void reset_default()
    {
        DELEGATE::reset_default();
    }

};

#endif /* OMG_DDS_CORE_QOS_TPROVIDER_HPP_ */
