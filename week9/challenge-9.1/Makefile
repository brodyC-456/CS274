.PHONY: all, clean


all: main

main: animals.o
	g++ -std=c++20 -Wall -Wextra -o main animals.o

animals.o: main.cpp animals.h
	g++ -std=c++20 -Wall -Wextra -c main.cpp -o animals.o

clean:
	rm -f main animals.o