#include "worktime.h"
#include "time.h"

void readtime(FILE* file, time* wh) {
    fscanf(file, "%d:%d", &(wh->hours), &(wh->minutes));
}

void writetime(FILE* file, time* wh, time* wh2) {
    fprintf(file, "%02d:%02d-%02d:%02d", wh->hours, wh->minutes, wh2->hours, wh2->minutes);
}