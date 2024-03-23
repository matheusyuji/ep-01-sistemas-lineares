#include "data.h"

int main () {
    double **A;
    double *b;

    int size = get_size();
    A = get_matriz(size);
    b = get_vetor(size);

    read_sistema_linear (A, b, size);

    print_vetor (b, size);
    print_matriz (A, size);

    free_matriz (A, size);
    free_vetor (b);
}