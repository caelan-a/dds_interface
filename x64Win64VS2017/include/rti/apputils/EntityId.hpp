/*
 * (c) Copyright, Real-Time Innovations, 2017-.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 *
 */

#ifndef HPP_SERVICE_ENTITY_ID_HPP_
#define HPP_SERVICE_ENTITY_ID_HPP_

// IMPORTANT: macros.hpp must be the first RTI header included in every header
// file so that symbols are exported correctly on Windows
#include <dds/core/macros.hpp>

#include "rtixmlutils/rtixmlutils_object.h"

namespace rti { namespace apputils {

class EntityFullNameIterator {
public:

    EntityFullNameIterator(const std::string& full_name)
    : full_name_(full_name), substring_pos_(0), next_substring_pos_(0)
    {
        next();
    }

    ~EntityFullNameIterator()
    {
    }

    bool is_end() const
    {
        return substring_pos_ == full_name_.length();
    }

    EntityFullNameIterator& end()
    {
        substring_pos_ = full_name_.length();
        next_substring_pos_ = substring_pos_;

        return *this;
    }

    EntityFullNameIterator& last()
    {
        next_substring_pos_ = full_name_.length();
        substring_pos_ = next_substring_pos_;

        for (; substring_pos_ > 0; --substring_pos_) {
            if (full_name_[substring_pos_] == '\"') {
                size_t opening_quotes = full_name_.rfind(
                        "\"",
                        substring_pos_ - 1);
                if (opening_quotes == std::string::npos) {
                    DDSLog_warn(
                            &RTI_LOG_ANY_s,
                            "detected unbalanced escaped name. Missing closing '\"'?");
                } else {
                    // skip all characters in escaped name
                    substring_pos_ = opening_quotes;
                }
            } else if (full_name_.find(
                    RTIXMLUTILS_OBJECT_NAME_SEPARATOR,
                    substring_pos_) == substring_pos_) {
                substring_pos_ += strlen(RTIXMLUTILS_OBJECT_NAME_SEPARATOR);
                break;
            }
        }

        return *this;
    }


    std::string parent()
    {
        size_t parent_length = (substring_pos_ == 0)
                ? 0
                : substring_pos_ - strlen(RTIXMLUTILS_OBJECT_NAME_SEPARATOR);
        return full_name_.substr(0, parent_length);
    }

    std::string operator*() const
    {
        size_t substring_pos = substring_pos_;
        size_t name_length = next_substring_pos_ - substring_pos_;
        if (name_length > 1
                && full_name_[substring_pos_ + name_length - 1] == '\"'
                && full_name_[substring_pos_] == '\"') {
            name_length -= 2;
            ++substring_pos;

        }
        return full_name_.substr(substring_pos, name_length);
    }

    EntityFullNameIterator& operator++()
    {
        next();
        return *this;
    }

    std::string escaped()
    {
        size_t substring_pos = substring_pos_;
        size_t name_length = next_substring_pos_ - substring_pos_;

        return full_name_.substr(substring_pos, name_length);
    }


    friend bool operator==(
            const EntityFullNameIterator &s1,
            const EntityFullNameIterator &s2)
    {
        return s1.substring_pos_ == s2.substring_pos_
                && s1.next_substring_pos_ == s2.next_substring_pos_
                && &s1.full_name_ == &s2.full_name_;
    }

    friend bool operator!=(
            const EntityFullNameIterator &s1,
            const EntityFullNameIterator &s2)
    {
        return !(s1 == s2);
    }


private:

    void next()
    {
        if (full_name_.find(
                RTIXMLUTILS_OBJECT_NAME_SEPARATOR,
                next_substring_pos_) == next_substring_pos_) {
            next_substring_pos_ += strlen(RTIXMLUTILS_OBJECT_NAME_SEPARATOR);
        }
        substring_pos_ = next_substring_pos_;

        for (; next_substring_pos_ < full_name_.length(); ++next_substring_pos_) {
            if (full_name_[next_substring_pos_] == '\"') {
                size_t closing_quotes = full_name_.find(
                        "\"",
                        next_substring_pos_ + 1);
                if (closing_quotes == std::string::npos) {
                    DDSLog_warn(
                            &RTI_LOG_ANY_s,
                            "detected unbalanced escaped name. Missing closing '\"'?");
                } else {
                    // skip all characters in escaped name
                    next_substring_pos_ = closing_quotes;
                }
            } else if (full_name_.find(
                    RTIXMLUTILS_OBJECT_NAME_SEPARATOR,
                    next_substring_pos_) == next_substring_pos_) {
                break;
            }
        }
    }

private:
    const std::string& full_name_;
    size_t substring_pos_;
    size_t next_substring_pos_;
};

template<typename ENTITY_KIND_TYPE>
class EntityId {
public:
    typedef EntityFullNameIterator name_iterator;

public:

    EntityId(const std::string& the_full_name, ENTITY_KIND_TYPE the_kind)
    : full_name_(the_full_name), kind_(the_kind)
    {
    }

    bool is_nil() const
    {
        return kind_ == ENTITY_KIND_TYPE::count_;
    }

    name_iterator begin() const
    {
        return EntityFullNameIterator(full_name_);
    }

    name_iterator end() const
    {
        return EntityFullNameIterator(full_name_).end();
    }

    const std::string& full_name() const
    {
        return full_name_;
    }

    const std::string name() const
    {
        return (*EntityFullNameIterator(full_name_).last());
    }

    const std::string parent_name() const
    {
        return EntityFullNameIterator(full_name_).last().parent();
    }

    const ENTITY_KIND_TYPE& kind() const
    {
        return kind_;
    }

    static EntityId<ENTITY_KIND_TYPE> nil()
    {
        static EntityId<ENTITY_KIND_TYPE> nil(
                "",
                ENTITY_KIND_TYPE::count_);

        return nil;
    }

    friend bool operator==(
            const EntityId<ENTITY_KIND_TYPE>& left,
            const EntityId<ENTITY_KIND_TYPE>& right)
    {
        return left.kind_ == right.kind_
                && left.full_name_ == right.full_name_;
    }

private:
    std::string full_name_;
    ENTITY_KIND_TYPE kind_;
};

} } /* namespace rti::apputils */


#endif //HPP_SERVICE_ENTITY_ID_HPP_

