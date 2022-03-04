/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)commend_facade.h    generated by: makeheader    Fri Nov 15 12:22:18 2019
 *
 *		built from:	facade.ifc
 */

#ifndef commend_facade_h
#define commend_facade_h



  #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
  #endif
  #ifndef reda_orderedDataType_h
    #include "reda/reda_orderedDataType.h"
  #endif
  #ifndef event_generator_h
    #include "event/event_generator.h"
  #endif
  #ifndef event_jobDispatcher_h
    #include "event/event_jobDispatcher.h"
  #endif
  #ifndef netio_configurator_h
    #include "netio/netio_configurator.h"
  #endif
  #ifndef netio_sender_h
    #include "netio/netio_sender.h"
  #endif
  #ifndef netio_receiver_h
    #include "netio/netio_receiver.h"
  #endif
  #ifndef mig_generator_h
    #include "mig/mig_generator.h"
  #endif
  #ifndef mig_interpreter_h
    #include "mig/mig_interpreter.h"
  #endif
  #ifndef commend_dll_h
    #include "commend/commend_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAWorkerFactory;

struct COMMENDFacade;

struct RTIEventGeneratorListener;

struct RTIEventGeneratorListenerStorage;

typedef RTIBool (*COMMENDFacadeEntryportDescAddFunction)(
    struct COMMENDFacade *me, struct REDAWeakReference *reference,
    const struct RTINetioLocatorInfo* entryport,
    struct REDAWorker *worker);

typedef void (*COMMENDFacadeEntryportDescRemoveFunction)(
    struct COMMENDFacade *me, const struct REDAWeakReference *reference,
    struct REDAWorker *worker);

typedef RTIBool (*COMMENDFacadeEntryportDescCheckFunction)(
    struct COMMENDFacade *me,
    RTIBool *hasActiveEntryPorts,
    const struct REDAWeakReference *referenceToPlugin,
    struct REDAWorker *worker);

typedef void (*COMMENDFacadeDestinationDescRemoveFunction)(
    struct COMMENDFacade *me, struct RTINetioSenderDestinationGroup *group,
    const struct REDAWeakReference *reference, struct REDAWorker *worker);

extern COMMENDDllExport RTIBool COMMENDFacade_sendAck(
    struct COMMENDFacade *me, int *size,
    const struct REDAWeakReference* destinationArrayIn, int destinationCountIn,
    int transportPriority,
    char flags, MIGRtpsObjectId readerObjectId, 
    const struct MIGRtpsGuid *writerGuidIn, 
    const struct MIGRtpsBitmap *bitmap,
    REDAEpoch epoch,
    MIGAckKind ackKind,
    const struct MIGGeneratorSecurityProperty *security,
    struct REDAWorker *worker);

extern COMMENDDllExport RTIBool  COMMENDFacade_sendAppAck(
    struct COMMENDFacade *me, int *size,
    const struct REDAWeakReference* destinationArrayIn, int destinationCountIn,
    int transportPriority,
    char flags, MIGRtpsObjectId readerObjectId, 
    const struct MIGRtpsGuid *writerGuidIn,
    struct MIGRtpsAppAck * appAck,
    const struct MIGGeneratorSecurityProperty *security,
    struct REDAWorker *worker);

struct COMMENDFacadeProperty {
    /*e @brief The method used to generate the ids.
     
    Using the mac address or the ip address.
    */
    RTI_UINT32 autoIdKind;

    /*e @brief The RTPS Host Id associated with this COMMEND instance.
     
     Used to initialize the RTPS message interpreter and generator 
     objects (defined in the MIG module).
    */
    MIGRtpsHostId hostId;

    /*e @brief The RTPS App Id associated with this COMMEND instance.
     
     Used to initialize the RTPS message interpreter and generator 
     objects (MIG).
    */
    MIGRtpsAppId appId;

    /*e @brief The RTPS State Id associated with this COMMEND instance.
     
     <RTPS.2.0> Used to initialize the RTPS message interpreter and generator 
     objects (MIG).
    */
    MIGRtpsInstanceId instanceId;

    /*e @brief domainId.

     Used to give a meaningful name to the thread
    */
    int domainId;

    /*e @brief Either the App Id or the participant index

     Used to give a meaningful name to the thread
    */
    RTI_UINT32 threadAppId;

    /*e @brief Specifies if the previous field is the App Id or the participant index

     Used to give a meaningful name to the thread
    */
    RTIBool participantIndexSpecified;  

