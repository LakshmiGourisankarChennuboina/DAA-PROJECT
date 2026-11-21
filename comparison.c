
#include <stdio.h>

void comparePerformance()
{
    printf("\n===== DATA STRUCTURE PERFORMANCE =====\n");

    printf("\nOperation\tMin-Heap\tSorted List\tUnsorted List\n");

    printf("Insert\t\tO(log n)\tO(n)\t\tO(1)\n");

    printf("Find Min\tO(1)\t\tO(1)\t\tO(n)\n");

    printf("Extract Min\tO(log n)\tO(1)\t\tO(n)\n");

    printf("\nMin-Heap provides efficient insertion and extraction.\n");

    printf("It is suitable for FEFO inventory management.\n");
}
