cmake_minimum_required(VERSION 3.17)

### CMAKE BEGIN ###
project(dds_wrapper_library VERSION 0.3)


# Include modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake")   # Custom module dir
include(dds_interface_integration)

set(CMAKE_DEBUG_POSTFIX _debug)                                       # Suffix for output files when using --config=Debug

##################################################################################
### BuildStaticLib Target - Allows building of static library for external use ###
##################################################################################

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)       # Output library for static libs

### Create target ###
set(STATIC_LIB_TARGET_NAME "BuildStaticLib")
add_library(${STATIC_LIB_TARGET_NAME} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h)

# Set target as default startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${STATIC_LIB_TARGET_NAME})

# Set library output name
set_target_properties(${STATIC_LIB_TARGET_NAME} PROPERTIES OUTPUT_NAME "dds_interface")

# Integrate DDS libraries and headers (FALSE argument means core libs ONLY, not previously compiled wrapper library to avoid link conflict)
integrate_dds_interface(${STATIC_LIB_TARGET_NAME} FALSE)

#####################################################################
### TestWrapper Target - Allows running of static lib for testing ###
#####################################################################

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)   # Output dir for executable

set(EXECUTABLE_TARGET_NAME "TestWrapper")

add_executable(${EXECUTABLE_TARGET_NAME} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h test_wrapper_library.cpp test_message.xml)

add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/../thirdparty/win/pugixml-1.12" "${CMAKE_CURRENT_LIST_DIR}/../thirdparty/win/pugixml-1.12/build" EXCLUDE_FROM_ALL)
target_link_libraries(${EXECUTABLE_TARGET_NAME} PUBLIC pugixml)

# Set working directory as the root of the project so VSCode is using the most logical spot for new resources
set_property(TARGET ${EXECUTABLE_TARGET_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "$(ProjectDir)/..")

# Set binary output name
set_target_properties(${EXECUTABLE_TARGET_NAME} PROPERTIES OUTPUT_NAME "DDSInterfaceTest")

# Integrate DDS libraries and headers (FALSE argument means core libs ONLY, not previously compiled wrapper library to avoid link conflict)
integrate_dds_interface(${EXECUTABLE_TARGET_NAME} FALSE)

# Copy over message.xml
set(DDS_TYPE_XML_FILE_NAME "test_message.xml")
message("CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
add_custom_command(TARGET ${EXECUTABLE_TARGET_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/${DDS_TYPE_XML_FILE_NAME}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>"
  COMMENT "Copying 'message.xml' to '${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>'"
)

message("Build using: cmake --build . --config=<Debug|Release>")