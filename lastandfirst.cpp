#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node *next;
}node;
struct node *head;
void insert(int item){
    struct node *temp,*pointer;
	pointer =(struct node*)malloc(sizeof(struct node));
    if(pointer == NULL)
    	printf("\nOVERFLOW!!!");
    else{
    	pointer->data = item;
    	if(head == NULL){
    		printf("\nHead Is NULL!!\n");
    		pointer->next = NULL;
    		head = pointer;
    		printf("\nNode Inserted\n");
		}
		else{
			temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = pointer;
			pointer->next = NULL;
			printf("\nNode Inserted!!!!!\n");
		}
    }
}
int search(int item)  {  
    struct node *pointer;  
    int i=0,flag;  
    pointer = head;          
    while (pointer != NULL){  
        if(pointer->data == item){  
            printf("item found at location %d \n",i+1);
			return i;  
            flag=0;  
        }   
        else{  
            flag=1;  
        }  
        i++;  
        pointer = pointer->next;
		if(flag==1){  
            printf("Item not found\n");  
        }   
    }
	//printf("\nLocation :%d\n",i);         
}  
void del(int loc){
	struct node *pointer,*pointer1;
	int i;
	pointer = head;
	for(i = 0 ; i < loc ; i++){
		pointer1 = pointer;
		pointer = pointer->next;
		if(pointer == NULL){
			printf("\nCan't Delete!!!\n");
			return;
		}
	}
	pointer1->next = pointer->next;
	free(pointer);
	//printf("\nNode Deleted At %d location",loc);
	
}
void printdata(){  
    struct node *pointer;  
    pointer = head;   
    if(pointer == NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values . . . . .\n");   
        while (pointer != NULL)  
        {  
            printf("\n%d",pointer->data);  
            pointer = pointer->next;  
        }  
    }  
}     
void printList(int small,int greatest){
	struct node *pointer,*lastnode,*temp;
	pointer = head;
	lastnode = head;
	//printdata();
	pointer = (struct node*)malloc(sizeof(struct node)); 
	if(pointer == NULL){
		printf("OVERFLOW!!!");
	}
	pointer->data = small;
	pointer->next = head;
	head = pointer;
	printf("\n Node Inserted smallest!!!\n");
	//printdata();
    lastnode =(struct node*)malloc(sizeof(struct node));
    lastnode->data = greatest;
	temp = head;
    while(temp->next != NULL){
    	temp = temp->next;
	}
	temp->next = lastnode;
	lastnode->next = NULL;
	printf("\nNode Inderted at Last!!!\n");
	printf("\n");	
	printdata();
}
int largest(){
	struct node *temp;
	temp = head;  
    int max = INT_MIN; 
    //temp = temp->next;
    while (temp != NULL) {  
        if (max < temp->data) 
            max = temp->data; 
        temp = temp->next; 
       // printf("Max no is:%d\n",max);
    } 
    return max; 
} 
int smallest(){
	struct node *temp;
	temp = head; 
    int min = INT_MAX; 
    while (temp != NULL) {  
        if (min > temp->data) 
            min = temp->data; 
        temp = temp->next; 
        //printf("Min No is:%d\n",min);
    } 
    return min; 
}

int main(){
    while(1){
        int query;
        printf("\n1) INSERT\n");
        printf("\n2) Smallest element at First Largest Element at End\n");
    	printf("\n3) EXIT\n");
        scanf("%d",&query);
        if(query==1){
            int data;
            scanf("%d",&data);
            insert(data);
        }
        else if(query==2){
        	int a,b,sum=0,locA,locB;
        	a = largest();
        	b = smallest();	
        	locA = search(a);
        	printf("\n Location of Largest:%d\n",locA);
        	del(locA);
        	locB = search(b);
        	printf("\n Location of Smallest:%d\n",locB);
        	del(locB);
        	printList(b,a);
		}
		else if(query==3){
			break;
		}
		else{
			printf("Input a Valid Number!!!!!\n");
		}	
	}
	return 0;
}

