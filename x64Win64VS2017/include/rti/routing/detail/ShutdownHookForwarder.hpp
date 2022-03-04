/*
 * (c) Copyright, Real-Time Innovations, 2017.
 * All rights reserved.
 *
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef RTI_ROUTING_SHUTDOWN_HOOK_HPP_
#define RTI_ROUTING_SHUTDOWN_HOOK_HPP_


#include "routingservice/routingservice_service.h"

namespace rti { namespace routing { namespace detail {

class AbstractShutdownHookForwarder {
public:

    AbstractShutdownHookForwarder()
    {
        native_.on_shutdown = on_shutdown_forwarder;
        native_.shutdown_hook_data = this;
    }
    
    virtual ~AbstractShutdownHookForwarder()
    {
    }
    
    virtual void on_shutdown()
    {
    }

    static void on_shutdown_forwarder(void *hook_data)
    {
        AbstractShutdownHookForwarder *self =
                static_cast<AbstractShutdownHookForwarder*>(hook_data);
        try {
            self->on_shutdown();
        } catch(...) {}
    }


    const RTI_RoutingServiceRemoteShutdownHook* native() const
    {
        return &native_;
    }
    
private:
    RTI_RoutingServiceRemoteShutdownHook native_;
};

template<typename HookFunc>
class ShutdownHookForwarder : public AbstractShutdownHookForwarder {
public:
    ShutdownHookForwarder(const HookFunc& shutdown_hook)
        : shutdown_hook_(shutdown_hook)
    {
       
    }

    void on_shutdown()
    {
       shutdown_hook_();
    };
    
private:
    HookFunc shutdown_hook_;
};

struct NoopShutdownHook {
    void operator()() {}
};

}

} }


#endif /* RTI_ROUTING_SHUTDOWN_HOOK_HPP_ */

