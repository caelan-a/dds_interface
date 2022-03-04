/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_dll_h
#define apputils_dll_h

#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_app_utils_DLL_EXPORT)
    #define APPUTILSDllExport __declspec( dllexport )
  #else
    #define APPUTILSDllExport
  #endif /* RTI_app utils_DLL_EXPORT */

  #if defined(RTI_app_utils_DLL_VARIABLE)
    #if defined(RTI_app_utils_DLL_EXPORT)
      #define APPUTILSDllVariable __declspec( dllexport )
    #else
      #define APPUTILSDllVariable __declspec( dllimport )
    #endif /* RTI_app_utils_DLL_EXPORT */
  #else
    #define APPUTILSDllVariable
  #endif /* RTI_app_utils_DLL_VARIABLE */
#else
  #define APPUTILSDllExport
  #define APPUTILSDllVariable
#endif /* RTI_WIN32 || RTI_WINCE */

#endif /* apputils_dll_h */
