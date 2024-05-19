#include "time.h"

Time::Time() {
    this->hours = 0;
    this->minutes = 0;
}

Time::Time(int h, int m) {
    this->hours = h;
    this->minutes = m;
}

std::istream& operator>>(std::istream& in, Time& time) {
    char ch;
    in >> time.hours >> ch >> time.minutes;
    return in;
}
std::ostream& operator<<(std::ostream& out, const Time& time) {
    out << (time.hours < 10 ? "0" : "") << time.hours << ":" << (time.minutes < 10 ? "0" : "") << time.minutes;
    return out;
}