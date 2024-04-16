#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "address.h"
#include "worktime.h"

#define MAX_LEN 255

typedef struct {
    char* name;
    char* specialization;
    char* type;
    char* phone;
    address store_address;
    worktime store_worktime[7];
}store;

void read(FILE* file, store* s1);
void write(FILE* file, store* s);
void alloc(store* s);
void dealloc(store* s);


