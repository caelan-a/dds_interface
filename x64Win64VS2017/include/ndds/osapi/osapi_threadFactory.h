/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_threadFactory.h    generated by: makeheader    Fri Apr 23 00:10:12 2021
 *
 *		built from:	threadFactory.ifc
 */

#ifndef osapi_threadFactory_h
#define osapi_threadFactory_h



  #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
  #endif
  #ifndef osapi_dll_h
    #include "osapi/osapi_dll.h"
  #endif
  #ifndef osapi_thread_h
    #include "osapi/osapi_thread.h"
  #endif
  #ifndef osapi_activityContext_h
    #include "osapi/osapi_activityContext.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIOsapiThreadFactory;

extern RTIOsapiDllExport struct RTIOsapiThread*
RTIOsapiThreadFactory_createThread(struct RTIOsapiThreadFactory *factory,
		   const char *name, int priority, 
                   int options, int stackSize, struct RTIOsapiCpuBitmap *cpuBitmap,
		   RTIOsapiThreadOnSpawnedMethod thread_rtn,
		   void *threadParam);

extern RTIOsapiDllExport void RTIOsapiThreadFactory_destroyThread(struct RTIOsapiThreadFactory* me, struct RTIOsapiThread *thread);

typedef struct RTIOsapiThread*(*RTIOsapiThreadNewMethod)(
    struct RTIOsapiThreadFactory* me,
    const char *name, int priority, int options, int stackSize,
    struct RTIOsapiCpuBitmap *cpuBitmap,
    RTIOsapiThreadOnSpawnedMethod onSpawned, void *threadParam);

typedef void (*RTIOsapiThreadDeleteMethod)(
    struct RTIOsapiThreadFactory* me,
    struct RTIOsapiThread *thread);

extern RTIOsapiDllExport struct RTIOsapiThreadFactory*
RTIOsapiThreadFactory_new(RTIOsapiThreadNewMethod constructor,
                          RTIOsapiThreadDeleteMethod destructor,
                          void* userObject);

extern RTIOsapiDllExport struct RTIOsapiThreadFactory*
RTIOsapiThreadFactory_newDefault(void);

extern RTIOsapiDllExport void RTIOsapiThreadFactory_delete(
    struct RTIOsapiThreadFactory* me);

extern RTIOsapiDllExport void* RTIOsapiThreadFactory_getUserObject(
    struct RTIOsapiThreadFactory* me);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* osapi_threadFactory_h */
