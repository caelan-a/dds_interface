/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_builtin.h    generated by: makeheader    Fri Nov 15 12:22:54 2019
 *
 *		built from:	builtin.ifc
 */

#ifndef dds_c_builtin_h
#define dds_c_builtin_h


  #ifndef dds_c_infrastructure_h
    #include "dds_c/dds_c_infrastructure.h"
  #endif
  #ifndef dds_c_sequence_h
    #include "dds_c/dds_c_sequence.h"
  #endif
  #ifndef dds_c_data_h
    #include "dds_c/dds_c_data.h"
  #endif
  #include "dds_c/dds_c_typecode.h"    
  #include "dds_c/dds_c_typeobject.h"  
  #ifndef pres_typePlugin_h
    #include "pres/pres_typePlugin.h"
  #endif
  #ifndef dds_c_subscription_h
    #include "dds_c/dds_c_subscription.h"
  #endif
#ifdef __cplusplus
    extern "C" {
#endif


#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #pragma warning(push)
  #pragma warning(disable:4190)
#elif defined(RTI_DARWIN)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif


#define DDS_BUILTIN_TOPIC_MAX_STRING_LENGTH     (256)


DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_W_ERROR_CHECKING(DDS_ParticipantBuiltinTopicData);

typedef struct DDS_ParticipantBuiltinTopicData {

    /*e \dref_ParticipantBuiltinTopicData_key
     */
    DDS_BuiltinTopicKey_t key;

    /*e \dref_ParticipantBuiltinTopicData_user_data
     */
    struct DDS_UserDataQosPolicy user_data;

    /* --- Extensions: ---------------------------------------------------- */

    /*e \dref_ParticipantBuiltinTopicData_property
     */
    struct DDS_PropertyQosPolicy property;
     
    /*e \dref_ParticipantBuiltinTopicData_rtps_protocol_version
     */
    DDS_ProtocolVersion_t rtps_protocol_version;

    /*e \dref_ParticipantBuiltinTopicData_rtps_vendor_id
     */
    struct DDS_VendorId_t rtps_vendor_id;

    /*e \dref_ParticipantBuiltinTopicData_dds_builtin_endpoints
     */
    DDS_UnsignedLong dds_builtin_endpoints;

    /*i \dref_ParticipantBuiltinTopicData_metatraffic_unicast_locators
     * If making this field externally documented, add it to the print function
     */
    struct DDS_LocatorSeq metatraffic_unicast_locators;

    /*i \dref_ParticipantBuiltinTopicData_metatraffic_multicast_locators
     * If making this field externally documented, add it to the print function
     */
    struct DDS_LocatorSeq metatraffic_multicast_locators;

    /*e \dref_ParticipantBuiltinTopicData_default_unicast_locators
     */
    struct DDS_LocatorSeq default_unicast_locators;

    /*i \dref_ParticipantBuiltinTopicData_lease_duration
     * If making this field externally documented, add it to the print function
     */
    struct DDS_Duration_t lease_duration;

    /*e \dref_ParticipantBuiltinTopicData_product_version
     */
    struct DDS_ProductVersion_t product_version;

    /*i \dref_ParticipantBuiltinTopicData_plugin_promiscuity_kind
     * If making this field externally documented, add it to the print function
     */
    DDS_DiscoveryPluginPromiscuityKind plugin_promiscuity_kind;

    /*e \dref_ParticipantBuiltinTopicData_participant_name
     */
    struct DDS_EntityNameQosPolicy participant_name;
    
    /*e \dref_ParticipantBuiltinTopicData_domain_id
     */
    DDS_DomainId_t domain_id;

    /*e \dref_ParticipantBuiltinTopicData_transport_info
     */
    struct DDS_TransportInfoSeq transport_info;

    /*e \dref_ParticipantBuiltinTopicData_reachability_lease_duration
     */
    struct DDS_Duration_t reachability_lease_duration;

    /*i \dref_ParticipantBuiltinTopicData_vendor_builtin_endpoints
     */
    DDS_UnsignedLong vendor_builtin_endpoints;

    /*i \dref_ParticipantBuiltinTopicData_service
     */
    struct DDS_ServiceQosPolicy service;

#ifdef RTI_CPP
    DDS_ParticipantBuiltinTopicData() { }
    ~DDS_ParticipantBuiltinTopicData() {
    DDS_ParticipantBuiltinTopicData_finalize(this);
    }
    struct DDS_ParticipantBuiltinTopicData& operator=(
    const struct DDS_ParticipantBuiltinTopicData& from) {
        DDS_ParticipantBuiltinTopicData_copy(this, &from);
    return *this;
    }
#endif /* RTI_CPP */
} DDS_ParticipantBuiltinTopicData;


#define DDS_ParticipantBuiltinTopicData_INITIALIZER \
{ DDS_BuiltinTopicKey_t_INITIALIZER, DDS_USER_DATA_QOS_POLICY_DEFAULT, \
  DDS_PROPERTY_QOS_POLICY_DEFAULT, DDS_PROTOCOL_VERSION_DEFAULT, \
  DDS_VENDOR_ID_DEFAULT, 0, \
  DDS_SEQUENCE_INITIALIZER, \
  DDS_SEQUENCE_INITIALIZER, \
  DDS_SEQUENCE_INITIALIZER, \
  { 0x7fffffff, 0x7fffffff }, \
  DDS_PRODUCTVERSION_UNKNOWN, \
  DDS_DISCOVERYPLUGIN_DISCOVER_MATCHING_REMOTE_ENTITIES_PROMISCUITY,\
  DDS_ENTITY_NAME_QOS_POLICY_DEFAULT, \
  -1, \
  DDS_SEQUENCE_INITIALIZER, \
  DDS_DOMAIN_PARTICIPANT_LOCATOR_REACHABILTY_LEASE_DURATION_DEFAULT, \
  0, \
  DDS_SERVICE_QOS_POLICY_DEFAULT}


DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_W_ERROR_CHECKING(DDS_TopicBuiltinTopicData);

typedef struct DDS_TopicBuiltinTopicData {

    /*e \dref_TopicBuiltinTopicData_key
     */
    DDS_BuiltinTopicKey_t key;

    /*e \dref_TopicBuiltinTopicData_name
     */
    char* name;

    /*e \dref_TopicBuiltinTopicData_type_name
     */
    char* type_name;

    /*e \dref_TopicBuiltinTopicData_durability
     */
    struct DDS_DurabilityQosPolicy durability;

    /*e \dref_TopicBuiltinTopicData_durability_service
     */
    struct DDS_DurabilityServiceQosPolicy durability_service;

    /*e \dref_TopicBuiltinTopicData_deadline
     */
    struct DDS_DeadlineQosPolicy deadline;

    /*e \dref_TopicBuiltinTopicData_latency_budget
     */
    struct DDS_LatencyBudgetQosPolicy latency_budget;

    /*e \dref_TopicBuiltinTopicData_liveliness
     */
    struct DDS_LivelinessQosPolicy liveliness;

    /*e \dref_TopicBuiltinTopicData_reliability
     */
    struct DDS_ReliabilityQosPolicy reliability;

    /*e \dref_TopicBuiltinTopicData_transport_priority
     */
    struct DDS_TransportPriorityQosPolicy transport_priority;

    /*e \dref_TopicBuiltinTopicData_lifespan
     */
    struct DDS_LifespanQosPolicy lifespan;

    /*e \dref_TopicBuiltinTopicData_destination_order
     */
    struct DDS_DestinationOrderQosPolicy destination_order;

    /*e \dref_TopicBuiltinTopicData_history
     */
    struct DDS_HistoryQosPolicy history;

    /*e \dref_TopicBuiltinTopicData_resource_limits
     */
    struct DDS_ResourceLimitsQosPolicy resource_limits;

    /*e \dref_TopicBuiltinTopicData_ownership
     */
    struct DDS_OwnershipQosPolicy ownership;

    /*e \dref_TopicBuiltinTopicData_topic_data
     */
    struct DDS_TopicDataQosPolicy topic_data;

    /*e \dref_TopicBuiltinTopicData_representation
    */
    struct DDS_DataRepresentationQosPolicy representation;

#ifdef RTI_CPP
    DDS_TopicBuiltinTopicData() { 
        name = NULL; 
        type_name = NULL;
    }
    ~DDS_TopicBuiltinTopicData() {
    DDS_TopicBuiltinTopicData_finalize(this);
    }
    struct DDS_TopicBuiltinTopicData& operator=(
    const struct DDS_TopicBuiltinTopicData& from) {
        DDS_TopicBuiltinTopicData_copy(this, &from);
    return *this;
    }
#endif /* RTI_CPP */
} DDS_TopicBuiltinTopicData;


#define DDS_TopicBuiltinTopicData_INITIALIZER \
{ DDS_BuiltinTopicKey_t_INITIALIZER, NULL, NULL, \
  DDS_DURABILITY_QOS_POLICY_DEFAULT, \
  DDS_DURABILITY_SERVICE_QOS_POLICY_DEFAULT, \
  DDS_DEADLINE_QOS_POLICY_DEFAULT, \
  DDS_LATENCY_BUDGET_QOS_POLICY_DEFAULT, \
  DDS_LIVELINESS_QOS_POLICY_DEFAULT, \
  DDS_RELIABILITY_QOS_POLICY_DEFAULT, \
  DDS_TRANSPORT_PRIORITY_QOS_POLICY_DEFAULT, \
  DDS_LIFESPAN_QOS_POLICY_DEFAULT, \
  DDS_DESTINATION_ORDER_QOS_POLICY_DEFAULT, \
  DDS_HISTORY_QOS_POLICY_DEFAULT, \
  DDS_RESOURCE_LIMITS_QOS_POLICY_DEFAULT, \
  DDS_OWNERSHIP_QOS_POLICY_DEFAULT, \
  DDS_TOPIC_DATA_QOS_POLICY_DEFAULT, \
  DDS_DataRepresentationQosPolicy_INITIALIZER /* representation */\
}


DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_W_ERROR_CHECKING(DDS_PublicationBuiltinTopicData);

typedef struct DDS_PublicationBuiltinTopicData {

    /*e \dref_PublicationBuiltinTopicData_key
      */
    DDS_BuiltinTopicKey_t key;

    /*e \dref_PublicationBuiltinTopicData_participant_key
      */
    DDS_BuiltinTopicKey_t participant_key;

    /*e \dref_PublicationBuiltinTopicData_topic_name
     */
    char* topic_name;

    /*e \dref_PublicationBuiltinTopicData_type_name
     */
    char* type_name;

    /*i \dref_PublicationBuiltinTopicData_max_sample_serialized_size 
     * If making this field externally documented, add it to the print function
     */
    DDS_Long max_sample_serialized_size;

    /*e \dref_PublicationBuiltinTopicData_durability
     */
    struct DDS_DurabilityQosPolicy durability;

    /*e \dref_PublicationBuiltinTopicData_durability_service
     */
    struct DDS_DurabilityServiceQosPolicy durability_service;

    /*e \dref_PublicationBuiltinTopicData_deadline
     */
    struct DDS_DeadlineQosPolicy deadline;

    /*e \dref_PublicationBuiltinTopicData_latency_budget
     */
    struct DDS_LatencyBudgetQosPolicy latency_budget;

    /*e \dref_PublicationBuiltinTopicData_liveliness
     */
    struct DDS_LivelinessQosPolicy liveliness;

    /*e \dref_PublicationBuiltinTopicData_reliability
     */
    struct DDS_ReliabilityQosPolicy reliability;

    /*e \dref_PublicationBuiltinTopicData_lifespan
     */
    struct DDS_LifespanQosPolicy lifespan;

    /*e \dref_PublicationBuiltinTopicData_user_data
     */
    struct DDS_UserDataQosPolicy user_data;

    /*e \dref_PublicationBuiltinTopicData_ownership
     */
    struct DDS_OwnershipQosPolicy ownership;

    /*e \dref_PublicationBuiltinTopicData_ownership_strength
     */
    struct DDS_OwnershipStrengthQosPolicy ownership_strength;

    /*e \dref_PublicationBuiltinTopicData_destination_order
     */
    struct DDS_DestinationOrderQosPolicy destination_order;

    /*e \dref_PublicationBuiltinTopicData_presentation
     */
    struct DDS_PresentationQosPolicy presentation;

    /*e \dref_PublicationBuiltinTopicData_partition
     */
    struct DDS_PartitionQosPolicy partition;

    /*e \dref_PublicationBuiltinTopicData_topic_data
     */
    struct DDS_TopicDataQosPolicy topic_data;

    /*e \dref_PublicationBuiltinTopicData_group_data
     */
    struct DDS_GroupDataQosPolicy group_data;

    /*i \dref_PublicationBuiltinTopicData_type
    */
    DDS_TypeObject * type;

    /*e \dref_PublicationBuiltinTopicData_representation
    */
    struct DDS_DataRepresentationQosPolicy representation;

    /*e \dref_PublicationBuiltinTopicData_data_tags
     */
    DDS_DataTagQosPolicy data_tags;

    /* --- Extensions: ---------------------------------------------------- */
    
    /*e \dref_PublicationBuiltinTopicData_type_code
    */
    struct DDS_TypeCode * type_code;

    /*e \dref_PublicationBuiltinTopicData_publisher_key
      */
    DDS_BuiltinTopicKey_t publisher_key;

    /*e \dref_PublicationBuiltinTopicData_property
     */
    struct DDS_PropertyQosPolicy property;

    /*e \dref_PublicationBuiltinTopicData_unicast_locators
     */
    struct DDS_LocatorSeq unicast_locators;

    /*e \dref_PublicationBuiltinTopicData_virtual_guid
     */
    struct DDS_GUID_t virtual_guid;

    /*e \dref_PublicationBuiltinTopicData_service
     */
    struct DDS_ServiceQosPolicy service;

    /*e \dref_PublicationBuiltinTopicData_rtps_protocol_version
     */
    DDS_ProtocolVersion_t rtps_protocol_version;

    /*e \dref_PublicationBuiltinTopicData_rtps_vendor_id
     */
    struct DDS_VendorId_t rtps_vendor_id;

    /*e \dref_PublicationBuiltinTopicData_product_version
     */
    struct DDS_ProductVersion_t product_version;

    /*e \dref_PublicationBuiltinTopicData_locator_filter
     */
    struct DDS_LocatorFilterQosPolicy locator_filter;

    /*e \dref_PublicationBuiltinTopicData_disable_positive_acks
     */
    DDS_Boolean disable_positive_acks;

    /*i \dref_PublicationBuiltinTopicData_send_queue_size
     * If making this field externally documented, add it to the print function
     */
    DDS_Long send_queue_size;

    /*i \dref_PublicationBuiltinTopicData_is_incompatible
     * If making this field externally documented, add it to the print function
     */
    DDS_Boolean is_incompatible;

    /*e \dref_PublicationBuiltinTopicData_publication_name
     */
    struct DDS_EntityNameQosPolicy publication_name;

#ifdef RTI_CPP
    DDS_PublicationBuiltinTopicData() { 
        topic_name = NULL; 
        type_name = NULL; 
        type_code=NULL;
        type=NULL;
    }
    ~DDS_PublicationBuiltinTopicData() {
    DDS_PublicationBuiltinTopicData_finalize(this);
    }
    struct DDS_PublicationBuiltinTopicData& operator=(
    const struct DDS_PublicationBuiltinTopicData& from) {
        DDS_PublicationBuiltinTopicData_copy(this, &from);
    return *this;
    }
#endif /* RTI_CPP */
} DDS_PublicationBuiltinTopicData;


#define DDS_PublicationBuiltinTopicData_INITIALIZER \
{ DDS_BuiltinTopicKey_t_INITIALIZER, \
  DDS_BuiltinTopicKey_t_INITIALIZER, \
  NULL, NULL,0, \
  DDS_DURABILITY_QOS_POLICY_DEFAULT, \
  DDS_DURABILITY_SERVICE_QOS_POLICY_DEFAULT, \
  DDS_DEADLINE_QOS_POLICY_DEFAULT, \
  DDS_LATENCY_BUDGET_QOS_POLICY_DEFAULT, \
  DDS_LIVELINESS_QOS_POLICY_DEFAULT, \
  DDS_RELIABILITY_QOS_POLICY_DEFAULT, \
  DDS_LIFESPAN_QOS_POLICY_DEFAULT, \
  DDS_USER_DATA_QOS_POLICY_DEFAULT, \
  DDS_OWNERSHIP_QOS_POLICY_DEFAULT, \
  DDS_OWNERSHIP_STRENGTH_QOS_POLICY_DEFAULT, \
  DDS_DESTINATION_ORDER_QOS_POLICY_DEFAULT, \
  DDS_PRESENTATION_QOS_POLICY_DEFAULT, \
  DDS_PARTITION_QOS_POLICY_DEFAULT, \
  DDS_TOPIC_DATA_QOS_POLICY_DEFAULT, \
  DDS_GROUP_DATA_QOS_POLICY_DEFAULT,\
  NULL, /* type */\
  DDS_DataRepresentationQosPolicy_INITIALIZER, /* representation */\
  DDS_DATA_TAG_QOS_POLICY_DEFAULT, \
  NULL, /* type_code */\
  DDS_BuiltinTopicKey_t_INITIALIZER, \
  DDS_PROPERTY_QOS_POLICY_DEFAULT , \
  DDS_SEQUENCE_INITIALIZER,         \
  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}, \
  DDS_SERVICE_QOS_POLICY_DEFAULT, \
  DDS_PROTOCOL_VERSION_DEFAULT, \
  DDS_VENDOR_ID_DEFAULT, \
  DDS_PRODUCTVERSION_UNKNOWN, \
  DDS_LOCATOR_FILTER_QOS_POLICY_DEFAULT, \
  DDS_BOOLEAN_FALSE, \
  PRES_PS_PUBLICATION_PARAMETER_SEND_QUEUE_SIZE_DEFAULT, \
  DDS_BOOLEAN_FALSE, DDS_ENTITY_NAME_QOS_POLICY_DEFAULT \
}


DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_W_ERROR_CHECKING(DDS_SubscriptionBuiltinTopicData);

typedef struct DDS_SubscriptionBuiltinTopicData {

    /*e \dref_SubscriptionBuiltinTopicData_key
     */
    DDS_BuiltinTopicKey_t key;

    /*e \dref_SubscriptionBuiltinTopicData_participant_key
     */
    DDS_BuiltinTopicKey_t participant_key;

    /*e \dref_SubscriptionBuiltinTopicData_topic_name
     */
    char* topic_name;

    /*e \dref_SubscriptionBuiltinTopicData_type_name
     */
    char* type_name;

    /*e \dref_SubscriptionBuiltinTopicData_durability
     */
    struct DDS_DurabilityQosPolicy durability;

    /*e \dref_SubscriptionBuiltinTopicData_deadline
     */
    struct DDS_DeadlineQosPolicy deadline;

    /*e \dref_SubscriptionBuiltinTopicData_latency_budget
     */
    struct DDS_LatencyBudgetQosPolicy latency_budget;

    /*e \dref_SubscriptionBuiltinTopicData_liveliness
     */
    struct DDS_LivelinessQosPolicy liveliness;

    /*e \dref_SubscriptionBuiltinTopicData_reliability
     */
    struct DDS_ReliabilityQosPolicy reliability;

    /*e \dref_SubscriptionBuiltinTopicData_ownership
     */
    struct DDS_OwnershipQosPolicy ownership;

    /*e \dref_SubscriptionBuiltinTopicData_destination_order
     */
    struct DDS_DestinationOrderQosPolicy destination_order;

    /*e \dref_SubscriptionBuiltinTopicData_user_data
     */
    struct DDS_UserDataQosPolicy user_data;

    /*e \dref_SubscriptionBuiltinTopicData_time_based_filter
     */
    struct DDS_TimeBasedFilterQosPolicy time_based_filter;

    /*e \dref_SubscriptionBuiltinTopicData_presentation
     */
    struct DDS_PresentationQosPolicy presentation;

    /*e \dref_SubscriptionBuiltinTopicData_partition
     */
    struct DDS_PartitionQosPolicy partition;

    /*e \dref_SubscriptionBuiltinTopicData_topic_data
     */
    struct DDS_TopicDataQosPolicy topic_data;

    /*e \dref_SubscriptionBuiltinTopicData_group_data
     */
    struct DDS_GroupDataQosPolicy group_data;

    /*e \dref_SubscriptionBuiltinTopicData_type_consistency 
     */
    struct DDS_TypeConsistencyEnforcementQosPolicy type_consistency;

    /*i \dref_SubscriptionBuiltinTopicData_type
    */
    DDS_TypeObject * type;

    /*e \dref_SubscriptionBuiltinTopicData_representation
    */
    struct DDS_DataRepresentationQosPolicy representation;

    /*e \dref_SubscriptionBuiltinTopicData_data_tags
     */
    DDS_DataTagQosPolicy data_tags;

    /* --- Extensions: ---------------------------------------------------- */
    
    /*e \dref_SubscriptionBuiltinTopicData_type_code
    */
    struct DDS_TypeCode * type_code;

    /*e \dref_SubscriptionBuiltinTopicData_subscriber_key
     */
    DDS_BuiltinTopicKey_t subscriber_key;

    /*e \dref_SubscriptionBuiltinTopicData_property
     */
    struct DDS_PropertyQosPolicy property;
    
    /*e \dref_SubscriptionBuiltinTopicData_unicast_locators
     */
    struct DDS_LocatorSeq unicast_locators;

    /*e \dref_SubscriptionBuiltinTopicData_multicast_locators
     */
    struct DDS_LocatorSeq multicast_locators;

    /*e \dref_SubscriptionBuiltinTopicData_content_filter_property
     */
    struct DDS_ContentFilterProperty_t content_filter_property;

    /*e \dref_SubscriptionBuiltinTopicData_virtual_guid
     */
    struct DDS_GUID_t virtual_guid;

    /*e \dref_SubscriptionBuiltinTopicData_service 
     */
    struct DDS_ServiceQosPolicy service;

    /*e \dref_SubscriptionBuiltinTopicData_rtps_protocol_version
     */
    DDS_ProtocolVersion_t rtps_protocol_version;

    /*e \dref_SubscriptionBuiltinTopicData_rtps_vendor_id
     */
    struct DDS_VendorId_t rtps_vendor_id;

    /*e \dref_SubscriptionBuiltinTopicData_product_version
     */
    struct DDS_ProductVersion_t product_version;

    /*e \dref_SubscriptionBuiltinTopicData_disable_positive_acks
     */
    DDS_Boolean disable_positive_acks;

    /*i \dref_SubscriptionBuiltinTopicData_expects_inline_qos
     * If making this field externally documented, add it to the print function
     */
    DDS_Boolean expects_inline_qos;

    /*i \dref_SubscriptionBuiltinTopicData_receive_queue_size
     * If making this field externally documented, add it to the print function
     */
    DDS_Long receive_queue_size;

    /*i \dref_SubscriptionBuiltinTopicData_is_incompatible
     * If making this field externally documented, add it to the print function
     */
    DDS_Boolean is_incompatible;

    /*e \dref_SubscriptionBuiltinTopicData_subscription_name
     */
    struct DDS_EntityNameQosPolicy subscription_name;

#ifdef RTI_CPP
    DDS_SubscriptionBuiltinTopicData() { 
        topic_name = NULL; 
        type_name = NULL; 
        type_code=NULL;
        type=NULL;
    }
    ~DDS_SubscriptionBuiltinTopicData() {
    DDS_SubscriptionBuiltinTopicData_finalize(this);
    }
    struct DDS_SubscriptionBuiltinTopicData& operator=(
    const struct DDS_SubscriptionBuiltinTopicData& from) {
        DDS_SubscriptionBuiltinTopicData_copy(this, &from);
    return *this;
    }
#endif /* RTI_CPP */
} DDS_SubscriptionBuiltinTopicData;


