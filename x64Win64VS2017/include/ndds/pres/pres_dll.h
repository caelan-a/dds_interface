/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)pres_dll.h    generated by: makeheader    Fri Apr 23 00:10:15 2021
 *
 *		built from:	dll.ifc
 */

#ifndef pres_dll_h
#define pres_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE) || defined(RTI_INTIME)
  #if defined(RTI_pres_DLL_EXPORT)
    #define PRESDllExport __declspec( dllexport )
  #else
    #define PRESDllExport
  #endif /* RTI_pres_DLL_EXPORT */

  #if defined(RTI_pres_DLL_VARIABLE) 
    #if defined(RTI_pres_DLL_EXPORT)
      #define PRESDllVariable __declspec( dllexport )
    #else
      #define PRESDllVariable __declspec( dllimport )
    #endif /* RTI_pres_DLL_EXPORT */
  #else 
    #define PRESDllVariable
  #endif /* RTI_pres_DLL_VARIABLE */
#else
  #define PRESDllExport
  #define PRESDllVariable
#endif /* RTI_WIN32 || RTI_WINCE || RTI_INTIME */


#endif /* pres_dll_h */
