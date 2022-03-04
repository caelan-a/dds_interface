/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_interpreter.h    generated by: makeheader    Fri Apr 23 00:06:00 2021
 *
 *		built from:	interpreter.ifc
 */

#ifndef dds_c_interpreter_h
#define dds_c_interpreter_h


#ifndef xcdr_typeCode_h
  #include "xcdr/xcdr_typeCode.h"
#endif
#ifdef __cplusplus
    extern "C" {
#endif

extern DDSCDllVariable RTIXCdrSampleAccessInfo DDS_g_sai_seq;

extern DDSCDllExport
RTIXCdrMemberValue DDS_Sequence_get_member_value_pointer(
        void *sample,
        RTIXCdrUnsignedLong *elementCount,
        RTIXCdrUnsignedLongLong bindingMemberValueOffset,
        RTIXCdrUnsignedLong elementIndex,
        const struct RTIXCdrTypeCode *memberTc,
        const struct RTIXCdrTypeCodeMember *memberInfo,
        RTIXCdrBoolean allocateMemberIfNull,
        void *programData);

extern DDSCDllExport
RTIXCdrMemberValue DDS_Sequence_set_member_element_count(
        RTIXCdrBoolean *failure,
        void *sample,
        RTIXCdrUnsignedLong elementCount,
        RTIXCdrUnsignedLongLong bindingMemberValueOffset,
        const struct RTIXCdrTypeCode *memberTc,
        const struct RTIXCdrTypeCodeMember *memberInfo,
        RTIXCdrBoolean allocateMemberIfNull,
        RTIXCdrBoolean trimToSize,
        RTIXCdrBoolean initializeElement,
        void *programData);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_interpreter_h */
