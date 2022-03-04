/*
 * (c) Copyright, Real-Time Innovations, 2016-.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef APPUTILS_HPP_
#define APPUTILS_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "stdio.h"
#include "stdlib.h"
#include <string>
#include <sstream>
#include <stdint.h>

#include "osapi/osapi_utility.h"
#include <dds/core/types.hpp>

#include <rti/core/Exception.hpp>


#define STATIC_CONST_STRING_DEFINITION(classname, name, value) \
const std::string& classname::name() \
{ \
    static std::string name##var(value); \
    return name##var; \
}

#define RECORDER_FILE_PATH_MAX_LENGTH  (4096)

namespace rti { namespace apputils { namespace util {

inline
std::string normalize_path(const std::string& file_name)
{
    char normalized[RECORDER_FILE_PATH_MAX_LENGTH] = {'\0'};
    if (!RTIOsapiUtility_normalizePath(
            normalized,
            RECORDER_FILE_PATH_MAX_LENGTH,
            file_name.c_str())) {
        std::stringstream error_msg;
        error_msg << "!normalize path " << file_name.c_str() << "\n";
        throw dds::core::IllegalOperationError(error_msg.str());
    }

    return normalized;
}

} } } // namespace rti:apputils::util

#endif /* APPUTILS_HPP_ */

