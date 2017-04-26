# setup the project
cmake_minimum_required(VERSION 3.5)
project(tests)

set(CMAKE_VERBOSE_MAKEFILE OFF)


# Build the googletest archives
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/gtest)
add_subdirectory(googletest)

# Add the gtest headers and compiled archives to the search path
include_directories(googletest/googletest/include/gtest)
include_directories(googletest/googlemock/include/gmock)
include_directories(${CMAKE_BINARY_DIR}/bin/gtest)

# Add source files to the search path
set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/../src)
include_directories(${PROJECT_SOURCE_DIR})

# Build the tests
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests)
set(GTEST_LIBRARIES gmock gtest gmock_main)

enable_testing()
include(${PROJECT_SOURCE_DIR}/tests/blink_test.cmake)
