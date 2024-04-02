#include <stdio.h>
#include <stdlib.h>
#include "store.h"
#include "worktime.h"

int main(int argc, char** argv) {
    int n;
    char* infilename, * outfilename;
    infilename = argv[1];
    outfilename = argv[2];
    printf("infilename: %s\n", infilename);
    printf("outfilename: %s\n", outfilename);

    FILE* infile = fopen(infilename, "r");
    if (infile == NULL) {
        printf("failed to open infile\n");
        exit(1);
    }
    fscanf(infile, " %d", &n);
    store* stores = (store*)malloc(sizeof(store) * n);
    if (stores == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        read(infile, &(stores[i]));
    }
    fclose(infile);

    FILE* outfile = fopen(outfilename, "w");
    if (outfile == NULL) {
        printf("failed to open outfile\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        if (around_the_clock(&(stores[i].store_worktime)) == 1) {
            write(outfile, &(stores[i]));
        }
            
    }

    fclose(outfile);

    for (int i = 0; i < n; i++) {
        dealloc(&(stores[i]));
    }
    free(stores);
    
    return 0;
}