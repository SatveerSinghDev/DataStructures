//Program to create a SPARSE-MATRIX using LINKED-LIST.
#include <iostream>
#include <stdlib.h>
using namespace std;
struct smatrix
{
	int val;
	struct smatrix * right;
	struct smatrix * down;
};
smatrix * head=(smatrix*)malloc(sizeof(smatrix));
smatrix * temp1;
smatrix * temp2;
smatrix * temp3;
smatrix * temp4;
int b,c,i,j,k,l,m,n,w,x,count=0;
int main()
{
	cout<<"\nEnter the NUMBER of ROWS of MATRIX:";
	cin>>w;
	cout<<"\nEnter the NUMBER of COLUMNS of MATRIX:";
	cin>>x;
	int ar[w][x];
	cout<<"\nEnter the elements:";
	for(b=0;b<w;b++)
	{
		for(c=0;c<x;c++)
		{
			cin>>ar[b][c];
			if(ar[b][c]!=0)
			{
				count++;
			}
		}
	}
	head->val=count;
	temp1=head;
	temp2=head;
	for(i=0;i<w;i++)
	{
		for(j=0;j<x;j++)
		{
			if(ar[i][j]!=0)
			{
				if(temp1==head)
				{
					smatrix * p=(smatrix*)malloc(sizeof(smatrix));
					p->right=NULL;
					p->down=NULL;
					p->val=i;
					temp1->down=p;
					temp1=p;
					if(temp2==head)
					{
						smatrix * q=(smatrix*)malloc(sizeof(smatrix));
						q->right=NULL;
						q->down=NULL;
						q->val=j;
						temp2->right=q;
						temp2=q;
					}
				}
				else
				{
					if(temp1->val==i)
					{
						if(temp2->val==j)
						{
							
						}
						else
						{
							smatrix * r=(smatrix*)malloc(sizeof(smatrix));
							r->right=NULL;
							r->down=NULL;
							r->val=j;
							temp2->right=r;
							temp2=r;
						}
					}
					else
					{
						smatrix * s=(smatrix*)malloc(sizeof(smatrix));
						s->right=NULL;
						s->down=NULL;
						s->val=i;
						temp1->down=s;
						temp1=s;
						smatrix * t=(smatrix*)malloc(sizeof(smatrix));
						t->right=NULL;
						t->down=NULL;
						t->val=j;
						temp2->right=t;
						temp2=t;
					}
				}
			}
		}
	}
	for(k=0;k<w;k++)
	{
		for(l=0;l<x;l++)
		{
			if(ar[k][l]!=0)
			{
				smatrix * u=(smatrix*)malloc(sizeof(smatrix));
				u->val=ar[k][l];
				u->right=NULL;
				u->down=NULL;
				//Making Connection with ROW.
				temp1=head;
				temp1=temp1->down;
				while(temp1->val!=k)
					temp1=temp1->down;
				//Making Connection with COLUMN.
				temp2=head;
				temp2=temp2->right;
				while(temp2->val!=l)
					temp2=temp2->right;
				//Connecting the new node with ROWS & COLUMNS.
				while(temp1->right!=NULL)
					temp1=temp1->right;
				temp1->right=u;
				while(temp2->down!=NULL)
					temp2=temp2->down;
				temp2->down=u;
			}
		}
	}
	cout<<"\nTotal NON-ZERO ELEMENTS are:"<<head->val<<endl;
	for(m=0;m<w;m++)
	{
		temp1=head;
		temp1=temp1->down;
		if(temp1->val==m)
		{
			temp2=head;
			temp2=temp2->right;
			for(n=0;n<x;n++)
			{
				if(temp2->val==n)
				{
					temp3=temp1;
					temp4=temp2;
					if(temp3->right->val==temp4->down->val)
					{
						cout<<temp3->right->val<<" ";
					} 
				}
				else
				{
					cout<<0<<" ";
				}
				temp2=temp2->right;
			}
		}
		else
		{
			cout<<0<<" ";
		}
		temp1=temp1->down;
		cout<<endl;
	}
	return 0;
}
