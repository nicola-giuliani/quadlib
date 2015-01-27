# This is to see wether the library compiles correctly:
#try_compile(COMPILE_SUCCEEDED ${CMAKE_BINARY_DIR}/compile_tests my_test_src.cpp)

#if(COMPILE_SUCCEEDED)
#  message("Success!")
#endif()
cmake_minimum_required (VERSION 2.6)

project (Test)

enable_testing()

add_executable(test_test test_test.cpp)
add_executable(point_1 point_1.cc)
add_executable(quadrature_test quadrature_test.cc)

# test:

add_test (test0 test_test)

add_test (point0 point_1)
add_test (point1 ${CMAKE_COMMAND} -E compare_files point_1.ouput temp.output)

add_test (quadrature_test0 quadrature_test)
add_test (quadrature_test0 ${CMAKE_COMMAND} -E compare_files quadrature.ouput temp.output)
