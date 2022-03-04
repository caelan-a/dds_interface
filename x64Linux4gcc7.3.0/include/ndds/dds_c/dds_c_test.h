/* (c) Copyright 2003-2019, Real-Time Innovations, Inc. All rights reserved. */
/*
 * @(#)dds_c_test.h    generated by: makeheader    Fri Nov 15 12:22:54 2019
 *
 *		built from:	test.ifc
 */

#ifndef dds_c_test_h
#define dds_c_test_h


  #ifndef test_setting_h
    #include "test/test_setting.h"
  #endif
  #ifndef dds_c_dll_h
    #include "dds_c/dds_c_dll.h"
  #endif
  #ifndef ndds_config_c_h
    #include "ndds/ndds_config_c.h"
  #endif
  #ifndef clock_interface_h
    #include "clock/clock_interface.h"
  #endif
#ifdef __cplusplus
    extern "C" {
#endif


#define DDS_C_TEST_DSN_MAX_LENGTH 100
#define DDS_C_TEST_LIBNAME_MAX_LENGTH 255
#define DDS_C_TEST_MAX_TEST_DATABASES 10

extern DDSCDllExport
RTIBool DDSCTesterHelper_cacheLoggingConfiguration(void);

extern DDSCDllExport
RTIBool DDSCTesterHelper_restoreLoggingConfiguration(void);

struct RTIDDSCTestOdbcDatabaseInfo {
    char DSN[DDS_C_TEST_DSN_MAX_LENGTH];
    char odbcDatabaseLib[DDS_C_TEST_LIBNAME_MAX_LENGTH];
};

struct RTIDDSCTestSetting {
    struct RTITestSetting parent;
    int numOdbcDatabases;
    int odbcDatabaseIndex;
    struct RTIDDSCTestOdbcDatabaseInfo 
        testOdbcDatabaseInfo[DDS_C_TEST_MAX_TEST_DATABASES];
    const char *libraryName;
    const char *profileName;
};


#ifdef __cplusplus
    }	/* extern "C" */
#endif

#endif /* dds_c_test_h */
