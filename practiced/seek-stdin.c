// seek-stdin.c

// A complete C Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 81

static char* get_input(const char*);
static void reverse_string(char*);

int main(int argc, char** argv){

    char* input = get_input("Enter a sentence: ");
    reverse_string(input);

    free(input);
}

void reverse_string(char* str) {
    for(size_t idx = strlen(str)-1; idx > 0; idx--)
        putc(str[idx], stdout);
    putchar(str[0]);
    printf("");
}

char* get_input(const char* msg) {
    fprintf(stdout, "%s", msg);
    char* line = malloc((SIZE+1)*sizeof(char));
    if (!line) {
        perror("Memory allocation failure.");
        exit(EXIT_FAILURE);
    }
    char* input = fgets(line, SIZE, stdin);
    if (!input) {
        perror("Invalid Input");
        exit(EXIT_FAILURE);
    }
    line[SIZE] = '\0';
    return line;
}
