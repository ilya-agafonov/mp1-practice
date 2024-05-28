#include "StoreLib.h"

StoreLib::StoreLib() {
    this->count = 0;
    this->stores = nullptr; 
}

StoreLib::StoreLib(int count) {
    this->count = count;
    this->stores = new Store[this->count];
}

StoreLib::StoreLib(const StoreLib& lib) {
    this->count = lib.count;
    this->stores = new Store[this->count];
    for (int i = 0; i < this->count; i++) {
        this->stores[i] = lib.stores[i];
    }
}

StoreLib StoreLib::get24stores() {
    int k = count24();
    StoreLib lib(k);
    int ind = 0;
    for (int i = 0; i < count; i++) {
        if (stores[i].is24()) {
            lib.stores[ind++] = stores[i];
        }
    }
    return lib;
}

StoreLib::~StoreLib() {
    delete[] this->stores;
}

int StoreLib::count24() {
    int k = 0;
    for (int i = 0; i < count; i++) {
        if (stores[i].is24()) {
            k++;
        }
    }
    return k;
}

std::ifstream& operator>>(std::ifstream& in, StoreLib& lib) {
    in >> lib.count;
    in.ignore();
    lib.stores = new Store[lib.count];
    for (int i = 0; i < lib.count; i++) {
        in >> lib.stores[i];        
    }
    return in;
}

std::ofstream& operator<<(std::ofstream& out, const StoreLib& lib) {
    for (int i = 0; i < lib.count; i++) {
        out << lib.stores[i] << std::endl;
    }
    return out; 
}

StoreLib& StoreLib::operator=(const StoreLib& lib) {
    if (this == &lib) {
        return *this;
    }
    delete[] stores;
    count = lib.count;
    stores = new Store[count];
    for (int i = 0; i < count; ++i) {
        stores[i] = lib.stores[i];
    }
    return *this;
}