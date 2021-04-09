			 //MERGING OF TWO STACKS
#include<conio.h>
#include<stdio.h>
#include<alloc.h>
#define max 3

int i;
typedef struct stack
  {
   int *N;
   int top;
  }stack;

void ask()
  {
   printf("Which stack do you want to use\n");
   printf("1. Stack 1\n");
   printf("2. Stack 2\n");
   scanf("%d",&i);
  }

void push(stack *s)
  {
   if(s->top==(max-1))
     {
      printf("Stack overflow");
      return;
     }
   printf("Enter an element\t");
   scanf("%d",&s->N[++s->top]);
  }

void pop(stack *s)
  {
   if(s->top==-1)
     {
      printf("Stack underflow");
      return;
     }
   printf("Poped element is %d",s->N[s->top--]);
  }

void show(stack *a1,stack *a2,stack *a3)
  {
   printf("Elements of stack 1 are :\n");
   for(i=0;i <= a1->top;i++)
     printf("%d\t",a1->N[i]);
   printf("\n\nElements of stack 2 are :\n");
   for(i=0;i <= a2->top;i++)
     printf("%d\t",a2->N[i]);
   printf("\n\nElements of stack 3 are :\n");
   for(i=0;i <= a3->top;i++)
     printf("%d\t",a3->N[i]);
  }

void merge(stack *a1,stack*a2,stack *a3)
  {
   a3->top=-1;
   for(i=0;i <= a1->top;i++)
     a3->N[++a3->top] = a1->N[i];
   for(i=0;i <= a2->top;i++)
     a3->N[++a3->top] = a2->N[i];
  }

void main()
{
stack s1,s2,s3;
s1.top=-1;
s1.N=(int*)malloc(sizeof(int)*max);
s2.top=-1;
s2.N=(int*)malloc(sizeof(int)*max);
s3.top=-1;
s3.N=(int*)malloc(sizeof(int)*(max+max));
while(1)
  {
   clrscr();
   printf("ENTER YOUR CHOICE :\n");
   printf("1. Push\n");
   printf("2. Pop\n");
   printf("3. Merge\n");
   printf("4. Show\n");
   printf("5. Exit\n");
   scanf("%d",&i);
   switch(i)
     {
      case 1:
	ask();
	if(i==1)
	  push(&s1);
	if(i==2)
	  push(&s2);
	break;
      case 2:
	ask();
	if(i==1)
	  pop(&s1);
	if(i==2)
	  pop(&s2);
	break;
      case 3:
	merge(&s1,&s2,&s3);
	break;
      case 4:
	show(&s1,&s2,&s3);
	break;
      case 5:
	exit(0);
     }
    getch();
  }
}