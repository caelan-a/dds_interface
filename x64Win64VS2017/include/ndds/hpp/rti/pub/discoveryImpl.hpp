/* $Id$

(c) Copyright, Real-Time Innovations, 2013-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.0a,14mar13,acr Created
============================================================================= */

#ifndef RTI_DDS_PUB_DISCOVERY_IMPL_HPP_
#define RTI_DDS_PUB_DISCOVERY_IMPL_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/topic/BuiltinTopic.hpp>
#include <dds/core/InstanceHandle.hpp>
#include <dds/domain/domainfwd.hpp>
#include <rti/core/Locator.hpp>
#include <rti/pub/pubfwd.hpp>

namespace rti { namespace pub {

void ignore(
    dds::domain::DomainParticipant& participant,
    const dds::core::InstanceHandle& handle);

OMG_DDS_API
dds::core::InstanceHandleSeq matched_subscriptions(
    const UntypedDataWriter& writer);

OMG_DDS_API
dds::topic::SubscriptionBuiltinTopicData matched_subscription_data(
    const UntypedDataWriter& writer,
    const dds::core::InstanceHandle& handle);

// Extensions

OMG_DDS_API
dds::topic::ParticipantBuiltinTopicData matched_subscription_participant_data_impl(
    const UntypedDataWriter& writer,
    const dds::core::InstanceHandle& handle);

template <typename T>
dds::topic::ParticipantBuiltinTopicData matched_subscription_participant_data(
    const dds::pub::DataWriter<T>& writer,
    const dds::core::InstanceHandle& handle)
{
    return rti::pub::matched_subscription_participant_data_impl(
        *writer.delegate().get(), handle);
}

OMG_DDS_API
rti::core::LocatorSeq matched_subscriptions_locators_impl(
    const UntypedDataWriter& writer);

/**
 * @relatesalso dds::pub::DataWriter
 * @headerfile rti/pub/discoveryImpl.hpp
 * @brief @extension Retrieve the list of locators for subscriptions currently
 * associated with this DataWriter.
 *
 * The locators returned are the ones that are used by the DDS implementation
 * to communicate with the corresponding matched DataReaders.
 *
 * @tparam T The topic-type that the DataWriter publishes.
 * @param writer The DataWriter.
 * 
 * @return The list of locators
 */
template<typename T>
rti::core::LocatorSeq matched_subscriptions_locators(
    const dds::pub::DataWriter<T>& writer)
{
    return rti::pub::matched_subscriptions_locators_impl(
        *writer.delegate().get());
}

OMG_DDS_API
bool is_matched_subscription_active_impl(
    const UntypedDataWriter& writer,
    const dds::core::InstanceHandle& handle);

/**
 * @relatesalso dds::pub::DataWriter
 * @headerfile rti/pub/discoveryImpl.hpp
 * @brief @extension Check if a matched subscription is active.
 *
 * @namespace_note rti::pub
 *
 * @tparam T The topic-type that the DataWriter publishes.
 * @param writer The DataWriter.
 * @param handle The dds::core::InstanceHandle of the matched subscription.
 *
 * \dref_details_DataWriter_is_matched_subscription_active
 */
template <typename T>
bool is_matched_subscription_active(
        const dds::pub::DataWriter<T>& writer,
        const dds::core::InstanceHandle& handle)
{
    return is_matched_subscription_active_impl(*writer.delegate().get(), handle);
}

OMG_DDS_API
std::vector<dds::topic::SubscriptionBuiltinTopicData> matched_subscription_data_impl(
        const UntypedDataWriter& writer);

/**
 * @relatesalso dds::pub::DataWriter
 * @headerfile rti/pub/discoveryImpl.hpp
 * @brief @extension Obtain the SubscriptionBuiltinTopicData for all of the
 * subscriptions matched with a DataWriter.
 *
 * @namespace_note rti::pub
 *
 * @details This API retrieves the matched publication data from all of the
 * subscriptions currently matched a DataWriter.
 * 
 * @tparam T The topic-type that the DataWriter publishes.
 * @param writer The DataWriter.
 *
 * @return A std::vector containing all of the matched subscription data.
 */
template <typename T>
std::vector<dds::topic::SubscriptionBuiltinTopicData> matched_subscription_data(
        const dds::pub::DataWriter<T>& writer)
{
    return matched_subscription_data_impl(*writer.delegate().get());
}

} } // namespace rti::pub

#endif // RTI_DDS_PUB_DISCOVERY_IMPL_HPP_
