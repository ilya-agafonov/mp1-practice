#pragma once

#include <iostream>
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
};