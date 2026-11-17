
#include <stdio.h>

#define MAX 100
#define INF 1000000000

struct Edge
{
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int V, int E, int source)
{
    int dist[MAX];

    // Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++)
    {
        int updated = 0;

        for (int j = 0; j < E; j++)
        {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                updated = 1;
            }
        }

        // Stop early if no distance changes
        if (!updated)
            break;
    }

    // Check for negative-weight cycle
    for (int i = 0; i < E; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        int w = edges[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            printf("\nGraph contains a negative weight cycle.\n");
            return;
        }
    }

    // Print shortest distances
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
    int V, E, source;
    struct Edge edges[MAX * MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || V > MAX || E < 0 || E > MAX * MAX)
    {
        printf("Invalid graph size.\n");
        return 1;
    }

    printf("Enter source, destination and weight:\n");

    for (int i = 0; i < E; i++)
    {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);

        if (edges[i].src < 0 || edges[i].src >= V ||
            edges[i].dest < 0 || edges[i].dest >= V)
        {
            printf("Invalid vertex.\n");
            return 1;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    if (source < 0 || source >= V)
    {
        printf("Invalid source vertex.\n");
        return 1;
    }

    bellmanFord(edges, V, E, source);

    return 0;
}
