# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Git\Clion\DataStructure

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Git\Clion\DataStructure\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/seqList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/seqList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/seqList.dir/flags.make

CMakeFiles/seqList.dir/LinearList/SeqList_main.c.obj: CMakeFiles/seqList.dir/flags.make
CMakeFiles/seqList.dir/LinearList/SeqList_main.c.obj: CMakeFiles/seqList.dir/includes_C.rsp
CMakeFiles/seqList.dir/LinearList/SeqList_main.c.obj: ../LinearList/SeqList_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Git\Clion\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/seqList.dir/LinearList/SeqList_main.c.obj"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\seqList.dir\LinearList\SeqList_main.c.obj   -c F:\Git\Clion\DataStructure\LinearList\SeqList_main.c

CMakeFiles/seqList.dir/LinearList/SeqList_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/seqList.dir/LinearList/SeqList_main.c.i"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Git\Clion\DataStructure\LinearList\SeqList_main.c > CMakeFiles\seqList.dir\LinearList\SeqList_main.c.i

CMakeFiles/seqList.dir/LinearList/SeqList_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/seqList.dir/LinearList/SeqList_main.c.s"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Git\Clion\DataStructure\LinearList\SeqList_main.c -o CMakeFiles\seqList.dir\LinearList\SeqList_main.c.s

CMakeFiles/seqList.dir/LinearList/SeqList.c.obj: CMakeFiles/seqList.dir/flags.make
CMakeFiles/seqList.dir/LinearList/SeqList.c.obj: CMakeFiles/seqList.dir/includes_C.rsp
CMakeFiles/seqList.dir/LinearList/SeqList.c.obj: ../LinearList/SeqList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Git\Clion\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/seqList.dir/LinearList/SeqList.c.obj"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\seqList.dir\LinearList\SeqList.c.obj   -c F:\Git\Clion\DataStructure\LinearList\SeqList.c

CMakeFiles/seqList.dir/LinearList/SeqList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/seqList.dir/LinearList/SeqList.c.i"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E F:\Git\Clion\DataStructure\LinearList\SeqList.c > CMakeFiles\seqList.dir\LinearList\SeqList.c.i

CMakeFiles/seqList.dir/LinearList/SeqList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/seqList.dir/LinearList/SeqList.c.s"
	"D:\Program Files\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S F:\Git\Clion\DataStructure\LinearList\SeqList.c -o CMakeFiles\seqList.dir\LinearList\SeqList.c.s

# Object files for target seqList
seqList_OBJECTS = \
"CMakeFiles/seqList.dir/LinearList/SeqList_main.c.obj" \
"CMakeFiles/seqList.dir/LinearList/SeqList.c.obj"

# External object files for target seqList
seqList_EXTERNAL_OBJECTS =

seqList.exe: CMakeFiles/seqList.dir/LinearList/SeqList_main.c.obj
seqList.exe: CMakeFiles/seqList.dir/LinearList/SeqList.c.obj
seqList.exe: CMakeFiles/seqList.dir/build.make
seqList.exe: CMakeFiles/seqList.dir/linklibs.rsp
seqList.exe: CMakeFiles/seqList.dir/objects1.rsp
seqList.exe: CMakeFiles/seqList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Git\Clion\DataStructure\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable seqList.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\seqList.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/seqList.dir/build: seqList.exe

.PHONY : CMakeFiles/seqList.dir/build

CMakeFiles/seqList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\seqList.dir\cmake_clean.cmake
.PHONY : CMakeFiles/seqList.dir/clean

CMakeFiles/seqList.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Git\Clion\DataStructure F:\Git\Clion\DataStructure F:\Git\Clion\DataStructure\cmake-build-debug F:\Git\Clion\DataStructure\cmake-build-debug F:\Git\Clion\DataStructure\cmake-build-debug\CMakeFiles\seqList.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/seqList.dir/depend

