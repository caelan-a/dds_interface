#ifndef OMG_DDS_RPC_TSERVER_
#define OMG_DDS_RPC_TSERVER_

/* 
(c) Copyright, Real-Time Innovations, 2020
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#include <string>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/Reference.hpp>
#include <dds/domain/DomainParticipant.hpp>

#include "dds/rpc/ServerParams.hpp"

namespace dds { namespace rpc {

/** 
 * @ingroup RpcServiceModule
 * @headerfile dds/rpc/Server.hpp
 * @RTI_class_definition class Server
 *
 * @brief @st_ref_type Provides the execution environment for one or more
 * ServiceEndpoint.
 */
template <typename Delegate>
class TServer : public dds::core::Reference<Delegate> {
public:
    OMG_DDS_REF_TYPE_NODC(TServer, dds::core::Reference, Delegate)

    /**
     * @brief Creates a new server with default ServerParams
     */
    TServer() : dds::core::Reference<Delegate>(new Delegate())
    {
    }

    /**
     * @brief Creates a new server with the specified ServerParams
     */
    explicit TServer(const ServerParams& params)
            : dds::core::Reference<Delegate>(new Delegate(params))
    {
    }

    /**
     * @brief Holds the execution of the current thread
     *
     * Calling this function is optional. A Server manages a thread pool that
     * runs as soon as a ServiceEndpoint is attached.
     */
    void run()
    {
        this->delegate()->run_impl();
    }

    /**
     * @brief Holds the execution of the current thread for the specified amount
     * of time
     *
     * Calling this function is optional. A Server manages a thread pool that
     * runs as soon as a ServiceEndpoint is attached.
     *
     * @param max_wait The time to sleep
     */
    void run(const dds::core::Duration& max_wait)
    {
        this->delegate()->run_impl(max_wait);
    }

    /**
     * @brief Forces the destruction of this entity.
     *
     * If run() is currently blocked on another thread, close() unblocks it.
     *
     * Any operation after close() throws dds::core::AlreadyClosedError
     *
     * @mtsafety_delete
     *
     * @see \ref a_st_ref_type "Reference types"
     */
    void close()
    {
        this->delegate()->close_impl();
    }
};

} } // namespace dds::rpc

#endif // OMG_DDS_RPC_TSERVER_

