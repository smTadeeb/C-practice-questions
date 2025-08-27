#include<stdio.h>
void linear_sort(int *, int);
void see_array(int *,int);
void bubble_sort(int *,int);
void selection_sort(int *,int);
void insertion_sort(int *,int);
void quick_sort(int *,int,int);
int find_partition_point(int *, int , int );


int main()
{
int x[6];

int x_copy[6];
int length, ch;
length=6;

for(int i=0;i<length;i++)
{
printf("\nEnter the %d index number: ",i);
scanf("%d", &x[i]);
}

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
printf("\n5. Insertion Sort using pointers");
printf("\n6. Quick Sort using pointers");
printf("\n7. See Array");
printf("\n8. Exit\n\n");

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
printf("\n____Array got Linear Sorted___\n\n");
linear_sort(x,length);
}
else if(ch==3)
{
printf("\n____Array got Bubble Sorted___\n\n");
bubble_sort(x,length);
}
else if(ch==4)
{
printf("\n____Array got Selection Sorted___\n\n");
selection_sort(x,length);
}
else if(ch==5)
{
printf("\n____Array got Insertion Sorted___\n\n");
insertion_sort(x,length);
}
else if(ch==6)
{
printf("\n____Array got Quick Sorted___\n\n");
quick_sort(x,0,length-1);
}
else if(ch==7)
{
see_array(x,length);
}
else if(ch==8)
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

void insertion_sort(int *ba, int length)
{
int *oep, *iep, *dimag, *bac;
int dimag_save;
dimag = ba+1;
oep = ba+length;
iep = ba-1;
	while(dimag!=oep)
	{

		dimag_save=*dimag;
		bac = dimag-1;
		while(bac != iep)
		{
			if(*bac<= dimag_save)
			{
				*(bac+1)= dimag_save;
				break;
			}
			*(bac+1)=*bac;
			bac--;
		}
	if(bac == iep)  *(bac+1)= dimag_save;
	//printf("\nDimag mai saved nos is: \n%d", dimag_save);
	dimag++;
	}
}

/* //Insertion Sort with for loop 
void insertion_sort(int *ba, int length)
{
int *oep, *iep, *dimag, *bac;
int dimag_save;
	for(dimag = ba+1, oep = ba+length, iep = ba-1;  dimag!=oep;  dimag++)
	{
		for(dimag_save=*dimag, bac = dimag-1; bac != iep; *(bac+1)=*bac, bac--)
		{
			if(*bac<= dimag_save)
			{
				*(bac+1)= dimag_save;
				break;
			}
		}
	if(bac == iep)  *(bac+1)= dimag_save;
	}
}
*/

int find_partition_point(int *ba, int lb, int ub)
{
int e,f,g;
e=lb;
f=ub;
while(1)
{
while(ba[e]<=ba[lb] && e<ub) e++; 
while(ba[f]>ba[lb]) f--; 
if(e<f)
{
g=ba[e];
ba[e]=ba[f];
ba[f]=g;
}
else
{
g=ba[lb];
ba[lb]=ba[f];
ba[f]=g;
break;
}
}
return f;
}

void quick_sort(int *ba, int lb, int ub)
{
int partition_point;
if(lb>=ub) return;
partition_point = find_partition_point(ba,lb,ub);
quick_sort(ba,lb,partition_point-1);
quick_sort(ba,partition_point+1,ub);
}
