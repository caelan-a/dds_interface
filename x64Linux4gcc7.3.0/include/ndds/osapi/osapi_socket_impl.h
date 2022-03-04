/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_socket_impl.h    generated by: makeheader    Fri Nov 15 12:21:38 2019
 *
 *		built from:	socket_impl.ifc
 */

#ifndef osapi_socket_impl_h
#define osapi_socket_impl_h



#ifdef cplusplus
    extern "C" {
#endif


typedef int (*RTIOsapiSocket_getHostByName_Fcn)(
        struct in_addr *address_out,
        const char *address_in );

extern RTIOsapiDllExport
void RTIOsapiSocket_setGetHostByName(
        RTIOsapiSocket_getHostByName_Fcn myGetHostByName);


#ifdef cplusplus
    }   /* extern "C" */
#endif
#endif /* osapi_socket_impl_h */