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
Продуктовый магазин "Уют"
ул.Центральная 10
89201234567
Продукты питания
Частное предприятие
Пн 8:00-22:00
Вт 8:00-22:00
Ср 8:00-22:00
Чт 8:00-22:00
Пт 8:00-22:00
Сб 8:00-21:00
Вс 8:00-21:00
*/
