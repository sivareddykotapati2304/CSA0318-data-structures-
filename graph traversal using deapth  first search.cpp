#include <stdio.h>

#define MAX 20

int visited[MAX];

void DFS(int g[MAX][MAX], int n, int v){
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++)
        if(g[v][i] && !visited[i])
            DFS(g, n, i);
}

int main(){
    int n, start;
    printf("Vertices: "); scanf("%d", &n);
    int g[MAX][MAX];
    printf("Adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    for(int i = 0; i < n; i++) visited[i] = 0;
    printf("Start vertex: "); scanf("%d", &start);
    printf("DFS: ");
    DFS(g, n, start);
}

