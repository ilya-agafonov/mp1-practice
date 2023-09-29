#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    float x1, x2, y1, y2, r1, r2, d; //x,y - ����� ����������, r - ������, d - ���������� ����� �������� �����������
    //������ ���������� � ������� �����������

    printf("Intput x1, y1: \n");
    if (scanf("%f %f", &x1, &y1) != 2) {
        printf("Incorrect data");
        return 0;
    }

    printf("Intput r1: \n");
    if (scanf("%f", &r1) != 1 || (r1 <= 0)) {
        printf("Incorret data");
        return 0;
    }


    printf("Intput x2, y2: \n");
    if (scanf("%f %f", &x2, &y2) != 2) {
        printf("Incorrect data");
        return 0;
    }

    printf("Intput r2: \n");
    if (scanf("%f", &r2) != 1 || (r2 <= 0)) {
        printf("Incorret data");
        return 0;
    }

    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //������� ���������� ����� �������� ����������� 

    if ((x1 == x2) && (y1 == y2) && (r1 == r2)) {
        printf("Circles with the same center and radius");
        return 0;
    }
    if (d == r1 + r2) {
        printf("Circles intersect at one point");
        return 0;
    }

    if ((d > 0) && (d < fabs(r1 - r2))) {
        printf("There are no common points, one circle inside another");
        return 0;
    }

    if (d > r1 + r2) {
        printf("There are no common points");
        return 0;
    }

    if ((d > fabs(r1 - r2)) && (d < r1 + r2)) {
        printf("Circles intersect at two points");
        return 0;
    }

    if ((d == 0) && (r1 != r2)) {
        printf("There are no common points, circles with the same center, one larger than the other");
        return 0;
    }

    if (d = fabs(r1 - r2)) {
        printf("Circles intersect at one point, one circle inside another");
        return 0;
    }


    return 0;
}