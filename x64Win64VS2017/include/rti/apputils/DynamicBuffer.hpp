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

#ifndef HPP_SERVICE_DYNAMIC_BUFFER_HPP_
#define HPP_SERVICE_DYNAMIC_BUFFER_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "osapi/osapi_heap.h"

#include <dds/core/Value.hpp>
#include <dds/core/types.hpp>
#include <rtiboost/assert.hpp>
#include <rti/apputils/ServiceException.hpp>

namespace rti { namespace apputils {

class DynamicBufferProperty {
public:

    DynamicBufferProperty(int32_t min_size, bool trim_to_size)
        :min_size_(min_size), trim_to_size_(trim_to_size)
    {
    }

    DynamicBufferProperty(const DynamicBufferProperty &property)
        :min_size_(property.min_size_), trim_to_size_(property.trim_to_size_)
    {
    }

    DynamicBufferProperty& min_size(int32_t min_size)
    {
        min_size_ = min_size;
        return *this;
    }
    int32_t min_size() const
    {
        return min_size_;
    }

    DynamicBufferProperty& trim_to_size(bool trim_to_size)
    {
        trim_to_size_ = trim_to_size;
        return *this;
    }

    bool trim_to_size() const
    {
        return trim_to_size_;
    }

private:
    int32_t min_size_;
    bool trim_to_size_;
};


class DynamicBuffer {
public:

    DynamicBuffer(const DynamicBufferProperty &property)
        :property_(property), buffer_(NULL), buffer_length_(0)
    {
        ensure_length(property.min_size());
    }

    ~DynamicBuffer()
    {
        if (buffer_ != NULL) {
            RTIOsapiHeap_freeArray(buffer_);
            buffer_ = NULL;
        }
        buffer_length_ = 0;
    }

    void ensure_length(int32_t new_length)
    {
        if (new_length > buffer_length_) {
            if (!RTIOsapiHeap_reallocateArray(&buffer_, new_length, char)) {
                RTI_THROW_SERVICE_EXCEPTION(
                        &RTI_OSAPI_MEMORY_LOG_OUT_OF_HEAP_STRING_d,
                        new_length);
            }
            buffer_length_ = new_length;
        }
    }

    void trim_to_size()
    {
        if (property_.trim_to_size()) {
            if (!RTIOsapiHeap_reallocateArray(
                    &buffer_,
                    property_.min_size(),
                    char)) {
                RTI_THROW_SERVICE_EXCEPTION(
                        &RTI_OSAPI_MEMORY_LOG_OUT_OF_HEAP_STRING_d,
                        property_.min_size());
            }
            buffer_length_ = property_.min_size();
        }
    }

    void release(char *&buffer, int32_t& length)
    {
        buffer = buffer_;
        length = buffer_length_;
        buffer_ = NULL;
        buffer_length_ = 0;
    }

    void own(char *buffer, int32_t length)
    {
        buffer_ =  buffer;
        buffer_length_ = length;
    }

    char *buffer()
    {
        return buffer_;
    }

    int32_t length()
    {
        return buffer_length_;
    }

private:
    const DynamicBufferProperty property_;
    char* buffer_;
    int32_t buffer_length_;
};


} } /* namespace rti::apputils */
#endif /* HPP_SERVICE_DYNAMIC_BUFFER_HPP_ */
