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

#ifndef HPP_SERVICE_RESOURCE_IDENTIFIER_HPP_
#define HPP_SERVICE_RESOURCE_IDENTIFIER_HPP_


// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "reda/reda_inlineList.h"
#include "apputils/apputils_resource_identifier_impl.h"

#include <dds/core/Value.hpp>
#include <rti/core/NativeValueType.hpp>
#include <rti/apputils/ServiceException.hpp>
#include <rti/apputils/EntityId.hpp>

namespace rti { namespace apputils {

class ResourceIdentifier;

class RelativeResource {
public:

    typedef const APPUTILSRelativeResourceInfo native_type;
    
            
    RelativeResource(native_type *native_value)
        : native_relative_resource_(native_value)
    {
    }

    ~RelativeResource()
    {
    }

     RelativeResource(const RelativeResource &other)
        : native_relative_resource_(other.native_relative_resource_)
    {
    }

    RelativeResource operator * () const
    {
        return RelativeResource(*this);
    }

    RelativeResource & operator = (const RelativeResource& other)
    {
        native_relative_resource_ = other.native_relative_resource_;
        return *this;
    }

    RelativeResource& operator ++ ()
    {
        native_relative_resource_ = next();
        return *this;
    }

    RelativeResource& operator -- ()
    {
        native_relative_resource_ = prev();
        return *this;
    }

    friend bool operator == (
            const RelativeResource & s1,
            const RelativeResource & s2)
    {
        return s1.native_relative_resource_ == s2.native_relative_resource_;
    }

    friend bool operator != (
            const RelativeResource & s1,
            const RelativeResource & s2)
    {
        return !(s1 == s2);
    }

    std::string name() const
    {
        return APPUTILSRelativeResourceInfo_get_name(
                native_relative_resource_);
    }

    std::string kind() const
    {
        return APPUTILSRelativeResourceInfo_get_kind(
                native_relative_resource_);
    }

    RelativeResource& last()
    {
        REDAInlineListNode *last = REDAInlineList_getLast(
                native_relative_resource_->_node.inlineList);
        RTIBOOST_ASSERT(last != NULL);
        native_relative_resource_ = reinterpret_cast<native_type*>(last);
        return *this;
    }

    RelativeResource& begin()
    {
        REDAInlineListNode *first = REDAInlineList_getFirst(
                native_relative_resource_->_node.inlineList);
        RTIBOOST_ASSERT(first != NULL);
        native_relative_resource_ = reinterpret_cast<native_type*> (first);
        return *this;
    }

     friend const std::string to_string(
            const RelativeResource& relative_id)
    {
        return relative_id.kind() + "/" + relative_id.name();
    }

    friend class ResourceIdentifier;
private:

    static RelativeResource nil()
    {
        static RelativeResource nil(NULL);

        return nil;
    }
    native_type * next()
    {
        return reinterpret_cast<native_type*> (
                native_relative_resource_->_node.next);
    }

    native_type * prev()
    {
        REDAInlineListNode *prev = native_relative_resource_->_node.prev;
        if (prev != NULL) {
            return reinterpret_cast<native_type*> (prev);
        }

        return native_relative_resource_;
    }

private:
    native_type *native_relative_resource_;
};

class ResourceIdentifier {
public:
    typedef APPUTILSResourceIdentifier native_type;    
    typedef RelativeResource iterator;
    typedef RelativeResource relative_resource;

public:

    ResourceIdentifier()
    {
        if (!APPUTILSResourceIdentifier_initialize(&native_)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_INIT_FAILURE_s,
                    "native resource identifier");
        }
    }

