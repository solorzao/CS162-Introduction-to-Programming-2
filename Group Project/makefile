### Citation:
###   Based off of makefile "intermediate_make_sample" by Harlan James
###   from OSU (W2019) Intro to Computer Science II -> Pages -> Make help
###
### Options
###   make       - Base - creates executable based on changed files, runs file
###   make debug - Runs valgrind
###   make clean - Cleans up files
###   make zip   - Creates zip file
###
### Version History
###   2019-01-11 - Used base sample from citation
###   2019-01-11 - Made initial modifications
###   2019-01-11 - Changed default behavior not to run valgrind
###                Run make debug to run valgrind
###   2019-01-11 - Added -D option to zip file creation
###   2019-02-01 - Added clean back in as a default option
###                Added clean back as part of debug option

# Project Name
PROJ = game

# Compiler
$(CXX) = g++

# Source Files
SRC  = main.cpp
SRC += Ant.cpp
SRC += Critter.cpp
SRC += Doodlebug.cpp
SRC += Game.cpp
SRC += grid_functions.cpp


# Create an object for each source file
OBJ = $(SRC:.cpp=.o)

# Output File
BIN = $(PROJ)

# Compiler Flags
# -Wall       - Enables all warnings about constructions
# -pedantic   - Enables all warnings demanded by strict C++
# -g          - Get debugging info
# -std=gnu+11 - Set language standard
CXXFLAGS  = -Wall
CXXFLAGS += -pedantic
CXXFLAGS += -std=gnu++11
CXXFLAGS += -g

# Valgrind Options
VOPT  = --tool=memcheck
VOPT += --leak-check=full
VOPT += --show-leak-kinds=all
VOPT += --track-origins=yes

# Names of files to always skip
.PHONY: default debug clean zip

# Default Behavior: compile & run
default: clean $(BIN)

# Notice the dependency chain.
#
# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
#
# Special Symbols:
#     $@    Name of tag
#     $^    Name of dependency
debug: clean $(BIN)
	@echo "Running valgrind:"
	valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "Creating the executable:"
	$(CXX) $(CXXFLAGS) $^ -o $@


# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "Creating the object files:"
	$(CXX) $(CXXFLAGS) -c $^
	@echo

zip:
	@echo "Creating the zip file:"
	zip -D $(PROJ)_Group3.zip *.cpp *.hpp makefile *.pdf

clean: $(CLEAN)
	@echo "Running clean command:"
	@echo "rm *.o"
	@echo "rm $(BIN)"
	@rm -f *.o $(BIN)
	@echo
