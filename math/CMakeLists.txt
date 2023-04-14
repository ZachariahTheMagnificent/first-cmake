cmake_minimum_required(VERSION 3.11)
project(math VERSION 1.0.0 DESCRIPTION "A basic header only math library" LANGUAGES CXX)

# The library is a header only library. It won't be compiled.
add_library(math INTERFACE)
# Declare that the library uses C++17.
target_compile_features(math INTERFACE cxx_std_17)
# Declare the library's includes.
target_include_directories(math INTERFACE "${PROJECT_SOURCE_DIR}/include")
# Declare the library's files.
target_sources(math INTERFACE "${PROJECT_SOURCE_DIR}/include/math/math.hpp")
