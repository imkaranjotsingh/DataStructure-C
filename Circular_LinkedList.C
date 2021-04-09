			 // CIRCULAR LINK LIST

#include<conio.h>
#include<stdio.h>
#include<alloc.h>

typedef struct Node Node;

struct Node
{
int info;
Node *next;
};

void insert(Node **s1)
{
Node *temp,*s;
s=*s1;
temp=(Node*)malloc(sizeof(Node));
printf("Enter an element\t");
scanf("%d",&temp->info);
temp->next=*s1;
if(*s1==NULL)
  {
   *s1=temp;
   temp->next=*s1;
   return;
  }
while(s->next!=*s1)
  s=s->next;
s->next=temp;
}

void show(Node **s1)
{
Node *s;
if(*s1==NULL)
  {
   printf("List is empty");
   return;
  }
s=*s1;
while(s->next!=*s1)
  {
   printf("%d\t",s->info);
   s=s->next;
  }
printf("%d\t",s->info);
}

void deletes(Node **s1)
{
int ele;
Node *s;
printf("Enter the element to delete\t");
scanf("%d",&ele);
if((*s1)->info == ele)
  {
   if(*s1!=(*s1)->next)
      *s1=(*s1)->next;
   else
      *s1=NULL;
  }
else
  {
   s=*s1;
   while(s->next!=*s1)
     {
      if(s->next->info == ele)
	{
	 s->next = s->next->next;
	 break;
	}
      s=s->next;
     }
  }
}

int main()
{
int i;
Node *root;
root=NULL;
while(1)
  {
   clrscr();
   printf("\t\t\t----CIRCULAR LINK LIST----\nEnter your choice\n1.Insert\n2.Show\n3.Delete\n4.Exit\n");
   scanf("%d",&i);
   switch(i)
     {
      case 1:
	insert(&root);break;
      case 2:
	show(&root);break;
      case 3:
	deletes(&root);break;
      case 4:
	
     }
   getch();
  }
}






















































