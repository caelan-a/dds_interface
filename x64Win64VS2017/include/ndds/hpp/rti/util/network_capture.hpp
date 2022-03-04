/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef RTI_UTIL_NETWORK_CAPTURE_HPP_
#define RTI_UTIL_NETWORK_CAPTURE_HPP_

#include <iosfwd>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "ndds/ndds_utility_c.h"
#include <dds/domain/DomainParticipant.hpp>
#include <dds/core/SafeEnumeration.hpp>
#include <rti/core/NativeValueType.hpp>
#include <dds/core/vector.hpp>
#include <rti/core/ThreadSettings.hpp>
#include <bitset>

/**
 * \dref_NetworkCaptureGroupDocs
 */

/*
 * Adapters
 */

namespace rti { namespace util { namespace network_capture {
    class NetworkCaptureParams;
}}}

namespace rti { namespace core {

class NetworkCaptureParamsAdapter {
public:
    typedef struct NDDS_Utility_NetworkCaptureParams_t native_type;

    static void initialize(native_type& native_value)
    {
        NDDS_Utility_NetworkCaptureParams_t_initialize(&native_value);
    }

    static void finalize(native_type& native_value)
    {
        NDDS_Utility_NetworkCaptureParams_t_finalize(&native_value);
    }

    static void copy(native_type& destination, const native_type& source)
    {
        NDDS_Utility_NetworkCaptureParams_t_copy(&destination, &source);
    }

    static bool equals(const native_type& first, const native_type& second)
    {
        RTIOsapiUtility_unusedParameter(first);
        RTIOsapiUtility_unusedParameter(second);

        throw dds::core::UnsupportedError("Unsupported operation: equals");
    }
};

template <>
struct native_type_traits<rti::util::network_capture::NetworkCaptureParams> {
    typedef NetworkCaptureParamsAdapter adapter_type;
    typedef NDDS_Utility_NetworkCaptureParams_t native_type;
};

} } // namespace rti::core

namespace rti { namespace util {

/**
 * @brief @extension Contains the functions to enable and use the Network
 * Capture utility.
 */
namespace network_capture {

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief @extension Mask indicating the types of contents to remove from RTPS
 * frames before saving them to the capture file.
 *
 * @details \dref_details_NetworkCaptureContentKindMask
 */
class OMG_DDS_API ContentKindMask : public std::bitset<32> {
public:
    /**
     * @brief A typedef of std::bitset<32> for convenience
     */
    typedef std::bitset<32> MaskType;

public:
    /**
     * @brief Default constructor for ContentKindMask.
     */
    ContentKindMask()
    {
        MaskType(NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_DEFAULT);
    }

    /**
     * @brief Construct a ContentKindMask from an integer
     *
     * @param mask Value whose bits are copied to the bitset positions
     */
    explicit ContentKindMask(uint64_t mask)
        : MaskType(mask)
    {
    }

    /**
     * @brief Construct a ContentKindMask from a MaskType object
     *
     * @param mask A std::bitset<32> to construct this
     * NetworkCaptureContentKindMask from.
     */
    ContentKindMask(const MaskType& mask)
        : MaskType(mask)
    {
    }

    /** \dref_NetworkCaptureContentKind_NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_USER_SERIALIZED_DATA
    */
    static const ContentKindMask user()
    {
        return ContentKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_USER_SERIALIZED_DATA);
    }

    /** \dref_NetworkCaptureContentKind_NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_ENCRYPTED_DATA
    */
    static const ContentKindMask encrypted()
    {
        return ContentKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_ENCRYPTED_DATA);
    }

    /** \dref_NetworkCaptureContentKindMask_NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_MASK_DEFAULT
    */
    static const ContentKindMask default_mask()
    {
        return ContentKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_MASK_DEFAULT);
    }

    /** \dref_NetworkCaptureContentKindMask_NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_MASK_NONE
    */
    static const ContentKindMask none()
    {
        return ContentKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_MASK_NONE);
    }

    /** \dref_NetworkCaptureContentKindMask_NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_MASK_ALL
    */
    static const ContentKindMask all()
    {
        return ContentKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_CONTENT_MASK_ALL);
    }
};

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief @extension Mask indicating the traffic direction to capture.
 *
 * @details \dref_details_NetworkCaptureTrafficKindMask
 */
