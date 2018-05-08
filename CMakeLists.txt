project(DailyCodingProblems)

cmake_minimum_required(VERSION 2.6)

include(CTest)
enable_testing()

# Flags
set(CMAKE_BUILD_TYPE "RELEASE")

## C++14 flag
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
## Optimizations
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s")

# Executables
add_executable(dcp1 1.cpp)
add_executable(dcp2 2.cpp)
add_executable(dcp3 3.cpp)
add_executable(dcp10 10.cpp)

# Tests
add_test(NAME test_dcp1  COMMAND ./dcp1)
add_test(NAME test_dcp2  COMMAND ./dcp2)
add_test(NAME test_dcp3  COMMAND ./dcp3)
add_test(NAME test_dcp10 COMMAND ./dcp10 800)
