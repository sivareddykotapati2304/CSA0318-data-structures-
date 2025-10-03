#include <stdio.h>
int main(){
    int b=5;
     int i,fact=1;
    for(i=1;i<=b;i++){
       fact*=i; 
}
printf("factorial of %d = %d",b,fact);
}
