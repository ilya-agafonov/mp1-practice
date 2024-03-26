#pragma once

#include <stdio.h>

typedef struct {
    char street[100];
    int house;
}address;

void read_address(FILE* file, address* adr);
void write_address(FILE* file, address* adr);