#include<stdio.h>
int main()
{
int power, base,i, cal;

printf("\nEnter the Base: ");
scanf("%d",&base);

printf("\nEnter the power: ");
scanf("%d",&power);
cal =1;
for(int i=0; i<power;i++)
{
cal = cal*base;
}
printf("\n%d to the power %d is: %d\n", base,power,cal);
return 0;
}
