/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_interface.h    generated by: makeheader    Fri Apr 23 00:11:22 2021
 *
 *		built from:	interface.ifc
 */

#ifndef transport_interface_h
#define transport_interface_h



#ifndef transport_dll_h
#include "transport/transport_dll.h"
#endif

#ifndef transport_common_h
#include "transport/transport_common.h"
#endif

/* Include the APIs useful for the transport plugin user */
#ifndef transport_interface_user_h
  #include "transport/transport_interface_user.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

struct NDDS_Transport_PluginImpl;

typedef struct NDDS_Transport_PluginImpl NDDS_Transport_Plugin;

typedef void *NDDS_Transport_Resource_t;

typedef NDDS_Transport_Resource_t NDDS_Transport_RecvResource_t;

typedef NDDS_Transport_Resource_t NDDS_Transport_SendResource_t;


#define NDDS_TRANSPORT_RESOURCE_DEFAULT    (NULL)

typedef struct  {
    /*e 
      \brief Actual structure where message is stored.

       The buffer structure has 2 fields, \c length and \c pointer.
       \c receive_rEA() should set the value of \c length to the
       length of the data stored in the memory pointed to by \c
       pointer. 

    \code
       struct NDDS_Transport_Buffer_t {
          RTI_INT32 length;
          char *pointer;
       }
    \endcode

    When the NDDS_Transport_Message_t structure is passed into the
    \c receive_rEA() call, the buffer will not be valid.  The \c
    receive_rEA() call should set the pointer to point at valid
    memory, either to the memory of the buffer that was passed into \c
    receive_rEA() or to internal memory of the transport that is being 
    loaned to the \ndds core for storing the message.

    @see NDDS_Transport_Buffer_t NDDS_Transport_Recv_Fcn_rEA
    */
    NDDS_Transport_Buffer_t buffer;

    /*e 
      \brief Storage that can be used by the Transport Plugin if
      the memory passed in \c buffer was loaned and additional
      information is required to return the buffer back to the plugin.

      If the Transport Plugin does not loan a buffer to the \ndds core
      to store a message, then \c receive_rEA() should set the value
      of loan_buffer_param to \b -1.  This will let the \ndds core know 
      that the buffer does not need to be returned to the plugin.

      If the buffer is loaned, then the loaned_buffer_param should be
      set to something other than -1.  Normally it will be set to
      store a handle to some additional information need by the
      Transport Plugin to return the loaned buffer when \c
      return_loaned_buffer_rEA() is called.
      
      @see NDDS_Transport_Return_Loaned_Buffer_Fcn_rEA 
    */
    void *loaned_buffer_param;

    /*e
     * @brief Used by the transport to store information about the source.
     *
     * The goal is to store information independently of the transport protocol.
     * After the transport fills the values, netio will parse them by calling
     * the get_transport_receive_context transport function,
     * which returns a transport context (NDDS_Transport_Context_t). The
     * transport context is then associated with the message (RTINetioMessage)
     * and can be used by Network Capture independently of the underlying
     * transport.
     */
    void *transport_info_source;

} NDDS_Transport_Message_t;


#define NDDS_Transport_Message_t_compare(transportMessage1, transportMessage2) \
  ((NDDS_Transport_Buffer_t_compare(&(transportMessage1)->buffer, &(transportMessage2)->buffer) != 0) ? \
    NDDS_Transport_Buffer_t_compare(&(transportMessage1)->buffer, &(transportMessage2)->buffer) : \
    (((transportMessage1)->loaned_buffer_param < (transportMessage2)->loaned_buffer_param) ? -1 : \
     (((transportMessage1)->loaned_buffer_param > (transportMessage2)->loaned_buffer_param) ? 1 : 0 )))


#define NDDS_TRANSPORT_MESSAGE_INVALID { { 0, NULL }, NULL, NULL }

 
typedef void (*NDDS_Transport_Listener_Interface_Changed_Callback)(
    void *listener_data_in,
    NDDS_Transport_Plugin *plugin_in,
    NDDS_Transport_Interface_t *interface_changed_in);

 
