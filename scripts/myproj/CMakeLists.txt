cmake_minimum_required(VERSION 3.17)

project(myproj VERSION 0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)   # Output dir for executable

# Include modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") 
include(dds_interface_integration)

# Create exe target
add_executable(${PROJECT_NAME} myproj.cpp myproj.hpp example_message.xml)

# Set target as default startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# Set working directory as output dir
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "$(OutDir)")

# Integrate DDS libraries and headers
integrate_dds_interface(${PROJECT_NAME})


###
### Start writing your project specific code!
###

# Copy over example_message.xml for use by executable. This is here just to support the example publisher code generated
set(DDS_TYPE_XML_FILE_NAME "example_message.xml")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/${DDS_TYPE_XML_FILE_NAME}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>"
  COMMENT "Copying 'message.xml' to '${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>'"
)

message("Build using: cmake --build . --config=<Debug|Release>")
