#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    int n;
    double* x;
}TVector;

void read(const char* filename, TVector* v1, TVector* v2);
void write(const char* filename, TVector* s, TVector* dif, double* p);
void alloc(TVector* v, int n);
void print(TVector* v);
TVector sum(TVector* v1, TVector* v2);
TVector subtraction(TVector* v1, TVector* v2);
double scalar_product(TVector* v1, TVector* v2);

#endif