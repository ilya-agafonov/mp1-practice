#include <stdio.h>
#include <locale.h>

typedef struct {
    int n;
    double* x;
}TVector;

void alloc(TVector* V, int n);

void fill(TVector* V);

TVector sum(TVector* V1, TVector* V2);

TVector diference(TVector* V1, TVector* V2);

int main() {
    int n; 
    TVector V1, V2, s;

    setlocale(LC_ALL, "Rus");

    printf("Длина вектора V1 = ");
    scanf("%d", &n);
    alloc(&V1, n);
    printf("Длина вектора V2 = ");
    scanf("%d", &n);
    alloc(&V2, n);
    fill(&V1);
    fill(&V2);
    s = sum(&V1, &V2);
    printf(&s);
    free(V1);
    free(V2);
    if (s.x != NULL) {
        free(s.x);
    }
    return 0;
}

void alloc(TVector* V, int n) {
    V->n = n;
    V->x = (double*)malloc(sizeof(double)*n);
}

void fill(TVector* V) {
    printf("Введите координаты вектора: \n");
    for (int i = 0; i < V->n; i++) {
        scanf("%lf", &(V->x[i]));
    }
}

TVector sum(TVector* V1, TVector* V2) {
    TVector res;
    int i;
    if (V1->n != V2->n) {
        printf("Длины векторов не одинаковы\n");
        res.n = 0;
        res.x = NULL;
        return res;
    }
    alloc(&res, V1->n);
    for (i = 0; i < res.n; i++) {
        res.x[i] = V1->x[i] + V2->x[i];
    }
    return res;
}

TVector diference(TVector* V1, TVector* V2) {
    TVector res;
    if (V1->n != V2->n) {
        printf("Векторы не одинаковы\n");
        res.x = NULL;
        res.n = 0;
        return res;
    }
    alloc(&res, V1->n);
    for (int i = 0; i < res.n; i++) {
        res.x[i] = V1->x[i] - V2->x[i];
    }
    return res;
}
// a*b = x1x2 +y1y2 + z1z2