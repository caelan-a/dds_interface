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

#ifndef RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_
#define RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <rti/core/detail/QosPolicyMacros.hpp>
#include <rti/core/QosPrintFormat.hpp>
#include <rti/core/types.hpp>

#include "ndds/ndds_c.h"

/** @RTI_namespace_start dds::domain::qos */
namespace rti { namespace domain { namespace qos {

class DomainParticipantQosImpl;

OMG_DDS_API
void swap(
    DomainParticipantQosImpl& left,
    DomainParticipantQosImpl& right) OMG_NOEXCEPT;

/** 
 * @ingroup DDSDomainParticipantModule
 * @headerfile dds/domain/qos/DomainParticipantQos.hpp
 * @RTI_class_definition class DomainParticipantQos
 *  
 * @brief @st_value_type Container of the QoS policies that a
 * dds::domain::DomainParticipant supports
 * @section DomainParticipantQos_policies DomainParticipantQos Policies
 *
 * A DomainParticipantQos contains the following policies:
 *  - dds::core::policy::UserData,
 *  - dds::core::policy::EntityFactory,
 *  - rti::core::policy::WireProtocol,
 *  - rti::core::policy::TransportBuiltin,
 *  - rti::core::policy::TransportUnicast,
 *  - rti::core::policy::Discovery,
 *  - rti::core::policy::DomainParticipantResourceLimits,
 *  - rti::core::policy::Event,
 *  - rti::core::policy::ReceiverPool,
 *  - rti::core::policy::Database,
 *  - rti::core::policy::DiscoveryConfig,
 *  - rti::core::policy::ExclusiveArea,
 *  - rti::core::policy::Property,
 *  - rti::core::policy::EntityName,
 *  - rti::core::policy::TransportMulticastMapping
 *  - rti::core::policy::Service
 * 
 * To get or set policies use the policy() getters and setters or operator <<
 * (see \ref DDSQosModule_set_qos "examples").
 *
 * @details \dref_details_DomainParticipantQos
 *
 * @see DDSQosExampleModule
 */
class OMG_DDS_API DomainParticipantQosImpl {
public:
    /**
     * @brief Creates a DomainParticipantQos with the default value for each
     * policy
     */
    DomainParticipantQosImpl();

  #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DomainParticipantQosImpl(
        DomainParticipantQosImpl&& other) OMG_NOEXCEPT
    {
        memset(this, 0, sizeof(*this));
        swap(*this, other);
    }

    DomainParticipantQosImpl& operator=(
        DomainParticipantQosImpl&& other) OMG_NOEXCEPT
    {
        DomainParticipantQosImpl tmp(std::move(other));
        swap(*this, tmp);
        return *this;
    }
  #endif

    bool operator==(const DomainParticipantQosImpl& other) const;

    DDS_DomainParticipantQos * native()
    {
        return reinterpret_cast<DDS_DomainParticipantQos *>(this);
    }

    const DDS_DomainParticipantQos * native() const
    {
        return reinterpret_cast<const DDS_DomainParticipantQos *>(this);
    }

public:

    /**
     * @brief Gets a QoS policy by const reference
     *
     * @tparam Policy One of the \ref DomainParticipantQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename POLICY>
    const POLICY& policy() const;

    /**
     * @brief Gets a QoS policy by reference
     *
     * @tparam Policy One of the \ref DomainParticipantQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename POLICY>
    POLICY& policy();

    /** @RTI_copydoc dds/core/TEntityQos.hpp EntityQosCopy TEntityQos::DomainParticipantQos */


public:
    dds::core::policy::UserData user_data;
    dds::core::policy::EntityFactory entity_factory;

    // Extensions:
    rti::core::policy::WireProtocol wire_protocol;
    rti::core::policy::TransportBuiltin transport_builtin;
    rti::core::policy::TransportUnicast default_unicast;
    rti::core::policy::Discovery discovery;
    rti::core::policy::DomainParticipantResourceLimits resource_limits;
    rti::core::policy::Event event;
    rti::core::policy::ReceiverPool receiver_pool;
    rti::core::policy::Database database;
    rti::core::policy::DiscoveryConfig discovery_config;
    rti::core::policy::ExclusiveArea exclusive_area;
    rti::core::policy::Property property;
    rti::core::policy::EntityName participant_name;
    rti::core::policy::TransportMulticastMapping multicast_mapping;

