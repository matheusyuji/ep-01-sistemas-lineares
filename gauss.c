#include "data.h"
#include "gauss.h"


void retrossubs (double** A, double* b, double* x, unsigned int size) {
    for (int i = size - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < size; ++j)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
}

// encontra o maior valor da coluna i
unsigned int encontra_max (double** A, int i, unsigned int size) {
    unsigned int iPivo = i;
    for (int j = i; j < size; j++) {
        if (fabs (A[j][i]) > fabs(A[iPivo][i]))
            iPivo = j;
    }
    return iPivo;
}

// troca a linha i pela iPivo da matriz A
void troca_linha (double** A, double* b, int i, 
                unsigned int iPivo, unsigned int size) 
{
    double aux;
    for (int j = 0; j < size; j++) {
        aux = A[i][j];
        A[i][j] = A[iPivo][j];
        A[iPivo][j] = aux;
    }
    aux = b[i];
    b[i] = b[iPivo];
    b[iPivo] = aux;

    return;
}

void mult_matriz (double** A, double* x, double* Ax, unsigned int size) {
    for (int i = 0; i < size; i++) {
        Ax[i] = 0.0;
        for (int j = 0; j < size; j++) {
            Ax[i] += A[i][j]*x[j];
        }
    }
}

void residuo (double** A, double* b, double* x, double* r, unsigned int size) {
    double* Ax = get_vetor(size);

    mult_matriz(A, x, Ax, size);
    
    for (int i = 0; i < size; i++) {
        r[i] = Ax[i] - b[i];
    }

    free(Ax);
}

void eliminacao_gauss (double** A, double* b, unsigned int size) {
    for (int i = 0; i < size; ++i) {
        unsigned int iPivo = encontra_max (A, i, size);
        if (i != iPivo) 
            troca_linha (A, b, i, iPivo, size);

        for (int k = i + 1; k < size; ++k) {
            //double m = A[k][i] / A[i][i];
            //A[k][i] = 0.0;
            for (int j = i + 1; j < size; ++j)
                A[k][j] = A[k][j]*A[i][i] - A[i][j] * A[k][i];
                //A[k][j] -= A[i][j] * m;
            b[k] = b[k]*A[i][i] - b[i]*A[k][i];
            //b[k] -= b[i] * m;
            A[k][i] = 0.0;
        }
    }
}

void eliminacao_gauss_tridiagonal (double *d, double *a,
                                double *c, double *b, double *x, 
                                unsigned int size) 
{
    for (int i = 0; i < size-1; ++i) {
        double m = a[i]/d[i];
        a[i] = 0.0;
        d[i+1] -= c[i]*m;
        b[i+1] -= b[i]*m;
    }

    x[size-1] = b[size-1]/d[size-1];
    for (int i = size-2; i>=0; --i)
        x[i] = (b[i] - c[i] * x[i+1])/d[i];
}