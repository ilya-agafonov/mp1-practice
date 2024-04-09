#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "StoresLib.h"

int main(int argc, char** argv) {
    int answer;
    char* infilename = argv[1], * outfilename = argv[2];
    StoresLib storelib;

    setlocale(LC_ALL, "Rus");

    read_stores(infilename, &storelib);
    printf("��� �� ������ �������? 1 - ���������� ���������, 2 - �������������� ��������\n");
    scanf("%d", &answer);
    switch (answer) {
    case 1:
        print_all_stores(outfilename, &storelib);
        printf("� ���� %s ���������� ��� ��������\n", outfilename);
        break;
    case 2:
        print_stores(outfilename, &storelib);
        printf("� ���� %s ���������� �������������� ��������\n", outfilename);
        break;
    default:
        printf("�������� ����\n");
        break;
    }

    for (int i = 0; i < storelib.count; i++) {
        dealloc(&(storelib.stores[i]));
    }
    free(storelib.stores);
    
    return 0;
}