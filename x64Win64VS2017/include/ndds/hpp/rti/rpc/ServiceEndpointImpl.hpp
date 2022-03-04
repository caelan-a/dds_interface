#ifndef RTI_DDS_RPC_SERVICEENDPOINTIMPL_
#define RTI_DDS_RPC_SERVICEENDPOINTIMPL_

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
#include "rti/request/Replier.hpp"
#include "dds/rpc/ServiceParams.hpp"
#include "dds/rpc/Server.hpp"

namespace rti { namespace rpc {

template <typename Dispatcher>
class ServiceEndpointImpl {
public:
    using InterfaceType = typename Dispatcher::InterfaceType;
    using RequestType = typename Dispatcher::RequestType;
    using ReplyType = typename Dispatcher::ReplyType;

    ServiceEndpointImpl(
            std::shared_ptr<InterfaceType> service_impl,
            dds::rpc::Server server,
            const dds::rpc::ServiceParams& params)
            : service_impl_(service_impl),
              replier_(dds::core::null),
              server_(server)
    {
        if (!service_impl_) {
            throw dds::core::PreconditionNotMetError(
                    "service_impl cannot be null");
        }

        if (server == dds::core::null) {
            throw dds::core::NullReferenceError(
                    "ServiceEndpoint ctor: server is a null reference");
        }

        replier_ = rti::request::Replier<RequestType, ReplyType>(params);
        server.extensions().attach_service_impl(*this);
    }

    ~ServiceEndpointImpl()
    {
        try {
            close_impl();
        } catch (...) {
        }
    }

    bool closed() const
    {
        return replier_ == nullptr;
    }

    void close_impl()
    {
        if (!closed()) {
            server_.extensions().detach_service_impl(*this);
            replier_ = nullptr;
            server_ = nullptr;
            service_impl_ = nullptr;
        }
    }

    void process_request_impl(
        const rti::sub::LoanedSample<RequestType>& request)
    {
        assert_not_closed();
        if (request.info().valid()) {
            thread_local std::unique_ptr<ReplyType> thread_reply_(new ReplyType());
            Dispatcher::dispatch_request(
                    service_impl_.get(),
                    *thread_reply_,
                    request.data());
            replier_.send_reply(*thread_reply_, request.info());
        }
    }

    dds::sub::DataReader<RequestType> request_datareader_impl()
    {
        return replier().request_datareader();
    }

    dds::pub::DataWriter<ReplyType> reply_datawriter_impl()
    {
        return replier().reply_datawriter();
    }

    rti::request::Replier<RequestType, ReplyType> replier()
    {
        assert_not_closed();
        return replier_;
    }

private:
    void assert_not_closed() const
    {
        if (closed()) {
            throw dds::core::AlreadyClosedError("ServiceEndpoint already closed");
        }
    }

    std::shared_ptr<InterfaceType> service_impl_;
    rti::request::Replier<RequestType, ReplyType> replier_;
    dds::rpc::Server server_;
};

} } // namespace rti::rpc

#endif // RTI_DDS_RPC_SERVICEENDPOINTIMPL_
