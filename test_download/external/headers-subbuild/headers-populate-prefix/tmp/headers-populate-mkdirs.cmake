# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-src"
  "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-build"
  "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-subbuild/headers-populate-prefix"
  "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-subbuild/headers-populate-prefix/tmp"
  "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-subbuild/headers-populate-prefix/src/headers-populate-stamp"
  "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-subbuild/headers-populate-prefix/src"
  "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-subbuild/headers-populate-prefix/src/headers-populate-stamp"
)

set(configSubDirs Debug;Release;MinSizeRel;RelWithDebInfo)
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/cande/Desktop/AMMO/tmp/dds_interface/test_download/external/headers-subbuild/headers-populate-prefix/src/headers-populate-stamp/${subDir}")
endforeach()
