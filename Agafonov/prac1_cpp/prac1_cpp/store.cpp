#include "store.h"

Store::Store() {
    this->name = nullptr;
    this->phone = nullptr;
    this->specialization = nullptr;
    this->type = nullptr;
    //adres
    //time
}   

Store::Store(const Store& s1) {
    this->name = s1.name;
    this->phone = s1.phone;
    this->specialization = s1.specialization;
    this->type = s1.type;
    //adres
    //time
}

Store::~Store() {
    delete name;
    delete specialization;
    delete type;
    delete phone;
    
}

