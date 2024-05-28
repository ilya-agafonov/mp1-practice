#pragma once

#include <iostream>
#include <fstream>

class Time {
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m);
    int gethours() const;
    int getminutes() const;
    friend std::istream& operator>>(std::istream& in, Time& time);
    friend std::ostream& operator<<(std::ostream& out, const Time& time);
};