#define DDS_SubscriptionBuiltinTopicData_INITIALIZER \
{ DDS_BuiltinTopicKey_t_INITIALIZER, \
  DDS_BuiltinTopicKey_t_INITIALIZER, \
  NULL, NULL, \
  DDS_DURABILITY_QOS_POLICY_DEFAULT, \
  DDS_DEADLINE_QOS_POLICY_DEFAULT, \
  DDS_LATENCY_BUDGET_QOS_POLICY_DEFAULT, \
  DDS_LIVELINESS_QOS_POLICY_DEFAULT, \
  DDS_RELIABILITY_QOS_POLICY_DEFAULT, \
  DDS_OWNERSHIP_QOS_POLICY_DEFAULT, \
  DDS_DESTINATION_ORDER_QOS_POLICY_DEFAULT, \
  DDS_USER_DATA_QOS_POLICY_DEFAULT, \
  DDS_TIME_BASED_FILTER_QOS_POLICY_DEFAULT, \
  DDS_PRESENTATION_QOS_POLICY_DEFAULT, \
  DDS_PARTITION_QOS_POLICY_DEFAULT, \
  DDS_TOPIC_DATA_QOS_POLICY_DEFAULT, \
  DDS_GROUP_DATA_QOS_POLICY_DEFAULT,\
  DDS_TYPE_CONSISTENCY_ENFORCEMENT_QOS_POLICY_DEFAULT, \
  NULL, /* type */ \
  DDS_DataRepresentationQosPolicy_INITIALIZER, /* representation */\
  DDS_DATA_TAG_QOS_POLICY_DEFAULT, \
  NULL, /* type_code */\
  DDS_BuiltinTopicKey_t_INITIALIZER, \
  DDS_PROPERTY_QOS_POLICY_DEFAULT, \
  DDS_SEQUENCE_INITIALIZER, \
  DDS_SEQUENCE_INITIALIZER, \
  DDS_CONTENT_FILTER_PROPERTY_DEFAULT, \
  {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}}, \
  DDS_SERVICE_QOS_POLICY_DEFAULT, \
  DDS_PROTOCOL_VERSION_DEFAULT, \
  DDS_VENDOR_ID_DEFAULT, \
  DDS_PRODUCTVERSION_UNKNOWN, \
  DDS_BOOLEAN_FALSE, \
  DDS_BOOLEAN_FALSE, \
  PRES_PS_SUBSCRIPTION_PARAMETER_RECV_QUEUE_SIZE_DEFAULT, \
  DDS_BOOLEAN_FALSE, DDS_ENTITY_NAME_QOS_POLICY_DEFAULT \
  }


