#include<iostream>
using namespace std;
int main()
{
int a[30],i,n,first,last,element,middle;
cout<<"Enter total number of elements\n";
cin>>n;
cout<<"Enter elements\n";
for(i=0;i<n;i++)
cin>>a[i];
cout<<"Your elements are: ";
for(i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"\nEnter elements which you want to search\n";
cin>>element;
first=0;
last=n-1;
middle=(first+last)/2;
while(first<=last)
    {
    if(a[middle]<element)
        {
        first=middle+1;
        }
        else if(a[middle]==element)
        {
        cout<<"Element "<<element<<" found at "<<middle+1<<" position";
        break;
        }
        else
        {
            last=middle-1;
        }
        middle=(first+last)/2;
    }
    if(first>last)
    {
        cout<<"Element "<<element<<" is not found!!";
    }
    return 0;
}
