character_print: character_print.o
	gcc character_print.o -o character_print

character_print.o: character_print.c
	gcc -Wall -std=c17 -c character_print.c -o character_print.o

.PHONY: clean
clean:
	rm -f character_print character_print.o