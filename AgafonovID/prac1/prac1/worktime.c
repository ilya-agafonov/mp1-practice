#include "worktime.h"
#include "time.h"

void read_worktime(FILE* file, worktime* wt) {
    char buffer[MAX_LEN];
    fgets(buffer, MAX_LEN, file);
    sscanf(buffer, "%s %d:%d-%d:%d", wt->workdays, &(wt->workhours_start.hours), &(wt->workhours_start.minutes), &(wt->workhours_end.hours), &(wt->workhours_end.minutes));
}

void write_worktime(FILE* file, worktime* wt) {
    fprintf(file, "%s ", wt->workdays);
    writetime(file, &(wt->workhours_start),&(wt->workhours_end));
}

void alloc_workdays(worktime* wt) {
    wt->workdays = NULL;
    wt->workdays = (char*)malloc(sizeof(char) * MAX_DAYS_LEN);
    if (wt->workdays == NULL) {
        printf("memory allocation error\n");
        return 0;;
    }
    strcpy(wt->workdays, "");
}

void dealloc_workdays(worktime* wt) {
    free(wt->workdays);
}

int around_the_clock(worktime* wt) {
    int tr = 1;
    if (wt->workhours_start.hours != 0 || wt->workhours_end.hours != 24 || wt->workhours_start.minutes != 0 || wt->workhours_end.minutes != 0) {
        tr = 0;
    }
    return tr;
}
