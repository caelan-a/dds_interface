/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)rti_dl_version_cpp.h    generated by: makeheader    Fri Apr 23 01:06:22 2021
 *
 *		built from:	version_cpp.ifcxx
 */

#ifndef rti_dl_version_cpp_h
#define rti_dl_version_cpp_h


#include <string>

#ifndef rti_dl_dll_c_h
  #include "rti_dl/rti_dl_dll_cpp.h"
#endif
#ifndef log_makeheader_h
  #include "log/log_makeheader.h"
#endif
#ifndef rti_dl_version_c
  #include "rti_dl/rti_dl_version_c.h"
#endif

/*e
  \defgroup RTI_DL_DistLogger_Version_Module RTI Distributed Logger Version Module
  \ingroup RTI_DL_DistLogger_Module
 */

/*e
  \ingroup RTI_DL_DistLogger_Version_Module
  \brief Get the Distributed Logger C++ library version
 */
RTIDLCPPDllExport 
const RTI_DL_DistLogger_LibraryVersion *RTI_DLDistLogger_get_version();

/*e
  \ingroup RTI_DL_DistLogger_Version_Module
  \brief Get the Distributed Logger C++ build version
 */
RTIDLCPPDllExport 
std::string RTI_DLDistLogger_get_api_build_version_string();

/*e
  \ingroup RTI_DL_DistLogger_Version_Module
  \brief Get the Distributed Logger C++ build version as a string
 */
RTIDLCPPDllExport 
std::string RTI_DLDistLogger_get_api_version_string();



#endif /* rti_dl_version_cpp_h */