typedef struct {
    /*e @brief Listener data.
     */
    void *listener_data;
    /*e
      \copydoc NDDS_Transport_Listener_Interface_Changed_Callback
    */
    NDDS_Transport_Listener_Interface_Changed_Callback on_interface_changed;
} NDDS_Transport_Listener;

 
typedef RTI_INT32 (*NDDS_Transport_Send_Fcn)(
    NDDS_Transport_Plugin               *self,
    const NDDS_Transport_SendResource_t *sendresource_in,
    const NDDS_Transport_Address_t      *dest_address_in, 
    const NDDS_Transport_Port_t          dest_port_in,
    RTI_INT32                            transport_priority_in,    
    const NDDS_Transport_Buffer_t        buffer_in[], 
    RTI_INT32                            buffer_count_in,
    void                                *reserved );

typedef RTI_INT32 (*NDDS_Transport_Recv_Fcn_rEA)(
    NDDS_Transport_Plugin               *self,
    NDDS_Transport_Message_t            *message_out, 
    const NDDS_Transport_Buffer_t       *buffer_in,
    const NDDS_Transport_RecvResource_t *recvresource_in, 
    void                                *reserved );

typedef void (*NDDS_Transport_Return_Loaned_Buffer_Fcn_rEA)(
    NDDS_Transport_Plugin               *self,
    const NDDS_Transport_RecvResource_t *recvresource_in, 
    NDDS_Transport_Message_t            *message_in,
    void                                *reserved);

typedef RTI_INT32 (*NDDS_Transport_Unblock_Recv_Fcn_rrEA)(
    NDDS_Transport_Plugin               *self,
    const NDDS_Transport_RecvResource_t *recvresource_in, 
    void                                *reserved );

typedef RTI_INT32 (*NDDS_Transport_Create_RecvResource_Fcn_rrEA)(
    NDDS_Transport_Plugin          *self, 
    NDDS_Transport_RecvResource_t  *recvresource_out, 
    NDDS_Transport_Port_t          *recv_port_inout,
    const NDDS_Transport_Address_t *multicast_address_in,
    RTI_INT32                       reserved );

typedef void (*NDDS_Transport_Destroy_RecvResource_Fcn_rrEA)(
    NDDS_Transport_Plugin               *self,
    const NDDS_Transport_RecvResource_t *recvresource_in );

typedef RTI_INT32 (*NDDS_Transport_Share_RecvResource_Fcn_rrEA)(
    NDDS_Transport_Plugin               *self, 
    const NDDS_Transport_RecvResource_t *recvresource_in,
    const NDDS_Transport_Port_t          recv_port_in, 
    const NDDS_Transport_Address_t      *multicast_address_in,
    RTI_INT32                            reserved );

typedef RTI_INT32 (*NDDS_Transport_Unshare_RecvResource_Fcn_rrEA)(
    NDDS_Transport_Plugin               *self,
    const NDDS_Transport_RecvResource_t *recvresource_in,
    const NDDS_Transport_Port_t          recv_port_in, 
    const NDDS_Transport_Address_t      *multicast_address_in,
    RTI_INT32                            reserved );

 
typedef RTI_INT32 (*NDDS_Transport_Create_SendResource_Fcn_srEA)(
    NDDS_Transport_Plugin           *self, 
    NDDS_Transport_SendResource_t   *sendresource_out,
    const NDDS_Transport_Address_t  *dest_address_in, 
    const NDDS_Transport_Port_t      dest_port_in, 
    RTI_INT32                        transport_priority_in );

 
typedef void (*NDDS_Transport_Destroy_SendResource_Fcn_srEA)(
    NDDS_Transport_Plugin               *self,
    const NDDS_Transport_SendResource_t *sendresource_in );

 
typedef RTI_INT32 (*NDDS_Transport_Share_SendResource_Fcn_srEA)(
    NDDS_Transport_Plugin               *self, 
    const NDDS_Transport_SendResource_t *sendresource_in,
    const NDDS_Transport_Address_t      *dest_address_in, 
    const NDDS_Transport_Port_t          dest_port_in, 
    RTI_INT32                            transport_priority_in );

 
typedef const char * (*NDDS_Transport_Get_Class_Name_Fcn_cEA)(
    NDDS_Transport_Plugin    *self );

 
