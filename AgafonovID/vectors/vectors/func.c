#include "vector.h"

void read(const char* filename, TVector* v1, TVector* v2) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Файл не найден");
        exit(1);
    }
    fscanf(file, " %d \n", &(v1->n));
    v1->x = (double*)malloc(sizeof(double) * v1->n);
    for (int i = 0; i < v1->n; i++) {
        fscanf(file, "%lf ", &(v1->x[i]));
    }
    fscanf(file, " %d \n", &(v2->n));
    v2->x = (double*)malloc(sizeof(double) * v2->n);
    for (int i = 0; i < v2->n; i++) {
        fscanf(file, "%lf ", &(v2->x[i]));
    }
    fclose(file);
}

void write(const char* filename, TVector* s, TVector* dif, double* p) {
    FILE* file = fopen(filename, "w+");
    if (file == NULL) {
        printf("Файл не найденw");
        exit(1);
    }
    fprintf(file, "sum = ");
    for (int i = 0; i < s->n; i++) {
        fprintf(file, "%.2lf ", s->x[i]);
    }
    fprintf(file, "\ndif = ");
    for (int i = 0; i < dif->n; i++) {
        fprintf(file, "%.2lf ", dif->x[i]);
    }
    fprintf(file, "\np = %.2lf", *p);
    fclose(file);
}

void print(TVector* v) {
    for (int i = 0; i < v->n; i++) {
        printf("%.2lf ", (v->x[i]));
    }
    printf("\n");
}

void alloc(TVector* v, int n) {
    v->n = n;
    v->x = (double*)malloc(sizeof(double) * n);
}

TVector sum(TVector* v1, TVector* v2) {
    if (v1->n != v2->n) {
        printf("Длины векторов разные");
        exit(0);
    }
    TVector v3;
    alloc(&v3, v1->n);
    for (int i = 0; i < v3.n; i++) {
        v3.x[i] = v1->x[i] + v2->x[i];
    }
    return v3;
}

TVector subtraction(TVector* v1, TVector* v2) {
    if (v1->n != v2->n) {
        printf("Длины векторов разные");
        exit(0);
    }
    TVector v3;
    alloc(&v3, v1->n);
    for (int i = 0; i < v3.n; i++) {
        v3.x[i] = v1->x[i] - v2->x[i];
    }
    return v3;
}

double scalar_product(TVector* v1, TVector* v2) {
    if (v1->n != v2->n) {
        printf("Длины векторов разные");
        exit(0);
    }
    double res = 0;
    for (int i = 0; i < v1->n; i++) {
        res += v1->x[i] * v2->x[i];
    }
    return res;
}