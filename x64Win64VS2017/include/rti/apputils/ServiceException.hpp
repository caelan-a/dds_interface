/*
 * $Id$
 *
 * (c) Copyright, Real-Time Innovations, 2016-.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef HPP_SERVICE_SERVICE_EXCEPTION_HPP_
#define HPP_SERVICE_SERVICE_EXCEPTION_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/types.hpp>
#include <dds/core/Exception.hpp>

namespace rti { namespace apputils {

static
void initialize_exception_message(
        std::string& message,
        const char *throwing_context,
        const RTILogMessage *log_message,
        va_list ap)
{
    RTIOsapiUtility_snprintf(
            &message[0],
            RTI_LOG_MSG_SIZE_MAX,
            "%s:",
            throwing_context);
    RTIOsapiUtility_vsnprintf(
            &message[0] + strlen(message.c_str()),
            RTI_LOG_MSG_SIZE_MAX - (int) strlen(message.c_str()),
            log_message->format,
            ap);
}


class ServiceException : public std::exception {
public:

    ServiceException(
            const char *throwing_context,
            const RTILogMessage *log_message,
            ...)
    : message_(RTI_LOG_MSG_SIZE_MAX, '\0'),
      error_code_(log_message->logNumber)
    {
        va_list ap;
        va_start(ap, log_message);
        initialize_exception_message(
                message_,
                throwing_context,
                log_message,
                ap);
        va_end(ap);
    }

    int32_t error_code() const
    {
        return error_code_;
    }

    virtual const char* what() const throw ()
    {
        return message_.c_str();
    }

    virtual ~ServiceException() throw ()
    {
    }

private:

    ServiceException() : error_code_(0)
    {
    }

    std::string message_;
    int32_t error_code_;
};

} } /* namespace rti::apputils */

#define RTI_THROW_SERVICE_EXCEPTION(...) \
    throw rti::apputils::ServiceException(\
            RTI_FUNCTION_NAME,\
            __VA_ARGS__)

#define RTI_SERVICE_CHECK_CONDITION(EXPRESSION) \
    if(!(EXPRESSION)) { \
        RTI_THROW_SERVICE_EXCEPTION( \
                &RTI_LOG_ANY_s, \
                __FILE__ ":" RTI_TOSTRING(__LINE__) ": condition failed: " #EXPRESSION); \
    }


#endif /* HPP_SERVICE_SERVICE_EXCEPTION_HPP_ */
