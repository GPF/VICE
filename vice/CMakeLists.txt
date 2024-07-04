cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_CXX_SOURCE_FILE_EXTENSIONS cc;cpp)
set(CMAKE_CXX_STANDARD 11)

if(NOT FIRST_RUN_COMPLETE)
    set(FIRST_RUN true)
endif()

# Check if CMAKE_TOOLCHAIN_FILE is set, and if not, provide a default value
if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "./dreamcast-toolchain.cmake")
endif()

# Include the toolchain file
include(${CMAKE_TOOLCHAIN_FILE})

# Set common compiler and linker flags
add_compile_options(${KOS_CFLAGS} ${EXTRA_CFLAGS})
add_link_options(${KOS_LDFLAGS} ${EXTRA_LDFLAGS})

project(VICE C CXX)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(src)

set(FIRST_RUN_COMPLETE true CACHE INTERNAL "Used to detect first run")
