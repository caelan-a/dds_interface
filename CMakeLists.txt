cmake_minimum_required(VERSION 3.12)

set(CMAKE_DEBUG_POSTFIX _debug)

### Load in DDS Platform ###
if(NOT ${PLATFORM} STREQUAL "")
message("PLATFORM: ${PLATFORM}")
else()
message( FATAL_ERROR "Platform argument is missing, please specify. \nEg. cmake -DPLATFORM=x64Win64VS2017 ../")
endif()

### Load in NDDSHOME from system environment ###
set(NDDS_HOME $ENV{NDDSHOME})
STRING(REGEX REPLACE "\\\\" "/" NDDS_HOME ${NDDS_HOME}) 
if(NDDS_HOME)
message("NDDSHOME: ${NDDS_HOME}")
else()
message( FATAL_ERROR "Missing NDDSHOME in environment variables, please set.\nThis is needed to find RTi headers and libs" )
endif()

### CMAKE BEGIN ###
project(dds_interface VERSION 1.0)

### Create targets ###
set(TARGET_DDS_INTERFACE_LIB_STANDALONE "${PROJECT_NAME}_standalone")
add_library(${TARGET_DDS_INTERFACE_LIB_STANDALONE} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h)
set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

### Specify include directories ###
set(INCLUDES
  "${NDDS_HOME}/include;"
  "${NDDS_HOME}/include/ndds;"
  "${NDDS_HOME}/include/ndds/hpp;"
)

# Set include directories
target_include_directories(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC ${INCLUDES})

### Link libraries ###

# Specify platform dependencies
set(PLATFORM_LIB_DEPENDENCIES_WITH_EXTENSION
  "netapi32.lib"
  "advapi32.lib"
  "user32.lib"
  "WS2_32.lib"
)
STRING(REGEX REPLACE ".lib" "" PLATFORM_LIB_DEPENDENCIES ${PLATFORM_LIB_DEPENDENCIES_WITH_EXTENSION}) 

# Specify debug libraries
set(ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG
  "nddscpp2zd"
  "nddsczd"
  "nddscorezd"
  ${PLATFORM_LIB_DEPENDENCIES}
)

# Specify release libraries
set(ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE
  "nddscpp2z"
  "nddscz"
  "nddscorez"
  ${PLATFORM_LIB_DEPENDENCIES}
)
target_link_libraries(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )

# Set link library directories
set(LINK_LIBRARY_DIRS
  "${NDDS_HOME}/lib/${DDS_PLATFORM};"
)
target_link_directories(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC "${LINK_LIBRARY_DIRS}")

### Add preprocessor definitions ###
target_compile_definitions(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PRIVATE
  $<$<CONFIG:Debug>:NDDS_DLL_VARIABLE WIN32_LEAN_AND_MEAN _DEBUG _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS>
  $<$<CONFIG:Release>:NDDS_DLL_VARIABLE WIN32_LEAN_AND_MEAN _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS>
)

### Merge lib target and rti dependencies into single static lib ###

# CMAKE_AR evaluates to path of lib.exe on windows for linking static libraries
if(CMAKE_AR)
    message("Found binary for CMAKE_AR. Creating target to automatically bundle RTi libs and some system deps into dds_interface.lib and dds_interface_debug.lib")

    # Create DEBUG RTi library targets
    add_library(nddscpp2zd SHARED IMPORTED )
    set_target_properties( nddscpp2zd PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/nddscpp2zd.lib IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/nddscpp2zd.lib )
    add_library(nddsczd SHARED IMPORTED )
    set_target_properties( nddsczd PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/nddsczd.lib IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/nddsczd.lib )
    add_library(nddscorezd SHARED IMPORTED )
    set_target_properties( nddscorezd PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/nddscorezd.lib IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/nddscorezd.lib )
    
    # Create DEBUG RTi library targets
    add_library(nddscpp2z SHARED IMPORTED )
    set_target_properties( nddscpp2z PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/nddscpp2z.lib IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/nddscpp2z.lib )
    add_library(nddscz SHARED IMPORTED )
    set_target_properties( nddscz PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/nddscz.lib IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/nddscz.lib )
    add_library(nddscorez SHARED IMPORTED )
    set_target_properties( nddscorez PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/nddscorez.lib IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/nddscorez.lib )
  
    # Create custom target for static library combination DEBUG
    add_custom_target(BundleStaticLibs ALL
        COMMAND ${CMAKE_AR} /OUT:$<TARGET_FILE_DIR:${TARGET_DDS_INTERFACE_LIB_STANDALONE}>/"${PROJECT_NAME}$<$<CONFIG:Debug>:${CMAKE_DEBUG_POSTFIX}>.lib"
            $<TARGET_FILE:${TARGET_DDS_INTERFACE_LIB_STANDALONE}> 
            "$<TARGET_FILE:nddscpp2z$<$<CONFIG:Debug>:d>>"
            "$<TARGET_FILE:nddscz$<$<CONFIG:Debug>:d>>" 
            "$<TARGET_FILE:nddscorez$<$<CONFIG:Debug>:d>>"
            ${PLATFORM_LIB_DEPENDENCIES_WITH_EXTENSION}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )

else()
  message("Failed to find binary for CMAKE_AR. You will have to manually bundle RTi libraries with interface..")
endif()

# Copy includes for usage with static library for convenient export.
set(HEADER_EXPORT_DIR "${CMAKE_CURRENT_BINARY_DIR}/include")
if(NOT IS_DIRECTORY "${HEADER_EXPORT_DIR}")
message("Copying headers from DDSHOME and root for easy export..")
message("Copying from ${NDDS_HOME}/include to ${HEADER_EXPORT_DIR}")
file(COPY "${NDDS_HOME}/include" DESTINATION "${HEADER_EXPORT_DIR}") 
file(RENAME "${HEADER_EXPORT_DIR}/include" "${HEADER_EXPORT_DIR}/rti_headers") 
file(COPY "DDSInterface.h" DESTINATION "${HEADER_EXPORT_DIR}/") 
file(COPY "DDSPublisher.h" DESTINATION "${HEADER_EXPORT_DIR}/") 
else()
message("Export headers already copied")
endif()

message("Build using: cmake --build . --config=<Debug|Release>")