# setup the project
cmake_minimum_required(VERSION 3.5)
project(square_interview)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)

# Builds the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
include_directories(src)
add_subdirectory(src)

# Builds the tests
enable_testing()
add_subdirectory(tests)
