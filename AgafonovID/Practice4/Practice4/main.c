#include <stdio.h>
#include <locale.h>

#define N 10
int barcodes[N][4] = { {9,9,6,8}, {5,8,8,0}, {1,9,4,3}, {9,9,0,1}, {5,7,3,3}, {7,8,2,6}, {4,8,6,1}, {2,4,6,9}, {5,9,9,0}, {1,2,8,4} };
char* product[N] = { "Хлеб", "Молоко", "Яйца", "Сыр",  "Сахар", "Курица", "Макароны", "Масло", "Яблоки", "Чай" };
float price[N] = { 30, 60, 90, 200, 90, 300, 60, 100, 70, 120 };
float discounts[N] = { 0, 5, 12, 15, 10, 8, 30, 23, 45, 35 };
char* receipt_products[N];
int quantity_products[N];
float amount[N];

int attempts = 1, i = 0;

int barcode_verification(int* code);

void scan_product();

void add_receipt(int id);

void generate_receipt(int id, int quantity, float cost);

void print_receipt();


int main() {
    setlocale(LC_ALL, "Rus");
    scan_product();
    return 0;
}

int barcode_verification(int* code) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < 4; j++) {
            if (barcodes[i][j] != code[j]) {
                break;
            }
            if (j == 3) {
                return i;
            }
        }
    }
    return -1;
}

void scan_product() {
    int code[4], id, bar;
    printf("Введите штрихкод: \n");
    scanf("%d", &bar);
    while (bar < 1000 || bar>9999) {
        printf("Неверный ввод, попробуй еще: \n");
        scanf("%d", &bar);
    }
    for (int i = 3; i >= 0; i--) {
        code[i] = bar % 10;
        bar /= 10;
    }
    id = barcode_verification(code);
    if (id == -1) {
        printf("Неверный штрихкод\n");
        scan_product();
    }
    else {
        printf("Товар: %s, цена: %.0f, скидка: %.0f%%\n", product[id], price[id], discounts[id]);
        add_receipt(id);
    }
}

void add_receipt(int id) {
    int quantity, add;
    float cost;
    printf("Добавить товар?\n");
    scanf("%d", &add);
    if (add == 1) {
        printf("Количество товара: \n");
        scanf("%d", &quantity);
        cost = (price[id] - (price[id] * (discounts[id] / 100))) * quantity;
        generate_receipt(id, quantity, cost);
    }
    else if (add == 0) {
        scan_product();
    }
}

void generate_receipt(int id, int quantity, float cost) {
    int end;
    printf("Товар: %s, цена за 1 шт: %.2f, количество: %d, сумма: %.2f\n", product[id], price[id], quantity, cost);
    receipt_products[i] = product[id];
    quantity_products[i] = quantity;
    amount[i] = cost;
    printf("Продолжить?\n");
    scanf("%d", &end);
    if (end == 1) {
        i++;
        attempts++;
        scan_product();
    }
    else if (end == 0) {
        print_receipt();
    }
}

void print_receipt() {
    printf("\t Ваш чек за покупку:\n");
    for (i = 0; i < attempts; i++) {
        printf("Товар: %s, количество: %d, сумма: %.2f\n", receipt_products[i], quantity_products[i], amount[i]);
    }
}

// Сделать/улучшить контроль ввода, сделать проверки,