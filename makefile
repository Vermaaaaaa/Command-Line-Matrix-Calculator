# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

# Target and its dependencies
all: unit2

# Linking rule
unit2: test2.o matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compilation rules
main.o: test2.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f *.o unit2
