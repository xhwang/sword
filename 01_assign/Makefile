
CXX=g++
CXXFLAGS=-g -O0 -Wall -std=c++11

all: assign.o demo.o
	$(CXX) -o demo assign.o demo.o

assign.o: assign.cpp
	$(CXX) $(CXXFLAGS) -c assign.cpp

demo.o: demo.cpp
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	rm -rf *.o demo
