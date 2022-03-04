#ifndef RTI_DDS_RPC_FAILEDSAMPLECOLLECTOR_
#define RTI_DDS_RPC_FAILEDSAMPLECOLLECTOR_

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

#include <vector>
#include <mutex>

#include <rti/request/Requester.hpp>

namespace rti { namespace rpc { namespace detail {

template <typename Request, typename Reply>
class XMQCPP2DllExport FailedRequestCollector final {
public:
    FailedRequestCollector(
        rti::request::Requester<Request, Reply> requester,
        size_t max_size)
        : requester_(requester), max_size_(max_size)
    {
        if (requester == dds::core::null) {
            throw dds::core::InvalidArgumentError(
                    "FailedRequestCollector ctor: requester is a null reference");
        }
    }

    void add_failed_request(const rti::core::SampleIdentity& request_id)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        try {
            purge();
        } catch (...) {
            // any potential error here has no impact on the user
        }

        failed_requests_.push_back(request_id);
        if (failed_requests_.size() >= max_size_) {
            failed_requests_.erase(failed_requests_.begin());
        }
    }

private:
    void purge()
    {
        for (auto request_it = failed_requests_.begin();
             request_it != failed_requests_.end();) {
            auto samples = requester_.take_replies(*request_it);
            if (samples.length() > 0) {
                request_it = failed_requests_.erase(request_it);
            } else {
                ++request_it;
            }
        }
    }

    std::mutex mutex_;
    rti::request::Requester<Request, Reply> requester_;
    std::vector<rti::core::SampleIdentity> failed_requests_;
    size_t max_size_;
};

} } } // namespace rti::rpc::detail

#endif // RTI_DDS_RPC_FAILEDSAMPLECOLLECTOR_
