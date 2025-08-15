// cseeker.c

// A complete C Program
#include <stdio.h>
#include <stdlib.h>
#include "../includes/str_util.h"

int main(int argc, char** argv){

    string filename = input("Enter a filename: ");
    FILE *fh;

    fh = fopen(filename, "r");
    if (!fh) {
        perror("Invalid File.");
        exit(EXIT_FAILURE);
    }

    fseek(fh, 0L, SEEK_END);
    long last = ftell(fh);
    for(long count = 1L; count <= last; count++) {
        fseek(fh, -count, SEEK_END);
        //int ch = getc(fh);
        putc(getc(fh), stdout);
    }
    fclose(fh);
    return 0;
}
