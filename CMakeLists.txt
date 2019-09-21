cmake_minimum_required(VERSION 3.12)
project(arev)
set(CMAKE_C_STANDARD 11)

# Enable LTO for release builds.
if (CMAKE_BUILD_TYPE MATCHES "Release")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
endif ()

# Set global compiler definitions and options.
if (CMAKE_C_COMPILER_ID MATCHES "GNU")
    add_compile_definitions(AREV_GCC)
    add_compile_options(-Wall -Wextra -Werror)
elseif (CMAKE_C_COMPILER_ID MATCHES "Clang")
    add_compile_definitions(AREV_CLANG AREV_GCC)
    add_compile_options(-Wall -Wextra -Werror)
endif ()
add_compile_definitions(
    AREV_COMPILER_ID="${CMAKE_C_COMPILER_ID}"
)

# Set global system definitions.
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    add_compile_definitions(AREV_LINUX)
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    add_compile_definitions(AREV_DARWIN)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    add_compile_definitions(AREV_WIN32)
endif ()
add_compile_definitions(
    AREV_SYSTEM_NAME="${CMAKE_SYSTEM_NAME}"
    AREV_SYSTEM_VERSION="${CMAKE_SYSTEM_VERSION}"
)

add_subdirectory(arev_base)
add_subdirectory(arev_http)
add_subdirectory(arev_test)
