/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_dynamic_data_converter_h
#define apputils_dynamic_data_converter_h

#ifndef dds_c_dynamicdata_h
  #include "dds_c/dds_c_dynamicdata.h"
#endif

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

struct APPUTILSDynamicDataConverter;

extern APPUTILSDllExport
DDS_DynamicData * APPUTILSDynamicDataConverter_get_sample(
        struct APPUTILSDynamicDataConverter *self,
        DDS_DynamicData *sample,
        DDS_DataRepresentationId_t target_representation);

extern APPUTILSDllExport
void* APPUTILSDynamicDataConverter_get_buffer(
        struct APPUTILSDynamicDataConverter *self,
        DDS_UnsignedLong *buffer_length,
        DDS_DynamicData *sample,
        DDS_DataRepresentationId_t target_representation);

extern APPUTILSDllExport
void APPUTILSDynamicDataConverter_return_sample(
        struct APPUTILSDynamicDataConverter *self,
        DDS_DynamicData *sample);

extern APPUTILSDllExport
void APPUTILSDynamicDataConverter_return_buffer(
        struct APPUTILSDynamicDataConverter *self,
        void *buffer);

extern APPUTILSDllExport
void APPUTILSDynamicDataConverter_finalize(
        struct APPUTILSDynamicDataConverter *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSDynamicDataConverter_initialize(
        struct APPUTILSDynamicDataConverter *self,
        const DDS_TypeCode *type_code,
        DDS_UnsignedLong sampleBufferMinSize);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* apputils_dynamic_data_converter_h */
