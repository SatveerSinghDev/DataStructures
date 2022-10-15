#include<iostream>
using namespace std;
void bisearch(int ar[],int num,int first,int last)
{
int mid;
while(first<=last)
{mid=(first+last)/2;
    if(first>last)
    cout<<"Element not found\n";
    else if(ar[mid]==num)
    {
        cout<<"Element "<<num<<" found at position "<<mid+1;
        break;
    }
    else if(ar[mid]<num)
    return bisearch(ar,num,mid+1,last);
    else
    return bisearch(ar,num,first,mid-1);
}
}
int main()
{
int ar[30],num,i,n,first,last;
cout<<"Enter the total number of elements: ";
cin>>n;
cout<<"\nEnter elements: ";
for(i=0;i<n;i++)
cin>>ar[i];
cout<<"\nYour elements are: ";
for(i=0;i<n;i++)
cout<<ar[i]<<" ";
first=0;
last=n-1;
cout<<"\nEnter the number you want to search: ";
cin>>num;
bisearch(ar,num,first,last);
return 0;
}
