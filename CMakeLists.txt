cmake_minimum_required (VERSION 2.6.4)

# these would prevent the in-source build, but the
# error/warning message is not user-friendly
#set(CMAKE_DISABLE_SOURCE_CHANGES ON)
#set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(quadrature-lib)
file(GLOB _files source/*cc)
include_directories(include)
add_library(quadrature-lib SHARED ${_files})

set(CMAKE_CXX_FLAGS_DEBUG:STRING=-g -DDEBUG)
