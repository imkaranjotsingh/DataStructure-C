//Removing Dublicate From Double Linked Iist...
#include <stdio.h>
#include <stdlib.h>  
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};        
struct node *head, *tail = NULL;    
void addNode(int data) {  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
    if(head == NULL) {    
        head = tail = newNode;    
        head->previous = NULL;    
        tail->next = NULL;  
    }  
    else {    
        tail->next = newNode;    
        newNode->previous = tail;   
        tail = newNode;    
        tail->next = NULL;  
    }  
}    
void removeDuplicateNode() {    
    struct node *current, *index, *temp;    
    if(head == NULL) {  
        return;  
    }  
    else {    
        for(current = head; current != NULL; current = current->next) {    
            for(index = current->next; index != NULL; index = index->next) {  
                if(current->data == index->data) {    
                    temp = index;    
                    index->previous->next = index->next;  
                    if(index->next != NULL)  
                        index->next->previous = index->previous;    
                    temp = NULL;  
                }  
            }  
        }  
    }  
}  
  
void display() {    
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {    
        printf("%d ", current->data);  
        current = current->next;  
    }  
    printf("\n");  
}  
   
int main()  
{    
    addNode(1);  
    addNode(2);  
    addNode(3);  
    addNode(2);  
    addNode(2);  
    addNode(4);  
    addNode(5);  
    addNode(3);  
    printf("Originals list: \n");  
    display();    
    removeDuplicateNode(); 
    printf("List after removing duplicates: \n");  
    display();  
   
    return 0;  
}  
