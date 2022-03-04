/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)recordingservice_storagereader.h    generated by: makeheader    Fri Apr 23 01:05:41 2021
 *
 *		built from:	storagereader.ifc
 */

#ifndef recordingservice_storagereader_h
#define recordingservice_storagereader_h



#ifndef dds_c_infrastructure_h
  #include "dds_c/dds_c_infrastructure.h"
#endif


#ifndef routingservice_adapter_h
  #include "routingservice/routingservice_adapter_new.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif




#define RTI_RecordingServiceStreamInfo RTI_RoutingServiceStreamInfo
#define RTI_RecordingServiceSample RTI_RoutingServiceSample
#define RTI_RecordingServiceSampleInfo RTI_RoutingServiceSampleInfo


struct RTI_RecordingServiceStorageReader;


struct RTI_RecordingServiceStorageStreamInfoReader;



#define RTI_RECORDING_SERVICE_DOMAIN_ID_PROPERTY_NAME \
        "rti.recording_service.domain_id"
#define RTI_RECORDING_SERVICE_START_TIMESTAMP_PROPERTY_NAME \
        "rti.recording_service.start_timestamp"
#define RTI_RECORDING_SERVICE_END_TIMESTAMP_PROPERTY_NAME \
        "rti.recording_service.end_timestamp"
#define RTI_RECORDING_SERVICE_JUMP_TIMESTAMP_PROPERTY_NAME \
        "rti.recording_service.jump_timestamp"
#define RTI_RECORDING_SERVICE_PLAYBACK_SAMPLE_ORDER_PROPERTY_NAME \
        "rti.recording_service.playback_settings.sample_order"

#define RTI_RecordingServiceSampleStateMask DDS_SampleStateMask
#define RTI_RecordingServiceTime DDS_Time_t



struct RTI_RecordingServiceHistoryState {
    
    /**
     * The number of historical samples to read. Note: currently the only depth
     * supported by \replay_product is 1, meaning the last value for every 
     * instance should be provided.
     */
    int depth;
};


struct RTI_RecordingServiceSelectorState {

    /*i @brief State that the samples to read must meet. Possible values:
     *         - DDS_NOT_READ_SAMPLE_STATE: indicates that all samples returned
     *           should not have been returned previously by a read() call.
     *         - DDS_READ_SAMPLE_STATE: indicates that all samples returned
     *           should have been returned previously by a read() call.
     *           Note: this kind is not currently used by Replay/Converter so
     *           it can be ignored.
     *         - DDS_ANY_SAMPLE_STATE: indicates that all samples within the
     *           specified constraints (e.g. time range) should be returned no
     *           matter whether they have been returned by a read() call before.
     */
    RTI_RecordingServiceSampleStateMask sample_state;

    /*i @brief The lower bound of the time range. Samples returned must have a
     *         timestamp greater or equal than this value. A value equal to
     *         DDS_TIME_ZERO can be received and means that there is no lower
     *         bound specified for the time range.
     */
    struct RTI_RecordingServiceTime time_range_start;

    /*i @brief The upper bound of the time range. Samples returned must have a
     *         timestamp lower or equal than this value. A value equal to
     *         DDS_TIME_MAX can be received and means that there is no upper
     *         bound specified for the time range.
     */
    struct RTI_RecordingServiceTime time_range_end;

    /*i @brief Maximum number of samples to be returned by a single call to
     *         read(), when positive. A negative value indicates an unlimited
     *         number of samples can be returned.
     *         Default: 1024 samples
     */
    int max_samples;
    
    /*i @brief Historical reading of instances. If a positive value is provided,
     *         the reader should provide the last values for every instance that
     *         was alive within the specified time range. Note: currently, just
     *         a depth of 1 is supported, and \replay_product will only use this 
     *         field with that depth, or 0 or negative, meaning that this type 
     *         of reading is disabled.
     */
    struct RTI_RecordingServiceHistoryState instance_history;
};



#define RTI_RecordingServiceSelectorState_MAX_SAMPLES_DEFAULT 1024

#define RTI_RecordingServiceHistoryState_NO_HISTORY_DEPTH 0

#define RTI_RecordingServiceHistoryState_INITIALIZER { \
        RTI_RecordingServiceHistoryState_NO_HISTORY_DEPTH \
}

