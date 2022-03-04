/*
 * $Id$
 *
 * (c) Copyright, Real-Time Innovations, 2016-.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef HPP_SERVICE_MONITORING_UTILS_HPP_
#define HPP_SERVICE_MONITORING_UTILS_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "osapi/osapi_host.h"
#include "osapi/osapi_process.h"
#include "cdr/cdr_md5.h"
#include "apputils/apputils_monitoring.h"

#include <rti/core/Guid.hpp>
#include <rti/apputils/ResourceIdentifier.hpp>

namespace rti { namespace apputils { namespace monitoring {

inline
void compute_object_id(
        rti::core::Guid& out_guid,
        const rti::core::Guid& application_id,
        const rti::apputils::ResourceIdentifier& resource_id)
{
    APPUTILSMonitoringSupport_compute_resource_guid(
            &out_guid.native(),
            &application_id.native(),
            &resource_id.native());
}

inline
void compute_application_guid(
        rti::core::Guid &out_guid,
        const std::string& application_name)
{
    APPUTILSMonitoringSupport_compute_application_guid(
            &out_guid.native(),
            application_name.c_str());
}

} } }// rti::apputils::monitoring

#endif /* HPP_SERVICE_MONITORING_UTILS_HPP_ */
