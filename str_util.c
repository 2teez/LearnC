// str_util.c
//
#include "str_util.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>


void str_title(char* str) {
    if (str[0] != '\0' && !isupper(str[0])) {
        str[0] = toupper(str[0]);
    }
    for (size_t i = 1; str[i] != '\0'; ++i) {
        if (str[i] == '\n') {  /* remove newline */
            str[i] = '\0';
        }
        str[i] = tolower(str[i]);
    }
}

char* trim(const char* nstr) {
    char* str = malloc(SIZE*sizeof(char));
    if (str == NULL) {
        perror("Memory can't be allocated.");
        exit(EXIT_FAILURE);
    }

    size_t count = 0;
    for (size_t i = 0; nstr[i] != '\0'; ++i) {
        if (isspace(nstr[i])) {
            continue;
        } else {
            str[count++] = nstr[i];
        }
    }
    str[count] = '\0';

    return str;
}
