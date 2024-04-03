#include "data.h"
// aloca um vetor de tamanho = size
double* get_vetor (unsigned int size) {
    double *vetor = (double *)malloc(size * sizeof(double));
    return vetor;
}

// imprime o vetor
void print_vetor (double* vetor, unsigned int size) {
    for (int i = 0; i < size; i++)
        printf("%lf ", vetor[i]);
    printf ("\n");
    return;
}

// aloca uma matriz de tamanho = size
double** get_matriz (unsigned int size) {
    double **matriz = (double **)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++)
        matriz[i] = (double *)malloc(size * sizeof(double));
    return matriz;
}

// libera o espaço alocado para a matriz
void free_matriz (double** matriz, unsigned int size) {
    for (int i = 0; i < size; i++)
        free (matriz[i]);
    free (matriz);
    return;
}

// imprime a matriz
void print_matriz (double** matriz, unsigned int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%lf ", matriz[i][j]);
        printf("\n");
    }
    return;
}

// printa a saída
void print_result (double* x, double* r, double time, int cont, 
                    char nome[], unsigned int size)
{
    if (strcmp(nome,"EG") == 0) {
        printf("----------------------------------------------\n");
        printf("EG clássico:\n");
    }
    else if (strcmp (nome, "GS") == 0)
        printf("GS clássico [%d iterações]\n", cont);
    else if (strcmp (nome, "EG3") == 0)
        printf ("EG 3-diagonal:\n");
    else 
        printf ("GS 3-diagonal [%d iterações]\n", cont);
    
    printf ("%lf ms\n", time);
    print_vetor (x, size);
    print_vetor (r, size);
    printf("\n");
}

// copia uma matriz
void copy_matriz (double** ACopy, double** A, unsigned int size) {
    for (int i = 0; i < size; i++) {
        memcpy(ACopy[i], A[i], size*sizeof(double));
    }
}

// transforma a matriz triangular em tres vetores a, c e d
void vetor_triangular (double** A, double* a, double* c, 
                        double* d, unsigned int size) 
{
    for (int i = 0; i < size-1; i++) {
        d[i] = A[i][i];
        a[i] = A[i+1][i];
        c[i] = A[i][i+1];
    }

    d[size-1] = A[size-1][size-1];
    return;
}