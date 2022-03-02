cmake_minimum_required(VERSION 3.17)

### CMAKE BEGIN ###
project(DynamicTypes VERSION 0.3)

set(CMAKE_DEBUG_POSTFIX _debug)                                   # Suffix for output files when using --config=Debug
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)   # Output library for static libs
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")  # Custom module dir

# Include modules
include(platform_tools)
include(dependency_downloader) 

### Determine compiler and thus RTi platform/libs to use ###
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  message(FATAL_ERROR "RTi libs not available for Clang")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 7.3.0)
    message("GCC 7.3.0 or higher is present")
  else()
    message(FATAL_ERROR "RTi libs not available for GCC version < 7.3.0")
  endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  message(FATAL_ERROR "RTi libs not available for intel compiler")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
  if(${MSVC_TOOLSET_VERSION} VERSION_GREATER_EQUAL 141)
    message("MSVC 2017 or higher is present")
    set(PLATFORM "x64Win64VS2017")
  else()
    message(FATAL_ERROR "RTi libs not available for MSVC version < 2017")
  endif()
else()
  message(FATAL_ERROR "No RTi libs available for compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

message("Using RTi platform: ${PLATFORM}")

# Download headers and core RTi libs for given platform
# Sets RTI_CORE_LIBS_DIR and RTI_HEADERS_DIR
download_resources_for_rti_platform(${PLATFORM})

### Create targets ###
set(TARGET_DDS_INTERFACE_LIB_STANDALONE "${PROJECT_NAME}")
add_library(${TARGET_DDS_INTERFACE_LIB_STANDALONE} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h)

set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

### Specify include directories ###
set(INCLUDES
  "${RTI_HEADERS_DIR}/include;"
  "${RTI_HEADERS_DIR}/include/ndds;"
  "${RTI_HEADERS_DIR}/include/ndds/hpp;"
)

# Set include directories
target_include_directories(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC ${INCLUDES})

set(CORE_RTI_LIBS 
  "nddscpp2z"
  "nddscz" 
  "nddscorez"
)

set(CORE_RTI_LIBS_DEBUG
  "nddscpp2zd"
  "nddsczd" 
  "nddscorezd"
)

### Link libraries ###
set(ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE
  ${CORE_RTI_LIBS}
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG
  ${CORE_RTI_LIBS_DEBUG}
)

# Set link library directories
set(LINK_LIBRARY_DIRS
  "${RTI_CORE_LIBS_DIR}/${PLATFORM};"
)

### Perform platform specific cmake instructions ###
if(WIN32)
  include(windows)
elseif(UNIX)
  include(linux)
else()
  message(FATAL_ERROR "Unsupported platform for building static library. Exiting..")
endif()

### Set linker flags ###

# Set link lib dirs 
target_link_directories(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC "${LINK_LIBRARY_DIRS}")
# Set link libs
target_link_libraries(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )

message("Build using: cmake --build . --config=<Debug|Release>")