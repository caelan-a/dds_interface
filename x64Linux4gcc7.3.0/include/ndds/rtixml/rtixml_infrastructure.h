/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)rtixml_infrastructure.h    generated by: makeheader    Fri Nov 15 12:21:57 2019
 *
 *		built from:	infrastructure.ifc
 */

#ifndef rtixml_infrastructure_h
#define rtixml_infrastructure_h


  #include "stdio.h"
  #include "stdarg.h"

  #include "rtixml/rtixml_dll.h"
  #include "osapi/osapi_type.h"

  #ifdef __cplusplus
      extern "C" {
  #endif

  #define RTIXML_XML_BUFFER_SIZE 32768
  #define RTIXML_XML_SMALL_BUFFER_SIZE 2048
  #define RTIXML_XML_MAX_DEPTH 128
  #define RTIXML_MAGIC_NUMBER 0x7344L
  #define RTIXML_INDENT_WIDTH 4
  #define RTIXML_INDENT_CHARACTER ' '
      


typedef enum RTIXMLErrorKind {
    RTI_XML_NO_ERROR,
    RTI_XML_GENERAL_ERROR,
    RTI_XML_DTD_VALIDATION_ERROR
} RTIXMLErrorKind;


struct XML_ParserStruct;


struct RTIXMLContext {
    struct XML_ParserStruct ** parser;
    /*e
      \brief This member is used to signal an error condition during the parsing process.
    */
    RTIBool error;
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
    /*e
      \brief error kind. This must be the last field. It cannot be exposed to
     * to the user
    */
    RTIXMLErrorKind errorKind;    
};


struct RTIXMLSaveContext {
    /*e
      \brief Destination output file
    */
    FILE * fout;
    /*e
      \brief Destination output string
    */
    char * sout;
    /*e
      \brief Size allocated for sout
    */
    unsigned int ssize;
    /*e
      \brief Number of characters printed on either fout or sout (not including
      the trailing '\0' used to end output to strings)
     */
    unsigned int outputStringLength;
    /*e
      \brief This member controls the indent depth
    */
    int depth;
    /*e
      \brief This member is used to signal an error condition during the parsing process.
    */
    RTIBool error;
    /*e
      \brief This member is availabler for higher levels to store information
    */
    void * userData;
};


#define RTIXMLSaveContext_INITIALIZER {  \
    NULL,                                \
    NULL,                                \
    0,                                   \
    0,                                   \
    0,                                   \
    RTI_FALSE,                           \
    NULL                                 \
}

extern RTIXMLDllExport 
void RTIXMLContext_setContextLineNumber(struct RTIXMLContext * context, int line);

extern RTIXMLDllExport 
void RTIXMLContext_resetContextLineNumber(struct RTIXMLContext * context);

extern RTIXMLDllExport 
int RTIXMLContext_getCurrentLineNumber(struct RTIXMLContext * context);

extern RTIXMLDllExport 
int RTIXMLHelper_getAttributeCount(const char **attrList);

extern RTIXMLDllExport 
const char * RTIXMLHelper_getAttribute(const char **attrList,const char * name);

extern RTIXMLDllExport 
const char * RTIXMLHelper_strTrim(char * str);

extern RTIXMLDllExport
void RTIXMLSaveContext_freeform(
    struct RTIXMLSaveContext * self,
    const char *format, ...);

extern RTIXMLDllExport
void RTIXMLSaveContext_freeform_v(
    struct RTIXMLSaveContext *self,
    const char *format,
    va_list args,
    va_list argsAux);


extern	RTIXMLDllExport void RTIXMLSaveContext_indent(struct RTIXMLSaveContext * self);


extern	RTIXMLDllExport RTIBool RTIXMLSaveContext_initialize(struct RTIXMLSaveContext * self);


extern	RTIXMLDllExport RTIBool RTIXMLSaveContext_finalize(struct RTIXMLSaveContext * self);


  #ifdef __cplusplus
    }	/* extern "C" */
  #endif

#endif /* rtixml_infrastructure_h */
