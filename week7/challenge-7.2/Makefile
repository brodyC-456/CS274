
.PHONY: all clean

all: main

main: main.o
	g++ -std=c++20 -Werror -Wextra -o $@ $^

main.o: main.cpp stack.h
	g++ -std=c++20 -Werror -Wextra -c $< -o $@

clean:
	rm -f main *.o
