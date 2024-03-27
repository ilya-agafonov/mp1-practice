//store.h
#pragma once

#define MAX_LEN 255

#include <stdio.h>
#include <stdlib.h>
#include "address.h"
#include "worktime.h"

typedef struct {
    char name[MAX_LEN];
    char specialization[MAX_LEN];
    char type[MAX_LEN];
    char phone[MAX_LEN];
    address store_address;
    worktime store_worktime[7];
}store;

void read(const char* filename, store* s1);
void write(const char* filename, store* s);

/*
����������� ������� "���"
��.����������� 10
89201234567
�������� �������
������� �����������
�� 8:00-22:00
�� 8:00-22:00
�� 8:00-22:00
�� 8:00-22:00
�� 8:00-22:00
�� 8:00-21:00
�� 8:00-21:00
*/
