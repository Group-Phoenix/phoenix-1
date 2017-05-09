.PHONY: all

all: clean Circle.a
	g++ -std=c++1y -o main.o -c main.cpp -Wall -O `pkg-config --cflags --libs opencv` -I.
	g++ -o main main.o `pkg-config --cflags --libs opencv` -L. -lCircle

Circle.a:
	g++ -std=c++1y -Wall -c Circle.cpp -o Circle.o
	ar rcs libCircle.a Circle.o

clean:
	rm -f *.o main
