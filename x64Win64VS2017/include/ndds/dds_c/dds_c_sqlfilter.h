/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_sqlfilter.h    generated by: makeheader    Fri Apr 23 00:06:07 2021
 *
 *		built from:	sqlfilter.ifc
 */

#ifndef dds_c_sqlfilter_h
#define dds_c_sqlfilter_h


  #ifndef property_propertyNames_h
    #include "property/property_propertyNames.h"
  #endif
  #ifndef dds_c_sequence_h
     #include "dds_c/dds_c_sequence.h"
  #endif
  #ifndef dds_c_infrastructure_h
    #include "dds_c/dds_c_infrastructure.h"
  #endif
  #ifndef dds_c_dll_h
#include "dds_c/dds_c_dll.h"
  #endif
  #ifndef dds_c_topic_h
    #include "dds_c/dds_c_topic.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif


#define DDS_CONTENT_FILTER_SQL_DESERIALIZED_SAMPLE_MIN_BUFFER_SIZE_PROPERTY_NAME \
    PROPERTY_NAME_DDS_CONTENT_FILTER_SQL_DESERIALIZED_SAMPLE_MIN_BUFFER_SIZE
#define DDS_CONTENT_FILTER_SQL_DESERIALIZED_SAMPLE_TRIM_TO_SIZE_PROPERTY_NAME \
    PROPERTY_NAME_DDS_CONTENT_FILTER_SQL_DESERIALIZED_SAMPLE_TRIM_TO_SIZE


#define DDS_SQLFILTER_RETCODE_OK                     0
#define DDS_SQLFILTER_RETCODE_SYNTAX_ERROR          -1
#define DDS_SQLFILTER_RETCODE_TYPES_NOT_COMPATIBLE  -2
#define DDS_SQLFILTER_RETCODE_PARAM_EXHAUSTED       -3
#define DDS_SQLFILTER_RETCODE_LABEL_EXHAUSTED       -4
#define DDS_SQLFILTER_RETCODE_PARSE_EXHAUSTED       -5
#define DDS_SQLFILTER_RETCODE_PROGRAM_EXHAUSTED     -6
#define DDS_SQLFILTER_RETCODE_UNKNOWN_PARAM_USED    -7
#define DDS_SQLFILTER_RETCODE_COMPARISON_INVALID    -8
#define DDS_SQLFILTER_RETCODE_INVALID_LOOKUP        -9
#define DDS_SQLFILTER_RETCODE_INVALID_FREE          -10
#define DDS_SQLFILTER_RETCODE_INVALID_QOS           -11
#define DDS_SQLFILTER_RETCODE_INVALID_COMPILER      -12
#define DDS_SQLFILTER_RETCODE_INVALID_PARAMSTRING   -13
#define DDS_SQLFILTER_RETCODE_INVALID_EXPRESSION    -14
#define DDS_SQLFILTER_RETCODE_INVALID_SYMBOL        -15
#define DDS_SQLFILTER_RETCODE_INVALID_NODE          -16
#define DDS_SQLFILTER_RETCODE_EMPTY_EXPRESSION      -17
#define DDS_SQLFILTER_RETCODE_NO_TYPECODE           -18

#define DDS_SQLFILTER_SYMBOL_TYPE_INT              0
#define DDS_SQLFILTER_SYMBOL_TYPE_FLOAT            1
#define DDS_SQLFILTER_SYMBOL_TYPE_STRING           2
#define DDS_SQLFILTER_SYMBOL_LOCATION_IMMEDIATE    0
#define DDS_SQLFILTER_SYMBOL_LOCATION_RELATIVE     1
#define DDS_SQLFILTER_SYMBOL_LOCATION_ABSOLUTE     2
#define DDS_SQLFILTER_SYMBOL_LOCATION_DREF         4

/* Dereference record commands
 * stop           - stop dereferencing
 * goto           - goto offset
 * goto_index     - goto offset and then index
 * add            - add to the current offset
 * disc_cond      - match discriminator with label
 * struct_realign - realign structure
 */
#define DDS_SQLFILTER_DREFCOMD_STOP            (0)
#define DDS_SQLFILTER_DREFCOMD_GOTO            (1)
#define DDS_SQLFILTER_DREFCOMD_GOTO_INDEX      (2)
#define DDS_SQLFILTER_DREFCOMD_ADD             (3)
#define DDS_SQLFILTER_DREFCOMD_DISC_COND       (4)
#define DDS_SQLFILTER_DREFCOMD_ALIGN_STRUCT    (5)
#define DDS_SQLFILTER_DREFCOMD_SEQLENGTH_GE    (6)

#define DDS_SQLFILTER_DREFRECORD_INIT(_dref)\
(_dref)->current = 0;\
(_dref)->entry[0].cmd = 0xf000;\
(_dref)->entry[0].index = 0;\
(_dref)->entry[0].value = 0;\
(_dref)->entry[0].union_index = -1;\
(_dref)->entry[0].union_default = DDS_BOOLEAN_FALSE;\
(_dref)->entry[0].union_map = NULL;

