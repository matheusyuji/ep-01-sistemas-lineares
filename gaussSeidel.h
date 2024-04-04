#ifndef _GAUSS_SEIDEL_
#define _GAUSS_SEIDEL_

#include <math.h>
#include <string.h>

// Macro que retorna o maior valor entre a e b
#define MAX(a,b) (((a)>(b))?(a):(b))

// Número máximo de interações utilizado no gauss seidel
#define MAXIT 50

// Epsilon utilizado na condição de parada do gauss seidel
#define EPSILON 0.0001

int gauss_seidel (double** A, double* b, double*x,
                  unsigned int size);

int gauss_seidel_tridiagonal (double *d, double *a, double *c, 
                              double *b, double *x, unsigned int size);

void residuo_tridiagonal(double *a, double *d, double *c, double *b,
                            double *x, double *r, unsigned int size) ;
#endif