/* $Id$

(c) Copyright, Real-Time Innovations, 2020-2020.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef RTI_CONFIG_ACTIVITY_CONTEXT_HPP_
#define RTI_CONFIG_ACTIVITY_CONTEXT_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>

#include "ndds/ndds_config_c.h"

#include <bitset>
/**
 * \dref_ActivityContextGroupDocs
 */

namespace rti { namespace config { namespace activity_context {

/**
 * @ingroup DDSActivityContextModule
 * @brief The attributes used in the string representation of the Activity
 * Context can be configured through this mask.
 *
 * @details \dref_details_ActivityContextAttributeKindMask
 */
class OMG_DDS_API AttributeKindMask : public std::bitset<32> {
public:
    /**
     * @brief A typedef of std::bitset<32> for convenience
     */
    typedef std::bitset<32> MaskType;

public:
    /** \dref_ActivityContextAttributeKindMask_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_NONE
    */
    AttributeKindMask()
    {
        MaskType(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_NONE);
    }

    /**
     * @brief Construct a AttributeKindMask from an integer
     *
     * @param mask Value whose bits are copied to the bitset positions
     */
    explicit AttributeKindMask(uint64_t mask)
        : MaskType(mask)
    {
    }

    /**
     * @brief Construct a AttributeKindMask from a MaskType object
     *
     * @param mask A std::bitset<32> to construct this AttributeKindMask from
     */
    AttributeKindMask(const MaskType& mask)
        : MaskType(mask)
    {
    }

    /** \dref_ActivityContextAttributeKind_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_GUID_PREFIX
    */
    static const AttributeKindMask guid_prefix()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_GUID_PREFIX);
    }

    /** \dref_ActivityContextAttributeKind_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_TOPIC
    */
    static const AttributeKindMask topic()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_TOPIC);
    }

    /** \dref_ActivityContextAttributeKind_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_TYPE
    */
    static const AttributeKindMask type()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_TYPE);
    }

    /** \dref_ActivityContextAttributeKind_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_ENTITY_KIND
    */
    static const AttributeKindMask entity_kind()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_ENTITY_KIND);
    }

    /** \dref_ActivityContextAttributeKind_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_DOMAIN_ID
    */
    static const AttributeKindMask domain_id()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_DOMAIN_ID);
    }

    /** \dref_ActivityContextAttributeKind_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_ENTITY_NAME
    */
    static const AttributeKindMask entity_name()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_ENTITY_NAME);
    }

    /** \dref_ActivityContextAttributeKindMask_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_DEFAULT
    */
    static const AttributeKindMask default_mask()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_DEFAULT);
    }

    /** \dref_ActivityContextAttributeKindMask_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_NONE
    */
    static const AttributeKindMask none()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_NONE);
    }

    /** \dref_ActivityContextAttributeKindMask_NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_ALL
    */
    static const AttributeKindMask all()
    {
        return AttributeKindMask(NDDS_CONFIG_ACTIVITY_CONTEXT_ATTRIBUTE_MASK_ALL);
    }
};


/**
 * \dref_ActivityContext_set_attribute_mask
 * @ingroup DDSActivityContextModule
 * @brief Set the AttributeKindMask of the Activity Context.
 */
OMG_DDS_API
void set_attribute_mask(AttributeKindMask attribute_mask);

} } } // namespace rti::config::activity_context

#endif // RTI_CONFIG_ACTIVITY_CONTEXT_HPP_
