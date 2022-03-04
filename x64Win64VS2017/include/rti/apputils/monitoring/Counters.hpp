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

#ifndef HPP_SERVICE_MONITORING_COUNTERS_HPP_
#define HPP_SERVICE_MONITORING_COUNTERS_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>

namespace rti { namespace apputils { namespace monitoring {

struct NetworkPerformanceCounters {

    NetworkPerformanceCounters()
        :received_samples(0), received_bytes(0), latency_ms(0)
    {
    }

    int64_t received_samples;
    int64_t received_bytes;
    int64_t latency_ms;
};

} } }// rti::apputils::monitoring

#endif /* HPP_SERVICE_MONITORING_COUNTERS_HPP_ */
