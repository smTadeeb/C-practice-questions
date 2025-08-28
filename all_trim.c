#include<stdio.h>
#include<string.h>
void left_trim(char *);
void right_trim(char *);
void mid_trim(char *);

int main()
{
char str[500];

printf("\nEnter the string: ");
scanf("%[^\n]s", str);

printf("Length of original: %u\n", strlen(str));
left_trim(str);

printf("Length after left trim: %u\n", strlen(str));

right_trim(str);

printf("Length after right trim: %u\n", strlen(str));

mid_trim(str);

printf("Length of final: %u\n", strlen(str));

printf("\nThe string is: %s \n\n", str);
return 0;
}

void left_trim(char *p)
{
char *q=p;
while(*q==' ') q++;
while(*q!='\0') 
{
*p=*q;
p++;
q++;
}
*p='\0';
}

void right_trim(char *p)
{
while(*p!='\0') p++;
p--;
while(*p== ' ') p--;
*(p+1) = '\0';  
}

// This is not completely working right now.
void mid_trim(char *p)
{
int count=0;
int runner = count+1;
char *q,*r;
q=p;

while(1)
{
while((*q != ' ' || count == 0) && *q!='\0') 
{
if(*q==' ') count++;
q++;
}
r=q;
while(*r == ' ') r++;

while((*r != ' ' || *r != '\0') && *r!='\0')
{
*q=*r;
*r = ' ';
q++;
r++;
}
if(*r=='\0') *q = '\0';

if(*q=='\0') break;
q=p;
r=NULL;
count=0;
}

}
