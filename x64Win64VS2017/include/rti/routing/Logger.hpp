/*
 * (c) Copyright, Real-Time Innovations, 2017.
 * All rights reserved.
 *
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef RTI_ROUTING_LOGGER_HPP_
#define RTI_ROUTING_LOGGER_HPP_

#include <dds/core/Reference.hpp>
#include <rti/config/Logger.hpp>

#include "routingservice/routingservice_log.h"
#include "routingservice/routingservice_service.h"

namespace rti { namespace routing {


/** \ingroup RTI_RoutingServiceLibModule
 *
 * @brief The singleton type used to configure @product verbosity
 *
 * For configuring other aspects such as output file, print format or
 * RTI Connext specific logging, use rti::config::Logger.
 */
class Logger
{
public:

    typedef rti::config::Verbosity Verbosity;
    typedef rti::config::LogCategory LogCategory;
    typedef rti::config::LoggerMode LoggerMode;
    typedef rti::config::PrintFormat PrintFormat;

    static Logger& instance()
    {
        static Logger singleton;
        return singleton;
    }

    /**
     * @brief Sets the verbosity for the log messages generated at the
     * @product level.
     *
     * @param verbosity
     *        @rs_st_in The verbosity of the service logs
     */
    void service_verbosity(rti::config::Verbosity verbosity)
    {
        RTILogBitmap submodule_mask = ROUTER_SUBMODULE_MASK_ALL;
        ROUTERLog_setBitmaps(
                submodule_mask,
                static_cast<RTILogBitmap>(verbosity.underlying()));
    }

    /**
     * @brief Getter for the same attribute
     *
     * @see service_verbosity(rti::config::Verbosity)
     */
     rti::config::Verbosity service_verbosity()
    {
        RTILogBitmap submodule_mask = ROUTER_SUBMODULE_MASK_ALL;
        RTILogBitmap instrumentation_mask = ROUTER_SUBMODULE_MASK_ALL;
        ROUTERLog_getBitmaps(&submodule_mask, &instrumentation_mask);

        return static_cast<rti::config::Verbosity::type>(instrumentation_mask);
    }

    /**
     * @brief Logs as message with EXCEPTION level
     *
     * The generated log will be part of logging stream of the running service
     * if the service verbosity contains EXCEPTION messages. The result log
     * message may include additional information according to the
     * Connext logging configuration, such as Advlog Context, thread ID,
     * line number, etc. Additionally, the result log message will contain a
     * newline character at the end, so the format does not need to contain it.
     *
     * @param[in] msg Message to be logged
     */
    void error(const std::string& msg)
    {
        this->error(msg.c_str());
    }

    /**
     * @brief overload of error(const std::string& msg)
     */
    void error(const char *msg)
    {
        this->message(rti::config::LogLevel::EXCEPTION, msg);
    }

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * WARNING.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::routing::Logger::error
     *
     */
    void warn(const std::string& msg)
    {
        this->warn(msg.c_str());
    }

    /**
     * @brief overload of warn(const std::string& msg)
     */
    void warn(const char *msg)
    {
        this->message(rti::config::LogLevel::WARNING, msg);
    }

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * STATUS_LOCAL.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::routing::Logger::error
     *
     */
    void local(const std::string& msg)
    {
        this->local(msg.c_str());
    }

    /**
     * @brief overload of local(const std::string& msg)
     */
    void local(const char *msg)
    {
        this->message(rti::config::LogLevel::STATUS_LOCAL, msg);
    }

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * STATUS_REMOTE.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::routing::Logger::error
     *
     */
    void remote(const std::string& msg)
    {
        this->remote(msg.c_str());
    }

    /**
     * @brief overload of remote(const std::string& msg)
     */
    void remote(const char *msg)
    {
        this->message(rti::config::LogLevel::STATUS_REMOTE, msg);
    }

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * STATUS_DEBUG.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::routing::Logger::error
     *
     */
    void debug(const std::string& msg)
    {
        this->debug(msg.c_str());
    }

    /**
     * @brief overload of debug(const std::string& msg)
     */
    void debug(const char *msg)
    {
        this->message(rti::config::LogLevel::STATUS_ALL, msg);
    }

    virtual ~Logger()
    {
    }

private:

    void message(const rti::config::LogLevel& level, const char* msg)
    {
        RTI_RoutingServiceLogger_log(
                static_cast<NDDS_Config_LogLevel> (level.underlying()),
                "%s",
                msg);
    }

    Logger()
    {
    }
     // Disable copy
    Logger(const Logger&);
    Logger& operator=(const Logger&);
};

}}

#endif // RTI_ROUTING_LOGGER_HPP_
