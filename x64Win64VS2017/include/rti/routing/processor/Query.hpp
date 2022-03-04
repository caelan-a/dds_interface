/* $Id$

(c) Copyright, Real-Time Innovations, 2015-2016.
All rights reserved.

No duplications, whole or partial, manual or electronic, may be made
without express written permission.  Any such copies, or
revisions thereof, must display this notice unaltered.
This code contains trade secrets of Real-Time Innovations, Inc.


============================================================================= */

#ifndef RTI_ROUTING_PROCESSOR_QUERY_HPP_
#define RTI_ROUTING_PROCESSOR_QUERY_HPP_

#include "routingservice/routingservice_processor.h"

#include <dds/core/Reference.hpp>
#include <rti/core/detail/SelfReference.hpp>


namespace rti { namespace routing { namespace processor {

class Input;

class QueryHolder : public rti::core::detail::RetainableType<QueryHolder>{
public:

    QueryHolder() : input_(NULL), query_data_(NULL)
    {
    }

    QueryHolder(RTI_RoutingServiceInput *input, const dds::topic::Filter& the_filter)
            : input_(input),
              query_data_(NULL)
    {
        filter(the_filter);
    }

    ~QueryHolder()
    {
        if (query_data_ != NULL) {
            /*
             * Ignore the error. We can't throw in the destructor and this
             * layer does not log anything
             */
            (void) RTI_RoutingServiceInput_delete_content_query(
                    input_,
                    query_data_);
        }
    }

    void filter(const dds::topic::Filter& filter)
    {
        RTI_RoutingServiceSelectorContent content =
                RTI_RoutingServiceSelectorContent_INITIALIZER;
        content.expression = (char *) filter.expression().c_str();
        rti::core::native_conversions::to_native(
                content.expression_parameters,
                filter->parameters());
        query_data_ = RTI_RoutingServiceInput_create_content_query(
                input_,
                query_data_,
                &content);
        DDS_StringSeq_finalize(&content.expression_parameters);
        if (query_data_ == NULL) {
            throw dds::core::Error("error creating content query from native input");
        }
    }

    RTI_RoutingServiceInput *input_;
    void* query_data_;
};

/** @ingroup RTI_RoutingServiceProcessorModule
 *
 * @class rti::routing::processor::Query
 *
 * @brief Encapsulates a content query to select data from a
 * rti::routing::adapter::StreamReader.
 *
 * Note that syntax for the query filter is StreamReader implementation
 * dependent. For the DDS Adapter case, the syntax corresponds to that
 * of the SQL filter.
 *
 * A Query object holds a custom query obtained by calling
 * rti::routing::adapter::StreamReader::create_content_query. Likewise,
 * the deletion of a Query object will call
 * rti::routing::adapter::StreamReader::delete_content_query.
 */
class Query : public dds::core::Reference<rti::routing::processor::QueryHolder> {
public:
    typedef dds::core::Reference<QueryHolder> Base;
    OMG_DDS_REF_TYPE_NOTYPENAME(
            Query,
            dds::core::Reference,
            rti::routing::processor::QueryHolder);

    explicit Query(Base::DELEGATE_REF_T reference) : Base(reference)
    {
        if (this->delegate()) {
            this->delegate()->remember_reference(this->delegate());
        }
    }

    /**
     * @brief Creates a Query described by a filter on an input.
     *
     * @param[in] input The native Input to query the data from.
     * @param[in] filter Description of the content query based on an expression
     *            and parameters.
     *
     * @see dds::topic::Filter
     */
    Query(RTI_RoutingServiceInput *input, const dds::topic::Filter& filter)
            : Base(new QueryHolder(input, filter))
    {
        this->delegate()->remember_reference(this->delegate());
    }


    /**
     * @brief Updates the current Query content filter.
     *
     * This operation will call
     * rti::routing::adapter::StreamReader::create_content_query providing
     * the current query content data this Query holds.
     */
    void filter(const dds::topic::Filter& filter)
    {
        this->delegate()->filter(filter);
    }
};

} } }

#endif // RTI_ROUTING_PROCESSOR_QUERY_HPP_
