cmake_minimum_required(VERSION 3.12)
project(arev_base C)

set(
    SOURCE_FILES
    include/arev/arev.h
    include/arev/error.inc
    include/arev/error.h
    include/arev/math.h
    include/arev/mem/endianness.h
    include/arev/mem/reader.h
    include/arev/mem/writer.h
    include/arev/net/host.h
    include/arev/net/tcp.h
    src/arev.c
    src/error.c
    src/math.c
    src/mem/reader.c
    src/mem/writer.c
    src/net/host.c
)
add_library(arev_base STATIC ${SOURCE_FILES})
target_include_directories(
    arev_base
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
