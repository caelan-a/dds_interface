/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_epoch_impl.h    generated by: makeheader    Fri Apr 23 00:10:54 2021
 *
 *		built from:	epoch_impl.ifc
 */

#ifndef reda_epoch_impl_h
#define reda_epoch_impl_h


#ifdef __cplusplus
    extern "C" {
#endif


  #define REDAEpoch_isGreater(me, value) \
    (((value) - (me)) >= REDA_EPOCH_HALF_VALUE)

  #define REDAEpoch_isLess(me, value) \
    (((me) - (value)) >= REDA_EPOCH_HALF_VALUE)


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* reda_epoch_impl_h */
