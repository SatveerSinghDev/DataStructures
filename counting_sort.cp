#include<iostream>
using namespace std;

int i,j;
int *a,*c,size;

void csort()
{
	int max=a[1],min=a[1];
	for(i=2;i<=size;i++)
	{
		if(a[i]>max)
			max=a[i];
		else
			min=a[i];
	}
	
	cout<<"max: "<<max<<endl;
	
	int b[max],count;
	
	for(i=0;i<=max;i++)
		b[i]=0;
	
	for(i=min;i<=max;i++)
	{
		count=0;
		for(j=1;j<=size;j++)
		{
			if(a[j]==i)
				count++;
		}
		b[i]=count;
	}
	
	int sum=0;
	for (i = min; i <= max; i++)
	{
		sum+=b[i];
		b[i]=sum;
		cout<<b[i]<<" ";
	}
	
	c=new int[size];
	
	for(i=size;i>0;i--)
	{
		c[b[a[i]]]=a[i];
		b[a[i]]--;
	}
	
}
int main()
{
	cout<<"Enter size: ";
	cin>>size;
	
	a=new int[size];
	
	cout<<"Enter array: ";
	for(i=1;i<=size;i++)
		cin>>a[i];
	
	csort();
	
	cout<<endl;
	for(i=1;i<=size;i++)
		cout<<c[i]<<" ";
}
