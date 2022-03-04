/* $Id$

(c) Copyright, Real-Time Innovations, 2015-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

/*
 * This header defines supporting types that CorePolicy.hpp uses
 */

#ifndef RTI_DDS_CORE_POLICY_SETTINGS_HPP_
#define RTI_DDS_CORE_POLICY_SETTINGS_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "dds_c/dds_c_infrastructure.h"

#include <dds/core/types.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/vector.hpp>
#include <dds/core/Exception.hpp>
#include <rti/core/NativeValueType.hpp>
#include <rti/core/detail/NativeSequence.hpp>
#include <rti/core/policy/PolicyKind.hpp>

namespace rti { namespace core {

typedef PODNativeAdapter<DDS_AllocationSettings_t> AllocationSettingsAdapter;

class AllocationSettings;

template<>
struct native_type_traits<AllocationSettings> {
    typedef rti::core::AllocationSettingsAdapter adapter_type;
    typedef DDS_AllocationSettings_t native_type;
};

/**
 * @RTI_class_definition class AllocationSettings
 * @ingroup DDSDomainParticipantResourceLimitsQosModule
 * @headerfile rti/core/PolicySettings.hpp
 *
 * @brief @extension Resource allocation settings
 *
 * @details \dref_details_AllocationSettings_t
 */
class AllocationSettings : public NativeValueType<AllocationSettings> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(AllocationSettings)

    typedef NativeValueType<AllocationSettings> Base;

public:
    /**
     * @brief A special value indicating that the quantity is
     *        derived from a different Qos value
     */
    static const int32_t AUTO_COUNT = -2;

    /**
     * @brief Creates an instance with an initial, max and incremental count
     * set to zero.
     */
    AllocationSettings()
    {
    }

    /**
     * @brief Creates an instance with the given initial, maximum and
     * incremental values
     */
    AllocationSettings(
            int32_t the_initial_count,
            int32_t the_max_count,
            int32_t the_incremental_count)
    {
        initial_count(the_initial_count);
        max_count(the_max_count);
        incremental_count(the_incremental_count);
    }

    AllocationSettings(const DDS_AllocationSettings_t& native_settings)
            : Base(native_settings)
    {
    }

    /**
     * @brief Getter (see setter with the same name)
     */
    int32_t initial_count() const
    {
        return native().initial_count;
    }

    /**
     * @brief Sets the initial count of resources
     *
     * @details \dref_details_AllocationSettings_t_initial_count
     */
    AllocationSettings& initial_count(int32_t the_initial_count)
    {
        native().initial_count = the_initial_count;
        return *this;
    }

    /**
     * @brief Getter (see setter with the same name)
     */
    int32_t max_count() const
    {
        return native().max_count;
    }

    /**
     * @brief Sets the maximum count of resources
     *
     * @details \dref_details_AllocationSettings_t_max_count
     */
    AllocationSettings& max_count(int32_t the_max_count)
    {
        native().max_count = the_max_count;
        return *this;
    }

    /**
     * @brief Getter (see setter with the same name)
     */
    int32_t incremental_count() const
    {
        return native().incremental_count;
    }

    /**
     * @brief Sets the incremental count of resources
     *
     * @details \dref_details_AllocationSettings_t_incremental_count
     */
    AllocationSettings& incremental_count(int32_t the_incremental_count)
    {
        native().incremental_count = the_incremental_count;
        return *this;
    }
};

class ChannelSettings;

class ChannelSettingsAdapter {
public:
    typedef struct DDS_ChannelSettings_t native_type;

    static void initialize(native_type& native_value)
    {
        DDS_ChannelSettings_t_initialize(&native_value);
    }

    static void finalize(native_type& native_value)
    {
        DDS_ChannelSettings_t_finalize(&native_value);
    }

    static void copy(native_type& destination, const native_type& source)
    {
        DDS_ChannelSettings_t_copy(&destination, &source);
    }

