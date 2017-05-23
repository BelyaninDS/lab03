cmake_minimum_required(VERSION 3.6)
project(Lab03)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp temp.cc)

set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(test_input input_test.cc temp.cc temp.h)

add_executable(Lab03 ${SOURCE_FILES})

enable_testing()
add_test(NAME test_input COMMAND test_input)