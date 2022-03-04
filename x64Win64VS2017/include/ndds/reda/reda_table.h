/* (c) Copyright 2003-2021, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)reda_table.h    generated by: makeheader    Fri Apr 23 00:10:58 2021
 *
 *		built from:	table.ifc
 */

#ifndef reda_table_h
#define reda_table_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif
  #ifndef reda_epoch_h
    #include "reda/reda_epoch.h"
  #endif
  #ifndef reda_fastBuffer_h
    #include "reda/reda_fastBuffer.h"
  #endif
#ifdef __cplusplus
    extern "C" {
#endif

struct REDASkiplistDescription;

struct REDAExclusiveArea;

struct REDAOrderedDataType;

struct REDAHashDefinition;

struct REDACursor;

struct REDATable;

struct REDAWorker;

struct REDAWeakReferenceManager;


#define REDA_TABLE_USE_DEFAULT_VALUE (-1)


#define REDA_TABLE_NAME_MAX_LENGTH (80)

typedef
void (*REDATableFinalizeFunction)(void *param, 
                                  void *recordFinalizeParam,
				  void *tableUserData,
				  struct REDAWorker *worker);

typedef
void (*REDATableRecordFinalizeFunction)(void *param, 
                                        void *key,
					void *readOnlyArea,
					void *readWriteArea,
					struct REDAWorker *worker);

struct REDATableProperty {
    struct REDAFastBufferPoolGrowthProperty growth;
    int hashBucketCount;
};

extern void REDATableProperty_init(struct REDATableProperty* me,
	int initial, int maximal, int growthIncrement,
    int hashBucketCount);

extern REDADllExport 
struct REDATable *
REDATable_new(const char *tableName,
	      const struct REDAOrderedDataType *keyType,
	      const struct REDAOrderedDataType *readOnlyAreaType,
	      const struct REDAOrderedDataType *readWriteAreaType,
	      const struct REDAHashDefinition  *hashDefinition,
	      const struct REDASkiplistDescription *skiplistDesc,
	      const struct REDAFastBufferPoolGrowthProperty* growthPropertyIn,
	      struct REDAWeakReferenceManager *weakRefManager,
	      struct REDAExclusiveArea *tableEA,
	      struct REDAExclusiveArea *adminEA,
	      REDATableFinalizeFunction tableFinalizeFnc,
	      void *tableFinalizeParam,
	      REDATableRecordFinalizeFunction recordFinalizeFnc,
	      void *recordFinalizeParam,
	      void *tableUserData,
	      struct REDAWorker *worker);

extern REDADllExport 
const struct REDAFastBufferPoolGrowthProperty*
REDATable_getGrowthProperty(struct REDATable *me);

/*e \ingroup REDATableClass

  @brief Get the read-only table name.
  @mtsafety Safe.
*/
extern REDADllExport
const char * REDATable_getName(const struct REDATable *me);

extern REDADllExport 
void
REDATable_delete(struct REDATable *table);

extern REDADllExport 
RTIBool
REDATable_bindCursor(struct REDATable  *table,
	             struct REDACursor *cursor,
		     struct REDAWorker *worker);

extern REDADllExport
RTIBool REDATable_cleanup(struct REDATable *table,
			  RTIBool *tableCanBeDeleted,
			  struct REDAWorker *worker);


/*e Table is alive */
#define REDA_TABLE_INFO_TABLE_STATE_ALIVE (0)
/*e Table is removed */
#define REDA_TABLE_INFO_TABLE_STATE_REMOVED (1)
/*e Table is ready to be deleted */
#define REDA_TABLE_INFO_TABLE_STATE_READY_TO_BE_DELETED (2)

struct REDATableInfo {
    /*e */
    void *tableId;
    /*e */
    int state;
    /*e */
    struct REDAHashedSkiplistInfo *hashedSkiplistInfo;
    /*e */
    int recordCount;
    /*e */
    int removedRecordsPendingDeletionCount;
    /*e */
    struct REDACursorInfo **cursorInfo;
    /*e */
    int cursorCount;
    /*e */
    int sizeOfKey;
    /*e */
    int sizeOfReadOnlyArea;
    /*e */
    int sizeOfReadWriteArea;
    /*e */
    int sizeOfRecord;
    /*e */
    int totalMemoryUsage;
    /*e */
    char tableName[REDA_TABLE_NAME_MAX_LENGTH+1];
    /*e */
    struct REDAWeakReferenceManagerInfo *weakReferenceManagerInfo;
    /*e */
    struct REDAExclusiveAreaInfo *adminExclusiveAreaInfo;
    /*e */
    struct REDAExclusiveAreaInfo *tableExclusiveAreaInfo;
    /*e */
    REDAEpoch tableEpoch;
};

extern REDADllExport struct REDATableInfo *
REDATableInfo_new(struct REDATable *table);

extern REDADllExport void
REDATableInfo_delete(struct REDATableInfo *info);

extern REDADllExport void
REDATableInfo_print(struct REDATableInfo *info, int indent);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

/* pick up hidden performance boosting macros and optimizations */
  #include "reda/reda_table_impl.h"

#endif /* reda_table_h */
