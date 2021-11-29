cmake_minimum_required(VERSION 3.8)

project(data_structure)

SET(CMAKE_C_COMPILER   "/usr/local/bin/clang")
SET(CMAKE_CXX_COMPILER "/usr/local/bin/clang++")
SET(CMAKE_CXX_FLAGS    "-std=c++17")
SET(CMAKE_AR           "/usr/local/bin/llvm-ar")
SET(CMAKE_LINKER       "/usr/local/bin/llvm-ld")
SET(CMAKE_NM           "/usr/local/bin/llvm-nm")
SET(CMAKE_OBJDUMP      "/usr/local/bin/llvm-objdump")
SET(CMAKE_RANLIB       "/usr/local/bin/llvm-ranlib")

add_executable(ExceptionTests src/test/ExceptionTests.cpp)
target_link_libraries(ExceptionTests gtest gtest_main pthread)
