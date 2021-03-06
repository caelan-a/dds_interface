function(integrate_dds_interface TARGET WITH_WRAPPER_LIB)
    if((NOT WIN32) AND (NOT UNIX))
        message(FATAL_ERROR "Unsupported platform for building static library. Exiting..")
    endif()    

    # Include modules
    include(platform_tools)
    include(dependency_downloader) 

    # Get RTI Platform. Sets RTI_PLATFORM
    get_rti_platform()
    message("Using RTi platform: ${RTI_PLATFORM}")

    # Download headers and core RTi libs for given platform
    # Sets RTI_CORE_LIBS_DIR and RTI_HEADERS_DIR
    download_resources_for_rti_platform(${RTI_PLATFORM})

    set_target_properties(${TARGET} PROPERTIES
        CXX_STANDARD 11
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
    )

    ### Specify include directories ###
    set(INCLUDES
        "${RTI_HEADERS_DIR};"
        "${RTI_HEADERS_DIR}/ndds;"
        "${RTI_HEADERS_DIR}/ndds/hpp;"
    )

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
        "${RTI_CORE_LIBS_DIR}"
    )

    # If integrating with DDS Interface wrapper library, add headers and libs appropriately
    if(WITH_WRAPPER_LIB)
        message("Integrating DDS with DDS Interface wrapper lib")
        
        # Downloads headers and libs for given RTI_PLATFORM
        # Sets DDS_INTERFACE_PRECOMPILED_LIBS_DIR DDS_INTERFACE_HEADERS_DIR
        download_diwrapper_deps_all(${RTI_PLATFORM})

        list(APPEND INCLUDES "${DDS_INTERFACE_HEADERS_DIR};")
        list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE "dds_interface")
        list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG "dds_interface_debug")
        list(APPEND LINK_LIBRARY_DIRS "${DDS_INTERFACE_PRECOMPILED_LIBS_DIR}")
    else()
        message("Integrating DDS with only core RTi libs")
    endif()

    #  Do windows specific config. Note that it must be before target_link_libraries or it will break. Yet to determine why
    if(WIN32)
        include(windows)
        configure_for_executable_windows(${TARGET})
    endif()

    ### Set target properties ###
    # Set include directories
    target_include_directories(${TARGET} PUBLIC ${INCLUDES})
    # Set link lib dirs 
    target_link_directories(${TARGET} PUBLIC "${LINK_LIBRARY_DIRS}")
    # Set link libs
    target_link_libraries(${TARGET} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )

    #  Do linux specific config. Note that it must be after target_link_libraries or it will break. Yet to determine why
    if(UNIX)
        include(linux)
        configure_for_linux(${TARGET})
    endif()

endfunction()