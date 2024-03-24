#ifndef _NUMERICOS_
#define _NUMERICOS_

#include <math.h>

void retrossubs (double** A, double* b, double* x, unsigned int size);
void eliminacao_gauss (double** A, double* b, unsigned int size);

#endif