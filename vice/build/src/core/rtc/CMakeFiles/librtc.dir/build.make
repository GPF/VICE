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
include src/core/rtc/CMakeFiles/librtc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.make

# Include the progress variables for this target.
include src/core/rtc/CMakeFiles/librtc.dir/progress.make

# Include the compile flags for this target's objects.
include src/core/rtc/CMakeFiles/librtc.dir/flags.make

src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/bq4830y.c
src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.o -MF CMakeFiles/librtc.dir/bq4830y.c.o.d -o CMakeFiles/librtc.dir/bq4830y.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/bq4830y.c

src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/bq4830y.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/bq4830y.c > CMakeFiles/librtc.dir/bq4830y.c.i

src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/bq4830y.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/bq4830y.c -o CMakeFiles/librtc.dir/bq4830y.c.s

src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds12c887.c
src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.o -MF CMakeFiles/librtc.dir/ds12c887.c.o.d -o CMakeFiles/librtc.dir/ds12c887.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds12c887.c

src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/ds12c887.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds12c887.c > CMakeFiles/librtc.dir/ds12c887.c.i

src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/ds12c887.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds12c887.c -o CMakeFiles/librtc.dir/ds12c887.c.s

src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1202_1302.c
src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.o -MF CMakeFiles/librtc.dir/ds1202_1302.c.o.d -o CMakeFiles/librtc.dir/ds1202_1302.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1202_1302.c

src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/ds1202_1302.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1202_1302.c > CMakeFiles/librtc.dir/ds1202_1302.c.i

src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/ds1202_1302.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1202_1302.c -o CMakeFiles/librtc.dir/ds1202_1302.c.s

src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1216e.c
src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.o -MF CMakeFiles/librtc.dir/ds1216e.c.o.d -o CMakeFiles/librtc.dir/ds1216e.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1216e.c

src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/ds1216e.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1216e.c > CMakeFiles/librtc.dir/ds1216e.c.i

src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/ds1216e.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1216e.c -o CMakeFiles/librtc.dir/ds1216e.c.s

src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1307.c
src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.o -MF CMakeFiles/librtc.dir/ds1307.c.o.d -o CMakeFiles/librtc.dir/ds1307.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1307.c

src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/ds1307.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1307.c > CMakeFiles/librtc.dir/ds1307.c.i

src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/ds1307.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1307.c -o CMakeFiles/librtc.dir/ds1307.c.s

src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1602.c
src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.o -MF CMakeFiles/librtc.dir/ds1602.c.o.d -o CMakeFiles/librtc.dir/ds1602.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1602.c

src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/ds1602.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1602.c > CMakeFiles/librtc.dir/ds1602.c.i

src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/ds1602.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/ds1602.c -o CMakeFiles/librtc.dir/ds1602.c.s

src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/pcf8583.c
src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.o -MF CMakeFiles/librtc.dir/pcf8583.c.o.d -o CMakeFiles/librtc.dir/pcf8583.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/pcf8583.c

src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/pcf8583.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/pcf8583.c > CMakeFiles/librtc.dir/pcf8583.c.i

src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/pcf8583.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/pcf8583.c -o CMakeFiles/librtc.dir/pcf8583.c.s

src/core/rtc/CMakeFiles/librtc.dir/rtc.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/rtc.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc.c
src/core/rtc/CMakeFiles/librtc.dir/rtc.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object src/core/rtc/CMakeFiles/librtc.dir/rtc.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/rtc.c.o -MF CMakeFiles/librtc.dir/rtc.c.o.d -o CMakeFiles/librtc.dir/rtc.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc.c

src/core/rtc/CMakeFiles/librtc.dir/rtc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/rtc.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc.c > CMakeFiles/librtc.dir/rtc.c.i

src/core/rtc/CMakeFiles/librtc.dir/rtc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/rtc.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc.c -o CMakeFiles/librtc.dir/rtc.c.s

src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-58321a.c
src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.o -MF CMakeFiles/librtc.dir/rtc-58321a.c.o.d -o CMakeFiles/librtc.dir/rtc-58321a.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-58321a.c

src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/rtc-58321a.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-58321a.c > CMakeFiles/librtc.dir/rtc-58321a.c.i

src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/rtc-58321a.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-58321a.c -o CMakeFiles/librtc.dir/rtc-58321a.c.s

src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.o: src/core/rtc/CMakeFiles/librtc.dir/flags.make
src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.o: /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-72421.c
src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.o: src/core/rtc/CMakeFiles/librtc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.o"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.o -MF CMakeFiles/librtc.dir/rtc-72421.c.o.d -o CMakeFiles/librtc.dir/rtc-72421.c.o -c /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-72421.c

src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/librtc.dir/rtc-72421.c.i"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-72421.c > CMakeFiles/librtc.dir/rtc-72421.c.i

src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/librtc.dir/rtc-72421.c.s"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && /opt/toolchains/dc/sh-elf/bin/sh-elf-gcc --sysroot=/opt/toolchains/dc/sh-elf $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gpf/code/dreamcast/VICE/vice/src/core/rtc/rtc-72421.c -o CMakeFiles/librtc.dir/rtc-72421.c.s

# Object files for target librtc
librtc_OBJECTS = \
"CMakeFiles/librtc.dir/bq4830y.c.o" \
"CMakeFiles/librtc.dir/ds12c887.c.o" \
"CMakeFiles/librtc.dir/ds1202_1302.c.o" \
"CMakeFiles/librtc.dir/ds1216e.c.o" \
"CMakeFiles/librtc.dir/ds1307.c.o" \
"CMakeFiles/librtc.dir/ds1602.c.o" \
"CMakeFiles/librtc.dir/pcf8583.c.o" \
"CMakeFiles/librtc.dir/rtc.c.o" \
"CMakeFiles/librtc.dir/rtc-58321a.c.o" \
"CMakeFiles/librtc.dir/rtc-72421.c.o"

# External object files for target librtc
librtc_EXTERNAL_OBJECTS =

src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/bq4830y.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/ds12c887.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/ds1202_1302.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/ds1216e.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/ds1307.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/ds1602.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/pcf8583.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/rtc.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/rtc-58321a.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/rtc-72421.c.o
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/build.make
src/core/rtc/librtc.a: src/core/rtc/CMakeFiles/librtc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gpf/code/dreamcast/VICE/vice/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library librtc.a"
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && $(CMAKE_COMMAND) -P CMakeFiles/librtc.dir/cmake_clean_target.cmake
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/librtc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/core/rtc/CMakeFiles/librtc.dir/build: src/core/rtc/librtc.a
.PHONY : src/core/rtc/CMakeFiles/librtc.dir/build

src/core/rtc/CMakeFiles/librtc.dir/clean:
	cd /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc && $(CMAKE_COMMAND) -P CMakeFiles/librtc.dir/cmake_clean.cmake
.PHONY : src/core/rtc/CMakeFiles/librtc.dir/clean

src/core/rtc/CMakeFiles/librtc.dir/depend:
	cd /home/gpf/code/dreamcast/VICE/vice/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gpf/code/dreamcast/VICE/vice /home/gpf/code/dreamcast/VICE/vice/src/core/rtc /home/gpf/code/dreamcast/VICE/vice/build /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc /home/gpf/code/dreamcast/VICE/vice/build/src/core/rtc/CMakeFiles/librtc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/core/rtc/CMakeFiles/librtc.dir/depend

