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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/src/extern_bluetooth_mp3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/src/extern_bluetooth_mp3/build

# Include any dependencies generated for this target.
include CMakeFiles/objects.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/objects.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/objects.dir/flags.make

CMakeFiles/objects.dir/src/main.cpp.o: CMakeFiles/objects.dir/flags.make
CMakeFiles/objects.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/src/extern_bluetooth_mp3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/objects.dir/src/main.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/objects.dir/src/main.cpp.o -c /home/pi/src/extern_bluetooth_mp3/src/main.cpp

CMakeFiles/objects.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/main.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/src/extern_bluetooth_mp3/src/main.cpp > CMakeFiles/objects.dir/src/main.cpp.i

CMakeFiles/objects.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/main.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/src/extern_bluetooth_mp3/src/main.cpp -o CMakeFiles/objects.dir/src/main.cpp.s

CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.o: CMakeFiles/objects.dir/flags.make
CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.o: ../src/tools/bluetooth_tool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/src/extern_bluetooth_mp3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.o -c /home/pi/src/extern_bluetooth_mp3/src/tools/bluetooth_tool.cpp

CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/src/extern_bluetooth_mp3/src/tools/bluetooth_tool.cpp > CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.i

CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/src/extern_bluetooth_mp3/src/tools/bluetooth_tool.cpp -o CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.s

objects: CMakeFiles/objects.dir/src/main.cpp.o
objects: CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.o
objects: CMakeFiles/objects.dir/build.make

.PHONY : objects

# Rule to build all files generated by this target.
CMakeFiles/objects.dir/build: objects

.PHONY : CMakeFiles/objects.dir/build

CMakeFiles/objects.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/objects.dir/cmake_clean.cmake
.PHONY : CMakeFiles/objects.dir/clean

CMakeFiles/objects.dir/depend:
	cd /home/pi/src/extern_bluetooth_mp3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/src/extern_bluetooth_mp3 /home/pi/src/extern_bluetooth_mp3 /home/pi/src/extern_bluetooth_mp3/build /home/pi/src/extern_bluetooth_mp3/build /home/pi/src/extern_bluetooth_mp3/build/CMakeFiles/objects.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/objects.dir/depend