typedef RTI_INT32 (*NDDS_Transport_Unshare_SendResource_Fcn_srEA)(
    NDDS_Transport_Plugin               *self,
    const NDDS_Transport_SendResource_t *sendresource_in,
    const NDDS_Transport_Address_t      *dest_address_in, 
    const NDDS_Transport_Port_t          dest_port_in, 
    RTI_INT32                            transport_priority_in );


#define NDDS_TRANSPORT_STRING_TO_ADDRESS_FAILURE (0)
#define NDDS_TRANSPORT_STRING_TO_ADDRESS_SUCCESS (1)
#define NDDS_TRANSPORT_STRING_TO_ADDRESS_FAILURE_W_NAME_RESOLUTION (2)
#define NDDS_TRANSPORT_STRING_TO_ADDRESS_SUCCESS_W_NAME_RESOLUTION (3)

 
typedef RTI_INT32 (*NDDS_Transport_String_To_Address_Fcn_cEA)(
    NDDS_Transport_Plugin    *self,
    NDDS_Transport_Address_t *address_out,
    const char               *address_in );

 
typedef RTI_INT32 (*NDDS_Transport_Get_Receive_Interfaces_Fcn_cEA)(
    NDDS_Transport_Plugin      *self,
    RTI_INT32                  *found_more_than_provided_for_out,
    RTI_INT32                  *interface_reported_count_out,
    NDDS_Transport_Interface_t  interface_array_inout[],
    RTI_INT32                   interface_array_size_in );


typedef RTI_INT32 (*NDDS_Transport_Are_Addresses_Equivalent_Fcn)(
        NDDS_Transport_Plugin *self,
        const NDDS_Transport_Address_t *address_1,
        const NDDS_Transport_Address_t *address_2);


typedef RTI_INT32 (*NDDS_Transport_Is_Valid_Entry_Port_Fcn)(
        NDDS_Transport_Plugin *self,
        const NDDS_Transport_Address_t *local_address_in,
        const NDDS_Transport_Port_t local_rtps_port_in);


typedef RTI_INT32 (*NDDS_Transport_Update_Destination_Fcn)(
        NDDS_Transport_Plugin *self,
        const NDDS_Transport_Address_t *dest_address_in,
        const NDDS_Transport_Port_t dest_rtps_port_in);

 
typedef RTI_INT32 (*NDDS_Transport_Register_Listener_Fcn_cEA)(
    NDDS_Transport_Plugin   *self,
    NDDS_Transport_Listener *listener_in);


typedef void (*NDDS_Transport_Get_Receive_Context_Fcn_cEA)(
        NDDS_Transport_Plugin *self,
        struct NDDS_Transport_Context_t *transport_context,
        const NDDS_Transport_RecvResource_t *recvresource_in,
        void *transport_info_source_in);


typedef void (*NDDS_Transport_Get_Send_Context_Fcn_cEA)(
        NDDS_Transport_Plugin *self,
        struct NDDS_Transport_Context_t *transport_context,
        const NDDS_Transport_SendResource_t *sendresource_in,
        const NDDS_Transport_Address_t *dest_address_in,
        const NDDS_Transport_Port_t dest_port_in);

 
typedef void (*NDDS_Transport_Delete_Fcn_cEA)(
    NDDS_Transport_Plugin *self,
    void                  *reserved );

struct NDDS_Transport_PluginImpl {
    /*e @brief Parent of all transport property, to be allocated and
      filled during transport creation.  This is a pointer since a child
      can "derive" from NDDS_Transport_Property_t.
    */
    struct NDDS_Transport_Property_t *property;

    /*e @brief Send a message.

     \copydoc NDDS_Transport_Send_Fcn
    */
    NDDS_Transport_Send_Fcn                      send;

    /*e @brief Receive a message.

     \copydoc NDDS_Transport_Recv_Fcn_rEA 
    */
    NDDS_Transport_Recv_Fcn_rEA                  receive_rEA;

    /*e @brief Return a loaned buffer.

     \copydoc NDDS_Transport_Return_Loaned_Buffer_Fcn_rEA 
    */
    NDDS_Transport_Return_Loaned_Buffer_Fcn_rEA  return_loaned_buffer_rEA;

