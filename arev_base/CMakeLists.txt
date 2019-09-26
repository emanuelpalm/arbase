cmake_minimum_required(VERSION 3.12)
project(arev_base C)

set(
    SOURCE_FILES
    include/arev/arev.h
    include/arev/error.inc
    include/arev/error.h
    include/arev/math.h
    src/arev.c
    src/error.c
    src/math.c
    include/arev/net/host.h src/net/host.c include/arev/mem/reader.h src/mem/reader.c include/arev/net/tcp.h include/arev/mem/endianness.h include/arev/mem/writer.h src/mem/writer.c)
add_library(arev_base STATIC ${SOURCE_FILES})
target_include_directories(
    arev_base
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
