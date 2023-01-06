default: client server

client: src/bin/client.c
	gcc src/bin/client.c -o client
	mkdir -p build/bin/release
	mv client build/bin/release

server: src/bin/server.c
	gcc src/bin/server.c -o server
	mkdir -p build/bin/release
	mv server build/bin/release

clean:
	rm -f *.a
	rm -f *.o
	rm -rf build