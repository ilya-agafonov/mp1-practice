//worktime.h
#pragma once

#include <stdio.h>
#include "time.h"

typedef struct {
    char workdays[100];
    time workhours;
    time workhours2;
}worktime;

void read_worktime(FILE* file, worktime* wt);
void write_worktime(FILE* file, worktime* wt);