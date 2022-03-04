/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
-------------------- 
1.7a,27feb14,eam Added ResourceLimits 
1.0a,22feb13,acr Created
============================================================================= */

#ifndef RTI_DDS_PUB_DATAWRITER_QOS_IMPL_HPP_
#define RTI_DDS_PUB_DATAWRITER_QOS_IMPL_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <dds/topic/qos/TopicQos.hpp>
#include <rti/core/detail/QosPolicyMacros.hpp>
#include <rti/core/QosPrintFormat.hpp>
#include <rti/core/types.hpp>

#include "ndds/ndds_c.h"

/** @RTI_namespace_start dds::pub::qos */
namespace rti { namespace pub { namespace qos {

class DataWriterQosImpl;

OMG_DDS_API
void swap(DataWriterQosImpl& left, DataWriterQosImpl& right) OMG_NOEXCEPT;

/** 
 * @RTI_class_definition class DataWriterQos
 * @headerfile dds/pub/qos/DataWriterQos.hpp
 * @ingroup DDSWriterModule
 *
 * @brief @st_value_type Container of the QoS policies that a
 * dds::pub::DataWriter supports
 *
 * @section DataWriterQos_policies DataWriterQos policies
 *
 * A DataWriterQos contains the following policies:
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
 *  - dds::core::policy::UserData,
 *  - dds::core::policy::Ownership,
 *  - dds::core::policy::OwnershipStrength,
 *  - dds::core::policy::WriterDataLifecycle,
 *  - dds::core::policy::DataRepresentation,
 *  - dds::core::policy::DataTag,
 *  - rti::core::policy::DataWriterResourceLimits,
 *  - rti::core::policy::DataWriterProtocol,
 *  - rti::core::policy::TransportSelection,
 *  - rti::core::policy::TransportUnicast,
 *  - rti::core::policy::TransportEncapsulation,
 *  - rti::core::policy::PublishMode,
 *  - rti::core::policy::Property,
 *  - rti::core::policy::Service,
 *  - rti::core::policy::Batch,
 *  - rti::core::policy::MultiChannel,
 *  - rti::core::policy::Availability,
 *  - rti::core::policy::EntityName,
 *  - rti::core::policy::TopicQueryDispatch,
 *  - rti::core::policy::DataWriterTransferMode,
 *  - rti::core::policy::TypeSupport
 *
 * To get or set policies use the policy() getters and setters or operator <<
 * (see \ref DDSQosModule_set_qos "examples").
 *
 * @details \dref_details_DataWriterQos
 *
 * @see DDSQosExampleModule
 */
class OMG_DDS_API DataWriterQosImpl {
public:

    /**
     * @brief Creates a DataWriterQos with the default value for each policy
     * 
     * @note If you configure Qos in XML, obtain the default value from the
     * default QosProvider, since it can be overriden by configuration:
     * \code
     * DataWriterQos writer_qos = dds::core::QosProvider::Default().datawriter_qos();
     * \endcode
     * 
     */
    DataWriterQosImpl();

  #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DataWriterQosImpl(DataWriterQosImpl&& other) OMG_NOEXCEPT
    {
        memset(this, 0, sizeof(*this));
        swap(*this, other);
    }

    DataWriterQosImpl& operator=(DataWriterQosImpl&& other) OMG_NOEXCEPT
    {
        DataWriterQosImpl tmp(std::move(other));
        swap(*this, tmp);
        return *this;
    }
  #endif

    void copy_topic_qos(const dds::topic::qos::TopicQos& topic_qos);

    /**
     * @brief Copies into this DataWriterQos those policies that are also in TopicQos
     *
     * A dds::topic::qos::TopicQos contains a subset of the policies of a DataWriterQos.
     * This assignment operator copies those common policies into this instance
     * while leaving the policies that are only defined in DataWriterQos unaltered.
     * 
     * @param topic_qos The TopicQos to copy the common policies from.
     * 
     * For example:
     * \code
     * // Load a TopicQos from a Qos profile
     * TopicQos topic_qos = dds::core::QosProvider::Default().topic_qos("MyLibrary::MyProfile");
     * // Create a DataWriterQos with the default policies
     * DataWriterQos writer_qos = dds::core::QosProvider::Default().datawriter_qos();
     * // Overwrite the policies that are also defined in topic_qos
     * writer_qos = topic_qos;
     * \endcode
     */
    DataWriterQosImpl& operator=(const dds::topic::qos::TopicQos& topic_qos)
    {
        copy_topic_qos(topic_qos);
        return *this;
    }

    bool operator==(const DataWriterQosImpl& other) const;

    DDS_DataWriterQos * native()
    {
        return reinterpret_cast<DDS_DataWriterQos *>(this);
    }

    const DDS_DataWriterQos * native() const
    {
        return reinterpret_cast<const DDS_DataWriterQos *>(this);
    }

