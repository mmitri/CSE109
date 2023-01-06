all:
	mkdir build/bin -p
	mkdir build/lib -p
	mkdir build/objects -p
	gcc src/lib.c -c
	ar rs -o libmylib.a lib.o
	gcc src/bin/main.c -lmylib -L. -I include -o my_which
	mv my_which build/bin/my_which
	mv lib.o build/objects/lib.o
	mv libmylib.a build/lib/libmylib.a

install:
	mv build/bin/my_which /usr/bin/my_which

clean:
	rm -rf build
