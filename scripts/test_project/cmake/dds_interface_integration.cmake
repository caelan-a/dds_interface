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
        configure_for_executable_windows(${TARGET})
    elseif(UNIX)
        include(linux)
        configure_for_linux(${TARGET})
    else()
        message(FATAL_ERROR "Unsupported platform for building static library. Exiting..")
    endif()

    ### Set linker flags ###
    # Set link lib dirs 
    target_link_directories(${TARGET} PUBLIC "${LINK_LIBRARY_DIRS}")
    # Set link libs
    target_link_libraries(${TARGET} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )
endfunction()