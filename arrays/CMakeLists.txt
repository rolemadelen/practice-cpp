# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(arrays_proj)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(main.out main.cc ivector.cc ivector_test.cc)

