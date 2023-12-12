CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

all: test

whole: matrix.o back.o front.o
	$(CXX) $(CXXFLAGS) $^ -o $@

matrix.o: matrix.cpp matrix.h back.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

back.o: back.cpp back.h matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

front.o: front.cpp back.h matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: whole
	./whole

clean:
	rm -f *.o whole

# Header dependencies
matrix.o: matrix.h back.h
back.o: back.h matrix.h
front.o: back.h matrix.h








