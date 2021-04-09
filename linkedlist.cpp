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
int find(node *pointer,int key){
    //pointer = pointer->next;
    while(pointer!=NULL){
        if(pointer->data==key)
            return 1;
        pointer = pointer->next;
        
    }
    return 0;
}
void delet(node *pointer,int data){
	/*
    while(pointer != NULL && pointer->data != data){
        pointer = pointer->next;
    }
    if(pointer == NULL){
        printf("Element %d is not Present\n",data);
        return;
    }
    node *temp;
    temp = pointer->next;
    pointer->next = temp->next;
    free(temp);
    return;
    int pos, cnt = 0, i;
 
    if (first == NULL)
    {
        ISEMPTY;
        printf(":No node to delete\n");
    }
    else
    {
        printf("\nEnter the position of value to be deleted:");
        scanf(" %d", &pos);
        ptr = first;
        if (pos == 1)
        {
            first = ptr->next;
            printf("\nElement deleted");    
        }
        else 
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                cnt = cnt + 1;
            }
            if (pos > 0 && pos <= cnt)    
            {
                ptr = first;
                for (i = 1;i < pos;i++)
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
                prev->next = ptr->next;
            }
            else
            {
                printf("Position is out of range");
            }
        free(ptr);
        printf("\nElement deleted");
        }
    }*/
}
void print(node *pointer){
	if(pointer == NULL){
        	return;
    	}
	while(pointer != NULL){
    	printf("%d",pointer->data);
    	pointer = pointer->next;
    	printf("\t");
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
   		printf("2) DELETE\n");
    	printf("3) PRINT\n");
    	printf("4) FIND\n");
    	printf("5) EXIT\n");
        scanf("%d",&query);
        if(query==1){
            int data;
            scanf("%d",&data);
            insert(start,data);
        }
        if(query==2){
            int data;
            scanf("%d",&data);
            delet(start,data);
        }
        else if(query==3){
            printf("The List is:");
            print(start->next);
            printf("\n");
        }
        else if(query == 4){
            int data;
            scanf("%d",&data);
            int status = find(start,data);
            if(status)
                printf("Element Found!!!\n");
            else
                printf("Element Not Found!!!\n");
        }
        else if(query == 5){
            break;
        }
    }
    return 0;
}
