# Install script for directory: /home/gpf/code/dreamcast/VICE/vice/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/opt/toolchains/dc/sh-elf/bin/sh-elf-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/joyport/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/drive/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/vdrive/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/fsdevice/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/diskimage/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/iecbus/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/serial/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/parallel/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/tape/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/imagecontents/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/fileio/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/video/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/raster/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/vicii/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/viciisc/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/vdc/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/crtc/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/printerdrv/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/rs232drv/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/samplerdrv/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/sid/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/monitor/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/core/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/userport/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/tapeport/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/diag/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/c64/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/scpu64/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/c64dtv/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/c128/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/vic20/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/pet/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/plus4/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/cbm2/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/arch/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/lib/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/hvsc/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/datasette/cmake_install.cmake")
  include("/home/gpf/code/dreamcast/VICE/vice/build/src/tools/cmake_install.cmake")

endif()

