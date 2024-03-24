#include "data.h"
#include "metodos_numericos.h"

int main () {
    double **A;
    double *b, *x;

    int size = get_size();
    A = get_matriz(size);
    b = get_vetor(size);
    x = get_vetor(size);

    read_sistema_linear (A, b, size);

    print_vetor (b, size);
    print_matriz (A, size);
    retrossubs (A, b, x, size);

    printf ("\n");
    print_vetor (x, size);

    free_matriz (A, size);
    free_vetor (b);
    free_vetor (x);
}