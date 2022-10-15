/*Program to implement sparse matrix using array.  "Create a FILE with name "sparse.csv" in Libre office first and enter the values in it."
  Created by Nitish Arya on 21/08/2018.
  */
   
#include<iostream>
#include<stdlib.h>   //for malloc.
#include<fstream>  //for file handling.
using namespace std;

struct node
{
	int val;
	node *right;
	node *down;
} ;

node *head=(node*)malloc(sizeof(node));   //node containing head.

node *t=(node*)malloc(sizeof(node));     //node for traversal.

node *temp=(node*)malloc(sizeof(node));  //node for traversing inner loops when t is already is use.
	
	

void linkage(int l,int m,int value) //l=> row index of element in the matrix to be linked.m=>column index of element in the matrix to be linked. value=>element.
{	
												
	node *tC=(node*)malloc(sizeof(node));  //node for column creation(and traversing).
	tC->val=m; 	tC->right=NULL;	 tC->down=NULL;
	
	node *tR=(node*)malloc(sizeof(node));  //node for row creation(and traversing).
	tR->val=l;	tR->right=NULL;	 tR->down=NULL;
	
	node *P=(node*)malloc(sizeof(node));   //node for element creation.
	P->val=value; 	P->right=NULL; 	P->down=NULL;
	
	int flag=0;      //Proceeding row wise, if an element of a row already present is to be added(we now only need to add a new column in node) then flag=1;
	                 //Otherwise(i.e if(flag==0)) a new row must be formed and search for the column if already present(if not then add a new colum node).
	
	if(t->down==NULL)    //Checking if any row(or column) is already created or not. t is head.
	{
		t->right = tC;     //Link column with head.
		t->down = tR;      //Link row with head.
        
        tC->down=P;        //Link element with column.
        tR->right=P;       //Link element with row.
          cout<<"doing first elem"<<endl;  
    }
    
    else      //If the element to be added is not a new one, then go through row search. 
			  //If element to be added(node P) is in a row already connected then create a column and turn flag=1.
	{   
		bool colF=false;  //bool value to check if column index is already present or not.
		
		temp=t;
		
		while(temp->right!=NULL)   //To check if column index is already present or not.
		{
			if(temp->right->val==m)
			 {
				 colF=true; break;
		     }
			  temp=temp->right;
		}
		while(t->down!=NULL)      //Search element's row in a downward manner until NULL is encountered.
		{
			if(t->down->val==l)    //If row index is found, create a new  column and link element with both row and column.
			{   
				if(colF)
				{
					for(tR=t->down;tR->right!=NULL;tR=tR->right);   //Moving to the last linked element in the row(rightwards).
					tR->right=P;        //Linking element to right of row.
					for(temp=temp->right;temp->down!=NULL;temp=temp->down); //Column linking of element.
					temp->down=P; 
					flag=1; cout<<"doing row found column found"<<endl; break;
				}					
				
				else
				{											//"temp" used to add column when "t" is in use for outer loop.
					for(temp=t;temp->right!=NULL;temp=temp->right); //Moving to the last column node.
					temp->right=tC;     //tC points to the created column.
				
																//tR moved to node containing row index of element.
					for(tR=t->down;tR->right!=NULL;tR=tR->right);   //Moving to the last linked element in the row(rightwards).
					tR->right=P;        //Linking element to right of row.
				
					tC->down=P;         //Linking element to down of column.
				
					flag=1; cout<<"doing row found colmn crtn"<<endl; break;     //break and come out of loop as node is added.
				}
				
			}
			
			else
			flag=0;
			
		  t=t->down;
		}	
		
		t=head;  //Re-initialsing t to head for next traversals.
		
		if(flag==0)         //If element's row index is not present already then create a new row and link element.
		{
			                                              //"temp" used to add row when "t" is to be used for other loop.
			for(temp=t;temp->down!=NULL;temp=temp->down); //Moving to the last row node.
			temp->down=tR;    //tR is pointing to the row created above.
			
			while(t->right!=NULL)  //Search element's column in rightward manner until NULL is encountered.
			{
				if(t->right->val==m)  //If column index is found, link the element with row and column both.
			    {
																   //tC moved to node containing column index of element.	
					for(tC=t->right;tC->down!=NULL;tC=tC->down);   //Moving to the last linked element in the column(downwords).
					tC->down=P;      //Linking element to down of column.
					
					tR->right=P;     //Linking element to right of row.
					flag=0;  cout<<"doing column found row crtn"<<endl;  break;   //break and come out of loop as node is added.
			    }
			    
			    else
			    {
																  //"temp" used to add column when "t" is used for outer loop.
					for(temp=t;temp->right!=NULL;temp=temp->right); //Moving to the last column node.
					temp->right=tC;    //tC is pointing to the column created above.
			        
			        tC->down=P;     //Linking element to down of column.
			        tR->right=P;    //Linking element to right of row.
			        
			        flag=0; cout<<"doing column NOT present row NOT present"<<endl; break;    //break and come out of loop as node is added.
			    }
			    
			   t=t->right;
			}
			
			t=head;    //Re-initialsing t to head for next traversals.
		}
	}
}

