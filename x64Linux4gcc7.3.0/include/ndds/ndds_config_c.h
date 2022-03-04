/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)ndds_config_c.h    generated by: makeheader    Fri Nov 15 12:22:54 2019
 *
 *		built from:	ndds_config_c.ifc
 */

#ifndef ndds_config_c_h
#define ndds_config_c_h


  #include <stdlib.h>
  #include <stdio.h>


  #ifndef log_common_h
    #include "log/log_common.h"
  #endif
  #ifndef advlog_logger_h
    #include "advlog/advlog_logger.h"
  #endif

  #ifndef dds_c_dll_h
    #include "dds_c/dds_c_dll.h"
  #endif
  #ifndef dds_c_common_h
    #include "dds_c/dds_c_common.h"     /*for DDS_Boolean*/
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct NDDS_Config_LibraryVersion_t {
    /*e \dref_LibraryVersion_t_major */
    DDS_Long  major;
    
    /*e \dref_LibraryVersion_t_minor */
    DDS_Long  minor;
    
    /*e \dref_LibraryVersion_t_release */
    char release;
    
    /*e \dref_LibraryVersion_t_build */
    DDS_Long  build;
};

extern DDSCDllExport
const struct DDS_ProductVersion_t* NDDS_Config_Version_get_product_version(
        void);

extern DDSCDllExport
const struct NDDS_Config_LibraryVersion_t* NDDS_Config_Version_get_api_version(
        void);

extern DDSCDllExport
const struct NDDS_Config_LibraryVersion_t* NDDS_Config_Version_get_core_version(
        void);

extern DDSCDllExport
const char* NDDS_Config_Version_to_string(void);

extern DDSCDllExport const char*
NDDS_Config_Version_get_core_build_number_string();

extern DDSCDllExport const char*
NDDS_Config_Version_get_C_build_number_string();

typedef enum {
    /*e \dref_LogVerbosity_NDDS_CONFIG_LOG_VERBOSITY_SILENT */
    /*i Corresponds to RTI_LOG_BIT_SILENCE */
    NDDS_CONFIG_LOG_VERBOSITY_SILENT = RTI_LOG_BIT_SILENCE,
    
    /*e \dref_LogVerbosity_NDDS_CONFIG_LOG_VERBOSITY_ERROR */
    /*i Corresponds to RTI_LOG_BIT_EXCEPTION */
    NDDS_CONFIG_LOG_VERBOSITY_ERROR = RTI_LOG_BIT_EXCEPTION,
    
    /*e \dref_LogVerbosity_NDDS_CONFIG_LOG_VERBOSITY_WARNING */
    /*i Corresponds to RTI_LOG_BIT_EXCEPTION | RTI_LOG_BIT_WARN */
    NDDS_CONFIG_LOG_VERBOSITY_WARNING = NDDS_CONFIG_LOG_VERBOSITY_ERROR |
                                        RTI_LOG_BIT_WARN,
    
    /*e \dref_LogVerbosity_NDDS_CONFIG_LOG_VERBOSITY_STATUS_LOCAL */
    /*i Corresponds to RTI_LOG_BIT_EXCEPTION | RTI_LOG_BIT_WARN |
     * RTI_LOG_BIT_LOCAL
     */
    NDDS_CONFIG_LOG_VERBOSITY_STATUS_LOCAL
        = NDDS_CONFIG_LOG_VERBOSITY_WARNING | RTI_LOG_BIT_LOCAL,

    /*e \dref_LogVerbosity_NDDS_CONFIG_LOG_VERBOSITY_STATUS_REMOTE */
    /*i Corresponds to RTI_LOG_BIT_EXCEPTION | RTI_LOG_BIT_WARN |
     * RTI_LOG_BIT_LOCAL | RTI_LOG_BIT_REMOTE
     */
    NDDS_CONFIG_LOG_VERBOSITY_STATUS_REMOTE
        = NDDS_CONFIG_LOG_VERBOSITY_STATUS_LOCAL | RTI_LOG_BIT_REMOTE,

    /*e \dref_LogVerbosity_NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL */
    /*i Corresponds to RTI_LOG_BIT_EXCEPTION | RTI_LOG_BIT_WARN |
     * RTI_LOG_BIT_LOCAL | RTI_LOG_BIT_REMOTE | RTI_LOG_BIT_PERIODIC
     */
    NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL
        = NDDS_CONFIG_LOG_VERBOSITY_STATUS_REMOTE | RTI_LOG_BIT_PERIODIC
} NDDS_Config_LogVerbosity;