    static bool equals(const native_type& first, const native_type& second)
    {
        return
            (DDS_ChannelSettings_t_equals(&first, &second) == DDS_BOOLEAN_TRUE);
    }
};

template<>
struct native_type_traits<ChannelSettings> {
    typedef ChannelSettingsAdapter adapter_type;
    typedef ChannelSettingsAdapter::native_type native_type;
};

class TransportUnicastSettings;

class TransportUnicastSettingsAdapter {
public:
    typedef DDS_TransportUnicastSettings_t native_type;

    static void initialize(native_type& native_value)
    {
        DDS_TransportUnicastSettings_t_initialize(&native_value);
    }

    static void finalize(native_type& native_value)
    {
        DDS_TransportUnicastSettings_t_finalize(&native_value);
    }

    static void copy(native_type& destination, const native_type& source)
    {
        DDS_TransportUnicastSettings_t_copy(&destination, &source);
    }

    static bool equals(const native_type& first, const native_type& second)
    {
        return (DDS_TransportUnicastSettings_t_equals(&first, &second)
                == DDS_BOOLEAN_TRUE);
    }
};

template<>
struct native_type_traits<TransportUnicastSettings> {
    typedef TransportUnicastSettingsAdapter adapter_type;
    typedef TransportUnicastSettingsAdapter::native_type native_type;
};

class TransportMulticastSettings;

class TransportMulticastSettingsAdapter {
public:
    typedef struct DDS_TransportMulticastSettings_t native_type;

    static void initialize(native_type& native_value)
    {
        DDS_TransportMulticastSettings_t_initialize(&native_value);
    }

    static void finalize(native_type& native_value)
    {
        DDS_TransportMulticastSettings_t_finalize(&native_value);
    }

    static void copy(native_type& destination, const native_type& source)
    {
        DDS_TransportMulticastSettings_t_copy(&destination, &source);
    }

    static bool equals(const native_type& first, const native_type& second)
    {
        return
            (DDS_TransportMulticastSettings_equals(&first, &second) == RTI_TRUE);
    }
};

template<>
struct native_type_traits<TransportMulticastSettings> {
    typedef TransportMulticastSettingsAdapter adapter_type;
    typedef TransportMulticastSettingsAdapter::native_type native_type;
};

/**
 * @RTI_class_definition class TransportUnicastSettings
 * @ingroup DDSTransportUnicastQosModule
 * @headerfile rti/core/policy/CorePolicy.hpp
 *
 * @brief @extension Represents a list of unicast locators
 *
 * @details \dref_details_TransportUnicastSettings_t
 */
class OMG_DDS_API TransportUnicastSettings
    : public NativeValueType<TransportUnicastSettings> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(TransportUnicastSettings)
    typedef NativeValueType<TransportUnicastSettings> Base;

    /**
     * @brief Creates the default policy
     */
    TransportUnicastSettings() { }

    /**
     * @brief Creates an instance with the specified transports and receive_port
     */
    explicit TransportUnicastSettings(
        const dds::core::StringSeq& transports,
        int32_t receive_port = 0);

    // For internal use
    /* implicit */ TransportUnicastSettings(
        const DDS_TransportUnicastSettings_t& native_value) : Base(native_value)
    {
    }

    /**
     * @brief Sets a sequence of transport aliases that specifies the unicast
     * interfaces on which to receive \em unicast traffic for the entity.
     *
     * @dref_TransportUnicastSettings_t_transports
     */
    TransportUnicastSettings& transports(const dds::core::StringSeq& value);

    /**
     * @brief Getter (see setter with the same name)
     */
    dds::core::StringSeq transports() const;

    /**
     * @brief The unicast port on which the entity can receive data.
     *
     * @dref_TransportUnicastSettings_t_receive_port
     */
    TransportUnicastSettings& receive_port(int32_t value);

    /**
     * @brief Getter (see setter with the same name)
     */
    int32_t receive_port() const;
};

/**
 * @ingroup DDSTransportUnicastQosModule
 * @headerfile rti/core/policy/CorePolicy.hpp
 *
 * @brief @extension A sequence of TransportUnicastSettings
 */
typedef std::vector<TransportUnicastSettings> TransportUnicastSettingsSeq;

