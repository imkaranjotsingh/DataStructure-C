#include<stdlib.h>
#include<stdio.h>
typedef struct node{
    int data;
    struct node *next;
}node;
node  *ptr;
node *first,*last;
void insert(node *pointer,int data){
    while(pointer->next != NULL){
        pointer = pointer->next;
    }
    pointer->next =(node*)malloc(sizeof(node));
    pointer = pointer->next;
    pointer->data = data;
    pointer->next = NULL;
}
void sort(node *pointer){
    int t;
    if (first == NULL)
	{
        printf(":No elements to sort\n");
    }
    else
    {
        for (pointer = first;pointer != NULL;pointer = pointer->next)
        {
            for (pointer = pointer->next;pointer != NULL;pointer = pointer->next)
            {
                if (pointer->data > pointer->data)
                {    
                    t = pointer->data;
                    pointer->data = pointer->data;
                    pointer->data = t;
                }
            }
        }
        printf("\n---Sorted List---");
        for (pointer = first;pointer != NULL;pointer = pointer->next)
        {
            printf("%d\t", pointer->data);
        }
    }
}
int main(){
	node *start,*temp;
    start = (node *) malloc(sizeof(node));
    temp = start;
    temp->next = NULL;
    while(1){
        int query;
        printf("1) INSERT\n");
   		printf("2) Sort\n");
   		printf("3) Exit\n");
        scanf("%d",&query);
        if(query==1){
        	int data;
            scanf("%d",&data);
            insert(start,data);
		}
		else if(query==2){
			printf("Sorting List in Accending Order!!!");
			sort(start);
		}
		else if(query==3){
			break;
		}
	}
	return 0;
}

