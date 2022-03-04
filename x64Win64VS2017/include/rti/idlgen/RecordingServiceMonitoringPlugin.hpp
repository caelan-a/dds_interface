

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from RecordingServiceMonitoring.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef RecordingServiceMonitoringPlugin_741490610_h
#define RecordingServiceMonitoringPlugin_741490610_h

#include "RecordingServiceMonitoring.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "ServiceCommonPlugin.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace RTI {
    namespace RecordingService {
        namespace Monitoring {
            using namespace ::RTI::Service;
            using namespace ::RTI::Service::Monitoring;

            #define TopicConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define TopicConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define TopicConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define TopicConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define TopicConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern TopicConfig*
            TopicConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern TopicConfig*
            TopicConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern TopicConfig*
            TopicConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            TopicConfigPluginSupport_copy_data(
                TopicConfig *out,
                const TopicConfig *in);

            NDDSUSERDllExport extern void 
            TopicConfigPluginSupport_destroy_data_w_params(
                TopicConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            TopicConfigPluginSupport_destroy_data_ex(
                TopicConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            TopicConfigPluginSupport_destroy_data(
                TopicConfig *sample);

            NDDSUSERDllExport extern void 
            TopicConfigPluginSupport_print_data(
                const TopicConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            TopicConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                TopicConfig *out,
                const TopicConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            TopicConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const TopicConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            TopicConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                TopicConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            TopicConfigPlugin_deserialize_from_cdr_buffer(
                TopicConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            TopicConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            TopicConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            TopicConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            TopicConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            TopicConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                TopicConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define TopicEventPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define TopicEventPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define TopicEventPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define TopicEventPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define TopicEventPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern TopicEvent*
            TopicEventPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern TopicEvent*
            TopicEventPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern TopicEvent*
            TopicEventPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            TopicEventPluginSupport_copy_data(
                TopicEvent *out,
                const TopicEvent *in);

            NDDSUSERDllExport extern void 
            TopicEventPluginSupport_destroy_data_w_params(
                TopicEvent *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            TopicEventPluginSupport_destroy_data_ex(
                TopicEvent *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            TopicEventPluginSupport_destroy_data(
                TopicEvent *sample);

            NDDSUSERDllExport extern void 
            TopicEventPluginSupport_print_data(
                const TopicEvent *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            TopicEventPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                TopicEvent *out,
                const TopicEvent *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            TopicEventPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const TopicEvent *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            TopicEventPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                TopicEvent **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            TopicEventPlugin_deserialize_from_cdr_buffer(
                TopicEvent *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            TopicEventPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            TopicEventPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            TopicEventPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            TopicEventPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            TopicEventPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                TopicEvent ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define TopicPeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define TopicPeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define TopicPeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define TopicPeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define TopicPeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern TopicPeriodic*
            TopicPeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern TopicPeriodic*
            TopicPeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern TopicPeriodic*
            TopicPeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            TopicPeriodicPluginSupport_copy_data(
                TopicPeriodic *out,
                const TopicPeriodic *in);

            NDDSUSERDllExport extern void 
            TopicPeriodicPluginSupport_destroy_data_w_params(
                TopicPeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            TopicPeriodicPluginSupport_destroy_data_ex(
                TopicPeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            TopicPeriodicPluginSupport_destroy_data(
                TopicPeriodic *sample);

            NDDSUSERDllExport extern void 
            TopicPeriodicPluginSupport_print_data(
                const TopicPeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            TopicPeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                TopicPeriodic *out,
                const TopicPeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            TopicPeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const TopicPeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            TopicPeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                TopicPeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            TopicPeriodicPlugin_deserialize_from_cdr_buffer(
                TopicPeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            TopicPeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            TopicPeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            TopicPeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            TopicPeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            TopicPeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                TopicPeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define TopicGroupConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define TopicGroupConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define TopicGroupConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define TopicGroupConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define TopicGroupConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern TopicGroupConfig*
            TopicGroupConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern TopicGroupConfig*
            TopicGroupConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern TopicGroupConfig*
            TopicGroupConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            TopicGroupConfigPluginSupport_copy_data(
                TopicGroupConfig *out,
                const TopicGroupConfig *in);

            NDDSUSERDllExport extern void 
            TopicGroupConfigPluginSupport_destroy_data_w_params(
                TopicGroupConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            TopicGroupConfigPluginSupport_destroy_data_ex(
                TopicGroupConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            TopicGroupConfigPluginSupport_destroy_data(
                TopicGroupConfig *sample);

            NDDSUSERDllExport extern void 
            TopicGroupConfigPluginSupport_print_data(
                const TopicGroupConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            TopicGroupConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupConfig *out,
                const TopicGroupConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            TopicGroupConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const TopicGroupConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            TopicGroupConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            TopicGroupConfigPlugin_deserialize_from_cdr_buffer(
                TopicGroupConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            TopicGroupConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            TopicGroupConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            TopicGroupConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            TopicGroupConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            TopicGroupConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define TopicGroupEventPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define TopicGroupEventPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define TopicGroupEventPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define TopicGroupEventPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define TopicGroupEventPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern TopicGroupEvent*
            TopicGroupEventPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern TopicGroupEvent*
            TopicGroupEventPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern TopicGroupEvent*
            TopicGroupEventPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            TopicGroupEventPluginSupport_copy_data(
                TopicGroupEvent *out,
                const TopicGroupEvent *in);

            NDDSUSERDllExport extern void 
            TopicGroupEventPluginSupport_destroy_data_w_params(
                TopicGroupEvent *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            TopicGroupEventPluginSupport_destroy_data_ex(
                TopicGroupEvent *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            TopicGroupEventPluginSupport_destroy_data(
                TopicGroupEvent *sample);

            NDDSUSERDllExport extern void 
            TopicGroupEventPluginSupport_print_data(
                const TopicGroupEvent *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            TopicGroupEventPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupEvent *out,
                const TopicGroupEvent *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            TopicGroupEventPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const TopicGroupEvent *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            TopicGroupEventPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupEvent **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            TopicGroupEventPlugin_deserialize_from_cdr_buffer(
                TopicGroupEvent *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            TopicGroupEventPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            TopicGroupEventPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            TopicGroupEventPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            TopicGroupEventPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            TopicGroupEventPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupEvent ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define TopicGroupPeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define TopicGroupPeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define TopicGroupPeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define TopicGroupPeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define TopicGroupPeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern TopicGroupPeriodic*
            TopicGroupPeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern TopicGroupPeriodic*
            TopicGroupPeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern TopicGroupPeriodic*
            TopicGroupPeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            TopicGroupPeriodicPluginSupport_copy_data(
                TopicGroupPeriodic *out,
                const TopicGroupPeriodic *in);

            NDDSUSERDllExport extern void 
            TopicGroupPeriodicPluginSupport_destroy_data_w_params(
                TopicGroupPeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            TopicGroupPeriodicPluginSupport_destroy_data_ex(
                TopicGroupPeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            TopicGroupPeriodicPluginSupport_destroy_data(
                TopicGroupPeriodic *sample);

            NDDSUSERDllExport extern void 
            TopicGroupPeriodicPluginSupport_print_data(
                const TopicGroupPeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            TopicGroupPeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupPeriodic *out,
                const TopicGroupPeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            TopicGroupPeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const TopicGroupPeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            TopicGroupPeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupPeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            TopicGroupPeriodicPlugin_deserialize_from_cdr_buffer(
                TopicGroupPeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            TopicGroupPeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            TopicGroupPeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            TopicGroupPeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            TopicGroupPeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            TopicGroupPeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                TopicGroupPeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define SessionConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define SessionConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define SessionConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define SessionConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define SessionConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern SessionConfig*
            SessionConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern SessionConfig*
            SessionConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern SessionConfig*
            SessionConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            SessionConfigPluginSupport_copy_data(
                SessionConfig *out,
                const SessionConfig *in);

            NDDSUSERDllExport extern void 
            SessionConfigPluginSupport_destroy_data_w_params(
                SessionConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            SessionConfigPluginSupport_destroy_data_ex(
                SessionConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            SessionConfigPluginSupport_destroy_data(
                SessionConfig *sample);

            NDDSUSERDllExport extern void 
            SessionConfigPluginSupport_print_data(
                const SessionConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            SessionConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                SessionConfig *out,
                const SessionConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            SessionConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const SessionConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            SessionConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                SessionConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            SessionConfigPlugin_deserialize_from_cdr_buffer(
                SessionConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            SessionConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            SessionConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            SessionConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            SessionConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            SessionConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                SessionConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define SessionEventPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define SessionEventPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define SessionEventPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define SessionEventPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define SessionEventPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern SessionEvent*
            SessionEventPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern SessionEvent*
            SessionEventPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern SessionEvent*
            SessionEventPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            SessionEventPluginSupport_copy_data(
                SessionEvent *out,
                const SessionEvent *in);

            NDDSUSERDllExport extern void 
            SessionEventPluginSupport_destroy_data_w_params(
                SessionEvent *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            SessionEventPluginSupport_destroy_data_ex(
                SessionEvent *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            SessionEventPluginSupport_destroy_data(
                SessionEvent *sample);

            NDDSUSERDllExport extern void 
            SessionEventPluginSupport_print_data(
                const SessionEvent *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            SessionEventPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                SessionEvent *out,
                const SessionEvent *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            SessionEventPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const SessionEvent *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            SessionEventPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                SessionEvent **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            SessionEventPlugin_deserialize_from_cdr_buffer(
                SessionEvent *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            SessionEventPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            SessionEventPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            SessionEventPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            SessionEventPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            SessionEventPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                SessionEvent ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define SessionPeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define SessionPeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define SessionPeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define SessionPeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define SessionPeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern SessionPeriodic*
            SessionPeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern SessionPeriodic*
            SessionPeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern SessionPeriodic*
            SessionPeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            SessionPeriodicPluginSupport_copy_data(
                SessionPeriodic *out,
                const SessionPeriodic *in);

            NDDSUSERDllExport extern void 
            SessionPeriodicPluginSupport_destroy_data_w_params(
                SessionPeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            SessionPeriodicPluginSupport_destroy_data_ex(
                SessionPeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            SessionPeriodicPluginSupport_destroy_data(
                SessionPeriodic *sample);

            NDDSUSERDllExport extern void 
            SessionPeriodicPluginSupport_print_data(
                const SessionPeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            SessionPeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                SessionPeriodic *out,
                const SessionPeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            SessionPeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const SessionPeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            SessionPeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                SessionPeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            SessionPeriodicPlugin_deserialize_from_cdr_buffer(
                SessionPeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            SessionPeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            SessionPeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            SessionPeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            SessionPeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            SessionPeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                SessionPeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define SqliteDatabaseConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define SqliteDatabaseConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define SqliteDatabaseConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define SqliteDatabaseConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define SqliteDatabaseConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern SqliteDatabaseConfig*
            SqliteDatabaseConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern SqliteDatabaseConfig*
            SqliteDatabaseConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern SqliteDatabaseConfig*
            SqliteDatabaseConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseConfigPluginSupport_copy_data(
                SqliteDatabaseConfig *out,
                const SqliteDatabaseConfig *in);

            NDDSUSERDllExport extern void 
            SqliteDatabaseConfigPluginSupport_destroy_data_w_params(
                SqliteDatabaseConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            SqliteDatabaseConfigPluginSupport_destroy_data_ex(
                SqliteDatabaseConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            SqliteDatabaseConfigPluginSupport_destroy_data(
                SqliteDatabaseConfig *sample);

            NDDSUSERDllExport extern void 
            SqliteDatabaseConfigPluginSupport_print_data(
                const SqliteDatabaseConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabaseConfig *out,
                const SqliteDatabaseConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            SqliteDatabaseConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const SqliteDatabaseConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabaseConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            SqliteDatabaseConfigPlugin_deserialize_from_cdr_buffer(
                SqliteDatabaseConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabaseConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            SqliteDatabaseConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabaseConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabaseConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabaseConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define SqliteDatabaseEventPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define SqliteDatabaseEventPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define SqliteDatabaseEventPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define SqliteDatabaseEventPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define SqliteDatabaseEventPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern SqliteDatabaseEvent*
            SqliteDatabaseEventPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern SqliteDatabaseEvent*
            SqliteDatabaseEventPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern SqliteDatabaseEvent*
            SqliteDatabaseEventPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseEventPluginSupport_copy_data(
                SqliteDatabaseEvent *out,
                const SqliteDatabaseEvent *in);

            NDDSUSERDllExport extern void 
            SqliteDatabaseEventPluginSupport_destroy_data_w_params(
                SqliteDatabaseEvent *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            SqliteDatabaseEventPluginSupport_destroy_data_ex(
                SqliteDatabaseEvent *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            SqliteDatabaseEventPluginSupport_destroy_data(
                SqliteDatabaseEvent *sample);

            NDDSUSERDllExport extern void 
            SqliteDatabaseEventPluginSupport_print_data(
                const SqliteDatabaseEvent *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseEventPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabaseEvent *out,
                const SqliteDatabaseEvent *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            SqliteDatabaseEventPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const SqliteDatabaseEvent *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseEventPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabaseEvent **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            SqliteDatabaseEventPlugin_deserialize_from_cdr_buffer(
                SqliteDatabaseEvent *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabaseEventPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            SqliteDatabaseEventPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabaseEventPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabaseEventPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabaseEventPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabaseEvent ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define SqliteDatabasePeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define SqliteDatabasePeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define SqliteDatabasePeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define SqliteDatabasePeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define SqliteDatabasePeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern SqliteDatabasePeriodic*
            SqliteDatabasePeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern SqliteDatabasePeriodic*
            SqliteDatabasePeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern SqliteDatabasePeriodic*
            SqliteDatabasePeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabasePeriodicPluginSupport_copy_data(
                SqliteDatabasePeriodic *out,
                const SqliteDatabasePeriodic *in);

            NDDSUSERDllExport extern void 
            SqliteDatabasePeriodicPluginSupport_destroy_data_w_params(
                SqliteDatabasePeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            SqliteDatabasePeriodicPluginSupport_destroy_data_ex(
                SqliteDatabasePeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            SqliteDatabasePeriodicPluginSupport_destroy_data(
                SqliteDatabasePeriodic *sample);

            NDDSUSERDllExport extern void 
            SqliteDatabasePeriodicPluginSupport_print_data(
                const SqliteDatabasePeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabasePeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabasePeriodic *out,
                const SqliteDatabasePeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            SqliteDatabasePeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const SqliteDatabasePeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabasePeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabasePeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            SqliteDatabasePeriodicPlugin_deserialize_from_cdr_buffer(
                SqliteDatabasePeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabasePeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            SqliteDatabasePeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabasePeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            SqliteDatabasePeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            SqliteDatabasePeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                SqliteDatabasePeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ParticipantInfoPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ParticipantInfoPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ParticipantInfoPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ParticipantInfoPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ParticipantInfoPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ParticipantInfo*
            ParticipantInfoPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ParticipantInfo*
            ParticipantInfoPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ParticipantInfo*
            ParticipantInfoPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ParticipantInfoPluginSupport_copy_data(
                ParticipantInfo *out,
                const ParticipantInfo *in);

            NDDSUSERDllExport extern void 
            ParticipantInfoPluginSupport_destroy_data_w_params(
                ParticipantInfo *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ParticipantInfoPluginSupport_destroy_data_ex(
                ParticipantInfo *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ParticipantInfoPluginSupport_destroy_data(
                ParticipantInfo *sample);

            NDDSUSERDllExport extern void 
            ParticipantInfoPluginSupport_print_data(
                const ParticipantInfo *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ParticipantInfoPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ParticipantInfo *out,
                const ParticipantInfo *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ParticipantInfoPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ParticipantInfo *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ParticipantInfoPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ParticipantInfo **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ParticipantInfoPlugin_deserialize_from_cdr_buffer(
                ParticipantInfo *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ParticipantInfoPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ParticipantInfoPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ParticipantInfoPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ParticipantInfoPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ParticipantInfoPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ParticipantInfo ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ServiceConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ServiceConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ServiceConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ServiceConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ServiceConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ServiceConfig*
            ServiceConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ServiceConfig*
            ServiceConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ServiceConfig*
            ServiceConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ServiceConfigPluginSupport_copy_data(
                ServiceConfig *out,
                const ServiceConfig *in);

            NDDSUSERDllExport extern void 
            ServiceConfigPluginSupport_destroy_data_w_params(
                ServiceConfig *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ServiceConfigPluginSupport_destroy_data_ex(
                ServiceConfig *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ServiceConfigPluginSupport_destroy_data(
                ServiceConfig *sample);

            NDDSUSERDllExport extern void 
            ServiceConfigPluginSupport_print_data(
                const ServiceConfig *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ServiceConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ServiceConfig *out,
                const ServiceConfig *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ServiceConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ServiceConfig *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ServiceConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ServiceConfig **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ServiceConfigPlugin_deserialize_from_cdr_buffer(
                ServiceConfig *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ServiceConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ServiceConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ServiceConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ServiceConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ServiceConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ServiceConfig ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ServiceEventPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ServiceEventPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ServiceEventPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ServiceEventPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ServiceEventPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ServiceEvent*
            ServiceEventPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ServiceEvent*
            ServiceEventPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ServiceEvent*
            ServiceEventPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ServiceEventPluginSupport_copy_data(
                ServiceEvent *out,
                const ServiceEvent *in);

            NDDSUSERDllExport extern void 
            ServiceEventPluginSupport_destroy_data_w_params(
                ServiceEvent *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ServiceEventPluginSupport_destroy_data_ex(
                ServiceEvent *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ServiceEventPluginSupport_destroy_data(
                ServiceEvent *sample);

            NDDSUSERDllExport extern void 
            ServiceEventPluginSupport_print_data(
                const ServiceEvent *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ServiceEventPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ServiceEvent *out,
                const ServiceEvent *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ServiceEventPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ServiceEvent *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ServiceEventPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ServiceEvent **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ServiceEventPlugin_deserialize_from_cdr_buffer(
                ServiceEvent *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ServiceEventPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ServiceEventPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ServiceEventPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ServiceEventPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ServiceEventPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ServiceEvent ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ServicePeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ServicePeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ServicePeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ServicePeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ServicePeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ServicePeriodic*
            ServicePeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ServicePeriodic*
            ServicePeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ServicePeriodic*
            ServicePeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ServicePeriodicPluginSupport_copy_data(
                ServicePeriodic *out,
                const ServicePeriodic *in);

            NDDSUSERDllExport extern void 
            ServicePeriodicPluginSupport_destroy_data_w_params(
                ServicePeriodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ServicePeriodicPluginSupport_destroy_data_ex(
                ServicePeriodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ServicePeriodicPluginSupport_destroy_data(
                ServicePeriodic *sample);

            NDDSUSERDllExport extern void 
            ServicePeriodicPluginSupport_print_data(
                const ServicePeriodic *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ServicePeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ServicePeriodic *out,
                const ServicePeriodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ServicePeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ServicePeriodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ServicePeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ServicePeriodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ServicePeriodicPlugin_deserialize_from_cdr_buffer(
                ServicePeriodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ServicePeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ServicePeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ServicePeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ServicePeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ServicePeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ServicePeriodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            #define ConfigUnionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ConfigUnionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ConfigUnionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ConfigUnionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ConfigUnionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern ConfigUnion*
            ConfigUnionPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern ConfigUnion*
            ConfigUnionPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern ConfigUnion*
            ConfigUnionPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ConfigUnionPluginSupport_copy_data(
                ConfigUnion *out,
                const ConfigUnion *in);

            NDDSUSERDllExport extern void 
            ConfigUnionPluginSupport_destroy_data_w_params(
                ConfigUnion *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ConfigUnionPluginSupport_destroy_data_ex(
                ConfigUnion *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ConfigUnionPluginSupport_destroy_data(
                ConfigUnion *sample);

            NDDSUSERDllExport extern void 
            ConfigUnionPluginSupport_print_data(
                const ConfigUnion *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            ConfigUnionPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                ConfigUnion *out,
                const ConfigUnion *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ConfigUnionPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const ConfigUnion *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ConfigUnionPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                ConfigUnion **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ConfigUnionPlugin_deserialize_from_cdr_buffer(
                ConfigUnion *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ConfigUnionPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ConfigUnionPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ConfigUnionPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ConfigUnionPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ConfigUnionPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                ConfigUnion ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            /* The type used to store keys for instances of type struct
            * AnotherSimple.
            *
            * By default, this type is struct Config
            * itself. However, if for some reason this choice is not practical for your
            * system (e.g. if sizeof(struct Config)
            * is very large), you may redefine this typedef in terms of another type of
            * your choosing. HOWEVER, if you define the KeyHolder type to be something
            * other than struct AnotherSimple, the
            * following restriction applies: the key of struct
            * Config must consist of a
            * single field of your redefined KeyHolder type and that field must be the
            * first field in struct Config.
            */
            typedef  class Config ConfigKeyHolder;

            #define ConfigPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define ConfigPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define ConfigPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define ConfigPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
            #define ConfigPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

            #define ConfigPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define ConfigPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern Config*
            ConfigPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern Config*
            ConfigPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern Config*
            ConfigPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            ConfigPluginSupport_copy_data(
                Config *out,
                const Config *in);

            NDDSUSERDllExport extern void 
            ConfigPluginSupport_destroy_data_w_params(
                Config *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            ConfigPluginSupport_destroy_data_ex(
                Config *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ConfigPluginSupport_destroy_data(
                Config *sample);

            NDDSUSERDllExport extern void 
            ConfigPluginSupport_print_data(
                const Config *sample,
                const char *desc,
                unsigned int indent);

            NDDSUSERDllExport extern Config*
            ConfigPluginSupport_create_key_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern Config*
            ConfigPluginSupport_create_key(void);

            NDDSUSERDllExport extern void 
            ConfigPluginSupport_destroy_key_ex(
                ConfigKeyHolder *key,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            ConfigPluginSupport_destroy_key(
                ConfigKeyHolder *key);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PRESTypePluginParticipantData 
            ConfigPlugin_on_participant_attached(
                void *registration_data, 
                const struct PRESTypePluginParticipantInfo *participant_info,
                RTIBool top_level_registration, 
                void *container_plugin_context,
                RTICdrTypeCode *typeCode);

            NDDSUSERDllExport extern void 
            ConfigPlugin_on_participant_detached(
                PRESTypePluginParticipantData participant_data);

            NDDSUSERDllExport extern PRESTypePluginEndpointData 
            ConfigPlugin_on_endpoint_attached(
                PRESTypePluginParticipantData participant_data,
                const struct PRESTypePluginEndpointInfo *endpoint_info,
                RTIBool top_level_registration, 
                void *container_plugin_context);

            NDDSUSERDllExport extern void 
            ConfigPlugin_on_endpoint_detached(
                PRESTypePluginEndpointData endpoint_data);

            NDDSUSERDllExport extern void    
            ConfigPlugin_return_sample(
                PRESTypePluginEndpointData endpoint_data,
                Config *sample,
                void *handle);    

            NDDSUSERDllExport extern RTIBool 
            ConfigPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                Config *out,
                const Config *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            ConfigPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const Config *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            ConfigPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                Config **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            ConfigPlugin_deserialize_from_cdr_buffer(
                Config *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            ConfigPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            ConfigPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            ConfigPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            ConfigPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            ConfigPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                Config ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool 
            ConfigPlugin_instance_to_key(
                PRESTypePluginEndpointData endpoint_data,
                ConfigKeyHolder *key, 
                const Config *instance);

            NDDSUSERDllExport extern RTIBool 
            ConfigPlugin_key_to_instance(
                PRESTypePluginEndpointData endpoint_data,
                Config *instance, 
                const ConfigKeyHolder *key);

            NDDSUSERDllExport extern RTIBool 
            ConfigPlugin_serialized_sample_to_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                struct RTICdrStream *stream, 
                DDS_KeyHash_t *keyhash,
                RTIBool deserialize_encapsulation,
                void *endpoint_plugin_qos); 

            /* Plugin Functions */
            NDDSUSERDllExport extern struct PRESTypePlugin*
            ConfigPlugin_new(void);

            NDDSUSERDllExport extern void
            ConfigPlugin_delete(struct PRESTypePlugin *);

            #define EventUnionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define EventUnionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define EventUnionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define EventUnionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define EventUnionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern EventUnion*
            EventUnionPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern EventUnion*
            EventUnionPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern EventUnion*
            EventUnionPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            EventUnionPluginSupport_copy_data(
                EventUnion *out,
                const EventUnion *in);

            NDDSUSERDllExport extern void 
            EventUnionPluginSupport_destroy_data_w_params(
                EventUnion *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            EventUnionPluginSupport_destroy_data_ex(
                EventUnion *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            EventUnionPluginSupport_destroy_data(
                EventUnion *sample);

            NDDSUSERDllExport extern void 
            EventUnionPluginSupport_print_data(
                const EventUnion *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            EventUnionPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                EventUnion *out,
                const EventUnion *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            EventUnionPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const EventUnion *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            EventUnionPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                EventUnion **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            EventUnionPlugin_deserialize_from_cdr_buffer(
                EventUnion *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            EventUnionPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            EventUnionPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            EventUnionPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            EventUnionPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            EventUnionPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                EventUnion ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            /* The type used to store keys for instances of type struct
            * AnotherSimple.
            *
            * By default, this type is struct Event
            * itself. However, if for some reason this choice is not practical for your
            * system (e.g. if sizeof(struct Event)
            * is very large), you may redefine this typedef in terms of another type of
            * your choosing. HOWEVER, if you define the KeyHolder type to be something
            * other than struct AnotherSimple, the
            * following restriction applies: the key of struct
            * Event must consist of a
            * single field of your redefined KeyHolder type and that field must be the
            * first field in struct Event.
            */
            typedef  class Event EventKeyHolder;

            #define EventPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define EventPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define EventPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define EventPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
            #define EventPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

            #define EventPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define EventPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern Event*
            EventPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern Event*
            EventPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern Event*
            EventPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            EventPluginSupport_copy_data(
                Event *out,
                const Event *in);

            NDDSUSERDllExport extern void 
            EventPluginSupport_destroy_data_w_params(
                Event *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            EventPluginSupport_destroy_data_ex(
                Event *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            EventPluginSupport_destroy_data(
                Event *sample);

            NDDSUSERDllExport extern void 
            EventPluginSupport_print_data(
                const Event *sample,
                const char *desc,
                unsigned int indent);

            NDDSUSERDllExport extern Event*
            EventPluginSupport_create_key_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern Event*
            EventPluginSupport_create_key(void);

            NDDSUSERDllExport extern void 
            EventPluginSupport_destroy_key_ex(
                EventKeyHolder *key,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            EventPluginSupport_destroy_key(
                EventKeyHolder *key);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PRESTypePluginParticipantData 
            EventPlugin_on_participant_attached(
                void *registration_data, 
                const struct PRESTypePluginParticipantInfo *participant_info,
                RTIBool top_level_registration, 
                void *container_plugin_context,
                RTICdrTypeCode *typeCode);

            NDDSUSERDllExport extern void 
            EventPlugin_on_participant_detached(
                PRESTypePluginParticipantData participant_data);

            NDDSUSERDllExport extern PRESTypePluginEndpointData 
            EventPlugin_on_endpoint_attached(
                PRESTypePluginParticipantData participant_data,
                const struct PRESTypePluginEndpointInfo *endpoint_info,
                RTIBool top_level_registration, 
                void *container_plugin_context);

            NDDSUSERDllExport extern void 
            EventPlugin_on_endpoint_detached(
                PRESTypePluginEndpointData endpoint_data);

            NDDSUSERDllExport extern void    
            EventPlugin_return_sample(
                PRESTypePluginEndpointData endpoint_data,
                Event *sample,
                void *handle);    

            NDDSUSERDllExport extern RTIBool 
            EventPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                Event *out,
                const Event *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            EventPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const Event *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            EventPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                Event **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            EventPlugin_deserialize_from_cdr_buffer(
                Event *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            EventPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            EventPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            EventPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            EventPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            EventPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                Event ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool 
            EventPlugin_instance_to_key(
                PRESTypePluginEndpointData endpoint_data,
                EventKeyHolder *key, 
                const Event *instance);

            NDDSUSERDllExport extern RTIBool 
            EventPlugin_key_to_instance(
                PRESTypePluginEndpointData endpoint_data,
                Event *instance, 
                const EventKeyHolder *key);

            NDDSUSERDllExport extern RTIBool 
            EventPlugin_serialized_sample_to_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                struct RTICdrStream *stream, 
                DDS_KeyHash_t *keyhash,
                RTIBool deserialize_encapsulation,
                void *endpoint_plugin_qos); 

            /* Plugin Functions */
            NDDSUSERDllExport extern struct PRESTypePlugin*
            EventPlugin_new(void);

            NDDSUSERDllExport extern void
            EventPlugin_delete(struct PRESTypePlugin *);

            #define PeriodicUnionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define PeriodicUnionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define PeriodicUnionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define PeriodicUnionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define PeriodicUnionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PeriodicUnion*
            PeriodicUnionPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern PeriodicUnion*
            PeriodicUnionPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern PeriodicUnion*
            PeriodicUnionPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            PeriodicUnionPluginSupport_copy_data(
                PeriodicUnion *out,
                const PeriodicUnion *in);

            NDDSUSERDllExport extern void 
            PeriodicUnionPluginSupport_destroy_data_w_params(
                PeriodicUnion *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            PeriodicUnionPluginSupport_destroy_data_ex(
                PeriodicUnion *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            PeriodicUnionPluginSupport_destroy_data(
                PeriodicUnion *sample);

            NDDSUSERDllExport extern void 
            PeriodicUnionPluginSupport_print_data(
                const PeriodicUnion *sample,
                const char *desc,
                unsigned int indent);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool 
            PeriodicUnionPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                PeriodicUnion *out,
                const PeriodicUnion *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            PeriodicUnionPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const PeriodicUnion *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            PeriodicUnionPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                PeriodicUnion **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            PeriodicUnionPlugin_deserialize_from_cdr_buffer(
                PeriodicUnion *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            PeriodicUnionPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            PeriodicUnionPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            PeriodicUnionPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            PeriodicUnionPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            PeriodicUnionPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                PeriodicUnion ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            /* The type used to store keys for instances of type struct
            * AnotherSimple.
            *
            * By default, this type is struct Periodic
            * itself. However, if for some reason this choice is not practical for your
            * system (e.g. if sizeof(struct Periodic)
            * is very large), you may redefine this typedef in terms of another type of
            * your choosing. HOWEVER, if you define the KeyHolder type to be something
            * other than struct AnotherSimple, the
            * following restriction applies: the key of struct
            * Periodic must consist of a
            * single field of your redefined KeyHolder type and that field must be the
            * first field in struct Periodic.
            */
            typedef  class Periodic PeriodicKeyHolder;

            #define PeriodicPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

            #define PeriodicPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
            #define PeriodicPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

            #define PeriodicPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
            #define PeriodicPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

            #define PeriodicPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
            #define PeriodicPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

            /* --------------------------------------------------------------------------------------
            Support functions:
            * -------------------------------------------------------------------------------------- */

            NDDSUSERDllExport extern Periodic*
            PeriodicPluginSupport_create_data_w_params(
                const struct DDS_TypeAllocationParams_t * alloc_params);

            NDDSUSERDllExport extern Periodic*
            PeriodicPluginSupport_create_data_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern Periodic*
            PeriodicPluginSupport_create_data(void);

            NDDSUSERDllExport extern RTIBool 
            PeriodicPluginSupport_copy_data(
                Periodic *out,
                const Periodic *in);

            NDDSUSERDllExport extern void 
            PeriodicPluginSupport_destroy_data_w_params(
                Periodic *sample,
                const struct DDS_TypeDeallocationParams_t * dealloc_params);

            NDDSUSERDllExport extern void 
            PeriodicPluginSupport_destroy_data_ex(
                Periodic *sample,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            PeriodicPluginSupport_destroy_data(
                Periodic *sample);

            NDDSUSERDllExport extern void 
            PeriodicPluginSupport_print_data(
                const Periodic *sample,
                const char *desc,
                unsigned int indent);

            NDDSUSERDllExport extern Periodic*
            PeriodicPluginSupport_create_key_ex(RTIBool allocate_pointers);

            NDDSUSERDllExport extern Periodic*
            PeriodicPluginSupport_create_key(void);

            NDDSUSERDllExport extern void 
            PeriodicPluginSupport_destroy_key_ex(
                PeriodicKeyHolder *key,RTIBool deallocate_pointers);

            NDDSUSERDllExport extern void 
            PeriodicPluginSupport_destroy_key(
                PeriodicKeyHolder *key);

            /* ----------------------------------------------------------------------------
            Callback functions:
            * ---------------------------------------------------------------------------- */

            NDDSUSERDllExport extern PRESTypePluginParticipantData 
            PeriodicPlugin_on_participant_attached(
                void *registration_data, 
                const struct PRESTypePluginParticipantInfo *participant_info,
                RTIBool top_level_registration, 
                void *container_plugin_context,
                RTICdrTypeCode *typeCode);

            NDDSUSERDllExport extern void 
            PeriodicPlugin_on_participant_detached(
                PRESTypePluginParticipantData participant_data);

            NDDSUSERDllExport extern PRESTypePluginEndpointData 
            PeriodicPlugin_on_endpoint_attached(
                PRESTypePluginParticipantData participant_data,
                const struct PRESTypePluginEndpointInfo *endpoint_info,
                RTIBool top_level_registration, 
                void *container_plugin_context);

            NDDSUSERDllExport extern void 
            PeriodicPlugin_on_endpoint_detached(
                PRESTypePluginEndpointData endpoint_data);

            NDDSUSERDllExport extern void    
            PeriodicPlugin_return_sample(
                PRESTypePluginEndpointData endpoint_data,
                Periodic *sample,
                void *handle);    

            NDDSUSERDllExport extern RTIBool 
            PeriodicPlugin_copy_sample(
                PRESTypePluginEndpointData endpoint_data,
                Periodic *out,
                const Periodic *in);

            /* ----------------------------------------------------------------------------
            (De)Serialize functions:
            * ------------------------------------------------------------------------- */

            NDDSUSERDllExport extern RTIBool
            PeriodicPlugin_serialize_to_cdr_buffer(
                char * buffer,
                unsigned int * length,
                const Periodic *sample,
                ::dds::core::policy::DataRepresentationId representation
                = ::dds::core::policy::DataRepresentation::xcdr()); 

            NDDSUSERDllExport extern RTIBool 
            PeriodicPlugin_deserialize(
                PRESTypePluginEndpointData endpoint_data,
                Periodic **sample, 
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_sample, 
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool
            PeriodicPlugin_deserialize_from_cdr_buffer(
                Periodic *sample,
                const char * buffer,
                unsigned int length);    

            NDDSUSERDllExport extern unsigned int 
            PeriodicPlugin_get_serialized_sample_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            /* --------------------------------------------------------------------------------------
            Key Management functions:
            * -------------------------------------------------------------------------------------- */
            NDDSUSERDllExport extern PRESTypePluginKeyKind 
            PeriodicPlugin_get_key_kind(void);

            NDDSUSERDllExport extern unsigned int 
            PeriodicPlugin_get_serialized_key_max_size(
                PRESTypePluginEndpointData endpoint_data,
                RTIBool include_encapsulation,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern unsigned int 
            PeriodicPlugin_get_serialized_key_max_size_for_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                RTIEncapsulationId encapsulation_id,
                unsigned int current_alignment);

            NDDSUSERDllExport extern RTIBool 
            PeriodicPlugin_deserialize_key(
                PRESTypePluginEndpointData endpoint_data,
                Periodic ** sample,
                RTIBool * drop_sample,
                struct RTICdrStream *stream,
                RTIBool deserialize_encapsulation,
                RTIBool deserialize_key,
                void *endpoint_plugin_qos);

            NDDSUSERDllExport extern RTIBool 
            PeriodicPlugin_instance_to_key(
                PRESTypePluginEndpointData endpoint_data,
                PeriodicKeyHolder *key, 
                const Periodic *instance);

            NDDSUSERDllExport extern RTIBool 
            PeriodicPlugin_key_to_instance(
                PRESTypePluginEndpointData endpoint_data,
                Periodic *instance, 
                const PeriodicKeyHolder *key);

            NDDSUSERDllExport extern RTIBool 
            PeriodicPlugin_serialized_sample_to_keyhash(
                PRESTypePluginEndpointData endpoint_data,
                struct RTICdrStream *stream, 
                DDS_KeyHash_t *keyhash,
                RTIBool deserialize_encapsulation,
                void *endpoint_plugin_qos); 

            /* Plugin Functions */
            NDDSUSERDllExport extern struct PRESTypePlugin*
            PeriodicPlugin_new(void);

            NDDSUSERDllExport extern void
            PeriodicPlugin_delete(struct PRESTypePlugin *);

        } /* namespace Monitoring  */
    } /* namespace RecordingService  */
} /* namespace RTI  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_MONITORING)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* RecordingServiceMonitoringPlugin_741490610_h */

