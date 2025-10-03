#include <stdio.h>
#define V 5
#define INF 9999

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };
    int dist[V], visited[V] = {0}, u, v, min;
    
    for (v = 0; v < V; v++) dist[v] = INF;
    dist[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        min = INF;
        for (v = 0; v < V; v++)
            if (!visited[v] && dist[v] < min) { min = dist[v]; u = v; }
        visited[u] = 1;
        for (v = 0; v < V; v++)
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Vertex\tDist\n");
    for (v = 0; v < V; v++) printf("%d\t%d\n", v, dist[v]);
    return 0;
}

