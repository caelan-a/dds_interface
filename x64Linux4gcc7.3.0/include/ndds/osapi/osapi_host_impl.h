/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_host_impl.h    generated by: makeheader    Fri Nov 15 12:21:38 2019
 *
 *		built from:	host_impl.ifc
 */

#ifndef osapi_host_impl_h
#define osapi_host_impl_h


#ifdef __cplusplus
    extern "C" {
#endif


typedef void (*RTIOsapiHost_g_testMacAddressFunction)(struct RTIHostHWAddr*);

extern RTIOsapiDllExport void RTIOsapiHost_setTestHWAddressFunction(
        RTIOsapiHost_g_testMacAddressFunction myGetHWAddress);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* osapi_host_impl_h */