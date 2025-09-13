#include<iostream>
using namespace std;

class kuchtohbhi
{
int num;
private:
kuchtohbhi(int num)
{
this->num=num;
}
friend class IntRange;

public:
int operator!=(kuchtohbhi &other)
{
return this->num != other.num;
}

void operator++()
{
this->num++;
}
void operator++(int)
{
this->num++;
}

int operator*()
{
return this->num;
}
};

class IntRange
{
private:
	int _start, _end;
public:

	IntRange(int _start, int _end)
	{
	this->_start=_start;
	this->_end=_end;
	}

kuchtohbhi begin()
{
return kuchtohbhi(this->_start);
}

kuchtohbhi end()
{
return kuchtohbhi(this->_end);
}

};

int main()
{
IntRange range(1,10);

for(int x : range)
{
cout<<x<<endl;
}
return 0;
}
