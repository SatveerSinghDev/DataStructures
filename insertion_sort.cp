#include<iostream>
using namespace std;

int i, j, *a, size;
void isort(int *a)
{ 
	int temp,c=0;
	for (int i = 1; i < size; i++)
	{
		j=i-1;
		temp=a[i];
		while(j>=0 && temp<=a[j])
		{	c++;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
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
	
	isort(a);
	
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
	
}
