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
    printf("Что вы хотите вывести? 1 - справочник магазинов, 2 - круглосуточные магазины\n");
    scanf("%d", &answer);
    switch (answer) {
    case 1:
        print_storelib(outfilename, &storelib);
        printf("В файл %s напечатаны все магазины\n", outfilename);
        break;
    case 2: {
        StoresLib lib24h;
        lib24h = create_lib24h(&storelib);
        print_storelib(outfilename, &lib24h);
        printf("В файл %s напечатаны круглосуточные магазины\n", outfilename);
        dealloc_stores(&lib24h);
        break;
    }
    default:
        printf("Неверный ввод\n");
        break;
    }
    
    dealloc_stores(&storelib);
    
    return 0;
}