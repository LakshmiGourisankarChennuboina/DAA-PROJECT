
#include <stdio.h>
#include "inventory.h"
#include "heap.h"
#include "expiry.h"

void purgeExpired(int today)
{
    Medicine m;
    int count = 0;

    while(heapSize > 0 && heap[0].expiryDate < today)
    {
        m = extractMin();

        logExpiredBatch(m);

        printf("\nExpired Batch Removed Successfully!\n");
        printf("Batch ID: %d\n", m.batchID);
        printf("Medicine Name: %s\n", m.medicineName);
        printf("Expiry Date: %d\n", m.expiryDate);
        printf("Quantity: %d\n", m.quantity);

        count++;
    }

    if(count == 0)
    {
        printf("\nNo expired medicines found!\n");
    }
    else
    {
        printf("\nTotal Expired Batches Removed: %d\n", count);
    }
}
