project(DataStructures C)

cmake_minimum_required(VERSION 2.8.7)
set(CMAKE_C_FLAGS "-Wall -Werror -Wpedantic -std=c11")

option(TRAVIS "Build tests." OFF)

if(TRAVIS)
  message(STATUS "Buiding on travis")
  include_directories ("${PROJECT_SOURCE_DIR}/cmocka/include")
  link_directories("${PROJECT_SOURCE_DIR}/cmocka/lib")
endif()

# enable test helpers
enable_testing()

add_subdirectory(src)
add_subdirectory(test)
