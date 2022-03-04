/*

 (c) Copyright, Real-Time Innovations, 2020.
 All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.

Description
-----------
Heap allocation for SQLITE3ODBC
=========================================================================*/

#ifndef rtisqlite_odbc_h
#define rtisqlite_odbc_h

#ifdef __cplusplus
    extern "C" {
#endif

#if defined(RTI_WIN32)
#include <windows.h>
#endif

#include <sql.h>
#include <sqltypes.h>
#include <sqlext.h>

/*e \ingroup RTISqliteModule
  @brief Memory allocation function
*/
typedef void *(*RTISqlAllocator_MallocFunction)(int);

/*e \ingroup RTISqliteModule
  @brief Free a prior allocation
*/
typedef void (*RTISqlAllocator_FreeFunction)(void*);

/*e \ingroup RTISqliteModule
  @brief Resize an allocation
*/
typedef void *(*RTISqlAllocator_ReallocFunction)(void*,int);

/*e \ingroup RTISqliteModule
  @brief Return the size of an allocation
*/
typedef int (*RTISqlAllocator_SizeFunction)(void*);

/*e \ingroup RTISqliteModule
  @briefRound up request size to allocation size
*/
typedef int (*RTISqlAllocator_RoundupFunction)(int);

/*e \ingroup RTISqliteModule
  @brief Initialize the memory allocator
*/
typedef int (*RTISqlAllocator_InitFunction)(void*);

/*e \ingroup RTISqliteModule
  @brief Deinitialize the memory allocator
*/
typedef void (*RTISqlAllocator_ShutdownFunction)(void*);

/*e \ingroup RTISqliteModule
*/
typedef struct RTISqlAllocator {
    RTISqlAllocator_MallocFunction xMalloc;
    RTISqlAllocator_FreeFunction xFree;
    RTISqlAllocator_ReallocFunction xRealloc;
    RTISqlAllocator_SizeFunction xSize;
    RTISqlAllocator_RoundupFunction xRoundup;
    RTISqlAllocator_InitFunction xInit;
    RTISqlAllocator_ShutdownFunction xShutdown;
} RTISqlAllocator;

#define RTISqlAllocator_INITIALIZER { \
    NULL, \
    NULL, \
    NULL, \
    NULL, \
    NULL, \
    NULL, \
    NULL  \
}

/**
 * Set Osapi Allocators
 * @param RTISqlAllocator struct with the different osapi methods to use
 */
SQLRETURN SQL_API SQLSetAllocator(const struct RTISqlAllocator *allocator);

/** \ingroup RTISqliteModule
 * @brief Connect to SQLite database
 *
 * This RTI implementation of the SQLConnect method checks the given DSN to know
 * if the method receives the name of a DSN or it receives the full DSN with
 * all its attributes.
 *
 * If the method receives a DSN name, it will process the odbcini file to obtain the
 * attributes of the given DSN name. It will check the ODBCINI environment variable
 * to identify the odbcini file to process.
 *
 * Otherwise, in case the method receives the full DSN with all its attributes,
 * it won't process the odbcini file.
 *
 * This RTI implementation allows using SQLite3ODBC without requiring a Driver Manager.
 *
 * The only ODBC driver implementing this RTI SQLConnect function at this point
 * is the one implemented in the sqlite.1.0 module that is using SQLite
 * as the underlying database.
 */
SQLRETURN SQL_API SQLConnect(
        SQLHDBC dbc,
        SQLCHAR *dsn,
        SQLSMALLINT dsnLen,
	      SQLCHAR *uid,
        SQLSMALLINT uidLen,
  	    SQLCHAR *pwd,
        SQLSMALLINT pwdLen);

#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* rtisqlite_odbc_h */
