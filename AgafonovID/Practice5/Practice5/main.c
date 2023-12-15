#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_LEN 255
//�������: ���������, ���������. �������: ��������.

typedef struct {
    char name[MAX_LEN];
    int size;
} fileinfo;

void bubble_sorting(fileinfo files[], int k) {
    for (int i = 0; i < k - 1; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            if (files[j].size > files[j + 1].size) {
                int tmp;
                tmp = files[j].size;
                files[j].size = files[j + 1].size;
                files[j + 1].size = tmp;
            }
        }
    }
    
}

void insert_sorting(fileinfo files[], int k) {
    for (int i = 1; i < k; i++) {
        int min, j;
        min = files[i].size;
        j = i - 1;
        while (j >= 0 && files[j].size > min) {
            files[j + 1].size = files[j].size;
            j--;
            files[j + 1].size = min;
        }
    }
}


void find_files(char *path, fileinfo files[], int* k) {
    char search_path[MAX_LEN];
    snprintf(search_path, MAX_LEN, "%s\\*.*", path);
    WIN32_FIND_DATAA FileData;
    HANDLE file = FindFirstFileA(search_path, &FileData);
    if (file == INVALID_HANDLE_VALUE) {
        printf("�� ������� ����� ����\n");
    }
    else {
        while (FindNextFileA(file, &FileData) != 0) {
            if (!(FileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                strcpy(files[*k].name, FileData.cFileName);
                files[*k].size = FileData.nFileSizeLow;
                (*k)++;
            }
        }
        printf("���������� ��������� ������: %d\n", *k);
    }
    FindClose(file);
}

void sorted_files(fileinfo files[], int k) {
    for (int i = 0; i < k; i++) {
        printf("��� ����� %s, ������ %d ����\n", files[i].name, files[i].size);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    srand((unsigned int)time(0));
    int method, true = 0, k = 0;
    char path[MAX_LEN];
    clock_t start, finish;
    double duration;
    printf("�������� ��������\n");
    printf("������� ����: \n");
    scanf("%s", &path);
    fflush(stdin);

    fileinfo files[1000];
    find_files(path, files, &k);

    printf("����� ����� ���������� ������������?(1 - ���������, 2 - ���������, 3 - ��������):\n");
    while (true != 1) {
        scanf("%d", &method);
        start = clock();
        switch (method) {
        case 1: 
            bubble_sorting(files, k);
            sorted_files(files, k);
            true = 1;
            break;
        case 2:
            insert_sorting(files, k);
            sorted_files(files, k);
            true = 1;
            break;
        case 3:
            //��������
            true = 1;

            break;
        default:
            printf("�������� ����\n");
            break;
        }
        finish = clock();
        duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
        printf("����� ���������� %.3lf�\n", duration);
    }
    return 0;
}
//��������� ���� ����