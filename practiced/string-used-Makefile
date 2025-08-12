VPATH = ../src ../includes

string-used-case: string-used-case.o str_util.o
	gcc string-used-case.o str_util.o -o string-used-case

string-used-case.o: string-used-case.c str_util.h
	gcc -Wall -std=c17 -c string-used-case.c -o string-used-case.o

str_util.o: str_util.c str_util.h
	gcc -Wall -std=c17 -I../src -I../includes -c ../src/str_util.c -o str_util.o

.PHONY: clean
clean:
	rm -f string-used-case string-used-case.o str_util.o
