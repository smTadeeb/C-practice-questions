#include<iostream>
using namespace std;

class aaa
{
public:
void abdurrehman()
{
cout<<"Hi, I am Abdurrehman the Boss"<<endl;
}
};

int main()
{
aaa a;
aaa *p;
a.abdurrehman();
p = &a;
cout<<"Break it baby"<<endl<<endl;
p->abdurrehman();
return 0;
}


