#include<iostream>
using namespace std;
int fib(int n);
int main()
{
int i,p;
cout<<"Enter total number of elements\n";
cin>>p;
cout<<"Fibonacci series is= ";
for(i=0;i<=p;i++)
cout<<fib(i)<<" ";
return 0;
}
int fib(int n)
{
    if(n==0)
        return 0;
    if((n==1)||(n==2))
        {return 1;}
    else
        {return fib(n-1)+fib(n-2);}
}
