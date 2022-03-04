/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)ndds_utility_c.h    generated by: makeheader    Fri Nov 15 12:22:54 2019
 *
 *		built from:	ndds_utility_c.ifc
 */

#ifndef ndds_utility_c_h
#define ndds_utility_c_h



#ifndef dds_c_infrastructure_h
  #include "dds_c/dds_c_infrastructure.h"
#endif

#ifndef dds_c_subscription_h
  #include "dds_c/dds_c_subscription.h"
#endif

#ifdef __cplusplus
    extern "C" {
#endif
        

extern DDSCDllExport 
void NDDS_Utility_sleep(const struct DDS_Duration_t* durationIn);

extern DDSCDllExport 
void NDDS_Utility_spin(DDS_UnsignedLongLong spinCount);

extern DDSCDllExport 
DDS_UnsignedLongLong NDDS_Utility_get_spin_per_microsecond();


typedef struct NDDS_StackManagedThreadImpl NDDS_StackManagedThread;

extern DDSCDllExport 
const char * NDDS_StackManagedThread_get_name(
        NDDS_StackManagedThread * self);

extern DDSCDllExport 
DDS_Long NDDS_StackManagedThread_get_stack_size(
        NDDS_StackManagedThread * self);

extern DDSCDllExport 
DDS_Long NDDS_StackManagedThread_get_stack_usage_max(
        NDDS_StackManagedThread * self);

extern DDSCDllExport 
void NDDS_StackManagedThread_setUserObjectI(
        NDDS_StackManagedThread * self,
        void * object);

extern DDSCDllExport 
void * NDDS_StackManagedThread_getUserObjectI(
        NDDS_StackManagedThread * self);


#define NDDS_ThreadStackAllocator_INITIALIZER {NULL, NULL}


typedef void* (*NDDS_ThreadStackAllocator_CreateStackCallback)(
        void * generator_data, 
        DDS_Long * stack_size);


struct NDDS_ThreadStackAllocator {    
    /* \dref_ThreadStackAllocator_generator_data */
    void * generator_data;
    /* \dref_ThreadStackAllocator_create_stack */
    NDDS_ThreadStackAllocator_CreateStackCallback create_stack;
};


typedef struct NDDS_StackManagedThreadFactoryImpl NDDS_StackManagedThreadFactory;

extern DDSCDllExport 
NDDS_StackManagedThreadFactory * NDDS_StackManagedThreadFactory_new(
        struct NDDS_ThreadStackAllocator * thread_stack_allocator);

extern DDSCDllExport 
void NDDS_StackManagedThreadFactory_delete(
        NDDS_StackManagedThreadFactory * self);

extern DDSCDllExport 
const struct DDS_ThreadFactory * NDDS_StackManagedThreadFactory_as_thread_factory(
        NDDS_StackManagedThreadFactory * self);

extern DDSCDllExport 
DDS_Long NDDS_StackManagedThreadFactory_get_thread_count(
        NDDS_StackManagedThreadFactory * self);

extern DDSCDllExport
NDDS_StackManagedThread * NDDS_StackManagedThreadFactory_get_thread_at(
        NDDS_StackManagedThreadFactory * self,
        DDS_Long index);

extern DDSCDllExport
void NDDS_StackManagedThreadFactory_print_threads_stack_summary(
        NDDS_StackManagedThreadFactory * self);

extern DDSCDllExport
DDS_Boolean NDDS_Utility_enable_heap_monitoring();

extern DDSCDllExport
void NDDS_Utility_disable_heap_monitoring();

extern DDSCDllExport
DDS_Boolean NDDS_Utility_pause_heap_monitoring();

extern DDSCDllExport
DDS_Boolean NDDS_Utility_resume_heap_monitoring();

extern DDSCDllExport
DDS_Boolean NDDS_Utility_take_heap_snapshot(
        const char *filename,
        DDS_Boolean print_details);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* ndds_utility_c_h */
