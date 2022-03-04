/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)connext_cpp_general_replier_details.h    generated by: makeheader    Fri Nov 15 12:23:49 2019
 *
 *		built from:	general_replier_details.ifcxx
 */

#ifndef connext_cpp_general_replier_details_h
#define connext_cpp_general_replier_details_h



#include <memory>
#include <limits>

#include "ndds/ndds_namespace_cpp.h"

#include "connext_cpp/connext_cpp_dll.h"
#include "connext_cpp/connext_cpp_exception.h"
#include "connext_cpp/connext_cpp_infrastructure.h"
#include "connext_cpp/connext_cpp_replier_untyped.h"
#include "connext_cpp/connext_cpp_replier_params.h"
#include "connext_cpp/connext_cpp_replier_listener.h"
#include "dds_c/dds_c_publication_impl.h"


namespace connext {

template <class TReq, class TRep>
class Replier;

namespace details {

// --- RequesterImpl: ---------------------------------------------------------

template <typename TReq, typename TRep>
class XMQCPPDllExport GeneralReplierImpl : public ReplierUntypedImpl {

private:

    // --- Listener: ----------------------------------------------------------

    class RequestListener : public DDS::DataReaderListener {
    public:   
        Replier<TReq, TRep> * _typed_replier;
        ReplierListener<TReq, TRep> * _replier_listener;
                                     
        RequestListener(Replier<TReq, TRep> * _typed_replier = 0,
                        ReplierListener<TReq, TRep> * = 0);

        virtual void on_data_available(DDS::DataReader* reader);
    };                                             

    void init(const ReplierParams<TReq, TRep> & params,
              const char * const);

public:

    // --- Other types: -------------------------------------------------------

    typedef TReq                                              Request;
    typedef TRep                                              Reply;
    typedef typename dds_type_traits<TReq>::DataReader        RequestDataReader;
    typedef typename dds_type_traits<TRep>::DataWriter        ReplyDataWriter;
    typedef typename details::type_support_adapter<TReq>      RequestTypeSupportAdapter;
    typedef typename details::type_support_adapter<TRep>      ReplyTypeSupportAdapter;
    typedef typename dds_type_traits<TReq>::LoanedSamplesType LoanedSamplesType;

    // --- ctors: -------------------------------------------------------------

    GeneralReplierImpl(DDS::DomainParticipant * participant,
                       const std::string& service_name);

    GeneralReplierImpl(const ReplierParams<TReq, TRep> & params);

    virtual ~GeneralReplierImpl();

    void swap(GeneralReplierImpl& other);

    bool wait_for_requests(const DDS_Duration_t & max_Wait);
    bool wait_for_requests(int min_count, const DDS_Duration_t & max_Wait);

    void send_reply_impl(
        char *, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        const char *, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        const std::string &, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        WriteSampleRef<char *> &, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        WriteSampleRef<const char *> &, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        WriteSampleRef<std::string> &, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        WriteSample<char *> &, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        WriteSample<const char *> &, 
        const SampleIdentity_t& related_request_id);

    void send_reply_impl(
        WriteSample<std::string> &, 
        const SampleIdentity_t& related_request_id);

    template <class URep>
    void send_reply_impl(
        WriteSample<URep> &, 
        const SampleIdentity_t& related_request_id);

    template <class URep>
    void send_reply_impl(
        WriteSampleRef<URep> &, 
        const SampleIdentity_t& related_request_id);

    template <class URep>
    void send_reply_impl(
        const URep &, 
        const SampleIdentity_t& related_request_id);

    bool get_request(connext::Sample<TReq> & request, bool take);

    bool get_request(connext::SampleRef<TReq> request, bool take);
    
    LoanedSamplesType get_requests(int count, bool take);

    bool receive_request(connext::Sample<TReq> & request,
                          const DDS_Duration_t & max_wait);

    bool receive_request(connext::SampleRef<TReq> request,
                         const DDS_Duration_t & max_wait);

    LoanedSamplesType receive_requests(const DDS_Duration_t & max_wait);
    LoanedSamplesType receive_requests(int min_request_count,
                                        int max_request_count,
                                        DDS_Duration_t max_wait);

    void set_replier(Replier<TReq, TRep> * typed_replier);
    // --- query methods: -----------------------------------------------------

    inline typename dds_type_traits<TReq>::DataReader * get_request_datareader() const;
    inline typename dds_type_traits<TRep>::DataWriter * get_reply_datawriter() const;

    // --- exception handling: ------------------------------------------------

    void log_and_rethrow(
        const connext::Rethrowable& ex,
        const char * METHOD_NAME);
private:
    RequestListener _request_listener;

