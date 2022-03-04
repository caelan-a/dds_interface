#ifndef RTI_DDS_RPC_SERVERIMPL_
#define RTI_DDS_RPC_SERVERIMPL_

/*
(c) Copyright, Real-Time Innovations, 2020
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#include <string>
#include <mutex>
#include <condition_variable>


// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <rti/request/detail/macros.hpp>

#include <dds/domain/DomainParticipant.hpp>
#include <rti/sub/SampleProcessor.hpp>

#include "dds/rpc/ServerParams.hpp"

        namespace rti { namespace rpc {

class XMQCPP2DllExport ServerImpl {
public:
    ServerImpl() = default;

    explicit ServerImpl(const dds::rpc::ServerParams& params)
            : request_processor_(params.extensions().async_waitset_property())
    {
    }

    void run_impl()
    {
        // Sleep until close() is called
        std::unique_lock<std::mutex> lock(run_mutex_);
        run_cv_.wait(lock);
    }

    void run_impl(const dds::core::Duration& max_wait)
    {
        // Sleep until max_wait expires or close() is called.
        std::unique_lock<std::mutex> lock(run_mutex_);
        run_cv_.wait_for(lock, max_wait.to_chrono());
    }

    void close_impl()
    {
        std::unique_lock<std::mutex> lock(run_mutex_);
        run_cv_.notify_all(); // wake up from run()
        request_processor_ = dds::core::null;
    }

    bool closed() const
    {
        return request_processor_ == dds::core::null;
    }

    template<typename ServiceType>
    void attach_service_impl(ServiceType& service);

    template<typename ServiceType>
    void detach_service_impl(ServiceType& service);

    size_t attached_service_count() const
    {
        assert_not_closed();
        return request_processor_.readers().size();
    }

private:
    void assert_not_closed() const
    {
        if (closed()) {
            throw dds::core::AlreadyClosedError("Server already closed");
        }
    }

    std::mutex run_mutex_;
    std::condition_variable run_cv_;
    rti::sub::SampleProcessor request_processor_;
};

template <typename ServiceType>
void ServerImpl::attach_service_impl(ServiceType& service)
{
    using RequestType = typename ServiceType::RequestType;
    using LoanedRequest = rti::sub::LoanedSample<RequestType>;

    assert_not_closed();

    auto request_handler =
            [&service](const LoanedRequest& request) mutable {
                service.process_request_impl(request);
            };

    request_processor_.attach_reader(
            service.request_datareader_impl(),
            request_handler);
}

template<typename ServiceType>
void ServerImpl::detach_service_impl(ServiceType& service)
{
    if (!closed()) {
        request_processor_.detach_reader(service.request_datareader_impl());
    }
}

} } // namespace rti::rpc

#endif // RTI_DDS_RPC_SERVERIMPL_
