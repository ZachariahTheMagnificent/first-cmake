cmake_minimum_required(VERSION 3.11)
project(calculator VERSION 1.0.0 DESCRIPTION "A very calculator application" LANGUAGES CXX)

# Declare the executable.
add_executable(calculator)
# This executable is compiled with C++17.
target_compile_features(calculator PRIVATE cxx_std_17)
# Declare the libraries this executable uses.
target_link_libraries(calculator PRIVATE math PRIVATE parser)
# Declare the executable's includes.
target_include_directories(calculator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
# Declare the executable's files.
target_sources(calculator
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include/command-line-calculator.hpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/command-line-calculator.cpp"
	PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp")
