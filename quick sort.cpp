#include <stdio.h>

void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}

int partition(int a[],int l,int r){
    int p=a[r],i=l-1,j;
    for(j=l;j<r;j++){
        if(a[j]<=p){i++;swap(&a[i],&a[j]);}
    }
    swap(&a[i+1],&a[r]);
    return i+1;
}

void quicksort(int a[],int l,int r){
    if(l<r){
        int pi=partition(a,l,r);
        quicksort(a,l,pi-1);
        quicksort(a,pi+1,r);
    }
}

int main(){
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    printf("Sorted: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}

