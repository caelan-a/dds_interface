cmake_minimum_required(VERSION 3.17)
project(test)

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}")
# include(TestModule)
message(${CMAKE_SOURCE_DIR})
file(DOWNLOAD
    https://insiteccomau.sharepoint.com/:w:/s/MISSystems-ProductDevelopment/EYd0CR6fk3BGrXcEYxZa2qwBjuxIpajGUplnT7PnDJ6VWQ?download=1
    ${CMAKE_SOURCE_DIR}/download/download.docx)

# include(FetchContent)

# set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)

# FetchContent_Declare(
#   headers
#   GIT_REPOSITORY https://github.com/caelan-a/dds_interface.git
#   GIT_TAG        f4a25b544a6c7f86d452d9da6e334736aa5ca765 # release-1.10.0
# )

# FetchContent_MakeAvailable(headers) 