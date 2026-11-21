
#include <stdio.h>
#include "inventory.h"
#include "heap.h"

void heapifyDown(int index)
{
    int left, right, smallest;
    Medicine temp;

    while(1)
    {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if(left < heapSize &&
           heap[left].expiryDate < heap[smallest].expiryDate)
            smallest = left;

        if(right < heapSize &&
           heap[right].expiryDate < heap[smallest].expiryDate)
            smallest = right;

        if(smallest == index)
            break;

        temp = heap[index];
        heap[index] = heap[smallest];
        heap[smallest] = temp;

        index = smallest;
    }
}

Medicine extractMin()
{
    Medicine min;

    min = heap[0];

    heap[0] = heap[heapSize - 1];
    heapSize--;

    if(heapSize > 0)
        heapifyDown(0);

    return min;
}

void dispenseMedicine()
{
    Medicine m;

    if(heapSize == 0)
    {
        printf("No medicines available!\n");
        return;
    }

    m = extractMin();

    printf("\nMedicine Dispensed Successfully!\n");
    printf("Batch ID: %d\n", m.batchID);
    printf("Medicine: %s\n", m.medicineName);
    printf("Expiry Date: %d\n", m.expiryDate);
    printf("Quantity Dispensed: %d\n", m.quantity);
}
