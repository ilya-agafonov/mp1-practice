#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

#define MAX_DAYS_LEN 30

typedef struct {
    char* workdays;
    time workhours_start;
    time workhours_end;
}worktime;

void read_worktime(FILE* file, worktime* wt);
void write_worktime(FILE* file, worktime* wt);
void alloc_workdays(worktime* wt);
int around_the_clock(worktime* wt);