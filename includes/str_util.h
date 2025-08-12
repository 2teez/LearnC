#ifndef __STR_UTIL__
#define __STR_UTIL__
#
#define SIZE 256

typedef char* string;

void str_title(char*);
char* trim(const char*);
char* lstrip(const char*);
char* rstrip(const char*);
char* strip(const char*);
char* input(const char*);

#endif  /* __STR_UTIL__ */
