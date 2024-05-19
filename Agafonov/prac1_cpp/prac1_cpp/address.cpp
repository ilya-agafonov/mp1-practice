#include "address.h"

Address::Address() {
    this->house = 0;
    this->street = "undefined";
}

std::istream& operator>>(std::istream& in, Address& address) {
    in >> address.street >> address.house;
    in.ignore();
    return in;
}
std::ostream& operator<<(std::ostream& out, const Address& address) {
    out << address.street << ", " << address.house;
    return out;
}

