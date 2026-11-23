.PHONY: all, clean


all: main

main: holder.o
	g++ -std=c++20 -Wall -Wextra -o main holder.o

holder.o: main.cpp holder.h
	g++ -std=c++20 -Wall -Wextra -c main.cpp -o holder.o

clean:
	rm -f main animals.o