    struct RTIEventGeneratorProperty eventGenerator;
    struct RTIEventJobDispatcherProperty jobDispatcher;
    struct MIGGeneratorProperty messageGenerator;
    struct MIGInterpreterProperty interpreter;
    struct RTINetioReceiverProperty receiver;
    struct RTINetioSenderProperty sender;
};

extern COMMENDDllExport RTIBool
COMMENDFacadeProperty_verify(const struct COMMENDFacadeProperty *me);


#define COMMEND_FACADE_PROPERTY_DEFAULT {                     \
    0, /* autoIdKind */                                       \
    0, /* hostId */                                           \
    0, /* appId */                                            \
    0, /* instanceId */                                       \
    0, /* domainId */					      \
    0, /* threadAppId */				      \
    RTI_FALSE, /* participantIndexSpecified */		      \
    RTI_EVENT_GENERATOR_PROPERTY_DEFAULT,                     \
    RTI_EVENT_JOB_DISPATCHER_PROPERTY_DEFAULT,                \
    MIG_GENERATOR_PROPERTY_DEFAULT,                           \
    MIG_INTERPRETER_PROPERTY_DEFAULT,                         \
    RTI_NETIO_RECEIVER_PROPERTY_DEFAULT,                      \
    RTI_NETIO_SENDER_PROPERTY_DEFAULT                         }

struct COMMENDFacade {

    /*i peer access */
    COMMENDFacadeEntryportDescAddFunction addEntryport;
    /*i peer access */
    COMMENDFacadeEntryportDescRemoveFunction removeEntryport;
    /*i peer access */
    COMMENDFacadeEntryportDescCheckFunction checkEntryports;
    /*i peer access */
    COMMENDFacadeDestinationDescRemoveFunction removeDestination;

    /* <<uses>> */
    struct REDAWorkerFactory *_workerFactory;
    /* <<uses>> */
    struct REDAExclusiveArea *_ea;
    /* <<uses>> */
    struct REDADatabase      *_database;
    /* <<uses>> */
    struct RTIClock          *_clock;
    /* <<uses>> */
    struct RTIClock          *_timestampClock;
    /* <<has>> */
    struct RTIEventGenerator *_eventGenerator;
    /* <<has>> */
    struct RTIEventJobDispatcher *_jobDispatcher;
    /* <<has>> */
    struct RTINetioSender    *_sender;
    /* <<has>> */
    struct RTINetioReceiver  *_receiver;
    /* <<uses>> */
    struct RTINetioConfigurator *_configurator;
    /* <<has>> */
    struct MIGInterpreter    *_messageInterpreter;
    /* <<has>> */
    struct MIGGenerator      *_messageGenerator;
};

extern COMMENDDllExport RTIBool COMMENDFacade_postEvent(
    struct COMMENDFacade *me,
    const struct RTINtpTime *time, const struct RTINtpTime *snooze,
    const struct RTIEventGeneratorListener *listener,
    const struct RTIEventGeneratorListenerStorage *listenerStorage,
    int bytesToCompareInReuse);

