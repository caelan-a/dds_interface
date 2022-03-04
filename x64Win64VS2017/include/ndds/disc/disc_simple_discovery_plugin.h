/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)disc_simple_discovery_plugin.h    generated by: makeheader    Fri Apr 23 00:06:22 2021
 *
 *		built from:	simple_discovery_plugin.ifc
 */

#ifndef disc_simple_discovery_plugin_h
#define disc_simple_discovery_plugin_h


 #ifndef rti_makeheader_h
    #include "log/log_makeheader.h"
 #endif
 #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
 #endif
 #ifndef mig_rtps_h
    #include "mig/mig_rtps.h"
 #endif
 #ifndef pres_common_h
    #include "pres/pres_common.h"
 #endif
 #ifndef pres_typePlugin_h
    #include "pres/pres_typePlugin.h"
 #endif
 #ifndef pres_participant_h
    #include "pres/pres_participant.h"
 #endif
 #ifndef pres_psService_h
    #include "pres/pres_psService.h"
 #endif
 #ifndef disc_pluggable_h
    #include "disc/disc_pluggable.h"
 #endif
 #ifndef disc_builtin_h
    #include "disc/disc_builtin.h"
 #endif


#ifdef __cplusplus
    extern "C" {
#endif


#define DISC_SIMPLE_DISCOVERY_PLUGIN_PARTICIPANT_PARAMETER                  "DISCParticipantParameter"

#define DISC_SIMPLE_DISCOVERY_PLUGIN_TYPE_PARTICIPANT_PARAMETER             "DISCParticipantParameter"

#define DISC_SIMPLE_DISCOVERY_PLUGIN_PARTICIPANT_STATE_PARAMETER            "DISCParticipantStateParameter"

#define DISC_SIMPLE_DISCOVERY_PLUGIN_PUBLICATION_PARAMETER                  "DISCPublicationParameter"
#define DISC_SIMPLE_DISCOVERY_PLUGIN_SUBSCRIPTION_PARAMETER                 "DISCSubscriptionParameter"

#define DISC_SIMPLE_DISCOVERY_PLUGIN_PARTITION_MAXIMUM_NAME_COUNT_LIMIT                            (64)
#define DISC_SIMPLE_DISCOVERY_PLUGIN_PARTITION_MAXIMUM_NAME_COUNT_DEFAULT                          (0)
#define DISC_SIMPLE_DISCOVERY_PLUGIN_TYPE_CODE_MAXIMUM_SERIALIZED_LENGTH_DEFAULT                   (0)
#define DISC_SIMPLE_DISCOVERY_PLUGIN_TYPE_OBJECT_MAXIMUM_SERIALIZED_LENGTH_DEFAULT                 (0)
#define DISC_SIMPLE_DISCOVERY_PLUGIN_SERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_DEFAULT   (0)
#define DISC_SIMPLE_DISCOVERY_PLUGIN_TYPE_OBJECT_MAXIMUM_DESERIALIZED_LENGTH_DEFAULT               (0)
#define DISC_SIMPLE_DISCOVERY_PLUGIN_DESERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_DEFAULT (0)
#define DISC_SIMPLE_DISCOVERY_PLUGIN_TRANSPORT_INFO_LIST_MAX_LENGTH_DEFAULT                        (12)


struct DISCDiscoveryPluginProperty {
    MIGRtpsHostId hostId;
    MIGRtpsAppId appId;
    MIGRtpsInstanceId instanceId;

    PRESServiceId serviceId;

    /*i Class-id for the compression used for lb PIDs. */
    RTIOsapiCompressionPluginClassId lbSerializationClassID;

    int participantUserDataMaximumLength;
    int topicDataMaximumLength;
    int writerGroupDataMaximumLength;
    int writerUserDataMaximumLength;
    int readerGroupDataMaximumLength;
    int readerUserDataMaximumLength;
    int partitionMaximumNameCount;
    int partitionMaximumCumulativeLength;
    int typeCodeMaximumSerializedLength;
    int typeObjectMaximumSerializedLength;
    int serializedTypeObjectDynamicAllocationThreshold;
    int typeObjectMaximumDeserializedLength;
    int deserializedTypeObjectDynamicAllocationThreshold;
    /*i Max size in bytes a serialized type object can have to not trigger the
     *  low bandwidh (compressed) serialization. If this limit is exceeded, we
     *  will serialize a compressed version of the serialized type object.
     */
    int typeObjectLbSerializationThreshold;
    int contentFilterPropertyMaxLength;
    int locatorFilterSeqMaxLength;
    int locatorFilterExpressionMaxLength;
    RTIBool enableRtpsDiscoveryOptimization;
};


#define DISC_SIMPLE_DISCOVERY_PLUGIN_REFRESH_PERIOD_SLOW_DEFAULT        {72, 0}
#define DISC_SIMPLE_DISCOVERY_PLUGIN_REFRESH_PERIOD_FAST_DEFAULT        {1, 0}
#define DISC_SIMPLE_DISCOVERY_PLUGIN_NUMBER_OF_FAST_ATTEMPTS_DEFAULT    (1)

#define DISC_SIMPLE_DISCOVERY_PLUGIN_EXPIRATION_TIME_SEC_DEFAULT        180
#define DISC_SIMPLE_DISCOVERY_PLUGIN_EXPIRATION_TIME_FRAC_DEFAULT       0

#define DISC_SIMPLE_DISCOVERY_PLUGIN_EXPIRATION_TIME_DEFAULT {  \
DISC_SIMPLE_DISCOVERY_PLUGIN_EXPIRATION_TIME_SEC_DEFAULT,       \
DISC_SIMPLE_DISCOVERY_PLUGIN_EXPIRATION_TIME_FRAC_DEFAULT       \
}

