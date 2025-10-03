#include <stdio.h>
#define V 5
#define E 7
int parent[V];
int find(int i){ return (parent[i]==i)?i:(parent[i]=find(parent[i])); }
void unionSet(int a,int b){ parent[find(a)]=find(b); }

int main(){
    int u[E]={0,0,1,1,1,2,3};
    int v[E]={1,3,2,3,4,4,4};
    int w[E]={2,6,3,8,5,7,9};
    int i,j;
    for(i=0;i<V;i++) parent[i]=i;
    for(i=0;i<E-1;i++)
        for(j=0;j<E-i-1;j++)
            if(w[j]>w[j+1]){
                int t=w[j]; w[j]=w[j+1]; w[j+1]=t;
                t=u[j]; u[j]=u[j+1]; u[j+1]=t;
                t=v[j]; v[j]=v[j+1]; v[j+1]=t;
            }

    printf("Edge\tWeight\n");
    for(i=0;i<E;i++){
        if(find(u[i])!=find(v[i])){
            printf("%d - %d\t%d\n",u[i],v[i],w[i]);
            unionSet(u[i],v[i]);
        }
    }
    return 0;
}

