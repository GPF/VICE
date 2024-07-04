# dreamcast-toolchain.cmake

# Specify the cross compiler paths
set(CMAKE_C_COMPILER /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc)
set(CMAKE_CXX_COMPILER /opt/toolchains/dc/sh-elf/bin/sh-elf-g++)
set(CMAKE_SYSROOT /opt/toolchains/dc/sh-elf)

# Set additional flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_arch_dreamcast -D__DREAMCAST__")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_arch_dreamcast -D__DREAMCAST__")


set(CMAKE_EXE_LINKER_FLAGS "${KOS_LDFLAGS} ${KOS_LIB_PATHS} -L/opt/toolchains/dc/sh-elf/sh-elf/lib/ -L/opt/toolchains/dc/kos/addons/lib/dreamcast/ -L/opt/toolchains/dc/kos/lib/dreamcast/ ${KOS_LIBS} -lSDL_1213DH -lstdc++ -lc -lgcc")



# Set the path to the KallistiOS include directories
include_directories(
    "/opt/toolchains/dc/kos/include"
    "/opt/toolchains/dc/kos/kernel/arch/dreamcast/include"
    "/opt/toolchains/dc/kos/addons/include"
    "/opt/toolchains/dc/kos/../kos-ports/include"
    "/opt/toolchains/dc/kos/addons/include/SDL"
)

# Set the path to the SDL library compiled for KallistiOS
#set(LIB_SDL_GL_1213DH "/opt/toolchains/dc/kos/addons/lib/dreamcast/libSDL_1213DH.a  /opt/toolchains/dc/sh-elf/sh-elf/lib/libm.a")

# Set the path to the KallistiOS library
set(LIB_KALLISTI "${KOS_LDFLAGS};${KOS_LIB_PATHS};kallisti;c;gcc;SDL_1213DH;stdc++")

# Optionally, set any other specific configuration needed for your project
