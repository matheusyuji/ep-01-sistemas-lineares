#ifndef _DATA_
#define _DATA_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double* get_vetor (unsigned int size);

void print_vetor (double* vetor, unsigned int size);

double** get_matriz (unsigned int size);

void free_matriz (double** matriz, unsigned int size);

void print_matriz (double** matriz, unsigned int size);

void print_result (double* x, double* r, double time, int cont, 
                    char nome[], unsigned int size);

void copy_matriz (double** ACopy, double** A, unsigned int size);

void vetor_triangular (double** A, double* a, double* c, 
                        double* d, unsigned int size); 

#endif