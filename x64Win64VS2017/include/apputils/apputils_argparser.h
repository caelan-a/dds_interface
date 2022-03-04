/*
 (c) Copyright, Real-Time Innovations, 2021.
 All rights reserved.

 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
=========================================================================*/

#ifndef apputils_argparser_h
#define apputils_argparser_h

#ifndef osapi_type_h
  #include "osapi/osapi_type.h"
#endif

#ifndef apputils_dll_h
  #include "apputils/apputils_dll.h"
#endif

#ifndef ndds_c_h
  #include "ndds/ndds_c.h"
#endif

#include "rtixmlutils/rtixmlutils_property.h"

#ifdef __cplusplus
    extern "C" {
#endif

typedef enum {
    /*e
     * @brief value = NULL
     */
    APPUTILS_ARGPARSER_VOID_ARGUMENT_TYPE = 0,
    /*e
     * @brief value = enum *
     */
    APPUTILS_ARGPARSER_ENUM_ARGUMENT_TYPE,
    /*e
     * @brief value = char *
     */
    APPUTILS_ARGPARSER_STRING_ARGUMENT_TYPE,
    /*e
     * @brief value = DDS_UnsignedLong **
     */
    APPUTILS_ARGPARSER_INT_ARGUMENT_TYPE,
    /*e
     * @brief value = double *
     */
    APPUTILS_ARGPARSER_DOUBLE_ARGUMENT_TYPE
} APPUTILSArgParserArgumentType;


struct APPUTILSArgParserEnumValue {
    const char **values;
    int value_count;
};


struct APPUTILSArgParserArgumentDesc {
    /*e
     * @brief Argument name.
     */
    const char *const name;
    /*e
     * @brief Argument type.
     */
    APPUTILSArgParserArgumentType type;
    /*e
     * @brief Argument description.
     */
    const char *const description;
    /*e
     * @brief Enum values.
     */
    struct APPUTILSArgParserEnumValue enum_value;
    /*e
     * @brief Indicates if an argument is required.
     */
    DDS_Boolean required;
    /*e
     * @brief Indicates if an argument is public (visible to the user)
     */
    DDS_Boolean visible;
    /*e
     * @brief Indicates if the value of an argument is optional
     */
    DDS_Boolean optional_value;
};


typedef union APPUTILSArgParserArgumentValue{
    DDS_UnsignedLong int_value;
    double double_value;
    char *char_value;
} APPUTILSArgParserArgumentValue;


struct APPUTILSArgParserArgument {
    DDS_Boolean exists;
    union APPUTILSArgParserArgumentValue value;
};


struct APPUTILSArgParser {
    /* Command line arguments */
    /*e
     * @brief List of arguments values
     */
    struct APPUTILSArgParserArgument *argument_list;

    /*e
     * @brief Total count of arguments
     */
    int argument_count;

    /*e
     * @brief List of user variables values
     */
    struct RTIXMLUTILSPropertyList user_variable_list;

    /*e
     * @brief Argument description list
     */
    const struct APPUTILSArgParserArgumentDesc *description_list;
};


/*e
 * @brief EnumValue initializer.
 */
#define APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER \
{ \
    NULL, \
    0 \
}


/*e
 * @brief ArgParser initializer.
 */
#define APPUTILS_ARGPARSER_INITIALIZER \
{ \
    NULL, \
    0, \
    { \
        NULL, \
        0, \
        0 \
    }, \
    NULL \
}

/*e
 * @brief appName option description
 */
#define APPUTILS_ARGPARSER_APPNAME_DESCRIPTION \
    { \
        "appName", \
        APPUTILS_ARGPARSER_STRING_ARGUMENT_TYPE, \
        "Application name\n" \
        "Used to identify this execution for \n" \
        "remote administration and monitoring,\n" \
        "and to name the DDS DomainParticipant.\n" \
        "Default: -cfgName\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief cfgfile option description
 */
#define APPUTILS_ARGPARSER_CFGFILE_DESCRIPTION \
    { \
        "cfgFile", \
        APPUTILS_ARGPARSER_STRING_ARGUMENT_TYPE, \
        "Semicolon-separated list of \n" \
        "configuration file paths.\n" \
        "Default: (unspecified)\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief cfgName option description
 */
#define APPUTILS_ARGPARSER_CFGNAME_DESCRIPTION \
    { \
        "cfgName", \
        APPUTILS_ARGPARSER_STRING_ARGUMENT_TYPE, \
        "Name of the configuration to be loaded.\n" \
        "It must match a <routing_service> \n" \
        "tag in the configuration.\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief heapSnapshotPeriod option description
 */
#define APPUTILS_ARGPARSER_HEAPSNAPSHOT_PERIOD_DESCRIPTION \
     { \
        "heapSnapshotPeriod" , \
        APPUTILS_ARGPARSER_INT_ARGUMENT_TYPE, \
        "Period at which heap monitoring snapshots\n" \
        "are dumped. Enables heap monitoring if > 0.\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief heapSnapshotDir option description
 */
#define APPUTILS_ARGPARSER_HEAPSNAPSHOT_DIR_DESCRIPTION \
    { \
        "heapSnapshotDir", \
        APPUTILS_ARGPARSER_STRING_ARGUMENT_TYPE, \
        "Output directory where the heap \n" \
        "monitoring snapshot are dumped.\n" \
        "The filename format is \n" \
        "RTI_heap_<appName>_<processId>_<index>.log\n" \
        "Default: current working directory\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }
/*e
 * @brief help option description
 */
#define APPUTILS_ARGPARSER_HELP_DESCRIPTION \
    { \
        "help", \
        APPUTILS_ARGPARSER_VOID_ARGUMENT_TYPE, \
        "Prints this help and exits.\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_TRUE \
    }
/*e
 * @brief maxObjectsPerThread option description
 */
#define APPUTILS_ARGPARSER_MAXOBJPERTHREAD_DESCRIPTION \
    { \
        "maxObjectsPerThread", \
        APPUTILS_ARGPARSER_INT_ARGUMENT_TYPE, \
        "Maximum number of Thread-specific\n" \
        "objects that can be created.\n" \
        "Default: 2048\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief remoteAdministrationDomainId option description
 */
#define APPUTILS_ARGPARSER_REMOTEADMIN_DOMAINID_DESCRIPTION \
    { \
        "remoteAdministrationDomainId", \
        APPUTILS_ARGPARSER_INT_ARGUMENT_TYPE, \
        "Enables remote administration and\n" \
        "sets the domain ID for communication.\n" \
        "Default: remote administration is not enabled\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief remoteMonitoringDomainId option description
 */
#define APPUTILS_ARGPARSER_REMOTEMONITOR_DOMAINID_DESCRIPTION \
    { \
        "remoteMonitoringDomainId", \
        APPUTILS_ARGPARSER_INT_ARGUMENT_TYPE, \
        "Enables remote monitoring and\n" \
        "sets the domain ID for status publication.\n" \
        "Default: remote monitoring is not enabled.\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief verbosity option description
 */
#define APPUTILS_ARGPARSER_VERBOSITY_DESCRIPTION \
    { \
        "verbosity", \
        APPUTILS_ARGPARSER_STRING_ARGUMENT_TYPE, \
        "Syntax is <service_level>[:<dds_level>], where:\n" \
        "<service_level> is the verbosity level for the\n" \
        "service logs and <dds_level> is the verbosity level\n" \
        "for the DDS logs. Both can take any of the \n" \
        "following values:\n" \
        "* SILENT\n" \
        "* ERROR\n" \
        "* WARN\n" \
        "* LOCAL\n" \
        "* REMOTE\n" \
        "* ALL\n" \
        "Default: ERROR:ERROR.\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_FALSE \
    }

/*e
 * @brief version option description
 */
#define APPUTILS_ARGPARSER_VERSION_DESCRIPTION \
    { \
        "version", \
        APPUTILS_ARGPARSER_VOID_ARGUMENT_TYPE, \
        "Prints the product version and exits.\n", \
        APPUTILS_ARGPARSER_ENUM_VALUES_INITIALIZER, \
        DDS_BOOLEAN_FALSE, \
        DDS_BOOLEAN_TRUE, \
        DDS_BOOLEAN_TRUE \
    }

/*e
 * @brief Argument description initializer.
 */
#define APPUTILS_ARGPARSER_DESCRIPTION_INITIALIZER \
    APPUTILS_ARGPARSER_APPNAME_DESCRIPTION, \
    APPUTILS_ARGPARSER_CFGFILE_DESCRIPTION, \
    APPUTILS_ARGPARSER_CFGNAME_DESCRIPTION, \
    APPUTILS_ARGPARSER_HEAPSNAPSHOT_PERIOD_DESCRIPTION, \
    APPUTILS_ARGPARSER_HEAPSNAPSHOT_DIR_DESCRIPTION, \
    APPUTILS_ARGPARSER_HELP_DESCRIPTION, \
    APPUTILS_ARGPARSER_MAXOBJPERTHREAD_DESCRIPTION, \
    APPUTILS_ARGPARSER_REMOTEADMIN_DOMAINID_DESCRIPTION, \
    APPUTILS_ARGPARSER_REMOTEMONITOR_DOMAINID_DESCRIPTION, \
    APPUTILS_ARGPARSER_VERBOSITY_DESCRIPTION, \
    APPUTILS_ARGPARSER_VERSION_DESCRIPTION


extern APPUTILSDllExport
void APPUTILSArgParser_print_version(const char *product_name);

extern APPUTILSDllExport
void APPUTILSArgParser_print_usage(const char *executable_name);

extern APPUTILSDllExport
void APPUTILSArgParser_print_help(
        const char *product_name,
        const char *executable_name,
        const struct APPUTILSArgParserArgumentDesc *description_list,
        int argument_count);

extern APPUTILSDllExport
DDS_UnsignedLong APPUTILSArgParser_get_user_env_count(
        const int argc,
        const char **argv);

extern APPUTILSDllExport
DDS_Boolean APPUTILSArgParser_has_argument(
        const int argc,
        const char **argv,
        const char *param_name);

extern APPUTILSDllExport
struct APPUTILSArgParser * APPUTILSArgParser_new(
        const struct APPUTILSArgParserArgumentDesc *description_list,
        int argument_count,
        int user_variable_count);

extern APPUTILSDllExport
void APPUTILSArgParser_delete(struct APPUTILSArgParser *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSArgParser_initialize(
        struct APPUTILSArgParser *self,
        const struct APPUTILSArgParserArgumentDesc *description_list,
        int argument_count,
        int user_variable_count);

/*e
 * @brief Finalize an ArgParser instance
 * @param[in,out] self the ArgParser instance
 */
extern APPUTILSDllExport
void APPUTILSArgParser_finalize(struct APPUTILSArgParser *self);

extern APPUTILSDllExport
struct APPUTILSArgParserArgument * APPUTILSArgParser_get(
        struct APPUTILSArgParser *self,
        int argument_id);

extern APPUTILSDllExport
struct RTIXMLUTILSPropertyList * APPUTILSArgParser_get_user_environment(
        struct APPUTILSArgParser *self);

extern APPUTILSDllExport
DDS_Boolean APPUTILSArgParser_parse(
        struct APPUTILSArgParser *self,
        const int argc,
        const char **argv);

extern APPUTILSDllExport
void APPUTILSArgParser_configure_log_print_format(
        const struct APPUTILSArgParser *self,
        const int log_format_id);

extern APPUTILSDllExport
DDS_Boolean APPUTILSArgParser_parse_verbosity(
        const struct APPUTILSArgParser *self,
        int *dds_verbosity,
        int *service_verbosity,
        int verbosity_id);


#ifdef __cplusplus
    }	/* extern "C" */
#endif


#endif /* apputils_argparser_h */
