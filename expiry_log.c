
#include <stdio.h>
#include "inventory.h"
#include "expiry.h"

void logExpiredBatch(Medicine m)
{
    FILE *fp;

    fp = fopen("expiry_log.txt", "a");

    if(fp == NULL)
    {
        printf("Unable to open expiry log file!\n");
        return;
    }

    fprintf(fp, "Batch ID: %d\n", m.batchID);
    fprintf(fp, "Medicine Name: %s\n", m.medicineName);
    fprintf(fp, "Expiry Date: %d\n", m.expiryDate);
    fprintf(fp, "Quantity: %d\n", m.quantity);
    fprintf(fp, "-------------------------\n");

    fclose(fp);
}

void displayExpiryLog()
{
    FILE *fp;
    char ch;

    fp = fopen("expiry_log.txt", "r");

    if(fp == NULL)
    {
        printf("No expiry records found!\n");
        return;
    }

    printf("\n===== EXPIRED MEDICINE LOG =====\n");

    while((ch = fgetc(fp)) != EOF)
    {
        putchar(ch);
    }

    fclose(fp);
}
