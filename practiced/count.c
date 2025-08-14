// count.c
// A complete C Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81

int main(int argc, char** argv){

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = malloc(SIZE*sizeof(char));
   if (filename == NULL) {
       perror("Invalid memory allocation.");
       exit(EXIT_FAILURE);
   }
   strncpy(filename, argv[1], SIZE+1);
   //while(*filename++ == '\n')*filename = '\0';

    FILE *fh = fopen(filename, "r");
    if (fh == NULL) {
        perror("invalid filename");
        exit(EXIT_FAILURE);
    }

    unsigned long count = 0; // count each character
    int ch;
    while((ch = getc(fh)) != EOF) {
        putchar(ch);
        count++;
    }

    printf("%ld\n", count);

    return 0;
}