#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_return_sample PRESTypePluginDefaultEndpointData_returnSample 
#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DDS_VirtualSubscriptionBuiltinTopicDataPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_W_ERROR_CHECKING(DDS_VirtualSubscriptionBuiltinTopicData);


typedef struct DDS_VirtualSubscriptionBuiltinTopicData {

    /*i \dref_VirtualSubscriptionBuiltinTopicData_key
     */
    DDS_BuiltinTopicKey_t  key;
	
    /*i \dref_VirtualSubscriptionBuiltinTopicData_topic_name
     */	
    char* topic_name;
	
    /*i \dref_VirtualSubscriptionBuiltinTopicData_name
     */	
    char* name;
	
    /*i \dref_VirtualSubscriptionBuiltinTopicData_quorum
     */	
    DDS_Long  quorum;

#ifdef RTI_CPP
    DDS_VirtualSubscriptionBuiltinTopicData() { }
    ~DDS_VirtualSubscriptionBuiltinTopicData() {
    DDS_VirtualSubscriptionBuiltinTopicData_finalize(this);
    }
    struct DDS_VirtualSubscriptionBuiltinTopicData& operator=(
    const struct DDS_VirtualSubscriptionBuiltinTopicData& from) {
        DDS_VirtualSubscriptionBuiltinTopicData_copy(this, &from);
    return *this;
    }
#endif /* RTI_CPP */	
} DDS_VirtualSubscriptionBuiltinTopicData;


