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

include_directories(./)
add_library(quadrature-lib SHARED ${_files})

set(CMAKE_CXX_FLAGS_DEBUG:STRING=-g -DDEBUG)
set(CMAKE_CXX_FLAGS_RELEASE:STRING=-O3)


add_library(quadrature.debug SHARED ${_files} )
SET_TARGET_PROPERTIES(quadrature.debug PROPERTIES
COMPILE_FLAGS "${CMAKE_CXX_FLAGS_DEBUG}")

add_library(quadrature.release SHARED ${_files})
SET_TARGET_PROPERTIES(quadrature.release PROPERTIES
COMPILE_FLAGS "${CMAKE_CXX_FLAGS_RELEASE}")

include(cmake/documentation.cmake)
include(cmake/install.cmake)


#EOF
