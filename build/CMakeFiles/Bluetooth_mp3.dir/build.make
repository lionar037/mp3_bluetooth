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
include CMakeFiles/Bluetooth_mp3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Bluetooth_mp3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Bluetooth_mp3.dir/flags.make

# Object files for target Bluetooth_mp3
Bluetooth_mp3_OBJECTS =

# External object files for target Bluetooth_mp3
Bluetooth_mp3_EXTERNAL_OBJECTS = \
"/home/pi/src/extern_bluetooth_mp3/build/CMakeFiles/objects.dir/src/main.cpp.o" \
"/home/pi/src/extern_bluetooth_mp3/build/CMakeFiles/objects.dir/src/oled/oled.cpp.o" \
"/home/pi/src/extern_bluetooth_mp3/build/CMakeFiles/objects.dir/src/sound/sound.cpp.o" \
"/home/pi/src/extern_bluetooth_mp3/build/CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.o"

../bin/Bluetooth_mp3: CMakeFiles/objects.dir/src/main.cpp.o
../bin/Bluetooth_mp3: CMakeFiles/objects.dir/src/oled/oled.cpp.o
../bin/Bluetooth_mp3: CMakeFiles/objects.dir/src/sound/sound.cpp.o
../bin/Bluetooth_mp3: CMakeFiles/objects.dir/src/tools/bluetooth_tool.cpp.o
../bin/Bluetooth_mp3: CMakeFiles/Bluetooth_mp3.dir/build.make
../bin/Bluetooth_mp3: CMakeFiles/Bluetooth_mp3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/src/extern_bluetooth_mp3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX executable ../bin/Bluetooth_mp3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Bluetooth_mp3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Bluetooth_mp3.dir/build: ../bin/Bluetooth_mp3

.PHONY : CMakeFiles/Bluetooth_mp3.dir/build

CMakeFiles/Bluetooth_mp3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Bluetooth_mp3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Bluetooth_mp3.dir/clean

CMakeFiles/Bluetooth_mp3.dir/depend:
	cd /home/pi/src/extern_bluetooth_mp3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/src/extern_bluetooth_mp3 /home/pi/src/extern_bluetooth_mp3 /home/pi/src/extern_bluetooth_mp3/build /home/pi/src/extern_bluetooth_mp3/build /home/pi/src/extern_bluetooth_mp3/build/CMakeFiles/Bluetooth_mp3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Bluetooth_mp3.dir/depend

