//store.c
#include "store.h"

void read(const char* filename, store* s1) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("failed to open file read");
        exit(1);
    }
    fscanf(file, "%[^\n]%*c", s1->name);
    read_address(file, &(s1->store_address));
    fscanf(file, "%s%*c", s1->phone);
    fscanf(file, "%[^\n]%*c", s1->specialization);
    fscanf(file, "%[^\n]%*c", s1->type);
    read_worktime(file, &(s1->store_worktime));
    fclose(file);
}

void write(const char* filename, store* s) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("failed to open file write");
        exit(1);
    }
    fprintf(file, "%s\n", s->name);
    write_address(file, &(s->store_address));
    fprintf(file, "%s\n", s->phone);
    fprintf(file, "%s\n", s->specialization);
    fprintf(file, "%s\n", s->type);
    write_worktime(file, &(s->store_worktime));
    fclose(file);
}

