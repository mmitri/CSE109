all:
	gcc src/bin/argv.c -c
	gcc src/bin/multiply_ptrs.c -c
	gcc src/bin/question1test.c -c
	gcc src/bin/strlen.c -c
	gcc src/lib.c -c -I include
	gcc src/anotherlib.c -c -I include
	arc rc libmylib.a lib.o anotherlib.o
	mkdir -o build/bin
	mkdir build/objects
	mkdir build/lib
	mv *.o build/objects
	mv *.o build/lib
	my homework3 build/bin
install:
	mv build/bin/homework3 /usr/bin/homework3
clean:
	rm *.o
	rm *.a
	rm homework3
	rm -rf build