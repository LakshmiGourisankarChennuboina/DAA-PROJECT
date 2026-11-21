
#include <stdio.h>
#include "inventory.h"
#include "heap.h"

void heapifyUp(int index)
{
    int parent;
    Medicine temp;

    while(index > 0)
    {
        parent = (index - 1) / 2;

        if(heap[parent].expiryDate <= heap[index].expiryDate)
            break;

        temp = heap[parent];
        heap[parent] = heap[index];
        heap[index] = temp;

        index = parent;
    }
}

void insertBatch(Medicine m)
{
    if(heapSize == MAX)
    {
        printf("Inventory is full!\n");
        return;
    }

    heap[heapSize] = m;
    heapifyUp(heapSize);
    heapSize++;

    printf("Medicine batch added successfully!\n");
}
