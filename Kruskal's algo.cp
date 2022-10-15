/*
 * Program to implement Kruskal's Algorithm for MST
 * The following input was given as a test case to check the program:-
 9 4 0 0 0 0 0 8 0 8 0 0 0 0 11 0 7 0 4 0 0 2 9 14 0 0 0 10 0 0 0 2 0 0 1 6 7

 * which gave the following adjacency matrix:-
0 4 0 0 0 0 0 8 0 
4 0 8 0 0 0 0 11 0 
0 8 0 7 0 4 0 0 2 
0 0 7 0 9 14 0 0 0 
0 0 0 9 0 10 0 0 0 
0 0 4 14 10 0 2 0 0 
0 0 0 0 0 2 0 1 6 
8 11 0 0 0 0 1 0 7 
0 0 2 0 0 0 6 7 0 

*/

#include <iostream>
using namespace std;
int main()
{
	int nodes;
	
	cout<<"Enter no. of nodes: ";
	cin>>nodes;
	
	int matrix[nodes][nodes];
	int output[nodes];
	int cost=0,i,j,k,m;
	
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
			matrix[i][j]=-1;
		output[i]=-1;
	}
	
	cout<<"Enter the connections into the Adjacency Matrix: ";
	for(i=0; i<nodes; i++)
	{
		for(j=i; j<nodes; j++)
		{
			cout<<endl<<(char)('A'+i)<<","<<(char)('A'+j)<<": ";
			if(i==j)
				matrix[i][j]=0;

			else if(matrix[i][j]==-1)
			{
				cin>>matrix[i][j];
				matrix[j][i]=matrix[i][j]; 		//Setting the equal value to the transpose of the value inputted
			}
		}
	}
	
	int min_row=0,min_c=0,min_val=100;
	cout<<endl<<endl;
	cout<<"Matrix is: "<<endl;
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			cout<<matrix[i][j]<<" ";
			
			if(matrix[i][j]!=0 && matrix[i][j]<=min_val)
			{
				min_val=matrix[i][j];
				min_row=i;
				min_c=j;
			}
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	
	cout<<"min_val: "<<min_val<<"\t";
	cout<<"min_row: "<<min_row<<"\t";
	cout<<"min_col: "<<min_c<<endl<<endl;
	output[0]=min_row;
	
	//Algorithm to find MST by Prim's Method	
	for(i=min_row,k=1,m=1; i<nodes && k<nodes; )
	{
		int min;	int min_col;
		bool flag=true;
		
		for(j=0; j<nodes; j++)
		{
			if(matrix[i][j]!=0)
			{	
				if(flag==true)
				{
					bool duplicate=false;
					
					for(int l=0; l<nodes; l++)
						if(j==output[l])
						{
							duplicate=true;
							break;
						}
						
					if(duplicate==false)
					{
						min=matrix[i][j];
						min_col=j;
						flag=false;
					}
				}
				else if (matrix[i][j]<=min)
				{
					bool duplicate=false;
					
					for(int l=0; l<nodes; l++)
						if(j==output[l])
						{
							duplicate=true;
							break;
						}
						
					if(duplicate==false)
					{
						min=matrix[i][j];
						min_col=j;
					}
				}
			}
		}
		if(min_col==output[k-1])
		{	
			matrix[i][min_col]=0;					//This step just removes the weight that has been used once
			matrix[min_col][i]=0;					//from both (i,j) and (j,i). We can omit this step if we want to.
													//Then, adjacency matrix will have no change whatsoever.
			min=0;
			i=output[m-2]; m--;
		}
		else
		{
			output[k]=min_col; k++; m++;
			cost+=min;
			
			matrix[i][min_col]=0;					//This step just removes the weight that has been used once
			matrix[min_col][i]=0;					//from both (i,j) and (j,i). We can omit this step if we want to.
													//Then, adjacency matrix will have no change whatsoever.
			i=min_col;
		}

		cout<<"min_col: "<<min_col<<"\t";
		cout<<"Cost: "<<cost<<" \t";
		cout<<"Output: "<<output[k-1]<<endl;
		
		//This 2D Loop is to see removal of elements from Matrix at every step
		for(int a=0;a<nodes;a++)
		{
			for(int b=0;b<nodes;b++)
				cout<<matrix[a][b]<<" ";
		cout<<endl;
		}
		cout<<endl<<endl;
	}
	
	cout<<endl;
	int abcd=0;
	for(i=abcd; i<nodes; i++)
	{
		abcd=output[i];
		cout<< (char) ('A' + abcd);
		
		if(i!=nodes-1)
			cout<<"->";
	}
	cout<<endl<<endl;
	cout<<"Cost: "<<cost;

}