#define DDS_VirtualSubscriptionBuiltinTopicData_INITIALIZER \
{ DDS_BuiltinTopicKey_t_INITIALIZER, \
  NULL, \
  NULL, \
  0}


#define DDS_ServiceRequestPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define DDS_ServiceRequestPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DDS_ServiceRequestPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define DDS_ServiceRequestPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
#define DDS_ServiceRequestPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define DDS_ServiceRequestPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DDS_ServiceRequestPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 


 extern DDSCDllVariable const DDS_Long DDS_UNKNOWN_SERVICE_REQUEST_ID;

 extern DDSCDllVariable const DDS_Long DDS_TOPIC_QUERY_SERVICE_REQUEST_ID;

 extern DDSCDllVariable const DDS_Long DDS_LOCATOR_REACHABILITY_SERVICE_REQUEST_ID;


DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_W_ERROR_CHECKING(DDS_ServiceRequest);

typedef struct DDS_ServiceRequest {

    /*e \dref_ServiceRequest_service_id
     */
    DDS_Long service_id;

    /*e \dref_ServiceRequest_instance_id
     */
    struct DDS_GUID_t instance_id;

    /*e \dref_ServiceRequest_request_body
     */
    struct DDS_OctetSeq request_body;

    DDSCPP_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT(DDS_ServiceRequest)

} DDS_ServiceRequest;

 extern DDSCDllVariable const struct DDS_ServiceRequest
