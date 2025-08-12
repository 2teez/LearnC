hello: hello.o
	gcc hello.o -o hello

hello.o: hello.c
	gcc -Wall -std=c17 -c hello.c -o hello.o

.PHONY: clean
clean:
	rm -f hello hello.o