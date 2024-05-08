#pragma once

#include <iostream>

class Address {
private:
    std::string street;
    int house;
public:
    Address();
    Address(const std::string&);
};