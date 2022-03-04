/* $Id$

(c) Copyright, Real-Time Innovations, 2019.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

============================================================================= */

#ifndef RTI_RTI_CORE_QOSPRINTFORMAT_HPP_
#define RTI_RTI_CORE_QOSPRINTFORMAT_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <ostream>

// For the DDS_QosPrintFormat definition
#include "dds_c/dds_c_infrastructure.h"

#include <rti/core/NativeValueType.hpp>

#ifndef RTI_NO_CXX11_HDR_INITIALIZER_LIST
#include <initializer_list>
#endif

namespace rti { namespace core {

// Forward Declaration
class QosPrintFormat;

typedef PODNativeAdapter<DDS_QosPrintFormat> QosPrintFormatAdapter;

template<>
struct native_type_traits<QosPrintFormat> {
    typedef QosPrintFormatAdapter adapter_type;
    typedef QosPrintFormatAdapter::native_type native_type;
};

/**
 * @ingroup DDSInfrastructureModule 
 * @headerfile rti/core/QosPrintFormat.hpp
 * @RTI_class_definition class QosPrintFormat 
 *
 * @brief @extension @st_value_type A collection of attributes used to 
 * configure how QoS will be formatted when converted 
 * to strings.
 */
class OMG_DDS_API QosPrintFormat
    : public rti::core::NativeValueType<QosPrintFormat> {

public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(QosPrintFormat)

public:
    /**
     * @brief Initializes the properties with the default values.
     */
    QosPrintFormat()
    {
        indent(0);
        print_private(false);
        is_standalone(false);
    }

    /**
     * @brief Initializes the properties
     */
    QosPrintFormat(
            unsigned int indent_in,
            bool print_private_in,
            bool is_standalone_in)
    {
        indent(indent_in);
        print_private(print_private_in);
        is_standalone(is_standalone_in);
    }

    /**
     * @brief Get the value of indent.
     * @see indent(unsigned int value)
     */
    unsigned int indent() const
    {
        return native().indent;
    }

    /**
     * @brief Set the amount of additional indent to be included when converting
     * a QoS to a string.
     *
     * @details \dref_details_QosPrintFormat_indent
     *
     * @param value The value to set for indent
     */
    QosPrintFormat& indent(unsigned int value)
    {
        native().indent = value;
        return *this;
    }

    /**
     * @brief Get the value of print_private.
     * @see print_private(bool value)
     */
    bool print_private() const
    {
        return native().print_private == DDS_BOOLEAN_TRUE;
    }

    /**
     * @brief Set whether or not to print private Qos fields.
     *
     * @details \dref_details_QosPrintFormat_print_private
     *
     * @param value The value to set for print_private.
     */
    QosPrintFormat& print_private(bool value)
    {
        native().print_private = value ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;
        return *this;
    }

    /**
     * @brief Get the value of is_standalone.
     * @see print_private(bool value)
     */
    bool is_standalone() const
    {
        return native().is_standalone == DDS_BOOLEAN_TRUE;
    }

    /**
     * @brief Set whether or not to print the XML preamble.
     *
     * @details \dref_details_QosPrintFormat_is_standalone
     *
     * @param value The value to set for is_standalone.
     */
    QosPrintFormat& is_standalone(bool value)
    {
        native().is_standalone = value ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;
        return *this;
    }
};

} } // namespace rti::core

#endif // RTI_RTI_CORE_QOSPRINTFORMAT_HPP_
