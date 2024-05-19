#include "store.h"

Store::Store() {
    this->name = "undefind";
    this->specialization = "undefind";
    this->phone = "undefind";
    this->type = "undefind";
}

Store::Store(const Store& s1) {
    this->name = s1.name;
    this->phone = s1.phone;
    this->specialization = s1.specialization;
    this->type = s1.type;
    this->store_address = s1.store_address;
    this->store_worktime = s1.store_worktime;
}

std::ifstream& operator>>(std::ifstream& in, Store& s) {
    std::getline(in, s.name);
    in >> s.store_address;
    std::getline(in, s.phone);
    std::getline(in, s.specialization);
    std::getline(in, s.type);
    in >> s.store_worktime;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Store& s) {
    out << s.name << std::endl;
    out << s.store_address << std::endl;
    out << s.phone << std::endl;
    out << s.specialization << std::endl;
    out << s.type << std::endl;
    out << s.store_worktime;
    return out;
}
