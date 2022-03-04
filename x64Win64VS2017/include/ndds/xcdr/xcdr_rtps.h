/*
(c) Copyright, Real-Time Innovations, 2014-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
============================================================================= */

#ifndef xcdr_rtps_h
#define xcdr_rtps_h


#include "xcdr/xcdr_dll.h"
#include "xcdr/xcdr_infrastructure.h"


#ifdef __cplusplus
    extern "C" {
#endif

/* ================================================================= */
/*                 RTPS Protocol Constants                           */
/* ================================================================= */
#define RTI_XCDR_RTPS_PROTOCOL_VERSION_MAJOR (0x02)
#define RTI_XCDR_RTPS_PROTOCOL_VERSION_MINOR (0x03)
#define RTI_XCDR_RTPS_VENDOR_ID_MAJOR (0x01)
#define RTI_XCDR_RTPS_VENDOR_ID_MINOR (0x01)

/* ================================================================= */
/*                 Submessage Header                                 */
/* ================================================================= */
extern RTIXCdrDllExport
void RTIXCdrRtpsBufferHelper_serializeSubMsgHeader(
        char *currentBufferPosition,
        RTIXCdrOctet submessageId,
        RTIXCdrOctet submessageFlags,
        RTIXCdrUnsignedShort octetsToNextHeader);

extern RTIXCdrDllExport
void RTIXCdrRtpsBufferHelper_deserializeSubMsgHeader(
        RTIXCdrOctet *submessageId,
        RTIXCdrOctet *submessageFlags,
        RTIXCdrUnsignedShort *submessagePayloadLength,
        const char *currentBufferPosition);

extern RTIXCdrDllExport
void RTIXCdrRtpsBufferHelper_isSubMsgId(
        const char *currentBufferPosition,
        RTIXCdrOctet submessageId);

/* ================================================================= */
/*                 RTPS Header                                       */
/* ================================================================= */
extern RTIXCdrDllExport
void RTIXCdrRtpsBufferHelper_serializeMsgHeader(
        char *currentBufferPosition,
        RTIXCdrOctet versionMajor,
        RTIXCdrOctet versionMinor,
        RTIXCdrOctet vendorMajor,
        RTIXCdrOctet vendorMinor,
        RTI_UINT32 hostId,
        RTI_UINT32 appId,
        RTI_UINT32 instanceId);

extern RTIXCdrDllExport
RTIXCdrBoolean RTIXCdrRtpsBufferHelper_isMsgHeader(
        const char *currentBufferPosition);

extern RTIXCdrDllExport
RTIXCdrBoolean RTIXCdrRtpsBufferHelper_skipMsgHeader(
        const char *currentBufferPosition);

#ifdef __cplusplus
    }   /* extern "C" */
#endif


#include "xcdr/xcdr_rtps_impl.h"

#endif /* xcdr_rtps_h */
