#pragma once

#include <stdio.h>
#include <string.h>

#define MAX_LEN 255

typedef struct {
    char street[MAX_LEN];
    int house;
}address;

void read_address(FILE* file, address* adr);
void write_address(FILE* file, address* adr);