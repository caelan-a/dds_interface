/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)mig_rtps_impl.h    generated by: makeheader    Fri Apr 23 00:06:32 2021
 *
 *		built from:	rtps_impl.ifc
 */

#ifndef mig_rtps_impl_h
#define mig_rtps_impl_h

extern MIGDllVariable const char *
MIG_RTPS_SUBMESSAGE_ID_NAME[MIG_RTPS_SUBMESSAGE_ID_COUNT_MAX];



#ifndef reda_sequenceNumber_h
#include "reda/reda_sequenceNumber.h"
#endif
#ifndef reda_orderedDataType_h
#include "reda/reda_orderedDataType.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif



/* --------------------------------------------------------- */
    /* DO NOT USE! The isReserved macro is deprecated and should not be used
       anymore. Use MIGRtpsObjectSuffix_isUser or
       MIGRtpsObjectSuffix_isVendorSpecific below. See CORE-6948 for details. */
  #define MIGRtpsObjectSuffix_isReserved(osx) \
    ((osx) & MIG_RTPS_OBJECT_KIND_R_BIT)

  #define MIGRtpsObjectSuffix_isMeta(osx) \
    ((osx) & MIG_RTPS_OBJECT_KIND_M_BIT)

  /* This macro checks for the combination of 00 in the two most-significant
   * bits of the entityKind. This is the bit combination that is used by the
   * DDS specification for user-defined entities. This check covers all
   * entities that are accessible to the user. */
  #define MIGRtpsObjectSuffix_isUser(osx) \
    (!((osx) & MIG_RTPS_OBJECT_KIND_M_BIT) && \
     !((osx) & MIG_RTPS_OBJECT_KIND_R_BIT) )

  #define MIGRtpsObjectSuffix_isVirtual(osx) \
    (((osx) == MIG_RTPS_OBJECT_NORMAL_USER_VIRTUAL_SUBSCRIPTION || \
      (osx) == MIG_RTPS_OBJECT_NORMAL_USER_VIRTUAL_CST_READER || \
      (osx) == MIG_RTPS_OBJECT_NORMAL_USER_VIRTUAL_READER_GROUP || \
      (osx) == MIG_RTPS_OBJECT_NORMAL_USER_VIRTUAL_TOPIC) ? \
      RTI_TRUE : RTI_FALSE)

  #define MIGRtpsObjectSuffix_isKeyed(osx) \
    (((osx) == MIG_RTPS_OBJECT_NORMAL_USER_CST_WRITER || \
      (osx) == MIG_RTPS_OBJECT_RESERVED_META_CST_WRITER || \
      (osx) == MIG_RTPS_OBJECT_NORMAL_USER_CST_READER || \
      (osx) == MIG_RTPS_OBJECT_RESERVED_META_CST_READER) ? \
      RTI_TRUE : RTI_FALSE)

  /* This macro checks for entities that were explicitly created by the user.
   * This check will exclude virtual entities that the user still has access
   * to, such as the builtin readers and topics  */
  #define MIGRtpsObjectSuffix_isUserCreated(osx) \
    (MIGRtpsObjectSuffix_isUser(osx) && \
     !MIGRtpsObjectSuffix_isVirtual(osx))

  /* This macro checks for the combinations of 01 or 10 in the two
   * most-significant bits of the entityKind. These are the bit combinations
   * that are used by the DDS specification for vendor-specific entities */
  #define MIGRtpsObjectSuffix_isVendorSpecific(osx) \
    ((!((osx) & MIG_RTPS_OBJECT_KIND_M_BIT) && \
      ((osx) & MIG_RTPS_OBJECT_KIND_R_BIT)) || \
     (((osx) & MIG_RTPS_OBJECT_KIND_M_BIT) && \
      !((osx) & MIG_RTPS_OBJECT_KIND_R_BIT)))

/* --------------------------------------------------------- */
  #define MIGRtpsObjectSuffix_getRWType(osx) \
    ((((osx) & 0x3F) == 0x02 || ((osx) & 0x3F) == 0x03) ? \
     MIG_RTPS_RW_TYPE_WRITER :                            \
    ((((osx) & 0x3F) == 0x04 || ((osx) & 0x3F) == 0x07 || \
      ((osx) & 0x3F) == 0x3C || ((osx) & 0x3F) == 0x3D) ? \
     MIG_RTPS_RW_TYPE_READER : MIG_RTPS_RW_TYPE_UNKNOWN))

