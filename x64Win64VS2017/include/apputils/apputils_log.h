/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_log_h
#define apputils_log_h

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif
#ifndef log_common_h
  #include "log/log_common.h"
#endif
#ifndef advlog_context_h
  #include "advlog/advlog_context.h"
#endif
#ifdef __cplusplus
    extern "C" {
#endif

  /*i \ingroup APPUTILSLogModule
      Submodule ID for Common submodule
  */
  #define SUBMODULE_APPUTILS_COMMON (0x1000)
  /*i \ingroup APPUTILSLogModule
    Submodule ID for Service submodule
  */
  #define SUBMODULE_APPUTILS_ARGPARSER (0x2000)

  /*i \ingroup APPUTILSLogModule
    Mask for turning on logging for all submoudles
  */
  #define APPUTILS_SUBMODULE_MASK_ALL (0xFFFFF)

extern APPUTILSDllVariable
const struct RTILogMessage APPUTILS_LOG_ARGPARSER_FAILURE;

extern APPUTILSDllVariable
const struct RTILogMessage APPUTILS_LOG_ARGPARSER_GET_ARGUMENT_FAILURE_s;

extern APPUTILSDllVariable
const struct RTILogMessage APPUTILS_LOG_ARGPARSER_GET_USER_ENV_VARIABLES_FAILURE;

extern APPUTILSDllExport
void APPUTILSLog_setVerbosity(RTILogBitmap submoduleMask, int verbosity);

extern APPUTILSDllExport void
APPUTILSLog_setBitmaps(RTILogBitmap submoduleMask,
		     RTILogBitmap instrumentationMask);

extern APPUTILSDllExport void APPUTILSLog_getBitmaps(
    RTILogBitmap *submoduleMask, RTILogBitmap *instrumentationMask);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* apputils_log_h */
