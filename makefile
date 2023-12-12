CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

all: test

whole: arithmetic.o arithmetic_test.o matrix.o
	$(CXX) $(CXXFLAGS) $^ -o $@

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

arithmetic.o: arithmetic.cpp arithmetic.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

arithmetic_test.o: arithmetic_test.cpp arithmetic.h matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: whole
	./whole

clean:
	rm -f *.o whole

matrix.o: matrix.h
arithmetic.o: arithmetic.h
arithmetic_test.o: arithmetic.h matrix.h