extern COMMENDDllExport 
RTIBool COMMENDFacade_removeTokenBucket(
    struct COMMENDFacade *me,
    struct RTIEventJobDispatcherTokenBucket *tokenBucket, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
struct RTIEventJobDispatcherTokenBucket *COMMENDFacade_assertTokenBucketEDF(
    struct COMMENDFacade *me,
    const struct RTIEventJobDispatcherTokenBucketProperty *property, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
struct RTIEventJobDispatcherTokenBucket *COMMENDFacade_assertTokenBucketHPF(
    struct COMMENDFacade *me,
    const struct RTIEventJobDispatcherTokenBucketProperty *property, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
struct RTIEventJobDispatcherTokenBucket *COMMENDFacade_assertTokenBucketRR(
    struct COMMENDFacade *me,
    const struct RTIEventJobDispatcherTokenBucketProperty *property, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
RTIBool COMMENDFacade_getTokenBucketProperty(
    struct COMMENDFacade *me,
    struct RTIEventJobDispatcherTokenBucket *tokenBucket, 
    struct RTIEventJobDispatcherTokenBucketProperty *property, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
RTIBool COMMENDFacade_setTokenBucketProperty(
    struct COMMENDFacade *me,
    struct RTIEventJobDispatcherTokenBucket *tokenBucket, 
    const struct RTIEventJobDispatcherTokenBucketProperty *property, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
RTIBool COMMENDFacade_addTokensToBucket(
    struct COMMENDFacade *me,
    struct RTIEventJobDispatcherTokenBucket *tokenBucket, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
RTIBool COMMENDFacade_assertThread(
    struct COMMENDFacade *me,
    const struct RTIEventJobDispatcherStorage *threadStorage,
    struct REDAExclusiveArea *eaBeforeAgentFncs,
    const struct RTIEventJobDispatcherThreadProperty *property, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
RTIBool COMMENDFacade_removeThread(
    struct COMMENDFacade *me,
    struct RTIEventJobDispatcherThread *executionThread, 
    struct REDAWorker *worker);

extern COMMENDDllExport 
RTIBool 
COMMENDFacade_getInstalledTransportPluginCount(
    struct COMMENDFacade *me,
    int *pluginCountOut,
    struct REDAWorker *worker);

extern COMMENDDllExport 
RTIBool 
COMMENDFacade_getInstalledTransportPlugins(
    struct COMMENDFacade *me,
    NDDS_Transport_Plugin **pluginsOut,
    int *countIn,
    struct REDAWorker *worker);

extern COMMENDDllExport RTIBool COMMENDFacade_getTime(struct COMMENDFacade *me,
						      struct RTINtpTime *time);

extern COMMENDDllExport RTIBool COMMENDFacade_getTimestampTime(
    struct COMMENDFacade *me, struct RTINtpTime *time);

extern COMMENDDllExport RTIBool COMMENDFacade_isTimestampClockSameAsClock(
    struct COMMENDFacade *me);

struct COMMENDWorkerStat {
    /*e \brief timestamped as soon as \ref COMMENDWriterServiceWriteFunction 
     is entered
    */
    struct RTINtpTime timeSendEntered;
    /*e \brief timestamped right before \ref RTINetioSender_sendFast or
      \ref RTINetioSenderDestinationGroup_sendFast is invoked.

      Therefore, the send path traversal time's contribution to latency in
      COMMEND layer is timeSent - timeSendEntered
    */
    struct RTINtpTime timeSent;
    /*e \brief timestamped right before \ref COMMENDWriterServiceWriteFunction 
      returns to the higher layer.

      Since send is synchronous, the higher layer that called
      \ref COMMENDWriterServiceWriteFunction would be blocked for the
      (timeSendExited - timeSendEntered) duration, ignoring the time spent
      in calling and exiting a function.
    */
    struct RTINtpTime timeSendExited;    

    /*e \brief Timestamped as soon as the facade's
      \ref RTINetioReceiver_receiveFast is entered.

      For an active facade, which has multiple receivers spending most of their
      time blocked waiting for a message on an entryport, this time will be
      meaningless by itself until a valid message is received, and then will
      be overwritten as soon as the receiver finishes parsing and processing
      the received message.
    */
    struct RTINtpTime timeReceiveEntered;

    /*e \brief timestamped right before invoking the listener on the higher
     layer.

     @note For an RTPS message with multiple submessages, this timestamp will
     change for each hand-off of a valid submessage to the higher layer.
    */
    struct RTINtpTime timeHandedOff;

    /*e \brief timestamped right before exiting

     @note For an RTPS message with multiple submessages, this timestamp will
     change for each completion of parsing a valid submessage

     The post processing time in COMMEND layer can be estimated by
     (timeReceiveExited - timeHandedOff) - (time spent in higher layer)
    */
    struct RTINtpTime timeReceiveExited;
};

extern COMMENDDllExport RTIBool
COMMENDWorkerStat_init(struct REDAWorkerFactory *workerFactory);

extern COMMENDDllExport void
COMMENDWorkerStat_finalize(struct REDAWorkerFactory* manager,
                           struct REDAWorker *worker);

extern COMMENDDllExport void
COMMENDWorkerStat_print(const void *stat, const char *desc, int indent);

extern COMMENDDllExport RTIBool
COMMENDWorkerStat_getStorageLazy(struct COMMENDWorkerStat **statPtr, 
				 struct REDAWorker *worker);


  #define COMMEND_PUBLICATION_PRIORITY_UNDEFINED (0)
  #define COMMEND_PUBLICATION_PRIORITY_AUTOMATIC (-1)


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "commend/commend_facade_impl.h"

#endif /* commend_facade_h */
