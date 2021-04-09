// Wap to find accurance of each letter in a Char array
#include<stdio.h>
#include<conio.h>
int main(){
	int count=0;
	char ar[20]="Hello How Are You";
	for(int i=0;i<17;i++){
		printf("%c",ar[i]);
	}
	int space = 0; 
    for (int i = 0; ar[i]; i++){
        if (ar[i] != ' ') 
            ar[space++] = ar[i]; 
    }
    ar[space] = '\0'; 
	for(int i = 0; i<14;i++){
		for(int j = 0; j<14; j++){
				if(ar[i] == ar[j]){
					count++;
			}
		}
		printf("\n%c Accurs %d times.\n",ar[i],count);
		count = 0;
	}	
	return 0;
}
