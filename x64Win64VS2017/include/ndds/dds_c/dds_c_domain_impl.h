/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_domain_impl.h    generated by: makeheader    Fri Apr 23 00:05:59 2021
 *
 *		built from:	domain_impl.ifc
 */

#ifndef dds_c_domain_impl_h
#define dds_c_domain_impl_h


  #ifndef dds_c_domain_h
    #include "dds_c/dds_c_domain.h"
  #endif
  #ifndef dds_c_topic_h
    #include "dds_c/dds_c_topic.h"
  #endif
  #ifndef dds_c_topic_impl_h
    #include "dds_c/dds_c_topic_impl.h"
  #endif
  #ifndef ddsc_factory_plugin_impl_h
    #include "dds_c/dds_c_factory_plugin_impl.h"
   #endif
  #ifndef dds_c_dll_h
    #include "dds_c/dds_c_dll.h"
  #endif
  #include "dds_c/dds_c_trust_plugins.h"

#ifdef __cplusplus
    extern "C" {
#endif

 extern DDSCDllVariable const int DDS_DATABASE_EXCLUSIVE_AREA_LEVEL;

 extern DDSCDllVariable const int DDS_BLOCKING_EXCLUSIVE_AREA_LEVEL;

 extern DDSCDllVariable const int DDS_REMOTE_EXCLUSIVE_AREA_LEVEL;

 extern DDSCDllVariable const int DDS_RECORD_EXCLUSIVE_AREA_LEVEL;


#define DDS_PUBLISHER_EXCLUSIVE_AREA_NAME "PUBLISHER_EA"

 extern DDSCDllVariable const int DDS_PUBLISHER_EXCLUSIVE_AREA_LEVEL;


#define DDS_SUBSCRIBER_EXCLUSIVE_AREA_NAME "SUBSCRIBER_EA"

 extern DDSCDllVariable const int DDS_SUBSCRIBER_EXCLUSIVE_AREA_LEVEL;

 extern DDSCDllVariable const int DDS_TABLE_EXCLUSIVE_AREA_LEVEL;

struct REDAWorkerFactory;

extern DDSCDllExport
struct REDAWorkerFactory *DDS_DomainParticipantGlobals_get_worker_factoryI(void);

typedef const char* (*DDS_DomainParticipantFactoryGetVersionStringFn)(
    void);

extern DDSCDllExport
struct REDAExclusiveArea * DDS_DomainParticipantFactory_create_EA(
        DDS_DomainParticipantFactory *self,
        int level,
        const char *name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipantFactory_destroy_EA(
        DDS_DomainParticipantFactory* self, struct REDAExclusiveArea* ea);

extern DDSCDllExport
struct REDAExclusiveArea * DDS_DomainParticipant_get_ref_counting_exclusive_area(
        DDS_DomainParticipant *self,
        int level,
        const char *name,
        DDS_Boolean forceUseSharedEa);

extern DDSCDllExport
void DDS_DomainParticipant_return_ref_counting_exclusive_area(
    DDS_DomainParticipant *self, struct REDAExclusiveArea* ea);

typedef void (*DDS_DomainParticipantFactoryThreadListenerOnStartedCallback)(
    void *onStartedParam,
    struct REDAWorker *worker);

typedef void (*DDS_DomainParticipantFactoryThreadListenerOnStoppedCallback)(
    void *onStoppedParam,
    struct REDAWorker *worker);

struct DDS_DomainParticipantFactoryThreadListenerI {
    DDS_DomainParticipantFactoryThreadListenerOnStartedCallback onStarted;
    void *onStartedParam;

    DDS_DomainParticipantFactoryThreadListenerOnStoppedCallback onStopped;
    void *onStoppedParam;
};


#define DDS_DomainParticipantFactoryThreadListenerI_INITIALIZER \
{ NULL, NULL, \
  NULL, NULL }

extern DDSCDllExport void
DDS_DomainParticipantFactory_set_thread_listenerI(
    DDS_DomainParticipantFactory* self,
    const struct DDS_DomainParticipantFactoryThreadListenerI *listener);

extern DDSCDllExport const struct DDS_DomainParticipantFactoryThreadListenerI *
DDS_DomainParticipantFactory_get_thread_listenerI(
    DDS_DomainParticipantFactory* self);

extern DDSCDllExport void 
DDS_DomainParticipantFactory_set_product_JMS(void);

extern DDSCDllExport DDS_Boolean
DDS_DomainParticipantFactory_is_globals_initializedI(
    DDS_DomainParticipantFactory* self);

extern DDSCDllExport
DDS_ReturnCode_t
DDS_DomainParticipantFactory_set_factory_plugin_supportI(
        DDS_DomainParticipantFactory* self,
        struct DDS_FactoryPluginSupport * factoryPluginSupport);

extern DDSCDllExport
DDS_ReturnCode_t
DDS_DomainParticipantFactory_set_factory_plugin_support_w_paramsI(
        DDS_DomainParticipantFactory* self,
        struct DDS_FactoryPluginSupport* factoryPluginSupport,
        DDS_Boolean supportsAutomaticUserTypeRegistration,
        DDS_Boolean useDefaultDynamicDataProxyTypeSupport);

extern DDSCDllExport
DDS_ReturnCode_t
DDS_DomainParticipantFactory_set_factory_plugin_service_qosI(
        DDS_DomainParticipantFactory* self,
        const struct DDS_ServiceQosPolicy serviceQos);

extern DDSCDllExport 
DDS_ReturnCode_t DDS_DomainParticipantFactory_register_type_supportI(
        DDS_DomainParticipantFactory * self,
        DDS_FactoryPluginUserTypeInfo typeSupport,
        const char * typeName);

extern DDSCDllExport DDS_DomainParticipant* 
DDS_DomainParticipantFactory_create_participant_disabledI(
        DDS_DomainParticipantFactory* self,
        DDS_Boolean *need_enable,
        DDS_DomainId_t domain_id,
        const struct DDS_DomainParticipantQos* qos, 
        const struct DDS_DomainParticipantListener* listener,
	DDS_StatusMask mask,
	struct RTIOsapiThreadFactory *db_thread_factory,
	struct RTIOsapiThreadFactory *recv_thread_factory,
	struct RTIOsapiThreadFactory *event_thread_factory,
	struct RTIOsapiThreadFactory *asynch_pub_thread_factory,
    DDS_Boolean _builtin_types,
	DDS_Boolean _sql_filter);

extern DDSCDllExport DDS_DomainParticipant*
DDS_DomainParticipantFactory_create_participant_disabled(
        DDS_DomainParticipantFactory *self,
        DDS_DomainId_t domain_id,
        const struct DDS_DomainParticipantQos *qos,
        const struct DDS_DomainParticipantListener *listener,
	DDS_StatusMask mask);

extern DDSCDllExport
DDS_DomainParticipantFactory* DDS_DomainParticipantFactory_newI(
    const char * version);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipantFactory_deleteI(DDS_DomainParticipantFactory* self);

extern DDSCDllExport DDS_Publisher*
DDS_DomainParticipant_create_publisher_disabledI(
    DDS_DomainParticipant* self,
    DDS_Boolean* need_enable,
    const struct DDS_PublisherQos* qos, 
    const struct DDS_PublisherListener* listener,
    DDS_StatusMask mask);

extern DDSCDllExport DDS_Subscriber*
DDS_DomainParticipant_create_subscriber_disabledI(
    DDS_DomainParticipant* self, DDS_Boolean* need_enable,
    const struct DDS_SubscriberQos* qos,
    const struct DDS_SubscriberListener* listener,
    DDS_StatusMask mask);

extern DDSCDllExport DDS_Topic* DDS_DomainParticipant_create_topic_disabledI(
    DDS_DomainParticipant* self, DDS_Boolean* need_enable,
    const char* topic_name, const char* type_name,
    const struct DDS_TopicQos* qos, const struct DDS_TopicListener* listener,
    DDS_StatusMask mask);

extern DDSCDllExport DDS_Subscriber*
DDS_DomainParticipant_get_builtin_subscriberI(
    DDS_DomainParticipant* self, DDS_Boolean* is_newly_created,
    DDS_Boolean* need_enable,
    DDS_Boolean create_builtin,
    PRESGroupSuffix suffix);

extern DDSCDllExport DDS_Publisher* 
DDS_DomainParticipant_get_builtin_publisherI(
    DDS_DomainParticipant* self, 
    DDS_Boolean* is_newly_created,
    DDS_Boolean* need_enable,
    DDS_Boolean create_builtin);

extern DDSCDllExport DDS_TopicDescription*
DDS_DomainParticipant_lookup_topicdescriptionI(
    DDS_DomainParticipant* self, DDS_Boolean* is_newly_created,
    DDS_Boolean* need_enable,
    DDS_Boolean create_builtin, const char* topic_name);

extern DDSCDllExport RTIBool
DDS_DomainParticipant_is_type_registered(
    DDS_DomainParticipant *self,
    const char* type_name);

extern DDSCDllExport
DDS_FlowController *DDS_DomainParticipant_create_flowcontrollerI(
    DDS_DomainParticipant* self, const char *name,
    RTIBool explicitDestroyOnly,
    const struct DDS_FlowControllerProperty_t *property);

extern DDSCDllExport DDS_ReturnCode_t DDS_DomainParticipant_disableI(
    DDS_DomainParticipant* ddsParticipant);

typedef enum {
    DDS_GROUP_PUBLISHER_I,
    DDS_GROUP_SUBSCRIBER_I
} DDS_GroupKindI;

extern DDSCDllExport DDS_ReturnCode_t DDS_DomainParticipant_lock_all_groupsI(
    DDS_DomainParticipant* ddsParticipant,
    DDS_GroupKindI groupKind);

extern DDSCDllExport DDS_ReturnCode_t DDS_DomainParticipant_unlock_all_groupsI(
    DDS_DomainParticipant* ddsParticipant,
    DDS_GroupKindI groupKind);

extern DDSCDllExport int DDS_DomainParticipant_get_user_group_countI(
    DDS_DomainParticipant* ddsParticipant,
    DDS_GroupKindI groupKind);

extern DDSCDllExport void
DDS_DomainParticipant_start_database_interactive_shellI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_participant_user_data_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_transport_info_list_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_publisher_group_data_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_subscriber_group_data_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_reader_user_data_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_writer_user_data_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_topic_data_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_max_partitionsI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_max_partition_cumulative_charactersI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_channel_seq_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_channel_filter_expression_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_participant_property_list_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_participant_property_string_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_writer_property_list_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_writer_property_string_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_reader_property_list_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_reader_property_string_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_type_signature_list_max_lengthI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Long
DDS_DomainParticipant_get_type_signature_string_max_lengthI(
    DDS_DomainParticipant* self);

struct PRESParticipant;

extern DDSCDllExport 
struct PRESParticipant* DDS_DomainParticipant_get_presentation_participantI(
    DDS_DomainParticipant *self);

struct RTINetioConfigurator;

extern DDSCDllExport 
struct RTINetioConfigurator *DDS_DomainParticipant_get_netio_configuratorI(
    DDS_DomainParticipant *self);

struct RTIEventActiveDatabase;

extern DDSCDllExport 
struct RTIEventActiveDatabase *DDS_DomainParticipant_get_active_databaseI(
    DDS_DomainParticipant *self);

struct DISCPluginManager;

extern DDSCDllExport 
struct DISCPluginManager *DDS_DomainParticipant_get_discovery_plugin_managerI(
    DDS_DomainParticipant* self);

extern DDSCDllExport 
PRESServiceId DDS_DomainParticipant_get_serviceIdI(
    DDS_DomainParticipant* self);

struct REDAWorker;

extern DDSCDllExport struct REDAWorker* DDS_DomainParticipant_get_workerI(
    DDS_DomainParticipant* self);

extern DDSCDllExport
struct REDAWorker * DDS_DomainParticipant_create_worker_with_nameI(
        DDS_DomainParticipant *self,
        const char *name);

struct REDAWorker;

extern DDSCDllExport struct REDAWorker*
DDS_DomainParticipantFactory_get_workerI(DDS_DomainParticipantFactory * self);

extern DDSCDllExport
struct REDAWorkerFactory* DDS_DomainParticipantFactory_get_worker_factoryI(
    DDS_DomainParticipantFactory * self, RTIBool* alreadyCreated);

extern DDSCDllExport
RTIOsapiThreadTssFactory * DDS_DomainParticipantFactory_get_tss_factoryI(
    DDS_DomainParticipantFactory * self);

extern DDSCDllExport
struct DDS_XMLObject * DDS_DomainParticipantFactory_get_xml_rootI(
    DDS_DomainParticipantFactory * self);

struct DDS_DomainParticipantNode {
    struct REDAInlineListNode _node;
    DDS_DomainParticipant *_participant;
    DDS_DomainId_t _domainId;
};

extern DDSCDllExport 
DDS_DataWriter *DDS_DomainParticipant_get_builtin_datawriterI(
        DDS_DomainParticipant *self, 
        const char *topic_name, 
        RTIBool isSecure);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipant_get_topic_data_protection_kindI(
        DDS_DomainParticipant *self,
        DDS_ProtectionKind *protection_kind,
        const char *topic_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipant_get_default_builtin_datareader_qosI(
        DDS_DomainParticipant* self, struct DDS_DataReaderQos* qos,
        const char *topicName);

struct REDAWorker;

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeTopicFinalizeFnc)(
    void* topicFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeContentFilteredTopicFinalizeFnc)(
    void* contentFilteredTopicFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeFlowControllerFinalizeFnc)(
    void* flowControllerFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforePublisherFinalizeFnc)(
    void* publisherFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeSubscriberFinalizeFnc)(
    void* subscriberFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeDataReaderFinalizeFnc)(
    void* dataReaderFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeDataWriterFinalizeFnc)(
    void* dataWriterFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeReadConditionFinalizeFnc)(
    void* readConditionFinalizeParam,
    void* userObject, struct REDAWorker *worker);

typedef void
(*DDS_DomainParticipantFactoryFinalizeListenerOnBeforeTopicQueryFinalizeFnc)(
    void* topicQueryFinalizeParam,
    void* userObject, struct REDAWorker *worker);

struct DDS_DomainParticipantFactoryFinalizeListenerI {
    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeTopicFinalizeFnc
        onBeforeTopicFinalizeFnc;
    void* topicFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeContentFilteredTopicFinalizeFnc
        onBeforeContentFilteredTopicFinalizeFnc;
    void* contentFilteredTopicFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeFlowControllerFinalizeFnc
        onBeforeFlowControllerFinalizeFnc;
    void* flowControllerFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforePublisherFinalizeFnc
        onBeforePublisherFinalizeFnc;
    void* publisherFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeSubscriberFinalizeFnc
        onBeforeSubscriberFinalizeFnc;
    void* subscriberFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeDataReaderFinalizeFnc
        onBeforeDataReaderFinalizeFnc;
    void* dataReaderFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeDataWriterFinalizeFnc
        onBeforeDataWriterFinalizeFnc;
    void* dataWriterFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeReadConditionFinalizeFnc
        onBeforeReadConditionFinalizeFnc;
    void* readConditionFinalizeParam;

    DDS_DomainParticipantFactoryFinalizeListenerOnBeforeTopicQueryFinalizeFnc
        onBeforeTopicQueryFinalizeFnc;
    void* topicQueryFinalizeParam;
};


#define DDS_DomainParticipantFactoryFinalizeListenerI_INITIALIZER \
{ NULL, NULL, \
  NULL, NULL, \
  NULL, NULL, \
  NULL, NULL, \
  NULL, NULL, \
  NULL, NULL, \
  NULL, NULL, \
  NULL, NULL, \
  NULL, NULL }

extern DDSCDllExport const struct DDS_DomainParticipantFactoryFinalizeListenerI*
DDS_DomainParticipantFactory_get_finalize_listenerI(
    DDS_DomainParticipantFactory* self);

extern DDSCDllExport void
DDS_DomainParticipantFactory_set_finalize_listenerI(
    DDS_DomainParticipantFactory* self,
    const struct DDS_DomainParticipantFactoryFinalizeListenerI *listener);

typedef void
(*DDS_SampleInfoListenerInitializeUserObjectFnc)(
    void** userObject, void* initializeParam);

typedef void
(*DDS_SampleInfoListenerFinalizeUserObjectFnc)(
    void** userObject, void* finalizeParam);

struct DDS_SampleInfoListenerI {
    DDS_SampleInfoListenerInitializeUserObjectFnc userObjectInitializeFnc;
    void* userObjectInitializeParam;

    DDS_SampleInfoListenerFinalizeUserObjectFnc userObjectFinalizeFnc;
    void* userObjectFinalizeParam;
};


#define DDS_SampleInfoListenerI_INITIALIZER \
{ NULL, NULL, \
  NULL, NULL }

extern DDSCDllExport
const struct DDS_SampleInfoListenerI*
DDS_DomainParticipantFactory_get_sampleinfo_listenerI(
    DDS_DomainParticipantFactory* self);

extern DDSCDllExport void
DDS_DomainParticipantFactory_set_sampleinfo_listenerI(
    DDS_DomainParticipantFactory* self,
    const struct DDS_SampleInfoListenerI *listener);

extern DDSCDllExport DDS_ReturnCode_t
DDS_DomainParticipant_register_contentfilterI(
    DDS_DomainParticipant* self,
    const char *name,
    const struct DDS_ContentFilter *contentFilter,
    const DDS_ContentFilterEvaluateFunction evaluateOnSerialized,
    const DDS_ContentFilterWriterEvaluateFunction writerEvaluateOnSerialized,
    const DDS_ContentFilterQueryFunction query,
    DDS_Boolean isBuiltin);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipantQos_get_defaultI(
    struct DDS_DomainParticipantQos* self);

extern DDSCDllExport
void DDS_DomainParticipantFactoryQos_get_defaultI(
    struct DDS_DomainParticipantFactoryQos* self);


struct DDS_DomainParticipantRemoteEndpointConfigListenerI {
    struct PRESRemoteEndpointConfigListener presListener;
    struct MIGRtpsGuid participant_guid;
    void*  listener_data;
};

extern DDSCDllExport void
DDS_DomainParticipantFactory_set_remote_endpoint_config_listenerI(
    DDS_DomainParticipantFactory* self,
    const struct PRESRemoteEndpointConfigListener *listener);

extern DDSCDllExport void
DDS_DomainParticipant_set_remote_endpoint_config_listener_user_dataI(
    DDS_DomainParticipant* self,
    void *listener_data);

extern DDSCDllExport
const void*
DDS_DomainParticipant_get_remote_endpoint_config_listener_user_dataI(
    DDS_DomainParticipant* self);

extern DDSCDllExport DDS_Publisher*
DDS_DomainParticipant_get_implicit_publisherI(
    DDS_DomainParticipant* self, DDS_Boolean* is_newly_created,
    DDS_Boolean* need_enable, DDS_Boolean create_default);

extern DDSCDllExport DDS_Subscriber*
DDS_DomainParticipant_get_implicit_subscriberI(
    DDS_DomainParticipant* self, DDS_Boolean* is_newly_created,
    DDS_Boolean* need_enable, DDS_Boolean create_default);

extern DDSCDllExport DDS_Boolean
DDS_DomainParticipant_is_implicit_publisherI(
    DDS_DomainParticipant* self, DDS_Publisher* publisher);

extern DDSCDllExport DDS_Boolean
DDS_DomainParticipant_is_implicit_subscriberI(
    DDS_DomainParticipant* self, DDS_Subscriber* subscriber);

extern DDS_Topic* 
DDS_DomainParticipant_check_create_and_enable_topic_if_no_existI(
    DDS_DomainParticipant* self, const char* topic_name, const char* type_name);

extern DDSCDllExport DDS_Topic* 
DDS_DomainParticipant_check_and_create_topic_if_no_existI(
        DDS_DomainParticipant* self, DDS_Boolean* is_newly_created,
        DDS_Boolean* need_enable,
        const char* topic_name, const char* type_name);

extern DDSCDllExport void
DDS_DomainParticipant_set_implicit_entities_nullI(
    DDS_DomainParticipant* ddsParticipant);

extern DDSCDllExport DDS_DomainParticipantFactory * 
DDS_DomainParticipant_get_participant_factoryI(
    DDS_DomainParticipant* self);

extern DDSCDllExport
int DDS_DomainParticipant_get_type_object_countI(
    DDS_DomainParticipant * self);

extern DDSCDllExport DDS_ReturnCode_t DDS_DomainParticipant_set_listenerI(
    DDS_DomainParticipant* self,
    const struct DDS_DomainParticipantListener* l,
    DDS_StatusMask mask,
    RTIBool logWarnEnable);

extern DDSCDllExport DDS_ReturnCode_t 
DDS_DomainParticipant_delete_non_user_entities(DDS_DomainParticipant* self);

extern DDSCDllExport DDS_DataReader* 
DDS_DomainParticipant_lookup_builtin_service_request_readerI(
    DDS_DomainParticipant* self, int requested_services);

extern DDSCDllExport
int DDS_DomainParticipant_get_max_private_signature_sizeI(
        DDS_DomainParticipant *self);

extern DDSCDllExport
DDS_Boolean DDS_DomainParticipant_private_signI(
        DDS_DomainParticipant *self,
        struct DDS_Buffer *signature,
        const struct DDS_Buffer *data_to_sign);

extern DDSCDllExport
DDS_Boolean DDS_DomainParticipant_verify_remote_participant_signed_dataI(
        DDS_DomainParticipant *self,
        const struct DDS_GUID_t *remote_participant_guid,
        const struct DDS_Buffer *signed_data,
        const struct DDS_Buffer *signature);

extern DDSCDllExport
DDS_Boolean DDS_DomainParticipant_is_fully_enabledI(DDS_Entity *self);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipant_get_unicast_locators_from_peer_descriptorI(
        DDS_DomainParticipant *self,
        struct DDS_LocatorSeq *locator_seq,
        const char *peer_desc_string);


/* builtin entities */
#define DDS_DOMAIN_PARTICIPANT_AUTOENABLE_BUILTIN_ENTITIES_PROPERTY_NAME \
    PROPERTY_NAME_DDS_DOMAIN_PARTICIPANT_AUTO_ENABLE_BUILTIN_ENTITIES

#define DDS_DOMAIN_PARTICIPANT_AUTOENABLE_LIVELINESS_PROPERTY_NAME \
    PROPERTY_NAME_DDS_DOMAIN_PARTICIPANT_AUTO_ENABLE_LIVELINESS


struct DDS_QosProvider;


typedef struct DDS_QosProvider DDS_QosProvider;


struct DDS_DomainParticipantFactoryQosXMLInfo {
    RTIBool isEntityFactoryTagPresent;
    RTIBool isLoggingTagPresent;
};

extern DDSCDllExport
DDS_QosProvider * DDS_QosProvider_new(
    const struct DDS_ProfileQosPolicy * profile_policy);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_load_profilesI(
    DDS_QosProvider * self, RTIBool reload);


struct DDS_XMLParser;

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_load_builtin_profilesI(
    struct DDS_XMLParser *parser, struct DDS_XMLObject ** root);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_finalize_profilesI(
    DDS_QosProvider * self);

extern DDSCDllExport
RTIBool DDS_QosProvider_are_profiles_loaded(DDS_QosProvider *self);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_set_default_library(
    DDS_QosProvider * self, const char * library);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_set_default_profile(
    DDS_QosProvider *self, const char * library_name, const char * profile_name);

/*ci @ingroup DDSDomainParticipantFactoryModule
 *
 * @brief gets the default profile used by the DomainParticipantFactory
 * 
 */
extern DDSCDllExport
const char * DDS_QosProvider_get_default_profile(
   DDS_QosProvider *self);

extern DDSCDllExport
const char * DDS_QosProvider_get_default_profile_library(
   DDS_QosProvider *self);

extern DDSCDllExport
const char * DDS_QosProvider_get_default_library(
   DDS_QosProvider *self);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_qos_profile_libraries(
    DDS_QosProvider * self,
    struct DDS_StringSeq * library_names);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_qos_profiles(
    DDS_QosProvider *self,
    struct DDS_StringSeq* profile_names,
    const char* library_name);

extern DDSCDllExport
const struct DDS_XMLObject * DDS_QosProvider_get_default_qos_profileI(
    DDS_QosProvider* self);

extern DDSCDllExport
void DDS_QosProvider_get_profile_qos(
   DDS_QosProvider * self, 
   struct DDS_ProfileQosPolicy * profileQosPolicy);

extern DDSCDllExport
void DDS_QosProvider_set_profile_qos(
    DDS_QosProvider * self,
    const struct DDS_ProfileQosPolicy * profileQosPolicy);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_load_profiles_from_url_listI(
    DDS_QosProvider *self,
    const char * urlList);

extern DDSCDllExport
void DDS_QosProvider_delete(DDS_QosProvider * self);

extern DDSCDllExport
const struct DDS_DomainParticipantFactoryQos *
DDS_QosProvider_get_default_participant_factory_qos(DDS_QosProvider * self,
                                                    struct DDS_DomainParticipantFactoryQosXMLInfo * factory_qos_xml_info);

extern DDSCDllExport
const struct DDS_DomainParticipantQos *
DDS_QosProvider_get_default_participant_qos(DDS_QosProvider * self);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_participant_factory_qos_from_profile(
    DDS_QosProvider *self,
    struct DDS_DomainParticipantFactoryQos *qos,
    const char *library_name,
    const char *profile_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_participant_qos_from_profile(
    DDS_QosProvider *self,
    struct DDS_DomainParticipantQos *qos,
    const char *library_name,
    const char *profile_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_publisher_qos_from_profile(
    DDS_QosProvider *self,
    struct DDS_PublisherQos *qos,
    const char *library_name,
    const char *profile_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_subscriber_qos_from_profile(
    DDS_QosProvider *self,
    struct DDS_SubscriberQos *qos,
    const char *library_name,
    const char *profile_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_datareader_qos_from_profile(
    DDS_QosProvider *self,
    struct DDS_DataReaderQos *qos,
    const char *library_name,
    const char *profile_name,
    const char *topic_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_datawriter_qos_from_profile(
    DDS_QosProvider *self,
    struct DDS_DataWriterQos *qos,
    const char *library_name,
    const char *profile_name,
    const char *topic_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_topic_qos_from_profile(
    DDS_QosProvider *self,
    struct DDS_TopicQos *qos,
    const char *library_name,
    const char *profile_name,
    const char *topic_name);

extern DDSCDllExport
struct DDS_XMLParser * DDS_QosProvider_get_xml_parser(DDS_QosProvider *self);

extern DDSCDllExport
struct DDS_XMLObject * DDS_QosProvider_get_xml_root(DDS_QosProvider *self);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_load_xml_element(
    DDS_QosProvider * self,
    const char ** xml_element_full_name,
    const char * xml_parent_full_name,
    const char * xml_element_str);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_unload_xml_element(
    DDS_QosProvider * self,
    const char * xml_element_full_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_save_xml_element(
    DDS_QosProvider * self,
    struct RTIXMLSaveContext * save_context,
    const char * xml_element_full_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_save_xml_element_children(
    DDS_QosProvider * self,
    struct RTIXMLSaveContext * dst,
    const char * xml_element_full_name);

extern DDSCDllExport
DDS_ReturnCode_t DDS_QosProvider_get_type_libraries(
    DDS_QosProvider *self,
    struct DDS_StringSeq* library_names);

/*ci @ingroup DDSDomainParticipantFactoryModule
 *
 * @brief Retrieves a type from a type library
 */
extern DDSCDllExport
const DDS_TypeCode * DDS_QosProvider_get_typecode_from_type_library(
    DDS_QosProvider *self,
    const char *library_name,
    const char *type_name);

extern DDSCDllExport struct DDS_QosProvider *
DDS_DomainParticipantFactory_get_qos_providerI(
    DDS_DomainParticipantFactory* self);

extern DDSCDllExport 
DDS_DomainParticipant * 
DDS_DomainParticipantFactory_create_participant_from_config_w_paramsI(
        DDS_DomainParticipantFactory *self,
        DDS_QosProvider *qos_provider,
        const char *configuration_name,
        const struct DDS_DomainParticipantConfigParams_t *params);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipantFactory_lockI(
    DDS_DomainParticipantFactory *self);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipantFactory_unlockI(
    DDS_DomainParticipantFactory *self);

extern DDSCDllExport DDS_Boolean
DDS_LocatorReachabilityHelper_locator_reachability_to_octet_seq(
    const struct DDS_LocatorReachabilityData *self,
    struct DDS_OctetSeq *seq);

extern DDSCDllExport DDS_Boolean
DDS_LocatorReachabilityHelper_locator_reachability_from_octet_seq(
    struct DDS_LocatorReachabilityData *self,
    const struct DDS_OctetSeq *seq); 

extern DDSCDllExport
DDS_ReturnCode_t DDS_DomainParticipant_set_tampering_listener(
        DDS_DomainParticipant *self,
        const struct MIGGeneratorListener *listener);

extern DDSCDllExport
int DDS_DomainParticipantResourceLimitsQosPolicyHelper_getAdjustedReaderMaxPropertyStringLength(
        int reader_property_string_max_length);

extern DDSCDllExport
int DDS_DomainParticipantResourceLimitsQosPolicyHelper_getAdjustedWriterMaxPropertyStringLength(
        int writer_property_string_max_length);


#define DDS_DOMAIN_PARTICIPANT_TABLE_NAME_REMOTE_PARTICIPANT \
    PRES_PARTICIPANT_TABLE_NAME_REMOTE_PARTICIPANT
#define DDS_DOMAIN_PARTICIPANT_TABLE_NAME_WRR \
    PRES_PARTICIPANT_TABLE_NAME_WRR
#define DDS_DOMAIN_PARTICIPANT_TABLE_NAME_RRW \
    PRES_PARTICIPANT_TABLE_NAME_RRW

extern DDSCDllExport
DDS_Boolean DDS_DomainParticipant_print_table(
        DDS_DomainParticipant *self,
        const char *tableName);

extern DDSCDllExport
const char * DDS_DomainParticipant_get_thread_participant_id(
        DDS_DomainParticipant *self);

extern DDSCDllExport const struct DDS_DomainParticipantQos *
DDS_DomainParticipantQos_get_print_all_sentinelI(void);

extern DDSCDllExport const struct DDS_DomainParticipantFactoryQos *
DDS_DomainParticipantFactoryQos_get_print_all_sentinelI(void);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_domain_impl_h */