#define DISC_SIMPLE_DISCOVERY_PLUGIN_INITIAL_REMOTE_PARTICIPANTS_DEFAULT 16
#define DISC_SIMPLE_DISCOVERY_PLUGIN_MAXIMUM_REMOTE_PARTICIPANTS_DEFAULT -1

#define DISC_DISCOVERY_PLUGIN_PROPERTY_DEFAULT { \
MIG_RTPS_HOST_ID_UNKNOWN, /* hostId */ \
MIG_RTPS_APP_ID_UNKNOWN, /* appId */ \
MIG_RTPS_INSTANCE_ID_UNKNOWN, /* instanceId */ \
PRES_SERVICE_ID_UNKNOWN, /* metatrafficServiceId */ \
RTI_OSAPI_COMPRESSION_CLASS_ID_AUTO, /* compressionId */ \
PRES_PARTICIPANT_USER_DATA_MAXIMUM,  /* participantUserDataMaximumLength */ \
PRES_PARTICIPANT_TOPIC_DATA_MAXIMUM, /* topicDataMaximumLength */ \
PRES_PS_GROUP_DATA_MAXIMUM,  /* writerGroupDataMaximumLength */ \
PRES_PS_USER_DATA_MAXIMUM,  /* writerUserDataMaximumLength */ \
PRES_PS_GROUP_DATA_MAXIMUM,  /* readerrGroupDataMaximumLength */ \
PRES_PS_USER_DATA_MAXIMUM,  /* readerUserDataMaximumLength */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_PARTITION_MAXIMUM_NAME_COUNT_DEFAULT, /*partitionMaximumNameCount*/ \
PRES_PS_PARTITION_MAXIMUM_CUMULATIVE_LENGTH_DEFAULT, /*partitionMaximumCumulativeLength*/ \
DISC_SIMPLE_DISCOVERY_PLUGIN_TYPE_CODE_MAXIMUM_SERIALIZED_LENGTH_DEFAULT, /* typeCodeMaximumSerializedLength */\
DISC_SIMPLE_DISCOVERY_PLUGIN_TYPE_OBJECT_MAXIMUM_SERIALIZED_LENGTH_DEFAULT, /* typeObjectMaximumSerializedLength */\
DISC_SIMPLE_DISCOVERY_PLUGIN_SERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_DEFAULT, /* serializedTypeObjectDynamicAllocationThreshold */\
DISC_SIMPLE_DISCOVERY_PLUGIN_TYPE_OBJECT_MAXIMUM_DESERIALIZED_LENGTH_DEFAULT, /* typeObjectMaximumDeserializedLength */\
DISC_SIMPLE_DISCOVERY_PLUGIN_DESERIALIZED_TYPE_OBJECT_DYNAMIC_ALLOCATION_THRESHOLD_DEFAULT, /* deserializedTypeObjectDynamicAllocationThreshold */\
PRES_PS_ENDPOINT_DISCOVERY_TYPE_OBJECT_LB_SERIALIZATION_THRESHOLD_DEFAULT, /* typeObjectLbSerializationThreshold */ \
PRES_CONTENT_FILTER_PROPERTY_LEN_MAX, /* maximum length for content filter property */\
PRES_LOCATOR_FILTER_DEFAULT_SEQ_LEN_MAX, \
PRES_LOCATOR_FILTER_DEFAULT_EXPRESSION_LEN_MAX, \
PRES_DISCOVERY_ENABLE_RTPS_DISCOVERY_OPTIMIZATION_DEFAULT /* enableRtpsDiscoveryOptimization */ \
}


