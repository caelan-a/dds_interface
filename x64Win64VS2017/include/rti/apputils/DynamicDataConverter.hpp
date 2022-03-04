/*
 * (c) Copyright, Real-Time Innovations, 2016-.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef HPP_SERVICE_DYNAMIC_DATA_CONVERTER_HPP_
#define HPP_SERVICE_DYNAMIC_DATA_CONVERTER_HPP_


// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "osapi/osapi_heap.h"
#include <dds/core/Value.hpp>
#include <dds/core/types.hpp>
#include <rtiboost/assert.hpp>
#include <dds/core/xtypes/DynamicType.hpp>
#include <dds/core/xtypes/DynamicData.hpp>
#include <rti/core/NativeValueType.hpp>
#include <rti/apputils/ServiceException.hpp>
#include <rti/apputils/DynamicBuffer.hpp>
#include "apputils/apputils_dynamic_data_converter_impl.h"

namespace rti { namespace apputils {

class DynamicDataConverter {
public:

    class ScopedSample {
    public:

        ScopedSample(
                APPUTILSDynamicDataConverter *converter,
                DDS_DynamicData *native) :
            converter_(converter),
            native_(native)
        {
        }

        ~ScopedSample()
        {
            APPUTILSDynamicDataConverter_return_sample(converter_, native_);
        }

        dds::core::xtypes::DynamicData& get()
        {
            return rti::core::native_conversions::cast_from_native<
                    dds::core::xtypes::DynamicData>(*native_);
        }

    private:
        APPUTILSDynamicDataConverter *converter_;
        DDS_DynamicData *native_;
    };

    class ScopedBuffer {
    public:

        ScopedBuffer() : converter_(NULL), native_(NULL), native_length_(0)
        {
        }

        ScopedBuffer(
                APPUTILSDynamicDataConverter *converter,
                void *native,
                uint32_t native_length) :
            converter_(converter),
            native_(native),
            native_length_(native_length)
        {
        }

        ~ScopedBuffer()
        {
            if (native_ != NULL) {
                APPUTILSDynamicDataConverter_return_buffer(converter_, native_);
            }
        }

        void clear()
        {
            assign(converter_, NULL, 0);
        }

        void assign(
                APPUTILSDynamicDataConverter *converter,
                void *native,
                uint32_t native_length)
        {
            if (native_ != NULL) {
                APPUTILSDynamicDataConverter_return_buffer(
                        converter_,
                        const_cast<void *>(native_));
            }
            converter_ = converter;
            native_ = native;
            native_length_ = native_length;
        }

        ScopedBuffer& operator =(ScopedBuffer& other)
        {
            assign(other.converter_, other.native_, other.native_length_);
            return *this;
        }

        const void * get()
        {
            return native_;
        }

        template <typename T>
        const T * get() {
            return static_cast<const T *>(native_);
        }

        uint32_t length()
        {
            return native_length_;
        }

    private:
        APPUTILSDynamicDataConverter *converter_;
        void *native_;
        uint32_t native_length_;
    };

    /**
     * The dynamic data converter allows for deferred initialization. When doing
     * so, it can be initialized at any moment by calling the set() method.
     */
    DynamicDataConverter() : initialized_(false) {}

    /**
     * Direct initialization constructor. A valid type-code has to be provided
     * (not null and it has to be a non-primitive and non null type-kind type).
     */
    DynamicDataConverter(
            const dds::core::xtypes::DynamicType& type_code,
            const DynamicBufferProperty &property) :
        initialized_(false)
    {
        set(type_code, property);
    }

    /**
     * Initialize this dynamic data converter. A valid type-code has to be
     * provided (not null and it has to be a non-primitive and non null
     * type-kind type).
     * If the converter has already been initialized, this method is a no-op.
     */
    void set(
            const dds::core::xtypes::DynamicType& type_code,
            const DynamicBufferProperty &property)
    {
        if (!initialized_) {
            if (!APPUTILSDynamicDataConverter_initialize(
                    &converter_,
                    &(type_code.native()),
                    (RTI_UINT32) property.min_size())) {
                RTI_THROW_SERVICE_EXCEPTION(
                        &RTI_LOG_INIT_FAILURE_s,
                        "native converter");
            }
            initialized_ = true;
        }
    }

    ~DynamicDataConverter()
    {
        if (initialized_) {
            APPUTILSDynamicDataConverter_finalize(&converter_);
        }
    }

    ScopedSample sample(
            const dds::core::xtypes::DynamicData& sample,
            const DDS_DataRepresentationId_t target_representation)
    {
        DDS_DynamicData *native = APPUTILSDynamicDataConverter_get_sample(
                &converter_,
                const_cast<DDS_DynamicData *>(&sample.native()),
                target_representation);
        if (native == NULL) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_ANY_FAILURE_s,
                    "get native sample");
        }
        return ScopedSample(&converter_, native);
    }

    ScopedBuffer buffer(
            const dds::core::xtypes::DynamicData& sample,
            const DDS_DataRepresentationId_t target_representation)
    {
        DDS_UnsignedLong native_length = 0;
        void *native = APPUTILSDynamicDataConverter_get_buffer(
                &converter_,
                &native_length,
                const_cast<DDS_DynamicData *>(&sample.native()),
                target_representation);
        if (native == NULL) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_ANY_FAILURE_s,
                    "get native buffer");
        }
        return ScopedBuffer(&converter_, native, (uint32_t) native_length);
    }

    void buffer(
            ScopedBuffer& scoped_buffer,
            const dds::core::xtypes::DynamicData& sample,
            const DDS_DataRepresentationId_t target_representation)
    {
        DDS_UnsignedLong native_length = 0;
        /*
         * The scoped buffer has to be cleared before we can use it again. The
         * buffer will automatically be returned to this converter. After this,
         * we can safely get the buffer again from the dynamic data sample and
         * reassign to the scoped buffer.
         */
        scoped_buffer.clear();
        void *native = APPUTILSDynamicDataConverter_get_buffer(
                &converter_,
                &native_length,
                const_cast<DDS_DynamicData *>(&sample.native()),
                target_representation);
        if (native == NULL) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_ANY_FAILURE_s,
                    "get native buffer");
        }
        scoped_buffer.assign(&converter_, native, (uint32_t) native_length);
    }

private:
    APPUTILSDynamicDataConverter converter_;
    bool initialized_;
};


} } /* namespace rti::apputils */
#endif /* HPP_SERVICE_DYNAMIC_DATA_CONVERTER_HPP_ */
