//-----------INSERTION SORT------------//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
}

void printArray(int arr[], int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n < 10)
    {
        printf("Please enter a number greater than or equal to 10.\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    

    if (arr == NULL)
    {
        printf("Memory not allocated.\n");
        return -1;
    }

    srand(time(NULL));
    generateRandomNumber(arr, n);

    printf("\nOriginal array:\n");
    printArray(arr, n);

    clock_t start = clock();

    for (int i = 0; i < 1000; i++)
    {
        
        insertionSort(arr, n);
    }

    printf("\nSorted array:\n");
    printArray(arr, n);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Insertion sort completed for %d elements.\n", n);
    printf("Average time taken for insertion sort: %lf seconds\n", time_taken);

    free(arr);
    

    return 0;
}
