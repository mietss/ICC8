#ifndef ICC8_H
#define ICC8_H
typedef struct{
  char *name;
  int ripeness;
} Banana;

void add_banana(Banana **basket, int *capacity, char *name, int ripeness);
void sort_bananas(Banana *basket, int *capacity);
int comp_banana(const void* a, const void* b);
#endif
