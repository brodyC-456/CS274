.PHONY: all clean pristine

all: runprog

runprog: runprog.o cpu.o
	g++ -std=c++20 -Werror -Wextra -o $@ $^

runprog.o: runprog.cpp cpu.h
	g++ -std=c++20 -Werror -Wextra -c $< -o $@
cpu.o: cpu.cpp cpu.h stack.h
	g++ -std=c++20 -Werror -Wextra -c $< -o $@

clean:
	rm -f *.o
pristine: 
	rm -f runprog *.o
