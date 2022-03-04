/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)mig_interpreter.h    generated by: makeheader    Fri Apr 23 00:06:31 2021
 *
 *		built from:	interpreter.ifc
 */

#ifndef mig_interpreter_h
#define mig_interpreter_h


  #ifndef osapi_ntptime_h
    #include "osapi/osapi_ntptime.h"
  #endif
  #ifndef netio_common_h
    #include "netio/netio_common.h"
  #endif
  #ifndef reda_worker_h
    #include "reda/reda_worker.h"
  #endif
  #ifndef reda_weakReference_h
    #include "reda/reda_weakReference.h"
  #endif
  #ifndef reda_database_h
    #include "reda/reda_database.h"
  #endif
  #ifndef netio_cap_include_manager_h
    #include "netio_cap/netio_cap_manager.h"
  #endif
  #ifndef mig_dll_h
    #include "mig/mig_dll.h"
  #endif
  #ifndef mig_rtps_h
    #include "mig/mig_rtps.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


/* security */
#define MIG_INTERPRETER_CONTEXT_NUM_DECODE_BUFFERS 2

struct MIGInterpreter;

struct RTIClock; /* forward declare to appease compiler */

struct REDABuffer;

struct REDAWorker;

struct REDACursor;

struct RTIEventActiveObjectListener;

struct RTINetioMessage;

struct MIGInterpreterContext {
    /*e RTPS message version */
    MIGRtpsProtocolVersion version;
    /*e RTPS implementation vendor ID of the source */
    MIGRtpsVendorId        vendorId;
    /*e */
    MIGRtpsHostId          sourceHostId;
    /*e */
    MIGRtpsAppId           sourceAppId;
    /*e */
    MIGRtpsInstanceId         sourceInstanceId; /*RTPS.2.0*/
    /*e */
    MIGRtpsHostId          destinationHostId;
    /*e */
    MIGRtpsAppId           destinationAppId;
    /*e */
    MIGRtpsInstanceId         destinationInstanceId; /*RTPS.2.0*/
    /*e */
    NDDS_Transport_Address_t        unicastReplyIp;
    /*e */
    NDDS_Transport_Port_t           unicastReplyPort;
    /*e */
    NDDS_Transport_Address_t        multicastReplyIp;
    /*e */
    NDDS_Transport_Port_t           multicastReplyPort;
    /*e Valid iff haveTimestamp is true */
    struct RTINtpTime      timestamp;
    /*e @see timestamp */
    RTIBool                haveTimestamp;

    MIGRtpsDataFlags    dataExtraFlags;

    RTI_UINT16  dataOctetsToInlineQos;

    /*e */
    MIGRtpsObjectId        readerObjectId;
    /*e */
    MIGRtpsObjectId        writerObjectId;

    /*e */
    MIGRtpsSubmessageId    submessageId;
    /*e Raw, undeserialized and (possibly) unaligned user data */
    struct REDABuffer      data; /* #6672 */
    /*e gives more context to each submessage */
    char                   submessageFlags;

    /* immutables */
    MIGRtpsHostId         _myHostId;
    MIGRtpsAppId          _myAppId;
    MIGRtpsInstanceId        _myInstanceId; /*RTPS.2.0*/
    /* mutable */
    MIGRtpsObjectId      _myObjectId;

    /* optimization to reduce latency */
    struct REDACursor    *_cursor;

    /*
     * These buffers are used for security cryptographic operations.
     * There are two buffers: one for a decoded RTPS message and one for the
     * decoded submessages.
     * The buffer used for the decoded submessages must be large enough to
     * hold all submessages that can fit in the transport buffer.
     */
    struct REDABuffer _decodeBuffers[MIG_INTERPRETER_CONTEXT_NUM_DECODE_BUFFERS];
};

extern MIGDllExport RTIBool
MIGInterpreterContext_needsByteSwap(const struct MIGInterpreterContext *contex);


extern	MIGDllExport void
MIGInterpreterContext_deserializeSubmessageDataLength(
        const struct MIGInterpreterContext *context,
        char **dataPtr);

struct MIGInterpreterStat {
    /* count for each type of submessages received */
    unsigned int submessageCount[MIG_RTPS_SUBMESSAGE_ID_COUNT_MAX];
    unsigned int successfulParseCount;
    unsigned int bufferLengthFailedCount;
    unsigned int nonRtpsMessageCount;
    unsigned int versionMismatchCount;
    unsigned int submessageDataLengthFailedCount;
    unsigned int unknownSubmessageCount;

