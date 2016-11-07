project(DataStructures C)

cmake_minimum_required(VERSION 2.6.0)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(LinkedList STATIC src/linked_list.c)
add_library(Queue STATIC src/queue.c)
