#include<stdio.h>

struct bst_node
{
int num;
struct bst_node *left, *right;
};


void add_to_bst(int num)
{
struct bst_node *t;
t=(struct bst_node *)malloc(sizeof(struct bst_node));



t->num=num;
t->left=NULL;
t->right=NULL;
}


int main()
{
int ch num;
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
