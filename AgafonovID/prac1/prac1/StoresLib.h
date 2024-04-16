#pragma once

#include "store.h"

typedef struct 
{
    store* stores;
    int count;
} StoresLib;

void read_stores(const char* infilename, StoresLib* storelib);
void print_stores(const char* outfilename, StoresLib* storelib);
void print_storelib(const char* outfilename, StoresLib* storelib);
int count_24h(StoresLib* storelib);
void alloc_lib(StoresLib* storelib, int k);
void dealloc_stores(StoresLib* storelib);
StoresLib create_lib24h(StoresLib* storelib);