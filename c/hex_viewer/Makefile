CC=gcc
CFLAGS=-Wall -g

all: clean main

main: main.c 
	$(CC) $(CFLAGS)  -o $@ $?
	./main

clean: 
	rm -rf *.o main