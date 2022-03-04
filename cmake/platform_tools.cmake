cmake_minimum_required(VERSION 3.17)

### Functions ###
# Generate filename for static library on current platform
function(get_platform_with_lib_extension text OUTPUT_VAR)
if(WIN32)
    set(${OUTPUT_VAR} "${text}.lib" PARENT_SCOPE)
elseif(UNIX)
    set(${OUTPUT_VAR} "lib${text}.a" PARENT_SCOPE)
else()
    message(FATAL_ERROR "Failed to get_platform_with_lib_extension: Unknown platform")
endif()
endfunction()

# Determine compiler and thus RTi platform/libs to use
# Sets following parent scope variable for external use: 
# RTI_PLATFORM
function(get_rti_platform)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(FATAL_ERROR "RTi libs not available for Clang")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 7.3.0)
        set(RTI_PLATFORM "x64Linux4gcc7.3.0" PARENT_SCOPE)
        message("GCC 7.3.0 or higher is present")
    else()
        message(FATAL_ERROR "RTi libs not available for GCC version < 7.3.0")
    endif()
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
        message(FATAL_ERROR "RTi libs not available for intel compiler")
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
    if(${MSVC_TOOLSET_VERSION} VERSION_GREATER_EQUAL 141)
        message("MSVC 2017 or higher is present")
        set(RTI_PLATFORM "x64Win64VS2017" PARENT_SCOPE)
    else()
        message(FATAL_ERROR "RTi libs not available for MSVC version < 2017")
    endif()
    else()
        message(FATAL_ERROR "No RTi libs available for compiler: ${CMAKE_CXX_COMPILER_ID}")
    endif()
endfunction()