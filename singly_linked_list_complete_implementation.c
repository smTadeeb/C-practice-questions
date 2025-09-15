#include<stdio.h>
#include<stdlib.h>

void add_node_at_end(int);
void insert_node_at_top(int);
int add_at_pos(int, int);
int remove_from_pos(int);
void traverse_top_to_bottom();
void traverse_bottom_to_top_using_stack();


struct node
{
int num;
struct node *next;
};

void traverse_bottom_to_top_using_recursion(struct node *);


void push(int num);
void pop();

int arr[60];
int top= -1;

void clear_stdin_buffer()
{
char m;
while(1)
{
m=getchar();
if(m == '\n') break;
}
}



struct node *start;

int main()
{
int num, ch, pos;
start=NULL;

while(1)
{
printf("\n__________ Singly Linked List __________");
printf("\n 1. Add node at end");
printf("\n 2. insert node at top");
printf("\n 3. Add node at pos");
printf("\n 4. Remove node");
printf("\n 5. Traverse Top to bottom");
printf("\n 6. Traverse bottom to top using stack");
printf("\n 7. Traverse bottom to top using recursion");


printf("\nEnter you choice: ");
scanf("%d", &ch);
clear_stdin_buffer();

if(ch==1) 
{
printf("\nEnter the Number to add: ");
scanf("%d", &num);
clear_stdin_buffer();
add_node_at_end(num);
}
else if(ch==2)
{
printf("\nEnter the Number to add: ");
scanf("%d", &num);
clear_stdin_buffer();
insert_node_at_top(num);
}
else if(ch==3)
{
printf("\nEnter the number to add: ");
scanf("%d", &num);
printf("\nEnter the position to add: ");
scanf("%d", &pos);
clear_stdin_buffer();
pos = add_at_pos(num,pos);
printf("\n%d added at postion %d", num,pos);
}
else if(ch==4)
{
printf("\nEnter the position to remove: ");
scanf("%d", &pos);
clear_stdin_buffer();
pos = remove_from_pos(pos);
printf("\nNumber removed from postion %d", pos);
}
else if(ch==5)
{
traverse_top_to_bottom();
}
else if(ch==6)
{
traverse_bottom_to_top_using_stack();
}
else if(ch==7)
{
traverse_bottom_to_top_using_recursion(start);
}
else
{
printf("\n\nInvaid Input choice\n");
}

}
return 0;
}

void add_node_at_end(int n)
{
struct node *t, *j;
t=(struct node *)malloc(sizeof(struct node));
t->num = n;
t->next = NULL;

if(start == NULL) 
{
start = t;
}
else
{
j=start;
while(j->next != NULL)
{
j=j->next;
}
j->next = t;
}
printf("\n Node Successfully added at end \n");
}

void insert_node_at_top(int n)
{
struct node *t;
t = (struct node *)malloc(sizeof(struct node));
t->next = start;
t->num = n;
start = t;

printf("\n Node Successfully added at Top \n");
}

int add_at_pos(int n, int pos)
{
int x;
struct node *t, *p1, *p2;
t= (struct node*)malloc(sizeof(struct node));
t->next = NULL;
t->num = n;

x=1;
if(start==NULL)
{
	start=t;
	return x;
}

if(pos<1)
{
printf("\nInvalid Position to add\n");
return 0;
}

if(pos==1)
{
t->next = start;
start=t;
return 1;
}

p1=start;
while(x<pos && p1 != NULL)
{
p2=p1;
p1=p1->next;
x++;
}

if(p1 == NULL)
{
p2->next = t;
return x;
}
else
{
t->next = p1->next;
p1->next = t;
}
return x;
}

int remove_from_pos(int pos)
{
int x;
struct node *p1, *p2;

if(start == NULL || pos<1) 
{
printf("\nNo Node in the List\n");
return 0;
}

x=1;
p1=start;
while(x<pos && p1!=NULL)
{
p2=p1;
p1=p1->next;
x++;
}

if(p1 == start)
{
start = start->next;
}
else
{
p2->next = p1->next;
}
free(p1);
return 1;
}

void traverse_top_to_bottom()
{
struct node *j;
if(start==NULL) 
{
printf("\nNo Node to Show\n");
return;
}
for(j=start;j != NULL; j= j->next)
{
printf("%d\n", j->num);
}
}



void traverse_bottom_to_top_using_stack()
{
struct node* j;
for(j=start; j!=NULL; j = j->next)
{
push(j->num);
}

for(int i=top; i>=0; i--)
{
pop();
}
}

void push(int num)
{
top++;
arr[top] = num;
}

void pop()
{
printf("%d\n", arr[top]);
top--;
}

void traverse_bottom_to_top_using_recursion(struct node *j)
{
if(j == NULL) return;
traverse_bottom_to_top_using_recursion(j->next);
printf("%d\n", j->num);
}
