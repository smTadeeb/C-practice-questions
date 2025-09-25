#include<iostream>
#include<vector>
using namespace std;

int main()
{

vector<int> v1;
cout<<"Size of vector object v1: "<<sizeof(v1)<<endl; // This is giving size of vector object not vector array.
v1={1,2,3}; // v1.=({1,2,3}) operator overloading will run here. and accordingly size of vector array for v1 object will be allocated in heap region.

cout<<endl<<"The elements in v1 objects vector(array) will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<endl;

vector<int> v2 = {10,20,30,40}; //here vector<int> v2({10,20,30,40});  <-- this parameterized constructor will run and make v2 objects vector as {10,20,30,40} 
cout<<endl<<"The elements in v2 objects vector(array) will be: ";
for(int x : v2)
{
cout<<" "<<x;
}
cout<<endl<<endl;

v1.assign(5,8);
cout<<endl<<"The new elements in v1 objects vector(array) after .assign(5,8) will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<endl;

int arr[4] = {11,22,33,44};
cout<<"int arr[4] is: {11,22,33,44}";
v1.assign(arr,arr+3);
cout<<endl<<"The new elements in v1 objects vector(array) after .assign(arr,arr+3) will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<endl;

v1.push_back(1001);
v1.push_back(1002);
v1.push_back(1003);
cout<<endl<<"The new elements in v1 objects vector(array) after 3 .push_back() will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<endl;

v1.pop_back();
cout<<endl<<"The new elements in v1 objects vector(array) after 1 .pop_back() will be: ";
for(int x : v1)
{
cout<<" "<<x;
}
cout<<endl<<endl;

return 0;
}
