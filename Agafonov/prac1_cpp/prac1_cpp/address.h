#pragma once

#include <iostream>
#include <string>
#include <fstream>

class Address {
private:
    std::string street;
    int house;
public:
    Address();
    friend std::istream& operator>>(std::istream& in, Address& address);
    friend std::ostream& operator<<(std::ostream& out, const Address& address);
};