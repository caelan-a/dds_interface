/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_bitVector.h    generated by: makeheader    Fri Apr 23 00:10:53 2021
 *
 *		built from:	bitVector.ifc
 */

#ifndef reda_bitVector_h
#define reda_bitVector_h



#include "limits.h"

  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef osapi_alignment_h
    #include "osapi/osapi_alignment.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif



/*e \ingroup REDABitVectorClass
 *  @brief Minimum map size in bits
 */
#define REDA_BIT_VECTOR_SIZE_MIN (1)        

        
/*e \ingroup REDABitVectorClass
 *  @brief Maximum map size in bits
 */
#define REDA_BIT_VECTOR_SIZE_MAX (RTI_INT32_MAX) 
        
/*e \ingroup REDABitVectorClass
 *  @brief Converts from bits to bytes.
 */       
#define REDABitVector_bitsToBytes(bits) ( (bits) / 8 + ((bits) % 8 != 0 ? 1 : 0 ))

/*e \ingroup REDABitVectorClass
 *  @brief Converts from bytes to bits.
 */       
#define REDABitVector_bytesToBits(bytes) ( (bytes) * 8 )   
        
        


struct REDABitVector;

extern REDADllExport
RTI_UINT32 REDABitVector_size(struct REDABitVector *self);

extern REDADllExport
RTIBool REDABitVector_equals(struct REDABitVector *self, struct REDABitVector *other);

extern REDADllExport
int REDABitVector_compare(struct REDABitVector *left, struct REDABitVector *right);

extern REDADllExport
RTIBool REDABitVector_copy(struct REDABitVector* self, struct REDABitVector* from);

extern REDADllExport
struct REDABitVector* REDABitVector_or(
        struct REDABitVector *self,  
        struct REDABitVector *other);

extern REDADllExport
struct REDABitVector* REDABitVector_and(
        struct REDABitVector *self,  
        struct REDABitVector *other);

extern REDADllExport
RTIBool REDABitVector_resize(
        struct REDABitVector *self,
        RTI_UINT32 newSize);

extern REDADllExport
void REDABitVector_one(struct REDABitVector *self);

extern REDADllExport
void REDABitVector_zero(struct REDABitVector *self);

extern REDADllExport
void REDABitVector_delete(struct REDABitVector *self);

extern REDADllExport
struct REDABitVector* REDABitVector_new(RTI_UINT32 size);

extern REDADllExport
struct REDABitVector* REDABitVector_newFromCharArray(
        RTI_UINT8 *charArray,
        RTI_INT32 charArraySize);


#ifdef __cplusplus
    }	/* extern "C" */
#endif
    
#include "reda/reda_bitVector_impl.h"


#endif /* reda_bitVector_h */
