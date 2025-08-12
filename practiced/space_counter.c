// space_counter.c

// A complete C Program
#include <stdio.h>

int main(int argc, char** argv){

    int space_counter = 0;
    int newline_counter = 0;
    int other_character = 0;

    char ch;
    while((ch = getchar()) != '#') {
        switch (ch) {
            case ' ':
                space_counter++;
                break;
            case '\n':
                newline_counter++;
                break;
            default:
                other_character++;
        }
    }

    printf("Space Character: %d,"
        " New Line Character: %d and Other Character: %d",
        space_counter, newline_counter, other_character);

    return 0;
}
