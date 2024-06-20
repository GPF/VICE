# dreamcast-toolchain.cmake

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR sh4)

# Specify the cross compiler paths
set(CMAKE_C_COMPILER /path/to/sh-elf-gcc)
set(CMAKE_CXX_COMPILER /path/to/sh-elf-g++)

# Specify the target sysroot
set(CMAKE_SYSROOT /opt/toolchains/dc/sh-elf)

# Specify the paths to search for libraries and headers
set(CMAKE_FIND_ROOT_PATH /opt/toolchains/dc/sh-elf)

# Adjust the default behavior of FIND_XXX() commands to search for the target programs and libraries
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Set additional flags
set(CMAKE_C_FLAGS "${KOS_CFLAGS}")
set(CMAKE_CXX_FLAGS "${KOS_CFLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${KOS_LDFLAGS}")
