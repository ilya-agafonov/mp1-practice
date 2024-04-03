#include "worktime.h"
#include "time.h"

void read_worktime(FILE* file, worktime* wt) {
    fscanf(file, "%s", wt->workdays);
    fscanf(file, "%d:%d-%d:%d", &(wt->workhours.hours), &(wt->workhours.minutes), &(wt->workhours2.hours), &(wt->workhours2.minutes));
}

void write_worktime(FILE* file, worktime* wt) {
    fprintf(file, "%s ", wt->workdays);
    writetime(file, &(wt->workhours),&(wt->workhours2));
}

int around_the_clock(worktime* wt) {
    int tr = 1;
    if (wt->workhours.hours != 0 || wt->workhours2.hours != 24 || wt->workhours.minutes != 0 || wt->workhours2.minutes != 0) {
        tr = 0;
    }
    return tr;
}
