//----------- FIBONACCI USING RECURSION ------------//

#include <stdio.h>
#include <time.h>

long long fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series:\n");

    clock_t start = clock();

    for (int i = 0; i < n; i++)
    {
        printf("%lld ", fib(i));
    }

    clock_t end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken: %lf seconds\n", time_taken);

    return 0;
}