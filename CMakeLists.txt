cmake_minimum_required(VERSION 3.11)

project(first-cmake VERSION 1.0.0 DESCRIPTION "A test to see if I can make a CMake Project" LANGUAGES CXX)

add_executable(first-cmake source/first-cmake.cpp)
target_include_directories(first-cmake PUBLIC include)
target_compile_features(first-cmake PUBLIC cxx_std_17)