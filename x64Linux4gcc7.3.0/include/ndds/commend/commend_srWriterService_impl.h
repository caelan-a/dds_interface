/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)commend_srWriterService_impl.h    generated by: makeheader    Fri Nov 15 12:22:18 2019
 *
 *		built from:	srWriterService_impl.ifc
 */

#ifndef commend_srWriterService_impl_h
#define commend_srWriterService_impl_h


#ifndef osapi_bufferUtils_h
  #include "osapi/osapi_bufferUtils.h"
#endif
#ifndef mig_rtps_h
  #include "mig/mig_rtps.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif


/* ---------------------------------------------------------------- */
#define COMMENDSrWriterServiceProperty_copy(to, from) \
   RTIOsapiMemory_copy(to, from, sizeof(struct COMMENDSrWriterServiceProperty))

/* ---------------------------------------------------------------- */
#define COMMENDSrWriterServiceWriterProperty_copy(to, from) \
   RTIOsapiMemory_copy(to, from,                            \
                       sizeof(struct COMMENDSrWriterServiceWriterProperty))

/* ---------------------------------------------------------------- */
#define COMMENDSrWriterServiceRemoteReaderProperty_copy(to, from) \
   RTIOsapiMemory_copy(to, from,                                  \
              sizeof(struct COMMENDSrWriterServiceRemoteReaderProperty))


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* commend_srWriterService_impl_h */