void display(const int nr,const int nc)           //nr=total rows present in matrix. nc=total columns present in matrix.
{
	node *t1=(node*)malloc(sizeof(node));
	node *t2=(node*)malloc(sizeof(node));
	bool Flag=false;    int r=0,R=0,ic=0;      //r contains index of row of last element found. ic contains index of column of last element found.
		                                        //R contains value of how many trivial rows are left between rows containing non-zero elements.
		t1=t=t2=temp=head;
		
		t1=t1->down;
		
		while(t1!=NULL)                    //Traversing "t1" downwards in rows.
		{
			
			for(t=t1;t!=NULL;t=t->right)     //Traversing "t" rightwards in a row. pointed by "t1".
			{  
				Flag=false;
				temp=head;
				
				for(temp=temp->right;(temp!=NULL)&&(!Flag);temp=temp->right)   //Traversing "temp" rightwards of head(going through columns).
				{
					t2=temp;
					
					while(t2->down!=NULL)            //Traversing "t2" downwards in column.
					{
						if(t->right == t2->down)              //If node present,is linked with given indices then do the else's execution, else print 0's.
						{
							R=((t1->val)-r);
							
							if(R>0) cout<<endl;
							
							while(R>0)
							{
								for(int i=nc;i>0;i--)    //Display no. of rows of zeroes where whole row's element are 0.
								{                        //These rows are  between current index and last row index where element was found.
								cout<<"0"<<"\t";
								} 
								cout<<endl;
							   R--;
							}
							r=t1->val+1;
							
							if(R==0)
							cout<<endl;
							
							for(int j=((temp->val)-ic);j>0;j--)      //Display given no. of zeroes where element is 0(columnwise)
							{                                     // between two columns seperated by current index and last index where non-zero element was found.
								cout<<"0"<<"\t";
							}
							ic=temp->val+1;
							
							cout<<t2->down->val<<"\t";
							
							Flag=true; 
							break;
						}
						t2=t2->down;
					}
				}
				if((t->right==NULL))
					{    
					   for(int k=nc-ic;k>0;k--)            //Display zeroes between last of column index(in matrix i.e c) and last column where
						{                                   //non-zero element was found.
							cout<<"0"<<"\t"; 
						}
						cout<<endl;
					}
			}
			
			ic=0;   //last element found takes column index 0 for next row traversal.
			
		    if(t1->down==NULL)
			{
			  for(int k=nr-r;k>0;k--)            //Display zeroes between last of row index(in matrix i.e c) and last row where
				{
					cout<<endl;                                 //non-zero element was found.
					for(int col=nc;col>0;col--)
						{
							cout<<"0"<<"\t"; 
						}
				cout<<endl;
				}
			} 
			
		   t1=t1->down;
	    }    
}

