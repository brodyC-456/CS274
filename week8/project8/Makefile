.PHONY: all, clean


all: shapes

shapes: shapes.o
	g++ -std=c++20 -Wall -Wextra -o shapes shapes.o

shapes.o: shapes.cpp shapes.h
	g++ -std=c++20 -Wall -Wextra -c shapes.cpp -o shapes.o

clean:
	rm -f shapes shapes.o