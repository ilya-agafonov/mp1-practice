#include "store.h"

Store::Store() {
    this->name = nullptr;
    this->phone = nullptr;
    this->specialization = nullptr;
    this->type = nullptr;
}   

Store::Store(const Store& s1) {
    this->name = s1.name;
    this->phone = s1.phone;
    this->specialization = s1.specialization;
    this->type = s1.specialization;

}

Store::~Store() {
    delete[] name;
    delete[] specialization;
    delete[] type;
    delete[] phone;
    
}

std::ifstream& operator>>(std::ifstream& in, Store& s) {

}