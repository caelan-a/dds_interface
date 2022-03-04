/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_log_impl.h    generated by: makeheader    Fri Apr 23 00:10:55 2021
 *
 *		built from:	log_impl.ifc
 */

#ifndef reda_log_impl_h
#define reda_log_impl_h


  #ifndef log_common_h
    #include "log/log_common.h"
  #endif
  #ifndef osapi_thread_h
    #include "osapi/osapi_thread.h"
  #endif
  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
#ifdef __cplusplus
    extern "C" {
#endif

extern REDADllVariable RTILogBitmap REDALog_g_submoduleMask;

extern REDADllVariable RTILogBitmap REDALog_g_instrumentationMask;



#define REDALogMessage_log(INSTRUMENT_BIT, ...) \
    RTILogMessage_log( \
            REDALog_g_instrumentationMask, \
            REDALog_g_submoduleMask, \
            REDA_CURRENT_SUBMODULE, \
            RTI_LOG_PRINT_FORMAT_MASK_ALL, \
            (INSTRUMENT_BIT), \
            MODULE_REDA, \
            __VA_ARGS__)

#define REDALog_fatal(...) \
    REDALogMessage_log(RTI_LOG_BIT_FATAL_ERROR, __VA_ARGS__)


#define REDALog_exception(...) \
    REDALogMessage_log(RTI_LOG_BIT_EXCEPTION, __VA_ARGS__)


#define REDALog_warn(...) \
    REDALogMessage_log(RTI_LOG_BIT_WARN, __VA_ARGS__)


#ifdef RTI_PRECONDITION_TEST
  #define  REDALog_preconditionOnly(declaration) declaration
#else /* nothing */
  #define REDALog_preconditionOnly(declaration)
#endif /* RTI_PRECONDITION_TEST */


#define REDALog_logPreconditionFailedWExpr(preconditionExpression)             \
{                                                                              \
    REDALog_fatal(                                                             \
            &RTI_LOG_PRECONDITION_FAILURE_s,                                   \
            #preconditionExpression);                                          \
    RTILog_onAssert();                                                         \
}


#define REDALog_testPrecondition(preconditionExpression, failAction)         \
  RTILog_testPrecondition(REDA, preconditionExpression, failAction)

#define REDALog_checkPrecondition(preconditionExpression, failAction) \
  RTILog_checkPrecondition(REDA, preconditionExpression, failAction)


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* reda_log_impl_h */
