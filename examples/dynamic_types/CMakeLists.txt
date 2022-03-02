# @author Caelan Anderson
# @email caelan.andsn@gmail.com
# @create date 2022-03-02 13:48:33
# @modify date 2022-03-02 13:48:42
# @desc This CMake supports windows and linux and integrates core rti DDS libs in addition to the DDS Interface convenience wrapper 

cmake_minimum_required(VERSION 3.17)

## USER PARAM
set(DDS_TYPE_XML_FILE_NAME "message.xml")

### CMAKE BEGIN ###
project(DynamicTypes VERSION 0.3)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)   # Output dir for executable

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../../cmake")  # Custom module dir

# Include modules
include(platform_tools)
include(dependency_downloader) 

# Get RTI Platform. Sets RTI_PLATFORM
get_rti_platform()
message("Using RTi platform: ${RTI_PLATFORM}")

# Download headers and core RTi libs for given platform
# Sets RTI_CORE_LIBS_DIR and RTI_HEADERS_DIR
download_resources_for_rti_platform(${RTI_PLATFORM})

# Downloads headers and libs for given RTI_PLATFORM
# Sets DDS_INTERFACE_PRECOMPILED_LIBS_DIR DDS_INTERFACE_HEADERS_DIR
download_dds_interface_precompiled_libs_and_headers(${RTI_PLATFORM})

### Create targets ###
add_executable(${PROJECT_NAME} load_dynamic_type.cpp load_dynamic_type.hpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

### Specify include directories ###
set(INCLUDES
  "${RTI_HEADERS_DIR}/include;"
  "${RTI_HEADERS_DIR}/include/ndds;"
  "${RTI_HEADERS_DIR}/include/ndds/hpp;"
  "${DDS_INTERFACE_HEADERS_DIR};"
)

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})

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
  "dds_interface"
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG
  ${CORE_RTI_LIBS_DEBUG}
  "dds_interface_debug"
)


# Set link library directories
set(LINK_LIBRARY_DIRS
  "${RTI_CORE_LIBS_DIR}/${RTI_PLATFORM};"
  "${DDS_INTERFACE_PRECOMPILED_LIBS_DIR}/${RTI_PLATFORM};"
)

### Perform platform specific cmake instructions ###
if(WIN32)
  include(windows)
  configure_for_executable_windows(${PROJECT_NAME})
elseif(UNIX)
  include(linux)
  configure_for_linux(${PROJECT_NAME})
else()
  message(FATAL_ERROR "Unsupported platform for building static library. Exiting..")
endif()

### Set linker flags ###
# Set link lib dirs 
target_link_directories(${PROJECT_NAME} PUBLIC "${LINK_LIBRARY_DIRS}")
# Set link libs
target_link_libraries(${PROJECT_NAME} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )

# Copy .xml
message("CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR}")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_LIST_DIR}/${DDS_TYPE_XML_FILE_NAME}" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>"
  COMMENT "Copying 'message.xml' to '${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>'"
  )

message("Build using: cmake --build . --config=<Debug|Release>")