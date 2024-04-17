#include "StoresLib.h"

void alloc_lib(StoresLib* storelib, int k) {
    storelib->count = k;
    storelib->stores = (store*)malloc(sizeof(store) * storelib->count);
    if (storelib->stores == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
}

void dealloc_stores(StoresLib* lib) {
    printf("%d\n", lib->count);
    for (int i = 0; i < lib->count; i++) {
        if (&(lib->stores[i]) != NULL) {
            printf("Очистка %d\n", i);
            dealloc(&(lib->stores[i]));
        }
    }
    free(lib->stores);
}

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

void print_storelib(const char* outfilename, StoresLib* storelib) {
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

int count_24h(StoresLib* storelib) {
    int count = 0;
    for (int i = 0; i < storelib->count; i++) {
        int go = 1;
        for (int j = 0; j < 7; j++) {
            if (around_the_clock(&(storelib->stores[i].store_worktime[j])) != 1) {
                go = 0;
                break;
            }
        }
        if (go) {
            count++;
        }
    }
    return count;
}


StoresLib create_lib24h(StoresLib* storelib) {
    int count = count_24h(storelib);
    StoresLib lib24;
    //alloc_lib(&lib24, count);
    lib24.count = count;
    lib24.stores = (store*)malloc(sizeof(store) * lib24.count);
    if (storelib->stores == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
    int ind = 0;
    for (int i = 0; i < storelib->count; i++) {
        int go = 1;
        for (int j = 0; j < 7; j++) {
            if (around_the_clock(&(storelib->stores[i].store_worktime[j])) != 1) {
                go = 0;
                break;
            }
        }
        if (go) {
            lib24.stores[ind++] = storelib->stores[i];
        }
    }
    return lib24;
}
