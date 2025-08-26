#include<stdio.h>
void linear_sort(int *, int);
void see_array(int *,int);
void bubble_sort(int *,int);
void selection_sort(int *,int);

int main()
{
int x[6] = {10,55,12,1,32,11};
int x_copy[6];
int length, ch;
length=6;
for(int i=0;i<length;i++)
{
x_copy[i] = x[i];
}
while(1)
{
printf("\n1. Bring Array to Unsorted State");
printf("\n2. Linear Sort using pointers");
printf("\n3. Bubble Sort using pointers");
printf("\n4. Selection Sort using pointers");
printf("\n5. See Array");
printf("\n6. Exit\n\n");

printf("Enter your choice: ");
scanf("%d", &ch);
if(ch==1)
{
for(int i=0;i<length;i++)
{
x[i] = x_copy[i];
}
}
else if(ch==2)
{
printf("\n____Array got Linear Sorted___\n");
linear_sort(x,length);
}
else if(ch==3)
{
printf("\n____Array got Bubble Sorted___\n");
bubble_sort(x,length);
}
else if(ch==4)
{
printf("\n____Array got Selection Sorted___\n");
selection_sort(x,length);
}
else if(ch==5)
{
see_array(x,length);
}
else if(ch==6)
{
break;
}
else 
{
printf("\nInvaid choice selected\n");
}
}

return 0;
}

void see_array(int *ba,int length)
{
for(int i=0;i<length;i++,ba++)
{
printf("%d\n", *ba);
}
}

void linear_sort(int *ba, int length)
{
int *buffer,*iep,*oep;
oep=ba+length;
while(ba!=oep)
{
iep=ba+1;
while(iep!=oep)
{
if(*iep<*ba)
{
*buffer=*ba;
*ba=*iep;
*iep=*buffer;
}
iep++;
}
ba++;
}
}

void bubble_sort(int *ba,int length)
{
int *oep, *iep,*buffer,*f;
f=ba;
oep=ba+length;
while(ba!=oep)
{
iep=ba+1;
while(iep!=oep)
{
if(*ba>*iep)
{
*buffer=*iep;
*iep=*ba;
*ba=*buffer;
}
iep++;
ba++;
}
ba=f;
oep--;
}
}

void selection_sort(int *ba, int length)
{
int *oep,*iep,*buffer,*sm;
oep=ba+length;
while(ba!=(oep-1))
{
iep=ba+1;
sm=ba;
while(iep!=oep)
{
if(*iep<*sm) sm=iep;
iep++;
}
*buffer=*ba;
*ba=*sm;
*sm=*buffer;
ba++;
}
}
