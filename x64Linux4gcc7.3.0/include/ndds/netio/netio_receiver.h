/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)netio_receiver.h    generated by: makeheader    Fri Nov 15 12:22:13 2019
 *
 *		built from:	receiver.ifc
 */

#ifndef netio_receiver_h
#define netio_receiver_h


  #ifndef netio_dll_h
    #include "netio/netio_dll.h"
  #endif
  #ifndef netio_common_h
    #include "netio/netio_common.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIClock;

struct REDABuffer;

struct REDAExclusiveArea;

struct REDAWorker;

struct REDAWeakReference;

struct REDADatabase;

struct RTIEventActiveObjectListener;

struct RTINetioConfigurator;

struct RTINetioReceiverProperty {
    /*e
      bitmap specifies which property the user is specifying actively.
      Those not indicated should be left as default.
      Boolean property such as whether blocking receive is to be used can
      be specified through just bitmap.

      @see RTI_NETIO_RECEIVER_PROPERTY_BIT_POLLED
      RTI_NETIO_RECEIVER_PROPERTY_BIT_TIMESTAMP
    */
    int bitmap;

    /*e Control resource growth.  Helps avoid memory allocation. */
    struct REDAFastBufferPoolGrowthProperty resourceGrowth;

    /*e Control entryport growth.  Helps avoid memory allocation. */
    struct REDAFastBufferPoolGrowthProperty entryportGrowth;
};


  #define RTI_NETIO_RECEIVER_PROPERTY_BIT_POLLED (0x1)


  #define RTI_NETIO_RECEIVER_PROPERTY_BIT_TIMESTAMP (0x2)


  #define RTI_NETIO_RECEIVER_PROPERTY_DEFAULT { \
    RTI_NETIO_RECEIVER_PROPERTY_BIT_TIMESTAMP,  \
    {16, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED}, \
    {8, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED} }

struct RTINetioReceiver;

extern RTINetioDllExport int
RTINetioReceiver_addEntryport(struct RTINetioReceiver *me,
			      struct REDAWeakReference *entryportWRPtrOut,
			      const struct RTINetioLocatorInfo* entryportIn,
			      struct REDAWorker *worker);

extern RTINetioDllExport int
RTINetioReceiver_removeEntryport(struct RTINetioReceiver *me,
		     const struct REDAWeakReference *entryportWRPtrIn,
		     struct REDAWorker *worker);

extern RTINetioDllExport int
RTINetioReceiver_checkEntryports(struct RTINetioReceiver *me,
        RTIBool *hasEntryPortsInUse,
        const struct REDAWeakReference *transportPluginWRPtrIn,
        struct REDAWorker *worker);

extern RTINetioDllExport RTIBool RTINetioReceiver_receiveFast(
    struct RTINetioReceiver *me, struct RTINetioMessage *messageOut,
    struct REDAWeakReference *resourceWRInOut,
    const struct REDABuffer *bufferIn, struct REDAWorker *worker);

extern RTINetioDllExport void
RTINetioReceiver_disownResource(struct RTINetioReceiver *me,
		 struct REDAWeakReference *resourceWRInOut,
		 struct REDAWorker *worker);

extern RTINetioDllExport int
RTINetioReceiver_getRequiredThreadCount(struct RTINetioReceiver *me,
					struct REDAWorker *worker);

extern RTINetioDllExport struct RTINetioReceiver *
RTINetioReceiver_new(struct RTIClock *clockIn,
		     struct REDAExclusiveArea* tableEa,
		     struct REDADatabase *dbIn,
		     struct RTIEventActiveObjectListener *listenerIn,
		     struct RTINetioConfigurator *configuratorIn,
		     const struct RTINetioReceiverProperty *propertyIn,
		     struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioReceiver_preShutdownWakeup(struct RTINetioReceiver *me,
				   struct REDAWorker *worker);

extern RTINetioDllExport RTIBool
RTINetioReceiver_shutdown(struct RTINetioReceiver *me,
                          struct REDAWorker *worker);

extern RTINetioDllExport void
RTINetioReceiver_delete(struct RTINetioReceiver *me,
                        struct REDAWorker *worker);

extern RTINetioDllExport void
RTINetioReceiver_returnLoan(struct RTINetioReceiver *self,
			    struct REDAWeakReference *resourceTableRecordWRIn,
			    NDDS_Transport_Message_t *loanedMessageIn,
			    struct REDAWorker *worker);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* netio_receiver_h */
