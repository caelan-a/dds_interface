/*
 * (c) Copyright, Real-Time Innovations, 2017.
 * All rights reserved.
 *
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef RTI_ROUTING_ENTITY_LISTENER_HPP_
#define RTI_ROUTING_ENTITY_LISTENER_HPP_

#include "routingservice/routingservice_service_impl.h"

#include <rti/apputils/ServiceException.hpp>
#include <rti/apputils/log/LogConfig.hpp>
#include <rti/routing/StreamInfo.hpp>

namespace rti { namespace routing {

/**
 */
struct EntityKind_def {
    /**
     * @brief The underlying \p enum type
     */
    enum type {
        SERVICE = RTI_ROUTING_SERVICE_SERVICE_ENTITY,
        DOMAIN_ROUTE = RTI_ROUTING_SERVICE_DOMAIN_ROUTE_ENTITY,
        CONNECTION = RTI_ROUTING_SERVICE_CONNECTION_ENTITY,
        SESSION = RTI_ROUTING_SERVICE_SESSION_ENTITY,
        AUTO_TOPIC_ROUTE = RTI_ROUTING_SERVICE_AUTO_TOPIC_ROUTE_ENTITY,
        TOPIC_ROUTE = RTI_ROUTING_SERVICE_TOPIC_ROUTE_ENTITY,
        INPUT = RTI_ROUTING_SERVICE_INPUT_ENTITY,
        OUTPUT = RTI_ROUTING_SERVICE_OUTPUT_ENTITY,
        count_
    };

};

/**
 */
typedef dds::core::safe_enum<EntityKind_def> EntityKind;


/**
 */
struct EntityStateKind_def {
    /**
     * @brief The underlying \p enum type
     */
    enum type {
        INVALID = RTI_SERVICE_INVALID_ENTITY_STATE,
        ENABLED = RTI_SERVICE_ENABLED_ENTITY_STATE,
        DISABLED = RTI_SERVICE_DISABLED_ENTITY_STATE,
        STARTED = RTI_SERVICE_STARTED_ENTITY_STATE,
        STOPPED = RTI_SERVICE_STOPPED_ENTITY_STATE,
        RUNNING = RTI_SERVICE_RUNNING_ENTITY_STATE,
        PAUSED = RTI_SERVICE_PAUSED_ENTITY_STATE
    };

};

typedef dds::core::safe_enum<EntityStateKind_def> EntityStateKind;

/*
 * @brief string representation of EntityStateKind
 */
inline
const std::string to_string(const rti::routing::EntityStateKind& kind)
{
    static const char * ENTITY_STATE_KIND_AS_STRING[] = {
        "INVALID",
        "ENABLED",
        "DISABLED",
        "STARTED",
        "STOPPED",
        "RUNNING",
        "PAUSED"
    };

    return ENTITY_STATE_KIND_AS_STRING[kind.underlying()];
}

inline
const char* to_action_native_string(const rti::routing::EntityStateKind& kind)
{
    static const char * ENTITY_STATE_ACTION_AS_STRING[] = {
        "INVALID",
        "ENABLE",
        "DISABLE",
        "START",
        "STOP",
        "RUN",
        "PAUSE"
        ""
    };

    return ENTITY_STATE_ACTION_AS_STRING[kind.underlying()];
}

inline
const std::string to_action_string(const rti::routing::EntityStateKind& kind)
{
    return to_action_native_string(kind);
}

class EntityListener {
public:

    class Context {
    public:

        friend EntityListener::Context from_native(
                RTI_RoutingServiceEntityListenerContext*);

        const rti::routing::EntityKind& entity_kind() const
        {
            return entity_kind_;
        }

        const std::string& entity_name() const
        {
            return entity_name_;
        }

        const rti::routing::EntityStateKind& entity_state_kind() const
        {
            return entity_state_kind_;
        }

        bool ok()
        {
            return ok_;
        }

        rti::advlog::Entries logging_context_entries()
        {
            return logging_context_entries_;
        }

