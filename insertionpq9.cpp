#include<iostream>
using namespace std;
int main()
{
int x[30],i,j,key,n;
cout<<"Enter the length of elements: ";
cin>>n;
cout<<"\nEnter the elements: ";
for(i=0;i<n;i++)
cin>>x[i];
cout<<"\nYour elements are: ";
for(i=0;i<n;i++)
cout<<x[i]<<" ";
    for(i=1;i<n;i++)
    {
        key=x[i];
        j=i-1;
        while(j>=0&&x[j]>key)
        {
            x[j+1]=x[j];
            j=j-1;
        }
        x[j+1]=key;
    }
cout<<"\nAfter sorting: ";
for(i=0;i<n;i++)
    cout<<x[i]<<" ";
    return 0;
}
