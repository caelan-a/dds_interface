cmake_minimum_required(VERSION 3.17)

project(myproj5 VERSION 0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)   # Output dir for executable

# Include modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") 
include(dds_interface_integration)

add_executable(${PROJECT_NAME} myproj5.cpp myproj5.hpp)

# Integrate DDS libraries and headers
integrate_dds_interface(${PROJECT_NAME})


###
### Start writing your project specific code!
###

message("Build using: cmake --build . --config=<Debug|Release>")