class OMG_DDS_API TrafficKindMask : public std::bitset<32> {
public:
    /**
     * @brief A typedef of std::bitset<32> for convenience
     */
    typedef std::bitset<32> MaskType;

public:
    /**
     * @brief Default constructor for TrafficKindMask.
     */
    TrafficKindMask()
    {
        MaskType(NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_DEFAULT);
    }

    /**
     * @brief Construct a TrafficKindMask from an integer
     *
     * @param mask Value whose bits are copied to the bitset positions
     */
    explicit TrafficKindMask(uint64_t mask)
        : MaskType(mask)
    {
    }

    /**
     * @brief Construct a TrafficKindMask from a MaskType object
     *
     * @param mask A std::bitset<32> to construct this TrafficKindMask from.
     */
    TrafficKindMask(const MaskType& mask)
        : MaskType(mask)
    {
    }

    /** \dref_NetworkCaptureTrafficKind_NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_OUT
    */
    static const TrafficKindMask out()
    {
        return TrafficKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_OUT);
    }

    /** \dref_NetworkCaptureTrafficKind_NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_IN
    */
    static const TrafficKindMask in()
    {
        return TrafficKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_IN);
    }

    /** \dref_NetworkCaptureTrafficKindMask_NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_DEFAULT
    */
    static const TrafficKindMask default_mask()
    {
        return TrafficKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_DEFAULT);
    }

    /** \dref_NetworkCaptureTrafficKindMask_NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_NONE
    */
    static const TrafficKindMask none()
    {
        return TrafficKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_NONE);
    }

    /** \dref_NetworkCaptureTrafficKindMask_NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_ALL
    */
    static const TrafficKindMask all()
    {
        return TrafficKindMask(
                NDDS_UTILITY_NETWORK_CAPTURE_TRAFFIC_MASK_ALL);
    }
};

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief @extension Input parameters for starting Network Capture.
 *
 * @details \dref_details_NetworkCaptureParams
 */
