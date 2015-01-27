cmake_minimum_required (VERSION 2.6.4)

#-------------------------------------------------#
# prevent in-source build

# these flags would prevent the in-source build, but
# the error/warning message is not user-friendly
#set(CMAKE_DISABLE_SOURCE_CHANGES ON)
#set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# check for polluted source tree
if(EXISTS ${CMAKE_SOURCE_DIR}/CMakeCache.txt OR EXISTS ${CMAKE_SOURCE_DIR}/CMakeFiles)
#  file(REMOVE_RECURSE ${CMAKE_SOURCE_DIR}/CMakeFiles ${CMAKE_SOURCE_DIR}/CMakeCache.txt)
  message(FATAL_ERROR "CMakeCache.txt or CMakeFiles exists in source directory, please cleanup!")
endif()

# disallow in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are forbidden!")
endif()
#-------------------------------------------------#

project(quadrature-lib)

file(GLOB _files source/*cc)
include_directories(include)
add_library(quadrature-lib SHARED ${_files})

set(CMAKE_CXX_FLAGS_DEBUG:STRING=-g -DDEBUG)

include(cmake/documentation.cmake)
#include(cmake/install.cmake)

#EOF
