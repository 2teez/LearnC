// strings.c

// A complete C Program
#include <stdio.h>
#include "../str_util.h"

int main(int argc, char** argv){

    printf("[%s]\n", trim(" hello, world!    "));
    printf("[%s]\n", lstrip("       hello, world!    "));
    printf("[%s]\n", rstrip(" hello, world!    "));
    return 0;
}
