/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)routingservice_adapter.h    generated by: makeheader    Fri Apr 23 01:06:16 2021
 *
 *		built from:	adapter.ifc
 */

#ifndef routingservice_adapter_h
#define routingservice_adapter_h


  #include "routingservice/routingservice_infrastructure.h"
  #ifdef __cplusplus
      extern "C" {
  #endif


struct RTI_RoutingServiceAdapterPlugin;


typedef void * RTI_RoutingServiceStreamWriter;

typedef int (*RTI_RoutingServiceStreamWriter_WriteFcn)(
    RTI_RoutingServiceStreamWriter stream_writer,
    const RTI_RoutingServiceSample * sample_list,
    const RTI_RoutingServiceSampleInfo * info_list,
    int count,
    RTI_RoutingServiceEnvironment * env);


typedef void * RTI_RoutingServiceStreamReader;

typedef 
void (*RTI_RoutingServiceStreamReaderListener_OnDataAvailableCallback)(
    RTI_RoutingServiceStreamReader stream_reader,
    void * listener_data);


struct RTI_RoutingServiceStreamReaderListener {
    /*e \dref_StreamReaderListener_listener_data
    */
    void * listener_data;
    /*e \dref_StreamReaderListener_on_data_available
    */
    RTI_RoutingServiceStreamReaderListener_OnDataAvailableCallback on_data_available;
};

typedef void (*RTI_RoutingServiceStreamReader_ReadFcn)(
    RTI_RoutingServiceStreamReader stream_reader,
    RTI_RoutingServiceSample ** sample_list,
    RTI_RoutingServiceSampleInfo ** info_list,
    int * count,
    RTI_RoutingServiceEnvironment * env);

typedef void (*RTI_RoutingServiceStreamReader_ReturnLoanFcn)(
    RTI_RoutingServiceStreamReader stream_reader,
    RTI_RoutingServiceSample * sample_list,
    RTI_RoutingServiceSampleInfo * info_list,
    int count,
    RTI_RoutingServiceEnvironment * env);


typedef void * RTI_RoutingServiceSession;


typedef void * RTI_RoutingServiceConnection;

typedef const char * (*RTI_RoutingServiceConnection_ToStringFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceEnvironment * env);

typedef RTI_RoutingServiceSession (*RTI_RoutingServiceConnection_CreateSessionFcn)(
    RTI_RoutingServiceConnection connection,
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);

typedef void (*RTI_RoutingServiceConnection_DeleteSessionFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceSession session,
    RTI_RoutingServiceEnvironment * env);

typedef RTI_RoutingServiceStreamReader (*RTI_RoutingServiceConnection_CreateStreamReaderFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceSession session,
    const struct RTI_RoutingServiceStreamInfo * stream_info,
    const struct RTI_RoutingServiceProperties * properties,
    const struct RTI_RoutingServiceStreamReaderListener * listener,
    RTI_RoutingServiceEnvironment * env);

typedef void (*RTI_RoutingServiceConnection_DeleteStreamReaderFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceStreamReader stream_reader,
    RTI_RoutingServiceEnvironment * env);

typedef RTI_RoutingServiceStreamWriter (*RTI_RoutingServiceConnection_CreateStreamWriterFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceSession session,
    const struct RTI_RoutingServiceStreamInfo * stream_info,
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);

typedef void (*RTI_RoutingServiceConnection_DeleteStreamWriterFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceStreamWriter stream_writer,
    RTI_RoutingServiceEnvironment * env);

typedef 
RTI_RoutingServiceStreamReader (*RTI_RoutingServiceConnection_GetDiscoveryReaderFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceEnvironment * env);

typedef RTI_RoutingServiceTypeRepresentation (*RTI_RoutingServiceConnection_CopyTypeRepresentationFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceTypeRepresentationKind type_representation_kind,
    RTI_RoutingServiceTypeRepresentation type_representation,
    RTI_RoutingServiceEnvironment * env);

typedef 
void (*RTI_RoutingServiceConnection_DeleteTypeRepresentationFcn)(
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceTypeRepresentationKind type_representation_kind,
    RTI_RoutingServiceTypeRepresentation type_representation,
    RTI_RoutingServiceEnvironment * env);


typedef void * RTI_RoutingServiceAdapterEntity;

 
typedef void (*RTI_RoutingServiceAdapterEntity_UpdateFcn)(
    RTI_RoutingServiceAdapterEntity entity,
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);

typedef void (*RTI_RoutingServiceAdapterPlugin_DeleteConnectionFcn)(
    struct RTI_RoutingServiceAdapterPlugin * plugin,
    RTI_RoutingServiceConnection connection,
    RTI_RoutingServiceEnvironment * env);

typedef RTI_RoutingServiceConnection (*RTI_RoutingServiceAdapterPlugin_CreateConnectionFcn)(
    struct RTI_RoutingServiceAdapterPlugin * plugin,
    const char * routing_service_name,
    const char * routing_service_group_name,
    const struct RTI_RoutingServiceStreamReaderListener * input_stream_discovery_listener,
    const struct RTI_RoutingServiceStreamReaderListener * output_stream_discovery_listener,
    const struct RTI_RoutingServiceTypeInfo ** edTypes,
    int edTypeCount,
    const struct RTI_RoutingServiceProperties * properties,
    RTI_RoutingServiceEnvironment * env);

typedef 
void (*RTI_RoutingServiceAdapterPlugin_DeleteFcn)(
    struct RTI_RoutingServiceAdapterPlugin * plugin,
    RTI_RoutingServiceEnvironment * env);


struct RTI_RoutingServiceAdapterPlugin {

    /* Adapter interface */
    int _init;
    struct RTI_RoutingServiceVersion _rs_version;

    /*e \brief The version of this adapter plugin */
    struct RTI_RoutingServiceVersion plugin_version;

    /*e \brief Handles the deletion of the adapter plugin (required). */
    RTI_RoutingServiceAdapterPlugin_DeleteFcn adapter_plugin_delete;

    /*e @brief Handles the creation of connections (required). */
    RTI_RoutingServiceAdapterPlugin_CreateConnectionFcn adapter_plugin_create_connection;
    /*e @brief Handles the deletion of connections (required). */
    RTI_RoutingServiceAdapterPlugin_DeleteConnectionFcn adapter_plugin_delete_connection;

    /* Connection interface */

    /*e @brief Handles the creation of sessions (optional). */
    RTI_RoutingServiceConnection_CreateSessionFcn connection_create_session;
    /*e @brief Handles the deletion of sessions (optional). */
    RTI_RoutingServiceConnection_DeleteSessionFcn connection_delete_session;
    /*e @brief Handles the creation of stream readers (optional for write-only adapters). */
    RTI_RoutingServiceConnection_CreateStreamReaderFcn connection_create_stream_reader;
    /*e @brief Handles the deletion of stream readers (optional for write-only adapters). */
    RTI_RoutingServiceConnection_DeleteStreamReaderFcn connection_delete_stream_reader;
    /*e @brief Handles the creation of stream writers (optional for read-only adapters). */
    RTI_RoutingServiceConnection_CreateStreamWriterFcn connection_create_stream_writer;
    /*e @brief Handles the deletion of stream writers (optional for read-only adapters). */
    RTI_RoutingServiceConnection_DeleteStreamWriterFcn connection_delete_stream_writer;
    /*e     
     * @brief Gets the input stream discovery reader (optional).
     */
    RTI_RoutingServiceConnection_GetDiscoveryReaderFcn connection_get_input_stream_discovery_reader;
    /*e
     * @brief Gets the output stream discovery reader (optional).
     */
    RTI_RoutingServiceConnection_GetDiscoveryReaderFcn connection_get_output_stream_discovery_reader;
    /*e @brief Handles the copy of type representations (optional). */
    RTI_RoutingServiceConnection_CopyTypeRepresentationFcn connection_copy_type_representation;
    /*e @brief Handles the deletion of type representations (optional). */
    RTI_RoutingServiceConnection_DeleteTypeRepresentationFcn connection_delete_type_representation;
    /*e @brief Returns the string representation of a connection for logging purposes (optional). */
    RTI_RoutingServiceConnection_ToStringFcn connection_to_string;
    /*e @brief Handles configuration changes in a connection (optional). */
    RTI_RoutingServiceAdapterEntity_UpdateFcn connection_update;

    /* Session interface */

    /*e @brief \not_supported Handles configuration changes in a session (optional). */
    RTI_RoutingServiceAdapterEntity_UpdateFcn session_update;

    /* StreamReader interface */

    /*e @brief Reads from an input stream (optional for write-only adapters). */
    RTI_RoutingServiceStreamReader_ReadFcn stream_reader_read;
    /*e @brief Returns the loan on the read samples and infos (optional for write-only adapters). */
    RTI_RoutingServiceStreamReader_ReturnLoanFcn stream_reader_return_loan;
    /*e @brief \not_supported Handles configuration changes in a stream reader (optional). */
    RTI_RoutingServiceAdapterEntity_UpdateFcn stream_reader_update;

    /* StreamWriter interface */

    /*e @brief Writes to an output stream (optional for read-only adapters). */
    RTI_RoutingServiceStreamWriter_WriteFcn stream_writer_write;
    /*e @brief \not_supported Handles configuration changes in a stream writer (optional). */
    RTI_RoutingServiceAdapterEntity_UpdateFcn stream_writer_update;

    /*e @brief A place for adapter implementors to keep a pointer to data that 
        may be needed by the implementation. */
    void * user_object;
};

typedef 
struct RTI_RoutingServiceAdapterPlugin * 
    (*RTI_RoutingServiceAdapterPlugin_CreateFcn)(
        const struct RTI_RoutingServiceProperties * properties,
	RTI_RoutingServiceEnvironment * env);



#define RTI_ROUTING_SERVICE_ADAPTER_PLUGIN_INIT_NUMBER (7654321)
/*e \ingroup RTI_RoutingServiceAdapterModule
 \hideinitializer
 @brief Initializes the adapter plugin structure.

 This macro must be called to initialize the
 return value of RTI_RoutingServiceAdapterPlugin_CreateFcn

 @param adapter Pointer to the adapter plugin structure

 @see \ref RTI_RoutingServiceAdapterPlugin_CreateFcn
*/
#define RTI_RoutingServiceAdapterPlugin_initialize(adapter)                   \
{                                                                             \
    struct RTI_RoutingServiceVersion rsVersion = RTI_ROUTING_SERVICE_VERSION; \
    struct RTI_RoutingServiceVersion adapterVersion = {0,0,0,0};              \
    (adapter)->_init = RTI_ROUTING_SERVICE_ADAPTER_PLUGIN_INIT_NUMBER;        \
    (adapter)->_rs_version = rsVersion;                                       \
    (adapter)->plugin_version = adapterVersion;                               \
    (adapter)->adapter_plugin_delete = 0;                                     \
    (adapter)->adapter_plugin_create_connection = 0;                          \
    (adapter)->adapter_plugin_delete_connection = 0;                          \
    (adapter)->connection_create_session = 0;                                 \
    (adapter)->connection_delete_session = 0;                                 \
    (adapter)->connection_create_stream_reader = 0;                           \
    (adapter)->connection_delete_stream_reader = 0;                           \
    (adapter)->connection_create_stream_writer = 0;                           \
    (adapter)->connection_delete_stream_writer = 0;                           \
    (adapter)->connection_get_input_stream_discovery_reader = 0;              \
    (adapter)->connection_get_output_stream_discovery_reader = 0;             \
    (adapter)->connection_copy_type_representation = 0;                       \
    (adapter)->connection_delete_type_representation = 0;                     \
    (adapter)->connection_to_string = 0;                                      \
    (adapter)->connection_update = 0;                                         \
    (adapter)->session_update = 0;                                            \
    (adapter)->stream_reader_read = 0;                                        \
    (adapter)->stream_reader_return_loan = 0;                                 \
    (adapter)->stream_reader_update = 0;                                      \
    (adapter)->stream_writer_write = 0;                                       \
    (adapter)->stream_writer_update = 0;                                      \
    (adapter)->user_object = 0;                                               \
}



  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#endif /* routingservice_adapter_h */
