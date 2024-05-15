#pragma once

#include <iostream>
#include <fstream>

class Address {
private:
    std::string street;
    int house;
public:
    Address();
    Address(const std::string&);
    friend std::ifstream& operator>>(std::ifstream& in, Address& address) {
        in >> address.street >> address.house;
        return in;
    }
    friend std::ofstream& operator<<(std::ofstream& out, Address& address) {
        out << address.street << ',' << address.house;
        return out;
    }
};