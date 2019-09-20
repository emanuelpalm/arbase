cmake_minimum_required(VERSION 3.2)
project(arev_http C)
set(CMAKE_C_STANDARD 11)

set(
    SOURCE_FILES
    include/arev/http.h
    src/http.c
)
add_library(arev_http STATIC ${SOURCE_FILES})
target_include_directories(
    arev_http
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
