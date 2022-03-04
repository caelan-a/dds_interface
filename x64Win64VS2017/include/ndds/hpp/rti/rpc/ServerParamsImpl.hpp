#ifndef RTI_DDS_RPC_SERVERPARAMSIMPL_
#define RTI_DDS_RPC_SERVERPARAMSIMPL_

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

#include <rti/sub/SampleProcessor.hpp>

namespace rti { namespace rpc {

/** @RTI_class_definition NA */
class XMQCPP2DllExport ServerParamsImpl {
public:
    /**
     * @memberof dds::rpc::ServerParams
     * @brief Configures the number of threads of a Server thread pool
     *
     * @extension_member_note
     *
     * By default a server uses only one thread, processing all function calls
     * sequentially. Incresing the pool size provides more parallelism.
     */
    void thread_pool_size(int32_t size)
    {
        async_waitset_property_.thread_pool_size(size);
    }

    /**
     * @memberof dds::rpc::ServerParams
     * @brief Returns the thread pool size
     *
     * @extension_member_note
     */
    int32_t thread_pool_size() const
    {
        return async_waitset_property_.thread_pool_size();
    }

    /**
     * @memberof dds::rpc::ServerParams
     * @brief Allows fine-tuning the internal AsyncWaitSet used to process
     * function calls.
     *
     * @extension_member_note
     */
    rti::core::cond::AsyncWaitSetProperty& async_waitset_property()
    {
        return async_waitset_property_;
    }

    /**
     * @memberof dds::rpc::ServerParams
     * @brief Returns the AsyncWaitSetProperty by const reference
     *
     * @extension_member_note
     */
    const rti::core::cond::AsyncWaitSetProperty& async_waitset_property() const
    {
        return async_waitset_property_;
    }

private:
    rti::core::cond::AsyncWaitSetProperty async_waitset_property_;
};

} } // namespace rti::rpc

#endif // RTI_DDS_RPC_SERVERPARAMSIMPL_
