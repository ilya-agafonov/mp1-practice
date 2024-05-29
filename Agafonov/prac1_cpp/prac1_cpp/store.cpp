#include "store.h"

Store::Store() {
    this->name = "undefind";
    this->specialization = "undefind";
    this->phone = "undefind";
    this->type = "undefind";
}

Store::Store(const Store& s) {
    this->name = s.name;
    this->phone = s.phone;
    this->specialization = s.specialization;
    this->type = s.type;
    this->store_address = s.store_address;
    this->store_worktime = s.store_worktime;
}

bool Store::is24() const {
    for (int i = 0; i < 7; i++) {
        if (store_worktime.get_worktime_start(i).gethours() != 0 || store_worktime.get_worktime_start(i).getminutes() != 0 || 
            store_worktime.get_worktime_end(i).gethours() != 24 || store_worktime.get_worktime_end(i).getminutes() != 0 ) {
            return false;
        }
    }
    return true;
}

std::ifstream& operator>>(std::ifstream& in, Store& s) {
    std::getline(in, s.name, ',');
    in.ignore(1, ' ');
    in >> s.store_address;
    in.ignore(1, ' ');
    std::getline(in, s.phone, ',');
    in.ignore(1, ' ');
    std::getline(in, s.specialization, ',');
    in.ignore(1, ' ');
    std::getline(in, s.type, ',');
    in.ignore(1, ' ');
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
