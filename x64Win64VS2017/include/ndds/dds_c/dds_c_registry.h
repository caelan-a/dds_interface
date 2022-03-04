/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_registry.h    generated by: makeheader    Fri Apr 23 00:06:06 2021
 *
 *		built from:	registry.ifc
 */

#ifndef dds_c_registry_h
#define dds_c_registry_h


#ifndef dds_c_infrastructure_h
	#include "dds_c/dds_c_infrastructure.h"
#endif
#ifndef reda_inlineList_h
	#include "reda/reda_inlineList.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

typedef void *DDS_RegistryValue;

typedef
void (*DDS_RegistryDeleteValueFnc)(
	const char *name,
	DDS_RegistryValue value,
	void *deleteValueFncParameter);

typedef
DDS_RegistryValue (*DDS_RegistryCreateValueFnc)(
	const char *name,
        void *createValueFncParameter);

typedef enum {
	DDS_REGISTRY_RETURN_CODE_ERROR,
	DDS_REGISTRY_RETURN_CODE_SUCCESS,
	DDS_REGISTRY_RETURN_CODE_NOT_FOUND
} DDS_RegistryReturnCode;

struct DDS_RegistryRecord {
	struct REDAInlineListNode _node;
	/* The key */
	const char *name;
	/* An opaque pointer for storage */
	DDS_RegistryValue value;
	/* A reference count to this record */	
	unsigned int referenceCount;
	/* The free function associated with this record */
	DDS_RegistryDeleteValueFnc deleteValueFnc;
	/* The parameter associated with the free function */
	void *deleteValueFncParameter;
};

struct DDS_RegistryConfiguration {
	/* The maximum length of the name string */
	unsigned int nameMaxLength;
        /* Flag for whether to use explicit locking */
	RTIBool multiThreadedAccess;
	/* Pool property for record pool */
	struct REDAFastBufferPoolProperty recordPoolProperty;
	/* Semaphore property */
	struct RTIOsapiSemaphoreProperty mutexProperty;
};


#define DDS_REGISTRY_CONFIGURATION_DEFAULT { 		\
    128,	/* nameMaxLength */			\
    RTI_TRUE,	/* multiThreadedAccess */		\
    REDA_FAST_BUFFER_POOL_PROPERTY_DEFAULT, /* recordPoolProperty */ \
    RTI_OSAPI_SEMAPHORE_PROPERTY_DEFAULT /* mutexProperty */ \
}

struct DDS_Registry {
	/* The list used to store the records */
	struct REDAInlineList *_list;
	/* The configuration parameters for this service instance */
	struct DDS_RegistryConfiguration _config;
	/* The fast buffer pool used for the records */
	struct REDAFastBufferPool *_recordPool;
	/* The mutex used to protect the table */
	struct RTIOsapiSemaphore *_mutex;
};

extern DDSCDllExport
struct DDS_Registry *
DDS_Registry_new(
	DDS_RegistryReturnCode *retCode, /* out */
	struct DDS_RegistryConfiguration *config);

extern DDSCDllExport
DDS_RegistryReturnCode
DDS_Registry_delete(
	struct DDS_Registry *registry);

extern DDSCDllExport
DDS_RegistryValue
DDS_Registry_findRecord(
	DDS_RegistryReturnCode *retCode, /* out */
	struct DDS_Registry *registry,
	const char *name);

extern DDSCDllExport
DDS_RegistryValue
DDS_Registry_assertRecord(
	DDS_RegistryReturnCode *retCode, /* out */
	struct DDS_Registry *registry,
	const char *name, 
	DDS_RegistryCreateValueFnc createValueFnc,
	void *createValueFncParameter,
	DDS_RegistryDeleteValueFnc deleteValueFnc,
	void *deleteValueFncParameter);

extern DDSCDllExport
DDS_RegistryReturnCode
DDS_Registry_releaseRecord(
	struct DDS_Registry *registry,
	const char *name);

typedef void
(*DDS_METypePlugin_setSampleSerializedFnc)(const void *sample);

typedef RTIBool
(*DDS_METypePlugin_serializeFnc)(
        PRESTypePluginEndpointData endpoint_data,
        const void *sample,
        struct RTICdrStream *stream,
        RTIBool serialize_encapsulation,
        RTIEncapsulationId encapsulation_id,
        RTIBool serialize_sample,
        void *endpoint_plugin_qos);

