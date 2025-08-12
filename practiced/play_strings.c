// play_strings.c

// A complete C Program
#include <malloc/_malloc_type.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/str_util.h"

#define SPACE ' '

char* get_first_word(void);
const char* my_strchr(const char* restrict, char);

int main(int argc, char** argv){

    //printf("{%s}\n", get_first_word());

    char* ans = my_strchr("C programmings", ' ');
    if (ans)
        printf("%p, %c", ans, *ans);

    return 0;
}

char* get_first_word(void){
    char nstr[SIZE] = {'\0'};
    int count = 0;
    printf("Enter a line: ");
    if (fgets(nstr, SIZE, stdin) == NULL) {
        perror("Bad input");
        exit(EXIT_FAILURE);
    }

    string str = malloc((SIZE+1)*sizeof(char));
    if (!str) {
        perror("Bad string");
        exit(EXIT_FAILURE);
    }

    do {
        if (count == 2 && nstr[count] == ' ') break;
        count++;
    }while(nstr[count] != ' ');
    strncpy(str, nstr, count);
    str[count] = '\0';
    return str;
}

const char* my_strchr(const char* restrict str, char ch) {
  while(*str != '\0' && *str != ch)
      str++;
  if (*str == ch) return str;
  return NULL;
}
