#ifndef RTI_DDS_RPC_CLIENTENDPOINTIMPL_
#define RTI_DDS_RPC_CLIENTENDPOINTIMPL_

/*
(c) Copyright, Real-Time Innovations, 2020
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#include <string>
#include <memory>

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <rti/request/detail/macros.hpp>

#include <dds/domain/DomainParticipant.hpp>
#include "rti/request/Requester.hpp"
#include "dds/rpc/ClientParams.hpp"
#include <rti/rpc/FailedRequestCollector.hpp>

namespace rti { namespace rpc { namespace detail {

template <typename Request, typename Reply>
class ClientEndpointImpl {
public:

    using RequestType = Request;
    using ReplyType = Reply;

    explicit ClientEndpointImpl(const dds::rpc::ClientParams& params)
            : requester_(create_requester(params)),
              function_call_max_wait_(params.function_call_max_wait()),
              failed_request_collector_(
                      requester_,
                      params.max_outstanding_failed_requests())
    {
    }

    // ClientEndpointImpl can only be created by ClientEndpoint as a shared_ptr.
    ClientEndpointImpl(const ClientEndpointImpl&) = delete;
    ClientEndpointImpl(ClientEndpointImpl&&) = delete;
    ClientEndpointImpl& operator=(const ClientEndpointImpl&) = delete;
    ClientEndpointImpl& operator=(ClientEndpointImpl&&) = delete;

    void close_impl()
    {
        if (!closed_impl()) {
            requester_.close();
        }
    }

    bool closed_impl() const
    {
        return requester_->closed();
    }

    void wait_for_service_impl(const dds::core::Duration& maxWait)
    {
        using dds::core::Duration;

        Duration remainingWait = maxWait;
        Duration sleepTime = Duration::from_millisecs(100);
        while (rti::request::matched_replier_count(requester_) == 0
               && remainingWait > Duration::zero()) {
            rti::util::sleep(sleepTime);
            remainingWait -= sleepTime;
        }

        if (remainingWait == Duration::zero()) {
            throw dds::core::TimeoutError(
                    "ClientEndpoint::wait_for_service: timeout");
        }
    }

    /**
     * @brief Waits for one or more services to be discovered for an unlimited
     * period of time.
     */
    void wait_for_service_impl()
    {
        while (rti::request::matched_replier_count(requester_) == 0) {
            rti::util::sleep(dds::core::Duration::from_millisecs(100));
        }
    }

    dds::pub::DataWriter<RequestType> request_datawriter_impl() const
    {
        return requester_.request_datawriter();
    }

    dds::sub::DataReader<ReplyType> reply_datareader_impl() const
    {
        return requester_.reply_datareader();
    }

    RequestType& scratchpad_request_impl()
    {
        // The request_datawriter() must be locked while this is used.
        assert_not_closed();
        return scratchpad_request_;
    }

    rti::core::SampleIdentity send_request_impl()
    {
        return requester_.send_request(scratchpad_request_impl());
    }

    dds::sub::LoanedSamples<ReplyType> receive_reply_impl(
            const rti::core::SampleIdentity& request_id,
            int32_t operation_id)
    {
        while (true) { // loop controlled by continue and return below
            if (!requester_.wait_for_replies(
                        1,
                        function_call_max_wait_,
                        request_id)) {
                // store the failed request id so if the service replies later
                // the client can purge the response from the reader queue
                failed_request_collector_.add_failed_request(request_id);
                throw dds::core::TimeoutError(
                        "ClientEndpoint: timeout receiving reply from service");
            }

            auto replies = requester_.take_replies(request_id);
            if (replies.length() == 0 || !replies[0].info().valid()) {
                // this shouldn't happen: RPC doesn't use keyed data, and the
                // DataReader should be configured to not generate
                // not-alive-no-writers meta-samples
                continue;
            }

            if (replies[0].data()._d() != operation_id) {
                // This can only happen with a malicious or buggy replier
                throw dds::core::Error(
                        "Received result for incorrect operation");
            }

            return replies;
        }
    }

private:
    static rti::request::Requester<Request, Reply> create_requester(
            const dds::rpc::ClientParams& params)
    {
        rti::request::RequesterParams requester_params(params.participant());
        rti::request::detail::convert_params(requester_params, params);
        return rti::request::Requester<RequestType, ReplyType>(
                requester_params);
    }

    void assert_not_closed() const
    {
        if (closed_impl()) {
            throw dds::core::AlreadyClosedError(
                    "ClientEndpoint already closed");
        }
    }

    rti::request::Requester<RequestType, ReplyType> requester_;
    dds::core::Duration function_call_max_wait_;
    FailedRequestCollector<RequestType, ReplyType> failed_request_collector_;

    // this request is an intermediate sample used by the client to populate the
    // data to send from the parameters of each function call. It must be
    // accessed within the writer mutex. We don't use a local variable because
    // the type can be too large to be allocated on the stack (a
    // ClientEndpointImpl, is always allocated on the heap and so is this
    // field).
    RequestType scratchpad_request_;
};


} } } // namespace rti::rpc::detail

#endif // RTI_DDS_RPC_CLIENTENDPOINTIMPL_
