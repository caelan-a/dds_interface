/*
 (c) Copyright, Real-Time Innovations, 2017-
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made without
 express written permission.  Any such copies, or revisions thereof, must
 display this notice unaltered.

 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef HPP_SERVICE_LOG_CONFIG_HPP_
#define HPP_SERVICE_LOG_CONFIG_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <cstdio>
#include <cstdarg>

#include "log/log_common.h"

#include <rti/advlog/Context.hpp>
#include <rti/config/Logger.hpp>
#include <rti/apputils/ServiceException.hpp>

#define RTI_SUBMODULE_MASK_ALL (0xFFFF)

namespace rti { namespace apputils { namespace log {

class LogConfig {
public:

    static LogConfig& instance()
    {
        static LogConfig singleton;
        return singleton;
    }

    RTILogBitmap instrumentation_mask() const
    {
        return instrumentation_mask_;
    }

    LogConfig& instrumentation_mask(RTILogBitmap logmask)
    {
        instrumentation_mask_ = logmask;
        return *this;
    }

    rti::config::Verbosity verbosity()
    {
        return static_cast<rti::config::Verbosity::type>(instrumentation_mask_);
    }

    void verbosity(rti::config::Verbosity verbosity)
    {
        instrumentation_mask(
                static_cast<RTILogBitmap>(verbosity.underlying()));
    }

    ~LogConfig()
    {
    }

    static RTILogBitmap mask_all()
    {
        return RTI_SUBMODULE_MASK_ALL;
    }

    static RTILogBitmap mask_none()
    {
        return 0;
    }

protected:

    // Constructor is private: this class is a singleton
    LogConfig()
        : instrumentation_mask_(RTI_LOG_BITMAP_DEFAULT)
    {
        RTILog_appendPrintMask(RTI_LOG_PRINT_BIT_AT_METHOD);
    }

    RTILogBitmap instrumentation_mask_;
};

inline
rti::config::Verbosity dds_verbosity_from_level(int32_t level)
{
    switch (level) {
    case 6:
        return rti::config::Verbosity::STATUS_REMOTE;
    case 5:
        /* no break */
    case 4:
        return rti::config::Verbosity::WARNING;
    case 3:
        /* no break */
    case 2:
        /* no break */
    case 1:
        return rti::config::Verbosity::EXCEPTION;
    case 0:
        return rti::config::Verbosity::SILENT;
    default:
        return rti::config::Verbosity::EXCEPTION;
    }
}

inline
rti::config::Verbosity service_verbosity_from_level(int32_t level)
{
    RTILogBitmap native_verbosity = RTI_LOG_BIT_SILENCE;

    switch (level) {
        /* no break */
    case 6:
         native_verbosity |= RTI_LOG_BIT_CONTENT;
        /* no break */
    case 5:
        native_verbosity |= RTI_LOG_BIT_PERIODIC;
        /* no break */
    case 4:
        /* no break */
        native_verbosity |= RTI_LOG_BIT_REMOTE;
    case 3:
        native_verbosity |= RTI_LOG_BIT_LOCAL;
        /* no break */
    case 2:
        native_verbosity |= RTI_LOG_BIT_WARN;
        /* no break */
    case 1:
        native_verbosity |= RTI_LOG_BIT_EXCEPTION | RTI_LOG_BIT_FATAL_ERROR;
        break;
    case 0:
        break;
    default:
        native_verbosity = RTI_LOG_BITMAP_DEFAULT;
        break;
    }

    return static_cast<rti::config::Verbosity::type>(native_verbosity);

}

/*
 * Example:
 * MyCatcherMethod: caught exception from:
 *     MyThrowerMethod:!init failure
 */
inline void log_service_exception(
        rti::apputils::log::LogConfig& log_config,
        const rti::apputils::ServiceException& exception,
        const char *method_name)
{
    RTILogMessage log_message;

    log_message.format = "caught exception from:\n    %s";
    log_message.logNumber = exception.error_code();

    if (log_config.instrumentation_mask() & RTI_LOG_BIT_EXCEPTION) {
        RTILogMessage_printWithParams(
                RTI_LOG_PRINT_FORMAT_MASK_ALL_EXCEPT_LOCATION_FILELINE_AND_MODULE,
                RTI_LOG_BIT_EXCEPTION,
                MODULE_LOG,
                NULL, /* filename */
                0, /* lineno */
                method_name,
                &log_message,
                exception.what());
    }
}

} } } /* namespace rti::apputils::log */

/*
 * --- C-like logger macros ---------------------------------------------------
 */
#define SERVICELog_fromException(SERVICE_EXCEPTION) \
    rti::apputils::log::log_service_exception( \
            (MODULE_LOG_CONFIG), \
            SERVICE_EXCEPTION, \
            RTI_FUNCTION_NAME)

