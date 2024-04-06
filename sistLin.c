// Matheus Yuji GRR20205104
#include "sistLin.h"

// Aloca um vetor de tamanho = size
double* get_vetor (unsigned int size) {
    double *vetor = (double *)malloc(size * sizeof(double));
    return vetor;
}

// Imprime o vetor
void print_vetor (double* vetor, unsigned int size) {
    for (int i = 0; i < size; i++)
        printf("%.12lf ", vetor[i]);
    printf ("\n");
    return;
}

// Aloca uma matriz de tamanho = size
double** get_matriz (unsigned int size) {
    double **matriz = (double **)malloc(size * sizeof(double*));
    for (int i = 0; i < size; i++)
        matriz[i] = (double *)malloc(size * sizeof(double));
    return matriz;
}

// Libera o espaço alocado para a matriz
void free_matriz (double** matriz, unsigned int size) {
    for (int i = 0; i < size; i++)
        free (matriz[i]);
    free (matriz);
    return;
}

// Printa a saída
void print_result (double* x, double* r, double time, int it, 
                    char nome[], unsigned int size)
{
    if (strcmp(nome,"EG") == 0) {
        printf("--------------------------------------------------------------------------------\n");
        printf("EG clássico:\n");
    }
    else if (strcmp (nome, "GS") == 0)
        printf("GS clássico [%d iterações]\n", it);
    else if (strcmp (nome, "EG3") == 0)
        printf ("EG 3-diagonal:\n");
    else 
        printf ("GS 3-diagonal [%d iterações]\n", it);
    
    printf ("%.8lf ms\n", time);
    print_vetor (x, size);
    print_vetor (r, size);
    printf("\n");
}

// Copia uma matriz
void copy_matriz (double** A, double** ACopy, unsigned int size) {
    for (int i = 0; i < size; i++) {
        memcpy(A[i], ACopy[i], size*sizeof(double));
    }
}

// Gera a matriz de coeficientes e vetor das constantes
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

// Transforma a matriz triangular em tres vetores a, c e d
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

// Faz a cópia dos vetores triangulares
void copy_triangular (double* d, double* dCopy, double* a, double* aCopy,
                        double* c, double* cCopy, unsigned int size)
{
    memcpy(d, dCopy, size*sizeof(double));
    memcpy(a, aCopy, (size-1)*sizeof(double));
    memcpy(c, cCopy, (size-1)*sizeof(double));
}