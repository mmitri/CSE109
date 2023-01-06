all:
	gcc src/bin/main.c -o my_which
	gcc src/bin/main.c -c 
	gcc src/lib.c -c -I include
	gcc src/anotherlib.c -c -I include
	arc rs libmylib.a lib.o anotherlib.o
	gcc -o mybinary main.o -L. -lmylib
	mkdir -p build/bin
	mkdir build/objects
	mkdir build/lib
	mv *.o build/objects
	mv *.o build/lib
	mv mybinary build/bin

install:
	mv my_which /usr/bin
	mv build/bin/mybinary /usr/bin/mybinary

clean:
	rm *.o
	rm *.a
	rm mybinary
	rm -rf build
