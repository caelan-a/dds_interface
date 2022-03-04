#ifndef OMG_DDS_RPC_DETAIL_SERVERPARAMS_
#define OMG_DDS_RPC_DETAIL_SERVERPARAMS_

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
#include <rti/request/detail/macros.hpp>

#include <dds/rpc/TServerParams.hpp>
#include <rti/rpc/ServerParamsImpl.hpp>

namespace dds { namespace rpc { namespace detail {

using ServerParams = ::dds::rpc::TServerParams<rti::rpc::ServerParamsImpl>;

} } }


#endif // OMG_DDS_RPC_DETAIL_SERVERPARAMS_