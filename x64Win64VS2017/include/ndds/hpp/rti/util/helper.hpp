/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef RTI_UTIL_HELPER_HPP_
#define RTI_UTIL_HELPER_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

namespace rti { namespace util {

// This helper method takes in a size_t and checks if it is greater than
// INT_MAX, throwing an error if true. This is needed for x64 architectures
// when trying to use the result of pointer arithmetic (which retuns int64
// values) to set the length of something that is assumed to be of type int32
OMG_DDS_API
int cast_length(size_t length);

template <typename T>
bool equal_ptr(const T * a, const T * b);

template <typename T>
std::ostream& print_ptr(std::ostream& out, const T * ptr);

OMG_DDS_API
std::string ptr_to_str(const void * p);

OMG_DDS_API
void * str_to_ptr(const std::string& s);

template <typename T>
bool equal_ptr(const T * a, const T * b)
{
    if (a == b) {
        return true; // Both are NULL or same address
    }

    if (a == NULL || b == NULL) {
        return false; // One is NULL and one isn't
    }

    return *a == *b; // None is NULL
}

template <typename T>
std::ostream& print_ptr(std::ostream& out, const T * ptr)
{
    if (ptr == NULL) {
        out << "NULL";
    } else {
        out << *ptr;
    }

    return out;
}

} } // namespace rti::util

#endif // RTI_UTIL_HELPER_HPP_
