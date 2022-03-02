macro(_configure_for_windows TARGET)
    # Add windows specific libs
    set(NATIVE_WIN_LIBS
    "netapi32"
    "advapi32"
    "user32"
    "WS2_32"
    )
    list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG ${NATIVE_WIN_LIBS})
    list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE ${NATIVE_WIN_LIBS})

    # Add windows specific preprocessor definitions
    target_compile_definitions(${TARGET} PRIVATE
    $<$<CONFIG:Debug>:WIN32_LEAN_AND_MEAN _DEBUG _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS>
    $<$<CONFIG:Release>:WIN32_LEAN_AND_MEAN _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS>
    )
endmacro()

macro(configure_for_executable_windows TARGET)
    _configure_for_windows(${TARGET})
endmacro()

macro(configure_for_static_library_windows TARGET OUTPUT_DIR)
    # Set Visual Studio specific properties
    # Set suffix for files produced in debug config
    set_target_properties(${TARGET} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
    # Set output dir for static libs
    set_target_properties(${TARGET} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
    # Set output dir for static libs in debug config
    set_target_properties(${TARGET} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR} )
    # Set output dir for static libs in release config
    set_target_properties(${TARGET} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${OUTPUT_DIR} )

    _configure_for_windows(${TARGET})

    target_compile_definitions(${TARGET} PRIVATE NDDS_DLL_VARIABLE)
endmacro()



### BELOW ARE INSTRUCTIONS FOR COMBINING STATIC LIBS ON WINDOWS ###
macro(create_combined_static_library)
    # CMAKE_AR evaluates to path of lib.exe on windows for linking static libraries
    if(CMAKE_AR)
        message("Found binary for CMAKE_AR.")
        ### Create bundled library by combining dds_interface_standalone and core rti libs 
        message("Creating target to automatically bundle RTi libs and some system deps into dds_interface.lib and dds_interface_debug.lib")

        # Create library targets for RTi debug and release libs
        foreach(CORE_RTI_LIB IN LISTS CORE_RTI_LIBS CORE_RTI_LIBS_DEBUG)
        get_platform_with_lib_extension("${CORE_RTI_LIB}" LIB_WITH_EXTENSION)
        add_library(${CORE_RTI_LIB} SHARED IMPORTED )
        set_target_properties( ${CORE_RTI_LIB} PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/${LIB_WITH_EXTENSION} IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/${LIB_WITH_EXTENSION} )
        endforeach()

        # Create custom target for static library combination 
        get_platform_with_lib_extension("${PROJECT_NAME}$<$<CONFIG:Debug>:${CMAKE_DEBUG_POSTFIX}>" LIB_WITH_EXTENSION)
        
        add_custom_target(BundleStaticLibs ALL
            COMMAND ${CMAKE_AR} /OUT:$<TARGET_FILE_DIR:${TARGET_DDS_INTERFACE_LIB_STANDALONE}>/"${LIB_WITH_EXTENSION}"
                "$<TARGET_FILE:${TARGET_DDS_INTERFACE_LIB_STANDALONE}>"
                "$<TARGET_FILE:nddscpp2z$<$<CONFIG:Debug>:d>>"
                "$<TARGET_FILE:nddscz$<$<CONFIG:Debug>:d>>" 
                "$<TARGET_FILE:nddscorez$<$<CONFIG:Debug>:d>>"
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        )
    else()
    message("Failed to find binary for CMAKE_AR. You will have to manually bundle RTi libraries with interface..")
    endif()
endmacro()

