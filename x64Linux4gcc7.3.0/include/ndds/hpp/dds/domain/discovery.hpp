#ifndef OMG_DDS_DOMAIN_DISCOVERY_HPP_
#define OMG_DDS_DOMAIN_DISCOVERY_HPP_

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

#include <dds/domain/DomainParticipant.hpp>
#include <dds/core/InstanceHandle.hpp>
#include <dds/topic/BuiltinTopic.hpp>

namespace dds { namespace domain {

/**
 * @relatesalso dds::domain::DomainParticipant
 * @brief Instructs @ndds to locally ignore a remote
 * dds::domain::DomainParticipant.
 *
 * \p \#include \p <dds/domain/discovery.hpp>
 *
 * @details @dref_Shared_ignore_participant
 * @param participant The DomainParticipant for which the remote entity will
 * be ignored.
 * @param handle The dds::core::InstanceHandle of the remote entity that will
 * be ignored.
 *
 */
OMG_DDS_API
void ignore(
    const dds::domain::DomainParticipant& participant,
    const dds::core::InstanceHandle& handle);

/**
 * @relatesalso dds::domain::DomainParticipant
 *
 * @brief Instructs @ndds to locally ignore a group of remote
 * dds::domain::DomainParticipant.
 *
 * \p \#include \p <dds/domain/discovery.hpp>
 *
 * The series of entities whose instance handles are made available via the
 * provided iterators will be ignored.
 *
 * @param participant The DomainParticipant for which the remote
 *                entity will be ignored
 *
 * @param begin The begin iterator for the series of InstanceHandles to ignore
 * @param end The end iterator for the series of InstanceHandles to ignore
 *
 * @see ignore(const dds::domain::DomainParticipant& participant, const dds::core::InstanceHandle& handle)
 */
template<typename FwdIterator>
void ignore(
    const dds::domain::DomainParticipant& participant,
    FwdIterator begin,
    FwdIterator end)
{
    while (begin != end) {
        ignore(participant, *begin);
        ++begin;
    }
}

/**
 * @relatesalso dds::domain::DomainParticipant
 *
 * @brief @extension Retrieves the list of other participants discovered by
 * this participant
 *
 * \p \#include \p <dds/domain/discovery.hpp>
 *
 * @details \dref_details_DomainParticipant_get_discovered_participants
 */
OMG_DDS_API
dds::core::InstanceHandleSeq discovered_participants(
        const dds::domain::DomainParticipant& participant);

/**
 * @relatesalso dds::domain::DomainParticipant
 *
 * @brief @extension Retrieves the list of other participants discovered by
 * this participant
 *
 * \p \#include \p <dds/domain/discovery.hpp>
 *
 * @tparam FwdIterator A forward iterator whose value type is dds::core::InstanceHandleSeq
 *
 * This overload copies the instance handles into an iterator range.
 *
 * @param participant The participant whose discovered participants are looked up
 * @param begin The begin iterator where to copy the instance handles
 * @param end One past the last position where instance handles are copied
 */
template <typename FwdIterator>
FwdIterator discovered_participants(
        const dds::domain::DomainParticipant& participant,
        FwdIterator begin,
        FwdIterator end)
{
    dds::core::InstanceHandleSeq participants =
            discovered_participants(participant);

    for (dds::core::InstanceHandleSeq::const_iterator it = participants.begin();
        begin != end && it != participants.end();
        ++begin, ++it) {

        *begin = *it;
    }

    return begin;
}

/**
 * @relatesalso dds::domain::DomainParticipant
 *
 * @brief @extension Retrieves the information about one participant discovered
 * by this participant
 *
 * \p \#include \p <dds/domain/discovery.hpp>
 *
 * @details \dref_details_DomainParticipant_get_discovered_participant_data
 */
OMG_DDS_API
dds::topic::ParticipantBuiltinTopicData discovered_participant_data(
        const dds::domain::DomainParticipant& participant,
        const dds::core::InstanceHandle& participant_handle);

} }

#include <dds/domain/detail/discovery_back_comp.hpp>

#endif /* OMG_DDS_DOMAIN_DISCOVERY_HPP_ */
