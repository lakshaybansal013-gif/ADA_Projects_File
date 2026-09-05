//----------- FIBONACCI USING MEMOIZATION ------------//

#include <stdio.h>
#include <time.h>

long long dp[100];

long long fib(int n)
{
    // Base case
    if (n <= 1)
        return n;

    // Return already calculated value
    if (dp[n] != -1)
        return dp[n];

    // Calculate and store the result
    dp[n] = fib(n - 1) + fib(n - 2);

    return dp[n];
}

int main()
{
    int n;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    if (n <= 0 || n > 90)
    {
        printf("Please enter a value between 1 and 90.\n");
        return 0;
    }

    // Initialize dp array
    for (int i = 0; i < n; i++)
    {
        dp[i] = -1;
    }

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