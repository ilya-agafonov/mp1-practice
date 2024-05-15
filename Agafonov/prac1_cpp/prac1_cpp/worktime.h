#pragma once

#include <iostream>
#include <fstream>
#include "time.h"

class WorkTime {
private:
    std::string* workdays;
    Time worktime_start;
    Time worktime_end;
public:
    WorkTime();
    WorkTime(const std::string&);
    ~WorkTime();
    double* operator[](int ind) {
        return this->worktime_start[ind]; //фигня
    }
    friend std::ifstream& operator>>(std::ifstream& in, WorkTime& wt) {
        std::string workdays;
        for (int i = 0; i < 7; i++) {
            in >> workdays;
            wt.workdays = new std::string(workdays);
            in >> wt.worktime_start >> wt.worktime_end;
        }
        return in;
    }
    friend std::ofstream& operator<<(std::ofstream& out, WorkTime& wt) {
        for (int i = 0; i < 7; i++) {
            out << wt[i].workdays << " " << wt[i].worktime_start << "-" << wt[i].worktime_end;
        }
        return out;
    }
};