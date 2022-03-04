/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)routingservice_infrastructure.h    generated by: makeheader    Fri Apr 23 01:06:18 2021
 *
 *		built from:	infrastructure.ifc
 */

#ifndef routingservice_infrastructure_h
#define routingservice_infrastructure_h


  #ifndef routingservice_dll_h
  #include "routingservice/routingservice_dll.h"
  #endif

  #ifndef dds_c_infrastructure_h
      #include "dds_c/dds_c_infrastructure.h"
  #endif
  #ifdef __cplusplus
      extern "C" {
  #endif


#if (defined(RTI_WIN32) || defined(RTI_INTIME))
#undef RTI_USER_DLL_EXPORT
#define RTI_USER_DLL_EXPORT __declspec(dllexport)
#else
#define RTI_USER_DLL_EXPORT
#endif


#define RTI_ROUTING_SERVICE_VERSION {6,1,0,0}


#define RTI_UNUSED_PARAMETER(x) (void)(x)


struct RTI_RoutingServiceNameValue {
    /*e @brief Property name */
    char * name;
    /*e @brief Property value */
    void * value;
};


struct RTI_RoutingServiceProperties {
    /*e @brief Array of configuration properties. */
    struct RTI_RoutingServiceNameValue * properties;
    /*e @brief Number of properties in the array. */
    int count;
    /*e @brief A non-zero value indicates that all the values of the
        properties are strings (char *) */
    DDS_Boolean string_values;
};

extern ROUTERDllExport
const char * RTI_RoutingServiceProperties_lookup_property(
    const struct RTI_RoutingServiceProperties * self,
    const char * name);

extern ROUTERDllExport
const char * RTI_RoutingServiceProperties_lookup_property_with_prefix(
        const struct RTI_RoutingServiceProperties * self,
        const char *prefix,
        const char *name);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingServiceProperties_add(
        struct RTI_RoutingServiceProperties *self,
        const char *name,
        const char *value);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingServiceProperties_assert(
        struct RTI_RoutingServiceProperties *self,
        const char *name,
        const char *value);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingServiceProperties_equals(
        const struct RTI_RoutingServiceProperties *left,
        const struct RTI_RoutingServiceProperties *right);

extern ROUTERDllExport
const struct RTI_RoutingServiceProperties *
RTI_RoutingServiceProperties_copy(
        struct RTI_RoutingServiceProperties *self,
        const struct RTI_RoutingServiceProperties *other);

extern ROUTERDllExport
void RTI_RoutingServiceProperties_finalize(
        struct RTI_RoutingServiceProperties *self);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingServiceProperties_initialize(
    struct RTI_RoutingServiceProperties *self);


#define RTI_ROUTING_SERVICE_OK 0


#define RTI_ROUTING_SERVICE_ERROR 1


#define RTI_ROUTING_SERVICE_ERROR_MAX_LENGTH 1024


struct RTI_RoutingServiceEnvironmentImpl;


typedef struct RTI_RoutingServiceEnvironmentImpl RTI_RoutingServiceEnvironment;


struct RTI_RoutingServiceVersion {
    /*e
     * @brief Major version number
     */
    int major;
    /*e
     * @brief Minor version number
     */
    int minor;
    /*e
     * @brief Release version number
     */
    int release;
    /*e
     * @brief Revision of a release
     */
    int revision;
};


typedef enum {
    /*e
     * No logging (-verbosity 0)
     */
    RTI_ROUTING_SERVICE_VERBOSITY_NONE = 0,
    /*e
     * Exceptions (-verbosity 1)
     */
    RTI_ROUTING_SERVICE_VERBOSITY_EXCEPTION,
    /*e
     * Warnings (-verbosity 2)
     */
    RTI_ROUTING_SERVICE_VERBOSITY_WARN,
    /*e
     * Information (-verbosity 3)
     */
    RTI_ROUTING_SERVICE_VERBOSITY_INFO,
    /*e
     * Debug information (-verbosity 5 and 6)
     */
    RTI_ROUTING_SERVICE_VERBOSITY_DEBUG
} RTI_RoutingServiceVerbosity;

extern ROUTERDllExport
void RTI_RoutingServiceEnvironment_set_error_w_params(
        RTI_RoutingServiceEnvironment * self,
        int overwrite,
        int error_code,
        int native_error_code,
        const char * error_format, ...);

extern ROUTERDllExport
void RTI_RoutingServiceEnvironment_set_error(
        RTI_RoutingServiceEnvironment * self,
        const char * error_format, ...);

extern ROUTERDllExport
void RTI_RoutingServiceEnvironment_clear_error(
        RTI_RoutingServiceEnvironment * self);

extern ROUTERDllExport
RTI_RoutingServiceVerbosity
RTI_RoutingServiceEnvironment_get_verbosity(
        const RTI_RoutingServiceEnvironment * self);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingServiceEnvironment_error_occurred(
        const RTI_RoutingServiceEnvironment * self);

extern ROUTERDllExport
const char * RTI_RoutingServiceEnvironment_get_error_message(
        const RTI_RoutingServiceEnvironment * self);

extern ROUTERDllExport
int RTI_RoutingServiceEnvironment_get_native_code(
        const RTI_RoutingServiceEnvironment * self);

extern ROUTERDllExport
int RTI_RoutingServiceVersion_compare(
        const struct RTI_RoutingServiceVersion *left,
        const struct RTI_RoutingServiceVersion *right);


#define RTI_ROUTING_SERVICE_TYPE_REPRESENTATION_DYNAMIC_TYPE 0


#define RTI_ROUTING_SERVICE_TYPE_REPRESENTATION_XML 1


#define RTI_ROUTING_SERVICE_TYPE_REPRESENTATION_JAVA_OBJECT 2


#define RTI_ROUTING_SERVICE_TYPE_REPRESENTATION_FIRST_CUSTOM_REPRESENTATION 100


#define RTI_ROUTING_SERVICE_DATA_REPRESENTATION_DYNAMIC_DATA 0


#define RTI_ROUTING_SERVICE_DATA_REPRESENTATION_XML 1


#define RTI_ROUTING_SERVICE_DATA_REPRESENTATION_JAVA_OBJECT 2


#define RTI_ROUTING_SERVICE_DATA_REPRESENTATION_FIRST_CUSTOM_REPRESENTATION 100


typedef int RTI_RoutingServiceTypeRepresentationKind;


typedef void * RTI_RoutingServiceTypeRepresentation;


struct RTI_RoutingServiceTypeInfo {
    /*e \dref_TypeInfo_type_name */
    char * type_name;
    /*e \dref_TypeInfo_representation_kind */
    RTI_RoutingServiceTypeRepresentationKind type_representation_kind;
    /*e \dref_TypeInfo_type_representation */
    RTI_RoutingServiceTypeRepresentation type_representation;
};


typedef int RTI_RoutingServiceDataRepresentationKind;


typedef void * RTI_RoutingServiceSample;


typedef void * RTI_RoutingServiceSampleInfo;


struct RTI_RoutingServiceStringSeq {
    /*e @brief Array of elements. */
    char ** element_array;
    /*e @brief Number of elements in the array. */
    int element_count;
    /*e @brief maximum capacity of the array. */
    int element_count_max;
};


#define RTI_RoutingServiceStringSeq_INITIALIZER \
    {NULL, 0, 0}

extern ROUTERDllExport
struct RTI_RoutingServiceStringSeq *
RTI_RoutingServiceStringSeq_copy(
        struct RTI_RoutingServiceStringSeq *self,
        struct RTI_RoutingServiceStringSeq *other);


struct RTI_RoutingServiceStreamInfo {
    /*e \dref_StreamInfo_stream_name
    */
    char * stream_name;
    /*e \dref_StreamInfo_type_info
     */
    struct RTI_RoutingServiceTypeInfo type_info;
    /*i
     *
     * @brief Internal use only
    */
    struct RTI_RoutingServiceStringSeq partition;
   /*e \dref_StreamInfo_disposed
    */
    DDS_Boolean disposed;
};


#define RTI_RoutingServiceStreamInfo_INITIALIZER {\
    NULL, \
    {NULL, 0, NULL},\
    RTI_RoutingServiceStringSeq_INITIALIZER, \
    DDS_BOOLEAN_FALSE \
}

