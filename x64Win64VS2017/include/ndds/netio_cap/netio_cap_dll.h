/* $Id$

 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.

Description
-----------
Strictly for Windows DLL linkage resolution
=========================================================================*/
#ifndef netio_cap_include_dll_h
#define netio_cap_include_dll_h

#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_netio_cap_DLL_EXPORT)
    #define RTINetioCapDllExport __declspec( dllexport )
  #else
    #define RTINetioCapDllExport
  #endif /* RTI_netio_cap_DLL_EXPORT */

  #if defined(RTI_netio_cap_DLL_VARIABLE)
    #if defined(RTI_netio_cap_DLL_EXPORT)
      #define RTINetioCapDllVariable __declspec( dllexport )
    #else
      #define RTINetioCapDllVariable __declspec( dllimport )
    #endif /* RTI_netio_cap_DLL_EXPORT */
  #else
    #define RTINetioCapDllVariable
  #endif /* RTI_netio_cap_DLL_VARIABLE */
#else
  #define RTINetioCapDllExport
  #define RTINetioCapDllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */

#endif /* netio_cap_include_dll_h */
/* end of $Id$ */
