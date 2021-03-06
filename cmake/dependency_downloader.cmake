cmake_minimum_required(VERSION 3.17)

list(APPEND SUPPORTED_RTI_PLATFORMS "x64Win64VS2017" "x64Linux4gcc7.3.0")

message("RTi Core Dependency Downloader ready for use. Supported platforms: ${SUPPORTED_RTI_PLATFORMS}")

set(GIT_REMOTE_WITH_RESOURCES "https://dev.azure.com/data6/AMMO/_git/DDS%20Interface")

# These commit tags are used to download dependencies from the above git needed for building against RTi libraries
# Note that the RESOURCE_COMMIT_TAG_RTI_DEPS_* resources contain only the minimal set of rti core libs for hosting reasons.
# If you get undefined symbols error from using RTi ConnextDDS API functions not in examples you likely need to link
# in more core libraries. These can be found in RTi installation media. You should manually update the link_libs and lib_dirs 
# in your cmake project
set(RESOURCE_COMMIT_TAG_RTI_DEPS_X64WIN64VS2017 "208d0d377bfa437f71e70ec7dfd4d08fd7917c0a")
set(RESOURCE_COMMIT_TAG_RTI_DEPS_X64LINUX4GCC730 "dc2fdabe282b72e9abbe66bed493e8a5e59ace0c")

# Includes res for all supported platforms
set(RESOURCE_COMMIT_TAG_DIWRAPPER_DEPS_ALL "0ac6210cd8caf65fc2015d1db7a4c9702bbf8e3d")

include(FetchContent)

# Specify location to download resources to
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/external) 

# Declare resources that can be downloaded
FetchContent_Declare(
  x64Win64VS2017
  GIT_REPOSITORY ${GIT_REMOTE_WITH_RESOURCES}
  GIT_TAG        ${RESOURCE_COMMIT_TAG_RTI_DEPS_X64WIN64VS2017}
  BUILD_COMMAND ""

)

FetchContent_Declare(
  x64Linux4gcc7.3.0
  GIT_REPOSITORY ${GIT_REMOTE_WITH_RESOURCES}
  GIT_TAG        ${RESOURCE_COMMIT_TAG_RTI_DEPS_X64LINUX4GCC730} 
  BUILD_COMMAND ""
)

# 'diwrapper_deps' => dds_interface (wrapper) precompiled libs and headers. 
# Name was shortened as it was maxing out 260char path limit on win
FetchContent_Declare(
  diwrapper_deps
  GIT_REPOSITORY ${GIT_REMOTE_WITH_RESOURCES}
  GIT_TAG        ${RESOURCE_COMMIT_TAG_DIWRAPPER_DEPS_ALL}
  BUILD_COMMAND ""
)

# Downloads headers and libs for given RTI_PLATFORM and sets following parent scope variables
# for external use: RTI_CORE_LIBS_DIR and RTI_HEADERS_DIR
function(download_resources_for_rti_platform RTI_PLATFORM)
    # Check if platform is supported. AKA do we have the libs to build against for that platform
    set(PLATFORM_SUPPORTED FALSE)
    foreach(SUPPORTED_RTI_PLATFORM IN LISTS SUPPORTED_RTI_PLATFORMS)
        if(${RTI_PLATFORM} STREQUAL ${SUPPORTED_RTI_PLATFORM})
            set(PLATFORM_SUPPORTED TRUE)
        endif()
    endforeach()
    
    # FetchContent will download resources from git. It will check first to see if already downloaded. Very handy :)
    if(${PLATFORM_SUPPORTED})
        message("Downloading RTi dependencies (headers and core libraries) for ${RTI_PLATFORM}..")
        message("Fetching from git: ${GIT_REMOTE_WITH_RESOURCES}")

        FetchContent_MakeAvailable(${RTI_PLATFORM}) 

        # Set variables for external use# FetchContent downloads to directory with dirname that is made LOWERCASE
        # We must return a path to dir with using lowercase(${RTI_PLATFORM}) to make sure unix systems can access properly
        string(TOLOWER ${RTI_PLATFORM} RTI_PLATFORM_LOWERCASE)
        
        # Set variables for external use
        set(RTI_CORE_LIBS_DIR "${FETCHCONTENT_BASE_DIR}/${RTI_PLATFORM_LOWERCASE}-src/${RTI_PLATFORM}/lib" PARENT_SCOPE)
        set(RTI_HEADERS_DIR "${FETCHCONTENT_BASE_DIR}/${RTI_PLATFORM_LOWERCASE}-src/${RTI_PLATFORM}/include" PARENT_SCOPE)

        message("Success! Downloaded resources can be found at: ${FETCHCONTENT_BASE_DIR}")
        message("Note that only minimal set of rti core libs are included. May need to link in more for advanced RTi Connext API usage")
    else()
        message(FATAL_ERROR "Unknown RTi platform: ${RTI_PLATFORM}\nUnable to download headers and core RTi libs")
    endif()
endfunction()

# Downloads headers and precompiled libs for DDS Interface
# for external use: DDS_INTERFACE_PRECOMPILED_LIBS_DIR DDS_INTERFACE_HEADERS_DIR
function(download_diwrapper_deps_all RTI_PLATFORM)
    # Check if platform is supported. AKA do we have the libs to build against for that platform
    set(PLATFORM_SUPPORTED FALSE)
    foreach(SUPPORTED_RTI_PLATFORM IN LISTS SUPPORTED_RTI_PLATFORMS)
        if(${RTI_PLATFORM} STREQUAL ${SUPPORTED_RTI_PLATFORM})
            set(PLATFORM_SUPPORTED TRUE)
        endif()
    endforeach()
    
    # FetchContent will download resources from git. It will check first to see if already downloaded. Very handy :)
    if(${PLATFORM_SUPPORTED})
        message("Downloading DDS Interface wrapper dependencies for ${RTI_PLATFORM}..")
        message("Fetching from git: ${GIT_REMOTE_WITH_RESOURCES}")

        FetchContent_MakeAvailable(diwrapper_deps) 

        # Set variables for external use
        set(DDS_INTERFACE_PRECOMPILED_LIBS_DIR "${FETCHCONTENT_BASE_DIR}/diwrapper_deps-src/${RTI_PLATFORM}/lib" PARENT_SCOPE)
        set(DDS_INTERFACE_HEADERS_DIR "${FETCHCONTENT_BASE_DIR}/diwrapper_deps-src/${RTI_PLATFORM}/include" PARENT_SCOPE)

        message("Success! Downloaded resources can be found at: ${FETCHCONTENT_BASE_DIR}")
    else()
        message(FATAL_ERROR "Unknown RTi platform: ${RTI_PLATFORM}\nUnable to download DDS Interface precompiled libs and headers")
    endif()
endfunction()