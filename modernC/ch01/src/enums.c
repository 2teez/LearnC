/* enums.c */

/* A complete C Program */
#include <stdio.h>
#include <stdlib.h>

typedef enum langs { c, cpp, python, java, js, langs_num } langs;

int main(int argc, char **argv) {

  char const *const lang_names[langs_num] = {[c] = "C",
                                             [cpp] = "C++",
                                             [python] = "Python",
                                             [java] = "Java",
                                             [js] = "JavaScript"};
  for (size_t i = 0; i < langs_num; i++) {
    printf("%s\n", lang_names[i]);
  }

  langs preferred = python;
  printf("Preferred language: %s\n", lang_names[preferred]);

  return EXIT_SUCCESS;
}