struct DISCSimpleParticipantDiscoveryPluginProperty {
    struct DISCDiscoveryPluginProperty parent;

    char *                  multicast_receive_addresses;
    RTIBool                 accept_unknown_peers;

    RTINtpTime              expirationTime;
    RTINtpTime              participantRefreshPeriodSlow;
    RTINtpTime              participantRefreshPeriodFastMinDelay;
    RTINtpTime              participantRefreshPeriodFastMaxDelay;
    
    /* Period at which the local domain participant will be announced in the
     * default domain (0) over multicast 
     */
    RTINtpTime              domainBroadcastPeriod;
    RTINtpTime dnsTrackerPeriod;

    struct PRESTransportPriorityQosPolicy transportPriority;
    struct RTINetioAliasList transportAliasList;

    int initialRemoteParticipants;
    int maximumRemoteParticipants;

    int     participantNumberOfFastAttempts;
    int     participantNumberOfFastAttemptsOnEnable;
    int     participantPropertyListMaximumLength;
    int     participantPropertyStringMaximumLength;
    int     transportInfoListMaxLength;

    struct PRESPsReaderFragmentationResourceLimits participantReaderFragmentationResourceLimits;

    RTIBool paClientOnly;

    struct PRESPsSrReaderProperty participantProxyReaderProperty;
    struct PRESPsSrWriterProperty participantStateWriterProperty;

    RTIBool sendParticipantAnnouncementOnDiscovery;
    RTIBool broadcastParticipantAnnouncementOnDiscovery;

    PRESCdrPaddingKind cdrPaddingKind;
};


#define DISC_PLUGIN_INFO_PARAMETER_MAX_LENGTH       0

#define DISC_SIMPLE_PARTICIPANT_DISCOVERY_PLUGIN_PROPERTY_DEFAULT { \
DISC_DISCOVERY_PLUGIN_PROPERTY_DEFAULT, /* parent */  \
NULL, /* multicast_receive_addresses */\
RTI_TRUE, /* accept_unknown_peers */\
DISC_SIMPLE_DISCOVERY_PLUGIN_EXPIRATION_TIME_DEFAULT, /* expirationTime */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_REFRESH_PERIOD_SLOW_DEFAULT, /* participantRefreshPeriodSlow */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_REFRESH_PERIOD_FAST_DEFAULT, /* participantRefreshPeriodFastMinDelay */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_REFRESH_PERIOD_FAST_DEFAULT, /* participantRefreshPeriodFastMaxDelay */ \
{0,0}, /* domainBroadcastPeriod */ \
RTI_NTP_TIME_MAX, /* dnsTrackerPeriod */ \
{NDDS_TRANSPORT_PRIORITY_DEFAULT},/*transportPriority*/ \
RTI_NETIO_ALIAS_LIST_DEFAULT,/* transportAliasList */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_INITIAL_REMOTE_PARTICIPANTS_DEFAULT, /* initialRemoteParticipants */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_MAXIMUM_REMOTE_PARTICIPANTS_DEFAULT, /* maximumRemoteParticipants */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_NUMBER_OF_FAST_ATTEMPTS_DEFAULT, /* participantNumberOfFastAttempts */ \
DISC_SIMPLE_DISCOVERY_PLUGIN_NUMBER_OF_FAST_ATTEMPTS_DEFAULT, /* participantNumberOfFastAttemptsOnEnable */ \
PRES_PARTICIPANT_PROPERTY_LIST_MAXIMUM, /* maximum participant property list length */\
PRES_PARTICIPANT_PROPERTY_STRING_MAXIMUM, /* maximum participant property list length */\
DISC_SIMPLE_DISCOVERY_PLUGIN_TRANSPORT_INFO_LIST_MAX_LENGTH_DEFAULT, /* transportInfoListMaxLength */\
PRES_PS_READER_FRAGMENTATION_RESOURCE_LIMITS_DEFAULT, /* participantReaderFragmentationResourceLimits */ \
RTI_FALSE, /* paClientOnly */ \
PRES_PS_SR_READER_PROPERTY_DEFAULT, /* participantProxyReaderProperty */ \
PRES_PS_SR_WRITER_PROPERTY_DEFAULT, /* participantStateWriterProperty */\
RTI_TRUE, /* sendParticipantAnnouncementOnDiscovery */ \
RTI_TRUE, /* broadcastParticipantAnnouncementOnDiscovery */ \
PRES_NOT_SET_CDR_PADDING /* zeroOnAlign */\
}


