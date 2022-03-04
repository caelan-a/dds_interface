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

#ifndef RTI_DDS_SUB_SUBSCRIBER_QOS_IMPL_HPP_
#define RTI_DDS_SUB_SUBSCRIBER_QOS_IMPL_HPP_

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

/** @RTI_namespace_start dds::sub::qos */
namespace rti { namespace sub { namespace qos {

class SubscriberQosImpl;

OMG_DDS_API
void swap(SubscriberQosImpl& left, SubscriberQosImpl& right) OMG_NOEXCEPT;

/** 
 * @RTI_class_definition class SubscriberQos 
 * @headerfile SubscriberQos.hpp "dds/sub/qos/SubscriberQos.hpp"
 * @ingroup DDSSubscriberModule 
 *  
 * @brief @st_value_type Container of the QoS policies that a
 * dds::sub::Subscriber supports
 *  
 * @details \dref_details_SubscriberQos
 *
 * @see DDSQosExampleModule
 */
class OMG_DDS_API SubscriberQosImpl {
public:

    SubscriberQosImpl() {}

  #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    SubscriberQosImpl(SubscriberQosImpl&& other) OMG_NOEXCEPT
    {
        memset(this, 0, sizeof(*this));
        swap(*this, other);
    }

    SubscriberQosImpl& operator=(SubscriberQosImpl&& other) OMG_NOEXCEPT
    {
        SubscriberQosImpl tmp(std::move(other));
        swap(*this, tmp);
        return *this;
    }
  #endif

    bool operator==(const SubscriberQosImpl& other) const;

public:
    DDS_SubscriberQos * native()
    {
        return reinterpret_cast<DDS_SubscriberQos *>(this);
    }

    const DDS_SubscriberQos * native() const
    {
        return reinterpret_cast<const DDS_SubscriberQos *>(this);
    }

public:

    /**
     * @brief Gets a QoS policy by const reference
     *
     * @see policy()
     */
    template<typename POLICY>
    const POLICY& policy() const;

    /**
     * @brief Gets a QoS policy by reference
     *
     * @tparam Policy One of the Subscriber QoS policies:
     *  - dds::core::policy::Presentation, 
     *  - dds::core::policy::Partition,
     *  - dds::core::policy::GroupData,
     *  - dds::core::policy::EntityFactory,
     *  - rti::core::policy::ExclusiveArea,
     *  - rti::core::policy::EntityName
     *
     * @see DDSQosModule_set_qos
     */
    template<typename POLICY>
    POLICY& policy();


public:
    dds::core::policy::Presentation presentation;
    dds::core::policy::Partition partition;
    dds::core::policy::GroupData group_data;
    dds::core::policy::EntityFactory entity_factory;

    /* --- Extensions: ---------------------------------------------------- */
    rti::core::policy::ExclusiveArea exclusive_area;
    rti::core::policy::SubscriberProtocol protocol;
    rti::core::policy::EntityName subscriber_name;

};

// --- Standalone functions: --------------------------------------------------

OMG_DDS_API
std::string to_string(
        const SubscriberQosImpl& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const SubscriberQosImpl& qos,
        const SubscriberQosImpl& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const SubscriberQosImpl& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

inline std::ostream& operator<<(
        std::ostream& out,
        const rti::sub::qos::SubscriberQosImpl& qos)
{
    out << to_string(qos);
    return out;
}

#ifdef DOXYGEN_DOCUMENTATION_ONLY
/**
 * @relatesalso dds::sub::qos::SubscriberQos
 * @brief @extension Obtains a string representation of the dds::sub::qos::SubscriberQos
 *
 * @param qos The qos object to convert to a string
 * @param format The optional print format used to format the output
 * string.
 * 
 * The several to_string overloads allow formatting the output and printing only
 * the differences with respect to another Qos object.
 *
 * \code
 * SubscriberQos qos;
 *
 * // When no QosPrintFormat is supplied, the default is used. Similarly, since
 * // no base profile has been specified we will only print the differences
 * // with respect to the documented default for SubscriberQos
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
 * SubscriberQos base; // ...;
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
        const SubscriberQos& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::sub::qos::SubscriberQos
 * @brief @extension Obtains a string representation of the dds::sub::qos::SubscriberQos
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
        const SubscriberQos& qos,
        const SubscriberQos& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::sub::qos::SubscriberQos
 * @brief @extension Obtains a string representation of the dds::sub::qos::SubscriberQos
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
        const SubscriberQos& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::sub::qos::SubscriberQos
 * @brief @extension Prints a dds::sub::qos::SubscriberQos to an output stream.
 */
inline std::ostream& operator<<(
        std::ostream& out,
        const rti::sub::qos::SubscriberQos& qos);
#endif

// Doxygen gets confused by these macros
#ifndef DOXYGEN_DOCUMENTATION_ONLY

RTI_DECL_POLICY_GETTER(
    SubscriberQosImpl, dds::core::policy::Presentation, presentation)

RTI_DECL_POLICY_GETTER(
    SubscriberQosImpl, dds::core::policy::Partition, partition)

RTI_DECL_POLICY_GETTER(
    SubscriberQosImpl, dds::core::policy::EntityFactory, entity_factory)

RTI_DECL_POLICY_GETTER(
    SubscriberQosImpl, rti::core::policy::EntityName, subscriber_name)

RTI_DECL_POLICY_GETTER(
    SubscriberQosImpl, dds::core::policy::GroupData, group_data)

RTI_DECL_POLICY_GETTER(
    SubscriberQosImpl, rti::core::policy::ExclusiveArea, exclusive_area)

RTI_DECL_POLICY_GETTER(
    SubscriberQosImpl, rti::core::policy::SubscriberProtocol, protocol)

#endif // !DOXYGEN_DOCUMENTATION_ONLY

/** @RTI_namespace_end dds::sub::qos */
} } } // namespace rti::sub::qos

#endif // RTI_DDS_SUB_SUBSCRIBER_QOS_IMPL_HPP_
