.PHONY: all clean

all: rpncalc

rpncalc: rpncalc.o stack.o
	gcc -o main $^

rpncalc.o: rpncalc.c
	gcc -Wall -Wextra -c -o $@ $<

stack.o: stack.c stack.h
	gcc -Wall -Wextra -c -o $@ $<

clean:
	rm -f *.o