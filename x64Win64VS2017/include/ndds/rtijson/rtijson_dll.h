/*
 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef rtijson_dll_h
#define rtijson_dll_h



#include "log/log_makeheader.h"

#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_rtijson_DLL_EXPORT)
    #define RTIJSONDllExport __declspec( dllexport )
  #else
    #define RTIJSONDllExport
  #endif /* RTI_rtijson_DLL_EXPORT */

  #if defined(RTI_rtijson_DLL_VARIABLE)
    #if defined(RTI_rtijson_DLL_EXPORT)
      #define RTIJSONDllVariable __declspec( dllexport )
    #else
      #define RTIJSONDllVariable __declspec( dllimport )
    #endif /* RTI_rtijson_DLL_EXPORT */
  #else
    #define RTIJSONDllVariable
  #endif /* RTI_rtijson_DLL_VARIABLE */
#else
  #define RTIJSONDllExport
  #define RTIJSONDllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */


#endif /* rtijson_dll_h */
