/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_common_impl.h    generated by: makeheader    Fri Nov 15 12:22:10 2019
 *
 *		built from:	common_impl.ifc
 */

#ifndef transport_common_impl_h
#define transport_common_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



/* ================================================================= */
/*                         Address                                   */
/* ================================================================= */

#define NDDS_Transport_Address_is_ipv4(address) \
    ((address)->network_ordered_value[0] == 0 && \
     (address)->network_ordered_value[1] == 0 && \
     (address)->network_ordered_value[2] == 0 && \
     (address)->network_ordered_value[3] == 0 && \
     (address)->network_ordered_value[4] == 0 && \
     (address)->network_ordered_value[5] == 0 && \
     (address)->network_ordered_value[6] == 0 && \
     (address)->network_ordered_value[7] == 0 && \
     (address)->network_ordered_value[8] == 0 && \
     (address)->network_ordered_value[9] == 0 && \
     (address)->network_ordered_value[10] == 0 && \
     (address)->network_ordered_value[11] == 0)

/* Is it IPv4 Multicast?
 * IPv4 - In range [::224.0.0.0, ::239.255.255.255]
 */
#define NDDS_Transport_Address_is_ipv4_multicast(address)                     \
    ( ( (void *) address != NULL ) &&                                         \
      ( NDDS_Transport_Address_is_ipv4(address) ) &&                          \
      ( ( (address)->network_ordered_value[12] & 0xF0) == 0xE0 ) )

/* Is it IPv6 Multicast?
 * IPv6 - In range  FF00::/8
 */
#define NDDS_Transport_Address_is_ipv6_multicast(address)                     \
    ( ( (void *) address != NULL ) &&                                         \
      ( (address)->network_ordered_value[0] == 0xFF) )

/* Is it IPv4 or IPv6 Multicast? 

   IPv6 - In range  FF00::/8
   IPv4 - In range [::224.0.0.0, ::239.255.255.255]
 */
#define NDDS_Transport_Address_is_multicast(address)                          \
    ( ( (void *) address != NULL ) &&                                         \
      ( ( NDDS_Transport_Address_is_ipv4_multicast(address) ) ||              \
        ( NDDS_Transport_Address_is_ipv6_multicast(address) ) ) )

          
#define NDDS_Transport_Address_is_equal(l,r) \
   ( !RTIOsapiMemory_compare(l, r, sizeof(NDDS_Transport_Address_t)) )
   
#define NDDS_Transport_Address_compare REDAOrderedDataType_compareQuadUInt

#define NDDS_Transport_Address_copy(dst,src) \
   ( *(dst) = *(src) )



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* transport_common_impl_h */