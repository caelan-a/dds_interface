cmake_minimum_required(VERSION 3.17)

### USER DEFINED PARAMETERS
set(ROOT_INCLUDE_DIR ${CMAKE_BINARY_DIR}/../../../build/out/include)
set(ROOT_LIB_DIR ${CMAKE_BINARY_DIR}/../../../build/out/lib)

# Check if rti headers and libs have been imported into project dir
if(NOT IS_DIRECTORY "${ROOT_INCLUDE_DIR}")
  message(FATAL_ERROR "RTi headers have not been imported into project. Please use DDS Interface repo to export and place in at ${ROOT_INCLUDE_DIR}\nChange path at CMakeLists.txt:4")
endif()

if(NOT IS_DIRECTORY "${ROOT_LIB_DIR}")
  message(FATAL_ERROR "RTi libs have not been imported into project. Please use DDS Interface repo to export and place in at ${ROOT_LIB_DIR}\nChange path at CMakeLists.txt:5")
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

# Load in NDDSHOME from system environment
set(NDDS_HOME $ENV{NDDSHOME})

### CMAKE BEGIN ###
project(DynamicTypes VERSION 1.1)

### Create targets ###
add_executable(${PROJECT_NAME} load_dynamic_type.cpp)

# Set MSVC specific properties
if ( MSVC )
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY} )
endif ( MSVC )

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

### Specify include directories ###
set(INCLUDES
  "${ROOT_INCLUDE_DIR};"
  "${ROOT_INCLUDE_DIR}/rti_headers;"
  "${ROOT_INCLUDE_DIR}/rti_headers/ndds;"
  "${ROOT_INCLUDE_DIR}/rti_headers/ndds/hpp;"
)
message("Looking for headers in: ${INCLUDES};")

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDES})

### Link libraries ###

set(ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG
  "nddscpp2zd"
  "nddsczd"
  "nddscorezd"
  "dds_interface_standalone_debug"
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE
  "nddscpp2z"
  "nddscz"
  "nddscorez"
  "dds_interface_standalone"
)

if (WIN32)
  set(NATIVE_WIN_LIBS
  "netapi32"
  "advapi32"
  "user32"
  "WS2_32"
  )

  list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG ${NATIVE_WIN_LIBS})
  list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE ${NATIVE_WIN_LIBS})
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )

# Include pthreads and libdl for unix
if(UNIX)
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)
  target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads ${CMAKE_DL_LIBS})
endif()

# Set link library directories
message("Looking for libraries in: ${ROOT_LIB_DIR};")
target_link_directories(${PROJECT_NAME} PUBLIC "${ROOT_LIB_DIR}")

### Copy over resources ### 
FILE(COPY message.xml DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

### Add preprocessor definitions ###
target_compile_definitions(${PROJECT_NAME} PUBLIC NDDS_DLL_VARIABLE; _CONSOLE; _SCL_SECURE_NO_WARNINGS;)

# Add platform specific preprocessor definitions
if(WIN32)
  target_compile_definitions(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:WIN32_LEAN_AND_MEAN WIN32 RTI_WIN32 _DEBUG>
    $<$<CONFIG:Release>:WIN32_LEAN_AND_MEAN WIN32 RTI_WIN32>
  )
elseif(UNIX)
  target_compile_definitions(${PROJECT_NAME} PUBLIC UNIX; RTI_UNIX; _DEBUG)
endif()

### CPACK
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
