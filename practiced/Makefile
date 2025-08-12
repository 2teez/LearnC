VPATH = ../includes ../src

play_strings: play_strings.o str_util.o
	clang -fsanitize=address play_strings.o str_util.o -o play_strings

play_strings.o: play_strings.c str_util.h
	clang -Wall -std=c17 -fsanitize=address -g -c play_strings.c -o play_strings.o

str_util.o: str_util.h str_util.c
	clang -Wall -std=c17 -fsanitize=address -c -I../includes -I../src ../src/str_util.c -o str_util.o

.PHONY: clean
clean:
	rm -f play_strings *.o
