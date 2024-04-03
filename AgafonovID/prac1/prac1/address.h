#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 255

typedef struct {
    char* street;
    int house;
}address;

void read_address(FILE* file, address* adr);
void write_address(FILE* file, address* adr);