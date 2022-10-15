#include<iostream>
using namespace std;

int i,j,k;
int *a,size;

void shsort()
{
	int temp,gap,c=0;
	
	for(gap=(size/2);gap>0;gap/=2)
	{
		for(j=gap;j<size;j+=gap)
		{
			k=j-gap;	temp=a[j];
			while(k>=0 && temp<=a[k])
			{
				c++;
				a[k+gap]=a[k];
				k-=gap;
			}
			a[k+gap]=temp;
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
	
	shsort();
	
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
}
