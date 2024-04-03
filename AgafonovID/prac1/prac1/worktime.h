#pragma once

#include <stdio.h>
#include "time.h"

typedef struct {
    char workdays[3];
    time workhours;
    time workhours2;
}worktime;

void read_worktime(FILE* file, worktime* wt);
void write_worktime(FILE* file, worktime* wt);
int around_the_clock(worktime* wt);