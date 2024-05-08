#pragma once

#include <iostream>
#include "address.h"
#include "worktime.h"

class Store {
private:
    std::string* name;
    std::string* phone;
    std::string* specialization;
    std::string* type;
    Address store_address;
    WorkTime store_worktime;
public:
    Store();
    Store(std::string&);
    Store(const Store&);
    ~Store();

    friend std::ifstream& operator>>(std::ifstream& in, Store& s);
    friend std::ofstream& operator<<(std::ofstream& out, Store& s);
};