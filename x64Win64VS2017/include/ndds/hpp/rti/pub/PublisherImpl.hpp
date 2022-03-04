/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.0a,12feb13,acr Created
============================================================================= */

#ifndef RTI_DDS_PUB_PUBLISHER_HPP_
#define RTI_DDS_PUB_PUBLISHER_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/ref_traits.hpp>
#include <dds/domain/domainfwd.hpp>
#include <dds/pub/pubfwd.hpp>

#include <rti/core/Entity.hpp>
#include <rti/core/detail/ListenerHolder.hpp>
#include <rti/core/detail/NativeEntity.hpp>

#include "ndds/ndds_c.h"

namespace rti { namespace pub {

namespace detail {

using namespace rti::core::detail;

// A helper function for the Publisher constructor.
// We implement the creation of the native entity in a helper function
// to be able to pass it directly to the Entity base ctor and avoid a
// two-phase construction. (See Publisher constructor.)
OMG_DDS_API
std::pair<DDS_Entity*, bool> create_native_publisher(
        const dds::domain::DomainParticipant& participant,
        const dds::pub::qos::PublisherQos* qos = NULL,
        dds::pub::PublisherListener* listener = NULL,
        const dds::core::status::StatusMask& mask =
                dds::core::status::StatusMask::all());

}  // namespace detail

/**
 * @RTI_class_definition NA
 */
class OMG_DDS_API PublisherImpl : public rti::core::Entity {
public:
    typedef dds::pub::PublisherListener Listener;

    PublisherImpl(const dds::domain::DomainParticipant& participant)
            : rti::core::Entity(
                    detail::create_native_publisher(participant),
                    detail::create_empty_listener_holder<Listener>()),
              participant_(participant)
    {
    }

    PublisherImpl(
            const dds::domain::DomainParticipant& participant,
            const dds::pub::qos::PublisherQos& qos,
            dds::pub::PublisherListener* listener = NULL,
            const dds::core::status::StatusMask& mask =
                    dds::core::status::StatusMask::all())
            : rti::core::Entity(
                    detail::create_native_publisher(
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
    PublisherImpl(
            const dds::domain::DomainParticipant& participant,
            const dds::pub::qos::PublisherQos& qos,
            std::shared_ptr<Listener> listener,
            const dds::core::status::StatusMask& mask)
            : rti::core::Entity(
                    detail::create_native_publisher(
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
    PublisherImpl(DDS_Publisher* the_native_publisher)
            : Entity(
                    DDS_Publisher_as_entity(the_native_publisher),
                    detail::create_empty_listener_holder<Listener>()),
              participant_(dds::core::null)
    {
        // Rebuild the C++ participant from the native one
        DDS_DomainParticipant* native_participant =
                DDS_Publisher_get_participant(the_native_publisher);

        participant_ = rti::core::detail::create_from_native_entity<
                dds::domain::DomainParticipant>(native_participant);
    }

    ~PublisherImpl();

    void listener_impl(
        dds::pub::PublisherListener * the_listener,
        const ::dds::core::status::StatusMask& event_mask,
        bool retain = true);
    dds::pub::PublisherListener * listener_impl() const;

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

    const dds::pub::qos::PublisherQos qos() const;
    void qos(const dds::pub::qos::PublisherQos& the_qos);

    dds::pub::qos::DataWriterQos default_writer_qos();
    PublisherImpl& default_writer_qos(const dds::pub::qos::DataWriterQos& qos);

    void wait_for_acknowledgments(const dds::core::Duration& max_wait);

    // Extension
    /**
     * @memberof dds::pub::Publisher
     *
     * \dref_Publisher_wait_for_asynchronous_publishing
     */
    void wait_for_asynchronous_publishing(const dds::core::Duration& max_wait);

    const dds::domain::DomainParticipant& participant() const;

    /**
     * @memberof dds::pub::Publisher
     * @brief @extension Closes all the entities created from this Publisher
     * @extension_member_note
     *
     * @note Calling this function explicitly is not necessary to close a
     * Publisher.
     *
     * @dref_details_Publisher_delete_contained_entities
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
    DDS_Publisher * native_publisher()
    {
        return (DDS_Publisher *) native_entity();
    }

    const DDS_Publisher * native_publisher() const
    {
        return (const DDS_Publisher *) native_entity();
    }

private:
    void close_impl(bool force_close);
    void close_contained_entities_impl(bool force_close);

    dds::domain::DomainParticipant participant_;
};

}}  // namespace pub::detail

#endif // RTI_DDS_PUB_PUBLISHER_HPP_
