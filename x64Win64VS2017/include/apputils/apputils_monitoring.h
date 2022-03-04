/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_monitoring_h
#define apputils_monitoring_h


#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

#ifndef apputils_resource_identifier_h
  #include "apputils/apputils_resource_identifier_impl.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

extern APPUTILSDllExport
void APPUTILSMonitoringSupport_compute_application_guid(
        struct DDS_GUID_t *out_guid,
        const char *application_name);

extern APPUTILSDllExport
void APPUTILSMonitoringSupport_compute_resource_guid(
        struct DDS_GUID_t *out_guid,
        const struct DDS_GUID_t *application_guid,
        struct APPUTILSResourceIdentifier *resource_id);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* apputils_monitoring_h */