/* --------------------------------------------------------- */
  #define MIGRtpsObjectSuffix_getSampleType(osx) \
    ((((osx) & 0x3F) == 0x02 || ((osx) & 0x3F) == 0x07 || \
      ((osx) & 0x3F) == 0x3D) ?                           \
     MIG_RTPS_SAMPLE_TYPE_CST :                           \
    ((((osx) & 0x3F) == 0x03 || ((osx) & 0x3F) == 0x04 || \
      ((osx) & 0x3F) == 0x3C) ? \
     MIG_RTPS_SAMPLE_TYPE_PS : MIG_RTPS_SAMPLE_TYPE_UNKNOWN))

/* --------------------------------------------------------- */

/* --------------------------------------------------------- */
  /*RTPS.2.0*/
  #define MIGRtpsGuid_toString REDAOrderedDataType_toStringQuadInt
/* --------------------------------------------------------- */
  /*RTPS.2.0*/
  #define MIGRtpsGuid_copy(to, from) \
    (to)->prefix.hostId    = (from)->prefix.hostId;  \
    (to)->prefix.appId    = (from)->prefix.appId;  \
    (to)->prefix.instanceId    = (from)->prefix.instanceId;  \
    (to)->objectId = (from)->objectId;

/* --------------------------------------------------------- */
  /*RTPS.2.0*/
  #define MIGRtpsGuid_equals(a, b)   \
    RTIOsapiRtpsGuid_equals(a, b)

/* --------------------------------------------------------- */
  #define MIGRtpsGuid_isUnknown(me)   \
    ((me)->prefix.hostId   == MIG_RTPS_HOST_ID_UNKNOWN && \
     (me)->prefix.appId    == MIG_RTPS_APP_ID_UNKNOWN &&  \
     (me)->prefix.instanceId    == MIG_RTPS_INSTANCE_ID_UNKNOWN &&  \
     (me)->objectId == MIG_RTPS_OBJECT_ID_UNKNOWN)

/* --------------------------------------------------------- */
  #define MIGRtpsGuid_isAuto(me)   \
    ((me)->prefix.hostId   == MIG_RTPS_HOST_ID_AUTO && \
     (me)->prefix.appId    == MIG_RTPS_APP_ID_AUTO &&  \
     (me)->prefix.instanceId    == MIG_RTPS_INSTANCE_ID_AUTO &&  \
     (me)->objectId == MIG_RTPS_OBJECT_ID_AUTO)

/* --------------------------------------------------------- */
  #define MIGRtpsGuid_expand(me) \
    (me)->prefix.hostId, \
    (me)->prefix.appId, \
    (me)->prefix.instanceId, \
    (me)->objectId

/* --------------------------------------------------------- */
  #define MIGRtpsGuidPrefix_isUnknown(me)   \
    ((me)->hostId   == MIG_RTPS_HOST_ID_UNKNOWN && \
     (me)->appId    == MIG_RTPS_APP_ID_UNKNOWN &&  \
     (me)->instanceId    == MIG_RTPS_INSTANCE_ID_UNKNOWN)

/* --------------------------------------------------------- */
  #define MIGRtpsGuidPrefix_setUnknown(me)   \
    (me)->hostId = MIG_RTPS_HOST_ID_UNKNOWN; \
    (me)->appId = MIG_RTPS_APP_ID_UNKNOWN;  \
    (me)->instanceId = MIG_RTPS_INSTANCE_ID_UNKNOWN

/* --------------------------------------------------------- */
  #define MIGRtpsGuid_setUnknown(me)   \
    MIGRtpsGuidPrefix_setUnknown(&((me)->prefix)); \
    (me)->objectId = MIG_RTPS_OBJECT_ID_UNKNOWN

/* --------------------------------------------------------- */
  #define MIGRtpsGuidPrefix_expand(me) \
    (me)->hostId, \
    (me)->appId, \
    (me)->instanceId

