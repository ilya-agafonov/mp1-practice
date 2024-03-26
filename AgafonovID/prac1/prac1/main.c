//main.c
#include <stdio.h>
#include "store.h"

int main(int argc, char** argv) {
    store s1, s2;
    char* infilename, * outfilename;
    infilename = argv[1];
    outfilename = argv[2];

    read(infilename, &s1);
    write(outfilename, &s1);

    return 0;
}