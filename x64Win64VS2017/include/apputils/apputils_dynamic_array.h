/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_dynamic_array_h
#define apputils_dynamic_array_h

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

#include "ndds/ndds_c.h"

struct APPUTILSDynamicArray;

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_reserve(
        struct APPUTILSDynamicArray *self,
        DDS_Long capacity);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_resize(
        struct APPUTILSDynamicArray *self,
        DDS_Long required_length_min);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_copy_from_array(
        struct APPUTILSDynamicArray *self,
        DDS_Long offset,
        DDS_Long length,
        const void *source);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_copy(
        struct APPUTILSDynamicArray *self,
        const struct APPUTILSDynamicArray *source);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_append_array(
        struct APPUTILSDynamicArray *self,
        DDS_Long length,
        const void *source);

extern APPUTILSDllExport
void *APPUTILSDynamicArray_get_element_at(
        struct APPUTILSDynamicArray *self,
        DDS_Long index);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_get_element_copy_at(
        struct APPUTILSDynamicArray *self,
        void *element_copy,
        DDS_Long index);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_set_element_at(
        struct APPUTILSDynamicArray *self,
        DDS_Long index,
        const void *element);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_add_element(
        struct APPUTILSDynamicArray *self,
        const void *element);

extern APPUTILSDllExport
void *APPUTILSDynamicArray_get_array_buffer(
        const struct APPUTILSDynamicArray *self);

extern APPUTILSDllExport
int APPUTILSDynamicArray_get_array_length(
        const struct APPUTILSDynamicArray *self);

extern APPUTILSDllExport
void APPUTILSDynamicArray_finalize(struct APPUTILSDynamicArray *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicArray_initialize(
        struct APPUTILSDynamicArray *self,
        DDS_Long element_type_size,
        const struct REDAFastBufferPoolGrowthProperty *growth_property);

extern APPUTILSDllExport
void APPUTILSDynamicArray_delete(struct APPUTILSDynamicArray *self);

extern APPUTILSDllExport
struct APPUTILSDynamicArray *APPUTILSDynamicArray_new(
        DDS_Long element_type_size,
        const struct REDAFastBufferPoolGrowthProperty *growth_property);

#endif /* apputils_dynamic_array_h */
