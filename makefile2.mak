CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

all: test

whole: arithmetic.o arithmetic_test.o matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@


matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

arithmetic.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

arithmetic_test.o: matrix.cpp matrix.h arithmetic.cpp arithmetic.h


clean:
	rm -f *.o whole

# Header dependencies
matrix.o: matrix.h
arithmetic.o: matrix.h
arithmetic_test.o: matrix.h arithmetic.h