typedef RTIBool
(*DDS_METypePlugin_deserializeFnc)(
        PRESTypePluginEndpointData endpoint_data,
        void **sample,
        RTIBool *drop,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample,
        void *endpoint_plugin_qos);

typedef RTIBool 
(*DDS_METypePlugin_validEncapsulationIdFnc)(
        RTIEncapsulationId encapsulation_id);

typedef RTIBool
(*DDS_METypePlugin_returnSampleFnc)(
        PRESTypePluginEndpointData endpointData,
        void *sample,
        void *handle);

typedef void*
(*DDS_METypePlugin_getSampleFnc)(
        PRESTypePluginEndpointData endpointData);

typedef PRESTypePluginParticipantData 
(*DDS_METypePlugin_onParticipantAttachedFnc)(
        PRESTypePluginParticipantData epd,
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

typedef void 
(*DDS_METypePlugin_onParticipantDetachedFnc)(
        PRESTypePluginParticipantData participant_data);

typedef RTI_UINT32(*DDS_METypePlugin_getMaxDeserializedSizeFunction)(void);

typedef RTIBool (*DDS_METypePlugin_initializeSampleFunction)(void*);

typedef RTIBool 
(*DDS_METypePlugin_onEndpointAttachedFnc)(
        PRESTypePluginParticipantData participant_data,
        PRESTypePluginEndpointData epd,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTI_UINT32 maxDeserializedSize,
        DDS_METypePlugin_initializeSampleFunction);

typedef void 
(*DDS_METypePlugin_onEndpointDetachedFnc)(
        PRESTypePluginEndpointData endpoint_data);

typedef RTIBool 
(*DDS_METypePlugin_serializeAndSetCdrEncapsulationFnc)(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream,
        RTIEncapsulationId encapsulation_id,
        RTIBool *oob);

typedef RTIBool 
(*DDS_METypePlugin_deserializeAndSetCdrEncapsulationFnc)(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream,
        RTIBool *oob);

typedef unsigned int 
(*DDS_METypePlugin_getSerializedSampleMaxSizeFnc)(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int size,
        RTIBool *oob);

typedef unsigned int 
(*DDS_METypePlugin_getSerializedSampleMinSizeFnc)(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int size,
        RTIBool *oob);

typedef unsigned int
(*DDS_METypePlugin_getSerializedSampleSizeFnc)(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment,
        RTIBool *oob);


struct DDS_MetpRegistryClass;

 
typedef struct DDS_MetpRegistryClass {
    DDS_METypePlugin_serializeAndSetCdrEncapsulationFnc serializeAndSetCdrEncapsulationFnc;
    DDS_METypePlugin_deserializeAndSetCdrEncapsulationFnc deserializeAndSetCdrEncapsulationFnc;
    DDS_METypePlugin_serializeFnc serializeFnc;
    DDS_METypePlugin_deserializeFnc deserializeFnc;
    DDS_METypePlugin_setSampleSerializedFnc setSampleSerializedFnc;
    DDS_METypePlugin_getSampleFnc getSampleFnc;
    DDS_METypePlugin_returnSampleFnc returnSampleFnc;
    DDS_METypePlugin_validEncapsulationIdFnc validEncapsulationIdFnc;
    DDS_METypePlugin_getSerializedSampleMaxSizeFnc getSerializedSampleMaxSizeFnc;
    DDS_METypePlugin_getSerializedSampleMinSizeFnc getSerializedSampleMinSizeFnc;
    DDS_METypePlugin_getSerializedSampleSizeFnc getSerializedSampleSizeFnc;
    DDS_METypePlugin_onParticipantAttachedFnc onParticipantAttachedFnc;
    DDS_METypePlugin_onParticipantDetachedFnc onParticipantDetachedFnc;
    DDS_METypePlugin_onEndpointAttachedFnc onEndpointAttachedFnc;
    DDS_METypePlugin_onEndpointDetachedFnc onEndpointDetachedFnc;

    void *userData;
} DDS_MetpRegistryClass;

typedef struct DDS_MetpRegistryValue {
    char *name;
    DDS_MetpRegistryClass *metpClass;    
} DDS_MetpRegistryValue;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_registry_h */
