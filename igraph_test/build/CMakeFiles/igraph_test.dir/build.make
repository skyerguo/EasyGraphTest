# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /users/gtc/test-EG/igraph_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /users/gtc/test-EG/igraph_test/build

# Include any dependencies generated for this target.
include CMakeFiles/igraph_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/igraph_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/igraph_test.dir/flags.make

CMakeFiles/igraph_test.dir/igraph_test.c.o: CMakeFiles/igraph_test.dir/flags.make
CMakeFiles/igraph_test.dir/igraph_test.c.o: ../igraph_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/users/gtc/test-EG/igraph_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/igraph_test.dir/igraph_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/igraph_test.dir/igraph_test.c.o -c /users/gtc/test-EG/igraph_test/igraph_test.c

CMakeFiles/igraph_test.dir/igraph_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/igraph_test.dir/igraph_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /users/gtc/test-EG/igraph_test/igraph_test.c > CMakeFiles/igraph_test.dir/igraph_test.c.i

CMakeFiles/igraph_test.dir/igraph_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/igraph_test.dir/igraph_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /users/gtc/test-EG/igraph_test/igraph_test.c -o CMakeFiles/igraph_test.dir/igraph_test.c.s

# Object files for target igraph_test
igraph_test_OBJECTS = \
"CMakeFiles/igraph_test.dir/igraph_test.c.o"

# External object files for target igraph_test
igraph_test_EXTERNAL_OBJECTS =

igraph_test: CMakeFiles/igraph_test.dir/igraph_test.c.o
igraph_test: CMakeFiles/igraph_test.dir/build.make
igraph_test: /usr/local/lib/libigraph.a
igraph_test: /usr/lib/x86_64-linux-gnu/libm.so
igraph_test: /usr/lib/gcc/x86_64-linux-gnu/7/libgomp.so
igraph_test: /usr/lib/x86_64-linux-gnu/libpthread.so
igraph_test: CMakeFiles/igraph_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/users/gtc/test-EG/igraph_test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable igraph_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/igraph_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/igraph_test.dir/build: igraph_test

.PHONY : CMakeFiles/igraph_test.dir/build

CMakeFiles/igraph_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/igraph_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/igraph_test.dir/clean

CMakeFiles/igraph_test.dir/depend:
	cd /users/gtc/test-EG/igraph_test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /users/gtc/test-EG/igraph_test /users/gtc/test-EG/igraph_test /users/gtc/test-EG/igraph_test/build /users/gtc/test-EG/igraph_test/build /users/gtc/test-EG/igraph_test/build/CMakeFiles/igraph_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/igraph_test.dir/depend

