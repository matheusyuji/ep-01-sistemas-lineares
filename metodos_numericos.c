#include "metodos_numericos.h"

void retrossubs (double** A, double* b, double* x, int size) {
    for (int i = size - 1; i >= 0; --i) {
        x[i] = b[i];
        for (int j = i + 1; j < size; ++j)
            x[i] -= A[i][j] * x[j];
        x[i] /= A[i][i];
    }
}

