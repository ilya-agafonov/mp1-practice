#include "worktime.h"
#include "time.h"

void read_worktime(FILE* file, worktime* wt) {
    alloc_workdays(wt);
    fscanf(file, "%s", wt->workdays);
    fscanf(file, "%d:%d-%d:%d", &(wt->workhours_start.hours), &(wt->workhours_start.minutes), &(wt->workhours_end.hours), &(wt->workhours_end.minutes));
}

void write_worktime(FILE* file, worktime* wt) {
    fprintf(file, "%s ", wt->workdays);
    writetime(file, &(wt->workhours_start),&(wt->workhours_end));
}

void alloc_workdays(worktime* wt) {
    wt->workdays = (char*)malloc(sizeof(char) * MAX_DAYS_LEN);
    if (wt->workdays == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
}

int around_the_clock(worktime* wt) {
    int tr = 1;
    if (wt->workhours_start.hours != 0 || wt->workhours_end.hours != 24 || wt->workhours_start.minutes != 0 || wt->workhours_end.minutes != 0) {
        tr = 0;
    }
    return tr;
}
