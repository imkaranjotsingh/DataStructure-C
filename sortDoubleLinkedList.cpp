#include<stdio.h>
02
#include<stdlib.h>
03
#include"list.h"
04
int i;
05
node *p;
06
node *n;
07
 
08
void insert(node *pointer, int data){
09
//go through list till ya find the last node
10
while(pointer->next!=NULL){
11
pointer = pointer->next;
12
}
13
//allocate memory for new node and put data in it
14
pointer->next = (node *)malloc(sizeof(node));
15
(pointer->next)->prev= pointer;
16
pointer = pointer->next;
17
pointer->data=data;
18
pointer->next = NULL;
19
}
20
void print(node *pointer){
21
if(pointer==NULL){
22
return;}
23
printf("%d ",pointer->data);
24
print(pointer->next);
25
}
26
 
27
int init(node *pointer,int find){
28
pointer =pointer->next;
29
while(pointer!=NULL){
30
if(pointer->data== find)//found find
31
{
32
printf("The data is in the list.");
33
return 1;
34
}
35
pointer = pointer->next;// Search in the next node.
36
}
37
//find is not found
38
printf("The data is not in the list.");
39
return 0;
40
}
41
void swap (node *x, node *y){
42
    int temp= x->data;
43
    x->data=y->data;
44
    y->data=temp;
45
}
46
void sort(node *pointer){
47
for(i=0;i<10;i++){
48
    if(pointer->data>pointer->next->data){
49
    }else{
50
        swap(pointer,pointer->next);
51
        }
52
        pointer=pointer->next;
53
    }
54
}
55
 
56
 
57
 
58
 
59
int main(){
60
//new is used to point to the first node
61
//temp is for the last node
62
node *new, *temp;
63
int z;
64
new=(node *)malloc(sizeof(node));
65
temp= new;
66
temp ->next = NULL;
67
temp ->prev = NULL;
68
 
69
for(z=0;z<10;z++){
70
insert(new,(3*10)-z);
71
}
72
init(new,12);
73
init(new,3);
74
init(new,27);
75
init(new,7);
76
print(new);
77
sort(new);
78
print(new);
79
 
80
}

