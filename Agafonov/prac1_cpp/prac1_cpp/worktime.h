#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "time.h"

class WorkTime {
private:
    std::string workdays[7];
    Time worktime_start[7];
    Time worktime_end[7];
public:
    WorkTime();

    friend std::istream& operator>>(std::istream& in, WorkTime& wt);
    friend std::ostream& operator<<(std::ostream& out, const WorkTime& wt);
};