namespace detail { // rti::core::detail

RTI_DEFINE_SEQUENCE_TRAITS(DDS_TransportUnicastSettings_t, DDS_TransportUnicastSettingsSeq);

} // namespace detail

/**
 * @RTI_class_definition class TransportMulticastSettings
 * @ingroup DDSTransportMulticastQosModule
 * @headerfile rti/core/policy/CorePolicy.hpp
 *
 * @brief @extension Represents a list of multicast locators
 *
 * @details \dref_details_TransportMulticastSettings_t
 */
class OMG_DDS_API TransportMulticastSettings : public NativeValueType<TransportMulticastSettings> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(TransportMulticastSettings)

    typedef NativeValueType<TransportMulticastSettings> Base;
public:

    TransportMulticastSettings() {}

    /**
     * @brief Creates an instance with the specified transport aliases, receive
     * address and receive port
     *
     * See individual setters.
     */
    TransportMulticastSettings(
        const dds::core::StringSeq& the_transports,
        const std::string& the_receive_address,
        int32_t the_receive_port)
    {
        transports(the_transports);
        receive_address(the_receive_address);
        receive_port(the_receive_port);
    }

    TransportMulticastSettings(
        const struct DDS_TransportMulticastSettings_t&
            native_transport_multicast_settings)
      : Base(native_transport_multicast_settings)
    {
    }

public:

    /**
     * \dref_TransportMulticastSettings_t_transports
     */
    TransportMulticastSettings& transports(
        const dds::core::StringSeq& the_transports)
    {
        using namespace rti::core::native_conversions;
        to_native(native().transports, the_transports);

        return *this;
    }

    /**
     * @brief Getter (see the setter with the same name)
     */
    dds::core::StringSeq transports() const
    {
        using namespace rti::core::native_conversions;
        return from_native<std::string, DDS_StringSeq>(
            native().transports);
    }

    /**
     * \dref_TransportMulticastSettings_t_receive_address
     */
    TransportMulticastSettings& receive_address(
        const std::string& the_receive_address);


    /**
     * @brief Getter (see the setter with the same name)
     */
    std::string receive_address() const
    {
        return native().receive_address;
    }

    /**
     * \dref_TransportMulticastSettings_t_receive_port
     */
    TransportMulticastSettings& receive_port(int32_t the_receive_port)
    {
        native().receive_port = (DDS_Long)the_receive_port;
        return *this;
    }

    /**
     * @brief Getter (see the setter with the same name)
     */
    int32_t receive_port() const
    {
        return native().receive_port;
    }
};

/**
 * @ingroup DDSTransportMulticastQosModule
 * @brief A sequence of TransportMulticastSettings
 */
typedef std::vector<TransportMulticastSettings> TransportMulticastSettingsSeq;

namespace detail { // rti::core::detail

RTI_DEFINE_SEQUENCE_TRAITS(DDS_TransportMulticastSettings_t, DDS_TransportMulticastSettingsSeq);

} // namespace detail

/**
 * \dref_PUBLICATION_PRIORITY_UNDEFINED
 */
const int32_t PUBLICATION_PRIORITY_UNDEFINED = DDS_PUBLICATION_PRIORITY_UNDEFINED;

/**
 * \dref_PUBLICATION_PRIORITY_AUTOMATIC
 */
const int32_t PUBLICATION_PRIORITY_AUTOMATIC = DDS_PUBLICATION_PRIORITY_AUTOMATIC;

// ----------------------------------------------------------------------------

/**
 * @RTI_class_definition class ChannelSettings
 * @ingroup DDSMultiChannelQosModule
 * @headerfile rti/core/policy/CorePolicy.hpp
 *
 * @brief @extension Configures the properties of a channel in rti::core::policy::MultiChannel
 *
 * @details \dref_details_ChannelSettings_t
 */
class OMG_DDS_API ChannelSettings : public NativeValueType<ChannelSettings> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(ChannelSettings)

    typedef NativeValueType<ChannelSettings> Base;

