CFLAGS=-Wall
CC=gcc

pbfi : pbfi.c
	$(CC) $(CFLAGS) -o pbfi pbfi.c

hello : pbfi
	./pbfi bf/hello.bf

clean :
	rm -f pbfi
