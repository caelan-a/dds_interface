cmake_minimum_required(VERSION 3.17)

project(NewProject VERSION 0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)   # Output dir for executable

# Include modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") 
include(dds_interface_integration)

add_executable(${PROJECT_NAME} load_dynamic_type.cpp load_dynamic_type.hpp)

# Integrate DDS libraries and headers
integrate_dds_interface(${PROJECT_NAME})

###
### Replace this block with your project specific code!
### 

# Copy over message.xml
set(DDS_TYPE_XML_FILE_NAME "message.xml")
message("CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/${DDS_TYPE_XML_FILE_NAME}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>"
  COMMENT "Copying 'message.xml' to '${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>'"
)

message("Build using: cmake --build . --config=<Debug|Release>")