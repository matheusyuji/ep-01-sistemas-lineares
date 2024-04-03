#include "data.h"
#include "gauss.h"
#include "utils.h"
#include "gauss_seidel.h"

int main () {
    unsigned int size;
    while ((scanf ("%d", &size) == 1)) {
        double** A = get_matriz(size);
        double* b = get_vetor(size);
        int cont = 0;

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size+1; j++) {
                if (j == size)
                    scanf ("%lf", &b[i]);
                else
                    scanf ("%lf", &A[i][j]);
        }

        // Eliminaçao de Gauss
        double** ACopy = get_matriz(size);
        double* bCopy = get_vetor(size);
        double* x = get_vetor(size);

        copy_matriz(ACopy, A, size);
        memcpy(bCopy, b, size*sizeof(double));
     
        double time = timestamp();
        eliminacao_gauss (ACopy, bCopy, size);
        retrossubs(ACopy, bCopy, x, size);
        time = timestamp () - time;

        double* r = get_vetor(size);
        residuo(ACopy, bCopy, x, r, size);
        
        print_result (x, r, time, cont, "EG", size);

        // Gauss Seidel
        copy_matriz(ACopy, A, size);
        memcpy(bCopy, b, size*sizeof(double));
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));

        time = timestamp();
        cont = gauss_seidel(A, b, x, size);
        time = timestamp() - time;
        residuo(ACopy, bCopy, x, r, size);

        print_result (x, r, time, cont, "GS", size);

        free_matriz(ACopy, size);

        // EG Tridiagonal
        double* a = get_vetor(size-1);
        double* c = get_vetor(size-1);
        double* d = get_vetor(size);

        vetor_triangular(A, a, c, d, size);
        free_matriz(A, size);

        double* aCopy = get_vetor(size-1);
        double* cCopy = get_vetor(size-1);
        double* dCopy = get_vetor(size);
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));

        memcpy(aCopy, a, (size-1)*sizeof(double));
        memcpy(bCopy, b, size*sizeof(double));
        memcpy(cCopy, c, (size-1)*sizeof(double));
        memcpy(dCopy, d, size*sizeof(double));

        time = timestamp();
        eliminacao_gauss_tridiagonal (dCopy, aCopy, cCopy, bCopy, x, size);
        time = timestamp() - time;
    

        print_result(x, r, time, cont, "EG3", size);
        
        // GS Tridiagonal
        cont = 0;
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));
        memcpy(aCopy, a, (size-1)*sizeof(double));
        memcpy(bCopy, b, size*sizeof(double));
        memcpy(cCopy, c, (size-1)*sizeof(double));
        memcpy(dCopy, d, size*sizeof(double));

        time = timestamp ();
        cont = gauss_seidel_tridiagonal (d, a, c, b, x, size);
        time = timestamp () - time;

        print_result(x, r, time, cont, "GS3", size);

        free(a);
        free(aCopy);
        free(b);
        free(bCopy);
        free(c);
        free(cCopy);
        free(d);
        free(dCopy);
        free(x);
        free(r);   
    }
}