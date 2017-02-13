cmake_minimum_required(VERSION 3.6)
project(opencl)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES number_of_platforms.c)
add_executable(opencl ${SOURCE_FILES})
target_link_libraries(opencl OpenCL)