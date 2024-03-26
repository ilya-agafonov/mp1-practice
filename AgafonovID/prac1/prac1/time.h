#pragma once

typedef struct {
    int hours;
    int minutes;
}time;

void readtime(FILE* file, time* wh);
void writetime(FILE* file, time* wh);