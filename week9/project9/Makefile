.PHONY: all clean pristine

all: llisttest

llisttest: llisttest.cpp llist.o
	g++ -std=c++20 -Werror -Wextra -o $@ $^

llist.o: llist.cpp llist.h
	g++ -std=c++20 -Wall -Wextra -c $< -o $@

clean:
	rm -rf *.o

pristine:
	rm -rf llisttest *.o

