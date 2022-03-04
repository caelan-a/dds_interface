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

#ifndef HPP_SERVICE_BODY_MANAGED_REPLY_HPP_
#define HPP_SERVICE_BODY_MANAGED_REPLY_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "osapi/osapi_heap.h"

#include <rtiboost/assert.hpp>
#include <dds/core/Value.hpp>
#include <dds/core/types.hpp>
#include <rti/apputils/ServiceException.hpp>
#include <rti/apputils/DynamicBuffer.hpp>

namespace rti { namespace apputils { namespace admin {

class BodyManagedReply
{
public:

    typedef RTI_Service_Admin_CommandReply reply_type;

    BodyManagedReply()
        : string_body_(default_property()), octet_body_(default_property())
    {
        initialize_native_reply();
    }

    BodyManagedReply(const DynamicBufferProperty &property)
        : string_body_(property), octet_body_(property)
    {
        initialize_native_reply();
    }

    ~BodyManagedReply()
    {
        // CODEGENII-779: clear pointers to avoid invalid deletion by finalizer
        reply_.string_body = NULL;
        if (!DDS_OctetSeq_has_ownership(&reply_.octet_body)) {
            DDS_OctetSeq_unloan(&reply_.octet_body);
        }

        RTI_Service_Admin_CommandReply_finalize_ex(
                &reply_,
                RTI_FALSE /* delete_pointers */);
    }

    void release_string_body(char *&buffer, int32_t& length)
    {
        string_body_.release(buffer, length);
        consolidate_string_body();
    }

    void own_string_body(char *buffer, int32_t length)
    {
        string_body_.own(buffer, length);
        consolidate_string_body();
    }

    char* string_body()
    {
        return reply_.string_body;
    }

    DDS_OctetSeq& octet_body()
    {
        return reply_.octet_body;
    }

    char* string_body(int32_t length)
    {
        string_body_.ensure_length(length + 1);
        consolidate_string_body();
        return string_body();
    }

    DDS_OctetSeq& octet_body(int32_t length)
    {
        octet_body_.ensure_length(length + 1);
        consolidate_octet_body();
        return octet_body();
    }

    void retcode(RTI_Service_Admin_CommandReplyRetcode retcode)
    {
        reply_.retcode = retcode;
    }

    void native_retcode(int32_t native_retcode)
    {
        reply_.native_retcode = native_retcode;
    }

    void clear()
    {
        string_body_.trim_to_size();
        *string_body_.buffer() = '\0';
        octet_body_.trim_to_size();
        DDS_OctetSeq_set_length(&reply_.octet_body, 0);
        retcode(RTI_SERVICE_COMMAND_REPLY_OK);
    }

    const reply_type& reply() const
    {
        return reply_;
    }

    static DynamicBufferProperty default_property()
    {
        return DynamicBufferProperty(32 * 1024, false);
    }

private:
    void consolidate_string_body()
    {
        reply_.string_body = string_body_.buffer();
    }

    void consolidate_octet_body()
    {
        // re-loan
        if (!DDS_OctetSeq_has_ownership(&reply_.octet_body)) {
            DDS_OctetSeq_unloan(&reply_.octet_body);
        }
        DDS_OctetSeq_loan_contiguous(
                &reply_.octet_body,
                (DDS_Octet *) octet_body_.buffer(),
                0,
                octet_body_.length());
    }

    void initialize_native_reply()
    {
        RTIOsapiMemory_zero(&reply_, sizeof(reply_type));
        if (!RTI_Service_Admin_CommandReply_initialize_ex(
                &reply_,
                RTI_FALSE, /*allocate_pointers */
                RTI_FALSE /*allocate_memory*/)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_INIT_FAILURE_s,
                    "reply buffer");
        }
        RTIBOOST_ASSERT(reply_.string_body == NULL);
        RTIBOOST_ASSERT(DDS_OctetSeq_get_length(&reply_.octet_body) == 0);
        consolidate_string_body();
        consolidate_octet_body();
    }

private:
    reply_type reply_;
    DynamicBuffer string_body_;
    DynamicBuffer octet_body_;

};

} } } // rti::apputils::admin
#endif /* HPP_SERVICE_BODY_MANAGED_REPLY_HPP_ */
