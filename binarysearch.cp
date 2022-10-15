#include<iostream>
using namespace std;
int main()
{
int n,i,search,first,last,middle,arr[50];
cout<<"enter total no of elements:\n";
cin>>n;
cout<<"enter"<<n<<"numbers";
for(i=0;i<n;i++)
{
 cin>>arr[i];
}
cout<<"enter a no to find";
cin>>search;
first=0;
last=n-1;
middle=(first+last)/2;
while(first<=last)
{ 
	if(arr[middle]<search)
	{
		first=middle+1;
	}
	else
	if(arr[middle]==search)
	{
		cout<<search<<"found at location"<<middle+1<<"\n";
		break;
	}
	else
	{ last=middle-1;}
	middle=(first+last)/2;
}
 if(first>last)
 {
	 cout<<"not found!"<<search<<"is not present in the list";
 }
}  	 			
