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

right_trim(str);
printf("Length after right trim: %u\n", strlen(str));

left_trim(str);
printf("Length after left trim: %u\n", strlen(str));

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


void mid_trim(char *p)
{
int count=0;
int runner = count+1;
char *q,*r,*marked_point;
q=p;

while(1)
{
while((*q != ' ' || count == 0) && *q!='\0') //this code is creative as it continues the loop if there is only a single space
                                              // but it doesnt not continues its work when there comes second single space and hence it breaks 
                                              // because when the second single space word enters this becomes false->(*q != ' ' || count == 0)
{
if(*q==' ') count++;
else count=0; // so i reset count to zero when there is no space so that(*q != ' ' || count == 0) will stay true until there are multispaces
q++;
}
marked_point=r=q;

while(*r == ' ') r++;

while(*r != ' ' && *r!='\0')   // previously while((*r != ' ' || *r != '\0') && *r!='\0') 
{
*q=*r; 
*r = ' ';  
q++;
r++;
}
if(*r=='\0') *q = '\0'; 
if(*q=='\0') break; 
else *q=' ';  
q=marked_point;  // previously q=p;
r=NULL;
count=0;
}

}


