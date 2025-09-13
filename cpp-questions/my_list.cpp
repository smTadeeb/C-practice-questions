#include<iostream>
using namespace std;

class my_list
{
private:
	//Node *top ,*bottom;
	class Node
	{
		private:
			int data;
			Node *next, *previous;
			Node(int data)
			{
				this->data=data;
				this->next = NULL;
				this->previous = NULL;
			}
			friend class my_list;
	};
	Node *top ,*bottom;

public:
	my_list()
	{
		this->top=this->bottom=NULL;
	}
	
	void insert(int data)
	{
		Node *t;
		t=new Node(data);
		if(!t) return; // Memory allocation failed, no memory left.
		if(!this->top && !this->bottom) 
		{
			this->top=this->bottom=t;
			return;
		}
		t->next = this->top;
		this->top->previous=t;
		this->top=t;
	}
	
	void add(int data)
	{
		Node *t;
		t=new Node(data);
		if(!t) return;
		if(!this->top && !this->bottom) 
		{
			this->top=this->bottom=t;
			return;
		}
		t->previous=this->bottom;
		this->bottom->next=t;
		this->bottom=t;
	}
	class reverse_iterator
	{
		private:
			Node *ptr;
			reverse_iterator(Node *ptr)
			{
				this->ptr=ptr;
			}
			friend class my_list;
		public:
			reverse_iterator()
			{	
				this->ptr=NULL;
			}
			
			int operator!=(reverse_iterator other)
			{
				return (this->ptr != other.ptr);
			}
			int operator*()
			{
				return this->ptr->data;	
			}
			
			void operator++() //prefix
			{
				if(!this->ptr) return;
				this->ptr=this->ptr->previous;
			}
		
			void operator++(int) //postfix
			{
				if(!this->ptr) return;
				this->ptr=this->ptr->previous;
			}
	};
	
	reverse_iterator reverse_begin()
	{ 
		return reverse_iterator(this->bottom);
	}
	
	reverse_iterator reverse_end()
	{
		return reverse_iterator();
	}
};

int main()
{
my_list list;
list.insert(10);
list.add(20);
list.insert(30);
list.add(30);

my_list::reverse_iterator i;
i=list.reverse_begin();
while(i!=list.reverse_end())
{
cout<<*i<<endl;
i++;
}
return 0;
}
