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

#ifndef RTI_DDS_PUB_PUBLISHER_QOS_IMPL_HPP_
#define RTI_DDS_PUB_PUBLISHER_QOS_IMPL_HPP_

#include <new> // for bad_alloc

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

/** @RTI_namespace_start dds::pub::qos */
namespace rti { namespace pub { namespace qos {

class PublisherQosImpl;

/**
 * @brief Swap the contents of two PublisherQos objects
 * @relatesalso dds::pub::qos::PublisherQos
 *
 * @param left A PublisherQos
 * @param right The other PublisherQos
 *
 */
OMG_DDS_API
void swap(PublisherQosImpl& left, PublisherQosImpl& right) OMG_NOEXCEPT;

/** 
 * @RTI_class_definition class PublisherQos 
 * @headerfile dds/pub/qos/PublisherQos.hpp
 * @ingroup DDSPublisherModule
 *  
 * @brief @st_value_type Container of the QoS policies that a
 * dds::pub::Publisher supports
 *  
 * @section PublisherQos_policies PublisherQos Policies
 *
 * A PublisherQos contains the following policies:
 *  - dds::core::policy::Presentation,
 *  - dds::core::policy::Partition,
 *  - dds::core::policy::GroupData,
 *  - dds::core::policy::EntityFactory,
 *  - rti::core::policy::AsynchronousPublisher,
 *  - rti::core::policy::ExclusiveArea,
 *  - rti::core::policy::EntityName
 *
 * To get or set policies use the policy() getters and setters or operator <<
 * (see \ref DDSQosModule_set_qos "examples").
 *
 * @details \dref_details_PublisherQos
 *
 * @see DDSQosExampleModule
 */
class OMG_DDS_API PublisherQosImpl {
public:

    PublisherQosImpl() {}

  #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    PublisherQosImpl(PublisherQosImpl&& other) OMG_NOEXCEPT
    {
        memset(this, 0, sizeof(*this));
        swap(*this, other);
    }

    PublisherQosImpl& operator=(PublisherQosImpl&& other) OMG_NOEXCEPT
    {
        PublisherQosImpl tmp(std::move(other));
        swap(*this, tmp);
        return *this;
    }
  #endif

    bool operator==(const PublisherQosImpl& other) const;

    DDS_PublisherQos * native()
    {
        return reinterpret_cast<DDS_PublisherQos *>(this);
    }

    const DDS_PublisherQos * native() const
    {
        return reinterpret_cast<const DDS_PublisherQos *>(this);
    }

    /**
     * @brief Gets a QoS policy by const reference
     *
     * @tparam Policy One of the \ref PublisherQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename POLICY>
    const POLICY& policy() const;

    /**
     * @brief Gets a QoS policy by reference
     *
     * @tparam Policy One of the \ref PublisherQos_policies
     *
     * @see \ref DDSQosModule_set_qos
     */
    template<typename POLICY>
    POLICY& policy();

    /** @RTI_copydoc dds/core/TEntityQos.hpp EntityQosCopy TEntityQos::PublisherQos */

    // Important: the order of these members needs to match that of dds_c.
    dds::core::policy::Presentation presentation;
    dds::core::policy::Partition partition;
    dds::core::policy::GroupData group_data;
    dds::core::policy::EntityFactory entity_factory;

    // --- Extensions: --------------------------------------------------------
    rti::core::policy::AsynchronousPublisher asynchronous_publisher;
    rti::core::policy::ExclusiveArea  exclusive_area;
    rti::core::policy::PublisherProtocol protocol;
    rti::core::policy::EntityName publisher_name;
};

// --- Standalone functions: --------------------------------------------------

OMG_DDS_API
std::string to_string(
        const PublisherQosImpl& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const PublisherQosImpl& qos,
        const PublisherQosImpl& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const PublisherQosImpl& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

inline std::ostream& operator<<(
        std::ostream& out,
        const rti::pub::qos::PublisherQosImpl& qos)
{
    out << to_string(qos);
    return out;
}

#ifdef DOXYGEN_DOCUMENTATION_ONLY
/**
 * @relatesalso dds::pub::qos::PublisherQos
 * @brief @extension Obtains a string representation of the dds::pub::qos::PublisherQos
 *
 * @param qos The qos object to convert to a string
 * @param format The optional print format used to format the output
 * string.
 * 
 * The several to_string overloads allow formatting the output and printing only
 * the differences with respect to another Qos object.
 *
 * \code
 * PublisherQos qos;
 *
 * // When no QosPrintFormat is supplied, the default is used. Similarly, since
 * // no base profile has been specified we will only print the differences
 * // with respect to the documented default for PublisherQos
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
 * PublisherQos base; // ...;
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
        const PublisherQos& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::pub::qos::PublisherQos
 * @brief @extension Obtains a string representation of the dds::pub::qos::PublisherQos
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
        const PublisherQos& qos,
        const PublisherQos& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::pub::qos::PublisherQos
 * @brief @extension Obtains a string representation of the dds::pub::qos::PublisherQos
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
        const PublisherQos& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::pub::qos::PublisherQos
 * @brief @extension Prints a dds::pub::qos::PublisherQos to an output stream.
 */
inline std::ostream& operator<<(
        std::ostream& out,
        const rti::pub::qos::PublisherQos& qos);
#endif

// Doxygen gets confused by these macros
#ifndef DOXYGEN_DOCUMENTATION_ONLY

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, dds::core::policy::Presentation, presentation)

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, dds::core::policy::Partition, partition)

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, dds::core::policy::EntityFactory, entity_factory)

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, rti::core::policy::EntityName, publisher_name)

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, dds::core::policy::GroupData, group_data)

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, rti::core::policy::AsynchronousPublisher, asynchronous_publisher)

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, rti::core::policy::ExclusiveArea, exclusive_area)

RTI_DECL_POLICY_GETTER(
    PublisherQosImpl, rti::core::policy::PublisherProtocol, protocol)

#endif // !DOXYGEN_DOCUMENTATION_ONLY

/** @RTI_namespace_end dds::pub::qos */
} } } // namespace rti::pub::qos

#endif // RTI_DDS_PUB_PUBLISHER_QOS_IMPL_HPP_
