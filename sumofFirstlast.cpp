//wap to Sum of first and last Value using linked list
#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}node;
void insert(node *pointer,int data){
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next =(node*)malloc(sizeof(node));
    pointer = pointer->next;
    pointer->data = data;
    pointer->next = NULL;
}
void sum(node *pointer){
	int first=0,last=0,sum=0;
	pointer = pointer->next;
	first = pointer->data;
	while(pointer->next != NULL){
		pointer = pointer->next;
	}
	last = pointer->data;
	printf("first Element in List is:%d\n",first);
	printf("last Element in List is:%d\n",last);
	sum = first+last;
	printf("Sum of first and last Element in List is:%d\n",sum);
}
int main(){
	 node *start,*temp;
    start = (node *) malloc(sizeof(node));
    temp = start;
    temp->next = NULL;
    while(1){
        int query;
        printf("1) INSERT\n");
        printf("2) Sum Of First And Last Element\n");
    	printf("3) EXIT\n");
        scanf("%d",&query);
        if(query==1){
            int data;
            scanf("%d",&data);
            insert(start,data);
        }
        else if(query==2){
        	sum(start);
		}
		else if(query==3){
			break;
		}	
	}
}