#define DDS_SQLFILTER_DREF_ENTRY_ADD(__dref,\
                               __cmd,\
                               __repeat,\
                               __index,\
                               __value)\
if (((((__dref)->entry[(__dref)->current].cmd>>12)&0xf) != __cmd) ||\
    ((__cmd) == DDS_SQLFILTER_DREFCOMD_GOTO_INDEX)) {\
    if ((__dref)->entry[(__dref)->current].cmd != 0xf000)\
        ++(__dref)->current;\
    (__dref)->entry[(__dref)->current].cmd = (__cmd<<12) | (__repeat);\
    (__dref)->entry[(__dref)->current].index = __index;\
    (__dref)->entry[(__dref)->current].value = __value;\
    (__dref)->entry[(__dref)->current].union_index = -1;\
	(__dref)->entry[(__dref)->current].union_default = DDS_BOOLEAN_FALSE;\
	(__dref)->entry[(__dref)->current].union_map = NULL;\
} else {\
    int __r = (__dref)->entry[(__dref)->current].cmd&0xfff;\
    (__dref)->entry[(__dref)->current].cmd &= 0xf000;\
    (__dref)->entry[(__dref)->current].index = __index;\
    (__dref)->entry[(__dref)->current].value += __value;\
    (__dref)->entry[(__dref)->current].cmd |= (__repeat + __r);\
    (__dref)->entry[(__dref)->current].union_index = -1;\
	(__dref)->entry[(__dref)->current].union_default = DDS_BOOLEAN_FALSE;\
	(__dref)->entry[(__dref)->current].union_map = NULL;\
}

#define DDS_SQLFILTER_DREFRECORD_MAX    (32)
#define DDS_SQLFILTER_MAX_UNION_LABELS  (8)

typedef struct {
	char bytes[8];
} DDS_SqlFilterLongLong;

typedef struct {
	char bytes[8];
} DDS_SqlFilterUnsignedLongLong;


struct DDS_SqlTypeSupport_DynamicTypeLabel {
    DDS_Long label;
    DDS_Long index;
};

struct DDS_SqlFilterDereferenceEntry {
    DDS_UnsignedShort cmd;
    DDS_UnsignedShort index;
    DDS_Long            value;
	struct DDS_SqlTypeSupport_DynamicTypeLabel *union_map;
	DDS_Long union_index;
	DDS_Boolean union_default;
};

struct DDS_SqlFilterDereference {
    int current;
    struct DDS_SqlFilterDereferenceEntry entry[DDS_SQLFILTER_DREFRECORD_MAX];
};



union DDS_SqlFilterSymbolValue {
    int offset;
    void *address;
    DDS_Long  int_value;
    DDS_UnsignedLong uint_value;
    double double_value;
	DDS_SqlFilterLongLong longlong_value;
	DDS_SqlFilterUnsignedLongLong ulonglong_value;
    struct DDS_SqlFilterDereference dref_record;
};

typedef enum DDS_SqlFilterMetaFieldKind {
    DDS_SQL_FILTER_NO_META_FIELD,
    DDS_SQL_FILTER_RELATED_IDENTITY_GUID_FIELD,
    DDS_SQL_FILTER_RELATED_SOURCE_GUID_FIELD,
    DDS_SQL_FILTER_RELATED_READER_GUID_FIELD  
} DDS_SqlFilterMetaFieldKind;

struct DDS_SqlFilterSymbol {
    int type;
    DDS_UnsignedLong size;  /* size of an octet array */
    int location;
    union DDS_SqlFilterSymbolValue value;
    struct DDS_SqlFilterSymbol *upper;
    void *type_code;
    int is_key;
    DDS_SqlFilterMetaFieldKind meta_field_kind;
};

struct DDS_SqlFilterAlignmentQos {
    DDS_UnsignedShort char_alignment;
    DDS_UnsignedShort short_alignment;
    DDS_UnsignedShort long_alignment;
    DDS_UnsignedShort float_alignment;
    DDS_UnsignedShort double_alignment;
    DDS_UnsignedShort longlong_alignment;
    DDS_UnsignedShort longdouble_alignment;
    DDS_UnsignedShort pointer_alignment;
};


#define DDS_SQLFILTER_ALIGNMENT_INITIALIZE {0,0,0,0,0,0,0,0}

typedef struct DDS_SqlFilterSymbol*
    (*DDS_SqlFilterGeneratorSymbolLookupFunction)(char *name_start,
                                                  char *name_end,
                                                  void *dynamic_type,
                                                  DDS_Boolean allow_nonprimitive_ptrs);

typedef struct DDS_SqlFilterSymbol*
    (*DDS_SqlFilterGeneratorEnumLookupFunction)(char *name_start,
                                                char *name_end,
                                                void *symbol);

typedef void 
    (*DDS_SqlFilterGeneratorSymbolFreeFunction)(struct DDS_SqlFilterSymbol*);

struct DDS_SqlFilterMemoryManagementQos {
    DDS_Long buffer_min_size;
    DDS_Boolean trim_buffer;
};


#define DDS_SqlFilterMemoryManagementQos_INITIALIZER \
{                                                    \
    32768,                                           \
    DDS_BOOLEAN_FALSE                                \
}

