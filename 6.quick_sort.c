//-----------QUICK SORT------------//

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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
    int *temp = (int *)malloc(n * sizeof(int));

    if (arr == NULL || temp == NULL)
    {
        printf("Memory not allocated.\n");
        return -1;
    }

    srand(time(NULL));
    generateRandomNumber(arr, n);

    clock_t start = clock();

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j] = arr[j];
        }
        quickSort(temp, 0, n - 1);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Quick sort completed for %d elements.\n", n);
    printf("Average time taken for quick sort: %lf seconds\n", time_taken);

    free(arr);
    free(temp);

    return 0;
}