    /*e @brief Wakeup a thread blocked receiving on an RecvResource.

     \copydoc NDDS_Transport_Unblock_Recv_Fcn_rrEA 
    */
    NDDS_Transport_Unblock_Recv_Fcn_rrEA         unblock_receive_rrEA;

    /*e @brief Initialize the plugin to receive on a port.

     \copydoc NDDS_Transport_Create_RecvResource_Fcn_rrEA 
    */
    NDDS_Transport_Create_RecvResource_Fcn_rrEA  create_recvresource_rrEA;

    /*e @brief Close a receive port.

     \copydoc NDDS_Transport_Destroy_RecvResource_Fcn_rrEA 
    */
    NDDS_Transport_Destroy_RecvResource_Fcn_rrEA destroy_recvresource_rrEA;

    /*e @brief Share an existing RecvResource to receive on a new port.

     \copydoc NDDS_Transport_Share_RecvResource_Fcn_rrEA
    */
    NDDS_Transport_Share_RecvResource_Fcn_rrEA   share_recvresource_rrEA;

    /*e @brief Unshare a RecvResource from receiving on a port.

     \copydoc NDDS_Transport_Unshare_RecvResource_Fcn_rrEA 
    */
    NDDS_Transport_Unshare_RecvResource_Fcn_rrEA unshare_recvresource_rrEA;



    /*e @brief Initialize the plugin to send to a destination.

     \copydoc NDDS_Transport_Create_SendResource_Fcn_srEA
    */
    NDDS_Transport_Create_SendResource_Fcn_srEA  create_sendresource_srEA;

    /*e @brief Release resources needed to send to a destination.

     \copydoc NDDS_Transport_Destroy_SendResource_Fcn_srEA 
    */
    NDDS_Transport_Destroy_SendResource_Fcn_srEA destroy_sendresource_srEA;

    /*e @brief Share an existing SendResource to send to a new destination. 

     \copydoc NDDS_Transport_Share_SendResource_Fcn_srEA
    */
    NDDS_Transport_Share_SendResource_Fcn_srEA   share_sendresource_srEA;

    /*e @brief Unshare a SendResource from sending to a destination.

     \copydoc NDDS_Transport_Unshare_SendResource_Fcn_srEA 
    */
    NDDS_Transport_Unshare_SendResource_Fcn_srEA unshare_sendresource_srEA; 



    /*e @brief Get the string class name of the transport.

     \copydoc NDDS_Transport_Get_Class_Name_Fcn_cEA 
    */
    NDDS_Transport_Get_Class_Name_Fcn_cEA     get_class_name_cEA;
        
    /*e @brief Convert a transport-specific address string to an IPv6-format
      address (16 byte value).

     \copydoc NDDS_Transport_String_To_Address_Fcn_cEA 
    */
    NDDS_Transport_String_To_Address_Fcn_cEA     string_to_address_cEA;

    /*e @brief Query the Transport Plugin for the associated network 
        interfaces.

     \copydoc NDDS_Transport_Get_Receive_Interfaces_Fcn_cEA 
    */
    NDDS_Transport_Get_Receive_Interfaces_Fcn_cEA get_receive_interfaces_cEA;

    /*e @brief Get a transport context for Network Capture (inbound traffic).
     *
     * \copydoc NDDS_Transport_Get_Receive_Context_Fcn_cEA 
     */
    NDDS_Transport_Get_Receive_Context_Fcn_cEA get_transport_receive_context;

    /*e @brief Get a transport context for Network Capture (outbound traffic).
     *
     * \copydoc NDDS_Transport_Get_Send_Context_Fcn_cEA 
     */
    NDDS_Transport_Get_Send_Context_Fcn_cEA get_transport_send_context;

    /*e @brief Called to check if a pair of addresses are equivalent.
     *
     * \copydoc NDDS_Transport_Are_Addresses_Equivalent_Fcn
     */
    NDDS_Transport_Are_Addresses_Equivalent_Fcn are_addresses_equivalent;

    /*e @brief Called to check if a destination is valid.
     *
     * \copydoc NDDS_Transport_Is_Valid_Entry_Port_Fcn
     */
    NDDS_Transport_Is_Valid_Entry_Port_Fcn  is_valid_entry_port;

