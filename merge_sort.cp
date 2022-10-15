#include<iostream>
using namespace std;
int i,j,k,*a,size;

void Merge(int *a, int f, int l, int m)
{
	int n1=m-f+1, n2=l-m;
	int temp1[n1], temp2[n2];
	
	for(i=0;i<n1;i++)
		temp1[i]=a[f+i];
	
	for(j=0;j<n2;j++)
		temp2[j]=a[m+1+j];
		
	i=0,j=0,k=f;
	
	while(i<n1 && j<n2)
	{
		if(temp1[i]<=temp2[j])
			a[k++]=temp1[i++];
		
		else
			a[k++]=temp2[j++];
	}
	while(i<n1)
		a[k++]=temp1[i++];
	
	while(j<n2)
		a[k++]=temp2[j++];
}
void msort(int *a, int first, int last)
{
	if(first<last)
	{
		int mid=(first+last)/2;
		msort(a,first,mid);
		msort(a,mid+1,last);
		Merge(a,first,last,mid);
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
	
	msort(a,0,size-1);
	
	for(i=0;i<size;i++)
		cout<<a[i]<<" ";
}
