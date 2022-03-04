/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)netio_test_impl.h    generated by: makeheader    Fri Nov 15 12:22:12 2019
 *
 *		built from:	test_impl.ifc
 */

#ifndef netio_test_impl_h
#define netio_test_impl_h



#ifndef reda_buffer_h
#include "reda/reda_buffer.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


  #define RTI_NETIO_TEST_SETTING_DEFAULT { \
    RTI_TEST_SETTING_DEFAULT, \
    0}

  #define RTI_NETIO_TEST_SETTING_IOV_COMBINATION_COUNT_MAX (6)
  #define testM(index) (RTI_NETIO_TEST_SETTING_IOV_COMBINATION[index][0])
  #define testN(index) (RTI_NETIO_TEST_SETTING_IOV_COMBINATION[index][1])
  #define RTI_NETIO_TEST_SETTING_IOV_COUNT_MAX (32)
  #define RTI_NETIO_TEST_SETTING_BUFFER_SIZE_SMALL (32)
  #define RTI_NETIO_TEST_SETTING_BUFFER_SIZE_LARGE (1024)

extern int RTI_NETIO_TEST_SETTING_IOV_COMBINATION[
    RTI_NETIO_TEST_SETTING_IOV_COMBINATION_COUNT_MAX][2];

extern char RTI_NETIO_TESTER_SMALL_STORAGE[
    RTI_NETIO_TEST_SETTING_IOV_COUNT_MAX-1][
	RTI_NETIO_TEST_SETTING_BUFFER_SIZE_SMALL];

extern char RTI_NETIO_TESTER_LARGE_STORAGE[
    RTI_NETIO_TEST_SETTING_BUFFER_SIZE_LARGE];

extern char RTI_NETIO_TESTER_RECEIVE_STORAGE[
    RTI_NETIO_TEST_SETTING_BUFFER_SIZE_LARGE];

struct REDABuffer RTI_NETIO_TESTER_SEND_BUFFER[
    RTI_NETIO_TEST_SETTING_IOV_COUNT_MAX];


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* netio_test_impl_h */
