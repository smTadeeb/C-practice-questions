#include<iostream>
using namespace std;

template<class T1, class T2>
class aaa
{
public:
void operator()(T1 x, T2 y)
{
cout<<"The sum of 2 nos is: "<<x+y<<endl;
}
};

int main()
{
aaa<int,int> a;                //a.aaa(&a)
a(50,20);   // a.()(50,20);
return 0;
}
