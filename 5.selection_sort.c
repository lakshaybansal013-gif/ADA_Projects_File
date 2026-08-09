//-----------SELECTION SORT------------//

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

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
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
        selectionSort(temp, n);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Selection sort completed for %d elements.\n", n);
    printf("Average time taken for selection sort: %lf seconds\n", time_taken);

    free(arr);
    free(temp);

    return 0;
}
