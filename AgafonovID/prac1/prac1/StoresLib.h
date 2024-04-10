#pragma once

#include "store.h"

typedef struct 
{
    store* stores;
    int count;
} StoresLib;

void read_stores(const char* infilename, StoresLib* storelib);
void print_stores(const char* outfilename, StoresLib* storelib);
void print_all_stores(const char* outfilename, StoresLib* storelib);