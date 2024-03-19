#include <stdio.h>
#include <locale.h>
#include "vector.h"
#include "func.c"

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