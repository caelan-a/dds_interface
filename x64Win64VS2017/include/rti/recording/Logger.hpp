/*
 * (c) Copyright, Real-Time Innovations, 2017.
 * All rights reserved.
 *
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef RTI_RECORDING_LOGGER_HPP_
#define RTI_RECORDING_LOGGER_HPP_

#include "recordingservice/recordingservice_dll.h"

#include <dds/core/Reference.hpp>
#include <rti/config/Logger.hpp>


namespace rti { namespace recording {

/** \ingroup RTI_RecordingServiceLibModule
 *
 * @brief The singleton type used to configure @product verbosity
 *
 * For configuring other aspects such as output file, print format or
 * RTI Connext specific logging, use rti::config::Logger.
 *
 */
class RECORDERDllExport Logger
{
public:

    typedef rti::config::Verbosity Verbosity;
    typedef rti::config::LogCategory LogCategory;
    typedef rti::config::LoggerMode LoggerMode;
    typedef rti::config::PrintFormat PrintFormat;

    static Logger& instance();

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
    void error(const std::string& msg);

    /**
     * @brief overload of error(const std::string& msg)
     */
    void error(const char *msg);

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * WARNING.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::recording::Logger::error
     *
     */
    void warn(const std::string& msg);

    /**
     * @brief overload of warn(const std::string& msg)
     */
    void warn(const char *msg);

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * STATUS_LOCAL.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::recording::Logger::error
     *
     */
    void local(const std::string& msg);

    /**
     * @brief overload of local(const std::string& msg)
     */
    void local(const char *msg);

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * STATUS_REMOTE.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::recording::Logger::error
     *
     */
    void remote(const std::string& msg);

    /**
     * @brief overload of remote(const std::string& msg)
     */
    void remote(const char *msg);

    /**
     * @brief Logs as message with WARNING level
     *
     * This operation behaves similar to error() except the log level is
     * STATUS_DEBUG.
     *
     * @param[in] msg Message to be logged
     *
     * @see rti::recording::Logger::error
     *
     */
    void debug(const std::string& msg);

    /**
     * @brief overload of debug(const std::string& msg)
     */
    void debug(const char *msg);

    /**
     * @brief Sets the verbosity for the log messages generated at the
     * @product level.
     *
     * @param[in] verbosity
     *            The verbosity of the service logs
     */
    void service_verbosity(rti::config::Verbosity verbosity);

    /**
     * @brief Getter for the same attribute
     *
     * @see verbosity(rti::config::Verbosity)
     */
    rti::config::Verbosity service_verbosity();

    /**
     * @deprecated
     * @see service_verbosity
     */
    void verbosity(rti::config::Verbosity verbosity);

    /**
     * @deprecated
     * @see service_verbosity
     */
    rti::config::Verbosity verbosity();

    virtual ~Logger();

private:

    void message(const rti::config::LogLevel& level, const char* msg);

    Logger();

     // Disable copy
    Logger(const Logger&);
    Logger& operator=(const Logger&);
};

}}

#endif // RTI_RECORDING_LOGGER_HPP_
