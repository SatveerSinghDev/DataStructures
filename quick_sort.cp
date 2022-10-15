#include<iostream>
using namespace std;
int i,j,k,*a,size;

int partition(int *a, int f, int l)
{
	int pivot=a[l], temp;
	i=f; 
	for(j=f;j<l;j++)
	{
		if(a[j]<=pivot)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++;
		}
	}
	temp=a[i];
	a[i]=a[l];
	a[l]=temp;
	
	return i;
}
void qsort(int *a, int first, int last)
{
	if(first<last)
	{
		int pi=partition(a,first,last);
		qsort(a,first,pi-1);
		qsort(a,pi+1,last);
	}
}
int main()
{
	cout<<"Enter size: ";
	cin>>size;
	
	a=new int[size];
	
	cout<<"Enter array: ";
	for(i=0;i<size;i++)
		cin>>a[i];
	
	qsort(a,0,size-1);
	
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
}
