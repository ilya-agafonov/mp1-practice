#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Rus");

    int number, n, attempts = 0;
    int true = 0;
    srand((unsigned int)time(NULL));
    number = rand() % 1000;
    printf("�������� ����� �� 0 �� 1000\n");
    printf("�������� �������� ��� �����: \n");
    scanf("%d", &n);
    while (n < 0) {
        printf("�������� ����, �������� ��� ���: \n");
        scanf("%d", &n);
    }
    while (true != 1) {
        if (n > number) {
            printf("���������� ����� ������, ��������� ��� ���: \n");
            scanf("%d", &n);
            attempts++;
        }

        if (n < number) {
            printf("���������� ����� ������, ��������� ��� ���: \n");
            scanf("%d", &n);
            attempts++;
        }

        if (n == number) {
            true = 1;
            attempts++;
            printf("�� �������� �����!\n");
            printf("����� ����� �������: %d\n",attempts);
            return 0;
        }
    }
    return 0;
}