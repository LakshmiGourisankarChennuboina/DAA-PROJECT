
#include <stdio.h>
#include "inventory.h"
#include "heap.h"

void partialDispense()
{
    int quantity;

    if(heapSize == 0)
    {
        printf("Inventory is empty!\n");
        return;
    }

    printf("Earliest Expiring Medicine: %s\n",
           heap[0].medicineName);

    printf("Available Quantity: %d\n",
           heap[0].quantity);

    printf("Enter quantity to dispense: ");
    scanf("%d", &quantity);

    if(quantity <= 0)
    {
        printf("Invalid quantity!\n");
    }
    else if(quantity > heap[0].quantity)
    {
        printf("Insufficient quantity in earliest batch!\n");
    }
    else
    {
        heap[0].quantity -= quantity;

        printf("Medicine dispensed successfully!\n");
        printf("Remaining Quantity: %d\n",
               heap[0].quantity);

        if(heap[0].quantity == 0)
        {
            extractMin();
            printf("Batch removed from inventory!\n");
        }
    }
}