/* --------------------------------------------------------- */
  /*RTPS.2.0*/
  #define MIGRtpsParticipantId_equals(a, b) \
    RTIOsapiRtpsGuidPrefix_equals(a, b)

#define MIGRtpsGuidPrefix_equals MIGRtpsParticipantId_equals

#define MIGRtpsGuidPrefix_copy(me, src) \
    (me)->hostId = (src)->hostId;  \
    (me)->appId = (src)->appId;  \
    (me)->instanceId = (src)->instanceId;

/* --------------------------------------------------------- */
  #define MIGRtpsObjectId_getObjectKey(oid) \
    ((MIGRtpsObjectKey)((oid) >> 8))
/* --------------------------------------------------------- */
  #define MIGRtpsObjectId_getObjectSuffix(oid) \
    ((MIGRtpsObjectSuffix)((oid) & 0x000000ff))
/* --------------------------------------------------------- */
  #define MIGRtpsObjectId_generate(oky, osx) \
    ((MIGRtpsObjectId)(((oky) << 8) | (osx)))
/* --------------------------------------------------------- */
/* Only objects that are exposed in the dds_c layer have user objects.
 * This includes:
 * 1) All non-meta entities (those that are not used for discovery).
 * 2) Non-anonymous vendor-specific meta-entities.
 * 3) Security-related meta-entities.
 */
  #define MIGRtpsObjectId_hasUserObject(oid) \
  ((!MIGRtpsObjectSuffix_isMeta(MIGRtpsObjectId_getObjectSuffix(oid))) || \
   ((MIGRtpsObjectSuffix_isMeta(MIGRtpsObjectId_getObjectSuffix(oid))) && \
    (((!MIGRtpsObjectSuffix_isReserved(MIGRtpsObjectId_getObjectSuffix(oid))) && \
      (oid != MIG_RTPS_OBJECT_ID_LOCATOR_PING_MESSAGE_WRITER) && \
      (oid != MIG_RTPS_OBJECT_ID_LOCATOR_PING_MESSAGE_READER)) || \
     (oid == MIG_RTPS_OBJECT_ID_STATELESS_MESSAGE_WRITER) || \
     (oid == MIG_RTPS_OBJECT_ID_STATELESS_MESSAGE_READER) || \
     (oid == MIG_RTPS_OBJECT_ID_SECURE_VOLATILE_MESSAGE_WRITER) || \
     (oid == MIG_RTPS_OBJECT_ID_SECURE_VOLATILE_MESSAGE_READER))))
/* --------------------------------------------------------- */
/* These endpoints bootstrap security and therefore never encode anything. */
  #define MIGRtpsObjectId_isNeverEncodingWriter(oid) \
    (((oid) == MIG_RTPS_OBJECT_ID_SPDP_PARTICIPANT_WRITER) || \
    ((oid) == MIG_RTPS_OBJECT_ID_STATELESS_MESSAGE_WRITER))
  #define MIGRtpsObjectId_isNeverEncodingReader(oid) \
    (((oid) == MIG_RTPS_OBJECT_ID_SPDP_PARTICIPANT_READER) || \
    ((oid) == MIG_RTPS_OBJECT_ID_STATELESS_MESSAGE_READER))
/* --------------------------------------------------------- */
/*
 * This macro checks if the endpoint supports directed writes.
 * Currently, the only endpoints not supporting directed writes are the pure
 * anonymous ones. For more information about "pure" and "non-pure" anonymous
 * endpoints, please refer to COMMENDAnonWriterService.
 */
  #define MIGRtpsObjectId_supportsDirectedWrites(oid) \
    (((oid) != MIG_RTPS_OBJECT_ID_SPDP_PARTICIPANT_WRITER) && \
     ((oid) != MIG_RTPS_OBJECT_ID_LOCATOR_PING_MESSAGE_WRITER))
/* --------------------------------------------------------- */
/*
 * This macro checks if the endpoint is a secure builtin endpoint.
 */
  #define MIGRtpsObjectId_isSecureBuiltin(oid) \
    ((MIGRtpsObjectSuffix_isMeta(MIGRtpsObjectId_getObjectSuffix(oid))) \
        && ((0xFF000000 & oid) == 0xFF000000))