#define DISC_SIMPLE_PARTICIPANT_DISCOVERY_PLUGIN_INFO {     \
MIG_RTPS_VENDOR_ID_RTI,                                     \
DISC_SIMPLE_DISCOVERY_PLUGIN_CLASS_ID,                      \
MIG_RTPS_PROTOCOL_VERSION,                                  \
}


struct DISCSimpleEndpointDiscoveryPluginProperty {
    struct DISCDiscoveryPluginProperty parent;

    RTIBool relyOnSpdpOnly;

    struct PRESPsSrReaderProperty publicationDetectorProperty;
    struct PRESPsSrReaderProperty subscriptionDetectorProperty;

    struct PRESPsSrWriterProperty publicationAnnouncerProperty;
    struct PRESPsSrWriterProperty subscriptionAnnouncerProperty;

    struct PRESPsWriterGroupProperty announcerGroupProperty;

    /*i
     * The maximum number of name,value pairs in the 
     * writer property list
     */
    int writerPropertyListMaximumLength;

    /*i The total number of bytes, excluding NULL termination,
     * in all the name,value pairs 
     */
    int writerPropertyStringMaximumLength;

    /*i 
     * The maximum number of name,value pairs in the 
     * reader property list
     */
    int readerPropertyListMaximumLength;

    /*i The total number of bytes, excluding NULL termination,
     * in all the name,value pairs 
     */
    int readerPropertyStringMaximumLength;

    /*i
     * The maximum number of name,value pairs in the 
     * writer data tag list
     */
    int writerDataTagListMaximumLength;

    /*i The total number of bytes, excluding NULL termination,
     * in all the name,value pairs 
     */
    int writerDataTagStringMaximumLength;

    /*i 
     * The maximum number of name,value pairs in the 
     * reader data tag list
     */
    int readerDataTagListMaximumLength;

    /*i The total number of bytes, excluding NULL termination,
     * in all the name,value pairs 
     */
    int readerDataTagStringMaximumLength;

    PRESCdrPaddingKind cdrPaddingKind;
};


