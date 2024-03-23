#ifndef _DATA_
#define _DATA_

#include <stdio.h>
#include <stdlib.h>

int get_size();
double* get_vetor (int size);
void free_vetor (double* vetor);
void print_vetor (double* vetor, int size);
double** get_matriz (int size);
void free_matriz (double** matriz, int size);
void print_matriz (double** matriz, int size);
void read_sistema_linear (double** A, double* b, int size);

#endif