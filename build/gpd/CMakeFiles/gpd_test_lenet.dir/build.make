# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shengjian/bulldog_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shengjian/bulldog_ws/build

# Include any dependencies generated for this target.
include gpd/CMakeFiles/gpd_test_lenet.dir/depend.make

# Include the progress variables for this target.
include gpd/CMakeFiles/gpd_test_lenet.dir/progress.make

# Include the compile flags for this target's objects.
include gpd/CMakeFiles/gpd_test_lenet.dir/flags.make

gpd/CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.o: gpd/CMakeFiles/gpd_test_lenet.dir/flags.make
gpd/CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.o: /home/shengjian/bulldog_ws/src/gpd/src/tests/test_lenet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shengjian/bulldog_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object gpd/CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.o"
	cd /home/shengjian/bulldog_ws/build/gpd && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.o -c /home/shengjian/bulldog_ws/src/gpd/src/tests/test_lenet.cpp

gpd/CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.i"
	cd /home/shengjian/bulldog_ws/build/gpd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shengjian/bulldog_ws/src/gpd/src/tests/test_lenet.cpp > CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.i

gpd/CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.s"
	cd /home/shengjian/bulldog_ws/build/gpd && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shengjian/bulldog_ws/src/gpd/src/tests/test_lenet.cpp -o CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.s

# Object files for target gpd_test_lenet
gpd_test_lenet_OBJECTS = \
"CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.o"

# External object files for target gpd_test_lenet
gpd_test_lenet_EXTERNAL_OBJECTS =

/home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet: gpd/CMakeFiles/gpd_test_lenet.dir/src/tests/test_lenet.cpp.o
/home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet: gpd/CMakeFiles/gpd_test_lenet.dir/build.make
/home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet: /home/shengjian/bulldog_ws/devel/lib/libgpd_lenet.so
/home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet: /home/shengjian/bulldog_ws/devel/lib/libgpd_conv_layer.so
/home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet: /home/shengjian/bulldog_ws/devel/lib/libgpd_dense_layer.so
/home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet: gpd/CMakeFiles/gpd_test_lenet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shengjian/bulldog_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet"
	cd /home/shengjian/bulldog_ws/build/gpd && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gpd_test_lenet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gpd/CMakeFiles/gpd_test_lenet.dir/build: /home/shengjian/bulldog_ws/devel/lib/gpd/test_lenet

.PHONY : gpd/CMakeFiles/gpd_test_lenet.dir/build

gpd/CMakeFiles/gpd_test_lenet.dir/clean:
	cd /home/shengjian/bulldog_ws/build/gpd && $(CMAKE_COMMAND) -P CMakeFiles/gpd_test_lenet.dir/cmake_clean.cmake
.PHONY : gpd/CMakeFiles/gpd_test_lenet.dir/clean

gpd/CMakeFiles/gpd_test_lenet.dir/depend:
	cd /home/shengjian/bulldog_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shengjian/bulldog_ws/src /home/shengjian/bulldog_ws/src/gpd /home/shengjian/bulldog_ws/build /home/shengjian/bulldog_ws/build/gpd /home/shengjian/bulldog_ws/build/gpd/CMakeFiles/gpd_test_lenet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gpd/CMakeFiles/gpd_test_lenet.dir/depend

