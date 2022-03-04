/* $Id$

(c) Copyright, Real-Time Innovations, 2019.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef RTI_DDS_CORE_COHERENT_SET_INFO_HPP_
#define RTI_DDS_CORE_COHERENT_SET_INFO_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "dds_c/dds_c_infrastructure.h"

#include <rti/core/NativeValueType.hpp>
#include <rti/core/detail/NativeConversion.hpp>
#include <rti/core/Guid.hpp>
#include <rti/core/SequenceNumber.hpp>

namespace rti { namespace core {

class CoherentSetInfoAdapter {
public:
    typedef struct DDS_CoherentSetInfo_t native_type;

    static void initialize(native_type& native_value)
    {
        struct DDS_CoherentSetInfo_t defaultValue = DDS_COHERENTSETINFO_DEFAULT;
        DDS_CoherentSetInfo_copy(&native_value, &defaultValue);
    }

    static void finalize(native_type&)
    {
        // nothing to do
    }

    static void copy(native_type& destination, const native_type& source)
    {
        DDS_CoherentSetInfo_copy(&destination, &source);
    }

    static bool equals(const native_type& first, const native_type& second)
    {
        return (DDS_CoherentSetInfo_equals(&first, &second) == DDS_BOOLEAN_TRUE);
    }
};

class CoherentSetInfo;

template <>
struct native_type_traits<CoherentSetInfo> {
    typedef rti::core::CoherentSetInfoAdapter adapter_type;
    typedef struct DDS_CoherentSetInfo_t native_type;
};

/** 
 * @ingroup DDSDataSampleModule
 * @RTI_class_definition class CoherentSetInfo 
 * @headerfile CoherentSetInfo.hpp "rti/core/CoherentSetInfo.hpp"
 *  
 * @brief @extension @st_value_type A CoherentSampleInfo provides information
 * about the coherent set associated with a sample.
 */
class CoherentSetInfo : public NativeValueType<CoherentSetInfo> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(CoherentSetInfo)

    typedef NativeValueType<CoherentSetInfo> Base;

    /**
     * @brief Create a default CoherentSampleInfo object.
     */
    CoherentSetInfo()
    {
    }

    /**
     * @brief Creates CoherentSampleInfo object with the specified parameters
     */
    CoherentSetInfo(
            const Guid &the_group_guid,  
            const SequenceNumber &the_coherent_set_sequence_number,
            const SequenceNumber &the_group_coherent_set_sequence_number,
            bool the_incomplete_coherent_set)
    {
        group_guid(the_group_guid);
        coherent_set_sequence_number(the_coherent_set_sequence_number);
        group_coherent_set_sequence_number(the_group_coherent_set_sequence_number);
        incomplete_coherent_set(the_incomplete_coherent_set);
    }

    CoherentSetInfo(const DDS_CoherentSetInfo_t &native_coherent_set_info) 
            : Base(native_coherent_set_info)
    {
    }

    /**
     * @brief Gets the coherent set group Guid.
     * 
     * @details \dref_details_CoherentSetInfo_group_guid
     */
    const Guid& group_guid() const
    {
        return rti::core::native_conversions::cast_from_native<Guid>(
                native().group_guid);
    }

    /**
     * @brief Gets the coherent set group Guid.
     *
     * @details \dref_details_CoherentSetInfo_group_guid
     */
    Guid& group_guid()
    {
        return rti::core::native_conversions::cast_from_native<Guid>(
                native().group_guid);
    }

    /**
     * @brief Sets the coherent set group Guid.
     *
     * @details \dref_details_CoherentSetInfo_group_guid
     */
    CoherentSetInfo& group_guid(const Guid& value) {
        native().group_guid = value.native();
        return *this;
    }

    /**
     * @brief Gets the coherent set sequence number that identifies a sample
     * as part of a DataWriter coherent set.
     * 
     * @details \dref_details_CoherentSetInfo_coherent_set_sequence_number
     */
    const SequenceNumber& coherent_set_sequence_number() const
    {
        return rti::core::native_conversions::cast_from_native<SequenceNumber>(
                native().coherent_set_sequence_number);
    }

    /**
     * @brief Gets the coherent set sequence number that identifies a sample
     * as part of a DataWriter coherent set.
     * 
     * @details \dref_details_CoherentSetInfo_coherent_set_sequence_number
     */
    SequenceNumber& coherent_set_sequence_number()
    {
        return rti::core::native_conversions::cast_from_native<SequenceNumber>(
                native().coherent_set_sequence_number);
    }

    /**
     * @brief Sets the coherent set sequence number that identifies a sample
     * as part of a DataWriter coherent set.
     *
     * @details \dref_details_CoherentSetInfo_group_guid
     */
    CoherentSetInfo& coherent_set_sequence_number(const SequenceNumber& value) {
        rti::core::native_conversions::cast_from_native<SequenceNumber>(
                native().coherent_set_sequence_number) = value.native();
        return *this;
    }

    /**
     * @brief Gets the group coherent set sequence number that identifies a sample
     * as part of a group coherent set.
     * 
     * @details \dref_details_CoherentSetInfo_group_coherent_set_sequence_number
     */
    const SequenceNumber& group_coherent_set_sequence_number() const
    {
        return rti::core::native_conversions::cast_from_native<SequenceNumber>(
                native().group_coherent_set_sequence_number);
    }

    /**
     * @brief Gets the group coherent set sequence number that identifies a sample
     * as part of a group coherent set.
     * 
     * @details \dref_details_CoherentSetInfo_group_coherent_set_sequence_number
     */
    SequenceNumber& group_coherent_set_sequence_number()
    {
        return rti::core::native_conversions::cast_from_native<SequenceNumber>(
                native().group_coherent_set_sequence_number);
    }

    /**
     * @brief Gets the group coherent set sequence number that identifies a sample
     * as part of a group coherent set.
     *
     * @details \dref_details_CoherentSetInfo_group_guid
     */
    CoherentSetInfo& group_coherent_set_sequence_number(const SequenceNumber& value) {
        rti::core::native_conversions::cast_from_native<SequenceNumber>(
                native().group_coherent_set_sequence_number) = value.native();
        return *this;
    }

    /**
     * @brief Indicates if a sample is part of an incomplete coherent set.
     */
    bool incomplete_coherent_set() const
    {
        return native().incomplete_coherent_set?true: false;
    }

    /**
     * @brief Sets the incomplete coherent set status
     */
    CoherentSetInfo& incomplete_coherent_set(bool value) 
    {
        native().incomplete_coherent_set =
                value ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;
        return *this;
    }

    /**
     * @brief An invalid or unknown coherent set info.
     */
    static CoherentSetInfo unknown()
    {
        return CoherentSetInfo();
    }
};

/**
 * @relates rti::core::CoherentSetInfo
 *
 * @brief Prints a CoherentSetInfo to an output stream
 */
inline std::ostream& operator<<(std::ostream& out, const CoherentSetInfo& csi)
{
    out << "[group_guid: " << csi.group_guid()
        << ", coherent_set_sequence_number: " << csi.coherent_set_sequence_number() 
        << ", group_coherent_set_sequence_number: " << csi.group_coherent_set_sequence_number() 
        << ", incomplete_coherent_set: " << csi.incomplete_coherent_set() << "]";
    return out;
}

} } // namespace rti::core

#endif // RTI_DDS_CORE_COHERENT_SET_INFO_HPP_
