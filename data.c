#include "data.h"

// retorna o tamanho da matriz
unsigned int get_size () {
    unsigned int size;
    scanf ("%d", &size);
    return size;
}

// aloca um vetor de tamanho = size
double* get_vetor (unsigned int size) {
    double *vetor = (double *)malloc(size * sizeof(double));
    return vetor;
}

// libera o espaço alocado para o vetor
void free_vetor (double* vetor) {
    free (vetor);
    return;
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

// gera a matriz de coeficientes e vetor das constantes
void read_sistema_linear (double** A, double* b, unsigned int size) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size+1; j++) {
            if (j == size)
                scanf ("%lf", &b[i]);
            else
                scanf ("%lf", &A[i][j]);
        }
    return;
}