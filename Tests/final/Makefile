# the compiler: gcc for C program, define as g++ for C++
CXX = g++
 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CXXFLAGS = -g -Wall

default: clean server

server: server.o
	$(CXX) $(CXXFLAGS) build/objects/release/server.o -o server -std=c++11
	mkdir -p build/bin/release
	mv server build/bin/release

server.o:
	$(CXX) $(CXXFLAGS) src/bin/server.cpp -c -Iinclude -std=c++11
	mkdir -p build/objects/release
	mv server.o build/objects/release

clean:
	rm -f *.a
	rm -f *.o
	rm -rf build