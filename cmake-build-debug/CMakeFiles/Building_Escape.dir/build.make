# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\Amir\Uni\Software M.Eng\Udemy\Unreal Engine C++\Building_Escape"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\Amir\Uni\Software M.Eng\Udemy\Unreal Engine C++\Building_Escape\cmake-build-debug"

# Utility rule file for Building_Escape.

# Include any custom commands dependencies for this target.
include CMakeFiles\Building_Escape.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\Building_Escape.dir\progress.make

CMakeFiles\Building_Escape:
	call "E:/Program Files/Epic Games/UE_4.27/Engine/Build/BatchFiles/Build.bat" Building_Escape Win64 Development "-project=E:/Amir/Uni/Software M.Eng/Udemy/Unreal Engine C++/Building_Escape/Building_Escape.uproject" -game -progress -buildscw

Building_Escape: CMakeFiles\Building_Escape
Building_Escape: CMakeFiles\Building_Escape.dir\build.make
.PHONY : Building_Escape

# Rule to build all files generated by this target.
CMakeFiles\Building_Escape.dir\build: Building_Escape
.PHONY : CMakeFiles\Building_Escape.dir\build

CMakeFiles\Building_Escape.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Building_Escape.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Building_Escape.dir\clean

CMakeFiles\Building_Escape.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "E:\Amir\Uni\Software M.Eng\Udemy\Unreal Engine C++\Building_Escape" "E:\Amir\Uni\Software M.Eng\Udemy\Unreal Engine C++\Building_Escape" "E:\Amir\Uni\Software M.Eng\Udemy\Unreal Engine C++\Building_Escape\cmake-build-debug" "E:\Amir\Uni\Software M.Eng\Udemy\Unreal Engine C++\Building_Escape\cmake-build-debug" "E:\Amir\Uni\Software M.Eng\Udemy\Unreal Engine C++\Building_Escape\cmake-build-debug\CMakeFiles\Building_Escape.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Building_Escape.dir\depend

