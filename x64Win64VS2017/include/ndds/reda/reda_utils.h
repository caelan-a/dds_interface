/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_utils.h    generated by: makeheader    Fri Apr 23 00:11:13 2021
 *
 *		built from:	utils.ifc
 */

#ifndef reda_utils_h
#define reda_utils_h



#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif

#ifndef reda_dll_h
  #include "reda/reda_dll.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAExclusiveArea;

struct REDAWorker;

struct REDAAtomicLongLong {
    /*i @brief the thread-safe 64bit epoch value */
    RTI_INT64 _epoch;
    /*i @brief The EA that protects the epoch value */
    struct REDAExclusiveArea * _ea;
};

extern REDADllExport
RTIBool REDAAtomicLongLong_increment(
        struct REDAAtomicLongLong * self,
        RTI_INT64 * value,
        struct REDAWorker * worker);

extern REDADllExport
RTIBool REDAAtomicLongLong_decrement(
        struct REDAAtomicLongLong * self,
        RTI_INT64 * value,
        struct REDAWorker * worker);

extern REDADllExport
RTIBool REDAAtomicLongLong_read(
        struct REDAAtomicLongLong * self,
        RTI_INT64 * value,
        struct REDAWorker * worker);

extern REDADllExport
RTIBool REDAAtomicLongLong_initialize(
        struct REDAAtomicLongLong * self,
        struct REDAExclusiveArea * ea);

extern REDADllExport
void REDAAtomicLongLong_finalize(
        struct REDAAtomicLongLong * self);


#ifdef __cplusplus
    }	/* extern "C" */
#endif


#endif /* reda_utils_h */
