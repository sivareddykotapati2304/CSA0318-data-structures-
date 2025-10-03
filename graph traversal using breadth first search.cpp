#include <stdio.h>
#define MAX 20

int queue[MAX], f=-1, r=-1;

void enq(int v){ if(r<MAX-1) queue[++r]=(f==-1)?(f=0,v):v; }
int deq(){ return (f==-1)?-1:queue[f++]; }
int empty(){ return f==-1 || f>r; }

void BFS(int g[MAX][MAX], int n, int s){
    int visited[MAX]={0};
    enq(s); visited[s]=1;
    while(!empty()){
        int v=deq();
        printf("%d ",v);
        for(int i=0;i<n;i++)
            if(g[v][i] && !visited[i]) { enq(i); visited[i]=1; }
    }
}

int main(){
    int n,s;
    printf("Vertices: "); scanf("%d",&n);
    int g[MAX][MAX];
    printf("Adjacency matrix:\n");
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&g[i][j]);
    printf("Start vertex: "); scanf("%d",&s);
    printf("BFS: "); BFS(g,n,s);
}

