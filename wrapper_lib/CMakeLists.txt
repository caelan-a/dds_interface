cmake_minimum_required(VERSION 3.17)

### CMAKE BEGIN ###
project(dds_wrapper_library VERSION 0.3)

set(CMAKE_DEBUG_POSTFIX _debug)                                   # Suffix for output files when using --config=Debug
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)   # Output library for static libs
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake")  # Custom module dir

# Include modules
include(platform_tools)
include(dependency_downloader) 

# Get RTI Platform. Sets RTI_PLATFORM
get_rti_platform()
message("Using RTi platform: ${RTI_PLATFORM}")

# Download headers and core RTi libs for given platform
# Sets RTI_CORE_LIBS_DIR and RTI_HEADERS_DIR
download_resources_for_rti_platform(${RTI_PLATFORM})

### Create targets ###
set(TARGET_DDS_INTERFACE_LIB_STANDALONE "${PROJECT_NAME}")
add_library(${TARGET_DDS_INTERFACE_LIB_STANDALONE} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h)

# Set target as default startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${TARGET_DDS_INTERFACE_LIB_STANDALONE})

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
  configure_for_static_library_windows(${TARGET_DDS_INTERFACE_LIB_STANDALONE} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
elseif(UNIX)
  include(linux)
  configure_for_linux(${TARGET_DDS_INTERFACE_LIB_STANDALONE} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
else()
  message(FATAL_ERROR "Unsupported platform for building static library. Exiting..")
endif()

### Set linker flags ###
# Set link lib dirs 
target_link_directories(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC "${LINK_LIBRARY_DIRS}")
# Set link libs
target_link_libraries(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )


### Add executable target to test code ###
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)   # Output dir for executable
set(EXECUTABLE_TARGET_NAME "TestWrapper")

# Include modules
include(dds_interface_integration)

add_executable(${EXECUTABLE_TARGET_NAME} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h test_wrapper_library.cpp test_message.xml)

# Integrate DDS libraries and headers (FALSE argument means core libs ONLY, not previously compiled wrapper library to avoid link conflict)
integrate_dds_interface(${EXECUTABLE_TARGET_NAME} FALSE)

# Set working directory as the root of the project so VSCode is using the most logical spot for new resources
set_property(TARGET ${EXECUTABLE_TARGET_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)/..")

# Copy over message.xml
set(DDS_TYPE_XML_FILE_NAME "test_message.xml")
message("CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
add_custom_command(TARGET ${EXECUTABLE_TARGET_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/${DDS_TYPE_XML_FILE_NAME}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>"
  COMMENT "Copying 'message.xml' to '${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>'"
)

message("Build using: cmake --build . --config=<Debug|Release>")