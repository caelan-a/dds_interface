/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_fastBuffer.h    generated by: makeheader    Fri Nov 15 12:21:50 2019
 *
 *		built from:	fastBuffer.ifc
 */

#ifndef reda_fastBuffer_h
#define reda_fastBuffer_h


  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
  #ifndef osapi_alignment_h
    #include "osapi/osapi_alignment.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAFastBufferPool;

struct REDAFastBufferPoolSet;


#define REDA_FAST_BUFFER_POOL_UNLIMITED (-1)


#define REDA_FAST_BUFFER_POOL_AUTO (-2)


#define REDA_FAST_BUFFER_POOL_BUFFER_SIZE_AUTO (-1)

typedef
RTIBool (*REDAFastBufferPoolBufferInitializeFunction)(void *buffer,
						      void *param);

typedef
void (*REDAFastBufferPoolBufferFinalizeFunction)(void *buffer,
						 void *param);

struct REDAFastBufferPoolGrowthProperty {
    /*e The number of buffers that will
      be allocated immediately on creation of the FastBufferPool. */
    int initial;

    /*e Determines to what size the pool can grow.
      When REDA_FAST_BUFFER_POOL_UNLIMITED, the pool-size 
      is only limited by available memory.  
      In case bufferCountLimit==bufferCountInitial, the pool will allocate its
      memory on initialization and not grow dynamically. */
    int maximal;

    /*e Determines the maximal
       number of buffers that will be allocated each time the FastBuffer runs
       out of buffers. The FastBuffer is initialized with
       initalBufferCount. Each time it runs out of buffers it allocates
       numBuffersToAlloc = MIN(2*numBuffers, allocationChunkMaximalBufferCount).

       The special value allocationChunkMaximalBufferCount ==
       REDA_FAST_BUFFER_POOL_UNLIMITED, indicates that the allocation size
       will keep doubling on each allocation until it reaches the
       maximalBufferCount.
  
       The value allocationChunkMaximalBufferCount == 0 is only permitted if
       initialBufferCount == maximalBufferCount. It is not meaningful to
       specify that the buffer pool may grow but then specify that it grow in
       increments of zero buffers at a time.
    */
    int increment;
};


#define REDA_FAST_BUFFER_POOL_GROWTH_PROPERTY_DEFAULT { \
    2                              /* initial */, \
    REDA_FAST_BUFFER_POOL_UNLIMITED/* maximal: unlimited */, \
    REDA_FAST_BUFFER_POOL_UNLIMITED/* increment: double */ }

extern REDADllExport 
void REDAFastBufferPoolGrowthProperty_add(
    struct REDAFastBufferPoolGrowthProperty *answer,
    const struct REDAFastBufferPoolGrowthProperty *left,
    const struct REDAFastBufferPoolGrowthProperty *right);

extern REDADllExport
int REDAFastBufferPoolGrowthProperty_compare(
        struct REDAFastBufferPoolGrowthProperty *l,
        struct REDAFastBufferPoolGrowthProperty *r);

struct REDAFastBufferPoolProperty {
    /*e control how the fast buffer pool grows */
    struct REDAFastBufferPoolGrowthProperty growth;
    /*e For Bug #8691 */
    int multiThreadedAccess;
    /*e For Bug #10224 */
    int zeroBufferContent;
    /*e For some usage of the fast buffer pool (like in table), we have a
        problem of using the fast buffer pool's getBuffer() method to limit
        the growth.  Instead, we check against a known limit in the higher
        layer.  But the problem is that we use the maximal field of the
        growth property to know what the allowed maximum (plus some heuristic
        number).  So until we have more confidence that we are exposing all the
        property necessary to size the pool, we should just grow this kind
	of table ad infinitum. */
    int ignoreMaximal;
    /*e Configures preallocation versus dynamic allocation */
    int dynamicAlloc;
};


#define REDA_FAST_BUFFER_POOL_PROPERTY_DEFAULT { \
    REDA_FAST_BUFFER_POOL_GROWTH_PROPERTY_DEFAULT, \
    0, /* multiThreadedAccess: FALSE */ \
    0, /* zeroBufferContent: FALSE*/ \
    0, /* ignoreMaximal: FALSE */ \
    0  /* dynamicAlloc: FALSE */ \
}

