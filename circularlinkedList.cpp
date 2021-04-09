// Circular Linked List
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
void insert(node *pointer,int data){
	node *start = pointer;
	while(pointer->next != start){
		pointer = pointer -> next;
	}
	pointer->next = (node*)malloc(sizeof(node));
	pointer = pointer->next;
	pointer->data = data;
	pointer->next = start;
}
void print(node *start,node *pointer){
	if (pointer == start){
		return;
	}
	while(pointer != start){
		printf("%d",pointer->data);
		pointer = pointer -> next;
		printf("\t");
	}
}
int main(){
	node *start,*temp;
	start = (node *) malloc (sizeof(node));
	temp = start;
	temp -> next = NULL;
	while(1){
        int query;
        printf("1) INSERT\n");
    	printf("2) PRINT\n");
    	printf("3) EXIT\n");
        scanf("%d",&query);
        if(query==1){
            int data;
            scanf("%d",&data);
            insert(start,data);
        }
        else if(query==2){
            printf("The List is:");
            print(start,start->next);
            printf("\n");
        }
        else if(query == 3){
            break;
        }
    }
    return 0;
}
