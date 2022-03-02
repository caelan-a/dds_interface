@ECHO OFF
:: This script will generate a new CMake project with RTi DDS core libs and precompiled DDS Interface linked in  
:: Usage: ./create_project_with_dds <project_name>

set CURRENT_DIR="%CD%"
set SCRIPT_LOCATION=%~dp0
set NEW_PROJECT_NAME=%1

set CMAKE_DIR="%SCRIPT_LOCATION%../cmake"

IF "%NEW_PROJECT_NAME%" == "" (
    ECHO Error: Project name not specified
    ECHO "Usage: ./create_project_with_dds <project_name>"
    exit
)

:: Make sure project doesnt exist
if exist "%NEW_PROJECT_NAME%" (
    ECHO ERROR: Project with this name already exists
    exit
)

:: Use cross platform CMake script for generating project 
cmake -DPROJECT_NAME="%NEW_PROJECT_NAME%" -DPROJECT_PARENT_DIR="%CURRENT_DIR%" -P %CMAKE_DIR%/create_dds_enabled_project.cmake


