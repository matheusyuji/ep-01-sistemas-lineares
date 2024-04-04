#include "sistLin.h"
#include "gauss.h"
#include "utils.h"
#include "gaussSeidel.h"

int main () {
    unsigned int size;
    while ((scanf ("%d", &size) == 1)) {
        double** A = get_matriz(size);
        double* b = get_vetor(size);
        int it = 0;

        read_sistema_linear(A, b, size);

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
        copy_matriz(ACopy, A, size);
        memcpy(bCopy, b, size*sizeof(double));
        residuo(ACopy, bCopy, x, r, size);
        
        print_result (x, r, time, it, "EG", size);

        // Gauss Seidel
        copy_matriz(ACopy, A, size);
        memcpy(bCopy, b, size*sizeof(double));
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));

        time = timestamp();
        it = gauss_seidel(A, b, x, size);
        time = timestamp() - time;

        copy_matriz(ACopy, A, size);
        memcpy(bCopy, b, size*sizeof(double));
        residuo(ACopy, bCopy, x, r, size);

        print_result (x, r, time, it, "GS", size);

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

        memcpy(aCopy, a, (size-1)*sizeof(double));
        memcpy(bCopy, b, size*sizeof(double));
        memcpy(cCopy, c, (size-1)*sizeof(double));
        memcpy(dCopy, d, size*sizeof(double));
    
        residuo_tridiagonal(aCopy, dCopy, cCopy, bCopy, x, r, size);
        
        print_result(x, r, time, it, "EG3", size);
        
        // GS Tridiagonal
        it = 0;
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));
        memcpy(aCopy, a, (size-1)*sizeof(double));
        memcpy(bCopy, b, size*sizeof(double));
        memcpy(cCopy, c, (size-1)*sizeof(double));
        memcpy(dCopy, d, size*sizeof(double));

        time = timestamp ();
        it = gauss_seidel_tridiagonal (d, a, c, b, x, size);
        time = timestamp () - time;

        memcpy(aCopy, a, (size-1)*sizeof(double));
        memcpy(bCopy, b, size*sizeof(double));
        memcpy(cCopy, c, (size-1)*sizeof(double));
        memcpy(dCopy, d, size*sizeof(double));
  
        residuo_tridiagonal(aCopy, dCopy, cCopy, bCopy, x, r, size);

        print_result(x, r, time, it, "GS3", size);

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