/* --------------------------------------------------------- */
/*
 * This macro checks if the endpoint is a non-secure builtin endpoint.
 */
  #define MIGRtpsObjectId_isNonSecureBuiltin(oid) \
    ((MIGRtpsObjectSuffix_isMeta(MIGRtpsObjectId_getObjectSuffix(oid))) \
        && ((0xFF000000 & oid) != 0xFF000000))
/* --------------------------------------------------------- */
/*
 * This macro checks if the endpoint supports using the secure volatile channel
 * for key exchange. With the exception of the secure volatile endpoints
 * themselves, this includes all the endpoints exposed to the user and
 * secure builtin endpoints.
 */
  #define MIGRtpsObjectId_supportsKeyExchange(oid) \
    (((oid) != MIG_RTPS_OBJECT_ID_SECURE_VOLATILE_MESSAGE_WRITER) \
            && ((oid) != MIG_RTPS_OBJECT_ID_SECURE_VOLATILE_MESSAGE_READER) \
            && (MIGRtpsObjectId_hasUserObject(oid) \
                    || ((0xFF000000 & (oid)) == 0xFF000000)))

/* --------------------------------------------------------- */
/* This macro checks if a given entity is stateless. Currently, this means
 * that the commend entity is anonymous. Since this macro uses instance ids
 * as input, it also requires providing isMeta and isVendor flags. Note that
 * we are shifting the reference object-ids, and therefore we only need to use
 * one of them (writer or reader) per channel. */
  #define MIGRtpsObjectKey_isStateless(oky, isMeta, isVendor) \
  (!isMeta ? RTI_FALSE : \
    (isVendor ? \
      (oky == (MIG_RTPS_OBJECT_ID_LOCATOR_PING_MESSAGE_WRITER >> 8)) \
    : \
      ((oky == (MIG_RTPS_OBJECT_ID_SPDP_PARTICIPANT_WRITER >> 8)) || \
       (oky == (MIG_RTPS_OBJECT_ID_STATELESS_MESSAGE_WRITER >> 8)))) \
  )

/* --------------------------------------------------------- */
  #define MIGRtpsGuid_getObjectSuffix(guid) \
    ((MIGRtpsObjectSuffix)((guid)->objectId & 0x000000ff))
/* --------------------------------------------------------- */
  #define MIGRtpsProtocolVersion_getMajor(version) (*(version) >> 8)
/* --------------------------------------------------------- */
  #define MIGRtpsProtocolVersion_getMinor(version) (*(version) & 0x00ff)

/* --------------------------------------------------------- */
  #define MIGRtpsVendorId_isPro(vendor) \
          (*(vendor) == MIG_RTPS_VENDOR_ID_RTI)

/* --------------------------------------------------------- */
  #define MIGRtpsVendorId_isMicro(vendor) \
          (*(vendor) == MIG_RTPS_VENDOR_ID_RTI_MICRO)

/* --------------------------------------------------------- */
  #define MIGRtpsVendorId_isRTI(vendor) \
        (MIGRtpsVendorId_isPro(vendor) || MIGRtpsVendorId_isMicro(vendor))

/* --------------------------------------------------------- */
  #define MIGRtpsVendorId_getMajor(vendor)         (*(vendor) >> 8)
/* --------------------------------------------------------- */
  #define MIGRtpsVendorId_getMinor(vendor)         (*(vendor) & 0x00ff)

/* --------------------------------------------------------- */
  #define MIGRtpsSequenceNumber_deserializeMacro(sn, streamPtr, needByteSwap) \
    (                                                                  \
      needByteSwap ? (                                                 \
        *(((char *)(&((sn)->high))) + 3) = *((*(streamPtr))++),        \
        *(((char *)(&((sn)->high))) + 2) = *((*(streamPtr))++),        \
        *(((char *)(&((sn)->high))) + 1) = *((*(streamPtr))++),        \
        *(((char *)(&((sn)->high)))    ) = *((*(streamPtr))++),        \
        *(((char *)(&((sn)->low)))  + 3) = *((*(streamPtr))++),        \
        *(((char *)(&((sn)->low)))  + 2) = *((*(streamPtr))++),        \
        *(((char *)(&((sn)->low)))  + 1) = *((*(streamPtr))++),        \
        *(((char *)(&((sn)->low)))     ) = *((*(streamPtr))++),        \
        RTI_TRUE                                                       \
      ) : (                                                            \
        (sn)->high = *((RTI_INT32 *)(*(streamPtr))), *(streamPtr) += 4,\
	(sn)->low = *((RTI_UINT32 *)(*(streamPtr))), *(streamPtr) += 4,\
        RTI_TRUE                                                       \
      )                                                                \
    )

  #ifndef RTI_PRECONDITION_TEST
    #define MIGRtpsSequenceNumber_deserialize \
      MIGRtpsSequenceNumber_deserializeMacro
  #endif