    ResourceIdentifier(const std::string& formatted_uri)
    {
        if (!APPUTILSResourceIdentifier_initialize(&native_)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_INIT_FAILURE_s,
                    "native resource identifier");
        }
        if (!APPUTILSResourceIdentifier_parse_formatted_identifier(
                &native_,
                formatted_uri.c_str())) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_SERVICE_LOG_MALFORMED_RESOURCE_IDENTIFIER_s,
                    formatted_uri.c_str());
        }
        parse(formatted_uri);
    }

    ResourceIdentifier(const ResourceIdentifier& other)
    {
        if (!APPUTILSResourceIdentifier_initialize(&native_)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_INIT_FAILURE_s,
                    "native resource identifier");
        }
        append(other);
    }

    ResourceIdentifier(
            const ResourceIdentifier& parent,
            const ResourceIdentifier& child)
    {
        if (!APPUTILSResourceIdentifier_initialize(&native_)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_INIT_FAILURE_s,
                    "native resource identifier");
        }
        append(parent);
        append(child);
    }

    ResourceIdentifier(
            const std::string& kind,
            const std::string& name)
    {
        if (!APPUTILSResourceIdentifier_initialize(&native_)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_INIT_FAILURE_s,
                    "native resource identifier");
        }
        add(kind, name);
    }

    ResourceIdentifier(
            const ResourceIdentifier::relative_resource& relative_resource)
    {
        if (!APPUTILSResourceIdentifier_initialize(&native_)) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_INIT_FAILURE_s,
                    "native resource identifier");
        }
        add(relative_resource);
    }

    ResourceIdentifier& parse(const std::string& formatted_uri)
    {
        if (!APPUTILSResourceIdentifier_parse_formatted_identifier(
                &native_,
                formatted_uri.c_str())) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_SERVICE_LOG_MALFORMED_RESOURCE_IDENTIFIER_s,
                    formatted_uri.c_str());
        }

        return *this;
    }

    ~ResourceIdentifier()
    {
        APPUTILSResourceIdentifier_finalize(&native_);
    }

    iterator last() const
    {
        return iterator(APPUTILSResourceIdentifier_get_resource(
                const_cast<native_type*> (&native_)));

    }

    iterator end() const
    {
        return iterator::nil();
    }

    iterator begin() const
    {
        iterator last = this->last();
        if (last != end()) {
            return last.begin();
        }

        return last;
    }

    ResourceIdentifier parent() const
    {
        ResourceIdentifier parent_id;
        iterator it = begin();
        for (; it != last(); ++it) {
            parent_id += ResourceIdentifier(it.kind(), it.name());
        }

        return parent_id;
    }

    const std::string fully_qualified_name() const
    {
        return APPUTILSResourceIdentifier_get_fully_qualified_name(
                const_cast<native_type*> (&native_));
    }

    const std::string fully_qualified_kind() const
    {
        return APPUTILSResourceIdentifier_get_fully_qualified_kind(
                const_cast<native_type*> (&native_));
    }

    const std::string custom_method() const
    {
        return APPUTILSResourceIdentifier_get_custom_method(
                const_cast<native_type*> (&native_));
    }

    ResourceIdentifier& operator+=(
            const ResourceIdentifier& right)
    {
        return append(right);
    }

    friend std::ostream& operator<<(
            std::ostream& os,
            const ResourceIdentifier& resource_id)
    {
        os << to_string(resource_id);

        return os;
    }

    friend const std::string to_string(
            const ResourceIdentifier& resource_id)
    {
        return std::string(to_native_string(resource_id));
    }

    friend const char* to_native_string(
            const ResourceIdentifier& resource_id)
    {
        return APPUTILSResourceIdentifier_to_string(
                const_cast<native_type*>(&resource_id.native_));
    }

    native_type& native() const
    {
        return const_cast<native_type&>(native_);
    }


private:

    ResourceIdentifier& add(
            const std::string& kind,
            const std::string& name = "")
    {
        if (!APPUTILSResourceIdentifier_add_relative_resource(
                &native_,
                kind.c_str(),
                name.c_str())) {
            RTI_THROW_SERVICE_EXCEPTION(
                    &RTI_LOG_ADD_FAILURE_s,
                    "relative resource");
        }

        return *this;
    }

    ResourceIdentifier& add(
            const ResourceIdentifier::relative_resource& relative_resource)
    {
        add(relative_resource.kind(), relative_resource.name());
        return *this;
    }

    ResourceIdentifier& append(
            const ResourceIdentifier& right)
    {
        ResourceIdentifier::iterator it = right.begin();
        for (; it != end(); ++it) {
            add(it);
        }

        return *this;
    }

    native_type native_;

};

} } /* namespace rti::apputils */
  

#endif /* HPP_SERVICE_RESOURCE_IDENTIFIER_HPP_ */
