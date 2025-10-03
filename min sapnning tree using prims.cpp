#include <stdio.h>
#define V 5
#define INF 9999

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int parent[V], key[V], visited[V] = {0};
    int i, u, v, min;

    for (i = 0; i < V; i++) key[i] = INF;
    key[0] = 0; parent[0] = -1;

    for (i = 0; i < V - 1; i++) {
        min = INF;
        for (v = 0; v < V; v++)
            if (!visited[v] && key[v] < min) { min = key[v]; u = v; }
        visited[u] = 1;
        for (v = 0; v < V; v++)
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printf("Edge\tWeight\n");
    for (i = 1; i < V; i++)
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    return 0;
}

