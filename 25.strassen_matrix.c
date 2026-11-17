
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 128

void add(int n, int A[n][n], int B[n][n],
         int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[n][n], int B[n][n],
              int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n],
              int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int h = n / 2;

    int A11[h][h], A12[h][h], A21[h][h], A22[h][h];
    int B11[h][h], B12[h][h], B21[h][h], B22[h][h];

    int M1[h][h], M2[h][h], M3[h][h], M4[h][h];
    int M5[h][h], M6[h][h], M7[h][h];

    int S1[h][h], S2[h][h];

    int C11[h][h], C12[h][h];
    int C21[h][h], C22[h][h];

    // Divide matrices into four submatrices
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + h];
            A21[i][j] = A[i + h][j];
            A22[i][j] = A[i + h][j + h];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + h];
            B21[i][j] = B[i + h][j];
            B22[i][j] = B[i + h][j + h];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    add(h, A11, A22, S1);
    add(h, B11, B22, S2);
    strassen(h, S1, S2, M1);

    // M2 = (A21 + A22)B11
    add(h, A21, A22, S1);
    strassen(h, S1, B11, M2);

    // M3 = A11(B12 - B22)
    subtract(h, B12, B22, S2);
    strassen(h, A11, S2, M3);

    // M4 = A22(B21 - B11)
    subtract(h, B21, B11, S2);
    strassen(h, A22, S2, M4);

    // M5 = (A11 + A12)B22
    add(h, A11, A12, S1);
    strassen(h, S1, B22, M5);

    // M6 = (A21 - A11)(B11 + B12)
    subtract(h, A21, A11, S1);
    add(h, B11, B12, S2);
    strassen(h, S1, S2, M6);

    // M7 = (A12 - A22)(B21 + B22)
    subtract(h, A12, A22, S1);
    add(h, B21, B22, S2);
    strassen(h, S1, S2, M7);

    // Calculate the four result submatrices
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            C11[i][j] = M1[i][j] + M4[i][j]
                      - M5[i][j] + M7[i][j];

            C12[i][j] = M3[i][j] + M5[i][j];

            C21[i][j] = M2[i][j] + M4[i][j];

            C22[i][j] = M1[i][j] - M2[i][j]
                      + M3[i][j] + M6[i][j];
        }
    }

    // Combine the result submatrices
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < h; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + h] = C12[i][j];
            C[i + h][j] = C21[i][j];
            C[i + h][j + h] = C22[i][j];
        }
    }
}

int main()
{
    int n, size = 1;

    printf("Enter order of square matrices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid matrix size. Enter 1 to 128.\n");
        return 1;
    }

    // Find next power of 2
    while (size < n)
        size *= 2;

    int A[size][size], B[size][size], C[size][size];

    srand(1);

    // Initialize matrices
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            A[i][j] = (i < n && j < n) ? rand() % 10 : 0;
            B[i][j] = (i < n && j < n) ? rand() % 10 : 0;
        }
    }

    clock_t start = clock();

    strassen(size, A, B, C);

    clock_t end = clock();

    printf("\nResultant Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    double time_taken =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nExecution Time: %.6f seconds\n", time_taken);

    return 0;
}
