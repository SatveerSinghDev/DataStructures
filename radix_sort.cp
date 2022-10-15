#include<iostream>
using namespace std;

int *a,size;
int i,j,k,l,base=1,digits=0;

void rsort()
{
	int max=a[0],d,*b;
	b=new int[size];
	
	for(i=1;i<size;i++)
		if(a[i]>max)
			max=a[i];
			
	while(max>0)
	{
		max/=10;
		digits++;
	}
	
	for(i=0;i<digits;i++,base*=10)
	{
		for(j=0,l=0;j<9;j++)
		{
			for(k=0;k<size;k++)
			{				
				d=(a[k]/base)%10;
				if(d==j)
					b[l++]=a[k];
			}
		}
		for(int m=0;m<size;m++)
			a[m]=b[m];		
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
	
	rsort();
	
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
}
