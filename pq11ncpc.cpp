#include<iostream>
using namespace std;
int fact(int n)
{
if(n==0)
return 1;
else
return n*fact(n-1);
}
int main()
{
int n,r,a,b,c,d,P,C,ch;
cout<<"Enter n\n";
cin>>n;
cout<<"Enter r\n";
cin>>r;
a=fact(n);
b=n-r;
c=fact(b);
P=a/c;
d=fact(r);
C=a/(d*c);
while(ch!=3)
{cout<<"\n1.PERMUTATION";
cout<<"\n2.COMBINATION";
cout<<"\n3.QUIT";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch)
{
    case 1:    cout<<"\nPermutation of "<<n<<"P"<<r<<" is="<<P;
                break;
    case 2:    cout<<"\nCombination of "<<n<<"C"<<r<<" is="<<C;
                break;
    case 3:     cout<<"\nTHANK YOU";
                break;
    default :  cout<<"Wrong choice!!!!\nEnter again";
}
}
return 0;
}
