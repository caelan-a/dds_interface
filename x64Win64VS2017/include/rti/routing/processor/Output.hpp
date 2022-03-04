/*
 * (c) Copyright, Real-Time Innovations, 2017.
 * All rights reserved.
 *
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef RTI_ROUTING_PROCESSOR_OUTPUT_HPP_
#define RTI_ROUTING_PROCESSOR_OUTPUT_HPP_

#include <dds/core/Value.hpp>
#include <dds/core/SafeEnumeration.hpp>
#include <rti/core/NativeValueType.hpp>
#include <dds/pub/DataWriter.hpp>
#include <dds/core/xtypes/DynamicData.hpp>

#include "routingservice/routingservice_processor.h"
#include "routingservice/routingservice_adapter_new.h"
#include <rti/routing/adapter/StreamWriter.hpp>

namespace rti { namespace routing { namespace processor {

class Route;

template <typename Data, typename Info> class TypedOutput;

template <typename Data, typename Info = dds::sub::SampleInfo>
class TypedOutput;

/** @ingroup RTI_RoutingServiceProcessorModule
 *
 * @class rti::routing::processor::Output
 *
 * @brief Generic Representation of a Route's output.
 *
 * This class provides a base representation of the outputs contained in a Route.
 * Since it is generic, this object does not allow performing any operation
 * that requires dealing with the data passed to the underlying
 * rti::routing::adapter::StreamWriter.
 */
class Output {
public:

    /*i
     */
    Output(
        RTI_RoutingServiceOutput *native,
        int32_t index,
        RTI_RoutingServiceRoute *native_route) :
            native_(native),
            index_(index),
            native_route_(native_route),
            stream_info_(*RTI_RoutingServiceOutput_get_stream_info(native)),
            name_(RTI_RoutingServiceOutput_get_name(native))
    {
    }

    /*i
     */
    const rti::routing::StreamInfo& stream_info() const
    {
        return stream_info_;
    }

    /*i
     *
     */
    const std::string& name() const
    {
        return name_;
    }

    /*i
     *
     */
    int32_t index()
    {
        return index_;
    }

    /**
     * @brief Returns a typed version of this Output.
     *
     * Note: This operation is not type-safe and it is the caller's
     * responsibility to use the appropriate type.
     *
     * @see TypedOutput
     * @see <tt>TypedOutput<DataRep, Info> Route<DataRep, InfoRep>::output(int32_t index)</tt>
     */
    template <typename Data, typename Info>
    TypedOutput<Data, Info> get()
    {
        return this;
    }

    /**
     * @brief Returns a typed version of this Output.
     *
     * Note: This operation is not type-safe and it is the caller's
     * responsibility to use the appropriate type.
     *
     * @see TypedOutput
     * @see TypedOutput<tt><DataRep, dds::sub::SampleInfo></tt> Route<DataRep>::output(int32_t index)
     */
    template <typename Data>
    TypedOutput<Data, dds::sub::SampleInfo> get()
    {
        return this;
    }

private:
    template <typename Data, typename Info> friend class TypedOutput;
    friend class Route;
    RTI_RoutingServiceOutput *native_;
    int32_t index_;
    RTI_RoutingServiceRoute *native_route_;
    rti::routing::StreamInfo stream_info_;
    std::string name_;
};

/** @ingroup RTI_RoutingServiceProcessorModule
 *
 * @class rti::routing::processor::TypedOutput
 *
 * @brief Representation of an Output whose data representation is \p DataRep,
 *        whose info representation is \p InfoRep.
 *
 */
template <typename Data, typename Info>
class TypedOutput{
public:
    TypedOutput(Output *output) ;

    TypedOutput<Data, Info>* operator->();

    /**
     * @brief Returns the StreamInfo associated with this object.
     *
     * The associated StreamInfo represents an equivalent object to the one
     * used to create the underlying rti::routing::adapter::StreamWriter.
     */
    const rti::routing::StreamInfo& stream_info() const;

    /**
     * @brief Returns the name of this output.
     *
     * The name is given by the name of the corresponding XML configuration tag.
     */
    const std::string& name() const;

    /**
     * @brief Writes the specified data and info sample in this output.
     *
     * This operation will call rti::routing::adapter::StreamWriter::write on
     * the underlying rti::routing::adapter::StreamWriter.
     *
     * The provided sample is interpreted to contain data represented
     * as \c Data and the info as \c Info.
     *
     * @see rti::routing::adapter::StreamWriter::write
     */
    void write(const Data& sample, const Info& info);

    /*
     * @brief Writes a sample given its data only.
     *
     * This operation will call rti::routing::adapter::StreamWriter::write
     * on the underlying rti::routing::adapter::StreamWriter, providing a null
     * value for the info sample. The underlying adapter will compute any
     * associated metadata from the data sample.
     */
    void write(const Data& sample);

