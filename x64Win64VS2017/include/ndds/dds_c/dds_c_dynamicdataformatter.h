/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_dynamicdataformatter.h    generated by: makeheader    Fri Apr 23 00:05:59 2021
 *
 *		built from:	dynamicdataformatter.ifc
 */

#ifndef dds_c_dynamicdataformatter_h
#define dds_c_dynamicdataformatter_h


#ifndef dds_c_dynamicdata_h
  #include "dds_c/dds_c_dynamicdata.h"
#endif

#ifndef dds_c_dynamicdata_jsonparser_h
  #include "dds_c/dds_c_dynamicdata_jsonparser.h"
#endif

#ifndef dds_c_printformat_h
  #include "dds_c/dds_c_printformat.h"
#endif

#ifndef osapi_utility_h
  #include "osapi/osapi_utility.h"
#endif

#ifdef RTI_OSAPI_VSNPRINTF_SUPPORTED
  #define DDS_DYNAMICDATAFORMATTER_TO_STRING_SUPPORTED
#endif

#ifdef __cplusplus
  extern "C" {
#endif

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_print_w_params(
        const DDS_DynamicData *self,
        struct RTIXMLSaveContext *save_context,
        struct DDS_PrintFormat *print_format);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_print(
        const DDS_DynamicData *self,
        FILE *fp,
        int indent);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_to_string(
        const DDS_DynamicData *self,
        char *str,
        DDS_UnsignedLong *str_size,
        int indent);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_print_xml(
        const DDS_DynamicData *self,
        FILE *fp,
        int indent);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_to_xml(
        const DDS_DynamicData *self,
        char *str,
        DDS_UnsignedLong *str_size,
        int indent);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_print_json(
        const DDS_DynamicData *self,
        FILE *fp,
        int indent);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_to_json(
        const DDS_DynamicData *self,
        char *str,
        DDS_UnsignedLong *str_size,
        int indent);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_to_string_w_format(
        const DDS_DynamicData *self,
        char *str,
        DDS_UnsignedLong *str_size,
        DDS_PrintFormat *format);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_from_json(
        DDS_DynamicData *self,
        const char *str);

extern DDSCDllExport
DDS_ReturnCode_t DDS_DynamicDataFormatter_from_json_w_params(
        DDS_DynamicData *self,
        const char *str,
        DDS_UnsignedLong str_length,
        struct DDS_DynamicDataJsonParserProperties_t *properties);


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif /* dds_c_dynamicdataformatter_h */
