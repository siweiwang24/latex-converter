# Compiler and flags.
CXX = g++
FLAGS = -std=c++17 -Wconversion -Wall -Werror -Wextra -pedantic
OPT = -Ofast -DNDEBUG

# Executable name for this program.
EXECUTABLE = ltx

# Build optimized executable.
release : $(EXECUTABLE).cpp
	$(CXX) $(FLAGS) $(OPT) $(EXECUTABLE).cpp -o $(EXECUTABLE)

# Checks code against Google's C++ style guide using cpplint.
.PHONY : style
style :
	cpplint $(EXECUTABLE).cpp

# Remove executable binary and generated objected files.
.PHONY : clean
clean : 
	rm -f $(EXECUTABLE)
