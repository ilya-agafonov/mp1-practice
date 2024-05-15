#pragma once

#include <iostream>
#include <fstream>
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

    friend std::ifstream& operator>>(std::ifstream& in, Store& s) {
        std::string name, phone, specialization, type;
        in >> name;
        in >> s.store_address;
        in >> phone;
        in >> specialization;
        in >> type;
        in >> s.store_worktime;
        s.name = new std::string(name);
        s.phone = new std::string(phone);
        s.specialization = new std::string(specialization);
        s.type = new std::string(type);
        return in;
    }
    friend std::ofstream& operator<<(std::ofstream& out, Store& s) {
        out << s.name << std::endl;
        out << s.phone << std::endl;
        out << s.specialization << std::endl;
        out << s.type << std::endl;
        return out;
    }
};