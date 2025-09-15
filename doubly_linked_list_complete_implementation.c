#include<stdio.h>
#include<stdlib.h>

void clear_stdin_buffer()
{
char m;
while(1)
{
m=getchar();
if(m=='\n') break;
}
}

struct node 
{
int num;
struct node *next;
struct node *previous;
};

struct node *start, *end;

void insert_at_top(int num)
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
t->num = num;
t->previous=NULL;
t->next=NULL;
if(start==NULL) 
{
start=t;
end=t;
}
else
{
t->next=start;
start->previous = t;
start = t;
}
}

void add_to_end(int num)
{
struct node *t;
if(start==NULL)
{
insert_at_top(num);
return;
}
t=(struct node *)malloc(sizeof(struct node));
t->num = num;
t->next=NULL;
t->previous=end;
end->next=t;
end=t;
}

int insert_at_pos(int num, int pos)
{
struct node *t, *p1;
int x;

if(pos<=1 || start==NULL)
{
insert_at_top(num);
return 1;
}
t=(struct node *)malloc(sizeof(struct node));
t->num = num;
t->next=NULL;
t->previous=NULL;

x=1;
p1 = start;
while(x<pos && p1!=NULL) 
{
p1 = p1->next; 
x++;
}
if(p1==NULL) // End mai add karna hai
{
end->next = t;
t->previous = end;
end=t;
}
else //insert beech mai krna hai just above node to which p1 is pointing to.
{
t->next = p1;
p1->previous->next=t;
t->previous = p1->previous;
p1->previous = t; 
}
return x;
}

int remove_from_position(int pos)
{
int x;
struct node *p1;

if(start==NULL)
{
printf("\n\nNo nodes or Data to be removed\n");
return 0;
}
if(pos<1) 
{
printf("\n\nInvalid position entered\n");
return 0;
}

x=1;
p1=start;
while(x<pos && p1!=NULL)
{
p1=p1->next;
x++;
}
if(p1==NULL)
{
printf("\n\nInvalid Position entered\n");
return 0;
}
if(start==p1 && end==p1) //matlab ek hi node hai
{
start=NULL;
end=NULL;
free(p1);
return x;
}
if(p1==start) //many nodes but remove 1st node
{
start=start->next;
start->previous=NULL;
free(p1);
return x;
}
if(p1==end) //many nodes but we need to remove last node
{
end=end->previous;
end->next=NULL;
free(p1);
return x;
}
//neither 1st node nor last node, some other middle pos needs to be removed
p1->next->previous = p1->previous;
p1->previous->next = p1->next;
free(p1);
return x;
}

void traverse_top_to_bottom()
{
struct node *t;
if(start==NULL) printf("\n____ No record while traversing from top to Bottom _____\n");
else
{
printf("\nThe doubly linked list from top to Bottom: ");
for(t=start; t != NULL; t=t->next) printf("%d ", t->num);
printf("\n\n");
}
}

void traverse_bottom_to_top()
{
struct node *t;
if(start==NULL || end==NULL) printf("\n____ No record while traversing from Bottom to top _____\n");
else
{
printf("\nThe doubly linked list from Bottom to top: ");
for(t=end; t!=NULL; t=t->previous) printf("%d ", t->num);
printf("\n\n");
}
}


int main()
{
int ch, pos, flag, num;
start = NULL;
end = NULL;
while(1)
{
printf("\n1. Add at End");
printf("\n2. Insert at top");
printf("\n3. Insert at Position");
printf("\n4. Remove from Position");
printf("\n5. Traverse top to bottom");
printf("\n6. Traverse bottom to top");
printf("\n7. Exit");

printf("\n\nEnter your choice: ");
scanf("%d", &ch);
clear_stdin_buffer();

if(ch==1)
{
printf("\nEnter the number ");
scanf("%d", &num);
clear_stdin_buffer();
add_to_end(num);
}
else if(ch==2)
{
printf("\nEnter the number: ");
scanf("%d", &num);
clear_stdin_buffer();
insert_at_top(num);
}
else if(ch==3)
{
printf("\nEnter the number: ");
scanf("%d", &num);
clear_stdin_buffer();
printf("\nEnter the Position: ");
scanf("%d", &pos);
clear_stdin_buffer();
pos = insert_at_pos(num,pos);
printf("\nThe number %d is inserted at position %d\n", num, pos);
}
else if(ch==4)
{
printf("\nEnter the Position: ");
scanf("%d", &pos);
clear_stdin_buffer();
flag=remove_from_position(pos);
if(flag == 0) printf("\nNos Not removed \n");
else printf("\nNos Removed from position %d\n",pos);
}
else if(ch==5)
{
traverse_top_to_bottom();
}
else if(ch == 6)
{
traverse_bottom_to_top();
}
else if(ch == 7)
{
break;
}
else
{
printf("\n\nInvalid Choice\n");
}
}
return 0;
}
