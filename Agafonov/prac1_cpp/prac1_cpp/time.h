#pragma once

#include <iostream>
#include <fstream>

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    friend std::ifstream& operator>>(std::ifstream& in, Time& time) {
        in >> time.hours >> time.minutes;
        return in;
    }
    friend std::ofstream& operator<<(std::ofstream& out, Time& time) {
        out << time.hours << ":" << time.minutes;
        return out;
    }
};