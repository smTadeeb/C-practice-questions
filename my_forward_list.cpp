#include<iostream>
using namespace std;

class my_forward_list
{
private:
	
	class Node
	{
		private:
			int data;
			my_forward_list::Node *next;
			Node(int data)
			{
				this->data=data;
				this->next=NULL;
			}
			friend class my_forward_list;
			//friend class iterator;    //friend class iterator;
	};
	my_forward_list::Node *top;
public:
	class iterator
	{
		private:
			my_forward_list::Node *ptr;
			iterator(my_forward_list::Node *ptr)
			{
				this->ptr=ptr;
			}
			friend class my_forward_list;
		public: 
			iterator()
			{
				this->ptr=NULL;
			}
			int operator*()
			{
				if(!this->ptr) return 0;
				return this->ptr->data;
			}
			void operator++()     //for prefix.
			{
				// this->ptr++; <== This will be wrong as ptr Node type ke utne space aage badh jayega, leking zaruri nhi hai next node waha ho, as its dynamicMemAlloc.
				if(!this->ptr) return;
				this->ptr=this->ptr->next;
			}
			void operator++(int)   //We have written for postfix as well, to avoid errors.
			{
				// this->ptr++; <== This will be wrong as ptr Node type ke utne space aage badh jayega, leking zaruri nhi hai next node waha ho, as its dynamicMemAlloc.
				if(!this->ptr) return;
				this->ptr=this->ptr->next;
			}
			int operator!=(my_forward_list::iterator other)
			{	
				/* if(this->ptr != other.ptr) return 1;
				else return 0; */
				return this->ptr != other.ptr;		
			}
	};
public:                              // I have written it 2 types but dont worry compiler wont give an error, purposely i wrote it.
	my_forward_list()
	{
		this->top=NULL;
	}
	void insert(int data)
	{
		my_forward_list::Node *t;
		t=new Node(data);
		if(t==NULL) return; //Memory Allocation fail.
		t->next=this->top;
		this->top=t;
	}
	my_forward_list::iterator begin()
	{
		// iterator tmp(this->top);
		// return tmp;

		/* Below I have not called a constructor because we know we can't explicitly call a constructor, it gets called implicitly upon object creation.
		   So in the backgound, similar to above 2 lines, an anonymous abject is created and it will be returned. "Anonymous means jiska koi naam na ho."  	
		*/
		return my_forward_list::iterator(this->top);       
	}
	my_forward_list::iterator end()
	{
		// Here also we are not explicitly calling anything, actually an anonymous object will be created and for that object default constructor is called
		// and value for its ptr will be assigned NULL and that anonymous object is returned here.	
		return my_forward_list::iterator(); 
	}

};

int main()
{
my_forward_list list;
list.insert(5);
list.insert(7);
list.insert(15);
list.insert(70);
list.insert(33);

my_forward_list::iterator i;
i = list.begin();
int j;
while(i!=list.end())
{
//j=*i;       // i.*(); ==> i.*(&i);
//cout<<j<<endl;
cout<<*i<<endl;
i++;        // i.++(&i); ==> i.++(&i);
} 
return 0;
}
