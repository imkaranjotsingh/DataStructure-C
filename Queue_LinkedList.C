// QUEUE USING LINK LIST
#include<conio.h>
#include<stdio.h>
#include<alloc.h>

typedef struct Node Node;

struct Node{
	int info;
	Node *next;
};
void insert(Node **sr){
	Node *temp;	
	temp=(Node*)malloc(sizeof(Node));
	printf("Enter the element\t");
	scanf("%d",&temp->info);
	temp->next=NULL;
	if(*sr != NULL)
		(*sr)->next=temp;
	*sr=temp;
}
void show(Node *s){
	if(s==NULL){
		printf("Queue is empty");
		return;
	}
	while(s!=NULL){
		printf("%d\t",s->info);
		s=s->next;
	}
}
void deletes(Node **sf){
	Node *s;
	if((*sf)==NULL){
		printf("Queue is empty");
		return;
	}
	s=*sf;
	printf("Deleted element is %d",s->info);
	*sf=(*sf)->next;
	free(s);
}

void main(){
	int i;
	Node *front;
	Node *rear;
	front=NULL;
	rear=NULL;
	while(1){
		clrscr();
		printf("\n\t\t\t----QUEUE USING LINK LIST----\nEnter your choice\n1.Insert\n2.Delete\n3.Show\n4.Exit\n");
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
				if(front==NULL)
					rear=NULL;
				break;
			case 3:
				show(front);
				break;
			case 4:
				exit(0);
		}
	getch();
	}
}

































































