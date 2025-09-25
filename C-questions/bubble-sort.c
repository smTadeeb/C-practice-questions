/* Bubble Sort without pointers*/
#include<stdio.h>
int main()
{
int length, in, out,count, buffer;
int x[5] = {50,70,30,8,12};
length = 5;
count=length;
for(int i=0;i<length-1;i++)
{
	for(out=0,in=out+1; in<count ;out++,in++)
	{
		buffer=x[in];
		if(x[out]>x[in]) 
		{
			x[in]=x[out];
			x[out]=buffer;
		}
	}
count--;
}

for(int i=0;i<length;i++)
{
printf("%d\n",x[i]);
}
return 0;
}
