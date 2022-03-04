/*
(c) Copyright, Real-Time Innovations, 2018.
All rights reserved.
No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.
*/
#ifndef HPP_APPUTILS_LOCKEDBUFFER_HPP_
#define HPP_APPUTILS_LOCKEDBUFFER_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "dds/core/types.hpp"

namespace rti { namespace apputils { namespace util {

/**
 * A type-agnostic class that services as a locked, unmodifiable region in
 * memory. This is handy to transport a data buffer from one code region to
 * another without having to perform any copy operations. Producer of the buffer
 * and consumer of the buffer know how to work with the raw data.
 */
class UntypedLockedBuffer {
public:
    UntypedLockedBuffer() : buffer_(NULL), size_(0) {}
    UntypedLockedBuffer(const void *buffer, const uint32_t size) :
        buffer_(buffer), size_(size) {}
    ~UntypedLockedBuffer() {}

    void set(const void *buffer, const uint32_t size)
    {
        buffer_ = buffer;
        size_ = size;
    }

    void reset()
    {
        buffer_ = NULL;
        size_ = 0;
    }

    uint32_t size() const { return size_; }

protected:

    const void * buffer() const { return buffer_; }

private:
    const void *buffer_;
    uint32_t size_;
};


/**
 * This class represents a locked, unmodifiable region in memory. This is handy
 * to transport a data buffer from one code region to another without having to
 * perform any copy operations. Producer of the buffer and consumer of the
 * buffer know how to work with the raw data.
 */
template <typename T>
class LockedBuffer : public UntypedLockedBuffer {
public:
    LockedBuffer() : UntypedLockedBuffer() {}
    LockedBuffer(const T *buffer, const uint32_t size) :
        UntypedLockedBuffer(static_cast<const void *>(buffer), size) {}
    ~LockedBuffer() {}

    void set(const T *buffer, const uint32_t size)
    {
        UntypedLockedBuffer::set(static_cast<const void *>(buffer), size);
    }

    const T * buffer() const {
        return static_cast<const T *>(UntypedLockedBuffer::buffer());
    }
};

} } } // namespace rti::apputils::util

#endif /* HPP_APPUTILS_LOCKEDBUFFER_HPP_ */
