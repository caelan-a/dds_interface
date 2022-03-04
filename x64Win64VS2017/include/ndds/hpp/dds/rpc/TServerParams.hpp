#ifndef OMG_DDS_RPC_TSERVERPARAMS_
#define OMG_DDS_RPC_TSERVERPARAMS_

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

#include <dds/core/Value.hpp>
#include "dds/rpc/ServiceParams.hpp"

namespace dds { namespace rpc {

/**
 * @ingroup RpcServiceModule
 * @headerfile dds/rpc/ServerParams.hpp
 * @RTI_class_definition class ServerParams
 *
 * @brief @st_value_type The parameters used to configure a Server
 */
template <typename Delegate>
class TServerParams : public dds::core::Value<Delegate> {
public:
    // No standard methods; the actual implementation is in the extensions()
};

} } // namespace dds::rpc

#endif // OMG_DDS_RPC_TSERVERPARAMS_

