//Queue Using LinkList
#include<stdio.h>
#include<stdlib.h>
typedef struct Node Node;

struct Node{
	int info;
	Node *next;
};
void insert(Node **sr){
	Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	printf("Enter The element\t");
	scanf("%d",temp->info);
	if(*sr != NULL){
		(*sr)->next = temp;	
	}
	*sr = temp;
}
void show(Node *s){
	if(s==NULL){
		printf("Queue is Empty!!!!\n");
		return;	
	}
	while(s != NULL){
		printf("%d\t",s->info);
		s = s->next;
	}
}
void deletes(Node **sf){
	Node *s;
	if((*sf)==NULL){
		printf("Queue is empty");
		return;
	}
	s = *sf;
	printf("Deleted element is %d ",s->info);
	*sf = (*sf)->next;
	free(s);
}
int main(){
	int i;
	Node *front;
	Node *rear;
	front = NULL;
	rear = NULL;
	while(1){
		printf("\n\t\t-------QUEUE USING LINKED LIST------\nEnter your choice:\n1.Insert\n2.Delete\n3.Show\n4.Exit\n");
		scanf("%d",&i);
		switch(i){
			case 1:
				if(front==NULL)
					i=1000;
				insert(&rear);
				if(i==1000)
					front=rear;
				break;
			case 2:
				deletes(&front);
				if(front == NULL)
					rear = NULL;
				break;
			case 3:
				show(front);
				break;
			case 4:
				exit(0);
				
		}
		return 0;
	}
}




















