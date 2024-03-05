#include <stdio.h>
#include <locale.h>
#include "vector.h"

int main(int argc, char** argv) {
    int n;
    double p;
    TVector v1, v2, s, dif;
    char* infilename, *outfilename;

    setlocale(LC_ALL, "Rus");

    if (argc < 4) {
        printf("Неверные аргументы\n");
        return 1;
    }
    n = atoi(argv[1]);
    printf("n = %d\n", n);
    infilename = argv[2];
    printf("in file name: %s\n", infilename);
    outfilename = argv[3];
    printf("out file name: %s\n", outfilename);
    read(infilename, &v1, &v2);
    s = sum(&v1, &v2);
    dif = subtraction(&v1, &v2);
    p = scalar_product(&v1, &v2);
    write(outfilename, &s, &dif, &p);
    if (s.x != NULL) {
        free(s.x);
    }
    if (dif.x != NULL) {
        free(dif.x);
    }
    free(v1.x);
    free(v2.x);
    return 0;
}

void read(const char* filename, TVector* v1, TVector* v2) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Файл не найден");
        exit(1);
    }
    fscanf(file, " %d ", &(v1->n));
    v1->x = (double*)malloc(sizeof(double) * v1->n);
    for (int i = 0; i < v1->n; i++) {
        fscanf(file, "%lf ", &(v1->x[i]));
    }
    fscanf(file, " %d ", &(v2->n));
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
        exit(1) ;
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