/*
 * (c) Copyright, Real-Time Innovations, 2017.
 * All rights reserved.
 *
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef RTI_RECORDING_RECORDING_SERVICE_IMPL_HPP_
#define RTI_RECORDING_RECORDING_SERVICE_IMPL_HPP_

#include "recordingservice/recordingservice_dll.h"

#include <dds/core/refmacros.hpp>
#include <rti/core/detail/SelfReference.hpp>
#include <rti/idlgen/ServiceAdmin.hpp>
#include <rti/recording/ServiceProperty.hpp>
#include <rti/routing/detail/ShutdownHookForwarder.hpp>

namespace rti { namespace recording {

namespace  service {
class Service;
}

namespace detail {

typedef rti::routing::detail::AbstractShutdownHookForwarder
        AbstractShutdownHookForwarder;

}

class Application;

class RECORDERDllExport RecordingServiceImpl
        : public rti::core::detail::RetainableType<RecordingServiceImpl> {

public:
    typedef RTI::Service::Admin::CommandRequest CommandRequest;
    typedef RTI::Service::Admin::CommandReply CommandReply;

    explicit RecordingServiceImpl(const ServiceProperty& property);
   
    RecordingServiceImpl(
            const ServiceProperty& property,
            detail::AbstractShutdownHookForwarder *hook_forwarder);

    ~RecordingServiceImpl();

    void start();

    void stop();

    CommandReply execute_command(const CommandRequest& request);
    
    CommandReply& execute_command(
            CommandReply& reply,
            const CommandRequest& request);

    static void initialize_globals();
    static void finalize_globals();

private:
    friend class rti::recording::Application;

    rti::recording::service::Service *impl_;
    detail::AbstractShutdownHookForwarder *shutdown_forwarder_fwd_;
};

}}

#endif // RTI_RECORDING_RECORDING_SERVICE_IMPL_HPP_
