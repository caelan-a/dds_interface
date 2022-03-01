cmake_minimum_required(VERSION 3.17)

### CMAKE BEGIN ###
project(dds_interface VERSION 0.2)

set(CMAKE_DEBUG_POSTFIX _debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)

### Functions ###
# Generate filename for static library on current platform
function(getPlatformLibWithExtension text OUTPUT_VAR)
if(WIN32)
    set(${OUTPUT_VAR} "${text}.lib" PARENT_SCOPE)
elseif(UNIX)
    set(${OUTPUT_VAR} "lib${text}.a" PARENT_SCOPE)
else()
    message(FATAL_ERROR "Failed to getPlatformLibWithExtension: Unknown platform")
endif()
endfunction()

### Load in DDS Platform ###
if(NOT ${PLATFORM} STREQUAL "")
message("PLATFORM: ${PLATFORM}")
else()
message( FATAL_ERROR "Platform argument is missing, please specify. \nEg. `cmake -DPLATFORM=x64Win64VS2017 ../` or `cmake -DPLATFORM=x64Linux4gcc7.3.0 ../`")
endif()

### Load in NDDSHOME from system environment ###
set(NDDS_HOME $ENV{NDDSHOME})
  STRING(REGEX REPLACE "\\\\" "/" NDDS_HOME ${NDDS_HOME}) 
if(NDDS_HOME)
  message("NDDSHOME: ${NDDS_HOME}")
else()
  message( FATAL_ERROR "Missing NDDSHOME in environment variables, please set.\nThis is needed to find RTi headers and libs" )
endif()

if(WIN32)
  message("Building for Windows")
elseif(UNIX)
  message("Building for UNIX")
else()
  message( FATAL_ERROR "Unsupported platform. Please extend")
endif()

### Create targets ###
set(TARGET_DDS_INTERFACE_LIB_STANDALONE "${PROJECT_NAME}_standalone")
add_library(${TARGET_DDS_INTERFACE_LIB_STANDALONE} DDSInterface.cpp DDSInterface.h DDSPublisher.cpp DDSPublisher.h)

# Set Visual Studio specific properties
if ( MSVC )
    set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
    set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
    set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} )
    set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY} )
endif ( MSVC )

set_target_properties(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

### Specify include directories ###
set(INCLUDES
  "${NDDS_HOME}/include;"
  "${NDDS_HOME}/include/ndds;"
  "${NDDS_HOME}/include/ndds/hpp;"
)

# Set include directories
target_include_directories(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC ${INCLUDES})

set(NATIVE_WIN_LIBS
  "netapi32"
  "advapi32"
  "user32"
  "WS2_32"
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

# Add platform specific libs for linking
if(WIN32)
  list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG ${NATIVE_WIN_LIBS})
  list(APPEND ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE ${NATIVE_WIN_LIBS})
elseif(UNIX)
  # Include pthreads and libdl
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)
  target_link_libraries(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PRIVATE Threads::Threads ${CMAKE_DL_LIBS})
endif()

target_link_libraries(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC debug "${ADDITIONAL_LIBRARY_DEPENDENCIES_DEBUG}" optimized "${ADDITIONAL_LIBRARY_DEPENDENCIES_RELEASE}" )

# Set link library directories
set(LINK_LIBRARY_DIRS
  "${NDDS_HOME}/lib/${PLATFORM};"
)
target_link_directories(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC "${LINK_LIBRARY_DIRS}")

### Add preprocessor definitions ###

if(WIN32)
target_compile_definitions(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PRIVATE
  $<$<CONFIG:Debug>:NDDS_DLL_VARIABLE WIN32_LEAN_AND_MEAN _DEBUG _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS>
  $<$<CONFIG:Release>:NDDS_DLL_VARIABLE WIN32_LEAN_AND_MEAN _CONSOLE WIN32 RTI_WIN32 _SCL_SECURE_NO_WARNINGS>
)
elseif(UNIX)
target_compile_definitions(${TARGET_DDS_INTERFACE_LIB_STANDALONE} PUBLIC UNIX; RTI_UNIX; NDDS_DLL_VARIABLE; _CONSOLE; _SCL_SECURE_NO_WARNINGS;)
endif()