public:

    ChannelSettings() {}

    /**
     * @brief Creates an instance with the specified multicast settings, filter
     * expression and priority.
     *
     * See individual setters.
     */
    ChannelSettings(
        const TransportMulticastSettingsSeq& the_multicast_settings,
        const std::string& the_filter_expression,
        int32_t the_priority)
    {
        multicast_settings(the_multicast_settings);
        filter_expression(the_filter_expression);
        priority(the_priority);
    }

    ChannelSettings(const struct DDS_ChannelSettings_t& native_channel_settings)
      : Base(native_channel_settings)
    {
    }

    /**
     * \dref_ChannelSettings_t_multicast_settings
     */
    ChannelSettings& multicast_settings(
        const TransportMulticastSettingsSeq& the_multicast_settings);

    /**
     * @brief Getter (see the setter with the same name)
     */
    TransportMulticastSettingsSeq multicast_settings() const;

    /**
     * \dref_ChannelSettings_t_filter_expression
     */
    ChannelSettings& filter_expression(
        const std::string& the_filter_expression)
    {
        if (!DDS_String_replace(
                &native().filter_expression, the_filter_expression.c_str())) {
            throw std::bad_alloc();
        }
        return *this;
    }

    /**
     * @brief Getter (see the setter with the same name)
     */
    std::string filter_expression() const
    {
        return native().filter_expression;
    }

    /**
     * \dref_ChannelSettings_t_priority
     */
    ChannelSettings& priority(int32_t the_priority)
    {
        native().priority = (DDS_Long)the_priority;
        return *this;
    }

    /**
     * @brief Getter (see the setter with the same name)
     */
    int32_t priority() const
    {
        return native().priority;
    }
};

/**
 * @ingroup DDSMultiChannelQosModule
 * @brief @extension A sequence of ChannelSettings
 */
typedef std::vector<ChannelSettings> ChannelSettingsSeq;

namespace detail { // rti::core::detail

RTI_DEFINE_SEQUENCE_TRAITS(DDS_ChannelSettings_t, DDS_ChannelSettingsSeq);

} // namespace detail

class RtpsReliableReaderProtocol;

class RtpsReliableReaderProtocolAdapter {
public:
    typedef struct DDS_RtpsReliableReaderProtocol_t native_type;

    static void initialize(native_type& native_value)
    {
        static const DDS_RtpsReliableReaderProtocol_t default_value =
            DDS_RTPS_RELIABLE_READER_PROTOCOL_DEFAULT;
        native_value = default_value;
    }

    static void finalize(native_type&)
    {
        // nothing to do
    }

    static void copy(native_type& destination, const native_type& source)
    {
        DDS_RtpsReliableReaderProtocol_copy(&destination, &source);
    }

    static bool equals(const native_type& first, const native_type& second)
    {
        return DDS_RtpsReliableReaderProtocol_equals(
            &first, &second) == DDS_BOOLEAN_TRUE;
    }
};

template <>
struct native_type_traits<RtpsReliableReaderProtocol> {
    typedef RtpsReliableReaderProtocolAdapter adapter_type;
    typedef DDS_RtpsReliableReaderProtocol_t native_type;
};


/**
 * @RTI_class_definition class RtpsReliableReaderProtocol
 * @ingroup DDSDataReaderProtocolQosModule
 * @headerfile rti/core/policy/CorePolicy.hpp
 *
 * @brief @extension Configures aspects of the RTPS protocol related to a
 * reliable DataReader
 *
 * @details \dref_details_RtpsReliableReaderProtocol_t
 */
class OMG_DDS_API RtpsReliableReaderProtocol :
    public NativeValueType<RtpsReliableReaderProtocol> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(
        RtpsReliableReaderProtocol)

    typedef NativeValueType<RtpsReliableReaderProtocol> Base;

