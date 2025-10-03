#include <stdio.h>
int func(int a){
    int i,fact=1;
    for(i=1;i<=a;i++){
       fact*=i; 
    }
    return fact;
}
int main(){
    int b=5;
    printf("%d ",func(b));
}
