# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/oled-clion.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/oled-clion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/oled-clion.dir/flags.make

CMakeFiles/oled-clion.dir/main.cpp.obj: CMakeFiles/oled-clion.dir/flags.make
CMakeFiles/oled-clion.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/oled-clion.dir/main.cpp.obj"
	/usr/local/CrossPack-AVR/bin/avr-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oled-clion.dir/main.cpp.obj -c "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/main.cpp"

CMakeFiles/oled-clion.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oled-clion.dir/main.cpp.i"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/main.cpp" > CMakeFiles/oled-clion.dir/main.cpp.i

CMakeFiles/oled-clion.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oled-clion.dir/main.cpp.s"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/main.cpp" -o CMakeFiles/oled-clion.dir/main.cpp.s

CMakeFiles/oled-clion.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/oled-clion.dir/main.cpp.obj.requires

CMakeFiles/oled-clion.dir/main.cpp.obj.provides: CMakeFiles/oled-clion.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles/oled-clion.dir/build.make CMakeFiles/oled-clion.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/oled-clion.dir/main.cpp.obj.provides

CMakeFiles/oled-clion.dir/main.cpp.obj.provides.build: CMakeFiles/oled-clion.dir/main.cpp.obj


CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj: CMakeFiles/oled-clion.dir/flags.make
CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj: ../Classes/Font.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj"
	/usr/local/CrossPack-AVR/bin/avr-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj -c "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Font.cpp"

CMakeFiles/oled-clion.dir/Classes/Font.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oled-clion.dir/Classes/Font.cpp.i"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Font.cpp" > CMakeFiles/oled-clion.dir/Classes/Font.cpp.i

CMakeFiles/oled-clion.dir/Classes/Font.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oled-clion.dir/Classes/Font.cpp.s"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Font.cpp" -o CMakeFiles/oled-clion.dir/Classes/Font.cpp.s

CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.requires:

.PHONY : CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.requires

CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.provides: CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.requires
	$(MAKE) -f CMakeFiles/oled-clion.dir/build.make CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.provides.build
.PHONY : CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.provides

CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.provides.build: CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj


CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj: CMakeFiles/oled-clion.dir/flags.make
CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj: ../Classes/Graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj"
	/usr/local/CrossPack-AVR/bin/avr-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj -c "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Graphics.cpp"

CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.i"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Graphics.cpp" > CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.i

CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.s"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Graphics.cpp" -o CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.s

CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.requires:

.PHONY : CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.requires

CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.provides: CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.requires
	$(MAKE) -f CMakeFiles/oled-clion.dir/build.make CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.provides.build
.PHONY : CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.provides

CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.provides.build: CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj


CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj: CMakeFiles/oled-clion.dir/flags.make
CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj: ../Classes/LinkedArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj"
	/usr/local/CrossPack-AVR/bin/avr-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj -c "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/LinkedArray.cpp"

CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.i"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/LinkedArray.cpp" > CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.i

CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.s"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/LinkedArray.cpp" -o CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.s

CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.requires:

.PHONY : CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.requires

CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.provides: CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.requires
	$(MAKE) -f CMakeFiles/oled-clion.dir/build.make CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.provides.build
.PHONY : CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.provides

CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.provides.build: CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj


CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj: CMakeFiles/oled-clion.dir/flags.make
CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj: ../Classes/OLED.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj"
	/usr/local/CrossPack-AVR/bin/avr-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj -c "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/OLED.cpp"

CMakeFiles/oled-clion.dir/Classes/OLED.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oled-clion.dir/Classes/OLED.cpp.i"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/OLED.cpp" > CMakeFiles/oled-clion.dir/Classes/OLED.cpp.i

CMakeFiles/oled-clion.dir/Classes/OLED.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oled-clion.dir/Classes/OLED.cpp.s"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/OLED.cpp" -o CMakeFiles/oled-clion.dir/Classes/OLED.cpp.s

CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.requires:

.PHONY : CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.requires

CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.provides: CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.requires
	$(MAKE) -f CMakeFiles/oled-clion.dir/build.make CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.provides.build
.PHONY : CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.provides

CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.provides.build: CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj


CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj: CMakeFiles/oled-clion.dir/flags.make
CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj: ../Classes/Pin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj"
	/usr/local/CrossPack-AVR/bin/avr-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj -c "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Pin.cpp"

CMakeFiles/oled-clion.dir/Classes/Pin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oled-clion.dir/Classes/Pin.cpp.i"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Pin.cpp" > CMakeFiles/oled-clion.dir/Classes/Pin.cpp.i

CMakeFiles/oled-clion.dir/Classes/Pin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oled-clion.dir/Classes/Pin.cpp.s"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/Pin.cpp" -o CMakeFiles/oled-clion.dir/Classes/Pin.cpp.s

CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.requires:

.PHONY : CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.requires

CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.provides: CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.requires
	$(MAKE) -f CMakeFiles/oled-clion.dir/build.make CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.provides.build
.PHONY : CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.provides

CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.provides.build: CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj


CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj: CMakeFiles/oled-clion.dir/flags.make
CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj: ../Classes/SPI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj"
	/usr/local/CrossPack-AVR/bin/avr-g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj -c "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/SPI.cpp"

CMakeFiles/oled-clion.dir/Classes/SPI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/oled-clion.dir/Classes/SPI.cpp.i"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/SPI.cpp" > CMakeFiles/oled-clion.dir/Classes/SPI.cpp.i

CMakeFiles/oled-clion.dir/Classes/SPI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/oled-clion.dir/Classes/SPI.cpp.s"
	/usr/local/CrossPack-AVR/bin/avr-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/Classes/SPI.cpp" -o CMakeFiles/oled-clion.dir/Classes/SPI.cpp.s

CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.requires:

.PHONY : CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.requires

CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.provides: CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.requires
	$(MAKE) -f CMakeFiles/oled-clion.dir/build.make CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.provides.build
.PHONY : CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.provides

CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.provides.build: CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj


# Object files for target oled-clion
oled__clion_OBJECTS = \
"CMakeFiles/oled-clion.dir/main.cpp.obj" \
"CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj" \
"CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj" \
"CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj" \
"CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj" \
"CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj" \
"CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj"

# External object files for target oled-clion
oled__clion_EXTERNAL_OBJECTS =

../bin/oled-clion: CMakeFiles/oled-clion.dir/main.cpp.obj
../bin/oled-clion: CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj
../bin/oled-clion: CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj
../bin/oled-clion: CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj
../bin/oled-clion: CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj
../bin/oled-clion: CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj
../bin/oled-clion: CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj
../bin/oled-clion: CMakeFiles/oled-clion.dir/build.make
../bin/oled-clion: CMakeFiles/oled-clion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/oled-clion"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/oled-clion.dir/link.txt --verbose=$(VERBOSE)
	avr-objcopy -O ihex -R.eeprom -R .fuse -R .lock -R .signature /Users/wangyang/Documents/Projects/On\ Git/AVRProjs/oled-clion/oled/bin/oled-clion /Users/wangyang/Documents/Projects/On\ Git/AVRProjs/oled-clion/oled/bin/oled-clion.hex
	avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 /Users/wangyang/Documents/Projects/On\ Git/AVRProjs/oled-clion/oled/bin/oled-clion /Users/wangyang/Documents/Projects/On\ Git/AVRProjs/oled-clion/oled/bin/oled-clion.eep
	avr-size /Users/wangyang/Documents/Projects/On\ Git/AVRProjs/oled-clion/oled/bin/oled-clion --mcu=atmega16 --format=avr
	/usr/local/CrossPack-AVR-20131216/bin/avrdude -pm16 -cusbasp -Uflash:w:/Users/wangyang/Documents/Projects/On\ Git/AVRProjs/oled-clion/oled/bin/oled-clion.hex:a

# Rule to build all files generated by this target.
CMakeFiles/oled-clion.dir/build: ../bin/oled-clion

.PHONY : CMakeFiles/oled-clion.dir/build

CMakeFiles/oled-clion.dir/requires: CMakeFiles/oled-clion.dir/main.cpp.obj.requires
CMakeFiles/oled-clion.dir/requires: CMakeFiles/oled-clion.dir/Classes/Font.cpp.obj.requires
CMakeFiles/oled-clion.dir/requires: CMakeFiles/oled-clion.dir/Classes/Graphics.cpp.obj.requires
CMakeFiles/oled-clion.dir/requires: CMakeFiles/oled-clion.dir/Classes/LinkedArray.cpp.obj.requires
CMakeFiles/oled-clion.dir/requires: CMakeFiles/oled-clion.dir/Classes/OLED.cpp.obj.requires
CMakeFiles/oled-clion.dir/requires: CMakeFiles/oled-clion.dir/Classes/Pin.cpp.obj.requires
CMakeFiles/oled-clion.dir/requires: CMakeFiles/oled-clion.dir/Classes/SPI.cpp.obj.requires

.PHONY : CMakeFiles/oled-clion.dir/requires

CMakeFiles/oled-clion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/oled-clion.dir/cmake_clean.cmake
.PHONY : CMakeFiles/oled-clion.dir/clean

CMakeFiles/oled-clion.dir/depend:
	cd "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled" "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled" "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug" "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug" "/Users/wangyang/Documents/Projects/On Git/AVRProjs/oled-clion/oled/cmake-build-debug/CMakeFiles/oled-clion.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/oled-clion.dir/depend