typedef enum {
    /*e \dref_LogLevel_NDDS_CONFIG_LOG_LEVEL_ERROR */
    NDDS_CONFIG_LOG_LEVEL_ERROR = RTI_LOG_LEVEL_ERROR,

    /*e \dref_LogLevel_NDDS_CONFIG_LOG_LEVEL_WARNING */
    NDDS_CONFIG_LOG_LEVEL_WARNING = RTI_LOG_LEVEL_WARNING,

    /*e \dref_LogLevel_NDDS_CONFIG_LOG_LEVEL_STATUS_LOCAL */
    NDDS_CONFIG_LOG_LEVEL_STATUS_LOCAL = RTI_LOG_LEVEL_STATUS_LOCAL,

    /*e \dref_LogLevel_NDDS_CONFIG_LOG_LEVEL_STATUS_REMOTE */
    NDDS_CONFIG_LOG_LEVEL_STATUS_REMOTE = RTI_LOG_LEVEL_STATUS_REMOTE,

    /*e \dref_LogLevel_NDDS_CONFIG_LOG_LEVEL_DEBUG */
    NDDS_CONFIG_LOG_LEVEL_DEBUG = RTI_LOG_LEVEL_DEBUG

} NDDS_Config_LogLevel;


#define NDDS_CONFIG_COUNT_LOG_LEVELS RTI_LOG_COUNT_LOG_LEVELS

typedef enum {
    /*e \dref_LogCategory_NDDS_CONFIG_LOG_CATEGORY_PLATFORM
     */
    NDDS_CONFIG_LOG_CATEGORY_PLATFORM,
    
    /*e \dref_LogCategory_NDDS_CONFIG_LOG_CATEGORY_COMMUNICATION
     */
    NDDS_CONFIG_LOG_CATEGORY_COMMUNICATION,
    
    /*e \dref_LogCategory_NDDS_CONFIG_LOG_CATEGORY_DATABASE
     */
    NDDS_CONFIG_LOG_CATEGORY_DATABASE,
    
    /*e \dref_LogCategory_NDDS_CONFIG_LOG_CATEGORY_ENTITIES
     */
    NDDS_CONFIG_LOG_CATEGORY_ENTITIES,
    
    /*e \dref_LogCategory_NDDS_CONFIG_LOG_CATEGORY_API
     */
    NDDS_CONFIG_LOG_CATEGORY_API,
    
    /*i \dref_LogCategory_NDDS_CONFIG_LOG_CATEGORY_ALL
     */
    NDDS_CONFIG_LOG_CATEGORY_ALL
} NDDS_Config_LogCategory;


#define NDDS_CONFIG_COUNT_LOG_CATEGORIES 5

