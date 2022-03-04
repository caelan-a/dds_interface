/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)transport_udpv6_impl.h    generated by: makeheader    Fri Nov 15 12:22:10 2019
 *
 *		built from:	udpv6_impl.ifc
 */

#ifndef transport_udpv6_impl_h
#define transport_udpv6_impl_h


#ifdef __cplusplus
    extern "C" {
#endif


#define NDDS_Transport_UDPv6_RecvResource_t  NDDS_Transport_UDP_RecvResource_t


#define NDDS_Transport_UDPv6_SendResource_t  NDDS_Transport_UDP_SendResource_t


#define NDDS_Transport_UDPv6_new(property_in) \
        NDDS_Transport_UDPv6_newI(property_in, NULL, NULL, NULL)


#define NDDS_Transport_UDPv6_assert_fake_ip_address  NDDS_Transport_UDP_assert_fake_ip_address


#define NDDS_Transport_UDPv6_remove_fake_ip_address  NDDS_Transport_UDP_remove_fake_ip_address


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* transport_udpv6_impl_h */
