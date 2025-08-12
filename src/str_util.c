// str_util.c
//
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../includes/str_util.h"

static char* make_string() {
    char* str = malloc(SIZE*sizeof(char));
    if (str == NULL) {
        perror("Memory can't be allocated.");
        exit(EXIT_FAILURE);
    }
    return str;
}

static char* make_sizable_string(const char* string) {
    char* str = malloc((strlen(string)+1)*sizeof(char));
    if (str == NULL) {
        perror("Memory can't be allocated.");
        exit(EXIT_FAILURE);
    }
    return str;
}


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
    char* str = make_string();
    size_t count = 0;
    for (size_t i = 0; nstr[i] != '\0'; ++i) {
        if (isspace((unsigned char)nstr[i])) {
            continue;
        } else {
            str[count++] = nstr[i];
        }
    }
    str[count] = '\0';

    return str;
}

char* lstrip(const char* str) {
    while(isspace((unsigned char)*str)){str++;}
    char* nstr = make_sizable_string(str);
    memcpy(nstr, str, strlen(str)+1);
    return nstr;
}

char* rstrip(const char* str) {
    size_t idx = strlen(str);
    while(idx > 0 && isspace((unsigned char)str[idx-1])) {
        idx--;
    }

    char* nstr = make_sizable_string(str);
    memcpy(nstr, str, idx);
    nstr[idx] = '\0';
    return nstr;
}

char* strip(const char* str) {
    return rstrip(lstrip(str));
}

char* input(const char* msg) {
    printf("%s", msg);
    char *result = make_string();
    int ch;
    int counter = 0;
    while((ch = getchar()) != '\n' && ch != EOF) {
        if (counter > SIZE -1) {
            char *temp = realloc(result, SIZE * 2);
            if (!temp) {
                perror("Can't re-allocate a bigger memory for input.");
                exit(EXIT_FAILURE);
            }
            result = temp;
        }
        result[counter++] = (char)ch;
    }
    result[counter] = '\0';
    return result;
}
