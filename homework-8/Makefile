# the compiler: gcc for C program, define as g++ for C++
CXX = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CXXFLAGS = -g -Wall

default: clean client

client: client.o
	$(CXX) $(CXXFLAGS) build/objects/release/client.o -o client -lboost_filesystem -lboost_system -std=c++11
	mkdir -p build/bin/release
	mv client build/bin/release

client.o:
	$(CXX) $(CXXFLAGS) src/bin/client.cpp -c -Iinclude -lboost_filesystem -lboost_system -std=c++11
	mkdir -p build/objects/release
	mv client.o build/objects/release

clean:
	rm -f *.a
	rm -f *.o
	rm -rf build