    bool validate(int min_request_count, 
                  int max_request_count, 
                  const DDS_Duration_t & max_wait);
};

// --- RequesterImpl implementation: ------------------------------------------

template <typename TReq, typename TRep>
GeneralReplierImpl<TReq, TRep>::
GeneralReplierImpl(DDS::DomainParticipant * participant,
                   const std::string& service_name)
    : ReplierUntypedImpl()
{
    // This constructor may throw.
    // When an exception escapes out of this constructor the 
    // destructor of EntityUntypedImpl will be called automatically
    // and it will release the allocated resources in 
    // EntityUntypedImpl::initialize.

    init(ReplierParams<TReq, TRep> (participant)
           .service_name(service_name),
         "GeneralReplierImpl::GeneralReplierImpl");
}

template <typename TReq, typename TRep>
GeneralReplierImpl<TReq, TRep>::
GeneralReplierImpl(const ReplierParams<TReq, TRep> & params) 
    : ReplierUntypedImpl()
{
    init(params, "GeneralReplierImpl::GeneralReplierImpl");
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::init(const ReplierParams<TReq, TRep> & params,
                                          const char * const METHOD_NAME)
{
    _request_listener._replier_listener = params.replier_listener();

    // ReplierUntypedImpl::initialize is basic exception safe 
    // so no need to clean up.
    ReplierUntypedImpl::initialize(
        params,
        RequestTypeSupportAdapter::register_type,
        ReplyTypeSupportAdapter::register_type,
        sizeof(TReq),
        params.replier_listener() ? &_request_listener : NULL, 
        UsesStringDataReader<TReq>::value);

    // At this stage the request_listener does not have the replier pointer.
    // set_replier will be called to do that immediately after this constructor. 
    // The race condition caused by this is taken care of in the 
    // on_data_available callback.
}

template <typename TReq, typename TRep>
GeneralReplierImpl<TReq, TRep>::~GeneralReplierImpl() 
{
    // Prevents callbacks after this object (and the ReplierListener)
    // have been destroyed
    if(get_datareader() != NULL) {
        get_datareader()->set_listener(NULL, DDS_STATUS_MASK_NONE);
    }
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::swap(GeneralReplierImpl& other)
{
    // This code needs to be atomic because swapping 
    // ReplierUntypedImpl and _request_listeners swaps internal
    // pointers, which could be an inconsistent state in the meanwhile.
    // Document this limitation. The alternative of using an EA
    // seems too expensive. Anyways, this method isn't public.
    ReplierUntypedImpl::swap(*this);
    std::swap(_request_listener, other._request_listener);
}

template <typename TReq, typename TRep>
inline typename dds_type_traits<TRep>::DataWriter * 
GeneralReplierImpl<TReq, TRep>::get_reply_datawriter() const
{
    return static_cast<typename dds_type_traits<TRep>::DataWriter *>(this->_writer);
}

template <typename TReq, typename TRep>
inline typename dds_type_traits<TReq>::DataReader * 
GeneralReplierImpl<TReq, TRep>::get_request_datareader() const
{
    return static_cast<typename dds_type_traits<TReq>::DataReader *>(this->_reader);
}

template <typename TReq, typename TRep>
typename GeneralReplierImpl<TReq, TRep>::LoanedSamplesType 
GeneralReplierImpl<TReq, TRep>::receive_requests(
    const DDS_Duration_t & max_wait)
{
    return receive_requests(1, DDS_LENGTH_UNLIMITED, max_wait);
}

template <typename TReq, typename TRep>
bool GeneralReplierImpl<TReq, TRep>::receive_request(
    connext::Sample<TReq> & request, 
    const DDS_Duration_t & max_wait)
{
    init_sample_info(request.info());
    LoanedSamplesType ls = 
        receive_requests(1 /* min */, 1 /* max */, max_wait);

    if (ls.length() == 0) {
        return false;
    }

    copy_sample(request, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep>
bool GeneralReplierImpl<TReq, TRep>::receive_request(
    connext::SampleRef<TReq> request,
    const DDS_Duration_t & max_wait)
{
    init_sample_info(request.info());
    LoanedSamplesType ls = 
        receive_requests(1 /* min */, 1 /* max */, max_wait);

    if (ls.length() == 0) {
        return false;
    }

    copy_sample_ref(request, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep>
typename GeneralReplierImpl<TReq, TRep>::LoanedSamplesType 
GeneralReplierImpl<TReq, TRep>::receive_requests(
        int min_request_count,
        int max_request_count,
        DDS_Duration_t max_wait)
{
    SampleInfoSeq info_seq;
    void ** dataPtrArray = NULL;
    int dataCount = 0;

    EntityUntypedImpl::receive_sample_loaned(
            &dataPtrArray,
            &dataCount,
            info_seq,
            max_request_count,
            max_wait,
            min_request_count);

    if (dataCount == 0) {
        // Return empty collection
        return LoanedSamplesType();
    }

    return create_loaned_samples<TReq>(
        dataPtrArray, dataCount, info_seq, get_request_datareader());
}

template <typename TReq, typename TRep>
typename GeneralReplierImpl<TReq, TRep>::LoanedSamplesType 
GeneralReplierImpl<TReq, TRep>::get_requests(int count, bool take)
{
    SampleInfoSeq info_seq;
    void ** dataPtrArray = NULL;
    int dataCount = 0;

    EntityUntypedImpl::get_sample_loaned(
            &dataPtrArray,
            &dataCount,
            info_seq,
            count,
            take);

    if (dataCount == 0) {
        // Return empty collection
        return LoanedSamplesType();
    }

    return create_loaned_samples<TReq>(
        dataPtrArray, dataCount, info_seq, get_request_datareader());
}

template <typename TReq, typename TRep>
bool GeneralReplierImpl<TReq, TRep>::get_request(
        connext::Sample<TReq> & request,
        bool take)
{
    init_sample_info(request.info());
    LoanedSamplesType ls = get_requests(1, take);

    if (ls.data_seq().length() == 0) {
        return false;
    }

    copy_sample(request, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template <typename TReq, typename TRep>
bool GeneralReplierImpl<TReq, TRep>::get_request(
        connext::SampleRef<TReq> request, bool take)
{
    init_sample_info(request.info());
    LoanedSamplesType ls = get_requests(1, take);

    if (ls.data_seq().length() == 0) {
        return false;
    }

    copy_sample_ref(request, ls.data_seq()[0], ls.info_seq()[0]);

    return true;
}

template<typename TReq, typename TRep>
bool GeneralReplierImpl<TReq, TRep>::wait_for_requests(
    const DDS_Duration_t & max_wait)
{
    return ReplierUntypedImpl::wait_for_any_sample(max_wait, 1);
}

template<typename TReq, typename TRep>
bool GeneralReplierImpl<TReq, TRep>::wait_for_requests(
    int min_count, const DDS_Duration_t & max_wait)
{
    return ReplierUntypedImpl::wait_for_any_sample(max_wait, min_count);
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(char * str, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    WriteParams_t writeinfo;
    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, writeinfo);
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(const char * str, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    WriteParams_t writeinfo;
    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, writeinfo);
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(const std::string & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    WriteParams_t writeinfo;
    const char * str = rep.c_str();
    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, writeinfo);
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSampleRef<char *> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    const char * str = rep.data();

    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, rep.info());
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSampleRef<const char *> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    const char * str = rep.data();

    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, rep.info());
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSampleRef<std::string> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    const char * str = rep.data().c_str();

    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, rep.info());
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSample<char *> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    const char * str = rep.data();

    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, rep.info());
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSample<const char *> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    const char * str = rep.data();

    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, rep.info());
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSample<std::string> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Reply_Type_Must_Be_A_String_Type<UsesStringDataWriter<TRep>::value>();

    const char * str = rep.data().c_str();

    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&str),
        related_request_id, rep.info());
}

template <typename TReq, typename TRep>
template <class URep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSample<URep> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Write_Sample_Types_Must_Match_Assertion_Failure<is_same<TRep, URep>::value>();

    ReplierUntypedImpl::send_sample(
        reinterpret_cast<const void *> (&rep.data()), related_request_id,
        rep.info());
}

template <typename TReq, typename TRep>
template <class URep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(WriteSampleRef<URep> & rep, 
                                                     const SampleIdentity_t& related_request_id)
{
    Write_Sample_Types_Must_Match_Assertion_Failure<is_same<TRep, URep>::value>();

    ReplierUntypedImpl::send_sample(
        reinterpret_cast<const void *> (&rep.data()), related_request_id,
        rep.info());
}

template <typename TReq, typename TRep>
template <class URep>
void GeneralReplierImpl<TReq, TRep>::send_reply_impl(const URep & data, 
                                                     const SampleIdentity_t& related_request_id)
{
    // Compile-type assertion
    Write_Sample_Types_Must_Match_Assertion_Failure<is_same<TRep, URep>::value>();

    WriteParams_t writeinfo;
    ReplierUntypedImpl::send_sample(reinterpret_cast<const void *> (&data),
        related_request_id, writeinfo);
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::log_and_rethrow(
    const connext::Rethrowable& ex,
    const char * METHOD_NAME)
{
    EntityUntypedImpl::log_and_rethrow(ex, "Replier", METHOD_NAME);
}

template <typename TReq, typename TRep>
void GeneralReplierImpl<TReq, TRep>::set_replier(Replier<TReq, TRep> * typed_replier)
{
    // Ideally this write should be atomic. On most platforms it is.
    _request_listener._typed_replier = typed_replier;
}

// --- RequestListener implementation: ----------------------------------------


template<class TReq, class TRep>
GeneralReplierImpl<TReq, TRep>::RequestListener::RequestListener(
    Replier<TReq, TRep> * typed_replier,
    ReplierListener<TReq, TRep> * replier_listener)
    : _typed_replier(typed_replier),
      _replier_listener(replier_listener)
{
}

template<class TReq, class TRep>
void GeneralReplierImpl<TReq, TRep>::RequestListener::on_data_available(
    DDSDataReader* reader)
{
    // This condition is necessary to take care of the race condition.
    // TODO(review): Catch and log and supress.
    if(_replier_listener && _typed_replier) {
        _replier_listener->on_request_available(*_typed_replier); 
    }
}

} // namespace details
} // namespace connext


#endif /* connext_cpp_general_replier_details_h */
