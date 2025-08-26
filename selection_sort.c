/* Selection Sort without pointers*/
#include<stdio.h>
int main()
{
int x[7] = {2,4,1,3,9,7,8};
int s_index, out, in, length, buffer;
length=7;

for(out=0; out<length-1;out++)
{
s_index=out;
for(in=out+1;in<length;in++)
{
if(x[in]<x[s_index]) s_index=in;
}
buffer=x[out];
x[out] = x[s_index];
x[s_index] = buffer;
}

for(int i=0;i<length;i++)
{
printf("%d\n",x[i]);
}
return 0;
}
