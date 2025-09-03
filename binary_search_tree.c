#include<stdio.h>
#include<stdlib.h>

struct bst_node;
struct stack_node;
struct queue_node;

void add_to_bst(int );
void remove_from_bst(int );
void __bst_inorder_traversal(struct bst_node *);
void __bst_preorder_traversal(struct bst_node *);
void __bst_postorder_traversal(struct bst_node *);
void bst_inorder_traversal();
void bst_preorder_traversal();
void bst_postorder_traversal();
void bst_inorder_traversal_no_reccursion();
void bst_preorder_traversal_no_reccursion();
void bst_postorder_traversal_no_reccursion();
void push(struct bst_node *);
struct bst_node * pop();
int isEmpty();
void bst_clear();
void __bst_clear(struct bst_node *);
void level_order_traversal();
void add_to_queue(struct bst_node *);
struct bst_node * remove_from_the_queue();
int is_queue_empty();

struct bst_node
{
int num;
struct bst_node *left, *right;
};
struct bst_node *bst_root;

struct stack_node
{
struct bst_node *addr;
struct stack_node *next;
};
struct stack_node *stack_top;

struct queue_node
{
struct bst_node *addr;
struct queue_node *next;
};
struct queue_node *queue_front;
struct queue_node *queue_rear;

void add_to_bst(int num)
{
struct bst_node *t, *j;
t=bst_root;
while(t!=NULL)
{
if(t->num == num)
{
printf("\n\nThis number already exist, Kindly enter a unique number\n\n");
return;
}
if(num < t->num)
{
t=t->left;
}
else
{
t=t->right;
}
}

t=(struct bst_node*)malloc(sizeof(struct bst_node));
t->num=num;
t->left=NULL;
t->right=NULL;

if(!bst_root)
{
bst_root = t;
}
else
{
j=bst_root;
while(1)
{

	if(t->num < j->num)
	{
		if(j->left)
		{
		 j=j->left;
		}
		else
		{
		 j->left=t;
		 break;
		}
	}

	if(t->num > j->num)
	{
		if(j->right)
		{
		 j=j->right;
		}
		else
		{
		 j->right = t;
		 break;
		}
	}
}
}
printf("\nNumber %d added Successfully\n\n", num);
}


void remove_from_bst(int num)
{
}


void bst_inorder_traversal()
{
if(!bst_root)
{
printf("\n\nNo data found in BST !\n\n");
return;
}
printf("\nInorder Traversal with recursion: ");
__bst_inorder_traversal(bst_root);
printf("\n\n");
}

void __bst_inorder_traversal(struct bst_node *root)
{
struct bst_node *t;
t=root;
if(t == NULL) return;
__bst_inorder_traversal(t->left);
printf("%d ", t->num);
__bst_inorder_traversal(t->right);
}

void bst_preorder_traversal()
{
if(!bst_root)
{
printf("\n\nNo data found in BST ! \n\n");
return;
}
printf("\nPreorder Traversal with recursion: ");
__bst_preorder_traversal(bst_root);
printf("\n\n");
}

void __bst_preorder_traversal(struct bst_node *root)
{
struct bst_node *t;
t=root;
if(t == NULL) return;
printf("%d ", t->num);
__bst_preorder_traversal(t->left);
__bst_preorder_traversal(t->right);
}

void bst_postorder_traversal()
{
if(!bst_root)
{
printf("\n\nNo data found in BST ! \n\n");
return;
}
printf("\nPostorder Traversal with recursion: ");
__bst_postorder_traversal(bst_root);
printf("\n\n");
}

void __bst_postorder_traversal(struct bst_node *root)
{
struct bst_node *t;
t=root;
if(t == NULL) return;
__bst_postorder_traversal(t->left);
__bst_postorder_traversal(t->right);
printf("%d ", t->num);
}

void bst_inorder_traversal_no_reccursion()
{
struct bst_node *t, *j;
t=bst_root;
while(t)
{
push(t);
t=t->left;
}

while(!isEmpty())
{
t = pop();
printf("%d ", t->num);
j=t->right;
while(j)
{
push(j);
j=j->left;
}
}

}

void push(struct bst_node *addr)
{
struct stack_node *j;
j= (struct stack_node *)malloc(sizeof(struct stack_node));
j->addr = addr;
j->next = stack_top;
stack_top=j;
}

struct bst_node * pop()
{
struct stack_node *t;
struct bst_node *addr;
if(!stack_top) return NULL ;
t=stack_top;
stack_top = stack_top->next;
addr = t->addr;  
free(t);
return addr;
}

