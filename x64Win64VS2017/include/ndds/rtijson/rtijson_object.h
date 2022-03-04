/*
 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef rtijson_object_h
#define rtijson_object_h



  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif

  #ifndef rtijson_dll_h
    #include "rtijson/rtijson_dll.h"
  #endif

  #include "rtijson/json.h"

#ifdef __cplusplus
    extern "C" {
#endif


typedef enum RTIJSONObjectKind {
    RTI_JSON_NONE_OBJECT,
    RTI_JSON_OBJECT_OBJECT,
    RTI_JSON_ARRAY_OBJECT,
    RTI_JSON_INTEGER_OBJECT,
    RTI_JSON_DOUBLE_OBJECT,
    RTI_JSON_STRING_OBJECT,
    RTI_JSON_BOOLEAN_OBJECT,
    RTI_JSON_NULL_OBJECT
} RTIJSONObjectKind;


struct RTIJSONObjectImpl {
    json_value *_json;
};


typedef struct RTIJSONObjectImpl RTIJSONObject;


#define RTIJSONObject_INITIALIZER {NULL}

extern RTIJSONDllExport
RTIJSONObject * RTIJSONObject_new(void);

extern RTIJSONDllExport
void RTIJSONObject_delete(RTIJSONObject *self);

extern RTIJSONDllExport
RTIBool RTIJSONObject_initialize(RTIJSONObject *self, json_value *json);

extern RTIJSONDllExport
void RTIJSONObject_finalize(RTIJSONObject *self);

extern RTIJSONDllExport
RTIJSONObjectKind RTIJSONObject_getKind(const RTIJSONObject *self);

extern RTIJSONDllExport
int RTIJSONObject_getChildCount(const RTIJSONObject *self);

extern RTIJSONDllExport
RTIBool RTIJSONObject_getChildAt(
        const RTIJSONObject *self,
        RTIJSONObject *child,
        int idx);

extern RTIJSONDllExport
RTIBool RTIJSONObject_getChildByName(
        const RTIJSONObject *self,
        RTIJSONObject *child,
        const char *name);

extern RTIJSONDllExport
const char * RTIJSONObject_getChildName(const RTIJSONObject *self, int idx);

extern RTIJSONDllExport
RTIBool RTIJSONObject_getIntValue(const RTIJSONObject *self, RTI_INT64 *val);

extern RTIJSONDllExport
RTIBool RTIJSONObject_getDoubleValue(
        const RTIJSONObject *self,
        RTI_DOUBLE64 *val);

extern RTIJSONDllExport
RTIBool RTIJSONObject_getBoolValue(const RTIJSONObject *self, RTIBool *val);

extern RTIJSONDllExport
RTIBool RTIJSONObject_getStringValue(
        const RTIJSONObject *self,
        char *string,
        int maxLength);

extern RTIJSONDllExport
const char * RTIJSONObject_getStringValueEx(const RTIJSONObject *self);

extern RTIJSONDllExport
RTIBool RTIJSONObject_equals(
        const RTIJSONObject *node1,
        const RTIJSONObject *node2);

extern RTIJSONDllExport
int RTIJSONObject_openJsonList(char *jsonStr, size_t jsonStrSize);

extern RTIJSONDllExport
int RTIJSONObject_closeJsonList(char *jsonStr, size_t jsonStrSize);

extern RTIJSONDllExport
int RTIJSONObject_addJsonElementToStr(
        char *jsonStr,
        size_t jsonStrSize,
        const char *elementName,
        const char *elementValue,
        RTIBool prependComma);


#ifdef __cplusplus
    }	/* extern "C" */
#endif


#endif /* rtijson_object_h */
