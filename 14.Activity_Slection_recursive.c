//----------- ACTIVITY SELECTION - RECURSIVE ------------//

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

int activitySelectionRecursive(struct Activity arr[], int n, int index)
{
    // Find the next compatible activity
    int next = index + 1;

    while (next < n &&
           arr[next].start <= arr[index].finish)
    {
        next++;
    }

    // No more compatible activities
    if (next >= n)
    {
        return 1;
    }

    // Select current activity and recursively find others
    return 1 + activitySelectionRecursive(arr, n, next);
}

int activitySelection(int start[], int finish[], int n)
{
    struct Activity arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].finish = finish[i];
    }

    // Sort by finish time
    qsort(arr, n, sizeof(struct Activity), compare);

    return activitySelectionRecursive(arr, n, 0);
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