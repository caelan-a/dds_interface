/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_sample_processor.h    generated by: makeheader    Fri Apr 23 00:06:06 2021
 *
 *		built from:	sample_processor.ifc
 */

#ifndef dds_c_sample_processor_h
#define dds_c_sample_processor_h



#ifndef dds_c_asyncwaitset_h
  #include "dds_c/dds_c_asyncwaitset.h"
#endif
#ifdef __cplusplus
    extern "C" {
#endif



typedef void (*DDS_SampleHandler_OnNewSampleCallback)(
        void *handler_data,
        const void *sample_data,
        const struct DDS_SampleInfo *sample_info);


#define DDS_SampleHandler_INITIALIZER { \
        NULL, \
        NULL}


struct DDS_SampleHandler {
    /*ce \dref_SampleHandler_handler_data
     */
    void *handler_data;

    /*ce \dref_SampleHandler_on_new_sample
     */
    DDS_SampleHandler_OnNewSampleCallback on_new_sample;
};


typedef struct DDS_SampleProcessorImpl
        DDS_SampleProcessor;

extern DDSCDllExport
DDS_ReturnCode_t
DDS_SampleProcessor_attach_reader(
        DDS_SampleProcessor *self,
        DDS_DataReader *reader,
        const struct DDS_SampleHandler *handler);

extern DDSCDllExport
DDS_ReturnCode_t
DDS_SampleProcessor_detach_reader(
        DDS_SampleProcessor *self,
        DDS_DataReader *reader);

extern DDSCDllExport
DDS_ReturnCode_t DDS_SampleProcessor_lookup_sample_handler(
        DDS_SampleProcessor *self,
        struct DDS_SampleHandler *handler_out,
        DDS_DataReader *reader);

extern DDSCDllExport
DDS_ReturnCode_t DDS_SampleProcessor_get_datareaders(
        DDS_SampleProcessor *self,
        struct DDS_DataReaderSeq *attached_readers);

extern DDSCDllExport
DDS_AsyncWaitSet *
DDS_SampleProcessor_get_aws(DDS_SampleProcessor *self);

extern DDSCDllExport
DDS_ReturnCode_t
DDS_SampleProcessor_delete(DDS_SampleProcessor *self);

extern DDSCDllExport
DDS_SampleProcessor*
DDS_SampleProcessor_new(const struct DDS_AsyncWaitSetProperty_t *aws_property);

extern DDSCDllExport
DDS_SampleProcessor*
DDS_SampleProcessor_new_with_aws(DDS_AsyncWaitSet *aws);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_sample_processor_h */
