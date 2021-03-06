# the compiler to use.
CC=gcc
# options I'll pass to the compiler.
CFLAGS=-c -Wall

all: tp0

tp0: main.o tp0.o
	$(CC) main.o tp0.o -o tp0

main.o: main.c
	$(CC) $(CFLAGS) main.c

tp0.o: tp0.c
	$(CC) $(CFLAGS) tp0.c
clean:
	rm -rf *o
