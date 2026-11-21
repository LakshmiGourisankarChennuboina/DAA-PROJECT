
#ifndef HEAP_H
#define HEAP_H

#include "inventory.h"

void insertBatch(Medicine m);
void heapifyUp(int index);
void heapifyDown(int index);
Medicine extractMin();

#endif
