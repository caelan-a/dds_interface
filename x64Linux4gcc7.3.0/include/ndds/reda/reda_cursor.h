/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_cursor.h    generated by: makeheader    Fri Nov 15 12:21:51 2019
 *
 *		built from:	cursor.ifc
 */

#ifndef reda_cursor_h
#define reda_cursor_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
  #ifndef reda_log_h
    #include "reda/reda_log.h"
  #endif
  #ifndef reda_buffer_h
    #include "reda/reda_buffer.h"
  #endif
  #ifndef reda_epoch_h
    #include "reda/reda_epoch.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDACursor;

struct REDAWeakReference;

struct REDAWorker;

struct REDATable;


  #define REDA_CURSOR_SUCCESS /*                          (0) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 0)


  #define REDA_CURSOR_FAIL_PRECONDITION /*                (1) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 1)


  #define REDA_CURSOR_FAIL_AT_END_OF_TABLE /*             (2) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 2)


  #define REDA_CURSOR_FAIL_KEY_WAS_NOT_FOUND /*           (3) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 3)


  #define REDA_CURSOR_FAIL_TABLE_HAS_NO_READ_ONLY_AREA  /* (4) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 4)


  #define REDA_CURSOR_FAIL_TABLE_HAS_NO_READ_WRITE_AREA /* (5) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 5)


  #define REDA_CURSOR_FAIL_TABLE_HAS_BEEN_DELETED /*      (6) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 6)


  #define REDA_CURSOR_FAIL_RECORD_HAS_BEEN_DELETED /*     (7) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 7)


  #define REDA_CURSOR_FAIL_TABLE_IS_FULL /*               (8) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 8)


  #define REDA_CURSOR_FAIL_UNIQUE_KEY_VIOLATION /*        (9) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 9)


  #define REDA_CURSOR_FAIL_UNEXPECTED_EXCEPTION /*       (10) */ \
    RTI_LOG_formSubmoduleSpecificNumber(MODULE_REDA, SUBMODULE_REDA_TABLE, 10)

extern REDADllExport
RTIBool 
REDACursor_startFnc(struct REDACursor *me, int* failReasonPtr);

extern REDADllExport
void
REDACursor_gotoTopFnc(struct REDACursor *me);

extern REDADllExport
RTIBool 
REDACursor_gotoNextFnc(struct REDACursor *me);

extern REDADllExport RTIBool
REDACursor_gotoKeyEqual(struct REDACursor *me,
			int *failReason,
			void* searchKey);

extern REDADllExport RTIBool 
REDACursor_gotoKeyLargerOrEqual(struct REDACursor *me, 
	                        int *failReason,
		                void *searchKey);

extern REDADllExport RTIBool 
REDACursor_gotoWeakReference(struct REDACursor *me,
                             int *failReason,
                             const struct REDAWeakReference *reference);

extern REDADllExport RTIBool 
REDACursor_getWeakReference(const struct REDACursor *me,
			    int *failReason,
                            struct REDAWeakReference *reference);

extern REDADllExport RTIBool 
REDACursor_lookupWeakReference(const struct REDACursor *me,
			       int *failReason,
			       struct REDAWeakReference *reference);

extern REDADllExport const void *
REDACursor_getKeyFnc(const struct REDACursor *me);

extern REDADllExport const void *
REDACursor_getReadOnlyAreaFnc(const struct REDACursor *me);

extern REDADllExport const struct REDAExclusiveArea *
REDACursor_getRecordEAFnc(const struct REDACursor *me);

extern REDADllExport void *
REDACursor_modifyReadWriteArea(struct REDACursor *me, int *failReason);

extern REDADllExport
const void *REDACursor_getTableUserDataFnc(const struct REDACursor *me);

extern REDADllExport
int REDACursor_getTableRecordCountFnc(const struct REDACursor *me);

extern REDADllExport struct REDAExclusiveArea *
REDACursor_getTableEAFnc(const struct REDACursor *me);

extern REDADllExport RTIBool REDACursor_lockTable(struct REDACursor *me,
						  int *failReason);

extern REDADllExport void *
REDACursor_assertAndModifyReadWriteArea(struct REDACursor *me,
					int *failReason,
					RTIBool *alreadyExisted,
					struct REDAWeakReference *weakReference,
					void *key, 
					void *readOnlyArea,
					struct REDAExclusiveArea *recordEA);

extern REDADllExport RTIBool 
REDACursor_assertAndReplaceRecord(struct REDACursor *me,
				  int *failReason,
				  RTIBool *alreadyExisted,
				  struct REDAWeakReference *weakReference,
				  void *key, 
			          void *readOnlyArea,
				  void *readWriteArea,
				  struct REDAExclusiveArea *recordEA);

extern REDADllExport RTIBool 
REDACursor_assertRecord(struct REDACursor *me,
			int *failReason,
			RTIBool *alreadyExisted,
			struct REDAWeakReference *weakReference,
			void *key, 
			void *readOnlyArea);

extern REDADllExport RTIBool
REDACursor_copyReadWriteArea(struct REDACursor *me,
                             int *failReason,
			     void *buffer, 
			     int numBytesToCopy, 
		             int offset,
			     RTIBool noRecordLock);

extern REDADllExport RTIBool REDACursor_removeRecord(struct REDACursor *me,
						     int *failReason,
						     RTIBool *alreadyRemoved);

extern REDADllExport RTIBool REDACursor_removeTable(struct REDACursor *me,
						    int *failReason, 
						    RTIBool *alreadyRemoved);

extern REDADllExport void
REDACursor_finishReadWriteArea(struct REDACursor *me);

extern REDADllExport RTIBool
REDACursor_unfreezeReadWriteAreaFnc(struct REDACursor *me);

extern REDADllExport void REDACursor_unlockTable(struct REDACursor *me);

extern REDADllExport void REDACursor_finish(struct REDACursor *me);

extern REDADllExport void
REDACursor_unbind(struct REDACursor *me,
                  struct REDAWorker *worker);

extern REDADllExport RTIBool
REDACursor_tableHasReadOnlyAreaFnc(const struct REDACursor *me);

extern REDADllExport RTIBool
REDACursor_tableHasReadWriteAreaFnc(const struct REDACursor *me);

extern REDADllExport int
REDACursor_getReadWriteAreaSizeFnc(const struct REDACursor *me);

extern REDADllExport void
REDACursor_printKey(const struct REDACursor *me, int indent);

extern REDADllExport void
REDACursor_printReadOnlyArea(const struct REDACursor *me, int indent);

extern REDADllExport void
REDACursor_printReadWriteArea(struct REDACursor *me, int indent);

extern REDADllExport void
REDACursor_printAdminArea(struct REDACursor *me, int indent);

extern REDADllExport void
REDACursor_printTableStatus(const struct REDACursor *me,
			    int indent, int verbosity);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

/* pick up hidden performance boosting macros and optimizations */
  #include "reda/reda_cursor_impl.h"

#endif /* reda_cursor_h */