public:
    /**
     * @brief Creates an instance with the default settings
     */
    RtpsReliableReaderProtocol() {}

    RtpsReliableReaderProtocol(
        const DDS_RtpsReliableReaderProtocol_t& native_value)
      : Base(native_value)
    {
    }

    /**
     * \dref_RtpsReliableReaderProtocol_t_min_heartbeat_response_delay
     */
    RtpsReliableReaderProtocol& min_heartbeat_response_delay(
        const dds::core::Duration& the_min_heartbeat_response_delay);
    /**
     * @brief Getter (see setter with the same name)
     */
    dds::core::Duration min_heartbeat_response_delay() const;

    /**
     * \dref_RtpsReliableReaderProtocol_t_max_heartbeat_response_delay
     */
    RtpsReliableReaderProtocol& max_heartbeat_response_delay(
        const dds::core::Duration& the_max_heartbeat_response_delay);
    /**
     * @brief Getter (see setter with the same name)
     */
    dds::core::Duration max_heartbeat_response_delay() const;

    /**
     * \dref_RtpsReliableReaderProtocol_t_heartbeat_suppression_duration
     */
    RtpsReliableReaderProtocol& heartbeat_suppression_duration(
        const dds::core::Duration& the_heartbeat_suppression_duration);
    /**
     * @brief Getter (see setter with the same name)
     */
    dds::core::Duration heartbeat_suppression_duration() const;

    /**
     * \dref_RtpsReliableReaderProtocol_t_nack_period
     */
    RtpsReliableReaderProtocol& nack_period(
        const dds::core::Duration& the_nack_period);
    /**
     * @brief Getter (see setter with the same name)
     */
    dds::core::Duration nack_period() const;

    /**
     * \dref_RtpsReliableReaderProtocol_t_receive_window_size
     */
    RtpsReliableReaderProtocol& receive_window_size(
        int32_t the_receive_window_size);
    /**
     * @brief Getter (see setter with the same name)
     */
    int32_t receive_window_size() const;

    /**
     * \dref_RtpsReliableReaderProtocol_t_round_trip_time
     */
    RtpsReliableReaderProtocol& round_trip_time(
        const dds::core::Duration& the_round_trip_time);
    /**
     * @brief Getter (see setter with the same name)
     */
    dds::core::Duration round_trip_time() const;

    /**
     * \dref_RtpsReliableReaderProtocol_t_app_ack_period
     */
    RtpsReliableReaderProtocol& app_ack_period(
        const dds::core::Duration& the_app_ack_period);
    /**
     * @brief Getter (see setter with the same name)
     */
    dds::core::Duration app_ack_period() const;

    /**
     * \dref_RtpsReliableReaderProtocol_t_samples_per_app_ack
     */
    RtpsReliableReaderProtocol& samples_per_app_ack(
        int32_t the_samples_per_app_ack);
    /**
     * @brief Getter (see setter with the same name)
     */
    int32_t samples_per_app_ack() const;
};

class DataWriterShmemRefTransferModeSettings;

class DataWriterShmemRefTransferModeSettingsAdapter {
public:
    typedef struct DDS_DataWriterShmemRefTransferModeSettings native_type;

    static void initialize(native_type& native_value)
    {
        static const DDS_DataWriterShmemRefTransferModeSettings default_value =
            DDS_DataWriterShmemRefTransferModeSettings_INITIALIZER;
        native_value = default_value;
    }

    static void finalize(native_type&)
    {
        // nothing to do
    }

    static void copy(native_type& destination, const native_type& source)
    {
        destination = source;
    }

    static bool equals(const native_type& first, const native_type& second)
    {
        return DDS_DataWriterShmemRefTransferModeSettings_equals(
                &first,
                &second) == DDS_BOOLEAN_TRUE;
    }
};

template <>
struct native_type_traits<DataWriterShmemRefTransferModeSettings> {
    typedef DataWriterShmemRefTransferModeSettingsAdapter adapter_type;
    typedef DDS_DataWriterShmemRefTransferModeSettings native_type;
};

/**
 * @RTI_class_definition class DataWriterShmemRefTransferModeSettings
 *
 * @ingroup DDSDataWriterTransferModeQosModule
 * @headerfile rti/core/policy/CorePolicy.hpp
 *
 * @brief @extension Configures aspects of the shared
 * memory reference transfer mode related to a DataWriter
 *
 * @details \dref_details_DataWriterShmemRefTransferModeSettings
 */
class OMG_DDS_API DataWriterShmemRefTransferModeSettings :
    public NativeValueType<DataWriterShmemRefTransferModeSettings> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(
        DataWriterShmemRefTransferModeSettings)

    typedef NativeValueType<DataWriterShmemRefTransferModeSettings> Base;

