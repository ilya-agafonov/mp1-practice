#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
    setlocale(LC_ALL, "Rus");
    int game, number, n, attempts = 0;
    int number2, n2, attempts2 = 0,a = 1, b = 1000;
    char p;
    int true = 0;

    printf("�������� ����� ����(1 - ����������� �����, 2 - �����������): \n");
    scanf("%d", &game);
    while (game < 1 || game > 2) {
        printf("�������� ����, �������� ��� ���: \n");
        scanf("%d", &game);
    }
    if (game == 1) {
        srand((unsigned int)time(NULL));
        number = 1 + rand() % (1000-1+1);
        printf("�������� ����� �� 1 �� 1000\n");
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
                printf("����� ����� �������: %d\n", attempts);
            }
        }
    }
    else if (game == 2){
        printf("� ��������� ������� �����, � �� ����������� ������� >, < ��� =. ������� ����� �� 1 �� 1000: \n");
        scanf("%d", &number2);
        while (number2 < 0) {
            printf("�������� ����, �������� ��� ���: \n");
            scanf("%d", &number2);
        }
        while (true != 1) {
            n2 = (a + b) / 2;
            printf("��� ����� %d?: \n", n2);
            scanf(" %c", &p);
            if (p == '<') {
                b = n2 + 1;
                attempts2++;            }
            if (p == '>') {
                a = n2 - 1;
                attempts2++;
            }
            if (p == '=') {
                true = 1;
                attempts2++;
                printf("� ������. ����� �������: %d",attempts2);
            }
        }
    }
    return 0;
}