#include<iostream>
using namespace std;

class aaa
{
public: 
virtual void manual()
{
cout<<endl<<"I am manual from BASE aaa";
}
};

class bbb : public aaa
{
public:
void manual()
{ 
cout<<endl<<"I am manual from Derived bbb";
}

};

int main()
{
aaa *ptr;
ptr=new aaa;
ptr->manual();
delete ptr;

ptr=new bbb;
ptr->manual();
delete ptr;
return 0;
}
