
#include <stdio.h>
#include "inventory.h"
#include "heap.h"
#include "filehandling.h"

void saveInventory()
{
    FILE *fp;
    int i;

    fp = fopen("inventory_data.txt", "w");

    if(fp == NULL)
    {
        printf("Unable to save inventory!\n");
        return;
    }

    for(i = 0; i < heapSize; i++)
    {
        fprintf(fp, "%d|%s|%d|%d\n",
                heap[i].batchID,
                heap[i].medicineName,
                heap[i].expiryDate,
                heap[i].quantity);
    }

    fclose(fp);
}

void loadInventory()
{
    FILE *fp;
    Medicine m;

    fp = fopen("inventory_data.txt", "r");

    if(fp == NULL)
    {
        printf("No previous inventory found. Starting new inventory.\n");
        return;
    }

    while(heapSize < MAX &&
          fscanf(fp, "%d|%49[^|]|%d|%d",
                 &m.batchID,
                 m.medicineName,
                 &m.expiryDate,
                 &m.quantity) == 4)
    {
        if(m.quantity > 0)
        {
            heap[heapSize] = m;
            heapifyUp(heapSize);
            heapSize++;
        }
    }

    fclose(fp);

    printf("Previous inventory loaded successfully!\n");
}
