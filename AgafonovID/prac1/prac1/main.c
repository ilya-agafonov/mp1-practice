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
        print_storelib(outfilename, &storelib);
        printf("� ���� %s ���������� ��� ��������\n", outfilename);
        break;
    case 2: {
        StoresLib lib24h;
        lib24h = create_lib24h(&storelib);
        print_storelib(outfilename, &lib24h);
        printf("� ���� %s ���������� �������������� ��������\n", outfilename);
        dealloc_stores(&lib24h);
        break;
    }
    default:
        printf("�������� ����\n");
        break;
    }
    
    dealloc_stores(&storelib);
    
    return 0;
}