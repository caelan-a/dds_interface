/* $Id$

 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.

===================================================================== */
#ifndef netio_cap_include_infrastructure_h
#define netio_cap_include_infrastructure_h

#include "netio_cap/netio_cap_infrastructure_psm.h"

#ifdef __cplusplus
    extern "C" {
#endif

#define RTINetioCapShort_MAX (32767)
#define RTINetioCapShort_MIN (-RTINetioCapShort_MAX-1)

#define RTINetioCapUnsignedShort_MAX (65535)
#define RTINetioCapUnsignedShort_MIN (0)

#define RTINetioCapLong_MAX (2147483647L)
#define RTINetioCapLong_MIN (0)

typedef RTINetioCapLong RTINetioCapTransportClassId;
typedef RTINetioCapUnsignedLong RTINetioCapTransportPort;

#define RTI_NETIO_CAP_TRANSPORT_PORT_INVALID ((RTINetioCapTransportPort) 0)
#define RTI_NETIO_CAP_TRANSPORT_CLASSID_INVALID \
        ((RTINetioCapTransportClassId) -1)

struct RTINetioCapTransportBuffer {
    RTINetioCapLong length;
    RTINetioCapChar *pointer;
};

#define RTI_NETIO_CAP_TRANSPORT_GATHER_BUFFER_INITIALIZER { 0, NULL }
struct RTINetioCapTransportGatherBuffer {
    RTINetioCapLong size;
    const struct RTINetioCapTransportBuffer *elements;
};

#define RTI_NETIO_CAP_TRANSPORT_CLASS_ID_LIST_SIZE (8)
#define RTI_NETIO_CAP_TRANSPORT_CLASSID_ANY (0)
struct RTINetioCapTransportClassIdList {
    RTINetioCapLong size;
    RTINetioCapTransportClassId elements[
            RTI_NETIO_CAP_TRANSPORT_CLASS_ID_LIST_SIZE];
};

#define RTI_NETIO_CAP_NTP_TIME_ZERO {0,0}
#define RTI_NETIO_CAP_NTP_TIME_SEC_MAX ((RTINetioCapLong) 0x7fffffff)
#define RTI_NETIO_CAP_NTP_TIME_FRAC_MAX ((RTINetioCapUnsignedLong) 0xffffffff)
#define RTI_NETIO_CAP_NTP_TIME_MAX { \
        RTI_NETIO_CAP_NTP_TIME_SEC_MAX, \
        RTI_NETIO_CAP_NTP_TIME_FRAC_MAX \
}
struct RTINetioCapNtpTime {
    RTINetioCapLong sec;
    RTINetioCapUnsignedLong frac;
};

#define RTI_NETIO_CAP_TRANSPORT_ADDRESS_SIZE  (16)
#define RTI_NETIO_CAP_TRANSPORT_ADDRESS_INVALID { \
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} \
}
struct RTINetioCapTransportAddress {
    RTINetioCapOctet network_ordered_value[RTI_NETIO_CAP_TRANSPORT_ADDRESS_SIZE];
};

#define RTI_NETIO_CAP_TRANSPORT_CONTEXT_INVALID { \
    RTI_NETIO_CAP_TRANSPORT_ADDRESS_INVALID, \
    RTI_NETIO_CAP_TRANSPORT_ADDRESS_INVALID, \
    RTI_NETIO_CAP_TRANSPORT_PORT_INVALID, \
    RTI_NETIO_CAP_TRANSPORT_PORT_INVALID, \
    RTI_NETIO_CAP_TRANSPORT_PORT_INVALID, \
    RTI_NETIO_CAP_TRANSPORT_CLASSID_INVALID \
}
struct RTINetioCapTransportContext {
    struct RTINetioCapTransportAddress sourceAddress;
    struct RTINetioCapTransportAddress destinationAddress;
    RTINetioCapTransportPort sourcePort;
    RTINetioCapTransportPort destinationPort;
    RTINetioCapTransportPort destinationRTPSPort;
    RTINetioCapTransportClassId classId;
};

#define RTI_NETIOCAP_GUID_PREFIX_UNKNOWN {0, 0, 0}
struct RTINetioCapGuidPrefix {
    RTINetioCapUnsignedLong hostId;
    RTINetioCapUnsignedLong appId;
    RTINetioCapUnsignedLong instanceId;
};

#define RTI_NETIO_CAP_BUFFER_POOL_GROWTH_PROPERTY_DEFAULT {150, 800, 20}
struct RTINetioCapPoolGrowthParams {
    RTINetioCapLong initial;
    RTINetioCapLong maximal;
    RTINetioCapLong increment;
};

#define RTI_NETIO_CAP_POOL_DEFAULT { \
    RTI_NETIO_CAP_BUFFER_POOL_GROWTH_PROPERTY_DEFAULT, \
    {0, 0}, \
    {0, 215000000} \
}
struct RTINetioCapPoolParams {
    struct RTINetioCapPoolGrowthParams growth;
    struct RTINetioCapNtpTime bufferBlockingTime;
    struct RTINetioCapNtpTime bufferCheckingTime;
};

#define RTI_NETIO_CAP_THREAD_SETTINGS_DEFAULT { \
    RTI_NETIO_CAP_THREAD_OPTION_DEFAULT, \
    RTI_NETIO_CAP_THREAD_PRIORITY_DEFAULT, \
    RTI_NETIO_CAP_THREAD_STACK_SIZE_DEFAULT \
}
struct RTINetioCapThreadSettings {
    RTINetioCapLong options;
    RTINetioCapLong priority;
    RTINetioCapLong stackSize;
};

#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* netio_cap_include_infrastructure_h */
/* end of $Id$ */
