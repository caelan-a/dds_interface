/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_dynamic_array_impl_h
#define apputils_dynamic_array_impl_h

#include "ndds/ndds_c.h"

#ifndef apputils_dynamic_array_h
  #include "apputils/apputils_dynamic_array.h"
#endif

struct APPUTILSDynamicArray
{
    /*i @brief array */
    void *_array;
    /*i @brief length of the array buffer.*/
    DDS_Long _arrayBufferLength;
    /*i @brief The number of elements in the array */
    DDS_Long _arrayLength;
    /*i @brief the size of the element type */
    DDS_Long _elementTypeSize;
    /*i @brief Growth policy */
    struct REDAFastBufferPoolGrowthProperty _growthProperty;
};

#endif /* apputils_dynamic_array_impl_h */
