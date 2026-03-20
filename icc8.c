//
// Created by Mies VanBeek on 2026-03-20.
//
#include <stdlib.h>
#include "icc8.h"
#include <stdio.h>
#include <string.h>

#define BANANA_RIPENESS(ripeness)   (((ripeness) > 5) ? ((ripeness) > 10) ? ("overripe") : ("ripe") : ("unripe"))

void add_banana(Banana **basket, int *capacity, char *name, int ripeness) {
    int size = *capacity + 1;
    realloc(capacity, size);

    basket[size - 1]->name = name;
    basket[size - 1]->ripeness = ripeness;
}

void sort_bananas(Banana *basket, int *capacity) {
    qsort(basket, *capacity, sizeof(int), comp_banana);

    for (int i = 0; i < *capacity; i++) {
        if (strcmp(BANANA_RIPENESS(basket[i].ripeness), "overripe") == 0) {
            printf("%s is removed due to being overripe\n", basket[i].name);
        }
        else {
            printf("%s %d %s\n", basket[i].name, basket[i].ripeness, BANANA_RIPENESS(basket[i].ripeness));
        }
    }

}


int comp_banana(const void *a, const void *b){
    Banana *bananaA = (Banana *)a;
    Banana *bananaB = (Banana *)b;

    if (bananaA->ripeness - bananaB->ripeness == 0){
        return strcmp(bananaA->name, bananaB->name);
    }

    return (bananaA->ripeness - bananaB->ripeness);
}