    /**
     * @brief Gets a QoS policy by const reference
     *
     * @tparam Policy One of the \ref DataWriterQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename Policy>
    const Policy& policy() const;

    /**
     * @brief Gets a QoS policy by reference
     *
     * @tparam Policy One of the \ref DataWriterQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename Policy>
    Policy& policy();

    /** @RTI_copydoc dds/core/TEntityQos.hpp EntityQosCopy TEntityQos::DataWriterQos */

public:
    // Important: the order of these members needs to match that of dds_c.
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
    dds::core::policy::UserData user_data;
    dds::core::policy::Ownership ownership;
    dds::core::policy::OwnershipStrength ownership_strength;
    dds::core::policy::WriterDataLifecycle writer_data_lifecycle;
    dds::core::policy::DataRepresentation representation;
    dds::core::policy::DataTag data_tag;

    rti::core::policy::DataWriterResourceLimits writer_resource_limits;
    rti::core::policy::DataWriterProtocol protocol;
    rti::core::policy::TransportSelection transport_selection;
    rti::core::policy::TransportUnicast unicast;
    rti::core::policy::TransportEncapsulation encapsulation;
    rti::core::policy::PublishMode publish_mode;
    rti::core::policy::Property property;
    rti::core::policy::Service service;
    rti::core::policy::Batch batch;
    rti::core::policy::MultiChannel multi_channel;
    rti::core::policy::Availability availability;
    rti::core::policy::EntityName publication_name;
    rti::core::policy::TopicQueryDispatch topic_query_dispatch;
    rti::core::policy::DataWriterTransferMode transfer_mode;
    rti::core::policy::TypeSupport type_support;
};

// --- Standalone functions: --------------------------------------------------

OMG_DDS_API
std::string to_string(
        const DataWriterQosImpl& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const DataWriterQosImpl& qos,
        const DataWriterQosImpl& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const DataWriterQosImpl& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

inline std::ostream& operator<<(
        std::ostream& out,
        const rti::pub::qos::DataWriterQosImpl& qos)
{
    out << to_string(qos);
    return out;
}

#ifdef DOXYGEN_DOCUMENTATION_ONLY
/**
 * @relatesalso dds::pub::qos::DataWriterQos
 * @brief @extension Obtains a string representation of the dds::pub::qos::DataWriterQos
 *
 * @param qos The qos object to convert to a string
 * @param format The optional print format used to format the output
 * string.
 * 
 * The several to_string overloads allow formatting the output and printing only
 * the differences with respect to another Qos object.
 *
 * \code
 * DataWriterQos qos;
 *
 * // When no QosPrintFormat is supplied, the default is used. Similarly, since
 * // no base profile has been specified we will only print the differences
 * // with respect to the documented default for DataWriterQos
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
 * DataWriterQos base; // ...;
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
        const DataWriterQos& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::pub::qos::DataWriterQos
 * @brief @extension Obtains a string representation of the dds::pub::qos::DataWriterQos
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
        const DataWriterQos& qos,
        const DataWriterQos& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::pub::qos::DataWriterQos
 * @brief @extension Obtains a string representation of the dds::sub::qos::DataWriterQos
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
        const DataWriterQos& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::pub::qos::DataWriterQos
 * @brief @extension Prints a dds::pub::qos::DataWriterQos to an output stream.
 */
inline std::ostream& operator<<(
        std::ostream& out,
        const rti::pub::qos::DataWriterQos& qos);
#endif

// Doxygen gets confused by these macros
#ifndef DOXYGEN_DOCUMENTATION_ONLY

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::Durability, durability)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::Deadline, deadline)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::LatencyBudget, latency_budget)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::UserData, user_data)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::Ownership, ownership)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::OwnershipStrength, ownership_strength)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::Liveliness, liveliness)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::Reliability, reliability)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::History, history)

RTI_DECL_POLICY_GETTER(
   DataWriterQosImpl, dds::core::policy::ResourceLimits, resource_limits)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::WriterDataLifecycle, writer_data_lifecycle)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::DataRepresentation, representation)

RTI_DECL_POLICY_GETTER(
        DataWriterQosImpl,
        dds::core::policy::DataTag,
        data_tag)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::EntityName, publication_name)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::TransportPriority, transport_priority)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::Lifespan, lifespan)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::DestinationOrder, destination_order)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, dds::core::policy::DurabilityService, durability_service)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::Property, property)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::TransportUnicast, unicast)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::Service, service)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::MultiChannel, multi_channel)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::PublishMode, publish_mode)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::Batch, batch)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::DataWriterResourceLimits, writer_resource_limits)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::TransportSelection, transport_selection)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::Availability, availability)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::DataWriterProtocol, protocol)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::TopicQueryDispatch, topic_query_dispatch)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::DataWriterTransferMode, transfer_mode)

RTI_DECL_POLICY_GETTER(
    DataWriterQosImpl, rti::core::policy::TypeSupport, type_support)

#endif // !DOXYGEN_DOCUMENTATION_ONLY

/** @RTI_namespace_end dds::pub::qos */
} } } // namespace rti::pub::qos

#endif // RTI_DDS_PUB_DATAWRITER_QOS_IMPL_HPP_
