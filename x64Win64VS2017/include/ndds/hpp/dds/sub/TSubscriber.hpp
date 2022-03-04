#ifndef OMG_TDDS_SUB_SUBSCRIBER_HPP_
#define OMG_TDDS_SUB_SUBSCRIBER_HPP_

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

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/TEntity.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <dds/sub/qos/DataReaderQos.hpp>

namespace dds { namespace sub {
  template <typename DELEGATE>
  class TSubscriber;

  class SubscriberListener;
} }

/** 
 * @ingroup DDSSubscriberModule 
 *  
 * @RTI_class_definition class dds::sub::Subscriber : public dds::core::Entity
 * @headerfile Subscriber.hpp "dds/sub/Subscriber.hpp"
 *  
 * @brief @st_ref_type A subscriber is the object responsible for actually 
 * receiving data from a subscription.
 * 
 * @details \dref_details_Subscriber
 *  
 * @see \ref DDSEntityExampleModuleForCpp2
 */
template<typename DELEGATE>
class dds::sub::TSubscriber : public dds::core::TEntity<DELEGATE> {
public:
    typedef dds::sub::SubscriberListener Listener;

public:
    OMG_DDS_BASIC_REF_TYPE(TSubscriber, dds::core::TEntity, DELEGATE)

    /**
     * @brief Create a Subscriber attached to the given 
     * DomainParticipant.
     *  
     * The subscriber QoS will be set to participant.default_subscriber_qos()
     *
     * @param the_participant the DomainParticipant that will own this subscriber.
     */
    explicit TSubscriber(const ::dds::domain::DomainParticipant& the_participant)
        : dds::core::TEntity<DELEGATE>(new DELEGATE(the_participant))
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * @brief Create a Subscriber attached to the given DomainParticipant.
     *
     * @deprecated When using a listener, prefer the constructor that receives a
     * `shared_ptr<Listener>` instead of a regular `Listener*` pointer.
     *
     * @param dp The DomainParticipant that will own this subscriber.
     * @param the_qos The qos::SubscriberQos
     * @param the_listener The subscriber listener.
     * @param mask Indicates which status updates the listener will receive
     */
    TSubscriber(
        const ::dds::domain::DomainParticipant& dp,
        const dds::sub::qos::SubscriberQos& the_qos,
        dds::sub::SubscriberListener* the_listener = NULL,
        const dds::core::status::StatusMask& mask =
            dds::core::status::StatusMask::all())
        : dds::core::TEntity<DELEGATE>(new DELEGATE(dp, the_qos, the_listener, mask))
    {
        this->delegate()->remember_reference(this->delegate());
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    /**
     * @brief Create a Subscriber attached to the given DomainParticipant.
     *
     * @param dp The DomainParticipant that will own this subscriber.
     * @param the_qos The qos::SubscriberQos
     * @param the_listener A shared_ptr to the listener. See set_listener() for
     * more information.
     * @param mask Indicates which status updates the listener will receive
     */
    TSubscriber(
            const ::dds::domain::DomainParticipant& dp,
            const dds::sub::qos::SubscriberQos& the_qos,
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : dds::core::TEntity<DELEGATE>(
                    new DELEGATE(dp, the_qos, the_listener, mask))
    {
        this->delegate()->remember_reference(this->delegate());
    }
#endif

    // For internal use only
    TSubscriber(dds::core::construct_from_native_tag_t, DELEGATE* the_delegate)
        : dds::core::TEntity<DELEGATE>(the_delegate)
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * @brief This operation invokes the operation on_data_available on the
     * DataReaderListener objects attached to contained DataReader
     * entities with a DATA_AVAILABLE status that is 
     * considered changed as described in \ref Status_changes_read. 
     *  
     * \dref_details_Subscriber_notify_datareaders 
     */
    void notify_datareaders()
    {
        this->delegate()->notify_datareaders();
    }

    /**
     * @brief Attach a listener to this Subscriber
     *
     * @deprecated The use of `set_listener()` is recommended. Unlike this
     * function, `set_listener` receives a `shared_ptr` which simplifies the
     * management of listener's lifecycle.
     *
     * @param the_listener The listener
     * @param event_mask The event mask for the listener.
     */
    void listener(
        Listener* the_listener,
        const dds::core::status::StatusMask& event_mask)
    {
        this->delegate()->listener_impl(the_listener, event_mask);
    }

    /**
     * @brief Get the Subscriber listener.
     *
     * @deprecated Use `get_listener` instead of this function.
     */
    Listener* listener() const
    {
        return this->delegate()->listener_impl();
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    /**
     * @brief Sets the listener associated with this subscriber
     *
     * The Subscriber will hold a `shared_ptr` to the listener argument,
     * ensuring that it is not deleted at least until this Subscriber is deleted
     * or the listener is reset with `set_listener(nullptr)`.
     *
     * @warning It's recommended that the listener implementation doesn't hold
     * a permanent reference to the Subscriber. If it does, the application
     * needs to manually reset the listener or manually close this Subscriber to
     * ensure that there is no cycle that prevents the destruction of these two
     * objects.
     *
     * @param the_listener A shared pointer to the listener to receive status
     * updates or `nullptr` to reset the current listener and stop receiving
     * status updates.
     * @param event_mask A mask that indicates which status updates will be
     * notified to the listener
     */
    void set_listener(
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& event_mask)
    {
        this->delegate()->set_listener_impl(the_listener, event_mask);
    }

    /**
     * @brief Sets the listener associated with this subscriber
     *
     * If `the_listener` is not `nullptr`, this overload is equivalent to:
     * ```
     * subscriber.set_listener(the_listener, dds::core::status::StatusMask::all());
     * ```
     *
     * If `the_listener` is `nullptr`, it is equivalent to:
     * ```
     * subscriber.set_listener(nullptr, dds::core::status::StatusMask::none());
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
     * @brief Returns the listener currently associated with this Subscriber.
     *
     * @return The shared pointer to the current listener or `nullptr` if there
     * is currently no listener associated to this entity.
     */
    std::shared_ptr<Listener> get_listener() const
    {
        return this->delegate()->get_listener_impl();
    }
#endif

    // Spec issue CPPPSM-217: return by value, not by reference
    /**
     * @brief Get the Subscriber QoS.
     */ 
    const dds::sub::qos::SubscriberQos qos() const
    {
        return this->delegate()->qos();
    }

    /**
     * @brief Set the Subscriber QoS.
     * 
     * @param the_qos the new QoS.
     */
    void qos(const dds::sub::qos::SubscriberQos& the_qos)
    {
        this->delegate()->qos(the_qos);
    }

    /**
     * @brief Get the default DataReader QoS.
     * 
     * @return dds::sub::qos::DataReaderQos 
     */
    dds::sub::qos::DataReaderQos default_datareader_qos() const
    {
        return this->delegate()->default_datareader_qos();
    }

    /**
     * @brief Set the default DataReaderQoS.
     *  
     * @param the_qos The default DataReaderQoS.
     */
    TSubscriber& default_datareader_qos(const dds::sub::qos::DataReaderQos& the_qos)
    {
        this->delegate()->default_datareader_qos(the_qos);
        return *this;
    }

    /**
     * @brief Return the DomainParticipant that owns this Subscriber.
     * 
     * @return const dds::domain::DomainParticipant& The DomainParticipant that 
     * owns this subscriber 
     */
    const dds::domain::DomainParticipant& participant() const
    {
        return this->delegate()->participant();
    }
};


#endif /* OMG_TDDS_SUB_SUBSCRIBER_HPP_ */
