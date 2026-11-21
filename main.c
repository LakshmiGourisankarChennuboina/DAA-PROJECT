
#include <stdio.h>
#include "inventory.h"
#include "heap.h"
#include "expiry.h"
#include "filehandling.h"

Medicine heap[MAX];
int heapSize = 0;

void displayInventory();
void dispenseMedicine();
void partialDispense();
void comparePerformance();

int main()
{
    int choice, day, month, year, today;

    loadInventory();

    printf("\nInventory loaded successfully!\n");

    do
    {
        printf("\n===== PHARMACY INVENTORY MANAGEMENT =====\n");
        printf("1. Add Medicine Batch\n");
        printf("2. Display Inventory\n");
        printf("3. Dispense Medicine\n");
        printf("4. Partial Dispensing\n");
        printf("5. Purge Expired Medicines\n");
        printf("6. View Expired Stock Log\n");
        printf("7. Compare Data Structure Performance\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                Medicine m;

                printf("Enter Batch ID: ");
                scanf("%d", &m.batchID);

                printf("Enter Medicine Name: ");
                scanf(" %49[^\n]", m.medicineName);

                printf("Enter Expiry Date (DD-MM-YYYY): ");

                if(scanf("%d-%d-%d", &day, &month, &year) != 3)
                {
                    printf("Invalid date format! Use DD-MM-YYYY.\n");
                    break;
                }

                if(day < 1 || day > 31 || month < 1 ||
                   month > 12 || year < 1)
                {
                    printf("Invalid expiry date!\n");
                    break;
                }

                m.expiryDate = year * 10000 + month * 100 + day;

                printf("Enter Quantity: ");
                scanf("%d", &m.quantity);

                if(m.quantity <= 0)
                {
                    printf("Invalid quantity!\n");
                    break;
                }

                insertBatch(m);
                break;
            }

            case 2:
                displayInventory();
                break;

            case 3:
                dispenseMedicine();
                break;

            case 4:
                partialDispense();
                break;

            case 5:
                printf("Enter Today's Date (DD-MM-YYYY): ");

                if(scanf("%d-%d-%d", &day, &month, &year) != 3)
                {
                    printf("Invalid date format! Use DD-MM-YYYY.\n");
                    break;
                }

                if(day < 1 || day > 31 || month < 1 ||
                   month > 12 || year < 1)
                {
                    printf("Invalid date!\n");
                    break;
                }

                today = year * 10000 + month * 100 + day;

                purgeExpired(today);
                break;

            case 6:
                displayExpiryLog();
                break;

            case 7:
                comparePerformance();
                break;

            case 8:
                printf("Exiting Inventory System...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

        saveInventory();

    } while(choice != 8);

    return 0;
}
