CC = g++


all: a.out

a.out: main.o foobar.o
	$(CC) main.o foobar.o

main.o: main.cpp
	$(CC) -c main.cpp

foobar.o: foobar.cpp
	$(CC) -c foobar.cpp

