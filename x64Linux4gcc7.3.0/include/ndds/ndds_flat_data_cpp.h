/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)ndds_flat_data_cpp.h    generated by: makeheader    Fri Nov 15 12:23:00 2019
 *
 *		built from:	ndds_flat_data_cpp.ifcxx
 */

#ifndef ndds_flat_data_cpp_h
#define ndds_flat_data_cpp_h



// The traditional C++ API disables exceptions in rtiflat.hpp
#define RTI_FLAT_DATA_NO_EXCEPTIONS
// Serialization functions use, for example, int instead of int32_t
#define RTI_AVOID_FIXED_WIDTH_INTEGERS

#include "rti/flat/rtiflat.hpp" // the actual Flat Data support

#undef RTI_AVOID_FIXED_WIDTH_INTEGERS
#undef RTI_FLAT_DATA_NO_EXCEPTIONS

#include "dds_c/dds_c_publication_impl.h" // for flat-data write() operations

namespace rti { namespace flat {

/**
 * @ingroup RTIFlatBuildersModule
 * 
 * @brief Begins building a new sample
 * 
 * @tparam TopicType A FlatData mutable type that corresponds to 
 * the type of the DataWriter argument.
 * 
 * @param writer The writer that will be used to write this sample.
 * @return The Builder to build the sample. For example if TopicType is 
 * \ref MyFlatMutable, this function returns a MyFlatMutableBuilder. In case
 * of error, this function returns an 
 * \ref rti::flat::AbstractBuilder::is_valid "invalid Builder"
 * 
 * Once you have completed the sample, call 
 * \ref MyFlatMutableBuilder::finish_sample() "finish_sample()" to 
 * obtain a \ref MyFlatMutable sample that can be written with \p writer.
 * 
 * If the building of this sample needs to be aborted before calling 
 * finish_sample(), use rti::flat::discard_builder(). If, after obtaining a
 * sample with finish_sample(), this sample is not written, then discard it with
 * \idref_FooDataWriter_discard_loan().
 * 
 * @see \idref_FooDataWriter_get_loan, the function that build_data() uses to obtain 
 * the memory required to build the sample.
 * @see \ref PublishingFlatData
 */
template <typename TopicType>
typename rti::flat::flat_type_traits<TopicType>::builder build_data(
        typename TopicType::DataWriter *writer)
{
    typedef typename rti::flat::flat_type_traits<TopicType>::builder Builder;

    TopicType *buffer;
    unsigned int max_size = 
            PRESTypePluginDefaultEndpointData_getMaxSizeSerializedSample(
                    DDS_DataWriter_get_endpoint_dataI(writer->get_c_datawriterI()));

    DDS_ReturnCode_t retcode = writer->get_loan(buffer);
    if (retcode != DDS_RETCODE_OK) {
        return Builder();
    }

    return Builder(
            reinterpret_cast<unsigned char *>(buffer),
            max_size,
            DDS_DataWriter_is_initialize_writer_loaned_sample(
                    writer->get_c_datawriterI()) == DDS_BOOLEAN_TRUE);
}

/**
 * @ingroup RTIFlatBuildersModule
 * 
 * @brief Discards a sample builder
 * 
 * @tparam TopicType An IDL-defined FlatData type that corresponds to the
 * type of the DataWriter argument.
 * 
 * This function invalidates and discards a builder before it is finished() and
 * before the sample it would have created was written.
 * 
 * @param writer The writer that was used to create the builder
 * @param builder The builder, created with \p rti::flat::build_data(writer);
 */
template <typename BuilderType>
void discard_builder(
        typename rti::flat::flat_type_traits<BuilderType>::flat_type::DataWriter *writer,
        BuilderType& builder)
{
    typedef typename rti::flat::flat_type_traits<BuilderType>::flat_type TopicType;
    unsigned char *buffer = builder.discard_sample_impl();
    if (buffer != NULL) {
        writer->discard_loan(*reinterpret_cast<TopicType *>(buffer));
    }
}

} }


#endif /* ndds_flat_data_cpp_h */
