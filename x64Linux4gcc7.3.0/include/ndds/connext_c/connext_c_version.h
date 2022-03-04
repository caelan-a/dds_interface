/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)connext_c_version.h    generated by: makeheader    Fri Nov 15 12:23:47 2019
 *
 *		built from:	version.ifc
 */

#ifndef connext_c_version_h
#define connext_c_version_h


  #ifndef xqm_c_dll_h
    #include "connext_c/connext_c_dll.h"
  #endif
  #ifndef dds_c_infrastructure_h
    #include "dds_c/dds_c_infrastructure.h"
  #endif


#ifndef log_common_h
   #include "log/log_common.h"
#endif


typedef struct DDS_ProductVersion_t RTI_Connext_Messaging_LibraryVersion;

extern XMQCDllExport
const RTI_Connext_Messaging_LibraryVersion*
    RTI_Connext_Messaging_get_api_version();

extern XMQCDllExport
const char *RTI_Connext_Messaging_Library_get_api_version_string(void);

extern XMQCDllExport const char*
RTI_Connext_Messaging_get_api_build_number_string();

#endif /* connext_c_version_h */
