cmake_minimum_required(VERSION 3.17)

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
