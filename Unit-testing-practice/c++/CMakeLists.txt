cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Add gtest source directory variable
set(gtest_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/third_party/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_subdirectory(${gtest_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/googletest)
enable_testing()

add_library(demo demo.cpp)
target_include_directories(demo PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
# Add source files here
add_executable(MyProject main.cpp)
target_include_directories(MyProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(MyProject PRIVATE demo)
# Build: cmake --build . --target MyProject
# or: make MyProject


add_executable(test_demo test_demo.cpp)
target_link_libraries(test_demo gtest gtest_main demo)
add_test(NAME test_demo COMMAND test_demo)
# Build: cmake --build . --target test_demo
# or: make test_demo
