//wap to Rev a string using Recursion..
#include<stdio.h>
#include<conio.h>
#include<string.h>
void retrn(int i,char s[10]){
	if(i){
		printf("%c",s[i-1]);
		retrn(i-1,s);
	}
}
int main(){
	char s[10] ="Hello";
	int a;
	puts(s);
	while(s[a] != '\0'){
		a++;
	}
	printf("%d\n",a);
	retrn(a,s);
	return 0;
}
