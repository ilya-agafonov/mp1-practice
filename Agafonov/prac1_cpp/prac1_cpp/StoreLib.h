#pragma once

#include <string.h>
#include <fstream>
#include "store.h"

class StoreLib {
private:
    int count;
    Store* stores;
public:
    StoreLib();
    StoreLib(int count);
    //StoreLib(std::string&);
    StoreLib(const StoreLib&);
    ~StoreLib();

    friend std::ifstream& operator>>(std::ifstream& in, StoreLib& lib);
    friend std::ofstream& operator<<(std::ofstream& out, StoreLib& lib);

};