    // Not exposed:
    rti::core::policy::Service service;
    rti::core::policy::UserObject user_object;
    rti::core::policy::DomainParticipantProtocol protocol;
    rti::core::policy::TypeSupport type_support;
};

// --- Standalone functions: --------------------------------------------------

OMG_DDS_API
std::string to_string(
        const DomainParticipantQosImpl& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const DomainParticipantQosImpl& qos,
        const DomainParticipantQosImpl& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const DomainParticipantQosImpl& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

inline std::ostream& operator<<(
        std::ostream& out,
        const DomainParticipantQosImpl& qos)
{
    out << to_string(qos);
    return out;
}

#ifdef DOXYGEN_DOCUMENTATION_ONLY
/**
 * @relatesalso dds::domain::qos::DomainParticipantQos
 * @brief @extension Obtains a string representation of the
 * dds::domain::qos::DomainParticipantQos
 *
 * @param qos The qos object to convert to a string
 * @param format The optional print format used to format the output
 * string.
 * 
 * The several to_string overloads allow formatting the output and printing only
 * the differences with respect to another Qos object.
 *
 * \code
 * DomainParticipantQos qos;
 *
 * // When no QosPrintFormat is supplied, the default is used. Similarly, since
 * // no base profile has been specified we will only print the differences
 * // with respect to the documented default for DomainParticipantQos
 * std::string str = to_string(qos);
 *
 * // In this overload we are specifying the print format used to format the output
 * // string.
 * QosPrintFormat format; // ...;
 * str = to_string(qos, format);
 *
 * // Here, the differences between qos and base will be included in the output
 * // string. If the two qos objects are the same, the resulting string will
 * // be empty.
 * DomainParticipantQos base; // ...;
 * str = to_string(qos, base);
 * // We could also specify the format at this point
 * str = to_string(qos, base, format);
 *
 * // Instead of supplying a base profile, the sentinel value qos_print_all can
 * // be supplied. This will result in the entire Qos object being printed (as
 * // opposed to only the differences with respect to a base qos).
 * str = to_string(qos, qos_print_all);
 * \endcode
 *
 * This overload uses the default print format and only prints the differences
 * between qos and the documented default.
 *
 * @returns The string representation of the qos
 */
std::string to_string(
        const DomainParticipantQos& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::domain::qos::DomainParticipantQos
 * @brief @extension Obtains a string representation of the 
 * dds::domain::qos::DomainParticipantQos
 *
 * @param qos The qos object to convert to a string
 * @param base The base qos. Only the differences between base and qos are included
 * in the output string. If you want to print everything within the QoS, use the
 * overload that accepts a rti::core::qos_print_all_t.
 * @param format The optional print format used to format the output
 * string.
 *
 * This overload prints the differences between qos and base. If no print format
 * is specified, the default will be used.
 * 
 * @returns The string representation of the qos
 */
std::string to_string(
        const DomainParticipantQos& qos,
        const DomainParticipantQos& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::domain::qos::DomainParticipantQos
 * @brief @extension Obtains a string representation of the
 * dds::domain::qos::DomainParticipantQos
 *
 * @param qos The qos object to convert to a string
 * @param qos_print_all The sentinel value indicating that the entire QoS should be converted
 * to a string. The other overloads of this API only print the differences with respect
 * to a base profile, or to the documented default.
 * @param format The optional print format used to format the output
 * string.
 *
 * This overload prints all of the policies within qos. If no print format is
 * specified, the default will be used.
 *
 * The only valid value for the qos_print_all argument is rti::core::qos_print_all
 * 
 * For example:
 * \code
 * to_string(qos, rti::core::qos_print_all);
 * \endcode
 * 
 * @returns The string representation of the qos
 */
std::string to_string(
        const DomainParticipantQos& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::domain::qos::DomainParticipantQos
 * @brief @extension Prints a dds::sub::qos::DomainParticipantQos to an output stream.
 */
inline std::ostream& operator<<(
        std::ostream& out,
        const rti::domain::qos::DomainParticipantQos& qos);
#endif

// Doxygen gets confused by these macros
#ifndef DOXYGEN_DOCUMENTATION_ONLY

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, dds::core::policy::UserData, user_data)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, dds::core::policy::EntityFactory, entity_factory)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::Database, database)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::EntityName, participant_name)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::Discovery, discovery)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::WireProtocol, wire_protocol)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::TransportBuiltin, transport_builtin)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::TransportUnicast, default_unicast)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::DomainParticipantResourceLimits, resource_limits)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::Event, event)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::ReceiverPool, receiver_pool)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::DiscoveryConfig, discovery_config)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::Property, property)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::TransportMulticastMapping, multicast_mapping)

RTI_DECL_POLICY_GETTER(
        DomainParticipantQosImpl,
        rti::core::policy::Service,
        service)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::DomainParticipantProtocol, protocol)

RTI_DECL_POLICY_GETTER(
    DomainParticipantQosImpl, rti::core::policy::TypeSupport, type_support)

#endif // !DOXYGEN_DOCUMENTATION_ONLY

/** @RTI_namespace_end dds::domain::qos */
} } } // namespace rti::domain::qos

#endif // RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_QOS_IMPL_HPP_
