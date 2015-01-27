# This is to see wether the library compiles correctly:
#try_compile(COMPILE_SUCCEEDED ${CMAKE_BINARY_DIR}/compile_tests my_test_src.cpp)

#if(COMPILE_SUCCEEDED)
#  message("Success!")
#endif()
cmake_minimum_required (VERSION 2.6)

project (Test)

enable_testing()

add_executable(test_test test_test.cpp)

add_test (test0 test_test)
