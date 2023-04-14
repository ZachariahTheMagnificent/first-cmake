cmake_minimum_required(VERSION 3.11)
project(parser VERSION 1.0.0 DESCRIPTION "A simple parser library" LANGUAGES CXX)

# Declare the library.
add_library(parser)

# Declare that the library uses C++17
target_compile_features(parser PUBLIC cxx_std_17)

# Declare our includes.
target_include_directories(parser
	PUBLIC
		"${PROJECT_SOURCE_DIR}/include"

	PRIVATE
		"${PROJECT_SOURCE_DIR}/internal"
)

# Declare the library's files.
target_sources(parser
	PUBLIC
		"${PROJECT_SOURCE_DIR}/include/parser/parser.hpp"

	PRIVATE
		"${PROJECT_SOURCE_DIR}/source/parser.cpp"
		"${PROJECT_SOURCE_DIR}/internal/internal/internal.hpp"
		"${PROJECT_SOURCE_DIR}/source/internal.cpp"
)
