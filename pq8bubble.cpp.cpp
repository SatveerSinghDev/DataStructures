#include<iostream>
using namespace std;
int main()
{
int a[30],temp,n,i,j;
cout<<"Enter total of elements\n";
cin>>n;
cout<<"Enter the elements\n";
for(i=0;i<n;i++)
cin>>a[i];
cout<<"Your elements are: ";
for(i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"\nSorted array is: ";
int count=0;
    for(i=0;i<n;++i)
    {

        for(j=0;j<n-i-1;++j)
           {
               if(a[j]>a[j+1])
            {
               temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
                count++;
            }
        }
    }
for(i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"\nTotal number of comparison is="<<count;
return 0;
}
