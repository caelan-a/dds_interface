/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


modification history
--------------------
1.7a,07may14,eam Created
============================================================================= */

#ifndef RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_FACTORY_QOS_IMPL_HPP_
#define RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_FACTORY_QOS_IMPL_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/policy/CorePolicy.hpp>
#include <rti/core/Exception.hpp>
#include <rti/core/detail/QosPolicyMacros.hpp>
#include <rti/core/QosPrintFormat.hpp>
#include <rti/core/types.hpp>

#include "ndds/ndds_c.h"

/** @RTI_namespace_start dds::domain::qos */
namespace rti { namespace domain { namespace qos {

class DomainParticipantFactoryQosImpl;

OMG_DDS_API
void swap(
    DomainParticipantFactoryQosImpl& left,
    DomainParticipantFactoryQosImpl& right) OMG_NOEXCEPT;

/** 
 * @RTI_class_definition class DomainParticipantFactoryQos 
 * @headerfile DomainParticipantFactoryQos.hpp "dds/domain/qos/DomainParticipantFactoryQos.hpp"
 * @ingroup DDSDomainParticipantModule 
 *  
 * @brief @st_value_type Container of the QoS policies that do not apply to a 
 * specific entity  
 *
 * To set or get this policies, use DomainParticipant::participant_factory_qos().
 *
 * @see DDSQosExampleModule
 *  
 */
class OMG_DDS_API DomainParticipantFactoryQosImpl {
public:
    DomainParticipantFactoryQosImpl();

  #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    DomainParticipantFactoryQosImpl(
        DomainParticipantFactoryQosImpl&& other) OMG_NOEXCEPT
    {
        memset(this, 0, sizeof(*this));
        swap(*this, other);
    }

    DomainParticipantFactoryQosImpl& operator=(
        DomainParticipantFactoryQosImpl&& other) OMG_NOEXCEPT
    {
        DomainParticipantFactoryQosImpl tmp(std::move(other));
        swap(*this, tmp);
        return *this;
    }
  #endif

    bool operator==(const DomainParticipantFactoryQosImpl& other) const;

    DDS_DomainParticipantFactoryQos * native()
    {
        return reinterpret_cast<DDS_DomainParticipantFactoryQos *>(this);
    }

    const DDS_DomainParticipantFactoryQos * native() const
    {
        return reinterpret_cast<const DDS_DomainParticipantFactoryQos *>(this);
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
     * @tparam Policy One of the DomainParticipantFactory QoS policies:
     *  - dds::core::policy::EntityFactory,
     *  - rti::core::policy::SystemResourceLimits
     * 
     * @note In other language APIs the DomainParticipantFactoryQos also contains
     * the policies to configure the loading of Qos profiles in XML (ProfileQosPolicy)
     * and the logging configuration. These are configured through dds::core::QosProvider and
     * rti::config::Logger respectively.
     *
     * @see DDSQosModule_set_qos
     */
    template<typename POLICY>
    POLICY& policy();


public:

    dds::core::policy::EntityFactory  entity_factory;

    // ---- Extensions --------------------------------------------------------
    rti::core::policy::SystemResourceLimits  resource_limits;    

    // This policy is not exposed. To configure how to load qos profiles we have
    // the QosProviderParams. This member is here only to ensure that the
    //  memory layout of this class is the same as the C struct.
    rti::core::policy::Profile profile;

    // This policy is not exposed. To configure logging we have the
    // the rti::config::Logger. This member is here only to ensure that the
    //  memory layout of this class is the same as the C struct.
    rti::core::policy::Logging logging;
};

// --- Standalone functions: --------------------------------------------------

OMG_DDS_API
std::string to_string(
        const DomainParticipantFactoryQosImpl& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const DomainParticipantFactoryQosImpl& qos,
        const DomainParticipantFactoryQosImpl& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

OMG_DDS_API
std::string to_string(
        const DomainParticipantFactoryQosImpl& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

inline std::ostream& operator<<(
        std::ostream& out,
        const DomainParticipantFactoryQosImpl& qos)
{
    out << to_string(qos);
    return out;
}

#ifdef DOXYGEN_DOCUMENTATION_ONLY
/**
 * @relatesalso dds::domain::qos::DomainParticipantFactoryQos
 * @brief @extension Obtains a string representation of the
 * dds::domain::qos::DomainParticipantFactoryQos
 *
 * @param qos The qos object to convert to a string
 * @param format The optional print format used to format the output
 * string.
 * 
 * The several to_string overloads allow formatting the output and printing only
 * the differences with respect to another Qos object.
 *
 * \code
 * DomainParticipantFactoryQos qos;
 *
 * // When no QosPrintFormat is supplied, the default is used. Similarly, since
 * // no base profile has been specified we will only print the differences
 * // with respect to the documented default for DomainParticipantFactoryQos
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
 * DomainParticipantFactoryQos base; // ...;
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
        const DomainParticipantFactoryQos& qos,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::domain::qos::DomainParticipantFactoryQos
 * @brief @extension Obtains a string representation of the 
 * dds::domain::qos::DomainParticipantFactoryQos
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
        const DomainParticipantFactoryQos& qos,
        const DomainParticipantFactoryQos& base,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::domain::qos::DomainParticipantFactoryQos
 * @brief @extension Obtains a string representation of the
 * dds::domain::qos::DomainParticipantFactoryQos
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
        const DomainParticipantFactoryQos& qos,
        const rti::core::qos_print_all_t& qos_print_all,
        const rti::core::QosPrintFormat& format = rti::core::QosPrintFormat());

/**
 * @relatesalso dds::domain::qos::DomainParticipantFactoryQos
 * @brief @extension Prints a dds::sub::qos::DomainParticipantFactoryQos to an output stream.
 */
inline std::ostream& operator<<(
        std::ostream& out,
        const rti::domain::qos::DomainParticipantFactoryQos& qos);
#endif

RTI_DECL_POLICY_GETTER(
    DomainParticipantFactoryQosImpl, dds::core::policy::EntityFactory, entity_factory)

RTI_DECL_POLICY_GETTER(
    DomainParticipantFactoryQosImpl, rti::core::policy::SystemResourceLimits, resource_limits)

/*
RTI_DECL_POLICY_GETTER(
    DomainParticipantFactoryQosImpl, rti::core::policy::Logging, logging)
*/

/** @RTI_namespace_end dds::domain::qos */
} } } // namespace rti::domain::qos

#endif // RTI_DDS_DOMAIN_DOMAIN_PARTICIPANT_FACTORY_QOS_HPP_
