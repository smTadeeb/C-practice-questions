#include<iostream>
using namespace std;

class my_string
{
private:
char arr[31];

public:
my_string()
{
cout<<"String class default constructor got run"<<endl<<endl;
}

void hello_world()
{
cout<<"Hello World"<<endl;
}


void operator=(const char *ptr)
{
cout<<"The name is: "<<ptr<<endl;
}

};

int main()
{
my_string *p;
p=new my_string;

const char *q;
//p = "Taddy";  // <-- Operator overloading doesnt works in case of pointers.

q = "Sheikh Muhammed"; 
cout<<q<<endl;

my_string x;
x.hello_world();
x = "Tadeeb";  // Operator overloading

return 0;
}
