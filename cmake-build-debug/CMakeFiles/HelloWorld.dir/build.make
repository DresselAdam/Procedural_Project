# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
CMAKE_COMMAND = "C:\Users\amdressel8336\AppData\Local\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\amdressel8336\AppData\Local\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\HelloWorld.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\HelloWorld.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\HelloWorld.dir\flags.make

CMakeFiles\HelloWorld.dir\main.cpp.obj: CMakeFiles\HelloWorld.dir\flags.make
CMakeFiles\HelloWorld.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HelloWorld.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\HelloWorld.dir\main.cpp.obj /FdCMakeFiles\HelloWorld.dir\ /FS -c "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\main.cpp"
<<

CMakeFiles\HelloWorld.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HelloWorld.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe > CMakeFiles\HelloWorld.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\main.cpp"
<<

CMakeFiles\HelloWorld.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HelloWorld.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\HelloWorld.dir\main.cpp.s /c "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\main.cpp"
<<

# Object files for target HelloWorld
HelloWorld_OBJECTS = \
"CMakeFiles\HelloWorld.dir\main.cpp.obj"

# External object files for target HelloWorld
HelloWorld_EXTERNAL_OBJECTS =

HelloWorld.exe: CMakeFiles\HelloWorld.dir\main.cpp.obj
HelloWorld.exe: CMakeFiles\HelloWorld.dir\build.make
HelloWorld.exe: CMakeFiles\HelloWorld.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HelloWorld.exe"
	"C:\Users\amdressel8336\AppData\Local\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\HelloWorld.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100171~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1414~1.264\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\HelloWorld.dir\objects1.rsp @<<
 /out:HelloWorld.exe /implib:HelloWorld.lib /pdb:"C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\cmake-build-debug\HelloWorld.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\HelloWorld.dir\build: HelloWorld.exe

.PHONY : CMakeFiles\HelloWorld.dir\build

CMakeFiles\HelloWorld.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\HelloWorld.dir\cmake_clean.cmake
.PHONY : CMakeFiles\HelloWorld.dir\clean

CMakeFiles\HelloWorld.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work" "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work" "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\cmake-build-debug" "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\cmake-build-debug" "C:\Users\amdressel8336\OneDrive - Florida Gulf Coast University\CLionProjects\Please_Work\cmake-build-debug\CMakeFiles\HelloWorld.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\HelloWorld.dir\depend