#define DISC_SIMPLE_ENDPOINT_DISCOVERY_PLUGIN_PROPERTY_DEFAULT {            \
DISC_DISCOVERY_PLUGIN_PROPERTY_DEFAULT,                                     \
RTI_FALSE,                                                                  \
PRES_PS_SR_READER_PROPERTY_DEFAULT, /* publicationDetectorProperty */       \
PRES_PS_SR_READER_PROPERTY_DEFAULT, /* subscriptionDetectorProperty */      \
PRES_PS_SR_WRITER_PROPERTY_DEFAULT, /* publicationAnnouncerProperty */      \
PRES_PS_SR_WRITER_PROPERTY_DEFAULT, /* subscriptionAnnouncerProperty */     \
PRES_PS_WRITER_GROUP_PROPERTY_DEFAULT, /* announcerGroupProperty */         \
PRES_PS_PROPERTY_LIST_MAXIMUM,      /* writerPropertyListMaximumLength */   \
PRES_PS_PROPERTY_STRING_MAXIMUM,    /* writerPropertyStringMaximumLength */ \
PRES_PS_PROPERTY_LIST_MAXIMUM,      /* readerPropertyListMaximumLength */   \
PRES_PS_PROPERTY_STRING_MAXIMUM,    /* readerPropertyStringMaximumLength */ \
PRES_PS_DATA_TAG_LIST_MAXIMUM,      /* writerDataTagListMaximumLength */   \
PRES_PS_DATA_TAG_STRING_MAXIMUM,    /* writerDataTagStringMaximumLength */ \
PRES_PS_DATA_TAG_LIST_MAXIMUM,      /* readerDataTagListMaximumLength */   \
PRES_PS_DATA_TAG_STRING_MAXIMUM,    /* readerDataTagStringMaximumLength */ \
PRES_NOT_SET_CDR_PADDING            /* cdrPaddingKind */                    \
}

