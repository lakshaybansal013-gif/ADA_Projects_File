
#include <stdio.h>
#include <string.h>

#define MAX 1000

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void LCS(char X[], char Y[])
{
    int m = strlen(X);
    int n = strlen(Y);

    int dp[MAX + 1][MAX + 1];

    // Initialize first row and column
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Build the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
        }
    }

    // Length of LCS
    int length = dp[m][n];

    // Reconstruct the LCS
    char lcs[MAX + 1];
    lcs[length] = '\0';

    int i = m, j = n, index = length - 1;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index] = X[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Display results
    printf("\nLength of LCS = %d\n", length);
    printf("Longest Common Subsequence = %s\n", lcs);
}

int main()
{
    char X[MAX + 1], Y[MAX + 1];

    printf("Enter first string: ");
    scanf("%1000s", X);

    printf("Enter second string: ");
    scanf("%1000s", Y);

    LCS(X, Y);

    return 0;
}
