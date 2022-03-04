/*
 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef rtijson_parser_h
#define rtijson_parser_h



  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif

  #ifndef rtijson_dll_h
    #include "rtijson/rtijson_dll.h"
  #endif

  #ifndef json_object_h
    #include "rtijson/rtijson_object.h"
  #endif

  #include "rtijson/json.h"

#ifdef __cplusplus
    extern "C" {
#endif


struct RTIJSONParserImpl {
    json_settings _settings;
};


typedef struct RTIJSONParserImpl RTIJSONParser;


#define RTIJSONParser_INITIALIZER {{0}}

extern RTIJSONDllExport
void RTIJSONParser_finalize(RTIJSONParser *self);

extern RTIJSONDllExport
RTIBool RTIJSONParser_initialize(RTIJSONParser *self);

extern RTIJSONDllExport
RTIJSONParser * RTIJSONParser_new(void);

extern RTIJSONDllExport
void RTIJSONParser_delete(RTIJSONParser *self);

extern RTIJSONDllExport
RTIBool RTIJSONParser_parse_w_params(
        RTIJSONParser *self,
        RTIJSONObject *root,
        const char *json,
        int json_length);

extern RTIJSONDllExport
RTIJSONObject * RTIJSONParser_parse(
        RTIJSONParser *self,
        const char *json,
        int json_length);

extern RTIJSONDllExport
RTIJSONObject * RTIJSONParser_parse_ex(
        const char *json,
        int json_length);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* rtijson_parser_h */