public:
    /**
     * @brief Creates an instance with the default settings
     */
    DataWriterShmemRefTransferModeSettings() {}

    DataWriterShmemRefTransferModeSettings(
        const DDS_DataWriterShmemRefTransferModeSettings& native_value)
      : Base(native_value)
    {
    }

    DataWriterShmemRefTransferModeSettings(
            bool the_enable_data_consistency_check);

    /**
     * \dref_DataWriterShmemRefTransferModeSettings_enable_data_consistency_check
     */
    DataWriterShmemRefTransferModeSettings& enable_data_consistency_check(
        bool the_enable_data_consistency_check);
    /**
     * @brief Getter (see setter with the same name)
     */
    bool enable_data_consistency_check() const;

};

class DataReaderResourceLimitsInstanceReplacementSettingsAdapter
        : public PODNativeAdapter<DDS_DataReaderResourceLimitsInstanceReplacementSettings> {
public:
    static void initialize(native_type& native_value)
        {
            PODNativeAdapter<DDS_DataReaderResourceLimitsInstanceReplacementSettings>::initialize(native_value);

            static const DDS_DataReaderResourceLimitsInstanceReplacementSettings g_default =
                    DDS_DataReaderResourceLimitsInstanceReplacementSettings_DEFAULT;
            native_value = g_default;
        }
};

class DataReaderResourceLimitsInstanceReplacementSettings;

template <>
struct native_type_traits<DataReaderResourceLimitsInstanceReplacementSettings> {
    typedef rti::core::DataReaderResourceLimitsInstanceReplacementSettingsAdapter adapter_type;
    typedef DDS_DataReaderResourceLimitsInstanceReplacementSettings native_type;
};

/**
 * @RTI_class_definition class DataReaderResourceLimitsInstanceReplacementSettings
 * @ingroup DDSDataReaderResourceLimitsQosModule
 * @headerfile rti/core/PolicySettings.hpp
 *
 * @brief @extension How instances are replaced in the DataReader queue when
 * resource limits are reached.
 *
 * @details \dref_details_DataReaderResourceLimitsInstanceReplacementSettings
 */
class DataReaderResourceLimitsInstanceReplacementSettings : public NativeValueType<DataReaderResourceLimitsInstanceReplacementSettings> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(DataReaderResourceLimitsInstanceReplacementSettings)

    typedef NativeValueType<DataReaderResourceLimitsInstanceReplacementSettings> Base;
public:
    /**
     * @brief Creates an instance with the default removal kind for each
     * instance state: \idref_DataReaderInstanceRemovalKind_NO_INSTANCE_REMOVAL for alive instances
     * and \idref_DataReaderInstanceRemovalKind_EMPTY_INSTANCE_REMOVAL for no_writers
     * and dispose instances.
     */
    DataReaderResourceLimitsInstanceReplacementSettings()
    {
    }

    /**
     * @brief Creates an instance with the given \idref_DataReaderInstanceRemovalKind
     * for alive, disposed and no_writers instances, respectively.
     */
    DataReaderResourceLimitsInstanceReplacementSettings(
            rti::core::policy::DataReaderInstanceRemovalKind the_alive_instance_removal,
            rti::core::policy::DataReaderInstanceRemovalKind the_disposed_instance_removal,
            rti::core::policy::DataReaderInstanceRemovalKind the_no_writers_instance_removal);

    DataReaderResourceLimitsInstanceReplacementSettings(
            const DDS_DataReaderResourceLimitsInstanceReplacementSettings& native_replacement)
      : Base(native_replacement)
    {
    }

    /**
     * @brief Getter (see setter with the same name)
     */
    rti::core::policy::DataReaderInstanceRemovalKind alive_instance_removal() const;

    /**
     * @brief Sets the instance replacement policy for instances in
     * the \idref_InstanceStateKind_ALIVE_INSTANCE_STATE state
     *
     * @details \dref_details_DataReaderResourceLimitsInstanceReplacementSettings_alive_instance_removal
     */
    DataReaderResourceLimitsInstanceReplacementSettings& alive_instance_removal(
            rti::core::policy::DataReaderInstanceRemovalKind the_alive_instance_removal);

    /**
     * @brief Getter (see setter with the same name)
     */
    rti::core::policy::DataReaderInstanceRemovalKind disposed_instance_removal() const;

    /**
     * @brief Sets the instance replacement policy for instances in
     * the \idref_InstanceStateKind_NOT_ALIVE_DISPOSED_INSTANCE_STATE state
     * 
     * @details \dref_details_DataReaderResourceLimitsInstanceReplacementSettings_disposed_instance_removal
     */
    DataReaderResourceLimitsInstanceReplacementSettings& disposed_instance_removal(
            rti::core::policy::DataReaderInstanceRemovalKind the_disposed_instance_removal);

    /**
     * @brief Getter (see setter with the same name)
     */
    rti::core::policy::DataReaderInstanceRemovalKind no_writers_instance_removal() const;

    /**
     * @brief Sets the instance replacement policy for instances in
     * the \idref_InstanceStateKind_NOT_ALIVE_NO_WRITERS_INSTANCE_STATE state
     *
     * @details \dref_details_DataReaderResourceLimitsInstanceReplacementSettings_no_writers_instance_removal
     */
    DataReaderResourceLimitsInstanceReplacementSettings& no_writers_instance_removal(
            rti::core::policy::DataReaderInstanceRemovalKind the_no_writers_instance_removal);
};

