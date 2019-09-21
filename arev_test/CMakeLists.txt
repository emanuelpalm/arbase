cmake_minimum_required(VERSION 3.12)
project(arev_test C)

set(
    SOURCE_FILES
    src/main.c
)
add_executable(arev_test ${SOURCE_FILES})
target_link_libraries(arev_test PRIVATE arev_base arev_http)
