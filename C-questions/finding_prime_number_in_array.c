#include<stdio.h>
int main()
{
int start_at, end_at, ep, i, j;
int ar[6] = {5,8,-11,14,17,-23};
int ar_copy[6];

for(i=0; i<6;i++)
{
if(ar[i]>0) ar_copy[i] = ar[i];
else ar_copy[i] = ar[i]*-1;
}

ep=0;
while(ep<6)
{
j=0;
start_at=2;
end_at=ar_copy[ep]/2;

while(start_at<=end_at)
{
if(ar_copy[ep]%start_at==0) 
{
j=1;
break;
}
start_at++;
}

if(j==0) printf("%d\n", ar[ep]);
ep++;
}

return 0;
}
