// name_place.c

// A complete C Program
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 256

char* get_name(const char*);
void str_title(char*);

int main(int argc, char** argv){

    char *first_name = get_name("Enter your first name: ");
    char *last_name = get_name("Enter your last name: ");

    str_title(first_name);
    str_title(last_name);

    printf("%s %s\n", first_name, last_name);
    printf("%*ld %*ld\n", (int)strlen(first_name), strlen(first_name),
        (int)strlen(first_name), strlen(last_name));

    free(first_name);
    free(last_name);

    return 0;
}

char* get_name(const char* msg) {
    char* name = malloc(sizeof(char)* SIZE);
    printf("%s ", msg);
    scanf("%s", name); /* get name from stdin */

    return name;
}

void str_title(char* str) {
    if (str[0] != '\0' && !isupper(str[0])) {
        str[0] = toupper(str[0]);
    }
}
