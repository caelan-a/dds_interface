/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_intra.h    generated by: makeheader    Fri Apr 23 00:11:22 2021
 *
 *		built from:	intra.ifc
 */

#ifndef transport_intra_h
#define transport_intra_h


  #ifndef transport_dll_h
    #include "transport/transport_dll.h"
  #endif
  #ifndef transport_interface_h
    #include "transport/transport_interface.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIClock;

struct REDAExclusiveArea;

struct NDDS_Transport_Intra_Property_t {
    /*i @brief Generic properties of all Transport Plugins. 
    */
    struct NDDS_Transport_Property_t parent;

    /*i @brief Number of messages that can be buffered in the receive
      queue.

      This is the maximum number of messages that can be buffered in
      a RecvResource of the Transport Plugin.

      This does not guarantee that the Transport Plugin will actually
      be able to buffer \c received_message_count_max messages of the
      maximum size set in NDDS_Transport_Property_t#message_size_max.

      The total number of bytes that can be buffered for a
      RecvResource is actually controlled by \c receive_buffer_size.

      @see NDDS_Transport_Property_t, NDDS_Transport_RecvResource_t,
      NDDS_TRANSPORT_INTRA_RECEIVED_MESSAGE_COUNT_MAX_DEFAULT

    */
    RTI_INT32 received_message_count_max;

    /*i @brief The total number of bytes that can be buffered in the
      receive queue.

      This number controls how much memory is allocated by the plugin
      for the receive queue (on a per RecvResource basis).  The actual 
      number of bytes allocated is 

      \code
      size = receive_buffer_size + message_size_max +
             received_message_count_max * fixedOverhead
      \endcode
      
      where \c fixedOverhead is some small number of bytes used by the 
      queue data structure.  The following rules are noted:

      \li \c receive_buffer_size \c < \c message_size_max \c * 
      \c received_message_count_max, then the Transport Plugin will 
      not be able to store \c received_message_count_max messages of
      size \c receive_buffer_size.

      \li \c receive_buffer_size \c > \c message_size_max \c * 
      \c received_message_count_max, then there will be memory
      allocated that cannot be used by the plugin and thus wasted.

      The reason for allow the end user to specify a size for the
      receive queue to be less than that required to hold the maximum
      number of messages which are all of the maximum size is to optimize
      memory usage.

      In most situations, the average message size may be far less
      than the maximum message size.  So for example, if the maximum
      message size is 64 K bytes, and the user configures the plugin
      to buffer at least 10 messages, then 640 K bytes of memory would 
      be needed if all messages were 64 K bytes.  Should this be
      desired, then \c receive_buffer_size should be set to 640 K bytes.

      However, if the average message size is only 10 K bytes, then
      the user could set the \c receive_buffer_size to 100 K bytes.
      This allows the user to optimize the memory usage of the plugin
      for the average case and yet allow the plugin to handle the
      extreme case.

      \b NOTE, the queue will always be able to hold 1 message of
      \c message_size_max bytes, no matter what the value of \c
      receive_buffer_size is.

      @see NDDS_TRANSPORT_INTRA_RECEIVE_BUFFER_SIZE_DEFAULT
    */
    RTI_INT32 receive_buffer_size;
};


#define NDDS_TRANSPORT_INTRA_CLASS_NAME		"intra"


#define NDDS_TRANSPORT_INTRA_ADDRESS_BIT_COUNT  (0)


#define NDDS_TRANSPORT_INTRA_PROPERTIES_BITMAP_DEFAULT \
              ( NDDS_TRANSPORT_PROPERTY_BIT_BUFFER_ALWAYS_LOANED )


#define NDDS_TRANSPORT_INTRA_GATHER_SEND_BUFFER_COUNT_MAX_DEFAULT (1024)


#define NDDS_TRANSPORT_INTRA_MESSAGE_SIZE_MAX_DEFAULT (9216)


#define NDDS_TRANSPORT_INTRA_RECEIVED_MESSAGE_COUNT_MAX_DEFAULT  (10)


#define NDDS_TRANSPORT_INTRA_RECEIVE_BUFFER_SIZE_DEFAULT  \
        (NDDS_TRANSPORT_INTRA_RECEIVED_MESSAGE_COUNT_MAX_DEFAULT * \
         NDDS_TRANSPORT_INTRA_MESSAGE_SIZE_MAX_DEFAULT)


#define NDDS_TRANSPORT_INTRA_PROPERTY_DEFAULT { \
    { NDDS_TRANSPORT_CLASSID_INTRA, \
      NDDS_TRANSPORT_INTRA_ADDRESS_BIT_COUNT, \
      NDDS_TRANSPORT_INTRA_PROPERTIES_BITMAP_DEFAULT, \
      NDDS_TRANSPORT_INTRA_GATHER_SEND_BUFFER_COUNT_MAX_DEFAULT, \
      NDDS_TRANSPORT_INTRA_MESSAGE_SIZE_MAX_DEFAULT, \
      NULL, 0, /* allow_interfaces_list */ \
      NULL, 0, /* deny_interfaces_list */ \
      NULL, 0, /* allow_multicast_interfaces_list */ \
      NULL, 0, /* deny_multicast_interfaces_list */ \
      NDDS_TRANSPORT_UUID_UNKNOWN, /* transport_uuid */ \
      NULL, /* domain_participant_ptr*/ \
      NULL, /* domain_participant_forwarder */ \
      NULL /* thread_name_prefix */ \
    }, \
    NDDS_TRANSPORT_INTRA_RECEIVED_MESSAGE_COUNT_MAX_DEFAULT, \
    NDDS_TRANSPORT_INTRA_RECEIVE_BUFFER_SIZE_DEFAULT \
}

extern NDDS_Transport_DllExport 
NDDS_Transport_Plugin *NDDS_Transport_Intra_newI(
    const struct NDDS_Transport_Intra_Property_t *property_in,
    struct RTIClock                              *clock_in);

extern NDDS_Transport_DllExport 
NDDS_Transport_Plugin *NDDS_Transport_Intra_new(
    const struct NDDS_Transport_Intra_Property_t *property_in);


#define NDDS_Transport_Intra_new(property_in) \
        NDDS_Transport_Intra_newI(property_in, NULL)

extern NDDS_Transport_DllExport 
const char * NDDS_Transport_Intra_get_class_name_cEA(
    NDDS_Transport_Plugin    *self);

extern NDDS_Transport_DllExport 
RTI_INT32 NDDS_Transport_Intra_string_to_address_cEA(
    NDDS_Transport_Plugin    *self,
    NDDS_Transport_Address_t *address_out,
    const char               *address_in);

extern NDDS_Transport_DllExport 
RTI_INT32 NDDS_Transport_Intra_get_receive_interfaces_cEA(
    NDDS_Transport_Plugin      *self,
    RTI_INT32                  *found_more_than_provided_for_out,
    RTI_INT32                  *interface_reported_count_out,
    NDDS_Transport_Interface_t  interface_array_inout[],
    RTI_INT32                   interface_array_size_in);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* transport_intra_h */