typedef enum {
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_NUMBER
     */
    NDDS_CONFIG_LOG_PRINT_BIT_NUMBER = RTI_LOG_PRINT_BIT_NUMBER,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_MESSAGE
     */
    NDDS_CONFIG_LOG_PRINT_BIT_MESSAGE = RTI_LOG_PRINT_BIT_MSG,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_MODULE
     */
    NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_MODULE = RTI_LOG_PRINT_BIT_AT_MODULE,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_FILELINE
     */
    NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_FILELINE = RTI_LOG_PRINT_BIT_AT_FILE |
                                                  RTI_LOG_PRINT_BIT_AT_LINE,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_METHOD
     */
    NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_METHOD = RTI_LOG_PRINT_BIT_AT_METHOD,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_TIMESTAMP
     */
    NDDS_CONFIG_LOG_PRINT_BIT_TIMESTAMP = ADVLOG_PRINT_BIT_TIMESTAMP,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_THREAD_ID
     */
    NDDS_CONFIG_LOG_PRINT_BIT_THREAD_ID = ADVLOG_PRINT_BIT_THREAD_ID,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_CONTEXT
     */
    NDDS_CONFIG_LOG_PRINT_BIT_CONTEXT = ADVLOG_PRINT_BIT_CONTEXT,
    
    /*i \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_BIT_TWO_LINES
     */
    NDDS_CONFIG_LOG_PRINT_BIT_TWO_LINES = ADVLOG_PRINT_BIT_TWO_LINES,

    
    /*e \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_FORMAT_DEFAULT
     */
    NDDS_CONFIG_LOG_PRINT_FORMAT_DEFAULT =
        RTI_LOG_PRINT_FORMAT_DEFAULT |
        NDDS_CONFIG_LOG_PRINT_BIT_CONTEXT,

    /*e \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_FORMAT_TIMESTAMPED
     */
    NDDS_CONFIG_LOG_PRINT_FORMAT_TIMESTAMPED =
        NDDS_CONFIG_LOG_PRINT_FORMAT_DEFAULT |
        NDDS_CONFIG_LOG_PRINT_BIT_TIMESTAMP,

    /*e \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_FORMAT_VERBOSE
     */
    NDDS_CONFIG_LOG_PRINT_FORMAT_VERBOSE =
        NDDS_CONFIG_LOG_PRINT_BIT_MESSAGE |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_METHOD |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_MODULE |
        NDDS_CONFIG_LOG_PRINT_BIT_THREAD_ID |
        NDDS_CONFIG_LOG_PRINT_BIT_CONTEXT |
        NDDS_CONFIG_LOG_PRINT_BIT_TWO_LINES,

    /*e \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_FORMAT_VERBOSE_TIMESTAMPED
     */
    NDDS_CONFIG_LOG_PRINT_FORMAT_VERBOSE_TIMESTAMPED =
        NDDS_CONFIG_LOG_PRINT_FORMAT_VERBOSE |
        NDDS_CONFIG_LOG_PRINT_BIT_TIMESTAMP,

    /*e \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_FORMAT_DEBUG
     */
    NDDS_CONFIG_LOG_PRINT_FORMAT_DEBUG =
        NDDS_CONFIG_LOG_PRINT_BIT_NUMBER |
        NDDS_CONFIG_LOG_PRINT_BIT_MESSAGE |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_FILELINE |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_MODULE |
        NDDS_CONFIG_LOG_PRINT_BIT_THREAD_ID,

    /*e \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_FORMAT_MINIMAL
     */
    NDDS_CONFIG_LOG_PRINT_FORMAT_MINIMAL =
        NDDS_CONFIG_LOG_PRINT_BIT_NUMBER |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_METHOD,

    /*e \dref_LogPrintFormat_NDDS_CONFIG_LOG_PRINT_FORMAT_MAXIMAL
     */
    NDDS_CONFIG_LOG_PRINT_FORMAT_MAXIMAL =
        NDDS_CONFIG_LOG_PRINT_BIT_NUMBER |
        NDDS_CONFIG_LOG_PRINT_BIT_MESSAGE |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_METHOD |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_FILELINE |
        NDDS_CONFIG_LOG_PRINT_BIT_LOCATION_MODULE |
        NDDS_CONFIG_LOG_PRINT_BIT_THREAD_ID |
        NDDS_CONFIG_LOG_PRINT_BIT_CONTEXT |
        NDDS_CONFIG_LOG_PRINT_BIT_TIMESTAMP |
        NDDS_CONFIG_LOG_PRINT_BIT_TWO_LINES

} NDDS_Config_LogPrintFormat;

typedef enum {
    /*i \dref_LoggerMode_NDDS_CONFIG_LOGGER_MODE_DEFAULT,
     */
    NDDS_CONFIG_LOGGER_MODE_DEFAULT                  = 0x00,
    
    /*i \dref_LoggerMode_NDDS_CONFIG_LOGGER_MODE_DISABLE_STANDARD_DEVICES
     */
    NDDS_CONFIG_LOGGER_MODE_DISABLE_STANDARD_DEVICES = 0x01,
    
    /*i \dref_LoggerMode_NDDS_CONFIG_LOGGER_MODE_DISABLE_ADVANCED_LOGGING
     */
    NDDS_CONFIG_LOGGER_MODE_DISABLE_ADVANCED_LOGGING = 0x02

} NDDS_Config_LoggerMode;

typedef struct NDDS_Config_LoggerImpl NDDS_Config_Logger;


DDSC_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT(DDS_LoggingQosPolicy);

struct DDS_LoggingQosPolicy {
    /*e \dref_LoggingQosPolicy_verbosity
    */
    NDDS_Config_LogVerbosity verbosity;

    /*e \dref_LoggingQosPolicy_category
    */
    NDDS_Config_LogCategory category;

    /*e \dref_LoggingQosPolicy_print_format
    */
    NDDS_Config_LogPrintFormat print_format;   
    
    /*e \dref_LoggingQosPolicy_output_file
    */
    char * output_file;

    /*e \dref_LoggingQosPolicy_output_file_suffix
    */
    char * output_file_suffix;

    /*e \dref_LoggingQosPolicy_max_bytes_per_file
    */
    DDS_Long max_bytes_per_file;

    /*e \dref_LoggingQosPolicy_max_files
    */
    DDS_Long max_files;

    DDSCPP_VARIABLE_LENGTH_VALUE_TYPE_SUPPORT(DDS_LoggingQosPolicy)
};


