cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(CMAKE_CXX_SOURCE_FILE_EXTENSIONS cc;cpp)
set(CMAKE_CXX_STANDARD 11)

if(NOT FIRST_RUN_COMPLETE)
    set(FIRST_RUN true)
endif()

project(VICE C CXX)
set(CMAKE_STATIC_LIBRARY_PREFIX "")

add_subdirectory(src)

set(FIRST_RUN_COMPLETE true CACHE INTERNAL "Used to detect first run")
