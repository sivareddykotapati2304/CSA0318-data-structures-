#include <stdio.h>
int main(){
	int arr[5]={1,2,3,4,5};
	int i,count=0,num=0;
	printf("even numbers:\n");
	for( i=0;i<5;i++){
		if(arr[i]%2==0){
			count++;
			printf("%d\n",arr[i]);
		}
	}
		printf("odd numbers:\n");
	for(i=0;i<5;i++){
	if(arr[i]%2!=0){
		num++;
			printf("%d\n",arr[i]);
		}
	}
	printf("no.of even numbers = %d\n",count);
	printf("no.of odd numbers = %d",num);
	return 0;
}

