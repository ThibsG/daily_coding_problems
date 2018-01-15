project(DailyCodingProblems)

cmake_minimum_required(VERSION 2.6)

include(CTest)
enable_testing()

# Flags
set(CMAKE_BUILD_TYPE "RELEASE")

## C++17 flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
## Optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")

# Executable
add_executable(dcp10 10.cpp)

# Tests
add_test(NAME test_dcp10 COMMAND ./dcp10 800)
