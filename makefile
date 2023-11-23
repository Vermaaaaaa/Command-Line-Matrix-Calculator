CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

all: whole

whole: front.o matrix.o back.o
	$(CXX) $(CXXFLAGS) $^ -o $@

front.o: front.cpp back.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

matrix.o: matrix.cpp matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

back.o: back.cpp matrix.h back.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o whole

# Header dependencies
front.o: back.h
matrix.o: matrix.h
back.o: matrix.h back.h
