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
include src/pet/CMakeFiles/libpetstubs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/pet/CMakeFiles/libpetstubs.dir/compiler_depend.make

# Include the progress variables for this target.
include src/pet/CMakeFiles/libpetstubs.dir/progress.make

# Include the compile flags for this target's objects.
include src/pet/CMakeFiles/libpetstubs.dir/flags.make

src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.o: src/pet/CMakeFiles/libpetstubs.dir/flags.make
src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.o: /home/gpf/code/dreamcast/VICE/vice/src/pet/pet-stubs.c
src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.o: src/pet/CMakeFiles/libpetstubs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/pet && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.o -MF CMakeFiles/libpetstubs.dir/pet-stubs.c.o.d -o CMakeFiles/libpetstubs.dir/pet-stubs.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/pet/pet-stubs.c

src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libpetstubs.dir/pet-stubs.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/pet && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/pet/pet-stubs.c > CMakeFiles/libpetstubs.dir/pet-stubs.c.i

src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libpetstubs.dir/pet-stubs.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/pet && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/pet/pet-stubs.c -o CMakeFiles/libpetstubs.dir/pet-stubs.c.s

# Object files for target libpetstubs
libpetstubs_OBJECTS = \
"CMakeFiles/libpetstubs.dir/pet-stubs.c.o"

# External object files for target libpetstubs
libpetstubs_EXTERNAL_OBJECTS =

src/pet/libpetstubs.a: src/pet/CMakeFiles/libpetstubs.dir/pet-stubs.c.o
src/pet/libpetstubs.a: src/pet/CMakeFiles/libpetstubs.dir/build.make
src/pet/libpetstubs.a: src/pet/CMakeFiles/libpetstubs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libpetstubs.a"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/pet && $(CMAKE_COMMAND) -P CMakeFiles/libpetstubs.dir/cmake_clean_target.cmake
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/pet && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libpetstubs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pet/CMakeFiles/libpetstubs.dir/build: src/pet/libpetstubs.a
.PHONY : src/pet/CMakeFiles/libpetstubs.dir/build

src/pet/CMakeFiles/libpetstubs.dir/clean:
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/pet && $(CMAKE_COMMAND) -P CMakeFiles/libpetstubs.dir/cmake_clean.cmake
.PHONY : src/pet/CMakeFiles/libpetstubs.dir/clean

src/pet/CMakeFiles/libpetstubs.dir/depend:
	cd /home/gpf/code/dreamcast/VICE/vice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gpf/code/dreamcast/VICE/vice /home/gpf/code/dreamcast/VICE/vice/src/pet /home/gpf/code/dreamcast/VICE/vice/build /home/gpf/code/dreamcast/VICE/vice/build/src/pet /home/gpf/code/dreamcast/VICE/vice/build/src/pet/CMakeFiles/libpetstubs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pet/CMakeFiles/libpetstubs.dir/depend