### Merge lib target and rti dependencies into single static lib ###

# CMAKE_AR evaluates to path of lib.exe on windows for linking static libraries
if(CMAKE_AR)
    message("Found binary for CMAKE_AR.")

    if(WIN32) 
      ### Create bundled library by combining dds_interface_standalone and core rti libs 
      message("Creating target to automatically bundle RTi libs and some system deps into dds_interface.lib and dds_interface_debug.lib")

      # Create library targets for RTi debug and release libs
      foreach(CORE_RTI_LIB IN LISTS CORE_RTI_LIBS CORE_RTI_LIBS_DEBUG)
        getPlatformLibWithExtension("${CORE_RTI_LIB}" LIB_WITH_EXTENSION)
        add_library(${CORE_RTI_LIB} SHARED IMPORTED )
        set_target_properties( ${CORE_RTI_LIB} PROPERTIES IMPORTED_LOCATION ${NDDS_HOME}/lib/${PLATFORM}/${LIB_WITH_EXTENSION} IMPORTED_IMPLIB ${NDDS_HOME}/lib/${PLATFORM}/${LIB_WITH_EXTENSION} )
      endforeach()
    
      # Create custom target for static library combination 
      getPlatformLibWithExtension("${PROJECT_NAME}$<$<CONFIG:Debug>:${CMAKE_DEBUG_POSTFIX}>" LIB_WITH_EXTENSION)
      
      add_custom_target(BundleStaticLibs ALL
          COMMAND ${CMAKE_AR} /OUT:$<TARGET_FILE_DIR:${TARGET_DDS_INTERFACE_LIB_STANDALONE}>/"${LIB_WITH_EXTENSION}"
              "$<TARGET_FILE:${TARGET_DDS_INTERFACE_LIB_STANDALONE}>"
              "$<TARGET_FILE:nddscpp2z$<$<CONFIG:Debug>:d>>"
              "$<TARGET_FILE:nddscz$<$<CONFIG:Debug>:d>>" 
              "$<TARGET_FILE:nddscorez$<$<CONFIG:Debug>:d>>"
          WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      )
    elseif(UNIX)
      # Linux ar binary doesnt automatically add index which inhibits making a combined static lib
      # Can overcome this by following: https://stackoverflow.com/questions/54249128/ar-command-does-not-produce-index-when-combining-static-libraries 
      # For now just output libs
      message("Combining static libs on unix has not been implemented yet. See CMakeLists.txt:154.")
    endif()
else()
  message("Failed to find binary for CMAKE_AR. You will have to manually bundle RTi libraries with interface..")
endif()

### Export Core RTi resources ###
set(HEADER_EXPORT_DIR "${CMAKE_CURRENT_BINARY_DIR}/out/include")

## Extract core headers
if(NOT IS_DIRECTORY "${HEADER_EXPORT_DIR}")
  message("Copying headers from DDSHOME and root for easy export..")
  message(STATUS "Copying from ${NDDS_HOME}/include to ${HEADER_EXPORT_DIR}")
  file(COPY "${NDDS_HOME}/include" DESTINATION "${HEADER_EXPORT_DIR}") 
  file(RENAME "${HEADER_EXPORT_DIR}/include" "${HEADER_EXPORT_DIR}/rti_headers") 
  file(COPY "DDSInterface.h" DESTINATION "${HEADER_EXPORT_DIR}/") 
  file(COPY "DDSPublisher.h" DESTINATION "${HEADER_EXPORT_DIR}/") 
else()
  message("Export headers already copied")
endif()


## Gather and export core RTi libs for when using standalone dds_interface lib
message("Gathering required rti libs for convenience in /build/out/lib")

foreach(CORE_LIB_TARGET ${CORE_RTI_LIBS} ${CORE_RTI_LIBS_DEBUG})
  getPlatformLibWithExtension("${CORE_LIB_TARGET}" LIB_WITH_EXTENSION)
  message(STATUS "Copying: ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/${LIB_WITH_EXTENSION}")
  file(COPY "${NDDS_HOME}/lib/${PLATFORM}/${LIB_WITH_EXTENSION}" DESTINATION "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}") 
endforeach()

message("Build using: cmake --build . --config=<Debug|Release>")