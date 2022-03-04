/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)persistence_dll.h    generated by: makeheader    Fri Nov 15 12:24:16 2019
 *
 *		built from:	dll.ifc
 */

#ifndef persistence_dll_h
#define persistence_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_persistence_DLL_EXPORT)
    #define PERSISTENCEDllExport __declspec( dllexport )
  #else
    #define PERSISTENCEDllExport
  #endif /* RTI_persistence_DLL_EXPORT */

  #if defined(RTI_persistence_DLL_VARIABLE) 
    #if defined(RTI_persistence_DLL_EXPORT)
      #define PERSISTENCEDllVariable __declspec( dllexport )
    #else
      #define PERSISTENCEDllVariable __declspec( dllimport )
    #endif /* RTI_persistence_DLL_EXPORT */
  #else 
    #define PERSISTENCEDllVariable
  #endif /* RTI_persistence_DLL_VARIABLE */
#else
  #define PERSISTENCEDllExport
  #define PERSISTENCEDllVariable
#endif /* RTI_WIN32 || RTI_WINCE */


#endif /* persistence_dll_h */