extern REDADllExport struct REDAFastBufferPool*
REDAFastBufferPool_new(
    int bufferSize,
    RTIOsapiAlignment bufferAlignment,
    const struct REDAFastBufferPoolProperty* propertyIn);

extern REDADllExport struct REDAFastBufferPool *
REDAFastBufferPool_newWithNotification(
    int bufferSize,
    RTIOsapiAlignment bufferAlignment,
    REDAFastBufferPoolBufferInitializeFunction bufferInitializeFnc,
    void *bufferInitializeParam,
    REDAFastBufferPoolBufferFinalizeFunction bufferFinalizeFnc,
    void *bufferFinalizeParam,
    const struct REDAFastBufferPoolProperty* propertyIn);

extern REDADllExport void 
REDAFastBufferPool_delete(struct REDAFastBufferPool *me);

extern REDADllExport void *
REDAFastBufferPool_getBufferNoMalloc(struct REDAFastBufferPool *me);

extern REDADllExport void *
REDAFastBufferPool_getBuffer(struct REDAFastBufferPool *me);


extern	REDADllExport void *REDAFastBufferPool_getBufferWithSize(
        struct REDAFastBufferPool *me,
        int bufferSize);

extern REDADllExport void 
REDAFastBufferPool_returnBuffer(struct REDAFastBufferPool *me, void *buffer);

extern REDADllExport int
REDAFastBufferPool_getBufferSize(struct REDAFastBufferPool *me);

extern REDADllExport const struct REDAFastBufferPoolProperty*
REDAFastBufferPool_getProperty(struct REDAFastBufferPool *me);


struct REDAFastBufferPoolInfo {
    /*e ID */
    void* id;
    /*e Buffer size */
    int   bufferSize;
    /*e Buffer alignment */
    int   bufferAlignment;
    /*e The number of buffers allocated */
    int   bufferAllocated;
    /*e The number of buffers in use */
    int   bufferInUse;
    /*e The maximum number of buffers that may be allocated */
    int   bufferCountLimit;
};

extern REDADllExport void
REDAFastBufferPool_getInfo(struct REDAFastBufferPool *pool, 
                           struct REDAFastBufferPoolInfo *info);

extern REDADllExport void
REDAFastBufferPoolInfo_print(struct REDAFastBufferPoolInfo *me);

struct REDAFastBufferStat {
    /*e current heap used in Bytes */
    size_t heapMemCurrentUse;
    /*e maximum heap usage in Bytes */
    size_t heapMemHighWatermark;
    /*e minimum heap usage in Bytes */
    size_t heapMemLowWatermark;
    /*e number of allocations from the heap (realloc is also counted as an alloc) */
    int heapMemAllocCount;
    /*e number of frees from the heap (realloc is also counted as a free) */
    int heapMemFreeCount;

    /*e current fast-buffer memory in Bytes */
    size_t fbMemCurrentUse;
    /*e maximum fast-buffer usage in Bytes */
    size_t fbMemHighWatermark;
    /*e minimum fast-buffer usage in Bytes */
    size_t fbMemLowWatermark;
    /*e number of times we asked to get a fast buffer */
    int fbMemGetCount;
    /*e number of times we returned a fast buffer */
    int fbMemReturnCount;
};

extern REDADllExport void
REDAFastBuffer_statGet(struct REDAFastBufferStat *stat);

extern REDADllExport void
REDAFastBuffer_statReset();

extern REDADllExport struct REDAFastBufferPoolSet *
REDAFastBufferPoolSet_new(
    int poolCount,
    int bufferSizes[],
    RTIOsapiAlignment bufferAlignment,
    const struct REDAFastBufferPoolProperty* propertyIn);

extern REDADllExport void 
REDAFastBufferPoolSet_delete(struct REDAFastBufferPoolSet *me);

extern REDADllExport void *
REDAFastBufferPoolSet_getBuffer(struct REDAFastBufferPoolSet *me,
                                int bufferSize);

extern REDADllExport void
REDAFastBufferPoolSet_returnBuffer(struct REDAFastBufferPoolSet *me,
                                   void * buffer,
                                   int bufferSize);

extern REDADllExport struct REDAFastBufferPool *
REDAFastBufferPoolSet_getPool(struct REDAFastBufferPoolSet *me,
                              int bufferSize);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "reda/reda_fastBuffer_impl.h"

#endif /* reda_fastBuffer_h */