struct DDS_SqlFilterGeneratorQos {
    int node_initial;
    int node_delta;
    int label_initial;
    int label_delta;
    int parameter_initial;
    int parameter_delta;
    int size_initial;
    int size_delta;
    int filter_serialized_data;
    struct DDS_SqlFilterAlignmentQos alignment;
    struct DDS_SqlFilterMemoryManagementQos memory_management;
    DDS_SqlFilterGeneratorSymbolLookupFunction symbol_lookup;
    DDS_SqlFilterGeneratorEnumLookupFunction enum_lookup;
    DDS_SqlFilterGeneratorSymbolFreeFunction symbol_free;
    REDACharacterEncodingKind character_encoding_kind;
    REDAUnicodeNormalizationKind normalization_kind;
    /* 
     * Internal: By default, content filters support escaped characters,
     * this can be turned off via a private property
     * for backwards compatibility. See CORE-5037 and CORE-10087
     */
    RTIBool supports_escaped_characters;
};

extern DDSCDllVariable struct DDS_SqlFilterGeneratorQos DDS_SQLFILTER_QOS_DEFAULT;

extern DDSCDllVariable struct DDS_SqlFilterGeneratorQos DDS_SQLFILTER_QOS_MIN;

extern DDSCDllVariable const char *const DDS_SQLFILTER_NAME;

extern DDSCDllVariable const char *const DDS_STRINGMATCHFILTER_NAME;

extern DDSCDllExport 
struct DDS_SqlFilterSymbol* DDS_SqlFilter_symbol_lookup(char *name_start,
                                                        char *name_end,
                                                        void* symbol,
                                                        DDS_Boolean allow_nonprimitive_ptrs);

extern DDSCDllExport 
struct DDS_SqlFilterSymbol* DDS_SqlFilter_enum_lookup(char *name_start,
                                                      char *name_end,
                                                      void* parent_type);

extern DDSCDllExport 
void DDS_SqlFilter_symbol_free(struct DDS_SqlFilterSymbol* s);

struct DDS_TypeCode;

extern DDSCDllExport DDS_ReturnCode_t
DDS_SqlFilter_compile(void *filter_data,
                      void **newHandle,
                      const char *expression,
                      const struct DDS_StringSeq *parameters,
                      const struct DDS_TypeCode *typeCode,
                      const char *typeClassName,
                      void *oldhandle);

extern DDSCDllExport DDS_Boolean
DDS_SqlFilter_evaluate(void *filterData, void *handle,
                       const void *sample, const struct DDS_FilterSampleInfo * meta_data);

extern DDSCDllExport DDS_Boolean
DDS_SqlFilter_evaluateOnSerialized(void *filterData, void *handle,
                                   const void *sample, const struct DDS_FilterSampleInfo * meta_data);

extern DDSCDllExport void
DDS_SqlFilter_finalize(void* filterData, void *handle);

extern DDSCDllExport DDS_Long
DDS_SqlFilter_query(void* filterData, void *handle);

extern DDSCDllExport DDS_ReturnCode_t
DDS_SqlFilter_writerCompile(void *filterData,
                            void *writerFilterData,
                            struct DDS_ExpressionProperty *prop,
                            const char *expression,
                            const struct DDS_StringSeq *parameters,
                            const struct DDS_TypeCode* typeCode,
                            const char* typeClassName,
                            const struct DDS_Cookie_t *cookie);

extern DDSCDllExport
struct DDS_CookieSeq * DDS_SqlFilter_writerEvaluate(void *filterData, 
                                                    void* writerFilterData, 
                                                    const void* sample,
                                                    const struct DDS_FilterSampleInfo * metaData);

extern DDSCDllExport
struct DDS_CookieSeq * DDS_SqlFilter_writerEvaluateOnSerialized(void *filter_data, 
                                                                void* writer_filter_data, 
                                                                const void* sample,
                                                                const struct DDS_FilterSampleInfo * meta_data);

extern DDSCDllExport
void DDS_SqlFilter_writerReturnLoan(void *filterData, 
                                    void* writerFilterData, 
                                    struct DDS_CookieSeq * cookies);

extern DDSCDllExport
void DDS_SqlFilter_writerFinalize(void *filterData, 
                                  void* writerFilterData,
                                  const struct DDS_Cookie_t *cookie);

extern DDSCDllExport DDS_ReturnCode_t
DDS_SqlFilter_writerAttach(void *filterData,void **writerFilterData,void*reserved);

extern DDSCDllExport 
void DDS_SqlFilter_writerDetach(void *filterData,void *writerFilterData);

 extern DDSCDllVariable const struct DDS_ContentFilter DDS_SQL_FILTER;

extern DDSCDllExport
void DDS_SqlTypeSupport_disable_legacy_impl(void);

extern DDSCDllExport
void DDS_SqlTypeSupport_enable_legacy_impl(void);

extern DDSCDllExport
DDS_Boolean DDS_SqlTypeSupport_legacy_impl_is_enabled(void);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_sqlfilter_h */