/* --------------------------------------------------------- */
  #define MIGRtpsEpoch_deserializeMacro(me, streamPtr, needByteSwap) \
    (                                                                 \
      needByteSwap ? (                                                \
        *(((char *)(me)) + 3) = *((*(streamPtr))++),                  \
        *(((char *)(me)) + 2) = *((*(streamPtr))++),                  \
        *(((char *)(me)) + 1) = *((*(streamPtr))++),                  \
        *(((char *)(me))    ) = *((*(streamPtr))++),                  \
        RTI_TRUE                                                      \
      ) : (                                                           \
        *(me) = *((REDAEpoch*)(*(streamPtr))), *(streamPtr) += 4,     \
        RTI_TRUE                                                      \
      )                                                               \
    )

  #ifndef RTI_PRECONDITION_TEST
    #define MIGRtpsEpoch_deserialize MIGRtpsEpoch_deserializeMacro
  #endif

/* --------------------------------------------------------- */
    #define MIGRtps_deserializeUnsignedShortMacro(twobytes, data, needByteSwap) \
    (                                                                           \
        needByteSwap ? (                                                        \
            *(((char *)(twobytes)) + 1) = *((*(data))++),                       \
            *(((char *)(twobytes))    ) = *((*(data))++),                       \
            RTI_TRUE                                                            \
        ) : (                                                                   \
            *(twobytes) = *((unsigned short *)(*(data))),                       \
            *(data) += 2,                                                       \
            RTI_TRUE                                                            \
        )                                                                       \
    )                                                                           \

    #ifndef RTI_PRECONDITION_TEST
        #define MIGRtps_deserializeUnsignedShort MIGRtps_deserializeUnsignedShortMacro
    #endif

/* --------------------------------------------------------- */
    #define MIGRtps_deserializeUnsignedLongMacro(fourbytes, data, needByteSwap) \
    (                                                                           \
        needByteSwap ? (                                                        \
            *(((char *)(fourbytes)) + 3) = *((*(data))++),                      \
            *(((char *)(fourbytes)) + 2) = *((*(data))++),                      \
            *(((char *)(fourbytes)) + 1) = *((*(data))++),                      \
            *(((char *)(fourbytes))    ) = *((*(data))++),                      \
            RTI_TRUE                                                            \
        ) : (                                                                   \
            *(fourbytes) = *((RTI_UINT32 *)(*(data))),                       \
            *(data) += 4,                                                       \
            RTI_TRUE                                                            \
        )                                                                       \
    )                                                                           \

    #ifndef RTI_PRECONDITION_TEST
        #define MIGRtps_deserializeUnsignedLong MIGRtps_deserializeUnsignedLongMacro
    #endif

/* --------------------------------------------------------- */
    #define MIGRtps_skipNBytesFast(stream, n) \
	stream+=n

/* --------------------------------------------------------- */
    #define MIGRtpsGuidPrefix_compareMacro(left, right) \
        (((left)->hostId > (right)->hostId) ? 1 : \
          (((left)->hostId < (right)->hostId) ? -1 : \
           (((left)->appId > (right)->appId) ? 1 : \
            (((left)->appId < (right)->appId) ? -1 : \
             (((left)->instanceId > (right)->instanceId) ? 1 : \
              (((left)->instanceId < (right)->instanceId) ? -1 : 0))))))

  #ifndef RTI_PRECONDITION_TEST
    #define MIGRtpsGuidPrefix_compare MIGRtpsGuidPrefix_compareMacro
  #endif

