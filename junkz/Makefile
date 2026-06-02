linkedlist: linkedlist.o
	gcc linkedlist.o -o linkedlist

linkedlist.o: linkedlist.c
	gcc -Wall -std=c17 -c linkedlist.c -o linkedlist.o

run:
	 ./linkedlist

.PHONY: clean
clean:
	rm -f linkedlist *.o