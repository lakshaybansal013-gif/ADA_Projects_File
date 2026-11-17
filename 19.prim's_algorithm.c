
#include <stdio.h>

#define MAX 100
#define INF 1000000000

void prim(int graph[MAX][MAX], int V)
{
    int key[MAX], parent[MAX], visited[MAX];
    int totalCost = 0;

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++) {
        int min = INF;
        int u = -1;

        // Find unvisited vertex with minimum key
        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        // Check if graph is disconnected
        if (u == -1) {
            printf("Graph is disconnected. MST does not exist.\n");
            return;
        }

        visited[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != INF &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 1; i < V; i++) {
        printf("%d - %d : %d\n",
               parent[i], i, key[i]);

        totalCost += key[i];
    }

    printf("Minimum Cost = %d\n", totalCost);
}

int main()
{
    int V, E;
    int graph[MAX][MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || V > MAX || E < 0) {
        printf("Invalid graph size.\n");
        return 1;
    }

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    printf("Enter source, destination and weight:\n");

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid vertex.\n");
            return 1;
        }

        if (u != v) {
            if (w < graph[u][v]) {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }
    }

    prim(graph, V);

    return 0;
}
