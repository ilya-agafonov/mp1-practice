#include "store.h"

void alloc(store* s) {
    s->name = (char*)malloc(sizeof(char) * MAX_LEN);
    s->specialization = (char*)malloc(sizeof(char) * MAX_LEN);
    s->type = (char*)malloc(sizeof(char) * MAX_LEN);
    s->phone = (char*)malloc(sizeof(char) * MAX_LEN);
    if (s->name == NULL || s->specialization == NULL || s->type == NULL || s->phone == NULL) {
        printf("memory allocation error\n");
        return 0;
    }
    s->store_address.street = (char*)malloc(sizeof(char) * MAX_LEN);
    if (s->store_address.street == NULL) {
        printf("memory allocation error\n");
        return 0;
    }
    for (int i = 0; i < 7; i++) {
        alloc_workdays(&(s->store_worktime[i]));
    }
}

void dealloc(store* s) {
    free(s->name);
    free(s->store_address.street);
    free(s->phone);
    free(s->specialization);
    free(s->type);
    for (int i = 0; i < 7; i++) {
        dealloc_workdays(&(s->store_worktime[i]));
    }
}

void read(FILE* file, store* s) {
    if (file == NULL) {
        printf("failed to open file read\n");
        return 0;
    }
    char buffer[MAX_LEN];

    alloc(s);
    fgets(buffer, MAX_LEN, file);
    buffer[strcspn(buffer, "\n")] = '\0';

    fgets(s->name, MAX_LEN, file);
    s->name[strcspn(s->name, "\n")] = '\0';

    read_address(file, &(s->store_address));

    fgets(s->phone, MAX_LEN, file);
    s->phone[strcspn(s->phone, "\n")] = '\0';

    fgets(s->specialization, MAX_LEN, file);
    s->specialization[strcspn(s->specialization, "\n")] = '\0';

    fgets(s->type, MAX_LEN, file);
    s->type[strcspn(s->type, "\n")] = '\0';

    for (int i = 0; i < 7; i++) {
        read_worktime(file, &(s->store_worktime[i]));
    }
}

void write(FILE* file, store* s) {
    if (file == NULL) {
        printf("failed to open file write\n");
        return 0;
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

