#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "store.h"

class StoreLib {
private:
    int count;
    Store* stores;
    int count24() const;
public:
    StoreLib();
    StoreLib(int count);
    StoreLib(const StoreLib&);
    ~StoreLib();
    
    StoreLib get24stores() const;
    const StoreLib& operator=(const StoreLib& lib);

    friend std::ifstream& operator>>(std::ifstream& in, StoreLib& lib);
    friend std::ofstream& operator<<(std::ofstream& out, const StoreLib& lib);

};