#ifndef OMG_DDS_RPC_CLIENTENDPOINT_
#define OMG_DDS_RPC_CLIENTENDPOINT_

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

#if !defined(RTI_NO_CXX11_RPC_SUPPORT)
#include <future>

#include <dds/rpc/Server.hpp>
#include <dds/rpc/ClientParams.hpp>
#include <rti/request/Requester.hpp>
#include <rti/core/EntityLock.hpp>
#include <dds/rpc/detail/ClientEndpoint.hpp>

namespace dds { namespace rpc {

/**
 * @defgroup RpcClientModule Client-side API
 * @ingroup RpcModule
 * @brief Part of the RPC API that relates to the client
 */

/**
 * @ingroup RpcClientModule
 * @headerfile dds/rpc/ClientEndpoint.hpp
 *
 * @brief @st_ref_type Manages the DDS entities required to make remote function
 * calls.
 *
 * This class is always the base of a concrete client, such as
 * rpc_example::RobotControlClient.
 */
template <typename Request, typename Reply>
class ClientEndpoint
    : public dds::core::Reference<detail::ClientEndpointImpl<Request, Reply>> {
private:
    using Delegate = detail::ClientEndpointImpl<Request, Reply>;
    using Base = dds::core::Reference<Delegate>;

public:
    /**
     * @brief The type used to make function calls
     */
    using RequestType = Request;

    /**
     * @brief The type used to receive the results of function calls
     */
    using ReplyType = Reply;

    /**
     * @brief Creates a new ClientEndpoint
     */
    explicit ClientEndpoint(const ClientParams& params)
        : Base(new Delegate(params))
    {
    }

    /**
     * @brief Destroyes the underlying requester and other resources
     *
     * Any operation after close() throws dds::core::AlreadyClosedError
     */
    void close()
    {
        this->delegate()->close_impl();
    }

    /**
     * @brief Whether this instance has been closed already
     */
    bool closed() const
    {
        return this->delegate()->closed_impl();
    }

    /**
     * @brief Waits for one or more services to be discovered
     *
     * @param maxWait The maximum time to wait, after which
     * dds::core::TimeoutError is thrown.
     */
    void wait_for_service(const dds::core::Duration& maxWait)
    {
        this->delegate()->wait_for_service_impl(maxWait);
    }

    /**
     * @brief Waits for one or more services to be discovered for an unlimited
     * period of time.
     */
    void wait_for_service()
    {
        this->delegate()->wait_for_service_impl();
    }

    /**
     * @brief Accesses the underlying DataWriter that sends the requests
     * (function calls)
     *
     * @return The DataWriter
     */
    dds::pub::DataWriter<RequestType> request_datawriter() const
    {
        return this->delegate()->request_datawriter_impl();
    }

    /**
     * @brief Accesses the underlying DataReader that receives the replies
     * (return values from the function calls)
     *
     * @return The DataReader
     */
    dds::sub::DataReader<ReplyType> reply_datareader() const
    {
        return this->delegate()->reply_datareader_impl();
    }

protected:
    RequestType& scratchpad_request()
    {
        return this->delegate()->scratchpad_request_impl();
    }

    rti::core::SampleIdentity send_request()
    {
        return this->delegate()->send_request_impl();
    }

    dds::sub::LoanedSamples<ReplyType> receive_reply(
            const rti::core::SampleIdentity& request_id,
            int32_t operation_id)
    {
        return this->delegate()->receive_reply_impl(request_id, operation_id);
    }
};

} }  // namespace dds::rpc

#endif // !defined(RTI_NO_CXX11_RPC_SUPPORT)

#ifdef DOXYGEN_DOCUMENTATION_ONLY

namespace rpc_example {
/**
 * @ingroup RpcClientModule
 * @brief An instantiation of dds::rpc::ClientEndpoint for the DDS types
 * that allow making function calls to the RobotControl service interface.
 *
 */
using RobotControlClientEndpoint =
        dds::rpc::ClientEndpoint<RobotControl_Call, RobotControl_Return>;


/**
 * @ingroup RpcClientModule
 * @brief @st_ref_type Allows client applications to make remote function calls
 *
 * This class implements the RobotControl and RobotControlAsync interfaces to
 * make remote function calls. It also inherits from RobotControlClientEndpoint,
 * which manages the DDS entities required to make those function calls.
 */
class RobotControlClient : public RobotControl,
                           public RobotControlAsync,
                           public RobotControlClientEndpoint {


};

}  // namespace rpc_example

#endif // DOXYGEN_DOCUMENTATION_ONLY

#endif  // OMG_DDS_RPC_CLIENTENDPOINT_