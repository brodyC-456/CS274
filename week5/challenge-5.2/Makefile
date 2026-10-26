.PHONY: all clean

all: main

main: main.o mather.o boxer.o
	gcc -o main $^

main.o: main.c
	gcc -Wall -Wextra -c -o $@ $<

mather.o: mather.c mather.h
	gcc -Wall -Wextra -c -o $@ $<


boxer.o: boxer.c boxer.h
	gcc -Wall -Wextra -c -o $@ $<

clean:
	rm -f *.o