//----------- FIBONACCI USING TABULATION ------------//

#include <stdio.h>
#include <time.h>

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

    long long dp[100];

    // Base cases
    dp[0] = 0;

    if (n > 1)
        dp[1] = 1;

    clock_t start = clock();

    // Build the table from bottom to top
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("Fibonacci Series:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%lld ", dp[i]);
    }

    clock_t end = clock();

    double time_taken =
        ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n\nTime taken: %lf seconds\n", time_taken);

    return 0;
}