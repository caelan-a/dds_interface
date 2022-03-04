/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_string_buffer_impl_h
#define apputils_string_buffer_impl_h


#include "ndds/ndds_c.h"

#ifndef apputils_dynamic_array_impl_h
  #include "apputils/apputils_dynamic_array_impl.h"
#endif

#ifndef apputils_string_buffer_h
  #include "apputils/apputils_string_buffer.h"
#endif

struct APPUTILSStringBuffer {

    /*i @brief dynamic byte array */
    struct APPUTILSDynamicArray _byteArray;
};

#endif /* apputils_string_buffer_impl_h */
