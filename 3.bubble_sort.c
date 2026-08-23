//-----------BUBBLE SORT------------//

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

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {   int swapped=0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped=1;
            }
        }
        if (swapped==0)
        {
            break;
        }
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

    

    clock_t start = clock();

    
        bubbleSort(arr, n);
    
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC ;

    printf("Bubble sort completed for %d elements.\n", n);
    printf("Time taken for bubble sort: %lf seconds\n", time_taken);

    free(arr);
    

    return 0;
}
