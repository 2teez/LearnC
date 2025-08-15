#ifndef __PLAYSTRUCT__
#define __PLAYSTRUCT__
#

typedef struct complex *Complex;

Complex new_cmplx(double, double);
Complex new_cmplx_default(void);
void print_cmplx(Complex);
void free_cmplx(Complex);

#endif  /* __PLAYSTRUCT__ */
