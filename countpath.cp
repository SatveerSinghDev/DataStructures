#include<iostream>
using namespace std;
#define MAX 10

int g[MAX][MAX];

int countpaths(int graph[][MAX],int V,int u,int v,int k)
{
 if(k==0&&u==v)
  return 1;
 if(k==1&& graph[u][v])
  return 1;
  if(k<=0)
  return 0;
  int pcount=0;
  for(int i=0;i<V;i++)
   if(graph[u][i]==1)
   pcount=pcount+ countpaths(graph,V,i,v,k-1);
   return pcount;
}   
int main()
{
int V,src,dest,k,choice,t;
cout<<"no of vertices in the graph=";
cin>>V;
if(V<=MAX)
{
	cout<<"enter the adjacency matrix of graphrow wise";
	for(int i=0;i<V;i++)
	 for(int j=0;j<V;j++)
	 cin>>g[i][j];
	 while(1)
	 {
	  cout<<"\n source vertex no.?";
	  cin>>src;
	  cout<<"\n destination vertex no.?";	 
      cin>>dest;
      cout<<"\n path length?"; 
      cin>>k;
      cout<<"\n number of paths of length"<<k<<countpaths(g,V,src,t,k);
      cout<<"\n another?.. or enter 'Q' to quit";
      cin>>choice;
      if((choice=='Q')||(choice=='q'))
      break;
     }
}
  else
    cout<<"graph is larger than expected\n";
    return 1;
 }    
       
