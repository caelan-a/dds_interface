/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)cdr_encapsulation_impl.h    generated by: makeheader    Fri Apr 23 00:04:25 2021
 *
 *		built from:	encapsulation_impl.ifc
 */

#ifndef cdr_encapsulation_impl_h
#define cdr_encapsulation_impl_h


#ifdef __cplusplus
    extern "C" {
#endif



#define RTICdrEncapsulation_validPlainCdrEncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_LE))

#define RTICdrEncapsulation_validParameterCdrEncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR2_LE))

#define RTICdrEncapsulation_validDelimitedCdrEncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_D_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_D_CDR2_LE))

#define RTICdrEncapsulation_validCdrV1EncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_LE))

#define RTICdrEncapsulation_validCdrV2EncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR2_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_D_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_D_CDR2_LE))

#define RTICdrEncapsulation_validCdrEncapsulationId(_id) \
(RTICdrEncapsulation_validPlainCdrEncapsulationId(_id) \
 || RTICdrEncapsulation_validParameterCdrEncapsulationId(_id) \
 || RTICdrEncapsulation_validDelimitedCdrEncapsulationId(_id))

#define RTICdrEncapsulation_validEncapsulationId \
    RTICdrEncapsulation_validCdrEncapsulationId

#define RTICdrEncapsulation_validShmemRefEncapsulationId(_id) \
(((_id) == RTI_ENCAPSULATION_ID_SHMEM_REF_PLAIN) \
 || ((_id) == RTI_ENCAPSULATION_ID_SHMEM_REF_FLAT_DATA))

#define RTICdrEncapsulation_getParameterCdrEncapsulationId(_id) \
( \
    (_id) == RTI_CDR_ENCAPSULATION_ID_CDR_BE \
            ? RTI_CDR_ENCAPSULATION_ID_PL_CDR_BE : ( \
    (_id) == RTI_CDR_ENCAPSULATION_ID_CDR_LE \
            ? RTI_CDR_ENCAPSULATION_ID_PL_CDR_LE : ( \
    (_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_BE \
            ? RTI_CDR_ENCAPSULATION_ID_PL_CDR2_BE : ( \
    (_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_LE \
            ? RTI_CDR_ENCAPSULATION_ID_PL_CDR2_LE : \
    (_id)))) \
)

#define RTICdrEncapsulation_isLittleEndianCdrEncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR2_LE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_D_CDR2_LE))

#define RTICdrEncapsulation_isBigEndianCdrEncapsulationId(_id) \
(((_id) == RTI_CDR_ENCAPSULATION_ID_CDR_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_PL_CDR2_BE) \
 || ((_id) == RTI_CDR_ENCAPSULATION_ID_D_CDR2_BE))

/* ----------------------------------------------------------------- */
/* Extensible types definitions                                      */
/* ----------------------------------------------------------------- */

#define RTICdrParameterId_stripOutFlags(pId) \
    (*(pId)) = ((*(pId)) & RTI_CDR_PID_NON_EXTENDED_ABSOLUTE_MAX_VALUE)

#define RTICdrLongParameterId_stripOutFlags(pId) \
    (*(pId)) = ((*(pId)) & 0x0FFFFFFF)



#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* cdr_encapsulation_impl_h */
