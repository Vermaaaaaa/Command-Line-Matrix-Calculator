# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Target and its dependencies
all: front


# Compilation rules

front.o: front.o
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f *.o front
