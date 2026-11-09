
.PHONY: all clean

all: main

main: main.o printcounter.o
	g++ -std=c++20 -Werror -Wextra -o $@ $^

main.o: main.cpp
	g++ -std=c++20 -Werror -Wextra -c $< -o $@

printcounter.o: printcounter.cpp printcounter.h
	g++ -std=c++20 -Werror -Wextra -c $< -o $@

clean:
	rm -f main *.o
