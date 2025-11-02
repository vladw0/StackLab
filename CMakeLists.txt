
cmake_minimum_required(VERSION 3.14)
project(StackLab LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_library(stacklib INTERFACE)
target_include_directories(stacklib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(stack src/main.cpp)
target_link_libraries(stack PRIVATE stacklib)

add_subdirectory(gtest)

add_executable(stack_test test/test_stack.cpp)
target_link_libraries(stack_test PRIVATE stacklib gtest_main)
include(GoogleTest)
gtest_discover_tests(stack_test)
