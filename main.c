#include "data.h"
#include "metodos_numericos.h"

int main () {
    double **A;
    double *b, *x;

    unsigned int size = get_size();
    A = get_matriz(size);
    b = get_vetor(size);
    x = get_vetor(size);

    read_sistema_linear(A, b, size);

    //print_vetor(b, size);
    //print_matriz(A, size);
    /*
    unsigned int i = encontra_max (A, 0, size);
    printf("%d\n", i);
    i = encontra_max (A, 1, size);
    printf("%d\n", i);
    i = encontra_max (A, 2, size);
    printf("%d\n", i);
    */

    eliminacao_gauss (A, b, size);
    retrossubs(A, b, x, size);
  

    printf("\n");
    print_vetor(x, size);

    free_matriz(A, size);
    free_vetor(b);
    free_vetor(x);
}