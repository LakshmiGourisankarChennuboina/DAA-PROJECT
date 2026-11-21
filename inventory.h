
#ifndef INVENTORY_H
#define INVENTORY_H

#define MAX 100

typedef struct
{
    int batchID;
    char medicineName[50];
    int expiryDate;
    int quantity;
} Medicine;

extern Medicine heap[MAX];
extern int heapSize;

#endif