    /* corrupted_rtps_message_count_change will be reset only by the public API
     * call - get_participant_protocol_status() */
    RTI_INT64 corruptedRtpsMessageCountChange;
    /* Below two statistics can be retrieved from
     * DomainParticipantProtocolStatus. Hence the table ea needs to be taken
     * before updating them. The corruptedRtpsMessageCount is incremented when 
     * the checksum present in the MIG_RTPS_CRC32 submessage is not equal to 
     * the computed checksum.
     * */
    RTI_INT64 corruptedRtpsMessageCount;
    struct RTINtpTime lastCorruptedMessageTS;
};


#define MIGInterpreterStat_INITIALIZER {                         \
    {0}, /* submessageCount[MIG_RTPS_SUBMESSAGE_ID_COUNT_MAX] */ \
    0, /* successfulParseCount */                                \
    0, /* bufferLengthFailedCount */                             \
    0, /* nonRtpsMessageCount */                                 \
    0, /* versionMismatchCount */                                \
    0, /* submessageDataLengthFailedCount */                     \
    0, /* unknownSubmessageCount */                              \
    0, /* corruptedRtpsMessageCountChange */                     \
    0, /* corruptedRtpsMessageCount */                           \
    {-1,0} /* lastCorruptedMessageTS */                          \
}

#define MIGInterpreterStat_initialize(p) {                              \
        struct MIGInterpreterStat d = MIGInterpreterStat_INITIALIZER;   \
        RTIOsapiMemory_copy(p, &d, sizeof(struct MIGInterpreterStat));  \
}

struct MIGInterpreterForwarder;


/*e \ingroup MIGInterpreterClass

  \brief Forwards decoding of a message or submessage to PRES.

  @param decodedBuffer \b Out.  The result of decoding the input

  @param encodedBuffer \b In.  The input

  @param isMultiSubmessage \b In.  True if this operation is decoding the whole
      rtps message; false if it's just decoding a submessage

  @param remoteParticipantId \b In. GUID prefix of the sender

  @param worker \b In. identifies the receiver thread that is parsing the
  message.
*/
typedef RTIBool
(*MIGInterpreter_DecodeFunction)(
    const struct MIGInterpreterForwarder *forwarder,
    struct REDABuffer *decodedBuffer,
    const struct REDABuffer *encodedBuffer,
    RTIBool isMultiSubmessage,
    const MIGRtpsParticipantId *remoteParticipantId,
    struct REDAWorker *worker);


struct MIGInterpreterForwarder {
    MIGInterpreter_DecodeFunction decode;
};



struct MIGInterpreterProperty {
    /*e boolean property can be encoded compactly as a bit */
    int bitmap;
    /*e \brief Enforces that the submessages are aligned to 4-bytes as specified
     * in the RTPS protocol.
     *
     * When enabled (default) we will not interoperate with non-patched 4.5d
     * and earlier versions if using data fragmentation.
     */
    RTIBool enforceSubmessageAlignment;
    /*e security: preallocate buffers to store the output of decode 
      operations */
    RTIBool canDecode;
    /*e security: with some exceptions, like participant simple discovery and
      stateless authentication handshake messages */
    RTIBool mustDecodeRtpsMessage;
    /*e \brief Specifies if RTPS CRC32 checksum needs to be validated
     *  Used to collect statistics of corrupted RTPS messages.
     */
    RTIBool crcEnabled;
    /*e control growth of interpreter table */
    struct REDATableProperty listener;
    /*e functions to forward to PRES */
    struct MIGInterpreterForwarder *forwarder;
};


#define MIG_INTERPRETER_PROPERTY_DEFAULT { \
    0,  /* bitmap */                       \
    RTI_TRUE,   /* enforceSubmessageAlignment */ \
    RTI_FALSE,  /* canDecode */             \
    RTI_FALSE,  /* mustDecodeRtpsMessage */ \
    RTI_FALSE,  /* crcEnabled */ \
    /* listener */  \
    {{32, REDA_FAST_BUFFER_POOL_UNLIMITED, REDA_FAST_BUFFER_POOL_UNLIMITED}, \
     9   /* hashBucketCount */},            \
    NULL /* forwarder */ \
}

extern MIGDllExport
void MIGInterpreter_getProperty(
        struct MIGInterpreter *me,
        struct MIGInterpreterProperty *property);

extern MIGDllExport
void MIGInterpreter_setProperty(
        struct MIGInterpreter *me,
        const struct MIGInterpreterProperty *property);

extern MIGDllExport RTIBool
MIGInterpreter_shutdown(struct MIGInterpreter *me, struct REDAWorker *worker);

