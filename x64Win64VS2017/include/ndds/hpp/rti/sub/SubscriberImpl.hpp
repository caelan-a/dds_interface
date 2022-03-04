/* $Id$

(c) Copyright, Real-Time Innovations, 2013-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.0a,15mar13,acr Created
============================================================================= */

#ifndef RTI_DDS_SUB_SUBSCRIBER_HPP_
#define RTI_DDS_SUB_SUBSCRIBER_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/domain/domainfwd.hpp>
#include <dds/sub/subfwd.hpp>
#include <rti/sub/qos/DataReaderQosImpl.hpp>

#include <rti/core/Entity.hpp>
#include <rti/core/detail/NativeEntity.hpp>

#include "ndds/ndds_c.h"

namespace rti { namespace sub {

namespace detail {

using namespace rti::core::detail;

OMG_DDS_API
std::pair<DDS_Entity*, bool> create_native_subscriber(
        const dds::domain::DomainParticipant& participant,
        const dds::sub::qos::SubscriberQos* qos = NULL,
        dds::sub::SubscriberListener* listener = NULL,
        const dds::core::status::StatusMask& mask =
                dds::core::status::StatusMask::all());

}  // namespace detail

/**
 * @RTI_class_definition NA
 */
class OMG_DDS_API SubscriberImpl : public rti::core::Entity {
public:
    typedef dds::sub::SubscriberListener Listener;

    // Note: the constructors need to be defined in the header, not in the .cxx
    // because detail::create_empty_listener_holder<Listener>() has a different
    // implementation when the end application is compiled with c++03 or c++11
    SubscriberImpl(const dds::domain::DomainParticipant& participant)
            : rti::core::Entity(
                    detail::create_native_subscriber(participant),
                    detail::create_empty_listener_holder<Listener>()),
              participant_(participant)
    {
    }

    SubscriberImpl(
            const dds::domain::DomainParticipant& participant,
            const dds::sub::qos::SubscriberQos& qos,
            dds::sub::SubscriberListener* listener = NULL,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : rti::core::Entity(
                    detail::create_native_subscriber(
                            participant,
                            &qos,
                            listener,
                            mask),
                    detail::create_empty_listener_holder<Listener>()),
              participant_(participant)
    {
        if (listener != NULL) {
            retain_for_listener();
        }
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    SubscriberImpl(
            const dds::domain::DomainParticipant& participant,
            const dds::sub::qos::SubscriberQos& qos,
            std::shared_ptr<Listener> listener,
            const dds::core::status::StatusMask& mask)
            : rti::core::Entity(
                    detail::create_native_subscriber(
                            participant,
                            &qos,
                            listener.get(),
                            mask),
                    detail::create_listener_holder(listener)),
              participant_(participant)
    {
    }
#endif

    // For internal use
    SubscriberImpl(DDS_Subscriber* the_native_subscriber)
            : Entity(
                    DDS_Subscriber_as_entity(the_native_subscriber),
                    detail::create_empty_listener_holder<Listener>()),
              participant_(dds::core::null)
    {
        // Rebuild the C++ participant from the native one
        DDS_DomainParticipant* native_participant =
                DDS_Subscriber_get_participant(the_native_subscriber);

        participant_ = rti::core::detail::create_from_native_entity<
                dds::domain::DomainParticipant>(native_participant);
    }

    ~SubscriberImpl();

    void notify_datareaders();

    void listener_impl(
            dds::sub::SubscriberListener* the_listener,
            const ::dds::core::status::StatusMask& event_mask,
            bool retain = true);
    dds::sub::SubscriberListener* listener_impl() const;

#ifndef RTI_NO_CXX11_SMART_PTR
    void set_listener_impl(
            std::shared_ptr<Listener> the_listener,
            const dds::core::status::StatusMask& mask)
    {
        assert_not_closed();
        listener_impl(the_listener.get(), mask, false);
        rti::core::detail::set_listener(listener_holder_, the_listener);
    }

    void set_listener_impl(std::shared_ptr<Listener> the_listener)
    {
        if (the_listener) {
            set_listener_impl(the_listener, dds::core::status::StatusMask::all());
        } else {
            set_listener_impl(nullptr, dds::core::status::StatusMask::none());
        }
    }

    std::shared_ptr<Listener> get_listener_impl() const
    {
        assert_not_closed();
        return rti::core::detail::get_listener<Listener>(listener_holder_);
    }
#endif

    const dds::sub::qos::SubscriberQos qos() const;
    void qos(const dds::sub::qos::SubscriberQos& the_qos);

    dds::sub::qos::DataReaderQos default_datareader_qos();
    SubscriberImpl& default_datareader_qos(
            const dds::sub::qos::DataReaderQos& qos);

    const dds::domain::DomainParticipant& participant() const;

    /**
     * @memberof dds::sub::Subscriber
     * @brief @extension Closes all the entities created from this Subscriber
     * @extension_member_note
     *
     * @note Calling this function explicitly is not necessary to close a
     * Subscriber.
     *
     * @dref_details_Subscriber_delete_contained_entities
     */
    void close_contained_entities()
    {
        close_contained_entities_impl(true);
    }

    // --- From Entity: -------------------------------------------------------
    void close()
    {
        close_impl(true);
    }

    // --- For internal use: --------------------------------------------------
    DDS_Subscriber* native_subscriber()
    {
        return (DDS_Subscriber*) native_entity();
    }

    const DDS_Subscriber* native_subscriber() const
    {
        return (const DDS_Subscriber*) native_entity();
    }

private:
    void close_impl(bool force_close);
    void close_contained_entities_impl(bool force_close);

    dds::domain::DomainParticipant participant_;
};

}}  // namespace rti::sub

#endif  // RTI_DDS_SUB_SUBSCRIBER_HPP_
