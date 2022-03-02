cmake_minimum_required(VERSION 3.17)

list(APPEND SUPPORTED_RTI_PLATFORMS "x64Win64VS2017" "x64Linux4gcc7.3.0")

message("RTi Core Dependency Downloader ready for use. Supported platforms: ${SUPPORTED_RTI_PLATFORMS}")

set(GIT_REMOTE_WITH_RESOURCES "https://github.com/caelan-a/dds_interface.git")

# These commit tags are used to download dependencies from the above git needed for building against RTi libraries
# Note that the RESOURCE_COMMIT_TAG_RTI_LIBS_* resources contain only the minimal set of rti core libs for hosting reasons.
# If you get undefined symbols error from using RTi ConnextDDS API functions not in examples you likely need to link
# in more core libraries. These can be found in RTi installation media. You should manually update the link_libs and lib_dirs 
# in your cmake project
set(RESOURCE_COMMIT_TAG_RTI_HEADERS "f4a25b544a6c7f86d452d9da6e334736aa5ca765")
set(RESOURCE_COMMIT_TAG_RTI_LIBS_X64WIN64VS2017 "31788483398ca72a09c01053551a3637f0a894ff")
set(RESOURCE_COMMIT_TAG_RTI_LIBS_X64LINUX4GCC730 "c512af4adb6668006f26242e796536ee144ba4bb")

# Includes res for all supported platforms
set(RESOURCE_COMMIT_TAG_DDS_INTERFACE_PRECOMPILED_LIBS_AND_HEADERS "c0d32b25425406829d75a2577155128641b69e50")

include(FetchContent)

# Specify location to download resources to
set(FETCHCONTENT_BASE_DIR ${CMAKE_BINARY_DIR}/external) 

# Declare resources that can be downloaded
FetchContent_Declare(
  rti_headers
  GIT_REPOSITORY ${GIT_REMOTE_WITH_RESOURCES}
  GIT_TAG        ${RESOURCE_COMMIT_TAG_RTI_HEADERS}
)

FetchContent_Declare(
  x64Win64VS2017
  GIT_REPOSITORY ${GIT_REMOTE_WITH_RESOURCES}
  GIT_TAG        ${RESOURCE_COMMIT_TAG_RTI_LIBS_X64WIN64VS2017}
)

FetchContent_Declare(
  x64Linux4gcc7.3.0
  GIT_REPOSITORY ${GIT_REMOTE_WITH_RESOURCES}
  GIT_TAG        ${RESOURCE_COMMIT_TAG_RTI_LIBS_X64LINUX4GCC730} 
)

FetchContent_Declare(
  dds_interface_precompiled_libs_and_headers
  GIT_REPOSITORY ${GIT_REMOTE_WITH_RESOURCES}
  GIT_TAG        ${RESOURCE_COMMIT_TAG_DDS_INTERFACE_PRECOMPILED_LIBS_AND_HEADERS}
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
        message("Downloading headers and rti core libs for ${RTI_PLATFORM}..")
        FetchContent_MakeAvailable(${RTI_PLATFORM} rti_headers) 

        # Set variables for external use
        set(RTI_CORE_LIBS_DIR "${FETCHCONTENT_BASE_DIR}/${RTI_PLATFORM}-src" PARENT_SCOPE)
        set(RTI_HEADERS_DIR "${FETCHCONTENT_BASE_DIR}/rti_headers-src" PARENT_SCOPE)

        message("Success! Downloaded resources can be found at: ${FETCHCONTENT_BASE_DIR}")
        message("Note that only minimal set of rti core libs are included. May need to link in more for advanced RTi Connext API usage")
    else()
        message(FATAL_ERROR "Unknown RTi platform: ${RTI_PLATFORM}\nUnable to download headers and core RTi libs")
    endif()
endfunction()

# Downloads headers and precompiled libs for DDS Interface
# for external use: DDS_INTERFACE_PRECOMPILED_LIBS_DIR DDS_INTERFACE_HEADERS_DIR
function(download_dds_interface_precompiled_libs_and_headers RTI_PLATFORM)
    # Check if platform is supported. AKA do we have the libs to build against for that platform
    set(PLATFORM_SUPPORTED FALSE)
    foreach(SUPPORTED_RTI_PLATFORM IN LISTS SUPPORTED_RTI_PLATFORMS)
        if(${RTI_PLATFORM} STREQUAL ${SUPPORTED_RTI_PLATFORM})
            set(PLATFORM_SUPPORTED TRUE)
        endif()
    endforeach()
    
    # FetchContent will download resources from git. It will check first to see if already downloaded. Very handy :)
    if(${PLATFORM_SUPPORTED})
        message("Downloading DDS Interface precompiled libs and headers for ${RTI_PLATFORM}..")
        FetchContent_MakeAvailable(dds_interface_precompiled_libs_and_headers)

        # Set variables for external use
        set(DDS_INTERFACE_PRECOMPILED_LIBS_DIR "${FETCHCONTENT_BASE_DIR}/dds_interface_precompiled_libs_and_headers-src/lib/${RTI_PLATFORM}" PARENT_SCOPE)
        set(DDS_INTERFACE_HEADERS_DIR "${FETCHCONTENT_BASE_DIR}/dds_interface_precompiled_libs_and_headers-src/include" PARENT_SCOPE)

        message("Success! Downloaded resources can be found at: ${FETCHCONTENT_BASE_DIR}")
    else()
        message(FATAL_ERROR "Unknown RTi platform: ${RTI_PLATFORM}\nUnable to download DDS Interface precompiled libs and headers")
    endif()
endfunction()