int pow10(int j)   //Function to generate power of 10 raised to "j".
{
	if(j==0)
	return 1;
	
	else if(j==1)
	return 10;
	
	else
	return 10*pow10(j-1);
}



int main()
{
	temp->down=temp->right=NULL;
	
	t->down=t->right=NULL;
	
	head->down=head->right=NULL;
	
	t=head;
	
	ifstream of; 
	of.open("sparse.csv");
	
	int col=0;  //To store column index.
	int i=0;    //To store row index.
	int count=0; //To count no. of non-zero elements.
	int p=0,q=0,c=0;
	
	if(of.is_open())
	{
		cout<<"file open\n";
		string a;
		
		while(getline(of,a))
		{
			string VAL;
			col=0;
			cout<<"\n"<<a<<"\t"; 
			for(int j=0;a[j]!='\0';j++)
			{
				if((a[j]==','))        //If comma(",") is detected in file then do following operations.
				{  
					 
					while(p)            //Costruct the number before comma in file by place value method(as a single character is read from file).
					{                               //value of VAL[] is substracted from char '0' so that we get the corresponding integer from ASCII.
						c = c + ((VAL[q]-'0') * pow10(p-1));   //VAL is a string which takes the substring before comma and constructs the number 'c'.
						p--; q++;                   
					}
					if((c!=0))          //If element is non-trivial, then link it with row and column index.
					{
						cout<<"row="<<i<<"\tcolumn="<<col<<"\tvalue="<<c<<"\n";
						linkage(i,col,c); count++; c=0;    //count the no. of non-trivial elements.
					}
					col++;            //count column.
				}
				else
				{
					
					VAL=VAL+a[j];p++; cout<<"VAL is: "<<VAL<<"\tp= "<<p<<endl;          //p counts the no. of characters in substring VAL.
					
				}
				if(a[j+1]=='\0')        //If after a character in string a, '\0' occurs, then form the number.(as last column won't be followed by a ",".
				{ 
					while(p)
					{
						c = c + ((VAL[q]-'0') * pow10(p-1));
						p--; q++; 
					}
					if((c!=0))
					{
						cout<<"row="<<i<<"\tcolumn="<<col<<"\tvalue="<<c<<"\n";
						linkage(i,col,c); count++; c=0;
					}
					col++;
					p=0;          //p counts no. of element in substring VAL which become zero after end of row.
					
				}
			}
			i++; q=0;         //q is searching index for VAL string.
		}	
		cout<<"\n\nRows ="<<i<<"\n"<<"Columns="<<col<<"\tNo of NON ZERO elements: "<<count<<endl;
		of.close();
	}
	else
	cout<<"file not opened";
	
	display(i,col);
	
	return 0;
}	

/* ifstream of; 
 of.open("sparse.csv");
 if(of.is_open())
 { int i=0; cout<<"file open\n";
	 string a;
 while(getline(of,a))
  { int count=0;
   cout<<a<<"\t"; 
   for(int j=0;a[j]!='\0';j++)
   { if(a[j]==',') {count++; cout<<"\nj="<<count<<endl;}}
   i++;cout<<"\ni="<<i<<"\n";
  }
   cout<<"\nRows ="<<i;
   of.close();
 }
 else
 cout<<"file not opened";  
*/
/* int x,y,count=0;   //x->Rows, y->columns.
	
	cout<<"Enter array size in m*n:\t"<<endl;
	cin>>x>>y;
	
	int **ar;
	
	ar=new int*[x];
	
	for(int k=0;k<x;k++)
	ar[k]=new int[y];
	
	cout<<"Enter array:\n";
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<y;j++)
		 {
			 cout<<"\t";
			 cin>>ar[i][j];
			 if(ar[i][j]!=0)
			 {
				 linkage(i,j,ar[i][j]); count++;
		     }
		 }
		 cout<<endl;
	}*/
