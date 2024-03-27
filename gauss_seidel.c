#include "gauss_seidel.h"
#include "data.h"

double norma_maxima (double* x, double* xa, unsigned int size) {
    double aux, max = 0;
    for (int i = 0; i < size; i++) {
        aux = fabs(x[i]-xa[i]);
        max = MAX(max,aux);
    }
    return max;
}

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
            for (j=0; j < size; ++j) {
                if (i != j) {
                    sum+= A[i][j]*x[j];
                }
            }
              
        x[i] = (b[i] - sum)/A[i][i];
        }
        erro = norma_maxima(x, xa, size);
    }
   
    return cont;
}