#include<iostream>
using namespace std;
int main()
{
 int fact(int n);
 int n,r;
 cout<<"enter the values of n\n";
 cin>>n;
 cout<<"enter value of r \n";
 cin>>r;
 //finding combinations
 int q=n-r;
 int a=fact(n);
 int b=fact(r);
 int c=fact(q);
 int d=a/(b*c); 
 cout<<"total combinations: "<<d<<"\n";
 //finding permutations
 int e=a/c;
 cout<<"total permutations: "<<e<<"\n";
}
int fact(int n)
{
 if(n==1)
 return 1;
 return n*fact(n-1);
}

