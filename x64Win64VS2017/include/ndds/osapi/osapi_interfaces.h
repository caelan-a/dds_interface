/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_interfaces.h    generated by: makeheader    Fri Apr 23 00:09:54 2021
 *
 *		built from:	interfaces.ifc
 */

#ifndef osapi_interfaces_h
#define osapi_interfaces_h



    #ifndef osapi_dll_h
        #include "osapi/osapi_dll.h"
    #endif

    #ifndef osapi_type_h
        #include "osapi/osapi_type.h"
    #endif

    #ifndef osapi_socket_h
        #include "osapi/osapi_socket.h"
    #endif

    #ifdef __cplusplus
       extern "C" {
    #endif


#define RTI_OSAPI_IPv4_ADDRESS_LENGTH  (4)


#if defined(RTI_WIN32)
    #include <ifdef.h>
    #define RTI_OSAPI_INTERFACE_NAME_LENGTH  IF_MAX_STRING_SIZE + 1
#else
    #define RTI_OSAPI_INTERFACE_NAME_LENGTH  16
#endif

typedef struct {
    unsigned char address[RTI_OSAPI_IPv4_ADDRESS_LENGTH];
} RTIOsapiIPv4Address_t;


#define RTI_OSAPI_IPv4_ADDRESS_LOCALHOST {{127,0,0,1}}


#if defined(RTI_QNX) || (defined(RTI_LINUX) && !defined(RTI_ANDROID)) \
    || defined(RTI_DARWIN) || defined(RTI_INTIME) || defined(RTI_ANDROID9)
  /**
   * In this case we retrieve interface info using the getifaddrs call so we use
   * struct ifaddrs.
   */
  #define RTI_OSAPI_INTERFACE_USEGETIFADDRS
#endif

typedef struct RTIOsapiSocket_InterfaceDescription {
        char *name;
        unsigned int index;
        struct sockaddr *address;
        unsigned int flags;
#if defined(RTI_WIN32)
        char nameArray[RTI_OSAPI_INTERFACE_NAME_LENGTH];
#endif
} RTIOsapiSocket_InterfaceDescription;

extern RTIOsapiDllExport
RTI_INT32 RTIOsapiSocket_getInterfaces(
        char ** outInterfaceBuffer,
        int * outInterfaceBufferSize,
        struct RTIOsapiSocket_InterfaceDescription ** outInterfaceArray,
        int * outInterfaceCount,
        RTIOsapiSocketAFKind kindAF,
        unsigned int requestedInterfacesMask,
        unsigned int reportIgnoreInterfaceWarnings,
        int inSocket);

extern RTIOsapiDllExport
void RTIOsapiSocket_freeInterfaces(
        int interfaceBufferSize,
        char * interfaceBuffer,
        int numInterfaces,
        RTIOsapiSocket_InterfaceDescription * interfaceArray);


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_UP           (0x1)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_BROADCAST    (0x2)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_LOOPBACK     (0x4)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_POINTOPOINT  (0x8)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_MULTICAST   (0x10)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_RUNNING     (0x20)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_MASTER           (0x40)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_SLAVE           (0x80)


    #ifdef __cplusplus
		}	/* extern "C" */
    #endif

#endif /* osapi_interfaces_h */
