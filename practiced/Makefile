VPATH = ../includes ../src

play_strings: play_strings.o str_util.o
	gcc play_strings.o str_util.o -o play_strings

play_strings.o: play_strings.c str_util.h
	gcc -Wall -std=c17 -c play_strings.c -o play_strings.o

str_util.o: str_util.h str_util.c
	gcc -Wall -std=c17 -c -I../includes -I../src ../src/str_util.c -o str_util.o

.PHONY: clean
clean:
	rm -f play_strings *.o
