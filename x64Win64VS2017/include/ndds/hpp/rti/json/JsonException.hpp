/*
 * (c) Copyright, Real-Time Innovations, 2020.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef HPP_RTI_JSON_EXCEPTION_HPP_
#define HPP_RTI_JSON_EXCEPTION_HPP_

#include <string>
#include <stdexcept>

// This header must be used along with the Modern C++ API
#ifdef OMG_DDS_API
    #include <dds/core/Exception.hpp>
#endif

#include "osapi/osapi_type.h"
#include "osapi/osapi_utility.h"

#define JSON_CURRENT_SUBMODULE JSON_SUBMODULE_MASK_PARSER

namespace rti { namespace json {

namespace detail {
#if defined(OMG_DDS_API)
typedef dds::core::PreconditionNotMetError JsonExceptionBase;
#else
typedef std::logic_error JsonExceptionBase;
#endif
} // namespace detail

/*
 * This class wraps an RTIJSONObject object providing to handle its memory
 * using a constructor and a destructor.
 */
class JsonError : public detail::JsonExceptionBase {
public:

    JsonError(const char *message) : detail::JsonExceptionBase(message)
    {
    }

};

} } /* namespace rti::json */

#undef JSON_CURRENT_SUBMODULE   /* JSON_SUBMODULE_MASK_PARSER */

#endif /* HPP_RTI_JSON_EXCEPTION_HPP_ */
