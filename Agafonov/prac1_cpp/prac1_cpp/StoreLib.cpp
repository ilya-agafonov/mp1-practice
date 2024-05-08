#include "StoreLib.h"

StoreLib::StoreLib() {
    this->count = 0;
    this->stores = nullptr; 
}

StoreLib::StoreLib(int count) {
    this->count = count;
    this->stores = new Store[this->count];
}

StoreLib::StoreLib(std::string& filename) {

}

StoreLib::StoreLib(const StoreLib& lib) {
    this->count = lib.count;
    this->stores = new Store[this->count];
    for (int i = 0; i < this->count; i++) {
        this->stores[i] = lib.stores[i];
    }
}

StoreLib::~StoreLib() {
    delete[] this->stores;
}

std::ifstream& operator>>(std::ifstream& in, StoreLib& lib) {
    in >> lib.count;
    lib = StoreLib(lib.count);
    for (int i = 0; i < lib.count; i++) {
        
    }
}