#include<iostream>
using namespace std;

int i, j, *a, size;
void ssort(int *a)
{ 
	int min,c=0; 
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{	c++;
			if(a[j]<a[min])
				min=j;
			
		}
		if(min!=i)
		{
			int temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	cout<<"c: "<<c<<endl;
}
int main()
{
	cout<<"Enter size: ";
	cin>>size;
	
	a=new int[size];
	
	cout<<"Enter array: ";
	for(i=0;i<size;i++)
		cin>>a[i];
	
	ssort(a);
	
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
	
}
