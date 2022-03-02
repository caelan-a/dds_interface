set(PROJECT_NAME $ENV{PROJECT_NAME})
set(PROJECT_PARENT_DIR $ENV{PROJECT_PARENT_DIR})
set(PROJECT_DIR "${PROJECT_PARENT_DIR}\\${PROJECT_NAME}")
set(SCRIPT_DIR ${CMAKE_CURRENT_LIST_DIR})

message("Generating DDS Enabled CMake project with name ${PROJECT_NAME}..")
message("Location: ${PROJECT_DIR}")

# FILE(MAKE_DIRECTORY ${PROJECT_DIR})
FILE(COPY ${SCRIPT_DIR} DESTINATION ${PROJECT_DIR}) # Copy in cmake deps

# Fill template variables
set(NEW_PROJECT_VERSION "0.1")
set(NEW_PROJECT_NAME ${PROJECT_NAME})
set(NEW_PROJECT_NAME_CMAKE_VERSION "3.17")

# Generate new project files
configure_file("${SCRIPT_DIR}/templates/new_project_CMakeList.txt.in" ${PROJECT_DIR}/CMakeLists.txt @ONLY)
configure_file("${SCRIPT_DIR}/templates/new_project.cpp.in" ${PROJECT_DIR}/${NEW_PROJECT_NAME}.cpp @ONLY)
configure_file("${SCRIPT_DIR}/templates/new_project.hpp.in" ${PROJECT_DIR}/${NEW_PROJECT_NAME}.hpp @ONLY)
configure_file("${SCRIPT_DIR}/templates/new_project_build.bat.in" ${PROJECT_DIR}/build.bat @ONLY)
# Add in linux build script               

# Delete template folder as its unused
FILE(REMOVE_RECURSE ${PROJECT_DIR}/cmake/templates)

message("\nSuccess! Check out your new project and see the repo for examples")