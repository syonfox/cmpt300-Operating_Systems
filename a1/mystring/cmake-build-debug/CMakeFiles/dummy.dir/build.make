# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/syonfox/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/syonfox/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/183.4886.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dummy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dummy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dummy.dir/flags.make

CMakeFiles/dummy.dir/mystring.c.o: CMakeFiles/dummy.dir/flags.make
CMakeFiles/dummy.dir/mystring.c.o: ../mystring.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/dummy.dir/mystring.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dummy.dir/mystring.c.o   -c /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/mystring.c

CMakeFiles/dummy.dir/mystring.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dummy.dir/mystring.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/mystring.c > CMakeFiles/dummy.dir/mystring.c.i

CMakeFiles/dummy.dir/mystring.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dummy.dir/mystring.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/mystring.c -o CMakeFiles/dummy.dir/mystring.c.s

CMakeFiles/dummy.dir/test_mystring.c.o: CMakeFiles/dummy.dir/flags.make
CMakeFiles/dummy.dir/test_mystring.c.o: ../test_mystring.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/dummy.dir/test_mystring.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dummy.dir/test_mystring.c.o   -c /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/test_mystring.c

CMakeFiles/dummy.dir/test_mystring.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dummy.dir/test_mystring.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/test_mystring.c > CMakeFiles/dummy.dir/test_mystring.c.i

CMakeFiles/dummy.dir/test_mystring.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dummy.dir/test_mystring.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/test_mystring.c -o CMakeFiles/dummy.dir/test_mystring.c.s

# Object files for target dummy
dummy_OBJECTS = \
"CMakeFiles/dummy.dir/mystring.c.o" \
"CMakeFiles/dummy.dir/test_mystring.c.o"

# External object files for target dummy
dummy_EXTERNAL_OBJECTS =

dummy: CMakeFiles/dummy.dir/mystring.c.o
dummy: CMakeFiles/dummy.dir/test_mystring.c.o
dummy: CMakeFiles/dummy.dir/build.make
dummy: CMakeFiles/dummy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable dummy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dummy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dummy.dir/build: dummy

.PHONY : CMakeFiles/dummy.dir/build

CMakeFiles/dummy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dummy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dummy.dir/clean

CMakeFiles/dummy.dir/depend:
	cd /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug /home/syonfox/github/cmpt300-Operating_Systems/a1/mystring/cmake-build-debug/CMakeFiles/dummy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dummy.dir/depend

