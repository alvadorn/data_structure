project(DataStructures C)

cmake_minimum_required(VERSION 2.6.0)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -std=c11")

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
