cmake_minimum_required(VERSION 3.17)
project(test)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../cmake")  # Custom module dir
include(download_rti_deps)

download_resources_for_rti_platform("x64Win64VS2017")