# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/stud/test_task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud/test_task

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/stud/test_task/CMakeFiles /home/stud/test_task//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/stud/test_task/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named url_shortener

# Build rule for target.
url_shortener: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 url_shortener
.PHONY : url_shortener

# fast build rule for target.
url_shortener/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/build
.PHONY : url_shortener/fast

interface.o: interface.cpp.o
.PHONY : interface.o

# target to build an object file
interface.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/interface.cpp.o
.PHONY : interface.cpp.o

interface.i: interface.cpp.i
.PHONY : interface.i

# target to preprocess a source file
interface.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/interface.cpp.i
.PHONY : interface.cpp.i

interface.s: interface.cpp.s
.PHONY : interface.s

# target to generate assembly for a file
interface.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/interface.cpp.s
.PHONY : interface.cpp.s

logger.o: logger.cpp.o
.PHONY : logger.o

# target to build an object file
logger.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/logger.cpp.o
.PHONY : logger.cpp.o

logger.i: logger.cpp.i
.PHONY : logger.i

# target to preprocess a source file
logger.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/logger.cpp.i
.PHONY : logger.cpp.i

logger.s: logger.cpp.s
.PHONY : logger.s

# target to generate assembly for a file
logger.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/logger.cpp.s
.PHONY : logger.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/main.cpp.s
.PHONY : main.cpp.s

saveload.o: saveload.cpp.o
.PHONY : saveload.o

# target to build an object file
saveload.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/saveload.cpp.o
.PHONY : saveload.cpp.o

saveload.i: saveload.cpp.i
.PHONY : saveload.i

# target to preprocess a source file
saveload.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/saveload.cpp.i
.PHONY : saveload.cpp.i

saveload.s: saveload.cpp.s
.PHONY : saveload.s

# target to generate assembly for a file
saveload.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/saveload.cpp.s
.PHONY : saveload.cpp.s

shortener.o: shortener.cpp.o
.PHONY : shortener.o

# target to build an object file
shortener.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/shortener.cpp.o
.PHONY : shortener.cpp.o

shortener.i: shortener.cpp.i
.PHONY : shortener.i

# target to preprocess a source file
shortener.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/shortener.cpp.i
.PHONY : shortener.cpp.i

shortener.s: shortener.cpp.s
.PHONY : shortener.s

# target to generate assembly for a file
shortener.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/url_shortener.dir/build.make CMakeFiles/url_shortener.dir/shortener.cpp.s
.PHONY : shortener.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... url_shortener"
	@echo "... interface.o"
	@echo "... interface.i"
	@echo "... interface.s"
	@echo "... logger.o"
	@echo "... logger.i"
	@echo "... logger.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... saveload.o"
	@echo "... saveload.i"
	@echo "... saveload.s"
	@echo "... shortener.o"
	@echo "... shortener.i"
	@echo "... shortener.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

