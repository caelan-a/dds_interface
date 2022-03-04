/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)monitor_common.h    generated by: makeheader    Fri Nov 15 12:23:52 2019
 *
 *		built from:	common.ifc
 */

#ifndef monitor_common_h
#define monitor_common_h



  #ifndef monitor_dll_h
    #include "monitor/monitor_dll.h"
  #endif

  #ifndef ndds_c_h
    #include "ndds/ndds_c.h"
  #endif

  #ifndef dds_c_monitoring_h
    #include "dds_c/dds_c_monitoring.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct RTIMonitorClass;


extern	RTIMonitorDllExport struct RTIMonitorClass * RTIDefaultMonitor_create(
	RTIMonitorReturnCode *retcode,
	const struct DDS_ProductVersion_t productVersion);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* monitor_common_h */
