#include "worktime.h"
#include "time.h"

void readtime(FILE* file, time* wh) {
    fscanf(file, "%d:%d", &(wh->hours), &(wh->minutes));
}

void writetime(FILE* file, time* wh) {
    fprintf(file, "%d:%02d", wh->hours, wh->minutes);
}