#define DDS_LOGGING_QOS_POLICY_DEFAULT \
{ \
  NDDS_CONFIG_LOG_VERBOSITY_ERROR,\
  NDDS_CONFIG_LOG_CATEGORY_ALL,\
  NDDS_CONFIG_LOG_PRINT_FORMAT_DEFAULT,\
  NULL, \
  NULL, \
  -1, \
  -1 \
}

extern DDSCDllExport
DDS_Boolean DDS_LoggingQosPolicy_equals(
    const struct DDS_LoggingQosPolicy* left,
    const struct DDS_LoggingQosPolicy* right);

extern DDSCDllExport
NDDS_Config_Logger* NDDS_Config_Logger_get_instance(void);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_preinit();

extern DDSCDllExport
NDDS_Config_LogVerbosity NDDS_Config_Logger_get_verbosity(
    const NDDS_Config_Logger* self);

extern DDSCDllExport
NDDS_Config_LogVerbosity NDDS_Config_Logger_get_verbosity_by_category(
    const NDDS_Config_Logger* self, NDDS_Config_LogCategory category);

extern DDSCDllExport
void NDDS_Config_Logger_set_verbosity(
    NDDS_Config_Logger* self, NDDS_Config_LogVerbosity verbosity);

extern DDSCDllExport
void NDDS_Config_Logger_set_verbosity_by_category(
    NDDS_Config_Logger* self, NDDS_Config_LogCategory category,
    NDDS_Config_LogVerbosity verbosity);

typedef void (*NDDS_Config_LoggerSetExternalInstrumentationMaskFnc)(
    RTILogBitmap mask);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_external_communication_instrumentation_mask(
    NDDS_Config_LoggerSetExternalInstrumentationMaskFnc fPtr);

extern DDSCDllExport
FILE* NDDS_Config_Logger_get_output_file(NDDS_Config_Logger* self);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_output_file(NDDS_Config_Logger* self,
                                               FILE* out);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_output_file_name(NDDS_Config_Logger* self,
                                                    const char * file_name);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_output_file_set(
        NDDS_Config_Logger *self,
        const char *file_preffix,
        const char *file_suffix,
        int max_capacity,
        int max_files);

extern DDSCDllExport
NDDS_Config_LogPrintFormat NDDS_Config_Logger_get_print_format(
    const NDDS_Config_Logger* self);

extern DDSCDllExport
NDDS_Config_LogPrintFormat NDDS_Config_Logger_get_print_format_by_log_level(
        const NDDS_Config_Logger *self,
        NDDS_Config_LogLevel log_level);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_print_format(
    NDDS_Config_Logger* self, NDDS_Config_LogPrintFormat print_format);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_print_format_by_log_level(
        NDDS_Config_Logger *self,
        NDDS_Config_LogPrintFormat print_format,
        NDDS_Config_LogLevel log_level);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_mode(
    NDDS_Config_Logger* self, NDDS_Config_LoggerMode mode);

struct NDDS_Config_LogMessage {
    /*e \dref_LogMessage_text
     */
    const char *text;

    /*e \dref_LogMessage_level
     */    
    NDDS_Config_LogLevel level;
    
    /*e \dref_LogMessage_is_security_message
     */
    DDS_Boolean is_security_message;
};

struct NDDS_Config_LoggerDevice;

typedef void (*NDDS_Config_LoggerDeviceWriteFnc)(
        struct NDDS_Config_LoggerDevice *device,
        const struct NDDS_Config_LogMessage *message);

typedef void (*NDDS_Config_LoggerDeviceCloseFnc)(
        struct NDDS_Config_LoggerDevice *device);


struct NDDS_Config_LoggerDevice {
    /*ci \dref_LoggerDevice_device_data
     * Device instance data.
     */
    void *device_data;
    /*ce \dref_LoggerDevice_write
     */
    NDDS_Config_LoggerDeviceWriteFnc write;
    /*ce \dref_LoggerDevice_close
     */
    NDDS_Config_LoggerDeviceCloseFnc close;
};

extern DDSCDllExport
struct NDDS_Config_LoggerDevice *NDDS_Config_Logger_get_output_device(
    NDDS_Config_Logger* self);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_output_device(
    NDDS_Config_Logger* self,
    struct NDDS_Config_LoggerDevice *device);

extern DDSCDllExport
DDS_Boolean NDDS_Config_Logger_set_output_deviceI(
    NDDS_Config_Logger* self,
    int slot,
    struct NDDS_Config_LoggerDevice *device);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* ndds_config_c_h */
