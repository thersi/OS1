# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Therese/CLionProjects/OS1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Therese/CLionProjects/OS1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OS1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OS1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OS1.dir/flags.make

CMakeFiles/OS1.dir/Main.c.o: CMakeFiles/OS1.dir/flags.make
CMakeFiles/OS1.dir/Main.c.o: ../Main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Therese/CLionProjects/OS1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/OS1.dir/Main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/OS1.dir/Main.c.o   -c /mnt/c/Users/Therese/CLionProjects/OS1/Main.c

CMakeFiles/OS1.dir/Main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OS1.dir/Main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/Therese/CLionProjects/OS1/Main.c > CMakeFiles/OS1.dir/Main.c.i

CMakeFiles/OS1.dir/Main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OS1.dir/Main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/Therese/CLionProjects/OS1/Main.c -o CMakeFiles/OS1.dir/Main.c.s

# Object files for target OS1
OS1_OBJECTS = \
"CMakeFiles/OS1.dir/Main.c.o"

# External object files for target OS1
OS1_EXTERNAL_OBJECTS =

OS1: CMakeFiles/OS1.dir/Main.c.o
OS1: CMakeFiles/OS1.dir/build.make
OS1: CMakeFiles/OS1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Therese/CLionProjects/OS1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable OS1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OS1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OS1.dir/build: OS1

.PHONY : CMakeFiles/OS1.dir/build

CMakeFiles/OS1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OS1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OS1.dir/clean

CMakeFiles/OS1.dir/depend:
	cd /mnt/c/Users/Therese/CLionProjects/OS1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Therese/CLionProjects/OS1 /mnt/c/Users/Therese/CLionProjects/OS1 /mnt/c/Users/Therese/CLionProjects/OS1/cmake-build-debug /mnt/c/Users/Therese/CLionProjects/OS1/cmake-build-debug /mnt/c/Users/Therese/CLionProjects/OS1/cmake-build-debug/CMakeFiles/OS1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OS1.dir/depend

