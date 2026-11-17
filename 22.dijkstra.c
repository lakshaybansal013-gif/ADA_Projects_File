
#include <stdio.h>

#define MAX 100
#define INF 1000000000

void dijkstra(int graph[MAX][MAX], int V, int source)
{
    int dist[MAX], visited[MAX];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Find shortest paths
    for (int count = 0; count < V - 1; count++)
    {
        int min = INF;
        int u = -1;

        // Find unvisited vertex with minimum distance
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Display shortest distances
    printf("\nVertex\tShortest Distance from Source\n");

    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INF)
            printf("%d\tUnreachable\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int V, E;
    int graph[MAX][MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || V > MAX || E < 0)
    {
        printf("Invalid graph size.\n");
        return 1;
    }

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    printf("Enter source, destination and weight:\n");

    for (int i = 0; i < E; i++)
    {
        int u, v, w;

        scanf("%d %d %d", &u, &v, &w);

        if (u < 0 || u >= V || v < 0 || v >= V || w < 0)
        {
            printf("Invalid edge or negative weight.\n");
            return 1;
        }

        // Undirected graph
        if (w < graph[u][v])
        {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }

    int source;

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= V)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }

    dijkstra(graph, V, source);

    return 0;
}
