#include <stdio.h>

void merge(int a[], int l, int m, int r) {
    int i=l, j=m+1, k=0, b[r-l+1];
    while(i<=m && j<=r) b[k++] = (a[i]<a[j]) ? a[i++] : a[j++];
    while(i<=m) b[k++] = a[i++];
    while(j<=r) b[k++] = a[j++];
    for(i=0;i<k;i++) a[l+i]=b[i];
}

void sort(int a[], int l, int r) {
    if(l<r) {
        int m=(l+r)/2;
        sort(a,l,m);
        sort(a,m+1,r);
        merge(a,l,m,r);
    }
}

int main() {
    int n,i;
    printf("Enter n: ");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,0,n-1);
    printf("Sorted: ");
    for(i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}

