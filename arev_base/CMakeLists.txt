cmake_minimum_required(VERSION 3.12)
project(arev_base C)

set(
    SOURCE_FILES
    include/arev/error.inc
    include/arev/error.h
    include/arev/loop.h
    include/arev/math.h
    src/error.c
    src/loop.c
    src/math.c
)
add_library(arev_base STATIC ${SOURCE_FILES})
target_include_directories(
    arev_base
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
