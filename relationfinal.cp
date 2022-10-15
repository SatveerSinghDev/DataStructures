#include<iostream>
using namespace std;

class Relation
{ 
public:
  int a[10][10],m,i,j,k,r=1,ir=1,s=1,ans=1,tr=1;
  int reflexive();
  int symmetric();
  int transitive();
  int relation();
  int order();
};

 int Relation::reflexive()
 {

  for(i=0;i<m;i++)
  {
   if(a[i][i]!=1)
   r=0;
  }
}

int Relation::symmetric()
 {
   for(i=0;i<m;i++)
   {
     if(( a[i][j]==1)&&(a[j][i]!=1))
     s=0;
     if((a[i][j]==1)&&(a[j][i]==1&&(i!=j)))
     ans=0;
   }
 }
 int Relation::transitive()
 {
     for(i=0;i<m;i++)
     for(j=0;j<m;j++)
     for(k=0;k<m;k++)
     if((a[i][j]==1)&&(a[j][k]==1)&&(a[i][k]!=1))
     tr=0;
 }
 int Relation::relation()
 {
     cout<<"enter the relation in matrix format(0/1):\n";
     for(i=0;i<m;i++)
     for(j=0;j<m;j++)
     cin>>a[i][j];
 }
 int Relation::order()
 {
     cout<<"enter the order of square matrix:\n";
     cin>>m;
 }

 int main()
 {
   int q,w,t,y;
   Relation a1;
   a1.order();
   a1.relation();
   
   a1.reflexive();
   q=a1.r;
   if(q==1)
   {
       cout<<"relation is reflexive\n";
   }
   else
       cout<<"relation is not reflexive\n";
   
   a1.symmetric();
   w=a1.s;
   t=a1.ans;
   if(w==1)
   {
       cout<<"relation is symmetric\n";
   }
   if(t==1)
   {cout<<"relation is antisymmetric\n";}
   else
   {
     cout<<"relation is not antisymmetric\n";
   }
   if((w!=1)&&(t!=1))
   cout<<"relation is not symetric\n";
   
   a1.transitive();
   y=a1.tr;
   if(y==1)
   cout<<"relation is transitive\n";
   else
   cout<<"relation is not transitive\n";
   
   if(q==1 && w==1 && y==1)
      cout<<"relation is equivalent"<<"\n";
   
   if(q==1 && t==1 && y==1)
      cout<<"partial order relation"<<"\n";
   
   
 }
