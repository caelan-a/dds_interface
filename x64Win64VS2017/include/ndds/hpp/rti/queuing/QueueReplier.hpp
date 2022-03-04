/*
(c) Copyright, Real-Time Innovations, 2016-2017.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission. Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.

 */

#ifndef RTI_QUEUING_REPLIER_HPP_
#define RTI_QUEUING_REPLIER_HPP_

#include <dds/sub/LoanedSamples.hpp>
#include <dds/core/status/Status.hpp>
#include <rti/queuing/QueueReplierListener.hpp>
#include <rti/queuing/detail/QueueReplierImpl.hpp>

namespace rti { namespace queuing {   
    
/**
 * \dref_QueueReplier
 *
 * @headerfile rti/queuing/QueueReplier.hpp
 */
template <typename TReq, typename TRep>
class QueueReplier
    : public dds::core::Reference< detail::QueueReplierImpl<TReq, TRep> > {
public:

    typedef detail::QueueReplierImpl<TReq, TRep> Delegate;
    typedef dds::core::Reference<Delegate> Base;
    typedef QueueReplierListener<TReq, TRep> Listener;
    typedef typename dds::core::smart_ptr_traits<Delegate >::ref_type ref_type;
    typedef typename dds::core::smart_ptr_traits<Delegate >::weak_ref_type weak_ref_type;


    OMG_DDS_REF_TYPE(QueueReplier, dds::core::Reference, Delegate);

    /**
     * @brief Creates a queue replier
     *
     * @deprecated When using a listener, prefer the constructor that receives
     * a `shared_ptr<Listener>` instead of a regular `Listener*` pointer.
     */
    explicit QueueReplier(
        const QueueReplierParams& params,    
        bool is_enabled = true,    
        Listener* replier_listener = NULL,    
        const rti::core::Guid& replier_guid = rti::core::Guid::unknown())
            : Base(new Delegate(params, replier_guid))
    {
        /* The listeners cannot be passed to the base class constructor because 
         * the listeners need the base class to be constructed. We use the
         * following initialize method to set the listeners and finish the
         * base class construction. */
        this->delegate()->initialize(
                new ReplierInternalProducerListener(this->delegate()), 
                new ReplierInternalConsumerListener(this->delegate()),
                replier_listener,
                is_enabled);

        this->delegate()->remember_reference(this->delegate());
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    /**
     * \dref_QueueReplier_new_w_params
     */
    explicit QueueReplier(
            const QueueReplierParams& params,
            bool is_enabled,
            std::shared_ptr<Listener> replier_listener,
            const rti::core::Guid& replier_guid = rti::core::Guid::unknown())
            : Base(new Delegate(params, replier_guid))
    {
        /* The listeners cannot be passed to the base class constructor because
         * the listeners need the base class to be constructed. We use the
         * following initialize method to set the listeners and finish the
         * base class construction. */
        this->delegate()->initialize(
                new ReplierInternalProducerListener(this->delegate()),
                new ReplierInternalConsumerListener(this->delegate()),
                replier_listener,
                is_enabled);

        this->delegate()->remember_reference(this->delegate());
    }
#endif

    QueueReplier(ref_type delegate_ref)
        : Base(delegate_ref)
    {
        this->delegate()->remember_reference(this->delegate());
    }

    /**
     * @brief Sets the listener associated with this queue requester.
     *
     * @deprecated The use of `set_listener()` is recommended. Unlike this
     * function, `set_listener` receives a `shared_ptr` which simplifies the
     * management of listener's lifecycle.
     *
     * @param the_listener The QueueReplierListener to set
     * @param event_mask The dds::core::status::StatusMask associated with the
     * listener
     */
    void listener(
        Listener* the_listener,
        const dds::core::status::StatusMask& event_mask = dds::core::status::StatusMask::none())
    {
        this->delegate()->listener_impl(the_listener, event_mask);
    }

    /**
     * @brief Returns the listener currently associated with this requester.
     *
     * @deprecated Prefer `get_listener()` instead of this function.
     *
     * If there is no listener it returns NULL.
     */
    Listener* listener() const
    {
        return this->delegate()->listener_impl();
    }

#ifndef RTI_NO_CXX11_SMART_PTR
    /**
     * @brief Gets the listener
     */
    std::shared_ptr<Listener> get_listener() const
    {
        return this->delegate()->get_listener_impl();
    }

    /**
     * @brief Sets a listener to be notified of status updates
     *
     * @warning It's recommended that the listener implementation doesn't hold
     * a permanent reference to this object. If it does, the application needs
     * to manually reset the listener or manually close this object to ensure
     * that there is no cycle that prevents the destruction of these two
     * objects.
     *
     * @param the_listener A shared pointer to the listener to receive
     * updates or `nullptr` to reset the current listener and stop receiving
     * updates.
     */
    void set_listener(std::shared_ptr<Listener> the_listener)
    {
        this->delegate()->set_listener_impl(the_listener);
    }
#endif

    /**
     * \dref_QueueReplier_enable
     */ 
    void enable() 
    {
        this->delegate()->enable();
    }
    
    dds::sub::LoanedSamples<TReq> receive_request(
        const dds::core::Duration& max_wait)
    {
        return this->delegate()->receive_request(max_wait);
    } 
    
    /**
     * \dref_QueueReplier_send_reply
     */
    void send_reply(
        const TRep& reply,
        const dds::sub::SampleInfo& related_request_info) 
    {
        this->delegate()->send_reply(reply, related_request_info);
    }
    
   /**
    * \dref_QueueReplier_send_reply_w_write_params
    */
    void send_reply(
        const TRep& reply,     
        rti::pub::WriteParams& write_params)
    {
        this->delegate()->send_reply(reply, write_params);
    }
    
    /**
     * \dref_QueueReplier_acknowledge_request
     */
    void acknowledge_request(
        const dds::sub::SampleInfo& sample_info, 
        bool is_positive_acknowledgment = true) 
    {
        this->delegate()->acknowledge_request(sample_info, is_positive_acknowledgment);
    }
    
    /**
     * \dref_QueueReplier_acknowledge_all
     */
    void acknowledge_all(bool is_positive_acknowledgment = true) 
    { 
        this->delegate()->acknowledge_all(is_positive_acknowledgment);
    }
    
    /**
     * \dref_QueueReplier_wait_for_acknowledgements
     */
    bool wait_for_acknowledgments(const dds::core::Duration& max_wait)
    {
        return this->delegate()->wait_for_acknowledgments(max_wait);
    }
   
    /**
     * \dref_QueueReplier_wait_for_sample_acknowledgement
     */
    bool wait_for_acknowledgments(
        const rti::core::SampleIdentity& identity,
        const dds::core::Duration& max_wait) 
    {
        return this->delegate()->wait_for_acknowledgments(identity, max_wait);
    }
    
    /**
     * \dref_QueueReplier_get_consumer
     */
    rti::queuing::QueueConsumer<TReq> consumer() const
    {
        return this->delegate()->consumer();
    }
    
    /**
     * \dref_QueueReplier_get_producer
     */
    rti::queuing::QueueProducer<TRep> producer() const
    {
        return this->delegate()->producer();
    }
    
    /**
     * \dref_QueueReplier_send_availability
     */
    void send_availability(ConsumerAvailabilityParams parameters) 
    {
        this->delegate()->send_availability(parameters);
    }
    
    /**
     * \dref_QueueReplier_has_matching_request_shared_reader_queue
     */
    bool has_matching_request_reader_queue()
    {
        return this->delegate()->has_matching_request_reader_queue();
    }
    
    /**
     * \dref_QueueReplier_has_matching_reply_shared_reader_queue
     */
    bool has_matching_reply_reader_queue()
    {
        return this->delegate()->has_matching_reply_reader_queue();
    }
   
    /**
     * \dref_QueueReplier_wait_for_requests_simple
     */
    bool wait_for_requests(const dds::core::Duration& max_wait)
    {
        return this->delegate()->wait_for_requests(max_wait);
    }
    
    /**
     * \dref_QueueReplier_wait_for_requests
     */
    bool wait_for_requests(int min_count, const dds::core::Duration& max_wait)
    {
        return this->delegate()->wait_for_requests(min_count, max_wait);
    }
    
    /**
     * \dref_QueueReplier_receive_requests_simple
     */
    dds::sub::LoanedSamples<TReq> receive_requests(
            const dds::core::Duration& max_wait) 
    {
        return this->delegate()->receive_requests(max_wait);
    }
    
    /**
     * \dref_QueueReplier_receive_requests
     */
    dds::sub::LoanedSamples<TReq> receive_requests(
            int min_count, 
            int max_count,
            const dds::core::Duration& max_wait) 
    {
        return this->delegate()->receive_requests(min_count, max_count, max_wait);
    }
    
    /**
     * \dref_QueueReplier_get_writeparams_for_related_request
     */
    rti::pub::WriteParams get_write_params_for_related_request(
        rti::pub::WriteParams& write_params, 
        const dds::sub::SampleInfo& related_request_info) 
    {
        return this->delegate()->get_write_params_for_related_request(
                write_params, 
                related_request_info);
    }
    
    /**
     * \dref_QueueReplier_take_requests_simple
     */
    dds::sub::LoanedSamples<TReq> take_requests()
    {
        return this->delegate()->take_requests();
    }
    
    /**
     * \dref_QueueReplier_take_requests
     */
    dds::sub::LoanedSamples<TReq> take_requests(int max_count)
    {
        return this->delegate()->take_requests(max_count);
    }
    
    /**
     * \dref_QueueReplier_read_requests_simple
     */
    dds::sub::LoanedSamples<TReq> read_requests()
    {
        return this->delegate()->read_requests();
    }
    
    /**
      * \dref_QueueReplier_read_requests
      */
    dds::sub::LoanedSamples<TReq> read_requests(int max_count)
    {
        return this->delegate()->read_requests(max_count);
    } 
    
    /**
     * \dref_QueueReplier_get_reply_datawriter
     */
    dds::pub::DataWriter<TRep> writer() const
    {
        return this->delegate()->writer();
    }
    
    /**
     * \dref_QueueReplier_get_request_datareader
     */
    dds::sub::DataReader<TReq> reader() const
    {
        return this->delegate()->reader();
    }
    
    /**
     * \dref_QueueReplier_get_guid
     */
    rti::core::Guid guid() {
        return this->delegate()->guid();
    }
    
    void close() 
    {
        this->delegate()->close();
    }
    
private:
    /* We need to pass a QueueReplier<T> object to the user so we are forced to
     * define the internal listener here instead of in the implementation */
    class ReplierInternalProducerListener : public rti::queuing::NoOpQueueProducerListener<TRep> {
        public:

        virtual void on_sample_acknowledged(
            QueueProducer<TRep>&,
            const rti::pub::AcknowledgmentInfo& info)
        { 
            // IMPORTANT: This listener simply forwards the callback to a user
            // listener. It doesn't do any bookkeeping. If that changes, the
            // solution to QUEUEING-688 will need to be reevaluated.            
            ref_type delegate_ref = requester_weak_ref_.lock();
            if (delegate_ref) {
                QueueReplier<TReq, TRep> requester_(delegate_ref);
                Listener* listener = requester_.delegate()->listener_impl();
                if (listener != NULL) {
                    listener->on_reply_acknowledged(requester_, info);
                }
            }  
        }
        
        virtual void on_shared_reader_queue_matched(
            QueueProducer<TRep>&,
            const dds::core::status::PublicationMatchedStatus& status) 
        {
            // IMPORTANT: This listener simply forwards the callback to a user
            // listener. It doesn't do any bookkeeping. If that changes, the
            // solution to QUEUEING-688 will need to be reevaluated.            
            ref_type delegate_ref = requester_weak_ref_.lock();
            if (delegate_ref) {
                QueueReplier<TReq, TRep> requester_(delegate_ref);
                Listener* listener = requester_.delegate()->listener_impl();
                if (listener != NULL) {
                    listener->on_reply_shared_reader_queue_matched(requester_, status);
                }
            }  
        }
        
        ReplierInternalProducerListener(ref_type requester) 
            : requester_weak_ref_(requester)
        {
            
        }

    private:
        weak_ref_type requester_weak_ref_;
    };
    
    
    class ReplierInternalConsumerListener : public rti::queuing::NoOpQueueConsumerListener<TReq> {
        public:

        virtual void on_sample_available(QueueConsumer<TReq>&)
        { 
            // IMPORTANT: This listener simply forwards the callback to a user
            // listener. It doesn't do any bookkeeping. If that changes, the
            // solution to QUEUEING-688 will need to be reevaluated.            
            ref_type delegate_ref = requester_weak_ref_.lock();
            if (delegate_ref) {
                QueueReplier<TReq, TRep> requester_(delegate_ref);
                Listener* listener = requester_.delegate()->listener_impl();
                if (listener != NULL) {
                    listener->on_request_available(requester_);
                }
            }  
        }
        
        virtual void on_shared_reader_queue_matched(
            QueueConsumer<TReq>&,
            const dds::core::status::SubscriptionMatchedStatus& status) 
        {
            // IMPORTANT: This listener simply forwards the callback to a user
            // listener. It doesn't do any bookkeeping. If that changes, the
            // solution to QUEUEING-688 will need to be reevaluated.            
            ref_type delegate_ref = requester_weak_ref_.lock();
            if (delegate_ref) {
                QueueReplier<TReq, TRep> requester_(delegate_ref);
                Listener* listener = requester_.delegate()->listener_impl();
                if (listener != NULL) {
                    listener->on_request_shared_reader_queue_matched(requester_, status);
                }
            }  
        }
        
        
        ReplierInternalConsumerListener(ref_type requester) 
            : requester_weak_ref_(requester)
        {
            
        }
        
    private:
        weak_ref_type requester_weak_ref_;
    };
    
    /* This class should hold no state. */
};


} } // namespace rti::queuing

#endif // RTI_QUEUING_REPLIER_HPP_
