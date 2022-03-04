/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_string_buffer_h
#define apputils_string_buffer_h

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

#include "ndds/ndds_c.h"

struct APPUTILSStringBuffer;

extern APPUTILSDllExport
DDS_Long APPUTILSStringBuffer_get_string_length(
        struct APPUTILSStringBuffer *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSStringBuffer_append_string(
        struct APPUTILSStringBuffer *self,
        const DDS_Char *string);

extern APPUTILSDllExport
DDS_Boolean APPUTILSStringBuffer_append_string_with_length(
        struct APPUTILSStringBuffer *self,
        const DDS_Char *string,
        DDS_Long length);

extern APPUTILSDllExport
DDS_Boolean APPUTILSStringBuffer_append(
        struct APPUTILSStringBuffer *self,
        const struct APPUTILSStringBuffer *string_buffer);

extern APPUTILSDllExport
DDS_Boolean APPUTILSStringBuffer_copy_string(
        struct APPUTILSStringBuffer *self,
        const DDS_Char *string);

extern APPUTILSDllExport
DDS_Boolean APPUTILSStringBuffer_copy(
        struct APPUTILSStringBuffer *self,
        const struct APPUTILSStringBuffer *string_buffer);

extern APPUTILSDllExport
const DDS_Char * APPUTILSStringBuffer_to_string(
        struct APPUTILSStringBuffer *self);

extern APPUTILSDllExport
void APPUTILSStringBuffer_finalize(struct APPUTILSStringBuffer *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSStringBuffer_initialize(
        struct APPUTILSStringBuffer *self,
        DDS_Long initial_buffer_length,
        DDS_Long buffer_length_max);

extern APPUTILSDllExport
void APPUTILSStringBuffer_delete(struct APPUTILSStringBuffer *self);

extern APPUTILSDllExport
struct APPUTILSStringBuffer * APPUTILSStringBuffer_new(
        DDS_Long initial_buffer_length,
        DDS_Long buffer_length_max);

#endif /* apputils_string_buffer_h */
