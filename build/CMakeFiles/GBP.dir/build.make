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
CMAKE_SOURCE_DIR = /homes/sc7617/ACA20-21/GBP-challenge-git-repo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /homes/sc7617/ACA20-21/GBP-challenge-git-repo/build

# Include any dependencies generated for this target.
include CMakeFiles/GBP.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GBP.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GBP.dir/flags.make

CMakeFiles/GBP.dir/src/main.cc.o: CMakeFiles/GBP.dir/flags.make
CMakeFiles/GBP.dir/src/main.cc.o: ../src/main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/homes/sc7617/ACA20-21/GBP-challenge-git-repo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GBP.dir/src/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GBP.dir/src/main.cc.o -c /homes/sc7617/ACA20-21/GBP-challenge-git-repo/src/main.cc

CMakeFiles/GBP.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GBP.dir/src/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /homes/sc7617/ACA20-21/GBP-challenge-git-repo/src/main.cc > CMakeFiles/GBP.dir/src/main.cc.i

CMakeFiles/GBP.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GBP.dir/src/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /homes/sc7617/ACA20-21/GBP-challenge-git-repo/src/main.cc -o CMakeFiles/GBP.dir/src/main.cc.s

# Object files for target GBP
GBP_OBJECTS = \
"CMakeFiles/GBP.dir/src/main.cc.o"

# External object files for target GBP
GBP_EXTERNAL_OBJECTS =

GBP: CMakeFiles/GBP.dir/src/main.cc.o
GBP: CMakeFiles/GBP.dir/build.make
GBP: liblibGBP.a
GBP: CMakeFiles/GBP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/homes/sc7617/ACA20-21/GBP-challenge-git-repo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GBP"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GBP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GBP.dir/build: GBP

.PHONY : CMakeFiles/GBP.dir/build

CMakeFiles/GBP.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GBP.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GBP.dir/clean

CMakeFiles/GBP.dir/depend:
	cd /homes/sc7617/ACA20-21/GBP-challenge-git-repo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /homes/sc7617/ACA20-21/GBP-challenge-git-repo /homes/sc7617/ACA20-21/GBP-challenge-git-repo /homes/sc7617/ACA20-21/GBP-challenge-git-repo/build /homes/sc7617/ACA20-21/GBP-challenge-git-repo/build /homes/sc7617/ACA20-21/GBP-challenge-git-repo/build/CMakeFiles/GBP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GBP.dir/depend

