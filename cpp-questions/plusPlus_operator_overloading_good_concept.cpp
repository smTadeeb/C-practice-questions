#include<iostream>
using namespace std;

class Number
{
int number;
public:
void setNumber(int number)
{
this->number=number;
}
int getNumber()
{
return this->number;
}


Number & operator++()      //It got run for prefix
{
this->number++;
return *this;
}

void operator++(int)                 //Number & operator++(int)      // it got run for postfix
{
this->number=this->number+10;
}

Number & operator+=(int val)
{
this->number = this->number+val;
return *this;
}

};
int main()
{
Number n1,n2,n3;              //n1.Number(&n1);    //n2.Number(&n1);
n1.setNumber(100);
n2.setNumber(200);
cout<<"Just for Learning"<<endl;
n1++; //n3=n1++; 	//postfix				//n1.++();
cout<<"Purpose"<<endl;
n3 = ++n2;    //prefix                               //n2.++();
cout<<"only"<<endl;
cout<<"I am postfix n1: "<<n1.getNumber()<<endl;
cout<<"I am prefix n2: "<<n2.getNumber()<<endl;
cout<<"I am n3: "<<n3.getNumber()<<endl;
cout<<"Ok"<<endl;
n1+=25;                  // n1.+=(25);
cout<<"Cool"<<endl;
cout<<"I am new value of n1 after += operator: "<<n1.getNumber()<<endl;
return 0;
}
