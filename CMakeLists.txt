cmake_minimum_required(VERSION 3.11)
project(first-cmake VERSION 1.0.0 DESCRIPTION "A test to see if I can make a CMake Project" LANGUAGES CXX)

# Build the math project.
add_subdirectory("${PROJECT_SOURCE_DIR}/math")
# Build the calculator project.
add_subdirectory("${PROJECT_SOURCE_DIR}/calculator")
# Build the parser project.
add_subdirectory("${PROJECT_SOURCE_DIR}/parser")
