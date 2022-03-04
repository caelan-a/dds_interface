/* $Id$

(c) Copyright, Real-Time Innovations, 2019.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

============================================================================= */

#ifndef RTI_DDS_CORE_XTYPES_DYNAMICTYPEPRINTFORMAT_HPP_
#define RTI_DDS_CORE_XTYPES_DYNAMICTYPEPRINTFORMAT_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <ostream>

#include "dds_c/dds_c_printformat.h"

#include <rti/core/NativeValueType.hpp>

namespace rti { namespace core { namespace xtypes {

class DynamicTypePrintFormatProperty;

} // namespace xtypes

typedef PODNativeAdapter<DDS_TypeCodePrintFormatProperty> DynamicTypePrintFormatPropertyAdapter;

template<>
struct native_type_traits<xtypes::DynamicTypePrintFormatProperty> {
    typedef DynamicTypePrintFormatPropertyAdapter adapter_type;
    typedef DynamicTypePrintFormatPropertyAdapter::native_type native_type;
};

} } // namespace rti::core

namespace rti { namespace core { namespace xtypes {

/**
 * @ingroup DDSXTypesModule 
 * @headerfile rti/core/xtypes/DynamicTypePrintFormat.hpp
 * @RTI_class_definition class DynamicTypePrintFormatProperty 
 *
 * @brief @extension @st_value_type A collection of attributes used to 
 * configure how DynamicTypes will be formatted when converted 
 * to strings.
 *
 * @see rti::core::xtypes::to_string 
 */
class OMG_DDS_API DynamicTypePrintFormatProperty
    : public rti::core::NativeValueType<DynamicTypePrintFormatProperty> {

public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(DynamicTypePrintFormatProperty)

public:
    /**
     * @brief Initializes the properties
     */
    explicit DynamicTypePrintFormatProperty(
            unsigned int indent_in = 0,
            bool print_ordinals_in = false)
    {
        indent(indent_in);
        print_ordinals(print_ordinals_in);
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
     * a DynamicType to a string.
     *
     * @details \dref_details_TypeCodePrintFormatProperty_indent
     *
     * @param value The value to set for indent
     */
    DynamicTypePrintFormatProperty& indent(unsigned int value)
    {
        native().indent = value;
        return *this;
    }

    /**
     * @brief Get the value of print_ordinals.
     * @see print_ordinals(bool value)
     */
    bool print_ordinals() const
    {
        return native().print_ordinals == DDS_BOOLEAN_TRUE;
    }

    /**
     * @brief Set whether or not to print ordinal values when printing
     * EnumTypes.
     *
     * @details \dref_details_TypeCodePrintFormatProperty_print_ordinals
     *
     * @param value The value to set for print_ordinals
     */
    DynamicTypePrintFormatProperty& print_ordinals(bool value)
    {
        native().print_ordinals = value ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;
        return *this;
    }
};

} } } // namespace rti::core::xtypes

#endif // RTI_DDS_CORE_XTYPES_DYNAMICTYPEPRINTFORMAT_HPP_
