#ifndef OMG_TDDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_
#define OMG_TDDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_

/* Copyright 2010, Object Management Group, Inc.
 * Copyright 2010, PrismTech, Corp.
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

#include <string>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/detail/conformance.hpp>
#include <dds/core/types.hpp>
#include <dds/core/Time.hpp>
#include <dds/core/TEntity.hpp>
#include <dds/domain/qos/DomainParticipantQos.hpp>
#include <dds/domain/qos/DomainParticipantFactoryQos.hpp>

#include <dds/topic/qos/TopicQos.hpp>
#include <dds/pub/qos/PublisherQos.hpp>
#include <dds/sub/qos/SubscriberQos.hpp>

namespace dds {

namespace domain {


template<typename DELEGATE> class TDomainParticipant;
class DomainParticipantListener;

} } // namespace dds::domain

/**
 * @ingroup DDSDomainParticipantModule
 */

/**
 * @RTI_class_definition class dds::domain::DomainParticipant : public dds::core::Entity
 * @headerfile dds/domain/DomainParticipant.hpp
 * @brief @st_ref_type Container for all \p dds::core::Entity objects.
 * @details @dref_Shared_domain_participant_description
 *
 * @see dds::core::QosProvider::create_participant_from_config to create a
 * DomainParticipant from an XML definition
 * @see \ref DDSParticipantExampleModule
 * @see \ref DDSEntityExampleModuleForCpp2
 */
template<typename DELEGATE>
class dds::domain::TDomainParticipant : public dds::core::TEntity<DELEGATE> {
public:
    /**
     * @brief The Listener type that DomainParticipants use
     */
    typedef DomainParticipantListener Listener;

