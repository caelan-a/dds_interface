/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_xml_impl.h    generated by: makeheader    Fri Apr 23 00:06:19 2021
 *
 *		built from:	xml_impl.ifc
 */

#ifndef dds_c_xml_impl_h
#define dds_c_xml_impl_h


  #include "dds_c/dds_c_publication_impl.h"
  #include "dds_c/dds_c_subscription_impl.h"
  #include "dds_c/dds_c_topic_impl.h"
  #include "dds_c/dds_c_domain_impl.h"
  #include "rtixml/rtixml_parser.h"

  #ifdef __cplusplus
    extern "C" {
  #endif

  #define DDS_XML_MAGIC_NUMBER RTIXML_MAGIC_NUMBER
  #define DDS_XML_BUILTIN_EXTENSIONS 38
  #define DDS_XML_TYPECODE_BUILTIN_EXTENSIONS 11
  #define DDS_XML_OBJECT_MAX_NAME_LENGTH RTIXML_OBJECT_MAX_NAME_LENGTH


struct DDS_XMLTypeCodeClassInfo {
    DDS_UnsignedLong unboundedStringMaxLength;
    DDS_UnsignedLong unboundedSequenceMaxLength;
};


struct DDS_XMLFileInfoList;


struct DDS_XMLIncludeClassInfo {
    struct DDS_XMLTypeCodeClassInfo tcInfo;
    char ** includePaths;
    struct DDS_XMLExtensionClass ** extensionClasses;

    /* \brief Ordered list of include file infos (DDS_XMLIncludeFileInfo)

       The purpose of this list is to avoid circular dependencies
       on include files
    */
    struct DDS_XMLFileInfoList * includeFileInfoList;
};


struct DDS_XMLTypeCodeParser {
    struct RTIXMLParser parent;
    struct RTIXMLExtensionClass * _extensionClasses[DDS_XML_TYPECODE_BUILTIN_EXTENSIONS+1];
    RTIBool _loanedExtensionCl;
    struct DDS_XMLTypeCodeClassInfo _tcClassInfo;
    struct DDS_XMLIncludeClassInfo _inclClassInfo;
    struct DDS_XMLFileInfoList * _includeFileInfoList;
};


struct DDS_XMLParser {
    struct RTIXMLParser parent;
    int _init;
    struct DDS_XMLExtensionClass * _typeExtensionClasses[DDS_XML_BUILTIN_EXTENSIONS+1];
    char * _includePaths[2];
    struct DDS_XMLFileInfoList * _includeFileInfoList;
    struct DDS_XMLIncludeClassInfo _includeClassInfo;
    /* Default QoSs that will be returned by the profiles when
       the QoSs are not defined in the XML file */
    struct DDS_DomainParticipantFactoryQos defaultParticipantFactoryQos;
    RTIBool _initDefaultParticipantFactoryQos;
    struct DDS_DomainParticipantQos defaultParticipantQos;
    RTIBool _initDefaultParticipantQos;
    struct DDS_TopicQos defaultTopicQos;
    RTIBool _initDefaultTopicQos;
    struct DDS_PublisherQos defaultPublisherQos;
    RTIBool _initDefaultPublisherQos;
    struct DDS_SubscriberQos defaultSubscriberQos;
    RTIBool _initDefaultSubscriberQos;
    struct DDS_DataWriterQos defaultWriterQos;
    RTIBool _initDefaultWriterQos;
    struct DDS_DataReaderQos defaultReaderQos;
    RTIBool _initDefaultReaderQos;

    RTIBool _ignoreIsDefaultQosAttr;
};


struct DDS_XMLExtensionClass {
    struct RTIXMLExtensionClass parent;
};


struct DDS_XMLObject {
    struct RTIXMLObject parent;
};


struct DDS_XMLQos;

extern DDSCDllExport
const char * DDS_XMLQos_get_topic_filter(struct DDS_XMLQos * self);


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#endif /* dds_c_xml_impl_h */
