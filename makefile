CC=gcc

CFLAGS=-g -Wall -pedantic -D_GNU_SOURCE=1 -D_REENTRANT
#CFLAGS=-g -Wall -D_REENTRANT
MATH_FLAGS=-lm
SOURCES=main.c funcoes.c globais.c
OBJECTS=main.o funcoes.o globais.o
BINARIES=main

all: $(BINARIES)

main: main.o funcoes.o 
	$(CC) -o main main.o funcoes.o

main.o: main.c 
	$(CC) -c main.c $(CFLAGS) $(MATH_FLAGS)

funcoes.o: funcoes.c interfaces/funcoes.h
	$(CC) -c funcoes.c $(CFLAGS)	
	
clean:
	rm -rf *.o *.exe *.bak *.c~ $(BINARIES) core a.out

limpa:
	del *.o *.exe *.bak *.c~ $(BINARIES) core

