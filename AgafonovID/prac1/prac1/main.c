#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "StoresLib.h"

int main(int argc, char** argv) {
    int answer;
    char* infilename, *outfilename;
    StoresLib storelib, lib24h;

    if (argc < 3) {
        printf("�������� ���������\n");
        return 0;
    }
    infilename = argv[1];
    outfilename = argv[2];

    setlocale(LC_ALL, "Rus");
    
    printf("��� �� ������ �������? 1 - ���������� ���������, 2 - �������������� ��������\n");
    scanf("%d", &answer);
    switch (answer) {
    case 1:
        read_stores(infilename, &storelib);
        print_storelib(outfilename, &storelib);
        printf("� ���� %s ���������� ��� ��������\n", outfilename);
        dealloc_stores(&storelib);
        break;
    case 2: {
        read_stores(infilename, &storelib);
        create_lib24(&storelib, &lib24h);
        print_storelib(outfilename, &lib24h);
        printf("� ���� %s ���������� �������������� ��������\n", outfilename);
        dealloc_stores(&lib24h);
        dealloc_stores(&storelib);
        break;
    }   
    default:
        printf("�������� ����\n");
        break;
    }
    
    return 0;
}