			    //STACK OF STACKS

#include<conio.h>
#include<stdio.h>
#define max 3

int i,j;
typedef struct stack
  {
   int arr[max];
   int arrcurpos;
  }stack;

struct queue
  {
   stack s1[max];
   int s1curpos;
  }s;

void push()
{
if(s.s1[s.s1curpos].arrcurpos==(max-1))
 {
  if(s.s1curpos==(max-1))
    {
     printf("Stack overflow");
     return;
    }
  s.s1curpos++;
  s.s1[s.s1curpos].arrcurpos=-1;
 }
printf("Enter the element\t");
scanf("%d",&s.s1[s.s1curpos].arr[++(s.s1[s.s1curpos].arrcurpos)]);
printf("%d %d ",s.s1curpos,s.s1[s.s1curpos].arrcurpos);
}

void pop()
{
if(s.s1[s.s1curpos].arrcurpos==-1 && s.s1curpos==0)
    {
     printf("Stack underflow");
     return;
    }
printf("The poped element is %d"
		    ,s.s1[s.s1curpos].arr[s.s1[s.s1curpos].arrcurpos--]);
if(s.s1[s.s1curpos].arrcurpos==-1 && s.s1curpos!=0)
 {
  s.s1[s.s1curpos].arrcurpos=(max-1);
  s.s1curpos--;
 }
}

void show()
{
if(s.s1[s.s1curpos].arrcurpos==-1 && s.s1curpos==0)
    {
     printf("Stack is empty");
     return;
    }
for(i=0;i<=s.s1curpos;i++)
  for(j=0;j!=s.s1[s.s1curpos].arrcurpos+1 && j<max;j++)
    printf("%d\t",s.s1[i].arr[j]);
}

void main()
{
s.s1curpos=0;
s.s1[s.s1curpos].arrcurpos=-1;
while(1)
  {
   clrscr();
   printf("Enter your choice\n");
   printf("1. Push\n");
   printf("2. Pop\n");
   printf("3. Show\n");
   printf("4. Exit\n");
   scanf("%d",&i);
   switch(i)
     {
      case 1:
	push();
	break;
      case 2:
	pop();
	break;
      case 3:
	show();
	break;
      case 4:
	exit();
     }
    getch();
  }
}




