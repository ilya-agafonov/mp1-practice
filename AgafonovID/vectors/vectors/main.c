#include <stdio.h>
#include <locale.h>
#include "vector.h"

int main() {
    int n;
    double p;
    TVector v1, v2, s, dif;

    setlocale(LC_ALL, "Rus");

    printf("Длина v1: ");
    scanf("%d", &n);
    alloc(&v1, n);
    printf("Длина v2: ");
    scanf("%d", &n);
    alloc(&v2, n);
    fill(&v1);
    fill(&v2);
    s = sum(&v1, &v2);
    dif = subtraction(&v1, &v2);
    p = scalar_product(&v1, &v2);
    print(&s);
    print(&dif);
    printf("%.2lf", p);
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

void alloc(TVector* v, int n) {
    v->n = n;
    v->x = (double*)malloc(sizeof(double) * n);
}

void fill(TVector* v) {
    printf("Веедите координаты вектора: ");
    for (int i = 0; i < v->n; i++) {
        scanf("%lf", &(v->x[i]));
    }
}

void print(TVector* v) {
    for (int i = 0; i < v->n; i++) {
        printf("%.2lf ", (v->x[i]));
    }
    printf("\n");
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