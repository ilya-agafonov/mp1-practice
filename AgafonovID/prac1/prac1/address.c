#include "address.h"

void read_address(FILE* file, address* adr) {
    adr->street = (char*)malloc(sizeof(char) * MAX_LEN);
    if (adr->street == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
    fscanf(file, "%s %d", adr->street, &(adr->house));
}

void write_address(FILE* file, address* adr) {
    fprintf(file, "%s %d\n", adr->street, adr->house);
}