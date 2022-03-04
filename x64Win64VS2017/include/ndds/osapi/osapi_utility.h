/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)osapi_utility.h    generated by: makeheader    Fri Apr 23 00:10:13 2021
 *
 *		built from:	utility.ifc
 */

#ifndef osapi_utility_h
#define osapi_utility_h


  #include <errno.h>
  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef osapi_dll_h
    #include "osapi/osapi_dll.h"
  #endif
  #ifndef osapi_vxVersions_h
    #include "osapi/osapi_vxVersions.h"
  #endif
  #include "osapi/osapi_ntptime.h"

  #include <stdio.h>
  #include <stdarg.h>

#if defined(RTI_INTY)
  #include <util/error_string.h>
#endif

#if (defined(RTI_VXWORKS) || defined(RTI_QNX) || defined(RTI_INTY))
  #define RTI_DOUBLE_SIGNIFICANT_DIGITS   15
#else
  #define RTI_DOUBLE_SIGNIFICANT_DIGITS   17
#endif
#define RTI_FLOAT_SIGNIFICANT_DIGITS   9

#ifdef RTI_WIN32
    #define RTI_OSAPI_FILE_PATH_SEPARATOR ("\\")
#else
    #define RTI_OSAPI_FILE_PATH_SEPARATOR ("/")
#endif

