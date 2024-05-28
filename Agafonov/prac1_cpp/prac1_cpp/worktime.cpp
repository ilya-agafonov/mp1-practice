#include "worktime.h"

WorkTime::WorkTime() {
     for (int i = 0; i < 7; i++) {
          workdays[i] = "undefined";
     }
}

Time WorkTime::get_worktime_start(int day) const {
    return worktime_start[day];
}

Time WorkTime::get_worktime_end(int day) const {
    return worktime_end[day];
}

std::istream& operator>>(std::istream& in, WorkTime& wt) {
    char ch;
    for (int i = 0; i < 7; i++) {
        in >> wt.workdays[i] >> wt.worktime_start[i] >> ch >> wt.worktime_end[i];
        in.ignore(1, ' ');
    }
    return in;
}
std::ostream& operator<<(std::ostream& out, const WorkTime& wt) {
    for (int i = 0; i < 7; i++) {
        out << wt.workdays[i] << " " << wt.worktime_start[i] << "-" << wt.worktime_end[i] << std::endl;
    }
    return out;
}