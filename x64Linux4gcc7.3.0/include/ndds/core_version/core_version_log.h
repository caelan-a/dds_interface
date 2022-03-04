/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)core_version_log.h    generated by: makeheader    Fri Nov 15 12:22:46 2019
 *
 *		built from:	log.ifc
 */

#ifndef core_version_log_h
#define core_version_log_h


  #ifndef log_common_h
    #include "log/log_common.h"
  #endif
  #ifndef core_version_dll_h
    #include "core_version/core_version_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


  #define SUBMODULE_VERS_VERSION        (0x1000)

  #define VERS_SUBMODULE_MASK_VERSION   (0x0001)
  #define VERS_SUBMODULE_MASK_ALL       (0xffff)

extern VERSDllExport
void VERSLog_setVerbosity(RTILogBitmap submoduleMask, int verbosity);

extern VERSDllExport
void VERSLog_setBitmaps(RTILogBitmap submoduleMask,
			RTILogBitmap instrumentationMask);

extern VERSDllExport
void VERSLog_getBitmaps(RTILogBitmap *submoduleMask,
			RTILogBitmap *instrumentationMask);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* core_version_log_h */