    /**
     * @brief Creates a new data sample that can be used to write in this
     *        output.
     *
     * The data constructor called in this operation depends on the data
     * representation kind of the TypeInfo associated with this output.
     * If the type representation is a dynamic type, then it will assume
     * the following constructor:
     * \code Data(const dds::core::xtypes::DynamicType&) \endcode
     *
     * and will use the type code object downcasted from the value
     * returned by TypeInfo::type_representation.
     *
     * Otherwise:
     * \code Data() \endcode
     *
     * @return A new data sample
     */
    Data create_data();

    /**
     * @brief Returns the underlying DDS DataWriter that is part of this
     * StreamWriter implementation, assuming this input holds a DDS StreamWriter.
     *
     * This operation will throw an exception if this output does not hold a
     * DDS StreamWriter.
     *
     * @note The access to the underlying DataWriter is allowed only as long as
     * this Output remains enabled. The object representing the DataWriter
     * must be invalidated before the output is disabled, otherwise the behavior
     * is undefined.
     *
     * @throw std::exception
     *
     * @return dds::pub::DataWriter<Data>
     */
    dds::pub::DataWriter<Data> dds_data_writer()
    {
        DDS_DataWriter *native_writer =
                RTI_RoutingServiceOutput_get_dds_writer(output_->native_);
        if (native_writer == NULL) {
            throw dds::core::InvalidArgumentError(
                    "invalid argument: input does not hold a DDS StreamWriter");
        }

        typedef dds::pub::DataWriter<Data> data_writer_type;
        return rti::core::detail::create_from_native_entity<data_writer_type>(
                native_writer);
    }

private:
    friend class rti::routing::processor::Route;

    Output *output_;
};

template <typename Data, typename Info>
struct create_data_from_output {

    static Data get(TypedOutput<Data, Info>& )
    {
        return Data();
    }
};


template <typename Info>
struct create_data_from_output<dds::core::xtypes::DynamicData, Info> {

    static dds::core::xtypes::DynamicData get(TypedOutput<dds::core::xtypes::DynamicData, Info>& output)
    {
        if (output->stream_info().type_info().type_representation_kind()
                != TypeRepresentationKind::DYNAMIC_TYPE) {
            throw dds::core::PreconditionNotMetError(
                    "inconsistent data representation kind");
        }
        dds::core::xtypes::DynamicType *type_code =
                static_cast<dds::core::xtypes::DynamicType *> (
                output->stream_info().type_info().type_representation());
        return dds::core::xtypes::DynamicData(*type_code);
    }
};


template <typename Data, typename Info>
TypedOutput<Data,Info>::TypedOutput(Output* output) : output_(output)
{
}

template <typename Data, typename Info>
const rti::routing::StreamInfo& TypedOutput<Data, Info>::stream_info() const
{
    return output_->stream_info_;
}

template <typename Data, typename Info>
const std::string& TypedOutput<Data, Info>::name() const
{
    return output_->name_;
}

template <typename Data, typename Info>
TypedOutput<Data, Info>* TypedOutput<Data,Info>::operator->()
{
    return this;
}

template <typename Data, typename Info>
void TypedOutput<Data, Info>::write(const Data& sample, const Info& info)
{
    if (!RTI_RoutingServiceOutput_write_sample(
            output_->native_,
            const_cast<void *> (reinterpret_cast<const void*> (&sample)),
            const_cast<void *> (reinterpret_cast<const void*> (&info)))) {
        throw dds::core::Error("error writing sample to native output");
    }
}

template <typename Data, typename Info>
void TypedOutput<Data,Info>::write(const Data& sample)
{
    if (!RTI_RoutingServiceOutput_write_sample(
            output_->native_,
            const_cast<void *> (reinterpret_cast<const void*> (&sample)),
            NULL)) {
        throw dds::core::Error("error writing sample to native output");
    }
}

template <typename Data, typename Info>
Data TypedOutput<Data,Info>::create_data()
{
    return create_data_from_output<Data, Info>::get(*this);
}


/**
 * @brief Convenient definition of a TypedOutput whose data representation
 * is DynamicData and info representation is dds::sub::SampleInfo.
 *
 * These data and info representations are expected be used by most
 * rti::routing::adapter::StreamWriter implementations.
 */
typedef TypedOutput<dds::core::xtypes::DynamicData> DynamicDataOutput;
typedef dds::pub::DataWriter<dds::core::xtypes::DynamicData> DynamicDataWriter;

} } }


#endif // RTI_ROUTING_PROCESSOR_OUTPUT_HPP_
