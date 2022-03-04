#!/bin/bash
echo "This script will generate a new CMake project with RTi DDS core libs and precompiled DDS Interface linked in"

CURRENT_DIR=$(pwd)
SCRIPT_LOCATION=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
NEW_PROJECT_NAME=$1

CMAKE_DIR="$SCRIPT_LOCATION/../cmake"

if [ -z "$NEW_PROJECT_NAME" ]; then
    echo Error: Project name not specified
    echo "Usage: ./create_project_with_dds <project_name>"
    exit
fi

# Make sure project doesnt exist
if [[ -d "$NEW_PROJECT_NAME" ]]
then
    echo "Project with this name already exists"
fi

# Use cross platform CMake script for generating project 
cmake -DPROJECT_NAME="$NEW_PROJECT_NAME" -DPROJECT_PARENT_DIR="$CURRENT_DIR" -P "$CMAKE_DIR/create_dds_enabled_project.cmake"


