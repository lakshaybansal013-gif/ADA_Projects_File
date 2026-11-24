
#include <stdio.h>

#define INF 9999

int main()
{
    int n, graph[10][10];
    int visited[10] = {0};
    int edges = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while (edges < n - 1)
    {
        int min = INF;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && graph[i][j] < min)
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1)
        {
            printf("MST does not exist.\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);

        cost += min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}
