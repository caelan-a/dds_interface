#ifndef OMG_DDS_RPC_CLIENTPARAMS_
#define OMG_DDS_RPC_CLIENTPARAMS_

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
#include <rti/request/RequesterParams.hpp>

namespace dds { namespace rpc {

/**
 * @ingroup RpcClientModule
 * @headerfile dds/rpc/ClientEndpoint.hpp
 *
 * @brief @st_value_type The parameters used to configure a ClientEndpoint
 *
 * Since clients use a rti::request::Requester to communicate with a service,
 * the ClientParams type contains the same parameters as an
 * rti::request::RequesterParams, plus function_call_max_wait.
 */
class ClientParams
        : public rti::request::detail::EntityParamsWithSetters<ClientParams> {
private:
    using Base = rti::request::detail::EntityParamsWithSetters<ClientParams>;

public:
    /**
     * @brief Construct a new Client Params object
     *
     * @param participant The DomainParticipant is a required parameter
     */
    ClientParams(dds::domain::DomainParticipant participant) : Base(participant)
    {
    }

    /**
     * @brief Specifies the maximum wait time for all the remote calls
     *
     * @param max_wait The maximum wait time for all remote calls made by a
     * client
     * @return This object
     */
    ClientParams& function_call_max_wait(const dds::core::Duration& max_wait)
    {
        function_call_max_wait_ = max_wait;
        return *this;
    }

    /**
     * @brief Returns the maximum wait time
     */
    dds::core::Duration function_call_max_wait() const
    {
        return function_call_max_wait_;
    }

    ClientParams& max_outstanding_failed_requests(size_t value)
    {
        max_outstanding_failed_requests_ = value;
        return *this;
    }

    size_t max_outstanding_failed_requests() const
    {
        return max_outstanding_failed_requests_;
    }

private:
    dds::core::Duration function_call_max_wait_ =
            dds::core::Duration::infinite();
    size_t max_outstanding_failed_requests_ = 200;
};

} }  // namespace dds::rpc

#endif // OMG_DDS_RPC_CLIENTPARAMS_