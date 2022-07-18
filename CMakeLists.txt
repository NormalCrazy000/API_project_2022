cmake_minimum_required(VERSION 3.22)
project(API_project_2022 C)

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -static-libasan")
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Werror -O2 -g3")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
add_executable(API_project_2022 main.c prova.cpp prova.h)
