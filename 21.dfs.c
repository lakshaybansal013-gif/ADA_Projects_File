
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];

void DFS(int vertex, int n)
{
    visited[vertex] = 1;

    printf("%d ", vertex);

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i, n);
        }
    }
}

int main()
{
    int n, edges, u, v, start;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start, n);

    return 0;
}
