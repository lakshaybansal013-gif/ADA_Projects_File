//----------- ACTIVITY SELECTION - ITERATIVE ------------//

#include <stdio.h>
#include <stdlib.h>

struct Activity
{
    int start;
    int finish;
};

int compare(const void *a, const void *b)
{
    struct Activity *x = (struct Activity *)a;
    struct Activity *y = (struct Activity *)b;

    return x->finish - y->finish;
}

int activitySelection(int start[], int finish[], int n)
{
    struct Activity arr[n];

    // Store activities
    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].finish = finish[i];
    }

    // Sort according to finish time
    qsort(arr, n, sizeof(struct Activity), compare);

    int count = 1;
    int j = 0;

    // Select compatible activities
    for (int i = 1; i < n; i++)
    {
        if (arr[i].start > arr[j].finish)
        {
            count++;
            j = i;
        }
    }

    return count;
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start) / sizeof(start[0]);

    printf("Maximum number of activities: %d\n",
           activitySelection(start, finish, n));

    return 0;
}