/* --------------------------------------------------------- */
    #define MIGRtpsGuid_compareMacro(left,right) \
        (((left)->prefix.hostId > (right)->prefix.hostId) ? 1 : \
          (((left)->prefix.hostId < (right)->prefix.hostId) ? -1 : \
           (((left)->prefix.appId > (right)->prefix.appId) ? 1 : \
            (((left)->prefix.appId < (right)->prefix.appId) ? -1 : \
             (((left)->prefix.instanceId > (right)->prefix.instanceId) ? 1 : \
              (((left)->prefix.instanceId < (right)->prefix.instanceId) ? -1 : \
               (((left)->objectId > (right)->objectId) ? 1 : \
                (((left)->objectId < (right)->objectId) ? -1 : 0))))))))

  #ifndef RTI_PRECONDITION_TEST
    #define MIGRtpsGuid_compare MIGRtpsGuid_compareMacro
  #endif

/* --------------------------------------------------------- */
struct MIGRtpsBitmap {
    /* lead sequence */
    struct REDASequenceNumber _lead;
    /* The size of the bitmap in the number of bits. */
    RTI_INT32 _bitCount;
    /* The bitmap stored as an array of integers.

       NOTE1: This must be unsigned in order to apply the >> operator.
       NOTE2: There are two approaches to handle bits outside bitCount:
                  1) They must always be zeroed.
		  2) They can be anything.
	      The first approach puts the burden on otherwise simple
	      methods such as truncate to zero out truncated bits, whereas
	      the second approach puts the burden on methods such as shift
	      to make sure bits beyond the bitCount are not shifted in.
	      In our implementation, we have opted for the second approach. */
    RTI_UINT32 _bits[MIG_RTPS_BITMAP_32BITS_ARRAY_SIZE_MAX];
};



  #define MIGRtpsBitmap_INITIALIZER { \
    REDA_SEQUENCE_NUMBER_ZERO, /* _lead */ \
    0, /* _bitCount */ \
    {0, 0, 0, 0, 0, 0, 0, 0}, /* _bits */ \
  }


/* --------------------------------------------------------- */
  #define MIGRtpsBitmap_getLead(a) (&(a)->_lead)
/* --------------------------------------------------------- */
  #define MIGRtpsBitmap_getBitCount(a) (a)->_bitCount
/* --------------------------------------------------------- */
  #define MIGRtpsBitmap_resetMacro(a, seqNum, bitCount)                     \
  {                                                                    \
    register int MIGRtpsBitmap_g_resetI = 0;                           \
    (a)->_lead = *(seqNum);                                            \
    (a)->_bitCount = (bitCount);                                       \
    for (MIGRtpsBitmap_g_resetI=0;                                     \
         MIGRtpsBitmap_g_resetI<MIG_RTPS_BITMAP_32BITS_ARRAY_SIZE_MAX; \
         ++MIGRtpsBitmap_g_resetI) {                                   \
        (a)->_bits[MIGRtpsBitmap_g_resetI] = 0;                      \
    }                                                                  \
  }
  #ifndef RTI_PRECONDITION_TEST
    #define MIGRtpsBitmap_reset MIGRtpsBitmap_resetMacro
  #endif

/* --------------------------------------------------------- */
  #define MIGRtpsBitmap_getSerializedSize(bitmap) \
      12 + sizeof(RTI_INT32)*(((bitmap)->_bitCount + 31)/32)

  #define MIGRtpsSubmessageId_toString(id) MIG_RTPS_SUBMESSAGE_ID_NAME[id]

/* --------------------------------------------------------- */


extern MIGDllExport
RTIBool MIGRtps_serialize2Octets(
    void *endpointData,
    const RTICdrUnsignedShort *in,
    struct RTICdrStream *stream,
    RTIBool serializeEncapsulation,
    RTIEncapsulationId encapsulationId,
    RTIBool serializeSample,
    void *endpointPluginQos);

extern MIGDllExport
RTIBool MIGRtps_deserialize2Octets(
    RTICdrUnsignedShort *out,
    struct RTICdrStream *stream);

