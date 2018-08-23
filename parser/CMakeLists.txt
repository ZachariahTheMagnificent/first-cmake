cmake_minimum_required(VERSION 3.11)
project(parser VERSION 1.0.0 DESCRIPTION "A simple parser library" LANGUAGES CXX)

# Declare the library.
add_library(parser)
# Declare that the library uses C++17
target_compile_features(parser PUBLIC cxx_std_17)
# Declare our includes.
target_include_directories(parser
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/internal")
# Declare the library's files.
target_sources(parser
	PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/parser/parser.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/parser.cpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/internal/internal/internal.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/internal.cpp")
