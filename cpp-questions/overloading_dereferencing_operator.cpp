#include<iostream>
using namespace std;

template<class T>
class Bulb
{
private:
T wattage;
public:
Bulb(T wattage)
{
this->wattage=wattage;
}
void setWattage(T wattage)
{
this->wattage=wattage;
}
T getWattage()
{
return this->wattage;
}

T operator*()
{
return this->wattage;
}

};

int main()
{
Bulb<int> b(60);
cout<<*b<<endl;
return 0;
}