#define RTI_RecordingServiceSelectorState_INITIALIZER { \
        DDS_ANY_SAMPLE_STATE, \
        DDS_TIME_ZERO, \
        DDS_TIME_MAX, \
        RTI_RecordingServiceSelectorState_MAX_SAMPLES_DEFAULT, \
        RTI_RecordingServiceHistoryState_INITIALIZER \
}



typedef void (*RTI_RecordingServiceStorageStreamInfoReader_ReadFcn)(
        void *stream_reader_data,
        struct RTI_RecordingServiceStreamInfo ***stream_info_array,
        int *count,
        const struct RTI_RecordingServiceSelectorState *selector);


typedef void (*RTI_RecordingServiceStorageStreamInfoReader_ReturnLoanFcn)(
        void *stream_reader_data,
        struct RTI_RecordingServiceStreamInfo **stream_info_array,
        const int count);


typedef long long
        (*RTI_RecordingServiceStorageStreamInfoReader_GetServiceStartTimeFcn)(
                void *stream_reader_data);


typedef long long
        (*RTI_RecordingServiceStorageStreamInfoReader_GetServiceStopTimeFcn)(
                void *stream_reader_data);


typedef int (*RTI_RecordingServiceStorageStreamInfoReader_FinishedFcn)(
        void *stream_reader_data);


typedef void (*RTI_RecordingServiceStorageStreamInfoReader_ResetFcn)(
        void *stream_reader_data);


struct RTI_RecordingServiceStorageStreamInfoReader {

    /*e @brief \replay_product calls this to retrieve data from the plugin about
     *  the streams that are stored.  After \replay_product takes a stream, the
     *  plugin should not notify \replay_product about the same stream. (required)
     */
    RTI_RecordingServiceStorageStreamInfoReader_ReadFcn read;

    /*e @brief \replay_product calls this to notify the plugin that it is no longer
     *  using the stream information, and the plugin can clean up the memory
     *  associated with the stream information. (required)
     */
    RTI_RecordingServiceStorageStreamInfoReader_ReturnLoanFcn return_loan;

    /*e @brief \replay_product calls this to determine the first timestamp in the
     *  recorded data. (required)
     */
    RTI_RecordingServiceStorageStreamInfoReader_GetServiceStartTimeFcn
            get_service_start_time;

    /*e @brief \replay_product calls this to determine the last timestamp in the
     *  recorded data. (required)
     */
    RTI_RecordingServiceStorageStreamInfoReader_GetServiceStopTimeFcn
            get_service_stop_time;

    /*e @brief \replay_product calls this to check if there is more discovery
     *  data available. (required)
     */
    RTI_RecordingServiceStorageStreamInfoReader_FinishedFcn finished;

    /*e @brief \replay_product calls this when looping is active and starts
     *  over. (required)
     *
     *  After this method is called, the stream reader should be ready to read
     *  again from the beginning of the stream.
     *
     */
    RTI_RecordingServiceStorageStreamInfoReader_ResetFcn reset;


    /*e @brief Data that the plugin can specify when the
     *  RTI_RecordingServiceStorageStreamInfoReader is created.  Passed
     *  to all discovery stream reader functions.
     */
    void *stream_reader_data;

};


#define RTI_RecordingServiceStorageStreamInfoReader_initialize(stream_reader) \
{\
    (stream_reader)->read = NULL; \
    (stream_reader)->return_loan = NULL; \
    (stream_reader)->get_service_start_time = NULL; \
    (stream_reader)->get_service_stop_time = NULL; \
    (stream_reader)->finished = NULL; \
    (stream_reader)->reset = NULL; \
    (stream_reader)->stream_reader_data = NULL; \
}


typedef void (*RTI_RecordingServiceStorageStreamReader_ReadFcn)(
        void *stream_reader_data,
        RTI_RecordingServiceSample **samples,
        RTI_RecordingServiceSampleInfo **sample_info_array,
        int *count,
        const struct RTI_RecordingServiceSelectorState *selector);


typedef void (*RTI_RecordingServiceStorageStreamReader_ReturnLoanFcn)(
        void *stream_reader_data,
        RTI_RecordingServiceSample *samples,
        RTI_RecordingServiceSampleInfo *sample_infos,
        int count);


typedef int (*RTI_RecordingServiceStorageStreamReader_FinishedFcn)(
        void *stream_reader_data);


typedef void (*RTI_RecordingServiceStorageStreamReader_ResetFcn)(
        void *stream_reader_data);


struct RTI_RecordingServiceStorageStreamReader {

