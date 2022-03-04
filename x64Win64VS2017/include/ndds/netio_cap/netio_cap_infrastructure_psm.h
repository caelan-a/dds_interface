/* $Id$

 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.

===================================================================== */
#ifndef netio_cap_include_infrastructure_psm_h
#define netio_cap_include_infrastructure_psm_h

#include "osapi/osapi_type.h"
#include "osapi/osapi_ntptime.h"
#include "osapi/osapi_ntptime_impl.h"
#include "osapi/osapi_host.h"
#include "osapi/osapi_rtpsGuid.h"
#include "transport/transport_common.h"

#ifdef __cplusplus
    extern "C" {
#endif

/* ------------------------------------------------------------------------- */
/* ---- Constants and Types ------------------------------------------------ */
/* ------------------------------------------------------------------------- */
typedef char RTINetioCapChar;
typedef unsigned char RTINetioCapUnsignedChar;
typedef RTI_UINT8 RTINetioCapOctet;
typedef RTI_INT16 RTINetioCapShort;
typedef RTI_UINT16 RTINetioCapUnsignedShort;
typedef RTI_INT32 RTINetioCapLong;
typedef RTI_UINT32 RTINetioCapUnsignedLong;
typedef RTI_INT64 RTINetioCapLongLong;
typedef RTI_UINT64 RTINetioCapUnsignedLongLong;
typedef FILE RTINetioCapFile;

#define RTI_NETIO_CAP_THREAD_OPTION_DEFAULT RTI_OSAPI_THREAD_OPTION_STDIO
#define RTI_NETIO_CAP_THREAD_PRIORITY_DEFAULT RTI_OSAPI_THREAD_PRIORITY_DEFAULT
#define RTI_NETIO_CAP_THREAD_STACK_SIZE_DEFAULT RTI_OSAPI_THREAD_STACK_SIZE_DEFAULT


/* ------------------------------------------------------------------------- */
/* ------ Conversion macros ------------------------------------------------ */
/* ------------------------------------------------------------------------- */

#define RTINetioCapNtpTime_toRTINtpTime(__timeOut, __timeIn) \
        (__timeOut)->sec = (__timeIn)->sec; \
        (__timeOut)->frac = (__timeIn)->frac

#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* netio_cap_include_infrastructure_psm_h */
/* end of $Id$ */
