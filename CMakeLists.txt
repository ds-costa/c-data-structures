cmake_minimum_required(VERSION 3.10)

project(main C CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(array src/array.c)
add_library(recursives src/recursives.c)
add_library(sort src/sort.c)
add_library(strings src/strings.c)
add_library(linkedList src/linkedList.c)

add_executable(main main.c)
target_link_libraries(main array recursives sort strings linkedList -lm)
