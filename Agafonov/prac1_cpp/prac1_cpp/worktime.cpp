#include "worktime.h"

WorkTime::WorkTime() {
    this->workdays = nullptr;
    
}

WorkTime::~WorkTime() {
    delete workdays;
}