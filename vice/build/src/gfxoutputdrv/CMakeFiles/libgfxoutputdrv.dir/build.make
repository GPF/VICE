# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gpf/code/dreamcast/VICE/vice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gpf/code/dreamcast/VICE/vice/build

# Include any dependencies generated for this target.
include src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.make

# Include the progress variables for this target.
include src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/progress.make

# Include the compile flags for this target's objects.
include src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/bmpdrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/bmpdrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/bmpdrv.c > CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/bmpdrv.c -o CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/artstudiodrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/artstudiodrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/artstudiodrv.c > CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/artstudiodrv.c -o CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ffmpegexedrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ffmpegexedrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ffmpegexedrv.c > CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ffmpegexedrv.c -o CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/gfxoutput.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o -MF CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/gfxoutput.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/gfxoutput.c > CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/gfxoutput.c -o CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/godotdrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/godotdrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/godotdrv.c > CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/godotdrv.c -o CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/iffdrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/iffdrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/iffdrv.c > CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/iffdrv.c -o CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/koaladrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/koaladrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/koaladrv.c > CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/koaladrv.c -o CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/minipaintdrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/minipaintdrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/minipaintdrv.c > CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/minipaintdrv.c -o CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/nativedrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/nativedrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/nativedrv.c > CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/nativedrv.c -o CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/pcxdrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/pcxdrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/pcxdrv.c > CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/pcxdrv.c -o CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ppmdrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ppmdrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ppmdrv.c > CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/ppmdrv.c -o CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.s

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/flags.make
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o: /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/zmbvdrv.c
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o -MF CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o.d -o CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/zmbvdrv.c

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/zmbvdrv.c > CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.i

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv/zmbvdrv.c -o CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.s

# Object files for target libgfxoutputdrv
libgfxoutputdrv_OBJECTS = \
"CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o" \
"CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o"

# External object files for target libgfxoutputdrv
libgfxoutputdrv_EXTERNAL_OBJECTS =

src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/bmpdrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/artstudiodrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ffmpegexedrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/gfxoutput.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/godotdrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/iffdrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/koaladrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/minipaintdrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/nativedrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/pcxdrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/ppmdrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/zmbvdrv.c.o
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/build.make
src/gfxoutputdrv/libgfxoutputdrv.a: src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking C static library libgfxoutputdrv.a"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && $(CMAKE_COMMAND) -P CMakeFiles/libgfxoutputdrv.dir/cmake_clean_target.cmake
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libgfxoutputdrv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/build: src/gfxoutputdrv/libgfxoutputdrv.a
.PHONY : src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/build

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/clean:
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv && $(CMAKE_COMMAND) -P CMakeFiles/libgfxoutputdrv.dir/cmake_clean.cmake
.PHONY : src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/clean

src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/depend:
	cd /home/gpf/code/dreamcast/VICE/vice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gpf/code/dreamcast/VICE/vice /home/gpf/code/dreamcast/VICE/vice/src/gfxoutputdrv /home/gpf/code/dreamcast/VICE/vice/build /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv /home/gpf/code/dreamcast/VICE/vice/build/src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/gfxoutputdrv/CMakeFiles/libgfxoutputdrv.dir/depend

