#include<stdio.h>
#include<stdlib.h>

struct bst_node
{
int num;
struct bst_node *left, *right;
};

struct bst_node *bst_root;


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
if(num > t->num)
{
t=t->right;
}
}

t= (struct bst_node*)malloc(sizeof(struct bst_node));
t->num=num;
t->left=NULL;
t->right=NULL;

j=bst_root;
while(j)
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
		}
	}
}
printf("\nNumber %d added Successfully\n\n", num);
}


void remove_from_bst(int num)
{
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

void bst_inorder_traversal()
{
__bst_inorder_traversal(bst_root);
}

void bst_preorder_traversal()
{
//__bst_preorder_traversal(bst_root);
}

void bst_postorder_traversal()
{
//__bst_postorder_traversal(bst_root);
}

int main()
{
int ch , num;
bst_root = NULL;
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
printf("\n9. Exit");

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
else if(ch==9)
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