    private:
        rti::routing::EntityKind entity_kind_;
        std::string entity_name_;
        rti::routing::EntityStateKind entity_state_kind_;
        bool ok_;
        /*
         * We need to keep the entries of the context because they are entered
         * in a function and left in another function.
         * The number of entries is two:
         *  - An entry for the resource.
         *  - An entry for the activity.
         *
         * Recorder:
         *  - The entries are entered into the context using the macro
         *   RTI_ENTITY_LISTENER_CONTEXT_ENTER_ON_BEFORE in a function.
         *  - The entries are left using the macro
         *   RTI_ENTITY_LISTENER_CONTEXT_LEAVE_ON_AFTER in another function.
         *
         * For example:
         *      - Enter in EntityListener::on_before_create
         *      - Leave in EntityListener::on_after_create
         */
        rti::advlog::Entries logging_context_entries_;
    };

    virtual void on_before_create( EntityListener::Context&)
    {
    }

    virtual void on_after_create(EntityListener::Context&)
    {
    }

    virtual void on_before_state_change(EntityListener::Context&)
    {
    }

    virtual void on_after_state_change(EntityListener::Context&)
    {
    }

    virtual void on_before_delete(EntityListener::Context&)
    {
    }

    virtual void on_after_delete(EntityListener::Context&)
    {
    }

    virtual void on_before_stream_event(
            EntityListener::Context&,
            const rti::routing::StreamInfo&)
    {
    }

    virtual void on_after_stream_event(
            EntityListener::Context&,
            const rti::routing::StreamInfo&)
    {
    }

    virtual ~EntityListener() {}

};

inline
EntityListener::Context from_native(
            RTI_RoutingServiceEntityListenerContext *native)
    {
        EntityListener::Context context;
        context.entity_kind_ = static_cast<EntityKind::type> (
                native->entity_kind);
        context.entity_name_ = native->entity_name;
        context.entity_state_kind_ = static_cast<EntityStateKind::type> (
                native->entity_state_kind);
        context.ok_ = native->ok ? true : false;
        context.logging_context_entries_.from_native(
                native->logging_context_entries,
                native->logging_context_params);

        return context;
    }

class EntityListenerForwarder  {
public:

    typedef RTI_RoutingServiceEntityListener native;

    static native create(
            EntityListener *listener)
    {
        native native_listener = RTI_RoutingServiceEntityListener_INITIALIZER;
        native_listener.on_before_create =
                on_before_create_forwarder;
        native_listener.on_after_create =
                on_after_create_forwarder;
        native_listener.on_before_state_change =
                on_before_state_change_forwarder;
        native_listener.on_after_state_change =
                on_after_state_change_forwarder;
        native_listener.on_before_delete =
                on_before_delete_forwarder;
        native_listener.on_after_delete =
                on_after_delete_forwarder;
        native_listener.on_before_stream_event =
                on_before_stream_event_forwarder;
        native_listener.on_after_stream_event =
                on_after_stream_event_forwarder;
        native_listener.listener_data = static_cast<void*>(listener);

        return native_listener;
    }

private:
    static void on_before_create_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_before_create(context);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }
    static void on_after_create_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_after_create(context);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }

    static void on_before_state_change_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_before_state_change(context);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }

    static void on_after_state_change_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_after_state_change(context);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }

    static void on_before_delete_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_before_delete(context);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }

    static void on_after_delete_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_after_delete(context);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }

    static void on_before_stream_event_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native,
            const RTI_RoutingServiceStreamInfo *stream_info)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_before_stream_event(
                    context,
                    *stream_info);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }

    static void on_after_stream_event_forwarder(
            void *listener_data,
            RTI_RoutingServiceEntityListenerContext *context_native,
            const RTI_RoutingServiceStreamInfo *stream_info)
    {
        EntityListener *listener =
                static_cast<EntityListener *>(listener_data);
        try {
            EntityListener::Context context =
                    rti::routing::from_native(context_native);
            listener->on_after_stream_event(
                    context,
                    *stream_info);
        } catch (rti::apputils::ServiceException& ex) {
            SERVICELog_fromException(ex);
        } catch (std::exception& ex) {
            SERVICELog_exception(&RTI_LOG_ANY_s, ex.what());
        } catch (...) {
            SERVICELog_exception(&RTI_LOG_UNEXPECTED_EXCEPTION);
        }
    }
};

}}





#endif // RTI_ROUTING_ENTITY_LISTENER_HPP_