extern MIGDllExport
unsigned int MIGRtps_get2OctetsMaxSizeSerialized(
    unsigned int size);


  #define MIGRtps_serializeProtocolVersion   MIGRtps_serialize2Octets
  #define MIGRtps_deserializeProtocolVersion MIGRtps_deserialize2Octets
  #define MIGRtps_getProtocolVersionMaxSizeSerialized \
     MIGRtps_get2OctetsMaxSizeSerialized

  #define MIGRtps_serializeVendorId   MIGRtps_serialize2Octets
  #define MIGRtps_deserializeVendorId MIGRtps_deserialize2Octets
  #define MIGRtps_getVendorIdMaxSizeSerialized \
     MIGRtps_get2OctetsMaxSizeSerialized

#define MIGRtpsKeyHash_compare(_left, _right)  	                                        \
    (((_left)->length < (_right)->length) ? -1 :		                        \
	 ((_left)->length > (_right)->length) ? 1 :		                        \
	 RTIOsapiMemory_compare((_left)->value, (_right)->value, (_left)->length))    

#define MIGRtpsKeyHash_copy(_dest, _src) (*(_dest) = *(_src))

#define MIGRtpsKeyHash_setDefault(_keyHash) {   \
struct MIGRtpsKeyHash _defaultKeyHash =         \
MIG_RTPS_KEY_HASH_DEFAULT;                      \
MIGRtpsKeyHash_copy(                            \
(_keyHash), &_defaultKeyHash);                  \
}

#define MIGRtpsKeyHash_equals(_left, _right)        \
(MIGRtpsKeyHash_compare((_left), (_right)) == 0)

#ifdef RTI_ENDIAN_LITTLE
#define MIGRtpsKeyHash_fromGuid(_keyHash, _guid)                                                    \
(_keyHash)->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;                                                  \
*((_keyHash)->value    ) = *((RTICdrOctet *)(&(_guid)->prefix.hostId) + 3);                         \
*((_keyHash)->value + 1) = *((RTICdrOctet *)(&(_guid)->prefix.hostId) + 2);                         \
*((_keyHash)->value + 2) = *((RTICdrOctet *)(&(_guid)->prefix.hostId) + 1);                         \
*((_keyHash)->value + 3) = *((RTICdrOctet *)(&(_guid)->prefix.hostId)    );                         \
*((_keyHash)->value + 4) = *((RTICdrOctet *)(&(_guid)->prefix.appId) + 3);                          \
*((_keyHash)->value + 5) = *((RTICdrOctet *)(&(_guid)->prefix.appId) + 2);                          \
*((_keyHash)->value + 6) = *((RTICdrOctet *)(&(_guid)->prefix.appId) + 1);                          \
*((_keyHash)->value + 7) = *((RTICdrOctet *)(&(_guid)->prefix.appId)    );                          \
*((_keyHash)->value + 8) = *((RTICdrOctet *)(&(_guid)->prefix.instanceId) + 3);                     \
*((_keyHash)->value + 9) = *((RTICdrOctet *)(&(_guid)->prefix.instanceId) + 2);                     \
*((_keyHash)->value + 10) = *((RTICdrOctet *)(&(_guid)->prefix.instanceId) + 1);                    \
*((_keyHash)->value + 11) = *((RTICdrOctet *)(&(_guid)->prefix.instanceId)    );                    \
*((_keyHash)->value + 12) = *((RTICdrOctet *)(&(_guid)->objectId) + 3);                             \
*((_keyHash)->value + 13) = *((RTICdrOctet *)(&(_guid)->objectId) + 2);                             \
*((_keyHash)->value + 14) = *((RTICdrOctet *)(&(_guid)->objectId) + 1);                             \
*((_keyHash)->value + 15) = *((RTICdrOctet *)(&(_guid)->objectId)    );                             
#else
#define MIGRtpsKeyHash_fromGuid(_keyHash, _guid)                        \
(_keyHash)->length = MIG_RTPS_KEY_HASH_MAX_LENGTH;                      \
*(RTI_UINT32 *)((_keyHash)->value) = (_guid)->prefix.hostId;            \
*(RTI_UINT32 *)((_keyHash)->value + 4) = (_guid)->prefix.appId;         \
*(RTI_UINT32 *)((_keyHash)->value + 8) = (_guid)->prefix.instanceId;    \
*(RTI_UINT32 *)((_keyHash)->value + 12) = (_guid)->objectId;                                
#endif

