cmake_minimum_required (VERSION 2.8.11)
project(quadrature-lib)
file(GLOB _files source/*cc)
include_directories(include)
add_library(quadrature-lib SHARED ${_files})

