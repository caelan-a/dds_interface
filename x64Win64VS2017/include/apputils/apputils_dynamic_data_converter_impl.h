/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/
#ifndef apputils_dynamic_data_converter_impl_h
#define apputils_dynamic_data_converter_impl_h

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

#ifndef apputils_dynamic_data_converter_h
  #include "apputils/apputils_dynamic_data_converter.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif

struct APPUTILSDynamicDataConverter {
    void *_minSizeBuffer;
    void *_dynamicBuffer;
    DDS_DynamicData _threshold;
    DDS_DynamicData _large;
    DDS_UnsignedLong _sampleBufferMinSize;
};


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* apputils_dynamic_data_converter_impl_h */
