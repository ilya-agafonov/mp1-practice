#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "store.h"

class StoreLib {
private:
    int count;
    Store* stores;
public:
    StoreLib();
    StoreLib(int count);
    StoreLib(const StoreLib&);
    ~StoreLib();
    int count24();
    StoreLib get24stores();
    StoreLib& operator=(const StoreLib& lib);

    friend std::ifstream& operator>>(std::ifstream& in, StoreLib& lib);
    friend std::ofstream& operator<<(std::ofstream& out, const StoreLib& lib);

};