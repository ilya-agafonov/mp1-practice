#pragma once

#include <string.h>
#include <stdlib.h>
#include "store.h"

typedef struct 
{
    store* stores;
    int count;
} StoresLib;

void read_stores(const char* infilename, StoresLib* storelib);
void print_storelib(const char* outfilename, StoresLib* storelib);
void alloc_lib(StoresLib* storelib, int k);
void dealloc_stores(StoresLib* lib);
void create_lib24(StoresLib* storelib, StoresLib* lib24);
int count_24h(StoresLib* storelib);
int is24(store* s);