DDS_SERVICE_REQUEST_DEFAULT;


#define DDS_ParticipantGenericMessagePlugin_get_sample PRESTypePluginDefaultEndpointData_getSample
#define DDS_ParticipantGenericMessagePlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer
#define DDS_ParticipantGenericMessagePlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DDS_ParticipantGenericMessagePlugin_get_key PRESTypePluginDefaultEndpointData_getKey
#define DDS_ParticipantGenericMessagePlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

#define DDS_ParticipantGenericMessagePlugin_create_sample PRESTypePluginDefaultEndpointData_createSample
#define DDS_ParticipantGenericMessagePlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample



DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT_W_ERROR_CHECKING(DDS_ParticipantGenericMessage);

typedef char *DDS_GenericMessageClassId;

typedef struct DDS_ParticipantGenericMessage {

    /*i \dref_ParticipantGenericMessage_message_identity
     */
    /* target for the request. Can be GUID_UNKNOWN */
    struct DDS_MessageIdentity message_identity;

    /*i \dref_ParticipantGenericMessage_related_message_identity
     */
    struct DDS_MessageIdentity related_message_identity;

    /*i \dref_ParticipantGenericMessage_destination_participant_key
     */
    DDS_GUID_t destination_participant_key;

    /*i \dref_ParticipantGenericMessage_destination_endpoint_key
     */
    DDS_GUID_t destination_endpoint_key;

    /*i \dref_ParticipantGenericMessage_source_endpoint_key
     */
    DDS_GUID_t source_endpoint_key;

    /*i \dref_ParticipantGenericMessage_message_class_id
     */
    DDS_GenericMessageClassId message_class_id;

    /*i \dref_ParticipantGenericMessage_message_data
     */
    struct DDS_DataHolderSeq message_data;

    DDSCPP_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT(DDS_ParticipantGenericMessage)

} DDS_ParticipantGenericMessage;

typedef DDS_ParticipantGenericMessage DDS_ParticipantStatelessMessage;

typedef DDS_ParticipantGenericMessage DDS_ParticipantVolatileSecureMessage;

 extern DDSCDllVariable const struct DDS_ParticipantGenericMessage
DDS_PARTICIPANT_GENERIC_MESSAGE_DEFAULT;


DDS_SEQUENCE(DDS_ParticipantBuiltinTopicDataSeq, struct DDS_ParticipantBuiltinTopicData);


DDS_TYPESUPPORT_C(DDS_ParticipantBuiltinTopicDataTypeSupport, struct DDS_ParticipantBuiltinTopicData);


DDS_DATAREADER_C(DDS_ParticipantBuiltinTopicDataDataReader, DDS_ParticipantBuiltinTopicDataSeq, struct DDS_ParticipantBuiltinTopicData);

 extern DDSCDllVariable const char *DDS_PARTICIPANT_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PARTICIPANT_TRUSTED_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PARTICIPANT_MESSAGE_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PARTICIPANT_MESSAGE_TRUSTED_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PARTICIPANT_PROXY_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PARTICIPANT_STATE_TOPIC_NAME;


DDS_SEQUENCE(DDS_TopicBuiltinTopicDataSeq, struct DDS_TopicBuiltinTopicData);


DDS_TYPESUPPORT_C(DDS_TopicBuiltinTopicDataTypeSupport, struct DDS_TopicBuiltinTopicData);


DDS_DATAREADER_C(DDS_TopicBuiltinTopicDataDataReader, DDS_TopicBuiltinTopicDataSeq, struct DDS_TopicBuiltinTopicData);

 extern DDSCDllVariable const char *DDS_TOPIC_TOPIC_NAME;


