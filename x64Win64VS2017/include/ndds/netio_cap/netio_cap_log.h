/* $Id$

 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.

=========================================================================*/
#ifndef netio_cap_include_log_h
#define netio_cap_include_log_h

#include "log/log_common.h"
#include "netio_cap/netio_cap_dll.h"
#include "netio_cap/netio_cap_infrastructure.h"

#ifdef __cplusplus
extern "C" {
#endif

/*i \file
 * @brief Logging facilities for the Network Monitoring module.
 */

/*e \mainpage
 *  RTI Data Distribution Service Network Monitoring Library.
 *
 */

/*e \ingroup RTINetioCapLogModule
 *
 * Submodule ID for plugin submodule (see Log.msg).
 */
#define SUBMODULE_NETIO_CAP_ALL                       (0x1000)
#define SUBMODULE_NETIO_CAP_MANAGER                   (0x2000)
#define SUBMODULE_NETIO_CAP_FORMATTER                 (0x3000)

/*e \ingroup RTINetioCapLogModule
 *
 * Mask for turning on logging for only the submodule
 */
#define RTI_NETIO_CAP_SUBMODULE_MASK_ALL              (0xFFFF)
#define RTI_NETIO_CAP_SUBMODULE_MASK_MANAGER          (0x0001)
#define RTI_NETIO_CAP_SUBMODULE_MASK_FORMATTER        (0x0002)


/*e \ingroup RTINetioCapLogModule
 *
 * Sets the log verbosity.
 */
extern RTINetioCapDllExport
void RTINetioCapLog_setVerbosity(
        RTILogBitmap submoduleMask,
        RTINetioCapLong verbosity);

/*e \ingroup RTINetioCapLogModule
 *
 * Sets a bitmap indicating which modules to log and the instrumentation to use.
 */
extern RTINetioCapDllExport
void RTINetioCapLog_setBitmaps(
        RTILogBitmap submoduleMask,
        RTILogBitmap instrumentationMask);

/*e \ingroup RTINetioCapLogModule
 *
 * Gets bitmap for current modules being logged and the instrumentation being
 * used.
 */
extern RTINetioCapDllExport
void RTINetioCapLog_getBitmaps(
        RTILogBitmap *submoduleMask,
        RTILogBitmap *instrumentationMask);

#ifdef __cplusplus
}    /* extern "C" */
#endif

#endif /* netio_cap_include_log_h */
/* end of $Id$ */
