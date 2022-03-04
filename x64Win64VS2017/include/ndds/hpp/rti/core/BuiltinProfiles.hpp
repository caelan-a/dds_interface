/* $Id$

(c) Copyright, Real-Time Innovations, 2015-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef RTI_DDS_CORE_BUILTIN_PROFILES_HPP_
#define RTI_DDS_CORE_BUILTIN_PROFILES_HPP_

#include <string>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>


/**
 * @defgroup DDSBuiltinQosProfilesModule Builtin Qos Profiles
 *
 * @brief @extension QoS libraries and profiles that are automatically built into \ndds.
 *
 * @details \dref_details_BuiltinQosProfilesGroupDocs
 */

namespace rti { namespace core {

/**
 * @brief @extension Contains the names of the built-in profiles
 *
 * @see \idref_BuiltinQosProfilesGroupDocs
 */
namespace builtin_profiles {

/**
 * @brief @extension Contains the names of the built-in profiles in the regular
 * (non-experimental) qos library
 *
 * @see \idref_BuiltinQosProfilesGroupDocs
 */
namespace qos_lib {

/**
 * \dref_BUILTIN_QOS_LIB
 */
OMG_DDS_API std::string library_name();
/**
 * \dref_PROFILE_BASELINE
 */
OMG_DDS_API std::string baseline();
/**
 * \dref_PROFILE_BASELINE_5_0_0
 */
OMG_DDS_API std::string baseline_5_0_0();
/**
 * \dref_PROFILE_BASELINE_5_1_0
 */
OMG_DDS_API std::string baseline_5_1_0();
/**
 * \dref_PROFILE_BASELINE_5_2_0
 */
OMG_DDS_API std::string baseline_5_2_0();
/**
 * \dref_PROFILE_BASELINE_5_3_0
 */
OMG_DDS_API std::string baseline_5_3_0();
/**
 * \dref_PROFILE_BASELINE_6_0_0
 */
OMG_DDS_API std::string baseline_6_0_0();
/**
 * \dref_PROFILE_BASELINE_6_1_0
 */
OMG_DDS_API std::string baseline_6_1_0();
/**
 * \dref_PROFILE_GENERIC_COMMON
 */
OMG_DDS_API std::string generic_common();
/**
 * \dref_PROFILE_GENERIC_MONITORING_COMMON
 */
OMG_DDS_API std::string generic_monitoring_common();
/**
 * \dref_PROFILE_GENERIC_CONNEXT_MICRO_COMPATIBILITY
 */
OMG_DDS_API std::string generic_connext_micro_compatibility();
/**
 * \dref_PROFILE_GENERIC_CONNEXT_MICRO_COMPATIBILITY_2_4_9
 */
OMG_DDS_API std::string generic_connext_micro_compatibility_2_4_9();
/**
 * \dref_PROFILE_GENERIC_CONNEXT_MICRO_COMPATIBILITY_2_4_3
 */
OMG_DDS_API std::string generic_connext_micro_compatibility_2_4_3();
/**
 * \dref_PROFILE_GENERIC_OTHER_DDS_VENDOR_COMPATIBILITY
 */
OMG_DDS_API std::string generic_other_dds_vendor_compatibility();
/**
 * \dref_PROFILE_GENERIC_510_TRANSPORT_COMPATIBILITY
 */
OMG_DDS_API std::string generic_510_transport_compatibility();
/**
 * \dref_PROFILE_GENERIC_SECURITY
 */
OMG_DDS_API std::string generic_security();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE
 */
OMG_DDS_API std::string generic_strict_reliable();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE
 */
OMG_DDS_API std::string generic_keep_last_reliable();
/**
 * \dref_PROFILE_GENERIC_BEST_EFFORT
 */
OMG_DDS_API std::string generic_best_effort();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_HIGH_THROUGHPUT
 */
OMG_DDS_API std::string generic_strict_reliable_high_throughput();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LOW_LATENCY
 */
OMG_DDS_API std::string generic_strict_reliable_low_latency();
/**
 * \dref_PROFILE_GENERIC_PARTICIPANT_LARGE_DATA
 */
OMG_DDS_API std::string generic_participant_large_data();
/**
 * \dref_PROFILE_GENERIC_PARTICIPANT_LARGE_DATA_MONITORING
 */
OMG_DDS_API std::string generic_participant_large_data_monitoring();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA
 */
OMG_DDS_API std::string generic_strict_reliable_large_data();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA_FAST_FLOW
 */
OMG_DDS_API std::string generic_strict_reliable_large_data_fast_flow();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA_MEDIUM_FLOW
 */
OMG_DDS_API std::string generic_strict_reliable_large_data_medium_flow();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA_SLOW_FLOW
 */
OMG_DDS_API std::string generic_strict_reliable_large_data_slow_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA_FAST_FLOW
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data_fast_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA_MEDIUM_FLOW
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data_medium_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA_SLOW_FLOW
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data_slow_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_TRANSIENT_LOCAL
 */
OMG_DDS_API std::string generic_keep_last_reliable_transient_local();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_TRANSIENT
 */
OMG_DDS_API std::string generic_keep_last_reliable_transient();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_PERSISTENT
 */
OMG_DDS_API std::string generic_keep_last_reliable_persistent();
/**
 * \dref_PROFILE_GENERIC_AUTO_TUNING
 */
OMG_DDS_API std::string generic_auto_tuning();
/**
 * \dref_PROFILE_GENERIC_MINIMAL_MEMORY_FOOTPRINT
 */
OMG_DDS_API std::string generic_minimal_memory_footprint();
/**
 * \dref_PROFILE_PATTERN_PERIODIC_DATA
 */
OMG_DDS_API std::string pattern_periodic_data();
/**
 * \dref_PROFILE_PATTERN_STREAMING
 */
OMG_DDS_API std::string pattern_streaming();
/**
 * \dref_PROFILE_PATTERN_RELIABLE_STREAMING
 */
OMG_DDS_API std::string pattern_reliable_streaming();
/**
 * \dref_PROFILE_PATTERN_EVENT
 */
OMG_DDS_API std::string pattern_event();
/**
 * \dref_PROFILE_PATTERN_ALARM_EVENT
 */
OMG_DDS_API std::string pattern_alarm_event();
/**
 * \dref_PROFILE_PATTERN_STATUS
 */
OMG_DDS_API std::string pattern_status();
/**
 * \dref_PROFILE_PATTERN_ALARM_STATUS
 */
OMG_DDS_API std::string pattern_alarm_status();
/**
 * \dref_PROFILE_PATTERN_LAST_VALUE_CACHE
 */
OMG_DDS_API std::string pattern_last_value_cache();
} // namespace qos_lib

/**
 * @brief @extension @st_exp Contains the names of the built-in profiles
 * in the experimental qos library.
 *
 * This qos library is deprecated. These profiles have been moved to qos_lib.
 *
 * The library name is rti::core::builtin_profiles::qos_lib_exp::library_name()
 */
namespace qos_lib_exp {

/**
 * \dref_BUILTIN_QOS_LIB_EXP
 */
OMG_DDS_API std::string library_name();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE
 */
OMG_DDS_API std::string generic_strict_reliable();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE
 */
OMG_DDS_API std::string generic_keep_last_reliable();
/**
 * \dref_PROFILE_GENERIC_BEST_EFFORT
 */
OMG_DDS_API std::string generic_best_effort();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_HIGH_THROUGHPUT
 */
OMG_DDS_API std::string generic_strict_reliable_high_throughput();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LOW_LATENCY
 */
OMG_DDS_API std::string generic_strict_reliable_low_latency();
/**
 * \dref_PROFILE_GENERIC_PARTICIPANT_LARGE_DATA
 */
OMG_DDS_API std::string generic_participant_large_data();
/**
 * \dref_PROFILE_GENERIC_PARTICIPANT_LARGE_DATA_MONITORING
 */
OMG_DDS_API std::string generic_participant_large_data_monitoring();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA
 */
OMG_DDS_API std::string generic_strict_reliable_large_data();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA_FAST_FLOW
 */
OMG_DDS_API std::string generic_strict_reliable_large_data_fast_flow();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA_MEDIUM_FLOW
 */
OMG_DDS_API std::string generic_strict_reliable_large_data_medium_flow();
/**
 * \dref_PROFILE_GENERIC_STRICT_RELIABLE_LARGE_DATA_SLOW_FLOW
 */
OMG_DDS_API std::string generic_strict_reliable_large_data_slow_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA_FAST_FLOW
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data_fast_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA_MEDIUM_FLOW
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data_medium_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_LARGE_DATA_SLOW_FLOW
 */
OMG_DDS_API std::string generic_keep_last_reliable_large_data_slow_flow();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_TRANSIENT_LOCAL
 */
OMG_DDS_API std::string generic_keep_last_reliable_transient_local();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_TRANSIENT
 */
OMG_DDS_API std::string generic_keep_last_reliable_transient();
/**
 * \dref_PROFILE_GENERIC_KEEP_LAST_RELIABLE_PERSISTENT
 */
OMG_DDS_API std::string generic_keep_last_reliable_persistent();
/**
 * \dref_PROFILE_GENERIC_AUTO_TUNING
 */
OMG_DDS_API std::string generic_auto_tuning();
/**
 * \dref_PROFILE_GENERIC_MINIMAL_MEMORY_FOOTPRINT
 */
OMG_DDS_API std::string generic_minimal_memory_footprint();
/**
 * \dref_PROFILE_PATTERN_PERIODIC_DATA
 */
OMG_DDS_API std::string pattern_periodic_data();
/**
 * \dref_PROFILE_PATTERN_STREAMING
 */
OMG_DDS_API std::string pattern_streaming();
/**
 * \dref_PROFILE_PATTERN_RELIABLE_STREAMING
 */
OMG_DDS_API std::string pattern_reliable_streaming();
/**
 * \dref_PROFILE_PATTERN_EVENT
 */
OMG_DDS_API std::string pattern_event();
/**
 * \dref_PROFILE_PATTERN_ALARM_EVENT
 */
OMG_DDS_API std::string pattern_alarm_event();
/**
 * \dref_PROFILE_PATTERN_STATUS
 */
OMG_DDS_API std::string pattern_status();
/**
 * \dref_PROFILE_PATTERN_ALARM_STATUS
 */
OMG_DDS_API std::string pattern_alarm_status();
/**
 * \dref_PROFILE_PATTERN_LAST_VALUE_CACHE
 */
OMG_DDS_API std::string pattern_last_value_cache();

} // namespace qos_lib_exp

/**
 * @brief @extension Contains the names of the built-in QoS Snippets
 *
 * @see \idref_BuiltinQosProfilesGroupDocs
 */
namespace qos_snippet_lib {
/**
 * \dref_BUILTIN_QOS_SNIPPET_LIB
 */
OMG_DDS_API std::string library_name();

/**
 * \dref_SNIPPET_OPTIMIZATION_RELIABILITY_PROTOCOL_COMMON
 */
OMG_DDS_API std::string snippet_optimization_reliability_protocol_common();

/**
 * \dref_SNIPPET_OPTIMIZATION_RELIABILITY_PROTOCOL_KEEP_ALL
 */
OMG_DDS_API std::string snippet_optimization_reliability_protocol_keep_all();

/**
 * \dref_SNIPPET_OPTIMIZATION_RELIABILITY_PROTOCOL_KEEP_LAST
 */
OMG_DDS_API std::string snippet_optimization_reliability_protocol_keep_last();

/**
 * \dref_SNIPPET_OPTIMIZATION_RELIABILITY_PROTOCOL_HIGH_RATE
 */
OMG_DDS_API std::string snippet_optimization_reliability_protocol_high_rate();

/**
 * \dref_SNIPPET_OPTIMIZATION_RELIABILITY_PROTOCOL_LOW_LATENCY
 */
OMG_DDS_API std::string snippet_optimization_reliability_protocol_low_latency();

/**
 * \dref_SNIPPET_OPTIMIZATION_RELIABILITY_PROTOCOL_LARGE_DATA
 */
OMG_DDS_API std::string snippet_optimization_reliability_protocol_large_data();

/**
 * \dref_SNIPPET_OPTIMIZATION_DATACACHE_LARGE_DATA_DYNAMICMEMALLOC
 */
OMG_DDS_API std::string snippet_optimization_reliability_protocol_dynamicmemalloc();

/**
 * \dref_SNIPPET_OPTIMIZATION_DISCOVERY_COMMON
 */
OMG_DDS_API std::string snippet_optimization_discovery_common();

/**
 * \dref_SNIPPET_OPTIMIZATION_DISCOVERY_PARTICIPANT_COMPACT
 */
OMG_DDS_API std::string snippet_optimization_discovery_participant_compact();

/**
 * \dref_SNIPPET_OPTIMIZATION_DISCOVERY_ENDPOINT_FAST
 */
OMG_DDS_API std::string snippet_optimization_discovery_endpoint_fast();

/**
 * \dref_SNIPPET_OPTIMIZATION_TRANSPORT_LARGE_BUFFERS
 */
OMG_DDS_API std::string snippet_optimization_transport_large_buffers();

/**
 * \dref_SNIPPET_QOS_POLICY_RELIABILITY_RELIABLE
 */
OMG_DDS_API std::string snippet_qos_policy_reliability_reliable();

/**
 * \dref_SNIPPET_QOS_POLICY_RELIABILITY_BEST_EFFORT
 */
OMG_DDS_API std::string snippet_qos_policy_reliability_best_effort();

/**
 * \dref_SNIPPET_QOS_POLICY_HISTORY_KEEP_LAST_1
 */
OMG_DDS_API std::string snippet_qos_policy_history_keep_last_1();

/**
 * \dref_SNIPPET_QOS_POLICY_HISTORY_KEEP_ALL
 */
OMG_DDS_API std::string snippet_qos_policy_history_keep_all();

/**
 * \dref_SNIPPET_QOS_POLICY_PUBLISH_MODE_ASYNCHRONOUS
 */
OMG_DDS_API std::string snippet_qos_policy_publish_mode_asynchronous();

/**
 * \dref_SNIPPET_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL
 */
OMG_DDS_API std::string snippet_qos_policy_durability_transient_local();

/**
 * \dref_SNIPPET_QOS_POLICY_DURABILITY_TRANSIENT
 */
OMG_DDS_API std::string snippet_qos_policy_durability_transient();

/**
 * \dref_SNIPPET_QOS_POLICY_DURABILITY_PERSISTENT
 */
OMG_DDS_API std::string snippet_qos_policy_durability_persistent();

/**
 * \dref_SNIPPET_QOS_POLICY_BATCHING_ENABLE
 */
OMG_DDS_API std::string snippet_qos_policy_batching_enable();

/**
 * \dref_SNIPPET_FEATURE_FLOW_CONTROLLER_838MBPS
 */
OMG_DDS_API std::string snippet_qos_policy_flow_controller_838mbps();

/**
 * \dref_SNIPPET_FEATURE_FLOW_CONTROLLER_209MBPS
 */
OMG_DDS_API std::string snippet_qos_policy_flow_controller_209mbps();

/**
 * \dref_SNIPPET_FEATURE_FLOW_CONTROLLER_52MBPS
 */
OMG_DDS_API std::string snippet_qos_policy_flow_controller_52mbps();

/**
 * \dref_SNIPPET_FEATURE_AUTO_TUNING_ENABLE
 */
OMG_DDS_API std::string snippet_feature_auto_tuning_enable();

/**
 * \dref_SNIPPET_FEATURE_MONITORING_ENABLE
 */
OMG_DDS_API std::string snippet_feature_monitoring_enable();

/**
 * \dref_SNIPPET_FEATURE_SECURITY_ENABLE
 */
OMG_DDS_API std::string snippet_feature_security_enable();

/**
 * \dref_SNIPPET_FEATURE_TOPIC_QUERY_ENABLE
 */
OMG_DDS_API std::string snippet_feature_topic_query_enable();

/**
 * \dref_SNIPPET_TRANSPORT_TCP_LAN_CLIENT
 */
OMG_DDS_API std::string snippet_transport_tcp_lan_client();

/**
 * \dref_SNIPPET_TRANSPORT_TCP_WAN_SYMMETRIC_CLIENT
 */
OMG_DDS_API std::string snippet_transport_tcp_wan_symmetric_client();

/**
 * \dref_SNIPPET_TRANSPORT_TCP_WAN_ASYMMETRIC_SERVER
 */
OMG_DDS_API std::string snippet_transport_tcp_wan_asymmetric_server();

/**
 * \dref_SNIPPET_TRANSPORT_TCP_WAN_ASYMMETRIC_CLIENT
 */
OMG_DDS_API std::string snippet_transport_tcp_wan_asymmetric_client();

/**
 * \dref_SNIPPET_COMPATIBILITY_CONNEXT_MICRO_VERSION_2_4_3
 */
OMG_DDS_API std::string snippet_compatibility_connext_micro_version_2_4_3();

/**
 * \dref_SNIPPET_COMPATIBILITY_OTHER_DDS_VENDORS_ENABLE
 */
OMG_DDS_API std::string snippet_compatibility_other_dds_vendors_enable();

/**
 * \dref_SNIPPET_5_1_0_TRANSPORT_ENABLE
 */
OMG_DDS_API std::string snippet_compatibility_5_1_0_transport_enable();
} // namespace qos_snippet_lib

} } } // namespace rti::core::builtin_profiles

#endif // RTI_DDS_CORE_BUILTIN_PROFILES_HPP_