    /*e @brief Called to update the transport about a destination.
     *
     * \copydoc NDDS_Transport_Update_Destination_Fcn
     */
    NDDS_Transport_Update_Destination_Fcn update_destination;

    /*e @brief Register a listener with Transport Plugin.

     \copydoc NDDS_Transport_Register_Listener_Fcn_cEA 
    */
    NDDS_Transport_Register_Listener_Fcn_cEA register_listener_cEA;
       

    /*e @brief Destructor for the Transport Plugin.

     \copydoc NDDS_Transport_Delete_Fcn_cEA 
    */
    NDDS_Transport_Delete_Fcn_cEA                delete_cEA;

};

extern NDDS_Transport_DllExport void
NDDS_Transport_Plugin_initialize(
    NDDS_Transport_Plugin*                        self,
    struct NDDS_Transport_Property_t*             property,
    NDDS_Transport_Send_Fcn                       send,
    NDDS_Transport_Recv_Fcn_rEA                   receive_rEA,
    NDDS_Transport_Return_Loaned_Buffer_Fcn_rEA   return_loaned_buffer_rEA,
    NDDS_Transport_Unblock_Recv_Fcn_rrEA          unblock_receive_rrEA,
    NDDS_Transport_Create_RecvResource_Fcn_rrEA   create_recvresource_rrEA,
    NDDS_Transport_Destroy_RecvResource_Fcn_rrEA  destroy_recvresource_rrEA,
    NDDS_Transport_Share_RecvResource_Fcn_rrEA    share_recvresource_rrEA,
    NDDS_Transport_Unshare_RecvResource_Fcn_rrEA  unshare_recvresource_rrEA,
    NDDS_Transport_Create_SendResource_Fcn_srEA   create_sendresource_srEA,
    NDDS_Transport_Destroy_SendResource_Fcn_srEA  destroy_sendresource_srEA,
    NDDS_Transport_Share_SendResource_Fcn_srEA    share_sendresource_srEA,
    NDDS_Transport_Unshare_SendResource_Fcn_srEA  unshare_sendresource_srEA,
    NDDS_Transport_Get_Class_Name_Fcn_cEA         get_class_name_cEA,
    NDDS_Transport_String_To_Address_Fcn_cEA      string_to_address_cEA,
    NDDS_Transport_Get_Receive_Interfaces_Fcn_cEA get_receive_interfaces_cEA,
    NDDS_Transport_Get_Receive_Context_Fcn_cEA    get_transport_receive_context,
    NDDS_Transport_Get_Send_Context_Fcn_cEA       get_transport_send_context,
    NDDS_Transport_Register_Listener_Fcn_cEA      _listener_cEA,
    NDDS_Transport_Delete_Fcn_cEA                 delete_cEA);

extern NDDS_Transport_DllExport 
NDDS_Transport_ClassId_t NDDS_Transport_Plugin_get_classid(
    const NDDS_Transport_Plugin *self);

extern NDDS_Transport_DllExport
RTI_INT32 NDDS_Transport_Plugin_is_valid(const NDDS_Transport_Plugin *self);

extern NDDS_Transport_DllExport 
RTI_INT32 NDDS_Transport_Plugin_is_polled(const NDDS_Transport_Plugin *self);

extern NDDS_Transport_DllExport 
RTI_INT32 NDDS_Transport_Plugin_is_blocking(const NDDS_Transport_Plugin *self);

extern NDDS_Transport_DllExport
RTI_INT32 NDDS_Transport_Plugin_get_message_size_max(
    const NDDS_Transport_Plugin *self);

extern NDDS_Transport_DllExport
NDDS_Transport_ClassId_t NDDS_Transport_Plugin_get_class_id(
    const NDDS_Transport_Plugin *self);


extern	NDDS_Transport_DllExport int NDDS_Transport_Plugin_compare(
        const void *leftData,
        const void *rightData);


extern	NDDS_Transport_DllExport void NDDS_Transport_Plugin_print(
        const void *data,
        const char *desc,
        int indent);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "transport/transport_interface_impl.h"

#endif /* transport_interface_h */
