/*
 * (c) Copyright, Real-Time Innovations, 2020.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef HPP_RTI_JSON_OBJECT_HPP_
#define HPP_RTI_JSON_OBJECT_HPP_

#include <string>
#include <sstream>
#include <stdint.h>

#include "osapi/osapi_type.h"
#include "rtijson/json.h"
#include "rtijson/rtijson_object.h"
#include "rtijson/rtijson_log.h"
#include "JsonException.hpp"

#define JSON_CURRENT_SUBMODULE JSON_SUBMODULE_MASK_PARSER
#define MAX_STRING_LENGTH 256

namespace rti { namespace json {

    /*
     * This class enum provide the possible types of a RTIJSONObject object
     */
    struct ObjectKind {
        enum type{
            NONE,
            OBJECT,
            ARRAY,
            INTEGER,
            DOUBLE,
            STRING,
            BOOLEAN,
            NULL_OBJECT
        };
    };

/*
 * This class wraps an RTIJSONObject object providing some extra
 * functionality such as find_node, which returns the first node with a
 * certain name.
 */
class JsonObject {

public:
    /*
     * Constructor that will do a shallow copy of the given RTIJSONObject
     */
    JsonObject(RTIJSONObject& json_object):
        json_object_(json_object)
    {
    }

    /*
     * Destructor
     */
    ~JsonObject()
    {
    }

    /*
     * It will return the kind of the JSON Object
     * @return the kind of the JSON Object
     */
    rti::json::ObjectKind::type kind() const
    {
        int type_value;

        type_value = (int) RTIJSONObject_getKind(&json_object_);
        return (rti::json::ObjectKind::type) type_value;
    }

    /*
     * Return the int64_t value inside the JSON Object
     * @pre kind() == ObjectKind::INTEGER or else it throws JsonError
     * @return the Json Object int value
     */
    int64_t int_value() const
    {
        int64_t value;

        if (!RTIJSONObject_getIntValue(&json_object_, (RTI_INT64 *) &value)) {
            throw rti::json::JsonError("failed to get int value");
        }

        return value;
    }

    /*
     * Return the double value inside the JSON Object
     * @pre kind() == ObjectKind::DOUBLE or else it throws JsonError
     * @return the Json Object double value
     */
    double double_value() const
    {
        double value;

        if (!RTIJSONObject_getDoubleValue(&json_object_, &value)) {
            throw rti::json::JsonError("failed to get double value");
        }

        return value;
    }

    /*
     * Return the bool value inside the JSON Object
     * @pre kind() == ObjectKind::BOOL or else it throws JsonError
     * @return the Json Object bool value
     */
    bool bool_value() const
    {
        RTIBool value;

        if (!RTIJSONObject_getBoolValue(&json_object_, &value)) {
            throw rti::json::JsonError("failed to get bool value");
        }

        return value ? true : false;
    }

    /*
     * Return the string value inside the JSON Object
     * @pre kind() == ObjectKind::STRING or else it throws JsonError
     * @return the Json Object string value
     */
    std::string string_value() const
    {
        std::string value = "";

        if (!RTIJSONObject_getStringValue(
                &json_object_,
                const_cast<char *>(value.c_str()),
                MAX_STRING_LENGTH)) {
            throw rti::json::JsonError("failed to get string value");
        }

        return value;
    }

    /*
     * This method will return the number of children elements if the given
     * JsonObject is object type. If the type of the JsonObject is array
     * it will returns the number of array elements. If the JsobObject kind is
     * different than Object or array, it will returns 0;
     * @param self the JsonObject
     * @return the total child/array count
     */
    int child_count() const
    {
        return RTIJSONObject_getChildCount(&json_object_);
    }

