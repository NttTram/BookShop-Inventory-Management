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
CMAKE_SOURCE_DIR = /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/build

# Include any dependencies generated for this target.
include CMakeFiles/MySQLExample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MySQLExample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MySQLExample.dir/flags.make

CMakeFiles/MySQLExample.dir/sql.cpp.o: CMakeFiles/MySQLExample.dir/flags.make
CMakeFiles/MySQLExample.dir/sql.cpp.o: ../sql.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MySQLExample.dir/sql.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MySQLExample.dir/sql.cpp.o -c /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/sql.cpp

CMakeFiles/MySQLExample.dir/sql.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MySQLExample.dir/sql.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/sql.cpp > CMakeFiles/MySQLExample.dir/sql.cpp.i

CMakeFiles/MySQLExample.dir/sql.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MySQLExample.dir/sql.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/sql.cpp -o CMakeFiles/MySQLExample.dir/sql.cpp.s

# Object files for target MySQLExample
MySQLExample_OBJECTS = \
"CMakeFiles/MySQLExample.dir/sql.cpp.o"

# External object files for target MySQLExample
MySQLExample_EXTERNAL_OBJECTS =

MySQLExample: CMakeFiles/MySQLExample.dir/sql.cpp.o
MySQLExample: CMakeFiles/MySQLExample.dir/build.make
MySQLExample: /usr/lib/x86_64-linux-gnu/libmysqlclient.so
MySQLExample: CMakeFiles/MySQLExample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MySQLExample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MySQLExample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MySQLExample.dir/build: MySQLExample

.PHONY : CMakeFiles/MySQLExample.dir/build

CMakeFiles/MySQLExample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MySQLExample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MySQLExample.dir/clean

CMakeFiles/MySQLExample.dir/depend:
	cd /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/build /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/build /mnt/c/Users/anime/Documents/GitHub/BookShop-Inventory-Management/src/build/CMakeFiles/MySQLExample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MySQLExample.dir/depend
