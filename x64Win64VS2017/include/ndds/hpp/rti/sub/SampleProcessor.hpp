/* $Id$

(c) Copyright, Real-Time Innovations, 2014-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


============================================================================= */

#ifndef RTI_DDS_SUB_SAMPLE_PROCESSOR_HPP_
#define RTI_DDS_SUB_SAMPLE_PROCESSOR_HPP_

#include "dds_c/dds_c_sample_processor_impl.h"
// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include <dds/core/corefwd.hpp>
#include <dds/sub/subfwd.hpp>
#include <dds/sub/AnyDataReader.hpp>
#include <rti/core/cond/AsyncWaitSet.hpp>

/**
 * @defgroup DDSSampleProcessorModule SampleProcessor
 * @ingroup DDSSubscriptionModule
 *
 * \dref_SampleProcessorModuleDocs
 */


namespace rti { namespace sub {

class SampleHandler {
public:
    virtual ~SampleHandler()
    {
    }

    virtual void on_sample_available_native(
            const void *sample_data,
            const struct DDS_SampleInfo *sample_info) = 0;
};

template <typename T, typename Functor>
class SampleHandlerFunctorHolder : SampleHandler {

public:
  SampleHandlerFunctorHolder(const Functor& func) : func_(func){ }

public:

    void on_sample_available_native(
            const void *sample_data,
            const struct DDS_SampleInfo *sample_info) RTI_OVERRIDE
    {
        rti::sub::LoanedSample<T> sample(
                reinterpret_cast<const T*> (sample_data),
                sample_info);
        func_(sample);
    }

private:
   Functor func_;
};

class SampleHandlerForwarder {

public:

    template <typename T, typename Functor>

    static DDS_SampleHandler create_native(
            const Functor& func)
    {
        DDS_SampleHandler native_handler;

        SampleHandlerFunctorHolder<T, Functor> *holder =
                new SampleHandlerFunctorHolder<T, Functor>(func);
        native_handler.on_new_sample =
                SampleHandlerForwarder::forward_on_new_sample_native;
        native_handler.handler_data = static_cast<void*>(holder);

        return native_handler;
    }

    static
    void delete_native(DDS_SampleHandler *native)
    {
        if (native->handler_data != NULL) {
            SampleHandler *functor_holder =
                    static_cast<SampleHandler*>(native->handler_data);
            delete functor_holder;
        }
    }

private:

    static void forward_on_new_sample_native(
            void *handler_data,
            const void *sample_data,
            const struct DDS_SampleInfo *sample_info)
    {
        SampleHandler *forwarder =
                static_cast<SampleHandler*>(handler_data);
        forwarder->on_sample_available_native(
                sample_data,
                sample_info);
    }

};

class OMG_DDS_API SampleProcessorImpl {
public:
    typedef std::vector<dds::sub::AnyDataReader> AnyDataReaderSeq;
    SampleProcessorImpl();

    SampleProcessorImpl(
            const rti::core::cond::AsyncWaitSetProperty& property);

    SampleProcessorImpl(rti::core::cond::AsyncWaitSet aws);

    ~SampleProcessorImpl();

    template <typename T, typename Functor>
    void attach_reader(
            dds::sub::DataReader<T> reader,
            const Functor& data_available_functor)
    {
        DDS_SampleHandler native_handler =
                SampleHandlerForwarder::create_native<T, Functor>(
                        data_available_functor);
        attach_reader(reader->native_reader(), &native_handler);
    }

    template <typename T>
    void detach_reader(
            dds::sub::DataReader<T> reader)
    {
        detach_reader(reader->native_reader());
    }
    AnyDataReaderSeq readers() const;
    AnyDataReaderSeq& readers(AnyDataReaderSeq&) const;

private:
    void attach_reader(
            DDS_DataReader *native_reader,
            DDS_SampleHandler *native_handler);

    void detach_reader(
            DDS_DataReader *native_reader);

private:
    rti::core::cond::AsyncWaitSet aws_;
    DDS_SampleProcessor *native_;
};


/**
 * @ingroup DDSSampleProcessorModule
 * @headerfile rti/sub/SampleProcessor.hpp
 *
 * @brief @extension @st_ref_type Utility to read and process the data samples 
 * that one or more DataReaders receive using a sample handler.
 *
 * The following example shows how to create an full application that subscribes
 * to a topic and prints each sample it receives:
 *
 * @code
 * int subscriber_main(int domain_id, int sample_count)
 * {
 *      dds::domain::DomainParticipant participant(domain_id);
 *      dds::topic::Topic<Foo> topic(participant, "Example Foo");
 *      dds::sub::DataReader<Foo> reader(dds::sub::Subscriber(participant), topic);
 *
 *      int count = 0;
 *      rti::sub::SampleProcessor sample_processor;
 *      sample_processor.attach_reader(reader, [](const rti::sub::LoanedSample<Foo>& sample) {
 *          if (sample.info().valid()) {
 *              std::cout << "Received " << sample.data() << std::endl;
 *          }
 *      });
 *
 *      while(1) {
 *          // wait forever
 *      }
 *
 *      return 1;
 * }
 * @endcode
 *
 * Note that the expected sample handler is a functor with signature
 * std::function<void(const rti::sub::LoanedSample<T>&)>, where \p T is the 
 * type associated with the \idref_DataReader.
 *
 * @details @dref_details_SampleProcessor
 */
class OMG_DDS_API SampleProcessor
    : public dds::core::Reference<SampleProcessorImpl> {

private:
    typedef dds::core::Reference<SampleProcessorImpl> Base;
    typedef SampleProcessorImpl::AnyDataReaderSeq AnyDataReaderSeq;

public:

    /**
     * \dref_SampleProcessor_new
     */
    SampleProcessor(const rti::core::cond::AsyncWaitSetProperty& aws_property)
        : Base(new SampleProcessorImpl(aws_property))
    {
    }

    /**
     * @brief Creates a \idref_SampleProcessor with the default
     * rti::core::cond::AsyncWaitSetProperty.
     *
     * @see \idref_ASYNC_WAITSET_PROPERTY_DEFAULT
     */
    SampleProcessor() : Base(new SampleProcessorImpl())
    {
    }

    /**
     * \dref_SampleProcessor_new_with_aws
     */
    SampleProcessor(rti::core::cond::AsyncWaitSet aws)
        : Base(new SampleProcessorImpl(aws))
    {
    }

    SampleProcessor(const dds::core::null_type&)
      : Base(static_cast<SampleProcessorImpl*>(NULL))
    {
    }

    /**
     * \dref_SampleProcessor_attach_reader
     */
    template <typename T, typename FUNCTOR>
    SampleProcessor& attach_reader(
            dds::sub::DataReader<T> reader,
            const FUNCTOR& handler)
    {
        this->delegate()->attach_reader(reader, handler);
        return *this;
    }

     /**
     * \dref_SampleProcessor_detach_reader
     */
    template <typename T>
    SampleProcessor& detach_reader(
            dds::sub::DataReader<T> reader)
    {
        this->delegate()->detach_reader(reader);
        return *this;
    }


    /**
     *  @brief Returns the list of attached \idref_DataReader (s).
     */
    std::vector<dds::sub::AnyDataReader> readers() const
    {
        return this->delegate()->readers();
    }
};

} } // namespace rti::sub

#endif // RTI_DDS_SUB_SAMPLE_PROCESSOR_HPP_
