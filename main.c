#include "data.h"
#include "gauss.h"
#include "utils.h"
#include "gauss_seidel.h"

int main () {
    /*double **A;
    double *b, *a, *c, *d, *x;
    int cont = 0;

    unsigned int size = get_size();
    A = get_matriz(size);
    b = get_vetor(size);
    a = get_vetor(size-1);
    c = get_vetor(size-1);
    d = get_vetor(size);

    x = get_vetor(size);
    x = zera_vetor (x, size);

    read_sistema_linear(A, b, size);
    vetor_triangular(A, a, c, d, size);
    double time = timestamp ();
    cont = gauss_seidel_tridiagonal (d, a, c, b, x, size);
    time = timestamp () - time;
    printf ("%lf\n", time);*/


    //print_vetor (x, size);
    //cont = gauss_seidel(A, b, x, size);

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

    //eliminacao_gauss (A, b, size);
    //retrossubs(A, b, x, size);
    //vetor_triangular(A, a, c, d, size);
    //eliminacao_gauss_tridiagonal(d, a, c, b, x, size);
    //print_vetor(d, size);
    //print_vetor(a, size-1);
    //print_vetor(c, size-1);

    /*
    printf("\n");
    print_vetor(x, size);
    printf ("\n");
    printf ("%d", cont);

    free_matriz(A, size);
    free_vetor(b);

    free_vetor(a);
    free_vetor(c);
    free_vetor(d);
    free_vetor(x);*/
  
    unsigned int size;
    while (!feof(stdin)) {
        scanf ("%d", &size);
        double** A = get_matriz(size);
        double* b = get_vetor(size);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size+1; j++) {
                if (j == size)
                    scanf ("%lf", &b[i]);
                else
                    scanf ("%lf", &A[i][j]);
        }

        
        print_matriz (A, size);
        print_vetor (b, size);
        printf("\n");


        double* x = get_vetor(size);
        double time = timestamp();
        eliminacao_gauss (A, b, size);
        retrossubs(A, b, x, size);
        time = timestamp () - time;

        print_vetor(x, size);
        printf ("%lf\n", time);
        printf("\n");

        free_matriz(A, size);
        free_vetor(b);
        free_vetor(x);
        size = 0;
    }
}