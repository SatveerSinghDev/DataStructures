#include<iostream>
using namespace std;
int main()
{
bool x,y;
cout<<"enter value of x:";
cin>>x;
cout<<"enter value of y:";
cin>>y;
//for conjunction
cout<<"conjunction is: "<<(x&y)<<"\n";
cout<<"disjunction is: "<<(x|y)<<"\n";
cout<<"ex or is: "<<(x^y)<<"\n";
cout<<"conditional is: "<<(!x|y)<<"\n";
cout<<"biconditional is: "<<(((!x)|y)&((!y)|x))<<"\n";
cout<<"negation of x is: "<<(!x)<<"\n";
cout<<"negation of y is: "<<(!y)<<"\n";  
}
