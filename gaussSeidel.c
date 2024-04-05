#include "gaussSeidel.h"
#include "sistLin.h"

// Cálcula o resíduo de uma matriz tridiagonal
void residuo_tridiagonal(double *a, double *d, double *c, double *b,
                            double *x, double *r, unsigned int size) 
{
    // Multiplicação da matriz tridiagonal pelo vetor x
    r[0] = d[0] * x[0] + c[0] * x[1];
    for (int i = 1; i < size - 1; i++) {
        r[i] = a[i - 1] * x[i - 1] + d[i] * x[i] + c[i] * x[i + 1];
    }
    r[size - 1] = a[size - 2] * x[size - 2] + d[size - 1] * x[size - 1];

    // Subtração do vetor b do resultado da multiplicação
    for (int i = 0; i < size; i++) {
        r[i] -= b[i];
    }
}

double norma_maxima (double* x, double* xa, unsigned int size) {
    double aux, max = 0;
    for (int i = 0; i < size; i++) {
        aux = fabs(x[i]-xa[i]);
        max = MAX(max,aux);
    }
    return max;
}

// Realiza o gauss seidel
int gauss_seidel (double** A, double* b, double*x,
                  unsigned int size)
{
    double erro = 1.0 + EPSILON;
    int j , cont = 0;
    double *xa = get_vetor(size); 
   
    while ((erro > EPSILON) && (cont < MAXIT)) {
        cont = cont + 1;
        memcpy (xa, x, size * sizeof(double));
       
        for (int i = 0; i < size; ++i) {
            double sum = 0.0;
            for (j = 0; j < size; ++j) {
                if (i != j) {
                    sum+= A[i][j]*x[j];
                }
            }
              
        x[i] = (b[i] - sum)/A[i][i];
        }
        erro = norma_maxima(x, xa, size);
    }

    free(xa);
    return cont;
}

// Realiza o gauss seidel tridiagonal
int gauss_seidel_tridiagonal (double *d, double *a, double *c, 
                              double *b, double *x, unsigned int size)
{
    double erro = 1.0 + EPSILON;
    int cont = 0;
    double *xa = get_vetor(size);

    while ((erro > EPSILON) && (cont < MAXIT)) {
        cont = cont + 1;
        memcpy (xa, x, size * sizeof(double));

        x[0] = (b[0]-c[0]*x[1])/d[0];

        for (int i = 1; i < size-1; ++i) {
            x[i] = (b[i]-a[i-1]*x[i-1]-c[i]*x[i+1])/d[i];
        }
        x[size-1] = (b[size-1]-a[size-2]*x[size-2])/d[size-1];
        erro = norma_maxima(x, xa, size);
    }
    
    free(xa);
    return cont;
}