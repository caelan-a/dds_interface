#ifndef OMG_DDS_RPC_SERVICEPARAMS_
#define OMG_DDS_RPC_SERVICEPARAMS_

/* 
(c) Copyright, Real-Time Innovations, 2020
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "dds/rpc/detail/ServiceParams.hpp"

namespace dds { namespace rpc {

using ServiceParams = dds::rpc::detail::ServiceParams;

} }

#endif // OMG_DDS_RPC_SERVICEPARAMS_