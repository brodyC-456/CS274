.PHONY: all clean

all: main

main: main.o llist.o
	gcc -o main $^

main.o: main.c
	gcc -Wall -Wextra -c -o $@ $<

llist.o: llist.c llist.h
	gcc -Wall -Wextra -c -o $@ $<

clean:
	rm -f *.o