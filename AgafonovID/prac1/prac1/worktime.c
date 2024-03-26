//worktime.c
#include "worktime.h"
#include "time.h"

void read_worktime(FILE* file, worktime* wt) {
    fscanf(file, "%s", wt->workdays);
    fscanf(file, "%d:%d ", &(wt->workhours.hours), &(wt->workhours.minutes));
    fscanf(file, "%d:%d", &(wt->workhours2.hours), &(wt->workhours2.minutes));
}

void write_worktime(FILE* file, worktime* wt) {
    fprintf(file, "%s ", wt->workdays);
    writetime(file, &(wt->workhours));
    writetime(file, &(wt->workhours2));
}