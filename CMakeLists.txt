project(DataStructures C)

cmake_minimum_required(VERSION 3.0)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -std=c11")

# download and build cmocka
include(cmocka.cmake)

# enable test helpers
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
