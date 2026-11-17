
#include <stdio.h>
#include <limits.h>

#define MAX 100

int m[MAX][MAX];
int split[MAX][MAX];

void printOptimalParenthesis(int i, int j)
{
    if (i == j)
    {
        printf("A%d", i);
        return;
    }

    printf("(");
    printOptimalParenthesis(i, split[i][j]);
    printOptimalParenthesis(split[i][j] + 1, j);
    printf(")");
}

void matrixChainMultiplication(int p[], int n)
{
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++)
            {
                long long cost = (long long)m[i][k]
                    + m[k + 1][j]
                    + (long long)p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = (int)cost;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("\nMinimum number of multiplications = %d\n",
           m[1][n]);

    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n);
    printf("\n");
}

int main()
{
    int n, p[MAX];

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    if (n <= 0 || n >= MAX)
    {
        printf("Invalid number of matrices.\n");
        return 1;
    }

    printf("Enter %d dimensions:\n", n + 1);

    for (int i = 0; i <= n; i++)
        scanf("%d", &p[i]);

    for (int i = 0; i <= n; i++)
    {
        if (p[i] <= 0)
        {
            printf("Dimensions must be positive.\n");
            return 1;
        }
    }

    matrixChainMultiplication(p, n);

    return 0;
}