DDS_SEQUENCE(DDS_PublicationBuiltinTopicDataSeq, struct DDS_PublicationBuiltinTopicData);


DDS_TYPESUPPORT_C(DDS_PublicationBuiltinTopicDataTypeSupport, struct DDS_PublicationBuiltinTopicData);


DDS_DATAREADER_C(DDS_PublicationBuiltinTopicDataDataReader, DDS_PublicationBuiltinTopicDataSeq, struct DDS_PublicationBuiltinTopicData);

 extern DDSCDllVariable const char *DDS_PUBLICATION_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PUBLICATION_TRUSTED_TOPIC_NAME;


DDS_SEQUENCE(DDS_SubscriptionBuiltinTopicDataSeq, struct DDS_SubscriptionBuiltinTopicData);


DDS_TYPESUPPORT_C(DDS_SubscriptionBuiltinTopicDataTypeSupport, struct DDS_SubscriptionBuiltinTopicData);


DDS_DATAREADER_C(DDS_SubscriptionBuiltinTopicDataDataReader, DDS_SubscriptionBuiltinTopicDataSeq, struct DDS_SubscriptionBuiltinTopicData);

 extern DDSCDllVariable const char *DDS_SUBSCRIPTION_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_SUBSCRIPTION_TRUSTED_TOPIC_NAME;


DDS_SEQUENCE(DDS_VirtualSubscriptionBuiltinTopicDataSeq, struct DDS_VirtualSubscriptionBuiltinTopicData);


DDS_TYPESUPPORT_C(DDS_VirtualSubscriptionBuiltinTopicDataTypeSupport, struct DDS_VirtualSubscriptionBuiltinTopicData);


DDS_DATAREADER_C(DDS_VirtualSubscriptionBuiltinTopicDataDataReader, DDS_VirtualSubscriptionBuiltinTopicDataSeq, struct DDS_VirtualSubscriptionBuiltinTopicData);


DDS_DATAWRITER_C(DDS_VirtualSubscriptionBuiltinTopicDataDataWriter, struct DDS_VirtualSubscriptionBuiltinTopicData);

 extern DDSCDllVariable const char *DDS_VIRTUAL_SUBSCRIPTION_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_VirtualSubscriptionBuiltinTopicDataTYPENAME;


DDS_SEQUENCE(DDS_ServiceRequestSeq, struct DDS_ServiceRequest);


DDS_TYPESUPPORT_C(DDS_ServiceRequestTypeSupport, struct DDS_ServiceRequest);


DDS_DATAREADER_C(DDS_ServiceRequestDataReader, DDS_ServiceRequestSeq, struct DDS_ServiceRequest);


DDS_DATAWRITER_C(DDS_ServiceRequestDataWriter, struct DDS_ServiceRequest);

 extern DDSCDllVariable const char *DDS_SERVICE_REQUEST_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_SERVICE_REQUEST_TRUSTED_TOPIC_NAME;



#define DDSC_BUILTIN_PROPERTY_VALUE_SIZE (32)

/* Service Request Writer */
#define DDSC_BUILTIN_SERVICE_REQUEST_WRITER_PROPERTY_LENGTH (1)

#define DDSC_BUILTIN_SERVICE_REQUEST_WRITER_PROPERTY_SIZE \
    strlen(NDDS_DWHISTORY_MEMORYMANAGER_FASTPOOL_POOLBUFFERMAXSIZE) \
    + (DDSC_BUILTIN_SERVICE_REQUEST_WRITER_PROPERTY_LENGTH \
       * DDSC_BUILTIN_PROPERTY_VALUE_SIZE) \
    + DDSC_BUILTIN_SERVICE_REQUEST_WRITER_PROPERTY_LENGTH

/* Service Request Reader */
#define DDSC_BUILTIN_SERVICE_REQUEST_READER_PROPERTY_LENGTH (2)

#define DDSC_BUILTIN_SERVICE_REQUEST_READER_PROPERTY_SIZE \
    strlen(NDDS_DRHISTORY_MEMORYMANAGER_FASTPOOL_POOLBUFFERMAXSIZE) \
    + strlen(PRES_READER_ISOLATED_PROPERTY) \
    + (DDSC_BUILTIN_SERVICE_REQUEST_READER_PROPERTY_LENGTH \
        * DDSC_BUILTIN_PROPERTY_VALUE_SIZE) \
    + DDSC_BUILTIN_SERVICE_REQUEST_READER_PROPERTY_LENGTH


DDS_SEQUENCE(DDS_ParticipantGenericMessageSeq, struct DDS_ParticipantGenericMessage);


DDS_TYPESUPPORT_C(DDS_ParticipantGenericMessageTypeSupport, DDS_ParticipantGenericMessage);


DDS_DATAREADER_C(DDS_ParticipantGenericMessageDataReader, DDS_ParticipantGenericMessageSeq, DDS_ParticipantGenericMessage);


DDS_DATAWRITER_C(DDS_ParticipantGenericMessageDataWriter, DDS_ParticipantGenericMessage);

 extern DDSCDllVariable const char *DDS_PARTICIPANT_GENERIC_MESSAGE_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PARTICIPANT_STATELESS_MESSAGE_TOPIC_NAME;

 extern DDSCDllVariable const char *DDS_PARTICIPANT_TRUSTED_VOLATILE_MESSAGE_TOPIC_NAME;



/* Participant Stateless Reader */
#define DDSC_BUILTIN_PARTICIPANT_STATELESS_READER_PROPERTY_LENGTH (1)

