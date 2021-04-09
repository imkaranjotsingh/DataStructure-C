//wap to Sum of Largest and smallest Value using linked list
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
int largest(node *pointer) 
{  
    int max = INT_MIN; 
    pointer = pointer->next;
    while (pointer != NULL) {  
        if (max < pointer->data) 
            max = pointer->data; 
        pointer = pointer->next; 
        printf("Max no is:%d\n",max);
    } 
    return max; 
} 
int smallest(node *pointer) 
{ 
    int min = INT_MAX; 
    while (pointer != NULL) {  
        if (min > pointer->data) 
            min = pointer->data; 
  
        pointer = pointer->next; 
        printf("Min No is:%d\n",min);
    } 
    return min; 
}
//	while(pointer->next != NULL){
//		if(largest > pointer->data)
//			largest = pointer->data;
//	}
//	printf("Largest Element in List is:%d\n",largest);
	//printf("smallest Element in List is:%d\n",smallest);
//	sum = largest+smallest;
//	printf("Sum of Largest and smallest Element in List is:%d\n",sum);
//}
int main(){
	node *start,*temp;
    start = (node *)malloc(sizeof(node));
    temp = start;
    temp->next = NULL;
    while(1){
        int query;
        printf("1) INSERT\n");
        printf("2) Sum Of Largest And Smallest Element\n");
    	printf("3) EXIT\n");
        scanf("%d",&query);
        if(query==1){
            int data;
            scanf("%d",&data);
            insert(start,data);
        }
        else if(query==2){
        	int a,b,sum=0;
        	a = largest(start);
        	b = smallest(start);
        	printf("Smallest No in List is:%d\n",b);
        	printf("Largest No in List is:%d\n",a);
        	sum = a+b;
        	printf("Sum :%d\n",sum);
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

