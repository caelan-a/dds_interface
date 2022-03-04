/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_data_vector_h
#define apputils_data_vector_h

#ifndef apputils_dynamic_array_impl_h
  #include "apputils/apputils_dynamic_array_impl.h"
#endif

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

typedef void * (*APPUTILSDataVectorDataGenerator_CreateDataFunction)(
        void *generator_data);

typedef void (*APPUTILSDataVectorDataGenerator_DeleteDataFunction)(
        void *generator_data,
        void *data);

typedef RTIBool (*APPUTILSDataVectorDataGenerator_CopyDataFunction)(
        void *generator_data,
        void *src,
        const void *from);

struct APPUTILSDataVectorGenerator {
    void *generator_data;
    APPUTILSDataVectorDataGenerator_CreateDataFunction create_data;
    APPUTILSDataVectorDataGenerator_CopyDataFunction copy_data;
    APPUTILSDataVectorDataGenerator_DeleteDataFunction delete_data;
};

struct APPUTILSDataVector;

extern APPUTILSDllExport
void * APPUTILSDataVector_get_element_at(
        struct APPUTILSDataVector *self,
        DDS_Long index);

extern APPUTILSDllExport
void * APPUTILSDataVector_add_new_element(
        struct APPUTILSDataVector *self);

extern APPUTILSDllExport
DDS_Long APPUTILSDataVector_get_array_length(
        const struct APPUTILSDataVector *self);

extern APPUTILSDllExport
void APPUTILSDataVector_finalize(struct APPUTILSDataVector *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDataVector_initialize(
        struct APPUTILSDataVector *self,
        const struct APPUTILSDataVectorGenerator *data_generator,
        const struct REDAFastBufferPoolGrowthProperty *growth_property);

extern APPUTILSDllExport
void APPUTILSDataVector_delete(struct APPUTILSDataVector *self);

extern APPUTILSDllExport
struct APPUTILSDataVector * APPUTILSDataVector_new(
        const struct APPUTILSDataVectorGenerator *data_generator,
        const struct REDAFastBufferPoolGrowthProperty *growth_property);

#endif /* apputils_data_vector_h */
