/* Linear Sort without pointers*/
#include<stdio.h>
int main()
{
int length, buffer;
int x[5] = {50,30,70,29,15};
length=5;
for(int out=0; out<length-1; out++)
{
	for(int in=out+1;  in<length; in++)
	{
		if(x[in] < x[out])
		{
			buffer=x[out];
			x[out] = x[in];
			x[in] = buffer;
		}
	}
}

for(int i=0;i<length;i++)
{
printf("%d\n", x[i]);
}
return 0;
}
