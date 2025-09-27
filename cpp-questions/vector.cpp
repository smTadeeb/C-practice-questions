#include<iostream>
#include<vector>
using namespace std;

int main()
{

vector<int> v1;
cout<<"size of vector object v1 itself is: "<<sizeof(v1)<<endl; // This is giving size of vector object not vector array.
cout<<"size of v1 objects vector is: "<<v1.size()<<endl; 
cout<<"capacity of v1 objects vector is: "<<v1.capacity()<<endl;
cout<<"max_size of v1 objects vector is: "<<v1.max_size()<<endl;

if(v1.empty()) v1={1,2,3}; // v1.=({1,2,3}) operator overloading will run here. and accordingly size of vector array for v1 object will be allocated in heap region.

cout<<endl<<"The elements in v1 objects vector(array) will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<"size of v1 objects vector is: "<<v1.size();
cout<<endl<<"capacity of v1 objects vector is: "<<v1.capacity();
cout<<endl<<endl;

vector<int> v2 = {10,20,30,40}; //here vector<int> v2({10,20,30,40});  <-- this parameterized constructor will run and make v2 objects vector as {10,20,30,40} 
cout<<endl<<"The elements in v2 objects vector(array) will be: ";
for(int x : v2)
{
cout<<" "<<x;
}
cout<<endl<<"size of v2 objects vector is: "<<v2.size();
cout<<endl<<"capacity of v2 objects vector is: "<<v2.capacity();
cout<<endl<<endl;

v1.assign(5,8);
cout<<endl<<"The new elements in v1 objects vector(array) after .assign(5,8) will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<"size of v1 objects vector after .assign(5,8) is: "<<v1.size();
cout<<endl<<"capacity of v1 objects vector after .assign(5,8) is: "<<v1.capacity();
cout<<endl<<endl;

int arr[4] = {11,22,33,44};
cout<<"int arr[4] is: {11,22,33,44}";
v1.assign(arr,arr+3);
cout<<endl<<"The new elements in v1 objects vector(array) after .assign(arr,arr+3) will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<"size of v1 objects vector after .assign(arr,arr+3) is: "<<v1.size();
cout<<endl<<"capacity of v1 objects vector after .assign(arr,arr+3) is: "<<v1.capacity();
cout<<endl<<endl;

v1.push_back(1001);
v1.push_back(1002);
v1.push_back(1003);
cout<<endl<<"The new elements in v1 objects vector(array) after 3 .push_back() will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<"size of v1 objects vector after 3 .push_back() is: "<<v1.size();
cout<<endl<<"capacity of v1 objects vector after 3 .push_back() is: "<<v1.capacity();
cout<<endl<<endl;

v1.pop_back();
cout<<endl<<"The new elements in v1 objects vector(array) after 1 .pop_back() will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<"But the size of v1 objects vector(array) after 1 .pop_back() will still be: "<<v1.size();
cout<<endl<<"But the capacity of v1 objects vector(array) after 1 .pop_back() will still be: "<<v1.capacity();
cout<<endl<<endl;

// vector<int> v4=(3,100);   // <-- this is wrong way 
// vector<int> v1(3,100);   // <-- this is also wrong, redeclaration cant be done in CPP, yes we can do v1={100,100,100} <-- this is allowed as this is reassignment not redeclaration

vector<int> v4(3,100);
cout<<endl<<"The elements in v4 objects vector(array) are: ";
for(int x : v4)
{
cout<<" "<<x;
}
cout<<endl<<"size of v4 objects vector is: "<<v4.size();
cout<<endl<<"capacity of v4 objects vector is: "<<v4.capacity();
cout<<endl<<endl;

vector<int>::iterator it;  // here it objects ptr is NULL
it=v4.begin(); //initialised it objects ptr
v4.insert(it,200);
cout<<endl<<"The elements in v4 objects vector(array) after .insert(it,200) are: ";
for(int x : v4)
{
cout<<" "<<x;
}
cout<<endl<<"size of v4 objects vector after .insert(it,200) is: "<<v4.size();
cout<<endl<<"capacity of v4 objects vector after .insert(it,200) is: "<<v4.capacity();
cout<<endl<<endl;

cout<<endl<<"*it basically *ptr of it object (but now it's ptr is still pointing to old location, thats why garbage value for *it): "<<*it<<endl;
it=v4.begin();
cout<<endl;
cout<<"*it basically *ptr of it object: (new location after copy,shift internal operations): "<<*it<<endl<<endl;
v4.insert(it,2,300);
cout<<endl<<"The elements in v4 objects vector(array) after .insert(it,2,300) are: ";
for(int x : v4)
{
cout<<" "<<x;
}
cout<<endl<<"size of v4 objects vector after .insert(it,2,300) is: "<<v4.size();
cout<<endl<<"capacity of v4 objects vector after .insert(it,2,300) is: "<<v4.capacity();
cout<<endl<<endl;
cout<<endl<<" *it basically *ptr"<<*it<<endl;

it=v4.begin(); //re-assigning the value to it 's  ptr because the ptr of it has jumped 2 positions because of above operation v4.insert(it,2,300);
vector<int> v5(2,11);
v4.insert(it,v5.begin(),v5.end()-1);
cout<<endl<<"The elements in v4 objects vector(array) after .insert(it,v5.begin(),v5.end()-1) are: ";
for(int x : v4)
{
cout<<" "<<x;
}
cout<<endl<<"size of v4 objects vector after .insert(it,v5.begin(),v5.end()-1) is: "<<v4.size();
cout<<endl<<"capacity of v4 objects vector after .insert(it,v5.begin(),v5.end()-1) is: "<<v4.capacity();
cout<<endl<<endl;

return 0;
}