/*
 * For legacy reasons, we keep the definition of freeForm.
 * freeForm is now deprecated and it should not be used anymore.
 * These are the alternatives to freeForm (only to be used in test code or
 * non-production code, like an instrumented build):
 * - If you need to log (verbosity filtered) an unformatted parameterized string
 *  you can use RTITestLogParamString_log (in tests) or
 *  RTILogParamString_logUnformatted (in non-test, instrumented build code).
 *  This is equivalent to old freeForm().
 * - If you just need to print (not verbosity filtered) an unformatted parameterized
 *   string, use RTILogParamString_printPlain.
 * - Finally, if you need print a formatted parameterized string, use RTILogParamString_print.
 */
#define SERVICELog_freeForm(INSTRUMENT_BIT, ...) \
    RTILogParamString_logUnformatted( \
            (MODULE_LOG_CONFIG).instrumentation_mask(), \
            RTI_SUBMODULE_MASK_ALL, \
            RTI_SUBMODULE_MASK_ALL, \
            (INSTRUMENT_BIT), \
            __VA_ARGS__)

#define SERVICELog_logMessage(INSTRUMENT_BIT, ...) \
    RTILogMessage_log( \
            (MODULE_LOG_CONFIG).instrumentation_mask(), \
            RTI_SUBMODULE_MASK_ALL, \
            RTI_SUBMODULE_MASK_ALL, \
            RTI_LOG_PRINT_FORMAT_MASK_ALL_EXCEPT_LOCATION, \
            (INSTRUMENT_BIT), \
            DEFINE_MODULE_NUMBER(MODULE_NS), \
            __VA_ARGS__)

#define SERVICELogMessage_log(INSTRUMENT_BIT, ...) \
    RTILogMessage_log( \
            (MODULE_LOG_CONFIG).instrumentation_mask(), \
            RTI_SUBMODULE_MASK_ALL, \
            RTI_SUBMODULE_MASK_ALL, \
            RTI_LOG_PRINT_FORMAT_MASK_ALL, \
            (INSTRUMENT_BIT), \
            DEFINE_MODULE_NUMBER(MODULE_NS), \
            __VA_ARGS__)

#define SERVICELog_exception(...) \
    SERVICELogMessage_log(RTI_LOG_BIT_EXCEPTION, __VA_ARGS__)

#define SERVICELog_warn(...) \
    SERVICELogMessage_log(RTI_LOG_BIT_WARN, __VA_ARGS__)

#define SERVICELog_local(...) \
    SERVICELogMessage_log(RTI_LOG_BIT_LOCAL, __VA_ARGS__)

#define SERVICELog_content(...) \
    SERVICELogMessage_log(RTI_LOG_BIT_CONTENT, __VA_ARGS__)

#define SERVICELog_remote(...) \
    SERVICELogMessage_log(RTI_LOG_BIT_REMOTE, __VA_ARGS__)


#define SERVICELog_any(INSTRUMENT_BIT, ...) \
    if ((((MODULE_LOG_CONFIG).instrumentation_mask()) & (INSTRUMENT_BIT)) \
            && ((RTI_SUBMODULE_MASK_ALL) & (RTI_SUBMODULE_MASK_ALL)))

#define SERVICELog_flushActivityContextWithAction(INSTRUMENT_BIT, ACTION) \
    SERVICELog_logMessage((INSTRUMENT_BIT), &RTI_LOG_ANY_s, (ACTION));

#define SERVICELog_flushActivityContext(INSTRUMENT_BIT) \
    SERVICELog_logMessage((INSTRUMENT_BIT), &RTI_LOG_ANY_s, "");

/*
 * The macro:
 *  - Creates a contextScope
 *  - Enter a resource entry into the context.
 *  - Enter an activity entry into the context.
 *
 * When the function where the macro is called is end, the destructor of
 * the contextScope will be called and the entries will leave the context.
 */
#define RTI_SERVICE_CONTEXT_ENTER( \
        RESOURCE_ID, \
        ...) \
    rti::advlog::ContextScope context_scope_guard_implicit__; \
    context_scope_guard_implicit__.enter(RESOURCE_ID); \
    context_scope_guard_implicit__.enter(__VA_ARGS__)

#define RTI_SERVICE_CONTEXT_ENTER_LOG( \
        RESOURCE_ID, \
        ...) \
    RTI_SERVICE_CONTEXT_ENTER( \
            RESOURCE_ID, \
            __VA_ARGS__); \
    SERVICELog_flushActivityContext(RTI_LOG_BIT_LOCAL)

#endif /* HPP_SERVICE_LOG_CONFIG_HPP_ */