    /*e @brief \replay_product calls this to retrieve data from the plugin from one
     *  stream (Topic).  (required)
     */
    RTI_RecordingServiceStorageStreamReader_ReadFcn read;

    /*e @brief \replay_product calls this to notify the plugin that it can free or
     *  reuse objects passed to \replay_product in the take call. (required)
     */
    RTI_RecordingServiceStorageStreamReader_ReturnLoanFcn return_loan;

    /*e @brief \replay_product calls this to check if there is more data available
        for a particular stream. (required)
     */
    RTI_RecordingServiceStorageStreamReader_FinishedFcn finished;

    /*e @brief \replay_product calls this when looping is active, to start
     *  over. (required)
     */
    RTI_RecordingServiceStorageStreamReader_ResetFcn reset;

    /*e @brief Data that the plugin can specify when the
     *  RTI_RecordingServiceStorageStreamReader is created.  Passed
     *  to all stream reader functions.
     */
    void *stream_reader_data;
};


#define RTI_RecordingServiceStorageStreamReader_initialize(stream_reader) \
{\
    (stream_reader)->read = NULL; \
    (stream_reader)->return_loan = NULL; \
    (stream_reader)->finished = NULL; \
    (stream_reader)->reset = NULL; \
    (stream_reader)->stream_reader_data = NULL; \
}


typedef void (*RTI_RecordingServiceStorageReader_DeleteStreamInfoReaderFcn)(
        void *storage_reader_data,
        struct RTI_RecordingServiceStorageStreamInfoReader *stream_reader);


typedef struct RTI_RecordingServiceStorageStreamInfoReader *
(*RTI_RecordingServiceStorageReader_CreateStreamInfoReaderFcn)(
        void *storage_reader_data,
        const struct RTI_RoutingServiceProperties *properties);


typedef void (*RTI_RecordingServiceStorageReader_DeleteStreamReaderFcn)(
        void *storage_reader_data,
        struct RTI_RecordingServiceStorageStreamReader *stream_reader);


typedef struct RTI_RecordingServiceStorageStreamReader *
(*RTI_RecordingServiceStorageReader_CreateStreamReaderFcn)(
        void *storage_reader_data,
        const struct RTI_RecordingServiceStreamInfo *stream_info,
        const struct RTI_RoutingServiceProperties *properties);


typedef void (*RTI_RecordingServiceStorageReader_DeleteFcn)(
        struct RTI_RecordingServiceStorageReader *storage_reader);


struct RTI_RecordingServiceStorageReader {

    /*e @brief \replay_product calls this to create a stream that will discover
     *  and read information about the user-data streams in the storage.
     *  (required)
     */
    RTI_RecordingServiceStorageReader_CreateStreamInfoReaderFcn create_stream_info_reader;

    /*e @brief \replay_product calls this to delete a stream information
     *  discovery reader.
     *  (required)
     */
    RTI_RecordingServiceStorageReader_DeleteStreamInfoReaderFcn delete_stream_info_reader;

    /*e @brief \replay_product calls this to create a user-data stream reader.
     *  (required)
     */
    RTI_RecordingServiceStorageReader_CreateStreamReaderFcn create_stream_reader;

    /*e @brief \replay_product calls this to delete a user-data stream reader.
     *  (required)
     */
    RTI_RecordingServiceStorageReader_DeleteStreamReaderFcn delete_stream_reader;

    /*e @brief \replay_product calls this to delete the storage reader object.
     *  (required)
     */
    RTI_RecordingServiceStorageReader_DeleteFcn delete_instance;

    /*e @brief Data that the plugin can specify when the
     *  RTI_RecordingServiceStorageReader is created.  Passed
     *  to all storage reader functions.
     */
    void *storage_reader_data;
};


#define RTI_RecordingServiceStorageReader_initialize(storage_reader) \
{\
    (storage_reader)->create_stream_info_reader = NULL; \
    (storage_reader)->delete_stream_info_reader = NULL; \
    (storage_reader)->create_stream_reader = NULL; \
    (storage_reader)->delete_stream_reader = NULL; \
    (storage_reader)->delete_instance = NULL; \
    (storage_reader)->storage_reader_data = NULL; \
}


typedef struct RTI_RecordingServiceStorageReader *
        (*RTI_RecordingServiceStorageReader_CreateFcn)(
                const struct RTI_RoutingServiceProperties *properties);


  #ifdef __cplusplus
    }   /* extern "C" */
  #endif

#endif /* recordingservice_storagereader_h */
