#include "address.h"

void read_address(FILE* file, address* adr) {
    char buffer[MAX_LEN];
    fgets(buffer, MAX_LEN, file);
    sscanf(buffer, "%s %d", adr->street, &(adr->house));
}

void write_address(FILE* file, address* adr) {
    fprintf(file, "%s %d\n", adr->street, adr->house);
}