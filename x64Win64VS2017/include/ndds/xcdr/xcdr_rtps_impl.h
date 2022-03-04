/*
(c) Copyright, Real-Time Innovations, 2020-2020.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
============================================================================= */

#ifndef xcdr_rtps_impl_h
#define xcdr_rtps_impl_h


#ifdef __cplusplus
    extern "C" {
#endif

#define RTI_XCDR_RTPS_MESSAGE_HEADER_SIZE (20)
    #define RTI_XCDR_RTPS_SUBMESSAGE_HEADER_SIZE (4)
#define RTI_XCDR_RTPS_SUBMESSAGE_FLAG_ENDIAN (0x01)

/* ================================================================= */
/*                 Internal Helpers                                  */
/* ================================================================= */
#ifdef RTI_ENDIAN_LITTLE
#define RTIXCdrRtpsSubmessageFlags_setEndianness(__flags) \
    (__flags | RTI_XCDR_RTPS_SUBMESSAGE_FLAG_ENDIAN)
#else
#define RTIXCdrRtpsSubmessageFlags_setEndianness(__flags) \
    (__flags & ~RTI_XCDR_RTPS_SUBMESSAGE_FLAG_ENDIAN)
#endif

#ifdef RTI_ENDIAN_LITTLE
#define RTIXCdrRtpsBufferHelper_deserializeSubMsgLength( \
        /* RTIXCdrUnsignedShort * */ __octetsToNextHeader, \
        /* const char * */ __bufferPtr, \
        /* RTIXCdrBoolean */ __isLittleEndian) \
    if (!__isLittleEndian) { \
        ((char *) (__octetsToNextHeader))[1] = *(__bufferPtr++); \
        ((char *) (__octetsToNextHeader))[0] = *(__bufferPtr++); \
    } else { \
        *(__octetsToNextHeader) = *((RTIXCdrUnsignedShort *) (__bufferPtr)); \
        (__bufferPtr += 2); \
    }
#else
#define RTIXCdrRtpsBufferHelper_deserializeSubMsgLength( \
        /* RTIXCdrUnsignedShort * */ __octetsToNextHeader, \
        /* const char * */ __bufferPtr, \
        /* RTIXCdrBoolean */ __isLittleEndian) \
    if (__isLittleEndian) { \
        ((char *) (__octetsToNextHeader))[1] = *(__bufferPtr++); \
        ((char *) (__octetsToNextHeader))[0] = *(__bufferPtr++); \
    } else { \
        *(__octetsToNextHeader) = *((RTIXCdrUnsignedShort *) (__bufferPtr)); \
        (__bufferPtr += 2); \
    }
#endif

/* ================================================================= */
/*                 Submessage Header                                 */
/* ================================================================= */
#define RTIXCdrRtpsBufferHelper_serializeSubMsgHeader( \
        /* char * */ __bufferPtr, \
        /* RTIXCdrOctet */ __submessageId, \
        /* RTIXCdrOctet */ __submessageFlags, \
        /* RTIXCdrUnsignedShort */ __octetsToNextHeader) \
    *(__bufferPtr++) = __submessageId; \
    *(__bufferPtr++) = RTIXCdrRtpsSubmessageFlags_setEndianness( \
            __submessageFlags); \
    *((RTIXCdrUnsignedShort *) (__bufferPtr)) = \
            (RTIXCdrUnsignedShort) __octetsToNextHeader; \
    (__bufferPtr) += 2

#define RTIXCdrRtpsBufferHelper_deserializeSubMsgHeader( \
        /* RTIXCdrOctet * */ __submessageId, \
        /* RTIXCdrOctet * */ __submessageFlags, \
        /* RTIXCdrUnsignedShort * */ __octetsToNextHeader, \
        /* const char * */ __bufferPtr) \
    *(__submessageId) = *(__bufferPtr++); \
    *(__submessageFlags) = *(__bufferPtr++); \
    RTIXCdrRtpsBufferHelper_deserializeSubMsgLength( \
            __octetsToNextHeader, \
            __bufferPtr, \
            (*(__submessageFlags) & RTI_XCDR_RTPS_SUBMESSAGE_FLAG_ENDIAN));

#define RTIXCdrRtpsBufferHelper_isSubMsgId( \
        /* const char * */ __bufferPtr, \
        /* RTIXCdrOctet */ __submessageId) \
        (*((RTIXCdrOctet *) __bufferPtr) == (__submessageId))

/* ================================================================= */
/*                 RTPS Header                                       */
/* ================================================================= */
#define RTIXCdrRtpsBufferHelper_serializeMsgHeader( \
        /* char * */ __bufferPtr, \
        /* RTIXCdrOctet */ __versionMajor, \
        /* RTIXCdrOctet */ __versionMinor, \
        /* RTIXCdrOctet */ __vendorMajor, \
        /* RTIXCdrOctet */ __vendorMinor, \
        /* RTI_UINT32 */ __hostId, \
        /* RTI_UINT32 */ __appId, \
        /* RTI_UINT32 */ __instanceId) \
    __bufferPtr[0] = 'R'; \
    __bufferPtr[1] = 'T'; \
    __bufferPtr[2] = 'P'; \
    __bufferPtr[3] = 'S'; \
    __bufferPtr[4] = __versionMajor; \
    __bufferPtr[5] = __versionMinor; \
    __bufferPtr[6] = __vendorMajor; \
    __bufferPtr[7] = __vendorMinor; \
    __bufferPtr += 8; \
    *(RTI_UINT32 *) __bufferPtr = htonl(__hostId); \
    __bufferPtr += 4; \
    *(RTI_UINT32 *) __bufferPtr = htonl(__appId); \
    __bufferPtr += 4; \
    *(RTI_UINT32 *) __bufferPtr = htonl(__instanceId); \
    __bufferPtr += 4; \

#define RTIXCdrRtpsBufferHelper_isMsgHeader( \
        /* const char * */ __bufferPtr) \
        ((__bufferPtr[0] == 'R' && __bufferPtr[1] == 'T' \
                && __bufferPtr[2] == 'P' &&__bufferPtr[3] == 'S') \
                ? (RTI_XCDR_TRUE) : (RTI_XCDR_FALSE))

#define RTIXCdrRtpsBufferHelper_skipMsgHeader( \
        /* const char * */ __bufferPtr) \
        __bufferPtr += RTI_XCDR_RTPS_MESSAGE_HEADER_SIZE

#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* xcdr_rtps_impl_h */
