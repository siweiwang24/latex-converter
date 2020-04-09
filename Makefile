# Compiler and flags.
CXX = g++ -std=c++17
FLAGS = -Wall -Werror -Wextra -Wconversion -pedantic -Wfloat-equal -Wduplicated-branches -Wduplicated-cond -Wshadow -Wdouble-promotion -Wundef
OPT = -Ofast -DNDEBUG

# Executable name for this program.
EXECUTABLE = ltx

# Build optimized executable.
all : $(EXECUTABLE).cpp
	$(CXX) $(FLAGS) $(OPT) $(EXECUTABLE).cpp -o $(EXECUTABLE)

# Remove executable binary and generated objected files.
.PHONY : clean
clean : 
	rm -f $(EXECUTABLE)
