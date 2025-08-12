// space_counter.c

// A complete C Program
#include <stdio.h>

#define LINE_LENGTH 8

int main(int argc, char** argv){

    int counter = 0;
    printf("Enter character, Exit use '#': ");
    char ch;
    while((ch = getchar()) != '#') {
        if (0 == counter % LINE_LENGTH) {
            printf("\n");
            counter = 0;
        }
        printf("%c : %d, ", ch, (unsigned int)ch);
        counter++;
    }

    return 0;
}
