/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_string.h    generated by: makeheader    Fri Apr 23 00:06:07 2021
 *
 *		built from:	string.ifc
 */

#ifndef dds_c_string_h
#define dds_c_string_h


  #ifndef dds_c_dll_h
    #include "dds_c/dds_c_dll.h"
  #endif
  #ifndef dds_c_common_h
    #include "dds_c/dds_c_common.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

extern DDSCDllExport char* 
DDS_String_alloc(size_t length);

extern DDSCDllExport char* 
DDS_String_dup(const char* str);

extern DDSCDllExport char* 
DDS_String_replace(char** string_ptr, const char* new_value);

extern DDSCDllExport
char * DDS_String_append(char **string_ptr, const char *append_ptr);

extern DDSCDllExport void 
DDS_String_free(char* str);

extern DDSCDllExport DDS_Wchar* 
DDS_Wstring_alloc(DDS_UnsignedLong length);

extern DDSCDllExport DDS_UnsignedLong
DDS_Wstring_length(const DDS_Wchar* str);

extern DDSCDllExport DDS_Wchar* 
DDS_Wstring_copy(DDS_Wchar* dst, const DDS_Wchar* src);

extern DDSCDllExport DDS_Wchar*
DDS_Wstring_copy_and_widen(DDS_Wchar* dst, const char* src);

extern DDSCDllExport DDS_Wchar*
DDS_Wstring_dup(const DDS_Wchar* str);

extern DDSCDllExport DDS_Wchar*
DDS_Wstring_dup_and_widen(const char* str);

extern DDSCDllExport DDS_Wchar* 
DDS_Wstring_replace(DDS_Wchar** string_ptr, const DDS_Wchar* new_value);

extern DDSCDllExport void 
DDS_Wstring_free(DDS_Wchar* str);

extern DDSCDllExport
DDS_Long DDS_Wstring_cmp(const DDS_Wchar *str1, const DDS_Wchar *str2);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_string_h */
