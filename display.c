
#include <stdio.h>
#include "inventory.h"

void displayInventory()
{
    int i;

    if(heapSize == 0)
    {
        printf("Inventory is empty!\n");
        return;
    }

    printf("\n===== MEDICINE INVENTORY =====\n");
    printf("Batch ID\tMedicine\tExpiry Date\tQuantity\n");

    for(i = 0; i < heapSize; i++)
    {
        printf("%d\t\t%s\t\t%d\t%d\n",
        heap[i].batchID,
        heap[i].medicineName,
        heap[i].expiryDate,
        heap[i].quantity);
    }
}
