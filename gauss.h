#ifndef _GAUSS_
#define _GAUSS_

#include <math.h>

void retrossubs (double** A, double* b, double* x, unsigned int size);

void residuo (double** A, double* b, double* x, double* r, unsigned int size);

void eliminacao_gauss (double** A, double* b, unsigned int size);

void eliminacao_gauss_tridiagonal (double *d, double *a,
                                double *c, double *b, double *x, 
                                unsigned int size);

#endif