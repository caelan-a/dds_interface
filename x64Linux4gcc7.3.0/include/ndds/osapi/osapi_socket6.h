/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_socket6.h    generated by: makeheader    Fri Nov 15 12:21:39 2019
 *
 *		built from:	socket6.ifc
 */

#ifndef osapi_socket6_h
#define osapi_socket6_h



#ifndef osapi_type_h
    #include "osapi/osapi_type.h"
#endif
#ifndef osapi_dll_h
    #include "osapi/osapi_dll.h"
#endif
#ifndef osapi_socket_h
    #include "osapi/osapi_socket.h"
#endif
#ifndef osapi_interfaces_h
    #include "osapi/osapi_interfaces.h"
#endif

#if (defined(RTI_IPV6) && !(defined(RTI_UNIX) || defined(RTI_QNX) || defined(RTI_VXWORKS) \
                            || defined(RTI_WINCE) || defined(RTI_WIN32) || defined(RTI_INTIME)))
    #error Need to port
#endif

#ifdef __cplusplus
    extern "C" {
#endif


  #if defined(RTI_UNIX) || defined(RTI_VXWORKS) || defined(RTI_QNX) || defined(RTI_INTIME)
    typedef u_int RTIOsapiSocket6MulticastLoopbackFlag;
    typedef u_int RTIOsapiSocket6TTL;
  #elif defined(RTI_WIN32) || defined(RTI_WINCE) 
    #define RTIOsapiSocket6MulticastLoopbackFlag BOOL
    #define RTIOsapiSocket6TTL int
  #elif defined(RTI_IPV6)
    #error "Need to port"
  #endif

extern RTIOsapiDllExport
/*e  \ingroup RTIOsapiSocketClass
  OS independent function to get socket option for IPv6 socket.

  @param s         Socket
  @param optType   Desired action.
  @param optVal    Pointer to the desired value corresponding to the optType.
  @param optLenPtr Pointer to the integer to return the actual value. Don't
                   set the initial value to 0!

  @return 0 if successful, -1 if error

  @see RTIOsapiSocketOption RTIOsapiSocket6_setOption
*/
int RTIOsapiSocket6_getOption(int s,
                              RTIOsapiSocketOption optType,
                              char *optVal, unsigned int *optLenPtr);

extern RTIOsapiDllExport
/*e  \ingroup RTIOsapiSocketClass
  OS independent function to set socket option for IPv6 socket.

  @param s       Socket
  @param optType Desired action.
  @param optVal  Pointer to the desired value corresponding to the optType.
  @param optLen  Length of the optVal in bytes.

  @return 0 if successful, -1 if error

  @see RTIOsapiSocket6_getOption
*/
int RTIOsapiSocket6_setOption(int s,
                             RTIOsapiSocketOption optType,
                             const char *optVal, unsigned int optLen);


#if defined(RTI_SOL210) || (defined(RTI_LINUX26) && !defined(RTI_GCC3))
  /* Transport priority for IPv6 (TCLASS) only supported on Solaris 10 AND Linux 2.6 */
  #define RTI_SOCKET_PRIORITY_IPv6
#endif

#ifdef RTI_IPV6 /* req'd for any functions that take sockaddr_in6 */

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Assign a port number to an (IPv6) socket.

  Bind a port to a socket.  Fills in sockAddr.  If the passed port number is
  0, then the system will assign a new port number.  If the passed port number
  is in use, RTIOsapiSocket_bind returns -1.  If the bind succeeds, the bound port
  number is returned, and is also available as ntohs(sockAddr->sin6_port).
  This is only necessary if the socket will receive data. 
*/
int RTIOsapiSocket6_bind(int sd, struct sockaddr_in6 *sockAddr, int portnum);

extern RTIOsapiDllExport
int RTIOsapiSocket6_bindWithIP(
        int sd, struct sockaddr_in6 *sockAddr, const struct in6_addr *ip, int portnum);

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Add an IPv6 multicast group.

  Adds a socket to a multicast group to receive traffic sent to that
  destination.  This is only necessary if the socket will receive data. 
*/
int RTIOsapiSocket_multicastAdd(int sd, const struct sockaddr *mcAddr,
                                 int ifIndex);

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Drop an IPv6 multicast group.

  Drops a socket from a multicast group previously added.  This is implicitly
  done on closing the socket.
*/
int RTIOsapiSocket_multicastDrop(int sd, const struct sockaddr *mcAddr,
                                  int ifIndex);


typedef struct {
       /*e @brief Length of the buffer pointed to by pointer. */
       RTI_INT32 length;
       /*e @brief Pre-allocated (by the caller) buffer. */
       char *pointer;
} RTIOsapiSocketBuffer_t;

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Receive data from a socket using zero-copy.
  
  Return buffer with \ref recvZeroCopyReturn
*/
int RTIOsapiSocket_recvZeroCopy(int sd, void **pbuffer, size_t *bufferSize,
                            struct sockaddr *fromAddress, socklen_t *addressLen);

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Return zero-copy buffer.
  
  Return buffer from \ref recvZeroCopy
*/
int RTIOsapiSocket_recvZeroCopyReturn(void **pbuffer);


typedef void *RTIOsapiSocketGatherBuffer_t;

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Allocate gather buffer, if needed on this platform.
    Need one per transport instance.  Return true on success.
*/
RTIBool RTIOsapiSocketGatherBuffer_init(RTIOsapiSocketGatherBuffer_t *gatherBuffer);

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Cleanup gather buffer, if one was allocated.
*/
void RTIOsapiSocketGatherBuffer_finalize(const RTIOsapiSocketGatherBuffer_t gatherBuffer);

extern RTIOsapiDllExport
int RTIOsapiSocket_sendMessage(int sd, RTIOsapiSocketGatherBuffer_t gatherBuffer,
                          const RTIOsapiSocketBuffer_t *buffers, size_t bufferCount,
                          const struct sockaddr *address, socklen_t addressLen);


#define RTIOsapiSocket_sendMessage(s, gB, bufs, bufCount, address, addrLen) \
        RTIOsapiSocket_sendMessageN(&s, 1, gB, bufs, bufCount, address, addrLen)

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Send data to a set of sockets (needed for multicast send).
*/
int RTIOsapiSocket_sendMessageN(int *sockets, size_t socketCount,
                          RTIOsapiSocketGatherBuffer_t gatherBuffer,
                          const RTIOsapiSocketBuffer_t *buffers, size_t bufferCount,
                          const struct sockaddr *address, socklen_t addressLen);


#if RTI_NO_PLATFORM
  /* Mutable priority not yet supported */
  #define RTI_SOCKET_MUTABLE_PRIORITY

extern RTIOsapiDllExport
int RTIOsapiSocket_sendMessageWithPriority(int sd, unsigned int priority,
                          RTIOsapiSocketGatherBuffer_t gatherBuffer,
                          const RTIOsapiSocketBuffer_t *buffers, size_t bufferCount,
                          const struct sockaddr *address, socklen_t addressLen);


#define RTIOsapiSocket_sendMessageWithPriority(s, prio, gB, bufs, bufCount, address, addrLen) \
        RTIOsapiSocket_sendMessageWithPriorityN(&s, 1, prio, gB, bufs, bufCount, address, addrLen)

extern RTIOsapiDllExport
/*e \ingroup RTIOsapiSocketClass

  @brief Send data to a set of sockets (needed for multicast send), with
    specified priority.
*/
int RTIOsapiSocket_sendMessageWithPriorityN(int *sockets, size_t socketCount,
                          unsigned int priority, RTIOsapiSocketGatherBuffer_t gatherBuffer,
                          const RTIOsapiSocketBuffer_t *buffers, size_t bufferCount,
                          const struct sockaddr *address, socklen_t addressLen);


#endif /*RTI_NO_PLATFORM*/


#endif /* RTI_IPV6 */


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_UP           (0x1)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_BROADCAST    (0x2)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_LOOPBACK     (0x4)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_POINTOPOINT (0x8)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_MULTICAST   (0x10)


#define RTI_OSAPI_SOCKET_INTERFACE_FLAG_RUNNING     (0x20)

extern RTIOsapiDllExport
RTI_INT32 RTIOsapiInterfaces_getIPv6Interfaces(
        int family,
        char ** outInterfaceBuffer,
        int * outInterfaceBufferSize,
        struct RTIOsapiSocket_InterfaceDescription ** outInterfaceArray,
        int * outInterfaceCount,
        unsigned int requestedInterfacesMask,
        unsigned int reportIgnoreInterfaceWarnings,
        int unisocket);


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* osapi_socket6_h */
