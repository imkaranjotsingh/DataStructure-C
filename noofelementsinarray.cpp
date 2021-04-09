//Wap to find No of accurence of each Element in Array
#include<stdio.h>
#include<conio.h>
int main(){
	int ar[10] = {1,3,2,1,5,4,7,6,8,7};
	int i,j,count=0;
	for(i = 0; i<10; i++){
		printf("%d\t",ar[i]);
	}
	for(i=0; i<10; i++){
		for(j=0; j<10; j++){
			if(ar[i] == ar[j])
				count++;
		}
		printf("\n%d No Accured %d Times.\n",ar[i],count);
		count = 0;
	}
	return 0;	
}
