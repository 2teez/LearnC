funpointer: funpointer.o
	gcc funpointer.o -o funpointer

funpointer.o: funpointer.c
	gcc -Wall -std=c17 -c funpointer.c -o funpointer.o

run:
	./funpointer

.PHONY: clean
clean:
	rm -f funpointer *.o
