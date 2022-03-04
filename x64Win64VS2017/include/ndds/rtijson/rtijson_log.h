/*
 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef rtijson_log_h
#define rtijson_log_h


  #ifndef log_common_h
    #include "log/log_common.h"
  #endif
  #ifndef rtijson_dll_h
    #include "rtijson/rtijson_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


  #define SUBMODULE_JSON_PARSER   (0x1000)


  #define JSON_SUBMODULE_MASK_PARSER  (0x1000)


  #define JSON_SUBMODULE_MASK_ALL (0xFFFF)

extern RTIJSONDllExport
void RTIJSONLog_setVerbosity(RTILogBitmap submoduleMask, int verbosity);

extern RTIJSONDllExport
void RTIOsapiLog_setBitmaps(
        RTILogBitmap submoduleMask,
		RTILogBitmap instrumentationMask);

extern RTIJSONDllExport
void RTIOsapiLog_getBitmaps(
        RTILogBitmap *submoduleMask,
        RTILogBitmap *instrumentationMask);

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_ENTITY_NOT_FOUND_s;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_KIND_NOT_MATCH_ss;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_CHILD_NOT_FOUND_s;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_CHILD_NOT_FOUND_d;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_CHILD_NOT_FOUND_dd;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_CHILD_NAME_NOT_FOUND_d;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_CHILD_NAME_NOT_FOUND_dd;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_EXCEPTION_REPORT_sd;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_PARSE_ERROR_s;

extern RTIJSONDllVariable
const struct RTILogMessage RTIJSON_LOG_PARSE_ERROR_ss;


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* rtijson_log_h */
