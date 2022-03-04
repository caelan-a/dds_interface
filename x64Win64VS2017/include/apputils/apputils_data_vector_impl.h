/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_data_vector_impl_h
#define apputils_data_vector_impl_h

#ifndef apputils_data_vector_h
  #include "apputils/apputils_data_vector.h"
#endif

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif


struct APPUTILSDataVector {
    /*i @brief array */
    struct APPUTILSDynamicArray _array;
    /*i @brief data generator */
    struct APPUTILSDataVectorGenerator _dataGenerator;
};

#endif /* apputils_data_vector_impl_h */
