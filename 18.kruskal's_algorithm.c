
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

int parent[100], rank[100];

int compare(const void *a, const void *b)
{
    struct Edge *e1 = (struct Edge *)a;
    struct Edge *e2 = (struct Edge *)b;

    return e1->weight - e2->weight;
}

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY)
        return;

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;
    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;
    else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
}

void kruskal(struct Edge edges[], int V, int E)
{
    int count = 0, totalCost = 0;

    qsort(edges, E, sizeof(struct Edge), compare);

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    printf("\nEdges in Minimum Spanning Tree:\n");

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v)) {
            printf("%d - %d : %d\n",
                   u, v, edges[i].weight);

            unionSets(u, v);

            totalCost += edges[i].weight;
            count++;
        }
    }

    if (count != V - 1)
        printf("Graph is disconnected. MST does not exist.\n");
    else
        printf("Minimum Cost = %d\n", totalCost);
}

int main()
{
    int V, E;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V <= 0 || V > 100 || E < 0) {
        printf("Invalid graph size.\n");
        return 1;
    }

    struct Edge edges[E > 0 ? E : 1];

    printf("Enter source, destination and weight:\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edges[i].src,
              &edges[i].dest,
              &edges[i].weight);

        if (edges[i].src < 0 || edges[i].src >= V ||
            edges[i].dest < 0 || edges[i].dest >= V) {
            printf("Invalid vertex.\n");
            return 1;
        }
    }

    kruskal(edges, V, E);

    return 0;
}
