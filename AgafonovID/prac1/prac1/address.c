#include "address.h"

void read_address(FILE* file, address* adr) {
    fscanf(file, "%s %d", adr->street, &(adr->house));
}

void write_address(FILE* file, address* adr) {
    fprintf(file, "%s %d\n", adr->street, adr->house);
}