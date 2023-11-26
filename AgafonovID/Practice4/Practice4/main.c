#include <stdio.h>
#include <locale.h>
#include <string.h>

#define N 10
char* barcodes[N] = { "9968", "5880", "1943", "9901", "5733", "7826", "4861", "2469", "5990", "1284" };
char* product[N] = { "����", "������", "����", "���",  "�����", "������", "��������", "�����", "������", "���" };
float price[N] = { 30, 60, 90, 200, 90, 300, 60, 100, 70, 120 };
float discounts[N] = { 0, 5, 12, 15, 10, 8, 30, 23, 45, 35 };

char* receipt_products[N];
float prices[N];
int quantity_products[N];
float amount[N];

int attempts = 1, i = 0;

int barcode_verification(char* code);

void scan_product();

void add_receipt(int id);

void generate_receipt(int id, int quantity, float cost);

void print_receipt();


int main() {
    setlocale(LC_ALL, "Rus");
    scan_product();
    return 0;
}

int barcode_verification(char* code) {
    int i;
    for (i = 0; i < N; i++) {
        if (strcmp(barcodes[i], code) == 0) {
            return i;
        }
    }
    return -1;
}

void scan_product() {
    char code[5];
    int id;
    printf("������� ��������: \n");
    scanf("%s", code);
    id = barcode_verification(code);
    if (id == -1) {
        printf("�������� ��������\n");
        scan_product();
    }
    else {
        printf("�����: %s, ����: %.0f, ������: %.0f%%\n", product[id], price[id], discounts[id]);
        add_receipt(id);
    }
}

void add_receipt(int id) {
    int quantity, add;
    float cost;
    printf("�������� �����?(1 - ��, 0 - ���)\n");
    scanf("%d", &add);
    while (add > 1 || add < 0) {
        printf("�������� �����\n");
        scanf("%d", &add);
    }
    if (add == 1) {
        printf("���������� ������: \n");
        scanf("%d", &quantity);
        cost = (price[id] - (price[id] * (discounts[id] / 100))) * quantity;
        generate_receipt(id, quantity, cost);
    }
    else if (add == 0) {
        scan_product();
    }
}

void generate_receipt(int id, int quantity, float cost) {
    int end, flag = 0;
    printf("�����: %s, ���� �� 1 ��: %.2f, ����������: %d, �����: %.2f\n", product[id], price[id], quantity, cost);
    for (int j = 0; j < i; j++) {
        if (strcmp(product[id], receipt_products[j]) == 0) {
            quantity_products[j] += quantity;
            amount[j] += cost;
            flag = 1;
            attempts--;
            break;
        }
    }
    if (flag == 0) {
        receipt_products[i] = product[id];
        prices[i] = price[id];
        quantity_products[i] = quantity;
        amount[i] = cost;
    }
    printf("���������� �������?(1 - ��, 0 - ���)\n");
    scanf("%d", &end);
    while (end > 1 || end < 0) {
        printf("�������� �����\n");
        scanf("%d", &end);
    }
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
    float sum = 0;
    printf("\t ��� ��� �� �������:\n");
    for (i = 0; i < attempts; i++) {
        printf("�����: %s, ��������� �� 1 ��: %.2f, ����������: %d, �����: %.2f\n", receipt_products[i], prices[i], quantity_products[i], amount[i]);
        sum += amount[i];
    }
    printf("�������� �����: %.2f", sum);
}