    /**
     * @brief Create a new DomainParticipant with default Qos
     *
     * Same as DomainParticipant(int32_t, const dds::domain::qos::DomainParticipantQos&, dds::domain::DomainParticipantListener*, const dds::core::status::StatusMask&)
     * except that it uses \ref Entity_default_qos "the default DomainParticipantQos"
     */
    // Spec error CPPPSM-246: Can't create a participant on domain
    // 0 if domain_id is of type uint32_t--changed it to int32_t
    explicit TDomainParticipant(int32_t the_domain_id)
        : dds::core::TEntity<DELEGATE>(new DELEGATE(the_domain_id))
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * @brief Create a new DomainParticipant.
     *
     * @deprecated When using a listener, prefer the constructor that receives
     * a `shared_ptr<Listener>` instead of a regular `Listener*` pointer.
     *
     * The DomainParticipant signifies that the application intends to join the
     * Domain identified by the domain_id argument.
     *
     * @param the_domain_id the id of the domain joined by this
     * DomainParticipant. \range [>=0], and does not violate guidelines stated
     * in \idref_RtpsWellKnownPorts_t.
     * @param the_qos The QoS settings for this DomainParticipant. See also
     * set_qos().
     * @param the_listener The listener (NULL by default)
     * @param mask Changes of communication status to be invoked on the listener.
     *
     * @details \dref_details_DomainParticipantFactory_create_participant
     */
    TDomainParticipant(
            int32_t the_domain_id,
            const dds::domain::qos::DomainParticipantQos& the_qos,
            dds::domain::DomainParticipantListener* the_listener = NULL,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : dds::core::TEntity<DELEGATE>(
                    new DELEGATE(the_domain_id, the_qos, the_listener, mask))
    {
        this->delegate()->remember_reference(this->delegate());
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    /**
     * @brief Create a new DomainParticipant.
     *
     * The DomainParticipant signifies that the application intends to join the
     * Domain identified by the domain_id argument.
     *
     * @param the_domain_id the id of the domain joined by this
     * DomainParticipant. \range [>=0], and does not violate guidelines stated
     * in \idref_RtpsWellKnownPorts_t.
     * @param the_qos The QoS settings for this DomainParticipant. See also
     * set_qos().
     * @param the_listener A shared_ptr to the listener. See set_listener() for
     * more information.
     * @param mask Changes of communication status to be invoked on the listener.
     *
     * @details \dref_details_DomainParticipantFactory_create_participant
     */
    TDomainParticipant(
            int32_t the_domain_id,
            const dds::domain::qos::DomainParticipantQos& the_qos,
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : dds::core::TEntity<DELEGATE>(
                    new DELEGATE(the_domain_id, the_qos, the_listener, mask))
    {
        this->delegate()->remember_reference(this->delegate());
    }
#endif

    // Spec error: this method needs an additional parameter
    // to disambiguate with respect to TDomainParticipant(uint32_t id)
    // For internal use only
    TDomainParticipant(
        dds::core::construct_from_native_tag_t, DELEGATE* the_delegate)
        : dds::core::TEntity<DELEGATE>(the_delegate)
    {
        this->delegate()->remember_reference(this->delegate());
    }

    OMG_DDS_BASIC_REF_TYPE(TDomainParticipant, dds::core::TEntity, DELEGATE)

    /**
     * @brief Register a listener with the DomainParticipant.
     *
     * @deprecated The use of `set_listener()` is recommended. Unlike this
     * function, `set_listener` receives a `shared_ptr` which simplifies the
     * management of listener's lifecycle.
     */
    void listener(Listener* l, const dds::core::status::StatusMask& mask)
    {
        this->delegate()->listener_impl(l, mask);
    }


    /**
     * @brief Get the DomainParticipant listener.
     *
     * @deprecated Prefer `get_listener()` instead of this function.
     *
     * @return The existing listener attached to the DomainParticipant or
     * NULL if no listener has been set.
     */
    Listener* listener() const
    {
        return this->delegate()->listener_impl();
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    /**
     * @brief Sets the listener associated with this participant.
     *
     * The DomainParticipant will hold the `shared_ptr`, ensuring that the
     * listener is not deleted at least until this DomainParticipant is deleted
     * or the listener is reset with `set_listener(nullptr)`.
     *
     * @warning It's recommended that the listener implementation doesn't hold
     * a permanent reference to the participant. If it does, the application
     * needs to manually reset the listener or manually close this participant
     * to ensure that there is no cycle that prevents the destruction of these
     * two objects.
     *
     * @param the_listener A shared pointer to the listener to receive status
     * updates or `nullptr` to reset the current listener and stop receiving
     * status updates.
     * @param event_mask A mask that indicates which status updates will be
     * notified to the listener
     *
     * @details \dref_details_DomainParticipant_set_listener
     */
    void set_listener(
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& event_mask)
    {
        this->delegate()->set_listener_impl(the_listener, event_mask);
    }

    /**
     * @brief Sets the listener associated with this participant
     *
     * If `the_listener` is not `nullptr`, this overload is equivalent to:
     * ```
     * participant.set_listener(the_listener,
     * dds::core::status::StatusMask::all());
     * ```
     *
     * If `the_listener` is `nullptr`, it is equivalent to:
     * ```
     * participant.set_listener(nullptr, dds::core::status::StatusMask::none());
     * ```
     *
     * @param the_listener A shared pointer to the listener to receive status
     * updates or `nullptr` to reset the current listener and stop receiving
     * status updates.
     */
    void set_listener(std::shared_ptr<Listener> the_listener)
    {
        this->delegate()->set_listener_impl(the_listener);
    }

    /**
     * @brief Returns the listener currently associated with this participant.
     *
     * @return The shared pointer to the current listener or `nullptr` if there
     * is currently no listener associated to this entity.
     */
    std::shared_ptr<Listener> get_listener() const
    {
        return this->delegate()->get_listener_impl();
    }
#endif

    /**
     * @brief Gets the current QoS policies of this DomainParticipant.
     *
     * @return The current QoS policies.
     */
    const dds::domain::qos::DomainParticipantQos qos() const
    {
        return this->delegate()->qos();
    }

    /**
     * @brief Set the DomainParticipantQos setting for this DomainParticipant
     * instance.
     *
     * @param the_qos Set of policies to be applied to the DomainParticipant.
     * Immutable policies cannot be changed after this entity has been enabled.
     *
     * @throw dds::core::ImmutablePolicyError if \p the_qos contains a different
     * value for an immutable policy.
     * @throw dds::core::InconsistentPolicyError if some policies are inconsistent.
     *
     * @see dds::domain::qos::DomainParticipantQos for rules on consistency
     * among QoS policies
     * @see \ref Entity_set_qos
     * @see default_participant_qos()
     * @see dds::core::QosProvider::participant_qos()
     */
    void qos(const dds::domain::qos::DomainParticipantQos& the_qos)
    {
        this->delegate()->qos(the_qos);
    }

    /**
     * @brief Equivalent to set_qos(the_qos)
     */
    TDomainParticipant& operator <<(const dds::domain::qos::DomainParticipantQos& the_qos)
    {
        qos(the_qos);
        return *this;
    }

    /**
     * @brief Equivalent to `get_qos()`
     *
     * @param the_qos the new qos for this DomainParticipant.
     */
    const TDomainParticipant& operator >> (dds::domain::qos::DomainParticipantQos& the_qos) const
    {
        the_qos = qos();
        return *this;
    }

    /**
     * @brief Get the unique domain identifier.
     *
     * @details @dref_Shared_domain_id_description
     * @return the domain id
     */
    int32_t domain_id() const
    {
        return this->delegate()->domain_id();
    }

    /**
     * @brief Manually assert the liveliness of the DomainParticipant.
     *
     * @dref_Shared_liveliness
     */
    void assert_liveliness()
    {
        this->delegate()->assert_liveliness();
    }

    /**
     * @brief Check whether or not the given handle represents an Entity that
     * was created from the DomainParticipant.
     *
     * @details \dref_details_DomainParticipant_contains_entity
     */
    bool contains_entity(const dds::core::InstanceHandle& a_handle)
    {
        return this->delegate()->contains_entity(a_handle);
    }

    /**
     * @brief Get the current time.
     *
     * @details \dref_details_DomainParticipant_get_current_time
     * @return The current time
     */
     dds::core::Time current_time()
     {
         return this->delegate()->current_time();
     }

public:

    /**
     * @brief Set the
     * dds::domain::qos::DomainParticipantFactoryQos
     *
     * @param qos The DomainParticipantFactoryQos to set.
     */
    static void participant_factory_qos(
       const dds::domain::qos::DomainParticipantFactoryQos& qos)
    {
        DELEGATE::participant_factory_qos(qos);
    }

    /**
     * @brief Get the current dds::domain::qos::DomainParticipantFactoryQos
     *
     * @return The current DomainParticipantFactoryQos
     */
    static dds::domain::qos::DomainParticipantFactoryQos participant_factory_qos()
    {
        return DELEGATE::participant_factory_qos();
    }

    /**
     * @brief Finalize the DomainParticipantFactory.
     *
     * The DomainParticipantFactory is a singleton that the C++ API
     * uses implicitly to create participants. RTI Connext provides
     * this operation for users who want to release memory used by
     * the participant factory.
     *
     * @warning This method uses a static variable. To avoid undefined behavior
     * in the order of destruction it shouldn't be called in the destructor
     * of a type for which other global or static variables exist.
     */
    static void finalize_participant_factory()
    {
        DELEGATE::finalize_participant_factory();
    }

    // --- DomainParticipant QoS Defaults --- //

    /**
     * @brief Get the current
     *        DomainParticipantQos for this instance.
     *
     * @return The current DomainParticipantQos
     *
     * @see \ref Entity_default_qos
     */
    static dds::domain::qos::DomainParticipantQos default_participant_qos()
    {
        return DELEGATE::default_participant_qos();
    }

    /**
     * @brief Set the DomainParticipantQos
     *
     * The UserData and EntityFactory policies can be changed. The other
     * policies are immutable.
     *
     * @param qos The DomainParticipantQos to set.
     *
     * @see \ref Entity_default_qos
     */
    static void default_participant_qos(
        const dds::domain::qos::DomainParticipantQos& qos)
    {
        DELEGATE::default_participant_qos(qos);
    }

    /**
     * @brief Get the current default dds::pub::qos::PublisherQos.
     *
     * @details The retrieved qos will match the set of values specified on the
     * last successful call to
     * default_publisher_qos(const dds::pub::qos::PublisherQos& qos),
     * or else, if the call was never made, the \ndds default values for the
     * dds::pub::qos::PublisherQos.
     *
     * This method may potentially allocate memory depending on the sequences
     * contained in some QoS policies.
     *
     * If no PublisherQos is specified when a dds::pub::Publisher is constructed,
     * the default value of the QoS set in the factory, equivalent to the
     * value obtained by calling this method, will be used to create the
     * Publisher.
     * @dref_Shared_get_default_publisher_qos_mtsafety
     * @return The current default PublisherQos
     */
    dds::pub::qos::PublisherQos default_publisher_qos() const
    {
        return this->delegate()->default_publisher_qos();
    }

    /**
     * @brief Set the default dds::pub::qos::PublisherQos for this
     * DomainParticipant.
     *
     * @details This set of default values will be used for a newly created
     * dds::pub::Publisher if no dds::pub::qos::PublisherQos is specified when
     * constructing the Publisher.
     * @dref_Shared_set_default_publisher_qos or creating a Publisher with
     * default QoS values.
     *
     * @param the_qos The PublisherQos to set.
     * @return This DomainParticipant instance
     * @throw One of the standard @ref DDSException,
     * or dds::core::InconsistentPolicyError
     */
    TDomainParticipant& default_publisher_qos(
        const dds::pub::qos::PublisherQos& the_qos)
    {
        this->delegate()->default_publisher_qos(the_qos);
        return *this;
    }

    /**
     * @brief Get the current default dds::sub::qos::SubscriberQos.
     * \dref_details_DomainParticipant_get_default_subscriber_qos
     *
     * @return The current default SubscriberQos
     */
    dds::sub::qos::SubscriberQos default_subscriber_qos() const
    {
        return this->delegate()->default_subscriber_qos();
    }

    /**
     * @brief Set the default dds::sub::qos::SubscriberQos for this
     * DomainParticipant.
     *
     * \dref_details_DomainParticipant_set_default_subscriber_qos
     *
     * @param the_qos The SubscriberQos to set.
     * @throw One of the standard @ref DDSException,
     * or dds::core::InconsistentPolicyError
     */
    TDomainParticipant& default_subscriber_qos(
        const dds::sub::qos::SubscriberQos& the_qos)
    {
        this->delegate()->default_subscriber_qos(the_qos);
        return *this;
    }

    /**
     * @brief Get the current default dds::topic::qos::TopicQos.
     *
     * @details The retrieve d qos will match the set of values specified on the
     * last successful call to
     * default_topic_qos(const dds::topic::qos::TopicQos& qos),
     * or else, if the call was never made, the \ndds default values for the
     * dds::topic::qos::TopicQos.
     *
     * This method may potentially allocate memory depending on the sequences
     * contained in some QoS policies.
     *
     * If no TopicQos is specified when a dds::topic::Topic is constructed,
     * the default value of the QoS set in the factory, equivalent to the
     * value obtained by calling this method, will be used to create the
     * Topic.
     * @dref_Shared_get_default_topic_qos_mtsafety
     * @return The current default TopicQos
     */
    dds::topic::qos::TopicQos default_topic_qos() const
    {
        return this->delegate()->default_topic_qos();
    }

    /**
     * @brief Set the default dds::topic::qos::TopicQos for this
     * DomainParticipant.
     *
     * @details This set of default values will be used for a newly created
     * dds::topic::Topic if no dds::topic::qos::TopicQos is specified when
     * constructing the Topic.
     * @dref_Shared_set_default_topic_qos or creating a Topic with
     * default QoS values.
     *
     * @param the_qos The TopicQos to set.
     * @return This DomainParticipant instance
     * @throw One of the standard @ref DDSException,
     * or dds::core::InconsistentPolicyError
     */
    TDomainParticipant& default_topic_qos(const dds::topic::qos::TopicQos& the_qos)
    {
        this->delegate()->default_topic_qos(the_qos);
        return *this;
    }
};


#endif /* OMG_TDDS_DOMAIN_DOMAIN_PARTICIPANT_HPP_ */
