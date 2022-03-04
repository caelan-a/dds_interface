cmake_minimum_required(VERSION 3.17)

### USER DEFINED PARAMETERS
set(ROOT_INCLUDE_DIR /home/caelan/dev/rti/dds_interface/wrapper_lib/build/external/rti_headers-src/include)
set(ROOT_LIB_DIR /home/caelan/dev/rti/dds_interface/wrapper_lib/build/external/x64linux4gcc7.3.0-src/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

# Load in NDDSHOME from system environment
set(NDDS_HOME $ENV{NDDSHOME})

### CMAKE BEGIN ###
project(DynamicTypes VERSION 1.1)

### Create targets ###
# add_executable(${PROJECT_NAME} load_dynamic_type.cpp)
add_executable(${PROJECT_NAME} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h test_wrapper_library.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

### Specify include directories ###x64Linux4gcc7.3.0
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
)

set(ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE
  "nddscpp2z"
  "nddscz"
  "nddscorez"
)

if (WIN32)
  set(NATIVE_WIN_LIBS
  "netapi32"
  "advapi32"
  "user32"
  "WS2_32"
  )

  link(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG ${NATIVE_WIN_LIBS})
  link(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE ${NATIVE_WIN_LIBS})
endif()

# Include pthreads and libdl for unix
if(UNIX)
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)

  set(LINUX_LIBS
    "Threads::Threads"
    "${CMAKE_DL_LIBS}"
  )
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )
target_link_libraries(${PROJECT_NAME} PRIVATE ${LINUX_LIBS})

get_target_property(OUT ${PROJECT_NAME} LINK_LIBRARIES)
message("OUT: ${OUT}")

# Set link library directories
message("Looking for libraries in: ${ROOT_LIB_DIR};")
target_link_directories(${PROJECT_NAME} PUBLIC "/home/caelan/dev/rti/dds_interface/wrapper_lib/build/external/x64linux4gcc7.3.0-src/x64Linux4gcc7.3.0")

### Copy over resources ### 
FILE(COPY message.xml DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

### Add preprocessor definitions ###
target_compile_definitions(${PROJECT_NAME} PUBLIC NDDS_DLL_VARIABLE; _DEBUG; _CONSOLE; _SCL_SECURE_NO_WARNINGS;)

if (WIN32)
target_compile_definitions(${PROJECT_NAME} PUBLIC WIN32_LEAN_AND_MEAN; WIN32; RTI_WIN32;)
elseif(UNIX)
target_compile_definitions(${PROJECT_NAME} PUBLIC ; UNIX; RTI_UNIX;)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