    /*
     * Return the Json Node in a specific position
     * @param idx the index position of the specific Json Object
     * @return a JsonObject which point to the JSON node with the given position.
     * If the Json Node doesn't exist, it throws JsonError
     */
    JsonObject get_child(int idx) const
    {
        JsonObject child;

        if (!RTIJSONObject_getChildAt(
                    &json_object_,
                    &child.json_object_,
                    idx)) {
            throw_child_not_found_ex(idx);
        }

        return child;
    }
    /*
     * Return the JSON Object with the given name
     * @param name the name of the JSON Object to return
     * @return a JSONObject which point to the Json Node with the given name.
     * If the Json Node doesn't exist, it throws JsonError
     */
    JsonObject get_child(const std::string& name) const
    {
        JsonObject child;

        if (!RTIJSONObject_getChildByName(
                &json_object_,
                &child.json_object_,
                name.c_str())) {
            throw_child_not_found_ex(name);
        }

        return child;
    }

    /*
     * Return the name of the Child in a specific position
     * @param idx the index position of the specific Child
     * @return the name of the Child in the given position
     * If the Json Node doesn't exist, it throws JsonError
     */
    std::string child_name(int idx) const
    {
        const char *value_char = RTIJSONObject_getChildName(&json_object_, idx);
        if (value_char == NULL) {
            throw_child_not_found_ex(idx);
        }

        return value_char;
    }

    /*
     *  This method compare two Json Objects
     *  @param node second Json Object of the comparison
     *  @return TRUE if both Json Objects have the same content.
     *  Otherwise, it will return FALSE
     */
    bool operator==(const JsonObject& node) const
    {
        return RTIJSONObject_equals(&json_object_, &node.json_object_);
    }

    /*
     * This method looks for a node within the JSON node tree with the given
     * name. It will create a JsonObject which will be returned.
     * @param node_name Name of the node to be located.
     * @return JsonObject which point to the JSON node with the given name.
     */
    JsonObject find_node(const std::string& node_name) const
    {
        return find_node(*this, node_name);
    }

    /*
     * This method returns the native object of the Json Object.
     * @return Reference to the RTIJSONObject instance. If the RTIJSONObject
     * instance has not been initialized (i.e., we have not parsed anything yet)
     * the method returns a RTIJSONObject instance with kind none.
     */
    const RTIJSONObject& native() const
    {
        return json_object_;
    }

private:
    RTIJSONObject json_object_;

    /*
     * Default constructor
     */
    JsonObject()
    {
        RTIJSONObject_initialize(
                &json_object_,
                NULL);
    }

    /*
     * This method looks for a node within the JSON node tree with the given
     * name.
     * @param parent_node reference to the parent node.
     * @param node_name Name of the node to be located.
     * @return JsonObject which point to the JSON node with the given name.
     */
    JsonObject find_node(
            const JsonObject& parent_node,
            const std::string& node_name) const
    {
        JsonObject root;

        switch (parent_node.kind()) {
        case rti::json::ObjectKind::OBJECT:
        {
            size_t length = parent_node.child_count();

            for (size_t i = 0; i < length; ++i) {
                if (parent_node.child_name(i) == node_name) {
                    root.json_object_ = json_object_;
                    root = parent_node.get_child(i);
                    return root;
                }

                JsonObject childNode = parent_node.get_child(i);
                if (childNode.kind() == rti::json::ObjectKind::OBJECT
                        || childNode.kind() ==
                                rti::json::ObjectKind::ARRAY) {
                    root = find_node(childNode, node_name);
                    if (root.native()._json != NULL) {
                        if(root.kind() != rti::json::ObjectKind::NONE){
                            return root;
                        }
                    }
                }
            }

        }
            break;

        case rti::json::ObjectKind::ARRAY:
        {
            size_t length = parent_node.child_count();

            for (size_t i = 0; i < length; ++i) {
                JsonObject childNode = parent_node.get_child(i);

                if (childNode.kind() == rti::json::ObjectKind::OBJECT
                        || childNode.kind() ==
                                rti::json::ObjectKind::ARRAY) {
                    root = find_node(childNode, node_name);
                    if (root.native()._json != NULL) {
                        if(root.kind() != rti::json::ObjectKind::NONE){
                            return root;
                        }
                    }
                }
            }

        }
            break;

        default:
            break;
        }

        return root;
    }