#ifdef __cplusplus
    extern "C" {
#endif


extern RTIOsapiDllExport int RTIOsapiUtility_max(int l, int r);

extern RTIOsapiDllExport int RTIOsapiUtility_isWithinBound(
    int me, int lower, int upper);

extern RTIOsapiDllExport int RTIOsapiUtility_min(int l, int r);

extern RTIOsapiDllExport int RTIOsapiUtility_abs(int l);

extern RTIOsapiDllExport RTI_UINT16 RTIOsapiUtility_ntohs(RTI_UINT16 s);

extern RTIOsapiDllExport RTI_UINT32 RTIOsapiUtility_ntohl(RTI_UINT32 l);

extern RTIOsapiDllExport RTI_UINT16 RTIOsapiUtility_htons(RTI_UINT16 s);

extern RTIOsapiDllExport RTI_UINT32 RTIOsapiUtility_htonl(RTI_UINT32 l);

extern RTIOsapiDllExport 
void RTIOsapiUtility_hostToNetworkByteOrder(
    void *dst, 
    const void *src,
    RTI_UINT32 size);

extern RTIOsapiDllExport int RTIOsapiUtility_isDigit(int c);

extern RTIOsapiDllExport
RTIBool RTIOsapi_removeFile(const char * fileName);

extern RTIOsapiDllExport
FILE * RTIOsapi_fileOpen(const char *filename, const char *type);

extern RTIOsapiDllExport
int RTIOsapi_fileClose(FILE *f);


#define OSAPI_UTILITY_MAX_TEMP_DIRECTORY_NAME_LENGTH 256

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_createTempDirectory(char *outPath);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_deleteDirectory(const char *path);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_fileExists(const char * fname);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_fileEquals(const char *fileX, const char *fileY);

extern RTIOsapiDllExport 
char* RTIOsapi_envVarOrFileGet(char *buffer, int bufferLen,
                                 const char *envVariableName,
                                 const char *fileName,
                                 char separator, 
                                 char commentchar);

extern RTIOsapiDllExport 
RTIBool RTIOsapiUtility_getUsername(char * username, 
                                    int maxNameLen);

extern RTIOsapiDllExport 
RTIBool RTIOsapiUtility_getExecutablePath(char * path, 
                                          int maxPathLen, 
                                          const char * executable);

extern RTIOsapiDllExport 
RTIBool RTIOsapiUtility_getSelfFullpath(char * path, int maxPathLen);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_getSelfDirectoryPath(
        char *path,
        int maxPathLength);

extern RTIOsapiDllExport 
char *RTIOsapiUtility_getCurrentDirectory(char *path, int maxPathLen);

extern RTIOsapiDllExport 
RTIBool RTIOsapiUtility_getTarget(char * target, int maxTargetLen);

extern RTIOsapiDllExport 
RTIBool RTIOsapiUtility_getCreationTimestamp(char * buf /* Out */, 
                                             int maxBufLen);

extern RTIOsapiDllExport 
RTIBool RTIOsapiUtility_getExecutionTimestamp(char * buf /* Out */, 
                                             int maxBufLen);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_normalizePath(char * path, 
                                      int maxPathLen, 
                                      const char * originalPath); 


#if defined(RTI_IOS_xxx)    \
    || defined(RTI_LINUX)   \
    || defined(RTI_DARWIN)  \
    || defined(RTI_AIX)     \
    || defined(RTI_INTY)
  #define RTI_OSAPI_SETENV_SUPPORTED
#endif

#if defined(RTI_WIN32)   \
    || defined(RTI_INTY) \
    || defined(RTI_QNX)  \
    || defined(RTI_OSAPI_SETENV_SUPPORTED)
  #define RTI_OSAPI_ENVIRONMENT_SET_SUPPORTED
#endif


extern RTIOsapiDllExport
RTIBool RTIOsapi_isEnvVarSetSupported(void);

extern RTIOsapiDllExport
RTIBool RTIOsapi_envVarSet(const char * envVariable);

extern RTIOsapiDllExport
RTIBool RTIOsapi_envVarUnset(const char * varName);

extern RTIOsapiDllExport
int RTIOsapiUtility_snprintf(char *str, int size, const char *format, ...);

extern RTIOsapiDllExport
int RTIOsapiUtility_snprintfAdv(char *str, int size, RTIBool showErrors, const char *format, ...);

extern RTIOsapiDllExport
int RTIOsapiUtility_vsnprintf(char *str, int size, const char *format, va_list args);

extern RTIOsapiDllExport
int RTIOsapiUtility_vsnprintfAdv(char *str, int size, RTIBool showErrors, const char *format, va_list args);

extern RTIOsapiDllExport
int RTIOsapiUtility_sscanf(const char *s, const char *format, ...);

extern RTIOsapiDllExport
int RTIOsapiUtility_strlen(char *str);

extern RTIOsapiDllExport
int RTIOsapiUtility_strlenFnc(char *str);

extern RTIOsapiDllExport
char *RTIOsapiUtility_strcpy(char *dest, int destStringLengthMax, const char *src);

extern RTIOsapiDllExport
char *RTIOsapiUtility_strncpy(char *dest, int destStringLengthMax, const char *src, size_t n);

extern RTIOsapiDllExport
char *RTIOsapiUtility_strcat(char *dest, int destStringLengthMax, const char *src);

extern RTIOsapiDllExport
char *RTIOsapiUtility_strncat(char *dest, int destStringLengthMax, const char *src,  size_t n);

extern RTIOsapiDllExport
const char *RTIOsapiUtility_strstr(const char *src, const char *pattern);


#if !(defined(RTI_VXWORKS) && VXWORKS_MAJOR_VERSION < 6) \
    && !(defined(RTI_LYNX) && RTI_LYNX < 500)
  #define RTI_OSAPI_VSNPRINTF_SUPPORTED
#endif

extern RTIOsapiDllExport
void RTIOsapiUtility_fprintf_llu(FILE *fp, RTI_UINT64 value);

extern RTIOsapiDllExport
void RTIOsapiUtility_fprintf_ll(FILE *fp, RTI_INT64 value);

extern RTIOsapiDllExport
unsigned int RTIOsapiUtility_get_double_precision(void);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_strtol(const char * str, RTI_INT32 * value);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_strtoul(const char * str, RTI_UINT32 * value);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_strtoll(const char * str, RTI_INT64 * value);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_strtollWithEndSeparator(
        const char *str,
        RTI_INT64 *value,
        const char expectedEndSeparator);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_strtoull(const char * str, RTI_UINT64 * value, int base);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_strtod(const char *str, RTI_DOUBLE64 *value);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_parseHexString(
        const char *strIn,
        unsigned char *bufOut,
        size_t maxSize,
        size_t *bufSizeOut);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_strtoptr(const char * str,void ** value);


#define RTI_OSAPI_STRING_SEQ_STRING_MAX_SIZE (4096)

#if defined(RTI_VXWORKS) && VXWORKS_VERSION_6_3_OR_BETTER \
    || defined(RTI_VX653) \
    || (ENABLE_FACE_COMPLIANCE != FACE_COMPLIANCE_LEVEL_NONE)
  #define RTI_REALTIME_CLOCK_ID CLOCK_REALTIME
#endif

extern RTIOsapiDllExport
RTI_INT64 RTIOsapiUtility_gethrtime(void);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_getTimeAdv(
        struct RTINtpTime *now,
        RTIBool logException);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_getTime(struct RTINtpTime *now);


#define RTI_OSAPI_UTC_TIME_BUFFER_SIZE 29

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_getUtcTime(
        char *buffer,
        unsigned int size,
        const struct RTINtpTime *time);

extern RTIOsapiDllExport
char * RTIOsapiUtility_strToken(char *s1, const char *delim, char **save);

extern RTIOsapiDllExport
char *  RTIOsapiUtility_strTokenEx(
        char *s1,
        const char *delim,
        const char *escape,
        char **save);

extern RTIOsapiDllExport
unsigned int RTIOsapiUtility_pow2(int y);

extern RTIOsapiDllExport
unsigned int RTIOsapiUtility_log2(unsigned int x, char floor);

extern RTIOsapiDllExport
char * RTIOsapiUtility_strTrimStart(char *str);

extern RTIOsapiDllExport
char *RTIOsapiUtility_strTrim(char *str);

extern RTIOsapiDllExport
void RTIOsapiUtility_srandWithSeed(unsigned int seed);

extern RTIOsapiDllExport
void RTIOsapiUtility_srand(void);

extern RTIOsapiDllExport
int RTIOsapiUtility_rand(void);

extern RTIOsapiDllExport
int RTIOsapiUtility_randRange(int rangeMin, int rangeMax);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_isnanf(float x);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_isnan(double x);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_isinff(float x);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_isinf(double x);

extern RTIOsapiDllExport
unsigned int RTIOsapiUtility_getEnabledBitCount(unsigned int i);

extern RTIOsapiDllExport
unsigned int RTIOsapiUtility_getLeastSignificantEnabledBit(unsigned int i);

extern RTIOsapiDllExport
int RTIOsapiUtility_linearNormalization(
        int x,
        int rMin,
        int rMax,
        int targetMin,
        int targetMax);


#define RTI_OSAPI_ERROR_STRING_MAX_SIZE (128)
#define RTI_OSAPI_UNKNOWN_ERROR_STRING "Unknown error"


#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #define RTIOsapiUtility_getError GetLastError
  #define RTIOsapiUtility_setError SetLastError
#else
  #ifdef RTI_VXWORKS
    #ifndef errno
      #define errno errnoGet()
    #endif
  #endif
  #define RTIOsapiUtility_getError() errno
  #define RTIOsapiUtility_setError(x) errno = (x)
#endif

extern RTIOsapiDllExport
const char * RTIOsapiUtility_getErrorString(
    char *buffer, size_t bufferSize, int errnum);

extern RTIOsapiDllExport
void * RTIOsapiUtility_intToPointer(const RTI_INT32 intValue);

extern RTIOsapiDllExport
RTI_INT32 RTIOsapiUtility_pointerToInt(const void *pointer);

extern RTIOsapiDllExport
RTI_UINT64 RTIOsapiUtility_pointerToUInt64(const void *pointer);

extern RTIOsapiDllExport
RTI_UINT32 RTIOsapiUtility_crc32(
        const void *data,
        RTI_UINT32 length,
        RTI_UINT32 previousCrc32);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_isNativeLittleEndian(void);

extern RTIOsapiDllExport 
RTIBool RTIOsapiUtility_stringArrayToDelimitedString(
        char* dst,
        size_t dst_max,
        char delim,
        const char **stringArray,
        int stringArrayLength);

extern RTIOsapiDllExport
int RTIOsapiUtility_stringUtf8ValidateChar(const char *inputString);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_stringUtf8ValidateString(const char *inputString);

extern RTIOsapiDllExport
int RTIOsapiUtility_stringUtf8ToCodepoint(
        RTI_UINT32 *codepoint,
        const char *inputString);

extern RTIOsapiDllExport
int RTIOsapiUtility_stringUtf8FromCodepoint(
        char *outputString,
        const RTI_UINT32 outputStringLength,
        const RTI_UINT32 codepoint);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_stringUtf16ToSurrogatePair(
        RTI_UINT16 *highSurrogate,
        RTI_UINT16 *lowSurrogate,
        const RTI_UINT32 codepoint);

extern RTIOsapiDllExport
RTIBool RTIOsapiUtility_stringUtf16FromSurrogatePair(
        RTI_UINT32 *codepoint,
        const RTI_UINT16 highSurrogate,
        const RTI_UINT16 lowSurrogate);

extern RTIOsapiDllExport
int RTIOsapiUtility_stringUtf8ToUtf16(
        RTI_UINT16 *outputString,
        RTI_UINT32 outputStringLength,
        const char *inputString);

extern RTIOsapiDllExport
int RTIOsapiUtility_stringUtf16ToUtf8(
        char *outputString,
        RTI_UINT32 outputStringLength,
        const RTI_UINT16 *inputString,
        RTI_UINT32 inputStringLength);

extern RTIOsapiDllExport
const char * RTIOsapiUtility_strGetToken(int *tokenLength, const char *s, char c);

extern RTIOsapiDllExport
int RTIOsapiUtility_strGetTokenCount(const char *string, char separator);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

  #include "osapi/osapi_utility_impl.h"

#endif /* osapi_utility_h */
