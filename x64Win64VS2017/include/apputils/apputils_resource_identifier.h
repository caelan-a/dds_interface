/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_resource_identifier_h
#define apputils_resource_identifier_h

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

#ifndef apputils_dynamic_array_impl_h
  #include "apputils/apputils_dynamic_array_impl.h"
#endif

#ifndef apputils_string_buffer_impl_h
  #include "apputils/apputils_string_buffer_impl.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

#define APPUTILS_RESOURCE_IDENTIFIER_LENGTH_MAX (2048)
#define APPUTILS_Admin_RESOURCE_IDENTIFIER_LENGTH_MAX ((APPUTILS_RESOURCE_IDENTIFIER_LENGTH_MAX))

#define APPUTILS_RESOURCE_IDENTIFIER_SEPARATOR_VALUE "/"
#define APPUTILS_RESOURCE_IDENTIFIER_CUSTOM_METHOD_SEPARATOR_VALUE ":"

extern APPUTILSDllVariable
const char * APPUTILS_RESOURCE_IDENTIFIER_SEPARATOR;

extern APPUTILSDllVariable
const char * APPUTILS_SERVICE_RESOURCE_IDENTIFIER_CUSTOM_METHOD_SEPARATOR;


struct APPUTILSResourceIdentifier;

extern APPUTILSDllVariable
struct APPUTILSResourceIdentifier
APPUTILS_RESOURCE_IDENTIFIER_NIL;

extern APPUTILSDllVariable
const char *RTI_SERVICE_CUSTOM_METHOD_NAMES[];


struct APPUTILSRelativeResourceInfo;

extern APPUTILSDllExport
const char*
APPUTILSRelativeResourceInfo_get_kind(
        const struct APPUTILSRelativeResourceInfo *self);

extern APPUTILSDllExport
const char*
APPUTILSRelativeResourceInfo_get_name(
        const struct APPUTILSRelativeResourceInfo *self);

extern APPUTILSDllExport
const struct APPUTILSRelativeResourceInfo *
APPUTILSRelativeResourceInfo_get_parent(
        const struct APPUTILSRelativeResourceInfo *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSResourceIdentifier_to_parent_id(
        struct APPUTILSResourceIdentifier *self,
        struct APPUTILSResourceIdentifier *parent_id);

extern APPUTILSDllExport
DDS_Boolean APPUTILSResourceIdentifier_initialize_with_parent(
        struct APPUTILSResourceIdentifier *self,
        const struct APPUTILSResourceIdentifier *parent);


#define APPUTILSResourceIdentifier_RELATIVE_RESOURCE_COUNT_MAX (16)
#define APPUTILSResourceIdentifier_INITIALIZER {\
        REDA_INLINE_LIST_EMPTY, \
        NULL, NULL, \
        {{REDAInlineListNode_INITIALIZER, NULL, 0, 0}}, \
        NULL, \
        NULL, \
        NULL}


struct APPUTILSResourceIdentifier;

extern APPUTILSDllExport
const struct APPUTILSRelativeResourceInfo *
APPUTILSResourceIdentifier_get_resource(
        struct APPUTILSResourceIdentifier *self);

extern APPUTILSDllExport
const struct APPUTILSRelativeResourceInfo *
APPUTILSResourceIdentifier_get_top(
        struct APPUTILSResourceIdentifier *self);

extern APPUTILSDllExport
void APPUTILSResourceIdentifier_finalize(
        struct APPUTILSResourceIdentifier *self);

extern APPUTILSDllExport
RTIBool APPUTILSResourceIdentifier_initialize(
        struct APPUTILSResourceIdentifier *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSResourceIdentifier_parse_formatted_identifier(
        struct APPUTILSResourceIdentifier *self,
        const char *formatted_identifier);

extern APPUTILSDllExport
DDS_Boolean APPUTILSResourceIdentifier_add_relative_resource(
        struct APPUTILSResourceIdentifier *self,
        const char *kind_name,
        const char *name);

extern APPUTILSDllExport
void APPUTILSResourceIdentifier_format_resource_identifier(
        char *formatted_identifier,
        const char *resource_fully_qualified_name,
        const char **kind_array);

extern APPUTILSDllExport
const char * APPUTILSResourceIdentifier_get_fully_qualified_name(
        struct APPUTILSResourceIdentifier *self);

extern APPUTILSDllExport
const char * APPUTILSResourceIdentifier_get_fully_qualified_kind(
        struct APPUTILSResourceIdentifier *self);

extern APPUTILSDllExport
const char * APPUTILSResourceIdentifier_get_custom_method(
        struct APPUTILSResourceIdentifier *self);

extern APPUTILSDllExport
const char * APPUTILSResourceIdentifier_to_string(
        struct APPUTILSResourceIdentifier *self);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* apputils_resource_identifier_h */
