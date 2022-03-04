function(integrate_dds_interface TARGET)
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

    set_target_properties(${TARGET} PROPERTIES
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
    target_include_directories(${TARGET} PUBLIC ${INCLUDES})

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

  link(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG ${NATIVE_WIN_LIBS})
  link(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE ${NATIVE_WIN_LIBS})
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
target_compile_definitions(${PROJECT_NAME} PUBLIC NDDS_DLL_VARIABLE; _DEBUG; _CONSOLE; _SCL_SECURE_NO_WARNINGS;)

if (WIN32)
target_compile_definitions(${PROJECT_NAME} PUBLIC WIN32_LEAN_AND_MEAN; WIN32; RTI_WIN32;)
elseif(UNIX)
target_compile_definitions(${PROJECT_NAME} PUBLIC ; UNIX; RTI_UNIX;)
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


endfunction()