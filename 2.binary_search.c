//-----------BINARY SEARCH------------//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void generateRandomNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
}

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
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
    qsort(arr, n, sizeof(int), compare);

    // Select a random key from the array
    int randomIndex = rand() % n;
    int key = arr[randomIndex];

    // Display the key and its original index
    printf("\nKey selected for searching: %d\n", key);
    printf("Original index of key: %d\n", randomIndex);

    clock_t start = clock();

    int result;
    for (int i = 0; i < 1000; i++)
    {
        result = binarySearch(arr, n, key);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Key found at index: %d\n", result);
    printf("Average time taken for binary search in %d elements: %lf seconds\n",
           n, time_taken);

    free(arr);

    return 0;
}
