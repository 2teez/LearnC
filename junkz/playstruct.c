// playstruct.c

// A complete C Program
#include <stdio.h>
#include <stdlib.h>
#include "playstruct.h"

typedef struct complex {
    double real;
    double imag;
} *Complex;

Complex new_cmplx(double real, double imag) {
    Complex cmplx = malloc(sizeof(struct complex));
    if (!cmplx) {
        perror("Insufficient Memory Allocation.");
        exit(EXIT_FAILURE);
    }
    cmplx->real = real;
    cmplx->imag = imag;
    return cmplx;
}

Complex new_cmplx_default() {
    return new_cmplx(0.0, 0.0);
}

void print_cmplx(Complex cmplx) {
    printf("Complex(real: %.2f, imag: %.2fi)\n", cmplx->real, cmplx->imag);
}

void free_cmplx(Complex cmplx) {
    free(cmplx);
}
