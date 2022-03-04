/* $Id$

(c) Copyright, Real-Time Innovations, 2013-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.0a,12feb13,acr Created
============================================================================= */

#ifndef RTI_DDS_DOMAIN_DOMAIN_PUBLISHER_QOS_HPP_
#define RTI_DDS_DOMAIN_DOMAIN_PUBLISHER_QOS_HPP_

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

/** @RTI_namespace_start dds::topic::qos */
namespace rti { namespace topic { namespace qos {

class TopicQosImpl;

OMG_DDS_API
void swap(TopicQosImpl& left, TopicQosImpl& right) OMG_NOEXCEPT;

/** 
 * @RTI_class_definition class TopicQos 
 * @headerfile dds/topic/qos/TopicQos.hpp
 * @ingroup DDSTopicEntityModule 
 *  
 * @brief @st_value_type Container of the QoS policies that a
 * dds::topic::Topic supports
 *
 * @section TopicQos_policies TopicQos Policies
 *
 * A TopicQos contains the following policies:
 *  - dds::core::policy::TopicData,
 *  - dds::core::policy::Durability,
 *  - dds::core::policy::DurabilityService,
 *  - dds::core::policy::Deadline,
 *  - dds::core::policy::LatencyBudget,
 *  - dds::core::policy::Liveliness,
 *  - dds::core::policy::Reliability,
 *  - dds::core::policy::DestinationOrder,
 *  - dds::core::policy::History,
 *  - dds::core::policy::ResourceLimits,
 *  - dds::core::policy::TransportPriority,
 *  - dds::core::policy::Lifespan,
 *  - dds::core::policy::Ownership,
 *  - dds::core::policy::DataRepresentation
 *  
 * To get or set policies use the policy() getters and setters or operator <<
 * (see \ref DDSQosModule_set_qos "examples").
 *
 * @details \dref_details_TopicQos
 *
 * @see DDSQosExampleModule
 */
class OMG_DDS_API TopicQosImpl {
public:

    /**
     * @brief Creates a TopicQos with the default value for each policy
     */
    TopicQosImpl() {}

  #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    TopicQosImpl(TopicQosImpl&& other) OMG_NOEXCEPT
    {
        memset(this, 0, sizeof(*this));
        swap(*this, other);
    }

    TopicQosImpl& operator=(TopicQosImpl&& other) OMG_NOEXCEPT
    {
        TopicQosImpl tmp(std::move(other));
        swap(*this, tmp);
        return *this;
    }
  #endif

    bool operator==(const TopicQosImpl& other) const;

    DDS_TopicQos * native()
    {
        return reinterpret_cast<DDS_TopicQos *>(this);
    }

    const DDS_TopicQos * native() const
    {
        return reinterpret_cast<const DDS_TopicQos *>(this);
    }

    /**
     * @brief Gets a QoS policy by const reference
     *
     * @tparam Policy One of the \ref TopicQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename POLICY>
    const POLICY& policy() const;

    /**
     * @brief Gets a QoS policy by reference
     *
     * @tparam Policy One of the \ref TopicQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename POLICY>
    POLICY& policy();

    /** @RTI_copydoc dds/core/TEntityQos.hpp EntityQosCopy TEntityQos::TopicQos */

    // Important: the order of these members needs to match that of dds_c.
    dds::core::policy::TopicData topic_data;
    dds::core::policy::Durability durability;
    dds::core::policy::DurabilityService durability_service;
    dds::core::policy::Deadline deadline;
    dds::core::policy::LatencyBudget latency_budget;
    dds::core::policy::Liveliness liveliness;
    dds::core::policy::Reliability reliability;
    dds::core::policy::DestinationOrder destination_order;
    dds::core::policy::History history;
    dds::core::policy::ResourceLimits resource_limits;
    dds::core::policy::TransportPriority transport_priority;
    dds::core::policy::Lifespan lifespan;
    dds::core::policy::Ownership ownership;
    dds::core::policy::DataRepresentation representation;

    // Extensions:
    rti::core::policy::TopicProtocol protocol;

};

// --- Standalone functions: --------------------------------------------------

OMG_DDS_API
std::string to_string(
        const TopicQosImpl& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const TopicQosImpl& qos,
        const TopicQosImpl& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const TopicQosImpl& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

inline std::ostream& operator<<(
        std::ostream& out,
        const rti::topic::qos::TopicQosImpl& qos)
{
    out << to_string(qos);
    return out;
}

#ifdef DOXYGEN_DOCUMENTATION_ONLY
/**
 * @relatesalso dds::topic::qos::TopicQos
 * @brief @extension Obtains a string representation of the dds::topic::qos::TopicQos
 *
 * @param qos The qos object to convert to a string
 * @param format The optional print format used to format the output
 * string.
 * 
 * The several to_string overloads allow formatting the output and printing only
 * the differences with respect to another Qos object.
 *
 * \code
 * TopicQos qos;
 *
 * // When no QosPrintFormat is supplied, the default is used. Similarly, since
 * // no base profile has been specified we will only print the differences
 * // with respect to the documented default for TopicQos
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
 * TopicQos base; // ...;
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
        const TopicQos& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::topic::qos::TopicQos
 * @brief @extension Obtains a string representation of the dds::topic::qos::TopicQos
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
        const TopicQos& qos,
        const TopicQos& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::topic::qos::TopicQos
 * @brief @extension Obtains a string representation of the dds::topic::qos::TopicQos
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
        const TopicQos& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::topic::qos::TopicQos
 * @brief @extension Prints a dds::topic::qos::TopicQos to an output stream.
 */
inline std::ostream& operator<<(
        std::ostream& out,
        const rti::topic::qos::TopicQos& qos);
#endif


// Doxygen gets confused by these macros
#ifndef DOXYGEN_DOCUMENTATION_ONLY

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::Durability, durability)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::Deadline, deadline)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::LatencyBudget, latency_budget)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::Ownership, ownership)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::ResourceLimits, resource_limits)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::TransportPriority, transport_priority)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::Lifespan, lifespan)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::TopicData, topic_data)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::DurabilityService, durability_service)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::Liveliness, liveliness)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::Reliability, reliability)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::DestinationOrder, destination_order)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::History, history)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, dds::core::policy::DataRepresentation, representation)

RTI_DECL_POLICY_GETTER(
    TopicQosImpl, rti::core::policy::TopicProtocol, protocol)

#endif // !DOXYGEN_DOCUMENTATION_ONLY

/** @RTI_namespace_end dds::topic::qos */
} } } // namespace rti::topic::qos

#endif // RTI_DDS_DOMAIN_DOMAIN_PUBLISHER_QOS_HPP_
