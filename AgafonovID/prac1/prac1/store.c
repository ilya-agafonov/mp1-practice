#include "store.h"

void alloc(store* s) {
    s->name = (char*)malloc(sizeof(char) * MAX_LEN);
    s->specialization = (char*)malloc(sizeof(char) * MAX_LEN);
    s->type = (char*)malloc(sizeof(char) * MAX_LEN);
    s->phone = (char*)malloc(sizeof(char) * MAX_LEN);

    if (s->name == NULL || s->specialization == NULL || s->type == NULL || s->phone == NULL) {
        printf("memory allocation error\n");
        exit(1);
    }
}

void dealloc(store* s) {
    free(s->name);
    free(s->specialization);
    free(s->type);
    free(s->phone);
    free(s->store_address.street);
}

void read(FILE* file, store* s) {
    if (file == NULL) {
        printf("failed to open file read\n");
        exit(1);
    }
    alloc(s);
    fscanf(file, " %[^\n]%*c", s->name);
    read_address(file, &(s->store_address));
    fscanf(file, "%s%*c", s->phone);
    fscanf(file, " %[^\n]%*c", s->specialization);
    fscanf(file, " %[^\n]%*c", s->type);
    for (int i = 0; i < 7; i++) {
        read_worktime(file, &(s->store_worktime[i]));
    }
}

void write(FILE* file, store* s) {
    if (file == NULL) {
        printf("failed to open file write\n");
        exit(1);
    }
    fprintf(file, "%s\n", s->name);
    write_address(file, &(s->store_address));
    fprintf(file, "%s\n", s->phone);
    fprintf(file, "%s\n", s->specialization);
    fprintf(file, "%s\n", s->type);
    for (int i = 0; i < 7; i++) {
        write_worktime(file, &(s->store_worktime[i]));
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}