int isEmpty()
{
return stack_top==NULL;
}


void bst_preorder_traversal_no_reccursion()
{
struct bst_node *t;
push(bst_root);
while(!isEmpty())
{
t=pop();
printf("%d ", t->num);
if(t->right) push(t->right);
if(t->left) push(t->left);
}
}

void bst_postorder_traversal_no_reccursion()
{
}

void bst_clear()
{
if(!bst_root) 
{
printf("\n\nAlready there is no data, Nothing to Clearup \n\n");
return;
}
__bst_clear(bst_root);
bst_root=NULL;
printf("\n\nWhole Tree is Successfully Deleted/Cleared\n\n");
}

void __bst_clear(struct bst_node *t)
{
if(t==NULL) return;
__bst_clear(t->left);
__bst_clear(t->right);
free(t);
}

void level_order_traversal()
{
int kitne_add_kare, ab_kitne_hai, n;
struct bst_node *t;
add_to_queue(bst_root);
kitne_add_kare=1;
while(!is_queue_empty())
{
ab_kitne_hai=0;
n=1;
while(n <= kitne_add_kare)
{
t=remove_from_the_queue();
printf("%d ", t->num);
if(t->left) add_to_queue(t->left);
ab_kitne_hai++;
if(t->right) add_to_queue(t->right);
ab_kitne_hai++;
n++;
}
kitne_add_kare = ab_kitne_hai;
}
}

int is_queue_empty()
{
return queue_front==NULL;
}

void add_to_queue(struct bst_node *addr)
{
struct queue_node *t;
t=(struct queue_node *)malloc(sizeof(struct queue_node));
t->addr = addr;
t->next=NULL;

if(!queue_front)
{
queue_front=t;
queue_rear=t;
return;
}
queue_rear->next = t;
queue_rear = t;
}

struct bst_node * remove_from_the_queue()
{
struct bst_node *t;
struct queue_node *j;
if(queue_front==NULL) return NULL;
j=queue_front;
t=queue_front->addr;
queue_front= queue_front->next;
if(queue_front==NULL) queue_rear = NULL;
free(j);
return t;
}

int main()
{
int ch , num;
bst_root = NULL;
stack_top = NULL;
queue_front = NULL;
queue_rear=NULL;
while(1)
{
printf("\n1. Add Node/data");
printf("\n2. Remove Node/data");
printf("\n3. Inorder traversal with Reccursion");
printf("\n4. Preorder traversal with Reccursion");
printf("\n5. Postorder traversal with Reccursion");
printf("\n6. Inorder traversal without Reccursion");
printf("\n7. Preorder traversal without Reccursion");
printf("\n8. Postorder traversal without Reccursion");
printf("\n9. Level Order Traversal");
printf("\n10. Clear the Tree");
printf("\n11. Exit");

printf("\nEnter your choice: ");
scanf("%d", &ch);

if(ch==1)
{
printf("\n\nEnter a number to add: ");
scanf("%d",&num);
add_to_bst(num);
}
else if(ch==2)
{
printf("\n\nEnter a number to remove: ");
scanf("%d",&num);
remove_from_bst(num);
}
else if(ch==3)
{
bst_inorder_traversal();
}
else if(ch==4)
{
bst_preorder_traversal();
}
else if(ch==5)
{
bst_postorder_traversal();
}
else if(ch==6)
{
if(!bst_root) 
{
printf("\n\nNo Data found in the BST\n\n");
continue;
}
printf("\nInorder Traversal without reccursion is: \n");
bst_inorder_traversal_no_reccursion();
printf("\n\n");
}
else if(ch==7)
{
if(!bst_root) 
{
printf("\n\nNo Data found in the BST\n\n");
continue;
}
printf("\nPreorder Traversal without reccursion is: \n");
bst_preorder_traversal_no_reccursion();
printf("\n\n");
}
else if(ch==8)
{
if(!bst_root) 
{
printf("\n\nNo Data found in the BST\n\n");
continue;
}
printf("\nPostorder Traversal without reccursion is: \n");
bst_postorder_traversal_no_reccursion();
printf("\n\n");
}
else if(ch==9)
{
if(!bst_root) 
{
printf("\n\nNo Data found in the BST\n\n");
continue;
}
level_order_traversal();
}
else if(ch==10)
{
bst_clear();
}
else if(ch==11)
{
break;
}
else
{
printf("\nInvalid Input, try again! \n");
}

}
return 0;
}
