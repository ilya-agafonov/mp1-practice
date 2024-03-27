//main.c
#include <stdio.h>
#include "store.h"

int main(int argc, char** argv) {
    int n = 10;
    store s1;
    store stores[2];
    char* infilename, * outfilename;
    infilename = argv[1];
    outfilename = argv[2];

    /*for (int i = 0; i < 2; i++) {
        read(infilename, &(stores[i]));
    }
    for (int i = 0; i < 2; i++) {
        write(outfilename, &(stores[i]));
    }
    */
    read(infilename, &s1);
    write(outfilename, &s1);

    return 0;
}