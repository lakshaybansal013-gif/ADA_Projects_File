//----------- FIBONACCI USING ITERATION ------------//

#include <stdio.h>
#include <time.h>

int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Please enter a positive number.\n");
        return 0;
    }

    long long a = 0, b = 1, next;

    printf("Fibonacci Series:\n");

    clock_t start = clock();

    for (int i = 0; i < n; i++)
    {
        printf("%lld ", a);

        next = a + b;
        a = b;
        b = next;
    }

    clock_t end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken: %lf seconds\n", time_taken);

    return 0;
}