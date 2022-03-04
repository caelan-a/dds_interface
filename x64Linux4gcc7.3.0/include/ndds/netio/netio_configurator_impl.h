/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)netio_configurator_impl.h    generated by: makeheader    Fri Nov 15 12:22:12 2019
 *
 *		built from:	configurator_impl.ifc
 */

#ifndef netio_configurator_impl_h
#define netio_configurator_impl_h


#ifdef __cplusplus
    extern "C" {
#endif


#define RTINetioConfiguratorUtil_generateShmemUuid(uuid, classid, hostid) \
        RTINetioConfiguratorUtil_generateDefaultNetworkAddress96( \
                uuid, \
                classid, \
                hostid, \
                0, \
                0, \
                0)


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* netio_configurator_impl_h */