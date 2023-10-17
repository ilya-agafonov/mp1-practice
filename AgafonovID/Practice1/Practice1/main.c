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
    printf("Загадано число от 0 до 1000\n");
    printf("Попробуй отгадать это число: \n");
    scanf("%d", &n);
    while (n < 0) {
        printf("Неверный ввод, попробуй еще раз: \n");
        scanf("%d", &n);
    }
    while (true != 1) {
        if (n > number) {
            printf("Загаданное число меньше, попытайся еще раз: \n");
            scanf("%d", &n);
            attempts++;
        }

        if (n < number) {
            printf("Загаданное число больше, попытайся еще раз: \n");
            scanf("%d", &n);
            attempts++;
        }

        if (n == number) {
            true = 1;
            attempts++;
            printf("Вы отгадали число!\n");
            printf("Число ваших попыток: %d\n",attempts);
            return 0;
        }
    }
    return 0;
}