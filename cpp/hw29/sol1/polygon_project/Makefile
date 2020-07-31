all: a.out

a.out: main.o polygon.o point.o
	g++ main.o polygon.o point.o -o a.out

%.o: source/%.cpp
	g++ -c -std=c++11 -I./include $<

clean:
	rm *.o
