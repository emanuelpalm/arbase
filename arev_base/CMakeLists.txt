cmake_minimum_required(VERSION 3.2)
project(arev_base C)
set(CMAKE_C_STANDARD 11)

set(
    SOURCE_FILES
    include/arev/base.h
    include/arev/error.inc
    src/base.c
    src/err.c
    src/err.h
    src/int.c
    src/int.h
)
add_library(arev_base STATIC ${SOURCE_FILES})
target_include_directories(
    arev_base
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