    /*
     * This method will be used to throw and exception related to Json Node
     * not found.
     * @param index the index/name of the not found Json node
     */
    template <typename IndexType>
    static void throw_child_not_found_ex(const IndexType& index)
    {
        std::stringstream error_stream;
        error_stream << "child (" << index << ") not found";
        throw rti::json::JsonError(error_stream.str().c_str());
    }

public:

    /*
     * This class allows the iteration over the different children
     * of a Json Object
     */
    class iterator {

    public:
         // iterator traits
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef JsonObject value_type;
        typedef value_type reference;
        typedef value_type pointer;

        /*
         * Constructor
         */
        explicit iterator(
                JsonObject& parent_json,
                const int idx) :
                root_json_object_(parent_json),
                current_position_(idx)
        {
        }

        /*
         * Advances to the next element
         * @return iterator pointing to the next element
         */
        iterator operator++()
        {
            current_position_++;
            return *this;
        }

        /*
         * Advances to the next element
         * @return iterator pointing to the previous element
         */
        iterator operator++(int)
        {
            iterator temp(*this);
            ++current_position_;
            return temp;
        }

        /*
         * Go backward to the previous element
         * @return iterator pointing to the previous element
         */
        iterator operator--()
        {
            current_position_--;
            return *this;
        }

        /*
         * Go backward to the previous element
         * @return iterator pointing to the before element
         */
        iterator operator--(int)
        {
            iterator temp(*this);
            --current_position_;
            return temp;
        }

        /*
         * Returns the current child
         * @return the JsonObject in the current position
         * of the Json document
         */
        value_type operator*()
        {
            return root_json_object_.get_child(current_position_);
        }

        /*
         * Returns the current child
         * @return the JsonObject in the current position
         * of the Json document
         */
        value_type operator->()
        {
            return *(*this);
        }

        /*
         * Compares two iterators
         * @return True on success
         */
        bool operator==(const iterator& other)
        {
            return &root_json_object_ + current_position_ ==
                    &other.root_json_object_ + other.current_position_;
        }

        /*
         * Compares two iterators
         * @return True on success
         */
        bool operator!=(const iterator& other)
        {
            return !(*this == other);
        }

        /*
         * Compares two iterators
         * @return True on success
         */
        bool operator<(const iterator& other) const
        {
            return !(*this >= other);
        }

        /*
         * Compares two iterators
         * @return True on success
         */
        bool operator<=(const iterator& other) const
        {
            return &root_json_object_ + current_position_ <=
                    &other.root_json_object_ + other.current_position_;
        }

        /*
         * Compares two iterators
         * @return True on success
         */
        bool operator>(const iterator& other) const
        {
            return !(*this <= other);
        }

        /*
         * Compares two iterators
         * @return True on success
         */
        bool operator>=(const iterator& other) const
        {
            return &root_json_object_ + current_position_ >=
                    &other.root_json_object_ + other.current_position_;
        }

        /*
         * Compares
         * @return True on success
         */
        bool at_end()
        {
            return root_json_object_.child_count() == current_position_;
        }

    private:
        JsonObject& root_json_object_;
        int current_position_;
    };

    /*
     * Return the beginning of the range of children
     * @return iterator that point to the first child of the Json Object
     */
    iterator begin()
    {
        iterator iterator(*this, 0);
        return iterator;
    }

    /*
     * Return the end of the range of children
     * @return iterator that point to the end of the range
     */
    iterator end()
    {
        iterator iterator(*this, child_count());
        return iterator;
    }

};

} } /* namespace rti::json */

#undef JSON_CURRENT_SUBMODULE   /* JSON_SUBMODULE_MASK_PARSER */

#endif /* HPP_RTI_JSON_OBJECT_HPP_ */
