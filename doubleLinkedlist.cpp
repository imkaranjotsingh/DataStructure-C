#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *pre;
	int data;
	struct node *next;
};
struct node *head;
void insert_begining();
void insert_last();
void insert_specific();
void deletion_begining();
void deletion_last();
void deletion_specific();
void search();
void display();
int main(){
	int choice = 0;
	 while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert_begining();  
            break;  
            case 2:  
                    insert_last();  
            break;  
            case 3:  
            insert_specific();  
            break;  
            case 4:  
            deletion_begining();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specific();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}
void insert_begining(){
	struct node *ptr;
	int item;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("\nOVERFLOW!!!!!");
	}
	else{
		printf("\nEnter Item Value");
		scanf("%d",&item);
		
		if (head == NULL){
			ptr->next = NULL;
			ptr->pre = NULL;
			ptr->data = item;
			head = ptr;
		}
		else{
			ptr->data = item;
			ptr->pre = NULL;
			ptr->next = head;
			head->pre = ptr;
			head = ptr;
		}
		printf("\nNode Inserted\n");
	}
}
void insert_last(){
	struct node *ptr,*temp;
	int item;
	ptr = (struct node*)malloc(sizeof(struct node));
	if (ptr == NULL){
		printf("\nOVERFLOW!!!!!!");
	}
	else{
		printf("\nEnter Value:");
		scanf("%d",&item);
		ptr->data = item;
		if(head == NULL){
			ptr->next = NULL;
			ptr->pre = NULL;
			ptr->data = item;
		}
		else{
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->pre = temp;
			ptr->next = NULL;
		}
	}
	printf("\nNode Inserted!!!!!!\n");
}
void insert_specific(){
	struct node *ptr,*temp;
	int item,loc,i;
	ptr = (struct node*)malloc(sizeof(struct node));
	if(ptr == NULL){
		printf("\nOVERFLOW!!!!!!\n");
	}
	else{
		temp = head;
		printf("Enter The location:");
		scanf("%d",&loc);
		for(i = 0; i<loc;i++){
			temp = temp->next;
			if(temp == NULL){
				printf("There Are less then %d elements",loc);
				return;
			}
		}
		printf("Enter Value:");
		scanf("%d",&item);
		ptr->data = item;
		ptr->next = temp->next;
		ptr->pre = temp;
		temp->next = ptr;
		temp->next->pre = ptr;
		printf("\nNode Inserted!!!!!\n");
	}
}
void deletion_begining(){
	struct node *ptr;
	if(head == NULL){
		printf("\n UNDERFLOW!!!!!!");
	}
	else if(head->next == NULL){
		head = NULL;
		free(head);
		printf("\nNode Deleted!!!!!!\n");
	}
	else{
		ptr = head;
		head = head -> next;
		head->pre = NULL;
		free(ptr);
		printf("\nNode Deleted!!!!!!\n");
	}
}

void deletion_last(){
    struct node *ptr;  
    if(head == NULL){  
        printf("\n UNDERFLOW!!!!!!!!!!!!!!");  
    }  
    else if(head->next == NULL){  
        head = NULL;   
        free(head);   
        printf("\nnode deleted!!!!!!!!!!\n");  
    }  
    else{  
        ptr = head;   
        while(ptr->next != NULL){  
            ptr = ptr -> next;   
        }
        ptr -> pre -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted!!!!!!!!!\n");  
    }
}
void deletion_specific(){
	struct node *ptr,*temp;
	int val;
	printf("\nEnter the data after the node is to be Deleted:");
	scanf("%d",&val);
	ptr = head;
	while(ptr->data != val){
		ptr = ptr->next;
	}
	if(ptr->next == NULL){
		printf("\n Cannot Delete!!!!!!\n");
	}
	else if(ptr->next->next == NULL){
		ptr->next = NULL;
	}
	else{
		temp = ptr->next;
		ptr->next = temp->next;
		temp->next->pre = ptr;
		free(temp);
		printf("\nNode Deleted!!!!!!!\n");
	}
}
void display(){
	struct node *ptr;
	printf("\nPrinting Values...........\n");
	ptr = head;
	while(ptr != NULL){
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	}
}
void search(){
	struct node *ptr;
	int item,i=0,flag;
	ptr = head;
	if(ptr == NULL){
		printf("\nEmpty List....\n");
	}
	else{
		printf("\nEnter item which you want to search:\n");
		scanf("%d",&item);
		while(ptr != NULL){
			if(ptr->data == item){
				printf("\nItem Found At Location %d ",i+1);
				flag = 0;
				break;
			}
			else{
				flag = 1;
			}
			i++;
			ptr = ptr->next;
		}
		if(flag == 1){
			printf("\nItem Not Found!!!!!!!!!\n");
		}
	}
}
