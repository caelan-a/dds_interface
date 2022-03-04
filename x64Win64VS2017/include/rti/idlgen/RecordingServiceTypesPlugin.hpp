

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from RecordingServiceTypes.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef RecordingServiceTypesPlugin_164879633_h
#define RecordingServiceTypesPlugin_164879633_h

#include "RecordingServiceTypes.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace RTI {
    namespace RecordingService {

        #define DataTagParamsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define DataTagParamsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define DataTagParamsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define DataTagParamsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define DataTagParamsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern DataTagParams*
        DataTagParamsPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern DataTagParams*
        DataTagParamsPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern DataTagParams*
        DataTagParamsPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        DataTagParamsPluginSupport_copy_data(
            DataTagParams *out,
            const DataTagParams *in);

        NDDSUSERDllExport extern void 
        DataTagParamsPluginSupport_destroy_data_w_params(
            DataTagParams *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        DataTagParamsPluginSupport_destroy_data_ex(
            DataTagParams *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        DataTagParamsPluginSupport_destroy_data(
            DataTagParams *sample);

        NDDSUSERDllExport extern void 
        DataTagParamsPluginSupport_print_data(
            const DataTagParams *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern PRESTypePluginParticipantData 
        DataTagParamsPlugin_on_participant_attached(
            void *registration_data, 
            const struct PRESTypePluginParticipantInfo *participant_info,
            RTIBool top_level_registration, 
            void *container_plugin_context,
            RTICdrTypeCode *typeCode);

        NDDSUSERDllExport extern void 
        DataTagParamsPlugin_on_participant_detached(
            PRESTypePluginParticipantData participant_data);

        NDDSUSERDllExport extern PRESTypePluginEndpointData 
        DataTagParamsPlugin_on_endpoint_attached(
            PRESTypePluginParticipantData participant_data,
            const struct PRESTypePluginEndpointInfo *endpoint_info,
            RTIBool top_level_registration, 
            void *container_plugin_context);

        NDDSUSERDllExport extern void 
        DataTagParamsPlugin_on_endpoint_detached(
            PRESTypePluginEndpointData endpoint_data);

        NDDSUSERDllExport extern void    
        DataTagParamsPlugin_return_sample(
            PRESTypePluginEndpointData endpoint_data,
            DataTagParams *sample,
            void *handle);    

        NDDSUSERDllExport extern RTIBool 
        DataTagParamsPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            DataTagParams *out,
            const DataTagParams *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        DataTagParamsPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const DataTagParams *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        DataTagParamsPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            DataTagParams **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        DataTagParamsPlugin_deserialize_from_cdr_buffer(
            DataTagParams *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        DataTagParamsPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        DataTagParamsPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        DataTagParamsPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        DataTagParamsPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        DataTagParamsPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            DataTagParams ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        /* Plugin Functions */
        NDDSUSERDllExport extern struct PRESTypePlugin*
        DataTagParamsPlugin_new(void);

        NDDSUSERDllExport extern void
        DataTagParamsPlugin_delete(struct PRESTypePlugin *);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        BreakpointFormatPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        BreakpointFormatPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        BreakpointFormatPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* ----------------------------------------------------------------------------
        Support functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern void
        BreakpointFormatPluginSupport_print_data(
            const BreakpointFormat *sample, const char *desc, int indent_level);

        #define BreakpointUnionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define BreakpointUnionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define BreakpointUnionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define BreakpointUnionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define BreakpointUnionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern BreakpointUnion*
        BreakpointUnionPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern BreakpointUnion*
        BreakpointUnionPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern BreakpointUnion*
        BreakpointUnionPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        BreakpointUnionPluginSupport_copy_data(
            BreakpointUnion *out,
            const BreakpointUnion *in);

        NDDSUSERDllExport extern void 
        BreakpointUnionPluginSupport_destroy_data_w_params(
            BreakpointUnion *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        BreakpointUnionPluginSupport_destroy_data_ex(
            BreakpointUnion *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        BreakpointUnionPluginSupport_destroy_data(
            BreakpointUnion *sample);

        NDDSUSERDllExport extern void 
        BreakpointUnionPluginSupport_print_data(
            const BreakpointUnion *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool 
        BreakpointUnionPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            BreakpointUnion *out,
            const BreakpointUnion *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        BreakpointUnionPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const BreakpointUnion *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        BreakpointUnionPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            BreakpointUnion **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        BreakpointUnionPlugin_deserialize_from_cdr_buffer(
            BreakpointUnion *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        BreakpointUnionPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        BreakpointUnionPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        BreakpointUnionPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        BreakpointUnionPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        BreakpointUnionPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            BreakpointUnion ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        #define BreakpointParamsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define BreakpointParamsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define BreakpointParamsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define BreakpointParamsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define BreakpointParamsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern BreakpointParams*
        BreakpointParamsPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern BreakpointParams*
        BreakpointParamsPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern BreakpointParams*
        BreakpointParamsPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        BreakpointParamsPluginSupport_copy_data(
            BreakpointParams *out,
            const BreakpointParams *in);

        NDDSUSERDllExport extern void 
        BreakpointParamsPluginSupport_destroy_data_w_params(
            BreakpointParams *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        BreakpointParamsPluginSupport_destroy_data_ex(
            BreakpointParams *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        BreakpointParamsPluginSupport_destroy_data(
            BreakpointParams *sample);

        NDDSUSERDllExport extern void 
        BreakpointParamsPluginSupport_print_data(
            const BreakpointParams *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern PRESTypePluginParticipantData 
        BreakpointParamsPlugin_on_participant_attached(
            void *registration_data, 
            const struct PRESTypePluginParticipantInfo *participant_info,
            RTIBool top_level_registration, 
            void *container_plugin_context,
            RTICdrTypeCode *typeCode);

        NDDSUSERDllExport extern void 
        BreakpointParamsPlugin_on_participant_detached(
            PRESTypePluginParticipantData participant_data);

        NDDSUSERDllExport extern PRESTypePluginEndpointData 
        BreakpointParamsPlugin_on_endpoint_attached(
            PRESTypePluginParticipantData participant_data,
            const struct PRESTypePluginEndpointInfo *endpoint_info,
            RTIBool top_level_registration, 
            void *container_plugin_context);

        NDDSUSERDllExport extern void 
        BreakpointParamsPlugin_on_endpoint_detached(
            PRESTypePluginEndpointData endpoint_data);

        NDDSUSERDllExport extern void    
        BreakpointParamsPlugin_return_sample(
            PRESTypePluginEndpointData endpoint_data,
            BreakpointParams *sample,
            void *handle);    

        NDDSUSERDllExport extern RTIBool 
        BreakpointParamsPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            BreakpointParams *out,
            const BreakpointParams *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        BreakpointParamsPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const BreakpointParams *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        BreakpointParamsPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            BreakpointParams **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        BreakpointParamsPlugin_deserialize_from_cdr_buffer(
            BreakpointParams *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        BreakpointParamsPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        BreakpointParamsPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        BreakpointParamsPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        BreakpointParamsPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        BreakpointParamsPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            BreakpointParams ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        /* Plugin Functions */
        NDDSUSERDllExport extern struct PRESTypePlugin*
        BreakpointParamsPlugin_new(void);

        NDDSUSERDllExport extern void
        BreakpointParamsPlugin_delete(struct PRESTypePlugin *);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        ContinueFormatPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        ContinueFormatPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        ContinueFormatPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* ----------------------------------------------------------------------------
        Support functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern void
        ContinueFormatPluginSupport_print_data(
            const ContinueFormat *sample, const char *desc, int indent_level);

        #define ContinueUnionPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define ContinueUnionPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define ContinueUnionPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define ContinueUnionPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define ContinueUnionPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern ContinueUnion*
        ContinueUnionPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern ContinueUnion*
        ContinueUnionPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern ContinueUnion*
        ContinueUnionPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        ContinueUnionPluginSupport_copy_data(
            ContinueUnion *out,
            const ContinueUnion *in);

        NDDSUSERDllExport extern void 
        ContinueUnionPluginSupport_destroy_data_w_params(
            ContinueUnion *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        ContinueUnionPluginSupport_destroy_data_ex(
            ContinueUnion *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        ContinueUnionPluginSupport_destroy_data(
            ContinueUnion *sample);

        NDDSUSERDllExport extern void 
        ContinueUnionPluginSupport_print_data(
            const ContinueUnion *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool 
        ContinueUnionPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            ContinueUnion *out,
            const ContinueUnion *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        ContinueUnionPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const ContinueUnion *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        ContinueUnionPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            ContinueUnion **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        ContinueUnionPlugin_deserialize_from_cdr_buffer(
            ContinueUnion *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        ContinueUnionPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        ContinueUnionPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        ContinueUnionPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        ContinueUnionPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        ContinueUnionPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            ContinueUnion ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        #define ContinueParamsPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define ContinueParamsPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define ContinueParamsPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define ContinueParamsPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define ContinueParamsPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern ContinueParams*
        ContinueParamsPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern ContinueParams*
        ContinueParamsPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern ContinueParams*
        ContinueParamsPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        ContinueParamsPluginSupport_copy_data(
            ContinueParams *out,
            const ContinueParams *in);

        NDDSUSERDllExport extern void 
        ContinueParamsPluginSupport_destroy_data_w_params(
            ContinueParams *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        ContinueParamsPluginSupport_destroy_data_ex(
            ContinueParams *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        ContinueParamsPluginSupport_destroy_data(
            ContinueParams *sample);

        NDDSUSERDllExport extern void 
        ContinueParamsPluginSupport_print_data(
            const ContinueParams *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern PRESTypePluginParticipantData 
        ContinueParamsPlugin_on_participant_attached(
            void *registration_data, 
            const struct PRESTypePluginParticipantInfo *participant_info,
            RTIBool top_level_registration, 
            void *container_plugin_context,
            RTICdrTypeCode *typeCode);

        NDDSUSERDllExport extern void 
        ContinueParamsPlugin_on_participant_detached(
            PRESTypePluginParticipantData participant_data);

        NDDSUSERDllExport extern PRESTypePluginEndpointData 
        ContinueParamsPlugin_on_endpoint_attached(
            PRESTypePluginParticipantData participant_data,
            const struct PRESTypePluginEndpointInfo *endpoint_info,
            RTIBool top_level_registration, 
            void *container_plugin_context);

        NDDSUSERDllExport extern void 
        ContinueParamsPlugin_on_endpoint_detached(
            PRESTypePluginEndpointData endpoint_data);

        NDDSUSERDllExport extern void    
        ContinueParamsPlugin_return_sample(
            PRESTypePluginEndpointData endpoint_data,
            ContinueParams *sample,
            void *handle);    

        NDDSUSERDllExport extern RTIBool 
        ContinueParamsPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            ContinueParams *out,
            const ContinueParams *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        ContinueParamsPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const ContinueParams *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        ContinueParamsPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            ContinueParams **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        ContinueParamsPlugin_deserialize_from_cdr_buffer(
            ContinueParams *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        ContinueParamsPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        ContinueParamsPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        ContinueParamsPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        ContinueParamsPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        ContinueParamsPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            ContinueParams ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        /* Plugin Functions */
        NDDSUSERDllExport extern struct PRESTypePlugin*
        ContinueParamsPlugin_new(void);

        NDDSUSERDllExport extern void
        ContinueParamsPlugin_delete(struct PRESTypePlugin *);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        TimerStatePlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern unsigned int 
        TimerStatePlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        TimerStatePlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* ----------------------------------------------------------------------------
        Support functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern void
        TimerStatePluginSupport_print_data(
            const TimerState *sample, const char *desc, int indent_level);

        #define DebugStatusPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define DebugStatusPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define DebugStatusPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define DebugStatusPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define DebugStatusPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern DebugStatus*
        DebugStatusPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern DebugStatus*
        DebugStatusPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern DebugStatus*
        DebugStatusPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        DebugStatusPluginSupport_copy_data(
            DebugStatus *out,
            const DebugStatus *in);

        NDDSUSERDllExport extern void 
        DebugStatusPluginSupport_destroy_data_w_params(
            DebugStatus *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        DebugStatusPluginSupport_destroy_data_ex(
            DebugStatus *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        DebugStatusPluginSupport_destroy_data(
            DebugStatus *sample);

        NDDSUSERDllExport extern void 
        DebugStatusPluginSupport_print_data(
            const DebugStatus *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern PRESTypePluginParticipantData 
        DebugStatusPlugin_on_participant_attached(
            void *registration_data, 
            const struct PRESTypePluginParticipantInfo *participant_info,
            RTIBool top_level_registration, 
            void *container_plugin_context,
            RTICdrTypeCode *typeCode);

        NDDSUSERDllExport extern void 
        DebugStatusPlugin_on_participant_detached(
            PRESTypePluginParticipantData participant_data);

        NDDSUSERDllExport extern PRESTypePluginEndpointData 
        DebugStatusPlugin_on_endpoint_attached(
            PRESTypePluginParticipantData participant_data,
            const struct PRESTypePluginEndpointInfo *endpoint_info,
            RTIBool top_level_registration, 
            void *container_plugin_context);

        NDDSUSERDllExport extern void 
        DebugStatusPlugin_on_endpoint_detached(
            PRESTypePluginEndpointData endpoint_data);

        NDDSUSERDllExport extern void    
        DebugStatusPlugin_return_sample(
            PRESTypePluginEndpointData endpoint_data,
            DebugStatus *sample,
            void *handle);    

        NDDSUSERDllExport extern RTIBool 
        DebugStatusPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            DebugStatus *out,
            const DebugStatus *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        DebugStatusPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const DebugStatus *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        DebugStatusPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            DebugStatus **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        DebugStatusPlugin_deserialize_from_cdr_buffer(
            DebugStatus *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        DebugStatusPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        DebugStatusPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        DebugStatusPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        DebugStatusPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        DebugStatusPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            DebugStatus ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        /* Plugin Functions */
        NDDSUSERDllExport extern struct PRESTypePlugin*
        DebugStatusPlugin_new(void);

        NDDSUSERDllExport extern void
        DebugStatusPlugin_delete(struct PRESTypePlugin *);

        #define TimestampHolderPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

        #define TimestampHolderPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
        #define TimestampHolderPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

        #define TimestampHolderPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
        #define TimestampHolderPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

        /* --------------------------------------------------------------------------------------
        Support functions:
        * -------------------------------------------------------------------------------------- */

        NDDSUSERDllExport extern TimestampHolder*
        TimestampHolderPluginSupport_create_data_w_params(
            const struct DDS_TypeAllocationParams_t * alloc_params);

        NDDSUSERDllExport extern TimestampHolder*
        TimestampHolderPluginSupport_create_data_ex(RTIBool allocate_pointers);

        NDDSUSERDllExport extern TimestampHolder*
        TimestampHolderPluginSupport_create_data(void);

        NDDSUSERDllExport extern RTIBool 
        TimestampHolderPluginSupport_copy_data(
            TimestampHolder *out,
            const TimestampHolder *in);

        NDDSUSERDllExport extern void 
        TimestampHolderPluginSupport_destroy_data_w_params(
            TimestampHolder *sample,
            const struct DDS_TypeDeallocationParams_t * dealloc_params);

        NDDSUSERDllExport extern void 
        TimestampHolderPluginSupport_destroy_data_ex(
            TimestampHolder *sample,RTIBool deallocate_pointers);

        NDDSUSERDllExport extern void 
        TimestampHolderPluginSupport_destroy_data(
            TimestampHolder *sample);

        NDDSUSERDllExport extern void 
        TimestampHolderPluginSupport_print_data(
            const TimestampHolder *sample,
            const char *desc,
            unsigned int indent);

        /* ----------------------------------------------------------------------------
        Callback functions:
        * ---------------------------------------------------------------------------- */

        NDDSUSERDllExport extern PRESTypePluginParticipantData 
        TimestampHolderPlugin_on_participant_attached(
            void *registration_data, 
            const struct PRESTypePluginParticipantInfo *participant_info,
            RTIBool top_level_registration, 
            void *container_plugin_context,
            RTICdrTypeCode *typeCode);

        NDDSUSERDllExport extern void 
        TimestampHolderPlugin_on_participant_detached(
            PRESTypePluginParticipantData participant_data);

        NDDSUSERDllExport extern PRESTypePluginEndpointData 
        TimestampHolderPlugin_on_endpoint_attached(
            PRESTypePluginParticipantData participant_data,
            const struct PRESTypePluginEndpointInfo *endpoint_info,
            RTIBool top_level_registration, 
            void *container_plugin_context);

        NDDSUSERDllExport extern void 
        TimestampHolderPlugin_on_endpoint_detached(
            PRESTypePluginEndpointData endpoint_data);

        NDDSUSERDllExport extern void    
        TimestampHolderPlugin_return_sample(
            PRESTypePluginEndpointData endpoint_data,
            TimestampHolder *sample,
            void *handle);    

        NDDSUSERDllExport extern RTIBool 
        TimestampHolderPlugin_copy_sample(
            PRESTypePluginEndpointData endpoint_data,
            TimestampHolder *out,
            const TimestampHolder *in);

        /* ----------------------------------------------------------------------------
        (De)Serialize functions:
        * ------------------------------------------------------------------------- */

        NDDSUSERDllExport extern RTIBool
        TimestampHolderPlugin_serialize_to_cdr_buffer(
            char * buffer,
            unsigned int * length,
            const TimestampHolder *sample,
            ::dds::core::policy::DataRepresentationId representation
            = ::dds::core::policy::DataRepresentation::xcdr()); 

        NDDSUSERDllExport extern RTIBool 
        TimestampHolderPlugin_deserialize(
            PRESTypePluginEndpointData endpoint_data,
            TimestampHolder **sample, 
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_sample, 
            void *endpoint_plugin_qos);

        NDDSUSERDllExport extern RTIBool
        TimestampHolderPlugin_deserialize_from_cdr_buffer(
            TimestampHolder *sample,
            const char * buffer,
            unsigned int length);    

        NDDSUSERDllExport extern unsigned int 
        TimestampHolderPlugin_get_serialized_sample_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        /* --------------------------------------------------------------------------------------
        Key Management functions:
        * -------------------------------------------------------------------------------------- */
        NDDSUSERDllExport extern PRESTypePluginKeyKind 
        TimestampHolderPlugin_get_key_kind(void);

        NDDSUSERDllExport extern unsigned int 
        TimestampHolderPlugin_get_serialized_key_max_size(
            PRESTypePluginEndpointData endpoint_data,
            RTIBool include_encapsulation,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern unsigned int 
        TimestampHolderPlugin_get_serialized_key_max_size_for_keyhash(
            PRESTypePluginEndpointData endpoint_data,
            RTIEncapsulationId encapsulation_id,
            unsigned int current_alignment);

        NDDSUSERDllExport extern RTIBool 
        TimestampHolderPlugin_deserialize_key(
            PRESTypePluginEndpointData endpoint_data,
            TimestampHolder ** sample,
            RTIBool * drop_sample,
            struct RTICdrStream *stream,
            RTIBool deserialize_encapsulation,
            RTIBool deserialize_key,
            void *endpoint_plugin_qos);

        /* Plugin Functions */
        NDDSUSERDllExport extern struct PRESTypePlugin*
        TimestampHolderPlugin_new(void);

        NDDSUSERDllExport extern void
        TimestampHolderPlugin_delete(struct PRESTypePlugin *);

    } /* namespace RecordingService  */
} /* namespace RTI  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT_RECORDER_SERVICE_ADMINISTRATION)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* RecordingServiceTypesPlugin_164879633_h */

