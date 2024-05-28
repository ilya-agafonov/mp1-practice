#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "address.h"
#include "worktime.h"

class Store {
private:
    std::string name;
    std::string phone;
    std::string specialization;
    std::string type;
    Address store_address;
    WorkTime store_worktime;
public:
    Store();
    Store(const Store&);
    bool is24();

    friend std::ifstream& operator>>(std::ifstream& in, Store& s);
    friend std::ostream& operator<<(std::ostream& out, const Store& s);
};
