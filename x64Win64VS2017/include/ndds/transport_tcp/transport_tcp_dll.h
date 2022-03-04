/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_tcp_dll.h    generated by: makeheader    Fri Apr 23 02:30:48 2021
 *
 *		built from:	dll.ifc
 */

#ifndef transport_tcp_dll_h
#define transport_tcp_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_transport_tcp_DLL_EXPORT)
    #define NDDS_Transport_TCP_DllExport __declspec( dllexport )
  #else
    #define NDDS_Transport_TCP_DllExport
  #endif /* NDDS_transport_tcp_DLL_EXPORT */

  #if defined(RTI_transport_tcp_DLL_VARIABLE) 
    #if defined(RTI_transport_tcp_DLL_EXPORT)
      #define NDDS_Transport_TCP_DllVariable __declspec( dllexport )
    #else
      #define NDDS_Transport_TCP_DllVariable __declspec( dllimport )
    #endif /* NDDS_transport_tcp_DLL_EXPORT */
  #else 
    #define NDDS_Transport_TCP_DllVariable
    #endif /* NDDS_transport_tcp_DLL_VARIABLE */
#else
  #define NDDS_Transport_TCP_DllExport
  #define NDDS_Transport_TCP_DllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */

#endif /* transport_tcp_dll_h */
