#include "StoresLib.h"

void read_stores(const char* infilename, StoresLib* storelib) {
    FILE* infile = fopen(infilename, "r");
    if (infile == NULL) {
        printf("failed to open infile\n");
        exit(1);
    }
    fscanf(infile, "%d", &(storelib->count));
    storelib->stores = (store*)malloc(sizeof(store) * storelib->count);
    if (storelib->stores == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
    for (int i = 0; i < storelib->count; i++) {
        read(infile, &(storelib->stores[i]));
    }
    fclose(infile);
}

void print_stores(const char* outfilename, StoresLib* storelib) {
    FILE* outfile = fopen(outfilename, "w");
    if (outfile == NULL) {
        printf("failed to open infile\n");
        exit(1);
    }
    for (int i = 0; i < storelib->count; i++) {
        int go = 1;
        for (int j = 0; j < 7; j++) {
            if (around_the_clock(&(storelib->stores[i].store_worktime[j])) != 1) {
                go = 0;
                break;
            }
        }
        if (go) {
            write(outfile, &(storelib->stores[i]));
        }
    }
    fclose(outfile);
}

void print_all_stores(const char* outfilename, StoresLib* storelib) {
    FILE* outfile = fopen(outfilename, "w");
    if (outfile == NULL) {
        printf("failed to open infile\n");
        exit(1);
    }
    for (int i = 0; i < storelib->count; i++) {
        write(outfile, &(storelib->stores[i]));
    }
    fclose(outfile);
}