extern MIGDllExport
struct MIGInterpreter * MIGInterpreter_new(
        struct REDADatabase *database,
        struct REDAExclusiveArea *ea,
        MIGRtpsHostId hostId,
        MIGRtpsAppId appId,
        MIGRtpsInstanceId instanceId, /*RTPS.2.0*/
        struct RTIEventActiveObjectListener *listener,
        const struct MIGInterpreterProperty *property,
        struct RTIClock *clock,
        struct RTINetioCapManager *netioCapManager,
        struct REDAWorker *worker);

extern MIGDllExport void
MIGInterpreter_delete(struct MIGInterpreter *me,
		      struct REDAWorker *worker);

extern MIGDllExport
void MIGInterpreter_getStat(
        struct MIGInterpreter *me,
        struct MIGInterpreterStat *stat,
        RTIBool clearChange,
        struct REDAWorker *worker);

struct MIGInterpreterWorkerStat {
    /*e Timestamped as soon as \ref MIGInterpreter_parse is entered */
    struct RTINtpTime timeParseEntered;
    /*e stamped right before user listener is called.  If the worker calls
       multiple listeners in sequence, only the last timestamp is kept.
    */
    struct RTINtpTime timeCalledBack;
    /*e Timestamped right before \ref MIGInterpreter_parse is exited */
    struct RTINtpTime timeParseExited;
};

extern MIGDllExport RTIBool
MIGInterpreterWorkerStat_init(struct REDAWorkerFactory *workerFactory);

extern MIGDllExport void
MIGInterpreterWorkerStat_finalize(struct REDAWorkerFactory *workerFactory,
                                  struct REDAWorker *worker);


  #define MIG_INTERPRETER_WORKER_STAT_STRING_LENGTH (70)

extern MIGDllExport char *
MIGInterpreterWorkerStat_toString(const void *me, struct REDABuffer *buffer);

extern MIGDllExport RTIBool
MIGInterpreterWorkerStat_getStorageLazy(
    struct MIGInterpreterWorkerStat **statPtr, struct REDAWorker *worker);

extern MIGDllExport struct MIGInterpreterContext *
MIGInterpreter_getContext(
        struct MIGInterpreter *me,
        RTIBool resetContext,
        struct REDAWorker *worker);

struct MIGInterpreterListenerStorage {
    void *field[8];
};


  #define MIG_INTERPRETER_LISTENER_STORAGE_INITIALIZER \
      {{NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}}

struct MIGInterpreterListener; /* forward declare to appease compiler */

typedef void (*MIGInterpreterListenerOnMatchCallback)(
    const struct MIGInterpreterListener* me,
    const struct MIGInterpreterContext *context,
    const struct RTINtpTime *timestamp,
    const struct MIGInterpreterListenerStorage *storage,
    int submessageSize,
    struct REDAWorker *worker);

struct MIGInterpreterListener {
    /*e Called for message matching the requested key */
    MIGInterpreterListenerOnMatchCallback onMatch;
};

extern MIGDllExport void
MIGInterpreter_parse(
        struct MIGInterpreter *me,
        struct MIGInterpreterContext *context,
        const struct RTINetioMessage *message,
        struct REDAWorker *worker);

struct MIGInterpreterListenerKey {
    /*e interested messages coming from this GUID */
    struct MIGRtpsGuid guid;
    /*e to this local object; if message has MIG_RTPS_OBJECT_ID_UNKNOWN,
      it is considered a wildcard and that message will be delivered to
      ANY object that expressed interested in matching GUID */
    MIGRtpsObjectId oid;
};


  #define MIG_INTERPRETER_LISTENER_KEY_STRING_LENGTH (55)

extern MIGDllExport const char *
MIGInterpreterListenerKey_toString(const void *me, struct REDABuffer *str);

extern MIGDllExport int
MIGInterpreterListenerKey_compare(void *l, void *r);

extern MIGDllExport void
MIGInterpreterListenerKey_print(const void *data, const char *desc, int indent);

extern MIGDllExport RTIBool
MIGInterpreter_assertListener(
    struct MIGInterpreter *me,
    const struct MIGInterpreterListenerKey *key,
    const struct MIGInterpreterListener *listener,
    const struct MIGInterpreterListenerStorage *storage,
    struct REDAWorker *worker);

extern MIGDllExport RTIBool
MIGInterpreter_removeListener(struct MIGInterpreter *me,
			      const struct MIGInterpreterListenerKey *key,
			      struct REDAWorker *worker);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "mig/mig_interpreter_impl.h"

#endif /* mig_interpreter_h */
