/*
 * (c) Copyright, Real-Time Innovations, 2020.
 * All rights reserved.
 * No duplications, whole or partial, manual or electronic, may be made
 * without express written permission.  Any such copies, or
 * revisions thereof, must display this notice unaltered.
 * This code contains trade secrets of Real-Time Innovations, Inc.
 */

#ifndef HPP_RTI_JSON_DOM_HPP_
#define HPP_RTI_JSON_DOM_HPP_

#include <string>

#include "osapi/osapi_type.h"
#include "rtijson/rtijson_object.h"
#include "rtijson/rtijson_parser.h"
#include "JsonObject.hpp"

#define JSON_CURRENT_SUBMODULE JSON_SUBMODULE_MASK_PARSER

namespace rti { namespace json {

/*
 * This class wraps an RTIJSONObject object providing to handle its memory
 * using a constructor and a destructor.
 */
class JsonDom {

public:
    /*
     * Constructor
     */
    explicit JsonDom(const std::string& json)
            : json_object_(),
              json_parser_(),
              valid_json_(false)
    {
        RTIJSONParser_initialize(&json_parser_);
        valid_json_ = parse(json);
    }

    /*
     * Destructor
     */
    ~JsonDom()
    {
        RTIJSONObject_finalize(&json_object_);
        RTIJSONParser_finalize(&json_parser_);
    }

    /*
     * This method parses a JSON string and returns a pointer to the root
     * node of the JSON tree.
     * @param json JSON string to be parsed.
     * @return True on success
     */
    bool parse(const std::string& json)
    {
        if (json_object_._json != NULL) {
            RTIJSONObject_finalize(&json_object_);
        }
        RTIJSONObject_initialize(&json_object_, NULL);

        valid_json_ = RTIJSONParser_parse_w_params(
                &json_parser_,
                &json_object_,
                json.c_str(),
                json.length()) ? true : false;

        return valid_json_;
    }

    /*
     * It will the current state of the JsonDom.
     * @return True if the JsonDom has parsed the Json String correctly.
     */
    bool is_valid() const {
        return valid_json_;
    }

    /*
     * It will return the root object of the Json tree.
     * @return the current root object of the Json object
     */
    JsonObject root()
    {
        JsonObject json_object(json_object_);

        return json_object;
    }

private:
    RTIJSONObject json_object_;
    RTIJSONParser json_parser_;
    bool valid_json_;

    /*
     * Copy Constructor
     */
    JsonDom(const JsonDom& json_object);

    /*
     * Assignment operator
     */
    void operator=(const JsonDom& json_object);
};

} } /* namespace rti::json */

#undef JSON_CURRENT_SUBMODULE   /* JSON_SUBMODULE_MASK_PARSER */

#endif /* HPP_RTI_JSON_DOM_HPP_ */