extern ROUTERDllExport
void RTI_RoutingServiceStreamInfo_finalize(
        struct RTI_RoutingServiceStreamInfo *self);

extern ROUTERDllExport
DDS_Boolean RTI_RoutingServiceStreamInfo_initialize(
        struct RTI_RoutingServiceStreamInfo *self,
        DDS_Boolean is_disposed_stream,
        const char *stream_name,
        const char *ed_type_name,
        int type_dfinition_format,
        RTI_RoutingServiceTypeRepresentation type_definition);

extern ROUTERDllExport
struct RTI_RoutingServiceStreamInfo *
RTI_RoutingServiceStreamInfo_new_discovered(
    const char * stream_name,
    const char * ed_type_name,
    RTI_RoutingServiceTypeRepresentationKind type_representation_kind,
    RTI_RoutingServiceTypeRepresentation type_representation);

extern ROUTERDllExport
struct RTI_RoutingServiceStreamInfo *
RTI_RoutingServiceStreamInfo_new_disposed(
    const char * stream_name);

extern ROUTERDllExport
void RTI_RoutingServiceStreamInfo_delete(
    struct RTI_RoutingServiceStreamInfo * self);



#define RTI_ROUTING_SERVICE_PROPERTY_PREFIX \
    "rti.routing_service"

/*e \ingroup RTI_RoutingServiceInfrastructureModule
 *
 * @brief Name of the property that provides the @product given application name
 *
 */
#define  RTI_ROUTING_SERVICE_APP_NAME_PROPERTY_NAME \
        RTI_ROUTING_SERVICE_PROPERTY_PREFIX".app_name"

/*e \ingroup RTI_RoutingServiceInfrastructureModule
 *
 * Name of the property that provides the configured group name.
 *
 */
#define  RTI_ROUTING_SERVICE_GROUP_PROPERTY_NAME \
        RTI_ROUTING_SERVICE_PROPERTY_PREFIX".group_name"

/*e \ingroup RTI_RoutingServiceInfrastructureModule
 *
 * @brief Name of the property that provides the @product version as string.
 *
 */
#define  RTI_ROUTING_SERVICE_VERSION_PROPERTY_NAME \
        RTI_ROUTING_SERVICE_PROPERTY_PREFIX".version"

/*e \ingroup RTI_RoutingServiceInfrastructureModule
 *
 * @brief  Name of the property that provides verbosity in use by @product.
 *
 * It can take on of the following stings:
 *      - NONE
 *      - EXCEPTION
 *      - WARN
 *      - INFO
 *      - DEBUG.
 *
 */
#define  RTI_ROUTING_SERVICE_VERBOSITY_PROPERTY_NAME \
        RTI_ROUTING_SERVICE_PROPERTY_PREFIX".verbosity"

/*e \ingroup RTI_RoutingServiceInfrastructureModule
 *
 * @brief Name of the property that provides the resource name of the entity
 *        that owns the adapter entity.
 *
 */
#define  RTI_ROUTING_SERVICE_ENTITY_RESOURCE_NAME_PROPERTY_NAME \
        RTI_ROUTING_SERVICE_PROPERTY_PREFIX".entity.resource_name"



  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#endif /* routingservice_infrastructure_h */
