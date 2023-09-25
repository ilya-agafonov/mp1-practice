#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    float x1, x2, y1, y2, r1, r2, d; //x,y - центр окружности, r - радиус, d - расстояние между центрами окружностей
    //Задаем координаты и радиусы окружностей
    printf("Intput x1, y1: \n");
    if (scanf("%f %f", &x1, &y1) == 0) {
        printf("Incorret data");
        return 0;
    }

    printf("Intput r1: \n");
    scanf("%f", &r1);
    if (r1 <= 0) {
        printf("Incorret data");
        return 0;
    }

    printf("Intput x2, y2: \n");
    scanf("%f %f", &x2, &y2);

    printf("Intput r2: \n");
    scanf("%f", &r2);
    if (r2 <= 0) {
        printf("Incorret data");
        return 0;
    }
    
    d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)); //считаем расстояние по теореме пифагора

    if ((x1 == x2) && (y1 == y2) && (r1 == r2) && (d == 0)) {
        printf("Окружности с одинаковым центром и радиусом");
        return 0;
    }
    if (d == r1 + r2) {
        printf("Окружности пересекаются в одной точке");
        return 0;
    }
    if ((d > 0) && (d < r1 - r2)) {
        printf("Общих точек нет, одна окружность внутри другой");
        return 0;
    }

    if (d > r1 + r2) {
        printf("Общих точек нет");
        return 0;
    }

}