typedef PODNativeAdapter<DDS_CompressionSettings_t> CompressionSettingsAdapter;

class CompressionSettings;
class CompressionIdMask;

template <>
struct native_type_traits<CompressionSettings> {
    typedef rti::core::CompressionSettingsAdapter adapter_type;
    typedef DDS_CompressionSettings_t native_type;
};

/**
 * @RTI_class_definition class CompressionIdMask
 * @ingroup DDSDataRepresentationQosModule
 * @headerfile rti/core/PolicySettings.hpp
 *
 * @brief @extension Mask that specifies which built-in compression method to
 * used.
 *
 * @details \dref_details_CompressionIdMask
 */
class CompressionIdMask : public std::bitset<16> {
public:
    /**
     * @brief The base type, std::bitset
     */
    typedef std::bitset<16> MaskType;

    CompressionIdMask()
    {
    }

    /**
     * @brief Creates a mask from the bits in an integer
     */
    explicit CompressionIdMask(uint64_t mask) : MaskType(mask)
    {
    }

    /**
     * @brief Creates a mask from a std::bitset
     */
    CompressionIdMask(const MaskType& mask) : MaskType(mask)
    {
    }

    /**
     * @brief All bits are set
     */
    static const CompressionIdMask all()
    {
        return CompressionIdMask(DDS_COMPRESSION_ID_MASK_ALL);
    }

    /**
     * @brief No bits are set
     */
    static const CompressionIdMask none()
    {
        return CompressionIdMask(DDS_COMPRESSION_ID_MASK_NONE);
    }

    /**
     * @brief Default mask value for publication.
     */
    static const CompressionIdMask default_publication()
    {
        return CompressionIdMask(DDS_COMPRESSION_ID_MASK_PUBLICATION_DEFAULT);
    }

    /**
     * @brief Default mask value for subscription.
     */
    static const CompressionIdMask default_subscription()
    {
        return CompressionIdMask(DDS_COMPRESSION_ID_MASK_SUBSCRIPTION_DEFAULT);
    }

    /**
     * @brief Selects the built-in ZLIB compression algorithm
     */
    static const CompressionIdMask zlib()
    {
        return CompressionIdMask(DDS_COMPRESSION_ID_ZLIB);
    }

    /**
     * @brief Selects the built-in BZIP2 compression algorithm
     */
    static const CompressionIdMask bzip2()
    {
        return CompressionIdMask(DDS_COMPRESSION_ID_BZIP2);
    }

    /**
     * @brief Selects the built-in LZ4 compression algorithm
     */
    static const CompressionIdMask lz4()
    {
        return CompressionIdMask(DDS_COMPRESSION_ID_LZ4);
    }
};

