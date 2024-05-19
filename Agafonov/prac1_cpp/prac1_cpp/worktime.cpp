#include "worktime.h"

WorkTime::WorkTime() {
     for (int i = 0; i < 7; i++) {
          workdays[i] = "undefined";
     }
}

std::istream& operator>>(std::istream& in, WorkTime& wt) {
    char ch;
    for (int i = 0; i < 7; i++) {
        in >> wt.workdays[i] >> wt.worktime_start[i] >> ch >> wt.worktime_end[i];
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const WorkTime& wt) {
    for (int i = 0; i < 7; i++) {
        out << wt.workdays[i] << " " << wt.worktime_start[i] << "-" << wt.worktime_end[i] << std::endl;
    }
    return out;
}