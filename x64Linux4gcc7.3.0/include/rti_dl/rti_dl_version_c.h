/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)rti_dl_version_c.h    generated by: makeheader    Fri Nov 15 12:23:45 2019
 *
 *		built from:	version_c.ifc
 */

#ifndef rti_dl_version_c_h
#define rti_dl_version_c_h


#ifndef rti_dl_dll_c_h
  #include "rti_dl/rti_dl_dll_c.h"
#endif
#ifndef log_makeheader_h
  #include "log/log_makeheader.h"
#endif
#ifndef dds_c_infrastructure_h
  #include "dds_c/dds_c_infrastructure.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

/*e
  \defgroup RTI_DL_DistLogger_Version_Module RTI Distributed Logger Version Module
  \ingroup RTI_DL_DistLogger_Module
 */ 

/*e
  \ingroup RTI_DL_DistLogger_Version_Module
  \brief The RTI Distributed Logger library version.
 */
typedef struct DDS_ProductVersion_t RTI_DL_DistLogger_LibraryVersion;

/*e
  \ingroup RTI_DL_DistLogger_Version_Module
  \brief Get the RTI Distributed Logger C library version
 */
RTIDLCDllExport
const RTI_DL_DistLogger_LibraryVersion *RTI_DL_DistLogger_get_version();

/*e
  \ingroup RTI_DL_DistLogger_Version_Module
  \brief Get the RTI Distributed Logger C build version
 */
RTIDLCDllExport
const char *RTI_DL_DistLogger_get_api_build_version();

/*e
  \ingroup RTI_DL_DistLogger_Version_Module
  \brief Get the RTI Distributed Logger C api version as a string.
 */
RTIDLCDllExport
const char *RTI_DL_DistLogger_get_api_version_string();

#ifdef __cplusplus
    }
#endif

#endif /* rti_dl_version_c_h */
