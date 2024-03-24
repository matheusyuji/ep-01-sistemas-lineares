#include "metodos_numericos.h"

void retrossubs (double** A, double* b, double* x, unsigned int size) {
    for (int i = size - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < size; ++j)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
}

unsigned int encontra_max (double** A, int i, unsigned int size) {
    unsigned int iPivo = i;
    for (int j = i; j < size; j++) {
        if (fabs (A[j][i]) > fabs(A[iPivo][i]))
            iPivo = j;
    }
    return iPivo;
}

void troca_linha (double** A, double* b, int i, unsigned int iPivo, unsigned int size) {
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