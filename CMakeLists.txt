cmake_minimum_required (VERSION 2.6.4)
project(quadrature-lib)
file(GLOB _files source/*cc)
include_directories(include)
add_library(quadrature-lib SHARED ${_files})

set(CMAKE_CXX_FLAGS_DEBUG:STRING=-g -DDEBUG)

