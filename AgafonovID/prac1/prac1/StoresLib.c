#include "StoresLib.h"

void alloc_lib(StoresLib* storelib, int k) {
    storelib->count = k;
    storelib->stores = (store*)malloc(sizeof(store) * storelib->count);
    if (storelib->stores == NULL) {
        printf("memory allocation error\n");
        return 0;
    }
}

void dealloc_stores(StoresLib* lib) {
    for (int i = 0; i < lib->count; i++) {
        dealloc(&(lib->stores[i]));
    }
    free(lib->stores);
    
}

void read_stores(const char* infilename, StoresLib* storelib) {
    FILE* infile = fopen(infilename, "r");
    if (infile == NULL) {
        printf("failed to open infile\n");
        return 0;
    }
    fscanf(infile, "%d", &(storelib->count));
    storelib->stores = (store*)malloc(sizeof(store) * storelib->count);
    if (storelib->stores == NULL) {
        printf("memory allocation error\n");
        return 0;
    }
    for (int i = 0; i < storelib->count; i++) {
        read(infile, &(storelib->stores[i]));
    }
    fclose(infile);
}

void print_storelib(const char* outfilename, StoresLib* storelib) {
    FILE* outfile = fopen(outfilename, "w");
    if (outfile == NULL) {
        printf("failed to open infile\n");
        return 0;
    }
    for (int i = 0; i < storelib->count; i++) {
        write(outfile, &(storelib->stores[i]));
    }
    fclose(outfile);
}

int is24(store* s) {
    int is = 1;
    for (int i = 0; i < 7; i++) {
        if (around_the_clock(&(s->store_worktime[i])) != 1) {
            is = 0;
            break;
        }
    }
    if (is) {
        return 1;
    }
    else {
        return 0;
    }
}

int count_24h(StoresLib* storelib) {
    int count = 0;
    for (int i = 0; i < storelib->count; i++) {
        if (is24(&(storelib->stores[i])) == 1) {
            count++;
        }
    }
    return count;
}

void create_lib24(StoresLib* storelib, StoresLib* lib24) {
    int count = count_24h(storelib);
    alloc_lib(lib24, count);
    int ind = 0;
    for (int i = 0; i < storelib->count; i++) {
        if (is24(&(storelib->stores[i])) == 1) {
            alloc(&(lib24->stores[ind]));
            strcpy(lib24->stores[ind].name, storelib->stores[i].name);
            strcpy(lib24->stores[ind].store_address.street, storelib->stores[i].store_address.street);
            lib24->stores[ind].store_address.house = storelib->stores[i].store_address.house;
            strcpy(lib24->stores[ind].phone, storelib->stores[i].phone);
            strcpy(lib24->stores[ind].specialization, storelib->stores[i].specialization);
            strcpy(lib24->stores[ind].type, storelib->stores[i].type);
            for (int j = 0; j < 7; j++) {
                strcpy(lib24->stores[ind].store_worktime[j].workdays, storelib->stores[i].store_worktime[j].workdays);
                lib24->stores[ind].store_worktime[j].workhours_start = storelib->stores[i].store_worktime[j].workhours_start;
                lib24->stores[ind].store_worktime[j].workhours_end = storelib->stores[i].store_worktime[j].workhours_end;
            }
            ind++;
        }
    }
}
