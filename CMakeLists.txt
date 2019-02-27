cmake_minimum_required(VERSION 2.8)
project(black_hole C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_C_FLAGS "-std=c89 -Os -mtune=native -Wall -Wextra -DNDEBUG")

add_executable(black_hole
        main.c
        ./algorithms/algorithm.c
        ./model/formula.c
        ./model/clause.c
        ./model/literal.c
        ./model/assigment.c)