class OMG_DDS_API NetworkCaptureParams :
        public rti::core::NativeValueType<NetworkCaptureParams> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(NetworkCaptureParams)

    typedef rti::core::NativeValueType<NetworkCaptureParams> Base;

    NetworkCaptureParams(const NDDS_Utility_NetworkCaptureParams_t& native)
            : Base(native)
    {
    }

    /* Default constructor */
    NetworkCaptureParams()
    {
    }

    /**
     * @brief Get the list of transports to capture.
     *
     * @return List of transports to capture.
     */
    dds::core::StringSeq transports() const;

    /**
     * @brief Set the list of transports to capture.
     *
     * @details \dref_details_NetworkCaptureParams_transports
     *
     * @param transports_in The sequence of transports that we want to capture
     * traffic from.
     *
     * @return The Network Capture's parameter instance.
     */
    NetworkCaptureParams& transports(
            const dds::core::StringSeq&  transports_in);

    /**
     * @brief Get the type of contents to exclude from the capture file.
     *
     * @return Contents to exclude from the capture file.
     */
    ContentKindMask dropped_content() const;

    /**
     * @brief Set the type of contents to exclude from the capture file.
     *
     * @details \dref_details_NetworkCaptureParams_dropped_content
     *
     * @param dropped_content_in The mask of contents to exclude from the
     * capture.
     *
     * @return The Network Capture's parameter instance.
     */
    NetworkCaptureParams& dropped_content(
            ContentKindMask dropped_content_in);

    /**
     * @brief Get the traffic direction to capture.
     *
     * @return Traffic direction to capture.
     */
    TrafficKindMask traffic() const;

    /**
     * @brief Set the traffic direction to capture.
     *
     * @details \dref_details_NetworkCaptureParams_traffic
     *
     * @param traffic_in The mask with the traffic directions that we want to
     * capture.
     *
     * @return The Network Capture's parameter instance.
     */
    NetworkCaptureParams& traffic(TrafficKindMask traffic_in);

    /**
     * @brief Get whether Network Capture will parse encrypted contents.
     *
     * @return Whether Network Capture will parse encrypted contents.
     */
    bool parse_encrypted_content() const;

    /**
     * @brief Set whether Network Capture will parse encrypted contents.
     *
     * @details \dref_details_NetworkCaptureParams_parse_encrypted_content
     *
     * @param parse_encrypted_content_in Boolean indicating whether to parse or
     * not encrypted content.
     *
     * @return The Network Capture's parameter instance.
     */
    NetworkCaptureParams& parse_encrypted_content(
            bool parse_encrypted_content_in);

    /**
     * @brief Get the properties of the checkpoint thread.
     *
     * @return Properties of the checkpoint thread.
     */
    const rti::core::ThreadSettings& checkpoint_thread_settings() const;
    rti::core::ThreadSettings& checkpoint_thread_settings();

    /**
     * @brief Set the properties of the checkpoint thread.
     *
     * @details \dref_details_NetworkCaptureParams_checkpoint_thread_settings
     *
     * @param checkpoint_thread_settings_in Properties of the checkpoint thread
     * that we want to set.
     *
     * @return The Network Capture's parameter instance.
     */
    NetworkCaptureParams& checkpoint_thread_settings(
            const rti::core::ThreadSettings& checkpoint_thread_settings_in);

    /**
     * @brief Get the size of the frame queue (Bytes).
     *
     * @details \dref_details_NetworkCaptureParams_frame_queue_size
     *
     * @return Size of the frame queue (Bytes).
     */
    int32_t frame_queue_size() const;

    /**
     * @brief Set the size of the frame queue.
     *
     * @details \dref_details_NetworkCaptureParams_frame_queue_size
     *
     * @param frame_queue_size_in Size of the frame queue in Bytes.
     *
     * @return The Network Capture's parameter instance.
     */
    NetworkCaptureParams& frame_queue_size(int32_t frame_queue_size_in);
};

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Enable Network Capture.
 *
 * @details \dref_details_NetworkCapture_enable
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool enable();
/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Disable Network Capture.
 *
 * @details \dref_details_NetworkCapture_disable
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool disable();

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Set the default Network Capture parameters.
 *
 * @details \dref_details_NetworkCapture_set_default_params
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool set_default_params(const NetworkCaptureParams& params);

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Start Network Capture.
 *
 * @details \dref_details_NetworkCapture_start
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool start(const std::string& filename);

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Start Network Capture for a participant.
 *
 * @details \dref_details_NetworkCapture_start_for_participant
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool start(
        dds::domain::DomainParticipant participant,
        const std::string& filename);

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Start Network Capture with parameters.
 *
 * @details \dref_details_NetworkCapture_start_w_params
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool start(
        const std::string& filename,
        const NetworkCaptureParams& params);

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Start Network Capture with parameters for a participant.
 *
 * @details \dref_details_NetworkCapture_start_w_params_for_participant
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool start(
        dds::domain::DomainParticipant participant,
        const std::string& filename,
        const NetworkCaptureParams& params);

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Stop Network Capture.
 *
 * @details \dref_details_NetworkCapture_stop
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool stop();

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Stop Network Capture.
 *
 * @details \dref_details_NetworkCapture_stop_for_participant
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool stop(dds::domain::DomainParticipant participant);

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Pause Network Capture.
 *
 * @details \dref_details_NetworkCapture_pause
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool pause();

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Pause Network Capture.
 *
 * @details \dref_details_NetworkCapture_pause_for_participant
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool pause(dds::domain::DomainParticipant participant);

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Resume Network Capture.
 *
 * @details \dref_details_NetworkCapture_resume
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool resume();

/**
 * @ingroup NDDSNetworkCaptureModule
 * @brief Resume Network Capture.
 *
 * @details \dref_details_NetworkCapture_resume_for_participant
 *
 * @namespace_note rti::util::network_capture
 */
OMG_DDS_API
bool resume(dds::domain::DomainParticipant participant);

} } } // rti::util::network_capture

#endif // RTI_UTIL_NETWORK_CAPTURE_HPP_