#ifdef RTI_ENDIAN_LITTLE
#define MIGRtpsGuid_fromKeyHash(_guid, _keyHash)                                        \
*((RTICdrOctet *)(&(_guid)->prefix.hostId)    ) = *((_keyHash)->value + 3);             \
*((RTICdrOctet *)(&(_guid)->prefix.hostId) + 1) = *((_keyHash)->value + 2);             \
*((RTICdrOctet *)(&(_guid)->prefix.hostId) + 2) = *((_keyHash)->value + 1);             \
*((RTICdrOctet *)(&(_guid)->prefix.hostId) + 3) = *((_keyHash)->value    );             \
*((RTICdrOctet *)(&(_guid)->prefix.appId)    ) = *((_keyHash)->value + 7);              \
*((RTICdrOctet *)(&(_guid)->prefix.appId) + 1) = *((_keyHash)->value + 6);              \
*((RTICdrOctet *)(&(_guid)->prefix.appId) + 2) = *((_keyHash)->value + 5);              \
*((RTICdrOctet *)(&(_guid)->prefix.appId) + 3) = *((_keyHash)->value + 4);              \
*((RTICdrOctet *)(&(_guid)->prefix.instanceId)    ) = *((_keyHash)->value + 11);        \
*((RTICdrOctet *)(&(_guid)->prefix.instanceId) + 1) = *((_keyHash)->value + 10);        \
*((RTICdrOctet *)(&(_guid)->prefix.instanceId) + 2) = *((_keyHash)->value + 9);         \
*((RTICdrOctet *)(&(_guid)->prefix.instanceId) + 3) = *((_keyHash)->value + 8);         \
*((RTICdrOctet *)(&(_guid)->objectId)    ) = *((_keyHash)->value + 15);                 \
*((RTICdrOctet *)(&(_guid)->objectId) + 1) = *((_keyHash)->value + 14);                 \
*((RTICdrOctet *)(&(_guid)->objectId) + 2) = *((_keyHash)->value + 13);                 \
*((RTICdrOctet *)(&(_guid)->objectId) + 3) = *((_keyHash)->value + 12);                        
#else
#define MIGRtpsGuid_fromKeyHash(_guid, _keyHash )                       \
(_guid)->prefix.hostId = *(RTI_UINT32 *)((_keyHash)->value);            \
(_guid)->prefix.appId = *(RTI_UINT32 *)((_keyHash)->value + 4);         \
(_guid)->prefix.instanceId = *(RTI_UINT32 *)((_keyHash)->value + 8);    \
(_guid)->objectId = *(RTI_UINT32 *)((_keyHash)->value + 12);                                
#endif



#define MIGRtpsWriterInfoList_saveState(me,state) \
    if ((me)->_writerInfoList != NULL) { \
        (state)->_currentWriterInfo = (me)->_currentNode; \
        if ((state)->_currentWriterInfo != NULL) { \
            (state)->_currentVirtualWriterInfo = (state)->_currentWriterInfo->_currentNode; \
        } else { \
            (state)->_currentVirtualWriterInfo = NULL; \
        } \
    } else { \
        (state)->_currentWriterInfo = NULL; \
        (state)->_currentVirtualWriterInfo = NULL; \
        (state)->_virtualWriterInfoList = *(me); \
    }

#define MIGRtpsWriterInfoList_restoreState(me,state) \
    if ((me)->_writerInfoList != NULL) { \
        (me)->_currentNode = (state)->_currentWriterInfo; \
        if ((me)->_currentNode != NULL) { \
            (me)->_currentNode->_currentNode = (state)->_currentVirtualWriterInfo; \
        } \
    } else { \
        *(me) = (state)->_virtualWriterInfoList; \
    }


#define MIGRtpsDomainTag_compare(tag1, tag2) \
    (REDAString_compare((tag1 == NULL) ? "" : tag1, (tag2 == NULL) ? "" : tag2))


#define MIGRtpsDomainTag_isDefault(self) \
    (MIGRtpsDomainTag_compare(self, MIG_RTPS_DOMAIN_TAG_DEFAULT) == 0)


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* mig_rtps_impl_h */
