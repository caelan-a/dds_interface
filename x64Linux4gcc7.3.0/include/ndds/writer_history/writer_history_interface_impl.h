/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)writer_history_interface_impl.h    generated by: makeheader    Fri Nov 15 12:22:22 2019
 *
 *		built from:	interface_impl.ifc
 */

#ifndef writer_history_interface_impl_h
#define writer_history_interface_impl_h


#ifdef __cplusplus
    extern "C" {
#endif


#define NDDS_WriterHistory_Property_initialize(self) \
    RTIOsapiMemory_zero(self, sizeof(struct NDDS_WriterHistory_Property))


#define NDDS_WriterHistory_Property_finalize(self) \
    RTIOsapiMemory_zero(self, sizeof(struct NDDS_WriterHistory_Property))


#define NDDS_WriterHistory_Property_copy(to, src) \
    RTIOsapiMemory_copy((to), (src), sizeof(struct NDDS_WriterHistory_Property)); \
    /* SEC-248: cryptoTokens don't always need to be copied. The plugin will
       decide whether and how it's copied. */ \
    (to)->cryptoTokens.length = 0; \
    (to)->cryptoTokens.pointer = NULL


#define NDDS_WriterHistory_OriginalWriterInfo_equals(self,other) \
    ((RTIOsapiMemory_compare(self,other,sizeof(struct NDDS_WriterHistory_OriginalWriterInfo)) == 0)?RTI_TRUE:RTI_FALSE)


#define NDDS_WriterHistory_Listener_initialize(listener) \
    listener->listener_data = NULL; \
    listener->initialize_sample = NULL; \
    listener->finalize_sample = NULL; \
    listener->initialize_instance = NULL; \
    listener->finalize_instance = NULL; \
    listener->close_batch = NULL; \
    listener->finalize_sample_in_batch = NULL; \
    listener->allocator.getBuffer = NULL; \
    listener->allocator.returnBuffer = NULL; \
    listener->allocator.newAllocator = NULL; \
    listener->allocator.deleteAllocator = NULL; \
    listener->get_sample_serialized_size = NULL


#define NDDS_WriterHistory_Listener_is_valid(listener,batching) \
    ((listener->initialize_instance == NULL) ? RTI_FALSE :\
    ((listener->initialize_sample == NULL) ? RTI_FALSE :\
    ((batching == RTI_TRUE && listener->finalize_sample_in_batch == NULL) ? RTI_FALSE :\
    ((batching == RTI_TRUE && listener->close_batch == NULL) ? RTI_FALSE :\
    (((listener->allocator.getBuffer == NULL || listener->allocator.returnBuffer == NULL) \
           && ((listener->allocator.getBufferWithParams == NULL || \
                   listener->allocator.returnBufferWithParams == NULL))) ? RTI_FALSE :\
    RTI_TRUE)))))

struct NDDS_WriterHistory_Context {
    struct REDAWorkerFactory * wf;
    struct RTIClock * clock;
};


#define NDDS_WRITERHISTORY_MEMORY_PLUGIN_NAMESPACE "dds.data_writer.history.memory_plugin"


#define NDDS_WRITERHISTORY_ODBC_PLUGIN_NAMESPACE "dds.data_writer.history.odbc_plugin"


#define NDDS_WRITERHISTORY_BUILTIN_MEMORY_PLUGIN_NAME  NDDS_WRITERHISTORY_MEMORY_PLUGIN_NAMESPACE".builtin"


#define NDDS_WRITERHISTORY_BUILTIN_ODBC_PLUGIN_NAME NDDS_WRITERHISTORY_ODBC_PLUGIN_NAMESPACE".builtin"


#define NDDS_WRITERHISTORY_PLUGIN_NAME_PROPERTY "dds.data_writer.history.plugin_name"


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* writer_history_interface_impl_h */
