#include<iostream>
using namespace std;

int i, j, *a, size;
void bsort(int *a)
{
	int c=0;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			c++;
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
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
	
	bsort(a);
	
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
	
}