/**
 * @RTI_class_definition class CompressionSettings
 * @ingroup DDSDataRepresentationQosModule
 * @headerfile rti/core/PolicySettings.hpp
 *
 * @brief @extension Compression Settings
 *
 * @details \dref_details_CompressionSettings_t
 */
class CompressionSettings : public NativeValueType<CompressionSettings> {
public:
    RTI_NATIVE_VALUE_TYPE_DEFINE_DEFAULT_MOVE_OPERATIONS(CompressionSettings)

    typedef NativeValueType<CompressionSettings> Base;
public:

    /**
     * @brief Creates an instance with default, compression_ids,
     * writer_compression_level and writer_compression_threshold.
     */
    CompressionSettings()
    {
        static const DDS_CompressionSettings_t g_default =
                DDS_CompressionSettings_t_INITIALIZER;
        native() = g_default;
    }

    /**
     * @brief Creates an instance with the given compression_ids
     */
    explicit CompressionSettings(
            const rti::core::CompressionIdMask compression_ids)
    {
        this->compression_ids(compression_ids);
        writer_compression_level(
                CompressionSettings::compression_level_default());
        writer_compression_threshold(DDS_COMPRESSION_THRESHOLD_DEFAULT);
    }

    /**
     * @brief Creates an instance with the given compression_ids,
     * writer_compression_level and writer_compression_threshold.
     */
    CompressionSettings(
            const rti::core::CompressionIdMask compression_ids,
            const uint32_t writer_compression_level,
            const int32_t writer_compression_threshold)
    {
        this->compression_ids(compression_ids);
        this->writer_compression_level(writer_compression_level);
        this->writer_compression_threshold(writer_compression_threshold);
    }

    CompressionSettings(const DDS_CompressionSettings_t& native_settings) 
      : Base(native_settings)
    {
    }

    /**
     * @brief Return the default value for the compression level
     */
    static uint32_t compression_level_default()
    {
        return DDS_COMPRESSION_LEVEL_DEFAULT;
    }

    /**
     * @brief Get the compression level that can be used to achieve the best
     * compression ratio.
     */
    static uint32_t compression_level_best_compression()
    {
        return DDS_COMPRESSION_LEVEL_BEST_COMPRESSION;
    }

    /**
     * @brief Get the compression level that can be used to achieve the best
     * compression speed.
     */
    static uint32_t compression_level_best_speed()
    {
        return DDS_COMPRESSION_LEVEL_BEST_SPEED;
    }

    /**
     * @brief Getter for compression_ids
     */
    rti::core::CompressionIdMask compression_ids() const
    {
        return rti::core::CompressionIdMask(native().compression_ids);
    }

    /**
     * @brief Setter for compression_ids
     *
     * @details \dref_details_CompressionSettings_t_compression_ids
     */
    CompressionSettings compression_ids(
            rti::core::CompressionIdMask compression_ids)
    {
        native().compression_ids =
                static_cast<uint32_t>(compression_ids.to_ulong());
        return *this;
    }

    /**
     * @brief Getter for writer_compression_level
     */
    uint32_t writer_compression_level() const
    {
        return native().writer_compression_level;
    }

    /**
     * @brief Setter for writer_compression_level
     *
     * @details \dref_details_CompressionSettings_t_writer_compression_level
     */
    CompressionSettings writer_compression_level(
            uint32_t writer_compression_level)
    {
        native().writer_compression_level = writer_compression_level;
        return *this;
    }

    /**
     * @brief Getter for writer_compression_threshold
     */
    int32_t writer_compression_threshold() const
    {
        return native().writer_compression_threshold;
    }

    /**
     * @brief Setter for writer_compression_threshold
     *
     * @details \dref_details_CompressionSettings_t_writer_compression_threshold
     */
    CompressionSettings writer_compression_threshold(
            int32_t writer_compression_threshold)
    {
        native().writer_compression_threshold = writer_compression_threshold;
        return *this;
    }

};


} } // namespace rti::core

#endif // RTI_DDS_CORE_POLICY_SETTINGS_HPP_
