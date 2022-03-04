/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef RTI_UTIL_UTIL_HPP_
#define RTI_UTIL_UTIL_HPP_

#include <iosfwd>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "ndds/ndds_utility_c.h"
#include "helper.hpp"
#include "network_capture.hpp"

#include <dds/core/Duration.hpp>
#include <dds/core/SafeEnumeration.hpp>
#include <rti/core/NativeValueType.hpp>

/**
 * \dref_HeapMonitoringGroupDocs
 */

/*
 * Adapters
 */
namespace rti { namespace util { namespace heap_monitoring {

typedef rti::core::PODNativeAdapter<NDDS_Utility_HeapMonitoringParams_t>
        HeapMonitoringParamsAdapter;
class HeapMonitoringParams;

} } // namespace util::heap_monitoring

namespace core {

template <>
struct native_type_traits<rti::util::heap_monitoring::HeapMonitoringParams> {
    typedef rti::util::heap_monitoring::HeapMonitoringParamsAdapter adapter_type;
    typedef NDDS_Utility_HeapMonitoringParams_t native_type;
};

} } // namespace rti::core

namespace rti {

/**
 * @brief @extension Contains general-purpose utilities
 */
namespace util {

/**
 * @brief @extension Contains the functions to enable and use the
 * heap-monitoring utility.
 */
namespace heap_monitoring {

/** \dref_HeapMonitoringSnapshotOutputFormat
 */
/**
 * @ingroup NDDSHeapMonitoringModule
 * @headerfile rti/util/util.hpp
 * @brief The definition of the rti::util::heap_monitoring SnapshotOutputFormat;
 */
struct SnapshotOutputFormat_def {

    typedef NDDS_Utility_HeapMonitoringSnapshotOutputFormat native_type;

    /**
     * @brief The underlying \p enum type
     */
    enum type {
        /** \dref_HeapMonitoringSnapshotOutputFormat_NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_OUTPUT_FORMAT_STANDARD
        */
        STANDARD = NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_OUTPUT_FORMAT_STANDARD,

        /** \dref_HeapMonitoringSnapshotOutputFormat_NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_OUTPUT_FORMAT_COMPRESSED
        */
        COMPRESSED = NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_OUTPUT_FORMAT_COMPRESSED
    };
};

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Specify the format of the output of the snapshot.
 *
 * @see SnapshotOutputFormat_def
 */
typedef dds::core::safe_enum<SnapshotOutputFormat_def> SnapshotOutputFormat;

/** \dref_HeapMonitoringSnapshotContentFormat
 */
/**
 * @ingroup NDDSHeapMonitoringModule
 * @headerfile rti/util/util.hpp
 * @brief The definition of the rti::util::heap_monitoring SnapshotContentFormat;
 */
struct SnapshotContentFormat_def {

    typedef NDDS_Utility_HeapMonitoringSnapshotContentFormat native_type;

    /**
     * @brief The underlying \p enum type
     */
    enum type {
        /** \dref_HeapMonitoringSnapshotContentFormat_NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_BIT_TOPIC
        */
        TOPIC = NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_BIT_TOPIC,

        /** \dref_HeapMonitoringSnapshotContentFormat_NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_BIT_FUNCTION
        */
        FUNCTION = NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_BIT_FUNCTION,

        /** \dref_HeapMonitoringSnapshotContentFormat_NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_BIT_ACTIVITY
        */
        ACTIVITY = NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_BIT_ACTIVITY,

        /** \dref_HeapMonitoringSnapshotContentFormat_NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_DEFAULT
        */
        DEFAULT = NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_DEFAULT,

        /** \dref_HeapMonitoringSnapshotContentFormat_NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_MINIMAL
        */
        MINIMAL = NDDS_UTILITY_HEAP_MONITORING_SNAPSHOT_CONTENT_MINIMAL
    };
};

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Bitmap used to decide which information of the snapshot will be displayed.
 *
 * @see SnapshotContentFormat_def
 */
typedef dds::core::safe_enum<SnapshotContentFormat_def> SnapshotContentFormat;

/** \dref_HeapMonitoringParams
 */
/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief @extension Input parameters for enabling heap monitoring
 * They will be used for configuring the format of the snapshot.
 */
class OMG_DDS_API HeapMonitoringParams : public rti::core::NativeValueType<HeapMonitoringParams> {

  public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(HeapMonitoringParams)