#define DDSC_BUILTIN_PARTICIPANT_STATELESS_READER_PROPERTY_SIZE \
    + strlen(PRES_READER_COMPUTE_SAMPLE_HASH_PROPERTY) \
    + (DDSC_BUILTIN_PARTICIPANT_STATELESS_READER_PROPERTY_LENGTH \
    * DDSC_BUILTIN_PROPERTY_VALUE_SIZE) \
    + DDSC_BUILTIN_PARTICIPANT_STATELESS_READER_PROPERTY_LENGTH


struct DDS_ParticipantBuiltinTopicDataPool {
    struct PRESTypePluginPool *_parent;

    struct REDAFastBufferPool *_userDataPool;
    struct REDAFastBufferPool *_propertyPool;
    struct REDAFastBufferPool *_metatrafficUnicastLocatorsPool;
    struct REDAFastBufferPool *_metatrafficMulticastLocatorsPool;
    struct REDAFastBufferPool *_defaultUnicastLocatorsPool;
    struct REDAFastBufferPool *_participantNamePool;
    struct REDAFastBufferPool *_transportInfoPool;

    int _propertyListMaximumLength;
    int _propertyStringMaximumLength;
    int _userDataMaximumLength;
    int _transportInfoListMaximumLength;
    
    RTIBool _isPoolMode;
};

 
struct DDS_TopicBuiltinTopicDataPool {
    struct PRESTypePluginPool *_parent;

    struct REDAFastBufferPool *_topicDataPool;

    int _topicDataMaximumLength;
};


struct DDS_PublicationBuiltinTopicDataPool {
    struct PRESTypePluginPool *_parent;

    struct REDAFastBufferPool *_userDataPool;
    struct REDAFastBufferPool *_groupDataPool;
    struct REDAFastBufferPool *_topicDataPool;
    struct REDAFastBufferPool *_partitionStringPtrPool;
    struct REDAFastBufferPool *_partitionStringsPool;
    struct REDAFastBufferPool *_typeCodePool;
    RTICdrTypeObjectFactory *_typeObjectFactory;
    struct REDAFastBufferPool *_propertyPool;
    struct REDAFastBufferPool *_dataTagPool;
    struct REDAFastBufferPool *_typeSignaturePool;
    struct REDAFastBufferPool *_unicastLocatorsPool;
    struct REDAFastBufferPool *_locatorFilterPool;
    struct REDAFastBufferPool *_locatorFilterLocatorsPool;
    struct REDAFastBufferPool *_publicationNamePool;
    struct REDAFastBufferPool *_dataRepresentationPool;

    int _userDataMaximumLength;
    int _groupDataMaximumLength;
    int _topicDataMaximumLength;
    int _maxPartitions;
    int _partitionMaximumCumulativeLength;
    int _typeCodeMaximumSerializedLength;
    int _typeObjectMaximumSerializedLength;
    int _serializedTypeObjectDynamicAllocationThreshold;
    int _typeObjectMaximumDeserializedLength;
    int _deserializedTypeObjectDynamicAllocationThreshold;
    int _propertyListMaximumLength;
    int _propertyStringMaximumLength;
    int _dataTagListMaximumLength;
    int _dataTagStringMaximumLength;
    int _typeSignatureListMaximumLength;
    int _typeSignatureStringMaximumLength;
    int _locatorFilterSeqMaximumLength;
    int _locatorFilterExpMaximumLength;
    
    RTIBool _isPoolMode;
};


struct DDS_SubscriptionBuiltinTopicDataPool {
    struct PRESTypePluginPool *_parent;

    struct REDAFastBufferPool *_userDataPool;
    struct REDAFastBufferPool *_groupDataPool;
    struct REDAFastBufferPool *_topicDataPool;
    struct REDAFastBufferPool *_partitionStringPtrPool;
    struct REDAFastBufferPool *_partitionStringsPool;

    struct REDAFastBufferPool *_typeCodePool;
    RTICdrTypeObjectFactory *_typeObjectFactory;
    struct REDAFastBufferPool *_propertyPool;
    struct REDAFastBufferPool *_dataTagPool;
    struct REDAFastBufferPool *_typeSignaturePool;    
    struct REDAFastBufferPool *_unicastLocatorsPool;
    struct REDAFastBufferPool *_multicastLocatorsPool;

    struct REDAFastBufferPool *_contentFilterPropertyPool;
    struct REDAFastBufferPool *_expressionParametersPtrPool;

    struct REDAFastBufferPool *_subscriptionNamePool;
    struct REDAFastBufferPool *_dataRepresentationPool;

    int _propertyListMaximumLength;
    int _propertyStringMaximumLength;
    int _dataTagListMaximumLength;
    int _dataTagStringMaximumLength;
    int _typeSignatureListMaximumLength;
    int _typeSignatureStringMaximumLength;
    int _typeCodeMaximumSerializedLength;
    int _typeObjectMaximumSerializedLength;
    int _serializedTypeObjectDynamicAllocationThreshold;
    int _typeObjectMaximumDeserializedLength;
    int _deserializedTypeObjectDynamicAllocationThreshold;
    int _userDataMaximumLength;
    int _groupDataMaximumLength;
    int _topicDataMaximumLength;
    int _maxPartitions;
    int _partitionMaximumCumulativeLength;
    int _contentFilterPropertyMaximumSerializedLength;  
    
    RTIBool _isPoolMode;
};


#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  /* restore extern "C"-related warning */
  #pragma warning(pop)
#elif defined(RTI_DARWIN)
  #pragma clang diagnostic pop
#endif


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* dds_c_builtin_h */
