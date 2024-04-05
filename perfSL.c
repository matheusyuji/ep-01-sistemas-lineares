#include "sistLin.h"
#include "gauss.h"
#include "utils.h"
#include "gaussSeidel.h"

int main () {
    unsigned int size;
    while ((scanf ("%d", &size) == 1)) {
        
        // Cria cópia de vetores
        double** ACopy = get_matriz(size);
        double* bCopy = get_vetor(size);
        int it = 0;

        // Lê da entrada o sistema linear
        read_sistema_linear(ACopy, bCopy, size);

        double** A = get_matriz(size);
        double* b = get_vetor(size);
        double* x = get_vetor(size);

        // Copia o sistema linear para A e b
        copy_matriz(A, ACopy, size);
        memcpy(b, bCopy, size*sizeof(double));
     
        // Eliminação de Gauss
        double time = timestamp();
        eliminacao_gauss (A, b, size);
        retrossubs(A, b, x, size);
        time = timestamp () - time;

        double* r = get_vetor(size);
        // Faz uma cópia do sistema linear para calcular resíduo
        copy_matriz(A, ACopy, size);
        memcpy(b, bCopy, size*sizeof(double));
        residuo(A, b, x, r, size);
        
        print_result (x, r, time, it, "EG", size);

         
        copy_matriz(A, ACopy, size);
        memcpy(b, bCopy, size*sizeof(double));
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));

        // Gauss Seidel
        time = timestamp();
        it = gauss_seidel(A, b, x, size);
        time = timestamp() - time;

        copy_matriz(A, ACopy, size);
          
        memcpy(b, bCopy, size*sizeof(double));
        residuo(A, b, x, r, size);

        print_result (x, r, time, it, "GS", size);


        free_matriz(A, size);
        double* aCopy = get_vetor(size-1);
        double* cCopy = get_vetor(size-1);
        double* dCopy = get_vetor(size);

        // Coloca o sistema linear nos vetores d,a e c
        vetor_triangular(ACopy, aCopy, cCopy, dCopy, size);
        free_matriz(ACopy, size);

        double* a = get_vetor(size-1);
        double* c = get_vetor(size-1);
        double* d = get_vetor(size);
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));

        // Faz uma cópia dos vetores triangulares
        copy_triangular(d, dCopy, a, aCopy, c, cCopy, size);    
        memcpy(b, bCopy, size*sizeof(double));
        

        // Eliminação de Gauss Tridiagonal
        time = timestamp();
        eliminacao_gauss_tridiagonal (d, a, c, b, x, size);
        time = timestamp() - time;

        copy_triangular(d, dCopy, a, aCopy, c, cCopy, size);
        memcpy(b, bCopy, size*sizeof(double));
     
        residuo_tridiagonal(a, d, c, b, x, r, size);
        
        print_result(x, r, time, it, "EG3", size);
        
        
        it = 0;
        memset(x, 0, size*sizeof(*x));
        memset(r, 0, size*sizeof(*r));
     
        memcpy(b, bCopy, size*sizeof(double));
        copy_triangular(d, dCopy, a, aCopy, c, cCopy, size);
       
        // Gauss Seidel Tridiagonal
        time = timestamp ();
        it = gauss_seidel_tridiagonal (d, a, c, b, x, size);
        time = timestamp () - time;

        memcpy(b, bCopy, size*sizeof(double));
        copy_triangular(d, dCopy, a, aCopy, c, cCopy, size);
              
        residuo_tridiagonal(a, d, c, b, x, r, size);

        print_result(x, r, time, it, "GS3", size);

        free(a); free(aCopy);
        free(b); free(bCopy);
        free(c); free(cCopy);
        free(d); free(dCopy);
        free(x); free(r);   
    }
}