    typedef rti::core::NativeValueType<HeapMonitoringParams> Base;

    /**
     * @brief Create HeapMonitoringParams.
     * @param snapshot_output_format The format of the output of the snapshot.
     * @param snapshot_content_format The bitmap to decide which information of
     * the snapshot will be displayed.
     */
    HeapMonitoringParams(
            SnapshotOutputFormat snapshot_output_format =
                    rti::util::heap_monitoring::SnapshotOutputFormat::STANDARD,
            SnapshotContentFormat snapshot_content_format =
                    rti::util::heap_monitoring::SnapshotContentFormat::DEFAULT);

    HeapMonitoringParams(
            const struct NDDS_Utility_HeapMonitoringParams_t& native)
      : Base(native)
    {
    }

    /**
     * @brief Get the format of the output of the snapshot
     *
     * @return The format of the output of the snapshot
     */
    SnapshotOutputFormat snapshot_output_format() const;

    /**
     * @brief Set the format of the output of the snapshot
     *
     * @param snapshot_output_format The format of the output of the snapshot
     */
    void snapshot_output_format(SnapshotOutputFormat snapshot_output_format);

    /**
     * @brief Get the bitmap to decide which information of the snapshot will
     * be displayed.
     *
     * @return The bitmap to decide which information of the snapshot will be
     * displayed.
     */
    SnapshotContentFormat snapshot_content_format() const;

    /**
     * @brief Set the bitmap to decide which information of the snapshot will
     * be displayed.
     *
     * @param snapshot_content_format The bitmap to decide which information of
     * the snapshot will be displayed.
     */
    void snapshot_content_format(SnapshotContentFormat snapshot_content_format);
  };

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Starts monitoring the heap memory used by \ndds.
 *
 * @details \dref_details_HeapMonitoring_enable
 *
 * @namespace_note rti::util::heap_monitoring
 */
OMG_DDS_API
bool enable();

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Starts monitoring the heap memory used by \ndds with params.
 *
 * @details \dref_details_HeapMonitoring_enable_w_params
 *
 * @namespace_note rti::util::heap_monitoring
 */
OMG_DDS_API
bool enable(const HeapMonitoringParams& params);

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Stops monitoring the heap memory used by \ndds.
 *
 * @details \dref_details_HeapMonitoring_disable
 *
 * @namespace_note rti::util::heap_monitoring
 */
OMG_DDS_API
void disable();

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Pauses heap monitoring.
 *
 * @details \dref_details_HeapMonitoring_pause
 *
 * @namespace_note rti::util::heap_monitoring
 */
OMG_DDS_API
bool pause();

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Resumes heap monitoring.
 *
 * @details \dref_details_HeapMonitoring_resume
 *
 * @namespace_note rti::util::heap_monitoring
 */
OMG_DDS_API
bool resume();

/**
 * @ingroup NDDSHeapMonitoringModule
 * @brief Saves the current heap memory usage in a file.
 *
 * @details \dref_details_HeapMonitoring_take_heap_snapshot
 *
 * @namespace_note rti::util::heap_monitoring
 */
OMG_DDS_API
bool take_snapshot(const std::string& filename, bool print_details = false);

} // namespace heap_monitoring

/**
 * \dref_UtilitiesGroupDocs
 */

/**
 * @ingroup NDDSUtilitiesModule
 * @brief Blocks the calling thread for the specified duration.
 *
 * @details \dref_details_Utilities_sleep
 */
OMG_DDS_API
void sleep(const dds::core::Duration& durationIn);

/**
 * @ingroup NDDSUtilitiesModule
 * @brief Returns the number of spin operations needed to wait 1 microsecond.
 *
 * @details \dref_details_Utilities_get_spin_per_microsecond
 */
OMG_DDS_API
uint64_t spin_per_microsecond();

/**
 * @ingroup NDDSUtilitiesModule
 * @brief Performs a spin operation (active wait) as many times as indicated.
 *
 * @details \dref_details_Utilities_spin
 */
OMG_DDS_API
void spin(uint64_t spin_count);

/**
 * @private
 * @brief @extension Contains the functions to enable Function History feature.
 */
namespace function_history {

    /**
     * @ingroup NDDSUtilitiesModule
     * @private
     * @brief enables Function History feature.
     *
     */
    OMG_DDS_API
    bool enable();

} } } // namespace rti::util::function_history

#endif // RTI_UTIL_UTIL_HPP_
