# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/build

# Include any dependencies generated for this target.
include CMakeFiles/employee.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/employee.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/employee.dir/flags.make

CMakeFiles/employee.dir/employee.cpp.o: CMakeFiles/employee.dir/flags.make
CMakeFiles/employee.dir/employee.cpp.o: ../employee.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/employee.dir/employee.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/employee.dir/employee.cpp.o -c /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/employee.cpp

CMakeFiles/employee.dir/employee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/employee.dir/employee.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/employee.cpp > CMakeFiles/employee.dir/employee.cpp.i

CMakeFiles/employee.dir/employee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/employee.dir/employee.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/employee.cpp -o CMakeFiles/employee.dir/employee.cpp.s

CMakeFiles/employee.dir/employee.cpp.o.requires:

.PHONY : CMakeFiles/employee.dir/employee.cpp.o.requires

CMakeFiles/employee.dir/employee.cpp.o.provides: CMakeFiles/employee.dir/employee.cpp.o.requires
	$(MAKE) -f CMakeFiles/employee.dir/build.make CMakeFiles/employee.dir/employee.cpp.o.provides.build
.PHONY : CMakeFiles/employee.dir/employee.cpp.o.provides

CMakeFiles/employee.dir/employee.cpp.o.provides.build: CMakeFiles/employee.dir/employee.cpp.o


# Object files for target employee
employee_OBJECTS = \
"CMakeFiles/employee.dir/employee.cpp.o"

# External object files for target employee
employee_EXTERNAL_OBJECTS =

employee: CMakeFiles/employee.dir/employee.cpp.o
employee: CMakeFiles/employee.dir/build.make
employee: CMakeFiles/employee.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable employee"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/employee.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/employee.dir/build: employee

.PHONY : CMakeFiles/employee.dir/build

CMakeFiles/employee.dir/requires: CMakeFiles/employee.dir/employee.cpp.o.requires

.PHONY : CMakeFiles/employee.dir/requires

CMakeFiles/employee.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/employee.dir/cmake_clean.cmake
.PHONY : CMakeFiles/employee.dir/clean

CMakeFiles/employee.dir/depend:
	cd /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/build /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/build /mnt/c/Users/ravid/Documents/GitHub/Company-Employee-Payroll-System/build/CMakeFiles/employee.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/employee.dir/depend

