/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_xml.h    generated by: makeheader    Fri Apr 23 00:06:19 2021
 *
 *		built from:	xml.ifc
 */

#ifndef dds_c_xml_h
#define dds_c_xml_h


  #include <stdarg.h>


  #ifndef dds_c_dll_h
    #include "dds_c/dds_c_dll.h"
  #endif
  #ifndef dds_c_common_h
    #include "dds_c/dds_c_common.h"
  #endif
  #ifndef dds_c_typecode_h
    #include "dds_c/dds_c_typecode.h"
  #endif
  #ifndef rtixml_parser_h
    #include "rtixml/rtixml_parser.h"
  #endif
  #ifndef rtixml_infrastructure_h
    #include "rtixml/rtixml_infrastructure.h"
  #endif
  #ifndef dds_c_domain_h
    #include "dds_c/dds_c_domain.h"
  #endif
  #ifdef __cplusplus
    extern "C" {
  #endif


/* Forward declaration to avoid dependency on domain_impl header file */
struct DDS_DomainParticipantFactoryQosXMLInfo;


struct DDS_XMLContext {
    /*e
       \brief Opaque data that should not be touched 
    */
    void * _parser;
    /*e
      \brief This member is used to signal an error condition during the parsing process.
    */
    int error;
    /*e
      \brief This member is a read-only and provides the current parsing depth.

      The root of the XML document has depth 1
    */
    int depth;
    
    /*e 
     * \brief the current line number of the file. It allows override the values
     * provided by expat
    */
    int currentFileOffset;
    
    /*e 
     * \brief the line number offset for the current file context. It allows override the values
     * provided by expat
    */
    int currentFileGlobalOffset;
    
    /*e
      \brief User data. It makes it possible to pass information among extensions
      from different families
    */
    void * userData;
};


#define DDS_XMLContext_INITIALIZER       \
{                                        \
    NULL, /* _parser */                  \
    0,    /* error */                    \
    0,    /* depth */                    \
    0,    /* currentFileOffset */        \
    0,    /* currentFileGlobalOffset */  \
    NULL  /* userData */                 \
}

struct DDS_XMLExtensionClass;

struct DDS_XMLObject;

struct DDS_XMLDds;

struct DDS_XMLLibrary;

struct DDS_XMLQosProfile;

struct DDS_XMLParticipantQos;

struct DDS_XMLParticipantFactoryQos;

struct DDS_XMLPublisherQos;

struct DDS_XMLSubscriberQos;

struct DDS_XMLTopicQos;

struct DDS_XMLDataWriterQos;

struct DDS_XMLDataReaderQos;

struct DDS_XMLTypeCode;

struct DDS_XMLConst;

struct DDS_XMLDomainLibrary;

struct DDS_XMLDomain;

struct DDS_XMLRegisterType;

struct DDS_XMLTopic;

struct DDS_XMLParticipant;

struct DDS_XMLPublisher;

struct DDS_XMLSubscriber;

struct DDS_XMLDataWriter;

struct DDS_XMLDataReader;


struct DDS_XMLTypeCodeParser;


struct DDS_XMLParser;

extern DDSCDllExport
int DDS_XMLContext_get_current_line_number(struct DDS_XMLContext * context);

extern DDSCDllExport
const char * DDS_XMLHelper_get_attribute_value(const char ** attr_list, const char * name);

extern DDSCDllExport
void DDS_XMLHelper_str_to_boolean(
    DDS_Boolean * value, const char * str, struct DDS_XMLContext * context);

extern DDSCDllExport
void DDS_XMLHelper_str_to_int_with_interval(
    int * value, const char * str, int min, int max, struct DDS_XMLContext * context);

extern DDSCDllExport
void DDS_XMLHelper_str_to_unsigned_int(
    unsigned int * value, const char * str, struct DDS_XMLContext * context);

extern DDSCDllExport
void DDS_XMLHelper_str_to_int(
    int * value, const char * str, struct DDS_XMLContext * context);

extern DDSCDllExport
void DDS_XMLHelper_str_to_double(
    double * value, const char * str, struct DDS_XMLContext * context);

extern DDSCDllExport
void DDS_XMLHelper_str_to_thread_settings_kind_mask(
        DDS_ThreadSettingsKindMask * value,
        const char *tag_name,
        const char * str,
        struct DDS_XMLContext * context);


/*
 * This value should be used when we need to parse a unsupported string value
 * inside of a mask in order to fill the field maskValue from
 * DDS_XMLQosBitMaskValue.
 */
#define DDS_XML_QOS_BIT_MASK_VALUE_UNKNOWN (0)
#define DDS_XML_MAX_ACCEPTED_XML_VALUES     3

/*i
 * @brief Struct to handle a mask type while reading an XML.
 */
typedef struct DDS_XMLQosBitMaskValue {
    int mask_value;
    unsigned int num_accepted_xml_values;
    char *accepted_xml_values[DDS_XML_MAX_ACCEPTED_XML_VALUES];

    /*
     * The unsupported field identifies when a string value is not supported by
     * Pro, a warning will be printed.
     */
    DDS_Boolean unsupported;
} DDS_XMLQosBitMaskValue;

extern DDSCDllExport
DDS_Boolean DDS_XMLHelper_get_bitmask_values(
        DDS_UnsignedLong *mask,
        const char *tag_name,
        const char *element_text,
        const DDS_XMLQosBitMaskValue *bitmask_xml_values,
        const size_t num_bitmask_xml_values,
        struct RTIXMLContext *context);


#define DDS_XMLHELPER_SAVE_INDENT            (1 << 0)
#define DDS_XMLHELPER_SAVE_NEWLINE           (1 << 1)
#define DDS_XMLHELPER_SAVE_INC_AFTER         (1 << 2)
#define DDS_XMLHELPER_SAVE_DEC_BEFORE        (1 << 3)
#define DDS_XMLHELPER_SAVE_CLOSE_TAG         (1 << 4)

#define DDS_XMLHELPER_SAVE_TAG_START         (DDS_XMLHELPER_SAVE_NEWLINE | DDS_XMLHELPER_SAVE_INDENT | DDS_XMLHELPER_SAVE_INC_AFTER)
#define DDS_XMLHELPER_SAVE_TAG_END           (DDS_XMLHELPER_SAVE_NEWLINE | DDS_XMLHELPER_SAVE_INDENT | DDS_XMLHELPER_SAVE_DEC_BEFORE | DDS_XMLHELPER_SAVE_CLOSE_TAG)

#define DDS_XMLHELPER_CHECK_ERROR(x) if((x)->error) return
#define DDS_XMLHELPER_SET_ERROR(x) (x)->error = RTI_TRUE; return


extern DDSCDllExport
void DDS_XMLHelper_save_parameterized_string(const char * str,
                                             long params,
                                             struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_tag_parameterized(
        long params,
        struct RTIXMLSaveContext *dst,
        const char *format,
        ...);

extern DDSCDllExport
void DDS_XMLHelper_save_tag(const char * tag_name,
                            long params,
                            struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_octet_seq(
        const char * tag_name,
        const struct DDS_OctetSeq * self,
        const struct DDS_OctetSeq * base,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_octet_array(
        const char * tag_name,
        const DDS_Octet * self,
        DDS_Long length,
        const DDS_Octet * base,
        DDS_Long baselength,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_string(
        const char * tag_name,
        const char * text,
        const char * base,
        DDS_Boolean isPrivate,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_string_seq(
        const char * tag_name,
        const struct DDS_StringSeq * self,
        const struct DDS_StringSeq * base,
        DDS_Boolean isPrivate,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_bool(
        const char * tag_name,
        DDS_Boolean value,
        const DDS_Boolean *base,
        DDS_Boolean isPrivate,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_int(
        const char * tag_name,
        int value,
        const int *base,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_long(
        const char * tag_name,
        DDS_Long value,
        const DDS_Long *base,
        DDS_Boolean isPrivate,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_length(
        const char * tag_name,
        DDS_Long length,
        const DDS_Long *base,
        DDS_Boolean isPrivate,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_long_seq(
        const char * tag_name,
        const struct DDS_LongSeq * self,
        const struct DDS_LongSeq * base,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_short(
        const char *tag_name,
        DDS_Short value,
        const DDS_Short *base,
        struct RTIXMLSaveContext *dst);

extern DDSCDllExport
void DDS_XMLHelper_save_unsigned_short(
        const char *tag_name,
        DDS_UnsignedShort value,
        const DDS_UnsignedShort *base,
        struct RTIXMLSaveContext *dst);

extern DDSCDllExport
void DDS_XMLHelper_save_short_seq(
        const char *tag_name,
        const struct DDS_ShortSeq *self,
        const struct DDS_ShortSeq *base,
        struct RTIXMLSaveContext *dst);

extern DDSCDllExport
void DDS_XMLHelper_save_unsigned_long(
        const char *tag_name,
        DDS_UnsignedLong value,
        const DDS_UnsignedLong *base,
        struct RTIXMLSaveContext* dst);

extern DDSCDllExport
void DDS_XMLHelper_save_unsigned_long_as_hex(
        const char *tag_name,
        DDS_UnsignedLong value,
        const DDS_UnsignedLong *base,
        struct RTIXMLSaveContext *dst);

extern DDSCDllExport
void DDS_XMLHelper_save_sequence_number(
        const char * tag_name,
        const struct DDS_SequenceNumber_t *value,
        const struct DDS_SequenceNumber_t *base,
        struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_pointer(
        const char *tag_name,
        const void *value,
        const void *base,
        DDS_Boolean isPrivate,
        struct RTIXMLSaveContext *dst);

extern DDSCDllExport
const char * DDS_XMLHelper_get_qualified_base_name(struct DDS_XMLObject *self);

extern DDSCDllExport
void DDS_XMLHelper_save_comment_open(struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_comment_close(struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_ddsFooter(struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_ddsHeader(struct RTIXMLSaveContext * dst);

extern DDSCDllExport
void DDS_XMLHelper_save_xmlHeader(struct RTIXMLSaveContext * dst);

 
typedef void (*DDS_XMLExtensionClass_OnStartTagFunction)(
    struct DDS_XMLObject * self, 
    const char * tag_name,
    const char ** attr,
    struct DDS_XMLContext * context);

 
typedef void (*DDS_XMLExtensionClass_OnEndTagFunction)(
    struct DDS_XMLObject * self, 
    const char * tag_name,
    const char * element_text,
    struct DDS_XMLContext * context);

 
typedef struct DDS_XMLObject * (*DDS_XMLExtensionClass_NewObjectFunction)(
    const struct DDS_XMLExtensionClass * extension_class,
    const struct DDS_XMLObject * parent_object,
    const char ** attr,
    struct DDS_XMLContext * context);

 
typedef void (*DDS_XMLExtensionClass_DeleteObjectFunction)(
    struct DDS_XMLObject * self);

 
typedef void (*DDS_XMLExtensionClass_SaveObjectFunction)(
    struct DDS_XMLObject * self, struct RTIXMLSaveContext * dst);


extern	DDSCDllExport const char * DDS_XMLExtensionClass_get_tag_name(struct DDS_XMLExtensionClass * self);


extern	DDSCDllExport void * DDS_XMLExtensionClass_get_user_data(struct DDS_XMLExtensionClass * self);


extern	DDSCDllExport struct DDS_XMLExtensionClass * DDS_XMLExtensionClass_new(
    const char * tag_name,
    void * user_data,
    DDS_Boolean allow_duplicated_objects,
    DDS_Boolean is_root,
    DDS_XMLExtensionClass_OnStartTagFunction on_start_tag_fcn,
    DDS_XMLExtensionClass_OnEndTagFunction on_end_tag_fcn,
    DDS_XMLExtensionClass_NewObjectFunction new_object_fcn,
    DDS_XMLExtensionClass_DeleteObjectFunction delete_object_fcn,
    DDS_XMLExtensionClass_SaveObjectFunction save_object_fcn
    );


extern	DDSCDllExport void DDS_XMLExtensionClass_delete(struct DDS_XMLExtensionClass * self);


extern	DDSCDllExport void DDS_XMLExtensionClass_finalize(struct DDS_XMLExtensionClass * self);


extern	DDSCDllExport DDS_Boolean DDS_XMLExtensionClass_initialize(
    struct DDS_XMLExtensionClass * self,
    const char * tag_name,
    void * user_data,
    DDS_Boolean allow_duplicated_objects,
    DDS_Boolean is_root,
    DDS_XMLExtensionClass_OnStartTagFunction on_start_tag_fcn,
    DDS_XMLExtensionClass_OnEndTagFunction on_end_tag_fcn,
    DDS_XMLExtensionClass_NewObjectFunction new_object_fcn,
    DDS_XMLExtensionClass_DeleteObjectFunction delete_object_fcn,
    DDS_XMLExtensionClass_SaveObjectFunction save_object_fcn);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_lookup(struct DDS_XMLObject * self,
                                                          const char * name);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_get_prev_sibling(struct DDS_XMLObject * self);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_get_next_sibling(struct DDS_XMLObject * self);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_get_first_child(struct DDS_XMLObject * self);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_get_last_child(struct DDS_XMLObject * self);


extern	DDSCDllExport int DDS_XMLObject_get_child_count(struct DDS_XMLObject * self);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_get_root(struct DDS_XMLObject * self);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_get_parent(struct DDS_XMLObject * self);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLObject_get_base(struct DDS_XMLObject * self);


extern	DDSCDllExport const char * DDS_XMLObject_get_tag_name(struct DDS_XMLObject * self);


extern	DDSCDllExport const char * DDS_XMLObject_get_name(struct DDS_XMLObject * self);

 
extern	DDSCDllExport const char * DDS_XMLObject_get_fully_qualified_name(
        struct DDS_XMLObject * self);


extern	DDSCDllExport void DDS_XMLObject_save(struct DDS_XMLObject * self, 
                                      struct RTIXMLSaveContext * dst);


extern	DDSCDllExport void DDS_XMLObject_save_children(struct DDS_XMLObject * self, 
                                               struct RTIXMLSaveContext * dst);

extern DDSCDllExport 
struct DDS_XMLObject * DDS_XMLObject_get_first_child_with_tag(
                                    struct DDS_XMLObject * self,
                                    const char * child_tag_name);

extern DDSCDllExport
struct DDS_XMLObject * DDS_XMLObject_get_next_sibling_with_tag(
                                        struct DDS_XMLObject * self,
                                        const char * sibling_tag_name);

extern DDSCDllExport
struct DDS_XMLObject * DDS_XMLObject_get_prev_sibling_with_tag(
                                        struct DDS_XMLObject * self,
                                        const char * sibling_tag_name);

extern DDSCDllExport
struct DDS_XMLObject * DDS_XMLObject_lookup_child(struct DDS_XMLObject * self,
                                                  const char * child_name);

extern DDSCDllExport 
DDS_Boolean DDS_XMLObject_initialize(struct DDS_XMLObject * self,
                                     const struct DDS_XMLExtensionClass * extension_class,
                                     const struct DDS_XMLObject * parent_object,
                                     const char * name,
                                     const char * base_name);

extern DDSCDllExport 
void DDS_XMLObject_finalize(struct DDS_XMLObject * self);

extern DDSCDllExport 
const struct DDS_DomainParticipantQos * DDS_XMLParticipantQos_get_dds_qos(struct DDS_XMLParticipantQos * self);

extern DDSCDllExport 
const struct DDS_DomainParticipantFactoryQos * DDS_XMLParticipantFactoryQos_get_dds_qos(struct DDS_XMLParticipantFactoryQos * self,
                                                                                        struct DDS_DomainParticipantFactoryQosXMLInfo * out_factory_qos_xml_info);


extern	const DDSCDllExport struct DDS_TopicQos * DDS_XMLTopicQos_get_dds_qos(struct DDS_XMLTopicQos * self);

extern DDSCDllExport 
const struct DDS_PublisherQos * DDS_XMLPublisherQos_get_dds_qos(struct DDS_XMLPublisherQos * self);

extern DDSCDllExport 
const struct DDS_SubscriberQos * DDS_XMLSubscriberQos_get_dds_qos(struct DDS_XMLSubscriberQos * self);

extern DDSCDllExport 
const struct DDS_DataWriterQos * DDS_XMLDataWriterQos_get_dds_qos(struct DDS_XMLDataWriterQos * self);

extern DDSCDllExport 
const struct DDS_DataReaderQos * DDS_XMLDataReaderQos_get_dds_qos(struct DDS_XMLDataReaderQos * self);

extern DDSCDllExport 
const struct DDS_DomainParticipantQos * DDS_XMLQosProfile_get_participant_dds_qos(struct DDS_XMLQosProfile * self, 
                                                                                  DDS_Boolean * is_default);

extern DDSCDllExport
void DDS_XMLQos_save(struct RTIXMLObject * self, struct RTIXMLSaveContext * dst);

extern DDSCDllExport 
const struct DDS_DomainParticipantFactoryQos * 
DDS_XMLQosProfile_get_participant_factory_dds_qos(struct DDS_XMLQosProfile * self,
                                                  struct DDS_DomainParticipantFactoryQosXMLInfo * factory_qos_xml_info,
                                                  DDS_Boolean * is_default);

extern DDSCDllExport 
const struct DDS_TopicQos * DDS_XMLQosProfile_get_topic_dds_qos(struct DDS_XMLQosProfile * self, 
                                                                DDS_Boolean * is_default);

extern DDSCDllExport 
const struct DDS_PublisherQos * DDS_XMLQosProfile_get_publisher_dds_qos(struct DDS_XMLQosProfile * self, 
                                                                        DDS_Boolean * is_default);

extern DDSCDllExport 
const struct DDS_SubscriberQos * DDS_XMLQosProfile_get_subscriber_dds_qos(struct DDS_XMLQosProfile * self, 
                                                                          DDS_Boolean * is_default);

extern DDSCDllExport 
const struct DDS_DataWriterQos * DDS_XMLQosProfile_get_datawriter_dds_qos(struct DDS_XMLQosProfile * self, 
                                                                          DDS_Boolean * is_default);

extern DDSCDllExport 
const struct DDS_DataReaderQos * DDS_XMLQosProfile_get_datareader_dds_qos(struct DDS_XMLQosProfile * self, 
                                                                          DDS_Boolean * is_default);

extern DDSCDllExport 
const struct DDS_DomainParticipantQos * DDS_XMLQosProfile_get_participant_dds_qos_filtered(
    struct DDS_XMLQosProfile * self,
    DDS_Boolean * is_default,
    const char * topic_filter);

extern DDSCDllExport 
const struct DDS_DomainParticipantFactoryQos * DDS_XMLQosProfile_get_participant_factory_dds_qos_filtered(
    struct DDS_XMLQosProfile * self,
    struct DDS_DomainParticipantFactoryQosXMLInfo * factory_qos_xml_info,
    DDS_Boolean * is_default,
    const char * topic_filter);

extern DDSCDllExport 
const struct DDS_TopicQos * DDS_XMLQosProfile_get_topic_dds_qos_filtered(
    struct DDS_XMLQosProfile * self,
    DDS_Boolean * is_default,
    const char * topic_filter);

extern DDSCDllExport 
const struct DDS_PublisherQos * DDS_XMLQosProfile_get_publisher_dds_qos_filtered(
    struct DDS_XMLQosProfile * self,
    DDS_Boolean * is_default,
    const char * topic_filter);

extern DDSCDllExport 
const struct DDS_SubscriberQos * DDS_XMLQosProfile_get_subscriber_dds_qos_filtered(
    struct DDS_XMLQosProfile * self,
    DDS_Boolean * is_default,
    const char * topic_filter);

extern DDSCDllExport 
const struct DDS_DataWriterQos * DDS_XMLQosProfile_get_datawriter_dds_qos_filtered(
    struct DDS_XMLQosProfile * self,
    DDS_Boolean * is_default,
    const char * topic_filter);

extern DDSCDllExport 
const struct DDS_DataReaderQos * DDS_XMLQosProfile_get_datareader_dds_qos_filtered(
    struct DDS_XMLQosProfile * self,
    DDS_Boolean * is_default,
    const char * topic_filter);

extern DDSCDllExport 
const struct DDS_XMLObject * DDS_XMLDds_get_default_qos_profile(
    struct DDS_XMLDds * self);

extern DDSCDllExport 
const struct DDS_XMLObject * DDS_XMLDds_get_default_participant_factory_profile(
    struct DDS_XMLDds * self);

extern DDSCDllExport 
const DDS_TypeCode * DDS_XMLTypeCode_get_dds_typecode(
    struct DDS_XMLTypeCode * self);

extern DDSCDllExport 
DDS_Boolean DDS_XMLTypeCode_is_top_level(
    struct DDS_XMLTypeCode * self);

extern DDSCDllExport 
DDS_DomainId_t DDS_XMLDomain_get_domain_id(struct DDS_XMLDomain * self); 

extern DDSCDllExport 
struct DDS_XMLTopic * DDS_XMLDomain_get_first_xml_topic(struct DDS_XMLDomain * self);

extern DDSCDllExport 
struct DDS_XMLRegisterType * DDS_XMLDomain_get_first_xml_register_type(
                                                    struct DDS_XMLDomain * self);

extern DDSCDllExport 
struct DDS_XMLTopic *
DDS_XMLDomain_get_next_xml_topic(struct DDS_XMLDomain * self,
                                 struct DDS_XMLTopic * xml_topic);

extern DDSCDllExport 
struct DDS_XMLRegisterType * DDS_XMLDomain_get_next_xml_register_type(
                                        struct DDS_XMLDomain * self,
                                        struct DDS_XMLRegisterType * _type);

extern DDSCDllExport 
const char * DDS_XMLRegisterType_get_registered_type_name(
                                        struct DDS_XMLRegisterType * self);

extern DDSCDllExport 
const char * DDS_XMLRegisterType_get_xml_type_name(
                                        struct DDS_XMLRegisterType * self);

extern DDSCDllExport 
const DDS_TypeCode * DDS_XMLRegisterType_get_type_code(
                                        struct DDS_XMLRegisterType * self);

extern DDSCDllExport 
const char * DDS_XMLTopic_get_topic_name(struct DDS_XMLTopic * self);

extern DDSCDllExport 
const char * DDS_XMLTopic_get_xml_register_type_name(struct DDS_XMLTopic * self);

extern DDSCDllExport 
DDS_Boolean DDS_XMLTopic_get_topic_qos(struct DDS_XMLTopic * self,
                                       struct DDS_TopicQos * topic_qos);

extern DDSCDllExport 
struct DDS_XMLDomain * DDS_XMLParticipant_get_xml_domain(
                                    struct DDS_XMLParticipant * self);

extern DDSCDllExport 
const char * DDS_XMLParticipant_get_xml_domain_name(
                                    struct DDS_XMLParticipant * self);

extern DDSCDllExport 
struct DDS_XMLTopic * DDS_XMLParticipant_get_xml_topic(
                                    struct DDS_XMLParticipant * self,
                                    const char * xml_topic_name);

extern DDSCDllExport 
struct DDS_XMLRegisterType * DDS_XMLParticipant_get_xml_register_type(
                                    struct DDS_XMLParticipant * self,
                                    const char * _type_name);

extern DDSCDllExport 
DDS_DomainId_t DDS_XMLParticipant_get_domain_id(
        struct DDS_XMLParticipant * self);

extern DDSCDllExport 
DDS_Boolean DDS_XMLParticipant_get_participant_qos(
                            struct DDS_XMLParticipant * self,
                            struct DDS_DomainParticipantQos * participant_qos);

extern DDSCDllExport 
struct DDS_XMLParticipant * DDS_XMLParticipant_narrow(
                                        struct DDS_XMLObject * xml_object);

extern DDSCDllExport 
struct DDS_XMLPublisher *
DDS_XMLParticipant_get_first_xml_publisher(struct DDS_XMLParticipant * self);

extern DDSCDllExport 
struct DDS_XMLSubscriber *
DDS_XMLParticipant_get_first_xml_subscriber(struct DDS_XMLParticipant * self);

extern DDSCDllExport 
struct DDS_XMLDataWriter *
DDS_XMLParticipant_get_first_xml_datawriter(struct DDS_XMLParticipant * self);

extern DDSCDllExport 
struct DDS_XMLDataReader * DDS_XMLParticipant_get_first_xml_datareader(
                                                struct DDS_XMLParticipant * self);

extern DDSCDllExport 
struct DDS_XMLPublisher *
DDS_XMLParticipant_get_next_xml_publisher(struct DDS_XMLParticipant * self,
                                          struct DDS_XMLPublisher * xml_publisher); 

extern DDSCDllExport 
struct DDS_XMLSubscriber *
DDS_XMLParticipant_get_next_xml_subscriber(struct DDS_XMLParticipant * self,
                                           struct DDS_XMLSubscriber * xml_subscriber);

extern DDSCDllExport 
struct DDS_XMLDataWriter *
DDS_XMLParticipant_get_next_xml_datawriter(struct DDS_XMLParticipant * self,
                                       struct DDS_XMLDataWriter * xml_datawriter);

extern DDSCDllExport 
struct DDS_XMLDataReader *
DDS_XMLParticipant_get_next_xml_datareader(struct DDS_XMLParticipant * self,
                                           struct DDS_XMLDataReader * xml_datareader);

extern DDSCDllExport
DDS_Long DDS_XMLPublisher_get_multiplicity(struct DDS_XMLPublisher * self);

extern DDSCDllExport
DDS_Boolean
DDS_XMLPublisher_get_publisher_qos(struct DDS_XMLPublisher * self,
                                   struct DDS_PublisherQos * publisher_qos);

extern DDSCDllExport
struct DDS_XMLDataWriter *
DDS_XMLPublisher_get_first_xml_datawriter(struct DDS_XMLPublisher * self);

extern DDSCDllExport
struct DDS_XMLDataWriter *
DDS_XMLPublisher_get_next_xml_datawriter(struct DDS_XMLPublisher * self,
                                      struct DDS_XMLDataWriter * xml_datawriter);

extern DDSCDllExport 
DDS_Long DDS_XMLSubscriber_get_multiplicity(struct DDS_XMLSubscriber * self);

extern DDSCDllExport
DDS_Boolean
DDS_XMLSubscriber_get_subscriber_qos(struct DDS_XMLSubscriber * self,
                                     struct DDS_SubscriberQos * subscriber_qos);

extern DDSCDllExport
struct DDS_XMLDataReader *
DDS_XMLSubscriber_get_first_xml_datareader(struct DDS_XMLSubscriber * self);

extern DDSCDllExport
struct DDS_XMLDataReader *
DDS_XMLSubscriber_get_next_xml_datareader(struct DDS_XMLSubscriber * self,
                                       struct DDS_XMLDataReader * xml_datareader);

extern DDSCDllExport
DDS_Boolean
DDS_XMLDataWriter_get_datawriter_qos(struct DDS_XMLDataWriter * self,
                                   struct DDS_DataWriterQos * datawriter_qos);

extern DDSCDllExport 
DDS_Long DDS_XMLDataWriter_get_multiplicity(struct DDS_XMLDataWriter * self);

extern DDSCDllExport
const char * DDS_XMLDataWriter_get_xml_topic_name(
                                        struct DDS_XMLDataWriter * self);

extern DDSCDllExport
struct DDS_XMLParticipant * DDS_XMLDataWriter_get_parent_xml_participant(
                                            struct DDS_XMLDataWriter * self);

extern DDSCDllExport
DDS_Boolean DDS_XMLDataReader_get_datareader_qos(struct DDS_XMLDataReader * self,
                                               struct DDS_DataReaderQos * datareader_qos);

extern DDSCDllExport 
DDS_Long DDS_XMLDataReader_get_multiplicity(struct DDS_XMLDataReader * self);

extern DDSCDllExport
const char * DDS_XMLDataReader_get_xml_topic_name(
                                        struct DDS_XMLDataReader * self);

extern DDSCDllExport
struct DDS_XMLParticipant * DDS_XMLDataReader_get_parent_xml_participant(
                                            struct DDS_XMLDataReader * self);

extern DDSCDllExport
DDS_Boolean DDS_XMLDataReader_has_filter(struct DDS_XMLDataReader * self);

extern DDSCDllExport
const char * DDS_XMLDataReader_get_filter_expression(
                                struct DDS_XMLDataReader * self);

extern DDSCDllExport
const char * DDS_XMLDataReader_get_filtered_topic_name(
                                struct DDS_XMLDataReader * self);

extern DDSCDllExport
const struct DDS_StringSeq * DDS_XMLDataReader_get_filter_parameters(
                                struct DDS_XMLDataReader * self);

extern DDSCDllExport
const char * DDS_XMLDataReader_get_filter_name(
                                struct DDS_XMLDataReader * self);

extern DDSCDllExport
struct DDS_XMLParser * DDS_XMLParser_new(void);

 
extern	DDSCDllExport void DDS_XMLParser_delete(struct DDS_XMLParser * self);

 
extern	DDSCDllExport DDS_Boolean DDS_XMLParser_initialize(
                            struct DDS_XMLParser * self);

 
extern	DDSCDllExport void DDS_XMLParser_finalize(struct DDS_XMLParser * self);

 
extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLParser_parse_from_file(
                                                struct DDS_XMLParser * self,
                                                const char * dtd_str[],
                                                unsigned int dtd_str_length,
                                                const char * filename,
                                                struct DDS_XMLObject * root);

 
extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLParser_parse_from_string(
                                        struct DDS_XMLParser * self,
                                        const char * dtd_str[],
                                        unsigned int dtd_str_length,
                                        const char * xml_str[], 
                                        unsigned int xml_str_length,
                                        struct DDS_XMLObject * root);

extern DDSCDllExport 
struct DDS_XMLObject * DDS_XMLParser_parse_from_url_list(struct DDS_XMLParser * self,
                                                         const char * dtd_str[],
                                                         DDS_UnsignedLong dtd_str_length,
                                                         const char * url_list,
                                                         struct DDS_XMLObject * root);


extern	DDSCDllExport void DDS_XMLParser_free_dom(struct DDS_XMLParser * self, struct DDS_XMLObject * dom);


extern	DDSCDllExport DDS_Boolean DDS_XMLParser_register_extension_class( 
                            struct DDS_XMLParser *self, 
                            struct DDS_XMLExtensionClass * extension);


extern	DDSCDllExport struct DDS_XMLExtensionClass * DDS_XMLParser_unregister_extension_class(
                            struct DDS_XMLParser * self,
                            const char * tagName);


extern	DDSCDllExport const char * DDS_XMLParser_get_last_xml_version(struct DDS_XMLParser * self);

 
extern	DDSCDllExport struct DDS_XMLTypeCodeParser * DDS_XMLTypeCodeParser_new(
    DDS_UnsignedLong unboundedStringMaxLength,
    DDS_UnsignedLong unboundedSequenceMaxLength,
    const char ** includePaths,
    const struct DDS_XMLExtensionClass ** extensionClasses);


extern	DDSCDllExport void DDS_XMLTypeCodeParser_delete(struct DDS_XMLTypeCodeParser * self);

 
extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLTypeCodeParser_parse_from_file(
    struct DDS_XMLTypeCodeParser * self,
    const char * dtd_str[],
    DDS_UnsignedLong dtd_str_length,
    const char * filename,
    struct DDS_XMLObject * root,
    void * context_user_data);


extern	DDSCDllExport struct DDS_XMLObject * DDS_XMLTypeCodeParser_parse_from_string(
    struct DDS_XMLTypeCodeParser * self,
    const char * dtd_str[],
    unsigned int dtd_str_length,
    const char * xml_str[], 
    DDS_UnsignedLong xml_str_length,
    struct DDS_XMLObject * root,
    void * context_user_data);


extern	DDSCDllExport void DDS_XMLTypeCodeParser_free_dom(
    struct DDS_XMLTypeCodeParser * self, 
    struct DDS_XMLObject * dom);


extern	DDSCDllExport DDS_Boolean DDS_XMLQosLibrary_is_builtin_libraryI(
   const char*);


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif
  #include "dds_c/dds_c_xml_impl.h"

#endif /* dds_c_xml_h */