extern DISCDllExport
struct DISCSimpleParticipantDiscoveryPlugin *
DISCSimpleParticipantDiscoveryPlugin_new(
        struct PRESParticipant *participant,
        struct RTINetioLocator *peer_destinations,
        int peer_destination_count,
        struct REDAExclusiveArea *readerGroupEA,
        struct REDAExclusiveArea *writerGroupEA,
        struct DISCSimpleParticipantDiscoveryPluginProperty *property,
        RTIBool createEdsEndpoints,
        struct DISCPluginManager *pluginManager,
        struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleParticipantDiscoveryPlugin_enable(
    struct DISCSimpleParticipantDiscoveryPlugin *me,
    struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleParticipantDiscoveryPlugin_assertDestinations(
    struct DISCSimpleParticipantDiscoveryPlugin *me,
    struct RTINetioLocator *destinationList, 
    int destinationCount,
    struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleParticipantDiscoveryPlugin_assertDomainBroadcastDestination(
    struct DISCSimpleParticipantDiscoveryPlugin *me,
    struct RTINetioLocator *destination, 
    struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleParticipantDiscoveryPlugin_removeDestinations(
    struct DISCSimpleParticipantDiscoveryPlugin *me,
    struct RTINetioLocator *destinationList, 
    int destinationCount,
    struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleParticipantDiscoveryPlugin_shutdown(
    struct DISCSimpleParticipantDiscoveryPlugin *me,
    struct REDAWorker *worker);

extern DISCDllExport 
struct DISCParticipantDiscoveryPlugin*
DISCSimpleParticipantDiscoveryPlugin_getPluginHandle(
    struct DISCSimpleParticipantDiscoveryPlugin *me);

extern DISCDllExport void
DISCSimpleParticipantDiscoveryPlugin_delete(
    struct DISCSimpleParticipantDiscoveryPlugin *me);

extern DISCDllExport void
DISCSimpleParticipantDiscoveryPlugin_finalizePlugins(void);

extern DISCDllExport
struct DISCSimpleParticipantDiscoveryPluginProperty *
DISCSimpleParticipantDiscoveryPlugin_getProperty(
    struct DISCSimpleParticipantDiscoveryPlugin *me);

extern DISCDllExport
struct DISCSimpleEndpointDiscoveryPlugin *
DISCSimpleEndpointDiscoveryPlugin_new(
    struct PRESParticipant *participant,
    struct REDAExclusiveArea *readerGroupEA,
    struct REDAExclusiveArea *writerGroupEA,
    struct DISCSimpleEndpointDiscoveryPluginProperty *property,
    struct DISCPluginManager *pluginManager,
    struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleEndpointDiscoveryPlugin_enable(
    struct DISCSimpleEndpointDiscoveryPlugin *me,
    struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleEndpointDiscoveryPlugin_shutdown(
    struct DISCSimpleEndpointDiscoveryPlugin *me,
    struct REDAWorker *worker);

extern DISCDllExport void
DISCSimpleEndpointDiscoveryPlugin_delete(
    struct DISCSimpleEndpointDiscoveryPlugin *me);

extern DISCDllExport
void DISCSimpleEndpointDiscoveryPlugin_finalizePlugins(void);

extern DISCDllExport struct PRESPsReader *
DISCSimpleEndpointDiscoveryPlugin_getSubscriptionReader(
    struct DISCSimpleEndpointDiscoveryPlugin *me);

extern DISCDllExport struct PRESPsReader *
DISCSimpleEndpointDiscoveryPlugin_getPublicationReader(
    struct DISCSimpleEndpointDiscoveryPlugin *me);

extern DISCDllExport RTIBool
DISCSimpleParticipantDiscoveryPluggin_setDnsTrackerPeriod(
        struct DISCSimpleParticipantDiscoveryPlugin* self,
        const RTINtpTime *newPeriod,
        struct REDAWorker *worker);

extern DISCDllExport RTIBool
DISCSimpleParticipantDiscoveryPluggin_getDnsTrackerPeriod(
        struct DISCSimpleParticipantDiscoveryPlugin* self,
        RTINtpTime *period,
        struct REDAWorker *worker);


typedef enum {
    DISC_SIMPLE_DISCOVERY_PLUGIN_PARTICIPANT_STATE_ACCEPTED,
    DISC_SIMPLE_DISCOVERY_PLUGIN_PARTICIPANT_STATE_IGNORED,
    DISC_SIMPLE_DISCOVERY_PLUGIN_PARTICIPANT_STATE_UNKNOWN
} DISCSimpleEndpointDiscoveryPluginParticipantStateKind;


struct DISCParticipantState {
    DISCSimpleEndpointDiscoveryPluginParticipantStateKind kind;
    /* the participant who just accepted/ignored/etc the subjectParticipant */
    struct MIGRtpsGuid sourceParticipantGuid;
    /* the participant who just got accepted/ignored/etc by the sourceParticipant */
    struct MIGRtpsGuid subjectParticipantGuid; /* key */
};

extern DISCDllExport 
struct PRESTypePlugin **
DISCParticipantStateTypePlugin_assert(void);

extern DISCDllExport void  
DISCParticipantStateTypePlugin_delete(
    struct PRESTypePlugin *plugin);


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_serializeData \
DISCBuiltinTopicParticipantDataPlugin_serializeData


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_serializeEncapsulation \
DISCBuiltinTopicParticipantDataPlugin_serializeEncapsulation


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_serialize \
DISCBuiltinTopicParticipantDataPlugin_serialize

extern DISCDllExport void 
DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_setDefaultParameterValues(
    struct DISCBuiltinTopicParticipantData *topic_data);


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_deserializeParameterValue \
DISCBuiltinTopicParticipantDataPlugin_deserializeParameterValue


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_deserializeData \
DISCBuiltinTopicParticipantDataPlugin_deserializeData


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_deserializeEncapsulation \
DISCBuiltinTopicParticipantDataPlugin_deserializeEncapsulation


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_deserialize \
DISCBuiltinTopicParticipantDataPlugin_deserialize

extern DISCDllExport unsigned int
DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_getMaxSizeSerializedWithData(
    unsigned int size,
    int userDataMaximumLength,
    int propertyListMaximumLength,
    int propertyStringMaximumLength);


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_print \
DISCBuiltinTopicParticipantDataPlugin_print


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_copy \
DISCBuiltinTopicParticipantDataPlugin_copy

extern DISCDllExport RTIBool 
DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_initialize(
    struct DISCBuiltinTopicParticipantData *topic_data);


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_finalize \
DISCBuiltinTopicParticipantDataPlugin_finalize

extern DISCDllExport 
struct DISCBuiltinTopicParticipantData *
DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_createSample(void);


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_destroySample \
DISCBuiltinTopicParticipantDataPlugin_destroySample

extern DISCDllExport struct PRESTypePlugin **
DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_assert(void);

extern DISCDllExport void  
DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_delete(
    struct PRESTypePlugin *plugin);


#define DISCSimpleParticipantDiscoveryPluginTopicDataPlugin_compare \
DISCBuiltinTopicParticipantDataPlugin_compare


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* disc_simple_discovery_plugin_h */
