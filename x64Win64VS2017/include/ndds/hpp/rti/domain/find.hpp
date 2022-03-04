#ifndef OMG_RTI_DDS_DOMAIN_FIND_HPP_
#define OMG_RTI_DDS_DOMAIN_FIND_HPP_

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

#include <dds/core/corefwd.hpp>
#include <dds/domain/DomainParticipant.hpp>
#include <rti/core/detail/NativeEntity.hpp>

namespace rti { namespace domain {

/**
 * @relatesalso dds::domain::DomainParticipant
 * @headerfile rti/domain/find.hpp
 *
 * @brief @extension Locates an existing dds::domain::DomainParticipant by name.
 *
 * @note \p \#include \p <rti/domain/find.hpp>
 * This function is in the `rti::domain` namespace
 *
 * If no such DomainParticipant exists, the operation will return
 * dds::core::null.
 */
OMG_DDS_API
dds::domain::DomainParticipant find_participant_by_name(
    const std::string& participant_name);

/**
 * @relatesalso dds::domain::DomainParticipant
 * @headerfile rti/domain/find.hpp
 *
 * @brief @extension Retrieves all the participants created by the application
 * up to a maximum number
 *
 * @note \p \#include \p <rti/domain/find.hpp>
 * This function is in the `rti::domain` namespace
 *
 * If no such DomainParticipant exists, the operation will return
 * dds::core::null.
 *
 * @tparam ParticipantFwdIterator A forward iterator whose value type
 * is dds::domain::DomainParticipant
 *
 * @param begin The iterator where to begin adding DomainParticipants.
 * @param max_size The maximum number of elements to add
 * @return The number of elements added
 */
template <typename ParticipantFwdIterator>
uint32_t find_participants(ParticipantFwdIterator begin, uint32_t max_size)
{
    if (max_size == 0) {
        return 0;
    }

    DDS_DomainParticipantSeq native_participants = DDS_SEQUENCE_INITIALIZER;
    // Ensure sequence destruction
    rti::core::detail::NativeSequenceAdapter<DDS_DomainParticipant> participants_adapter(
        native_participants);

    DDS_ReturnCode_t retcode = DDS_DomainParticipantFactory_get_participants(
        DDS_DomainParticipantFactory_get_instance(),
        &native_participants);
    rti::core::check_return_code(retcode, "get native participants");

    rti::core::detail::create_from_native_entity<
        dds::domain::DomainParticipant, DDS_DomainParticipant, ParticipantFwdIterator>(
            begin, max_size, participants_adapter);

    return max_size < participants_adapter.size()
        ? max_size : participants_adapter.size();
}

/**
 * @relatesalso dds::domain::DomainParticipant
 * @headerfile rti/domain/find.hpp
 *
 * @brief @extension Retrieves all the participants created by the application
 *
 * @note \p \#include \p <rti/domain/find.hpp>
 * This function is in the `rti::domain` namespace
 *
 * (Note: this function is in the rti::domain namespace)
 *
 * @tparam ParticipantFwdIterator A forward iterator whose value type
 * is dds::domain::DomainParticipant
 *
 * @param begin The iterator where to begin adding DomainParticipants.
 * @return The number of elements added
 *
 */
template <typename ParticipantFwdIterator>
uint32_t find_participants(ParticipantFwdIterator begin)
{
    DDS_DomainParticipantSeq native_participants = DDS_SEQUENCE_INITIALIZER;
    // Ensure sequence destruction
    rti::core::detail::NativeSequenceAdapter<DDS_DomainParticipant> participants_adapter(
        native_participants);

    DDS_ReturnCode_t retcode = DDS_DomainParticipantFactory_get_participants(
        DDS_DomainParticipantFactory_get_instance(),
        &native_participants);
    rti::core::check_return_code(retcode, "get native participants");

    rti::core::detail::create_from_native_entity<
        dds::domain::DomainParticipant, DDS_DomainParticipant, ParticipantFwdIterator>(
            begin, participants_adapter);

    return participants_adapter.size();
}

/**
 * @relatesalso dds::domain::DomainParticipant
 * @headerfile rti/domain/find.hpp
 *
 * @brief @extension Retrieves a type registered with this participant
 *
 * \p \#include \p <rti/domain/find.hpp>
 *
 * Every data type used in a DomainParticipant has a registered type name, which
 * in most cases is the same as the type's name (the name used to define the
 * type), but it can be different.
 *
 * Types are registered by the creation of a dds::topic::Topic, whose
 * constructors optionally receive a registered type name different from the
 * type's name.
 *
 * Types can also be registered when parsing an XML configuration
 * and calling dds::core::QosProvider::create_participant_from_config().
 *
 * @param participant The DomainParticipant where the type is registered
 * @param type_name The name used to register the type in this participant
 * @return If `type_name` exists in this `participant`, this function returns the 
 * DynamicType describing the type. It can be cast down to dds::core::xtypes::StructType or
 * dds::core::xtypes::UnionType, depending on whether the type is a struct or a union.
 * @throw dds::core::Error If the type doesn't exist or the operation fails for
 * any other reason
 *
 * Example:
 * 
 * \code
 * dds::domain::DomainParticipant participant(0);
 * dds::topic::Topic<Foo> topic1(participant, "Foo Topic"); // registered as "Foo"
 * dds::topic::Topic<Foo> topic2(participant, "MyFoo Topic", "MyFoo"); // registered as "MyFoo"
 *
 * const auto& type1 = rti::domain::find_type(participant, "Foo");
 * const auto& type2 = rti::domain::find_type(participant, "MyFoo");
 * 
 * std::cout << type1 << std::endl;
 * std::cout << type2 << std::endl;
 * assert(type1 == type2); // Same type registered with different names
 * 
 * // Cast to StructType to access more information about the type
 * const auto& type1_struct = 
 *         static_cast<const dds::core::xtypes::StructType&>(type1);
 * std::cout << type1_struct.member(0).name() << std::endl;
 * 
 * \endcode
 *
 */
OMG_DDS_API
const dds::core::xtypes::DynamicType& find_type(
        const dds::domain::DomainParticipant& participant,
        const std::string& type_name);

} }

#endif // OMG_RTI_DDS_DOMAIN_FIND_HPP_
