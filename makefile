# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -Wno-format


# Target and its dependencies
all: main.cpp
	g++ $(CXXFLAGS) main.cpp matrix.cpp -o unit2
