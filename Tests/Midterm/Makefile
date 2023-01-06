static:
	gcc -c libmyls.c
	ar rs libmyls.a libmyls.o
	mkdir -p build/lib
	mv *.a build/lib
shared:
	gcc -c -fpic libmyls.c
	gcc -shared -o libmyls.so libmyls.o
	mv *.so build/lib
bin:
	gcc --static -I../include -L../lib -o main main.c -llprprint
	mkdir -p build/objects
	mkdir -p build/lib
	mkdir -p build/bin
	mv *.exe build/bin
	mv *.c build/bin
	mv *.a build/lib
	mv *.l build/lib
	mv *.o build/objects
all:
	main
clean:
	rm -rf build
install:
	mkdir -p /usr/lib
	mv *.so /usr/lib
