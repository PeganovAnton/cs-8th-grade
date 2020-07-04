all: a.out

a.out: fraction.o main.o
	g++ fraction.o main.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

fraction.o: fraction.cpp
	g++ -c fraction.cpp

clean:
	rm *.o
