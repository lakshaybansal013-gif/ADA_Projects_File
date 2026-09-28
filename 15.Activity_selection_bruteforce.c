//----------- ACTIVITY SELECTION - BRUTE FORCE ------------//

#include <stdio.h>

int isCompatible(int start[], int finish[], int selected[], int n)
{
    int lastFinish = -1;

    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            if (start[i] <= lastFinish)
            {
                return 0;
            }

            lastFinish = finish[i];
        }
    }

    return 1;
}

int countSelected(int selected[], int n)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            count++;
        }
    }

    return count;
}

void bruteForce(int start[], int finish[], int n,
                int index, int selected[], int *maxCount)
{
    // All activities have been considered
    if (index == n)
    {
        if (isCompatible(start, finish, selected, n))
        {
            int count = countSelected(selected, n);

            if (count > *maxCount)
            {
                *maxCount = count;
            }
        }

        return;
    }

    // Case 1: Do not select current activity
    selected[index] = 0;

    bruteForce(start, finish, n,
               index + 1, selected, maxCount);

    // Case 2: Select current activity
    selected[index] = 1;

    bruteForce(start, finish, n,
               index + 1, selected, maxCount);

    // Reset
    selected[index] = 0;
}

int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(start) / sizeof(start[0]);

    int selected[n];

    for (int i = 0; i < n; i++)
    {
        selected[i] = 0;
    }

    int maxCount = 0;

    bruteForce(start, finish, n,
               0, selected, &maxCount);

    printf("Maximum number of activities: %d\n", maxCount);

    return 0;
}