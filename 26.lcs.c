

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void LCS(char X[], char Y[])
{
    int m = strlen(X);
    int n = strlen(Y);

    int (*dp)[n + 1] = malloc((m + 1) * sizeof(*dp));

    if (dp == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for (int j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Build DP table
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

    int length = dp[m][n];

    char lcs[length + 1];
    lcs[length] = '\0';

    int i = m, j = n;
    int index = length - 1;

    // Reconstruct LCS
    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index--] = X[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\nLength of LCS = %d\n", length);
    printf("Longest Common Subsequence = %s\n", lcs);

    free(dp);
}

int main()
{
    char X[1001], Y[1001];

    printf("Enter first string: ");
    scanf("%1000s", X);

    printf("Enter second string: ");
    scanf("%1000s", Y);

    LCS(X, Y);

    return 0;
}
