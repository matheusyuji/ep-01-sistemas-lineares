#ifndef _GAUSS_SEIDEL_
#define _GAUSS_SEIDEL_

#include <math.h>
#include <string.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAXIT 50
#define TOL 0.0001

int gauss_seidel (double** A, double* b, double*x,
                  unsigned int size, double tol);

#endif