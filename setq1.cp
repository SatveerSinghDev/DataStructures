#include<iostream>
#include<set>
#include<algorithm>
#include<unordered_set>
#include<iterator>
#include<cmath>
using namespace std;

int main()
{
  unordered_set<int>AU;//an unordered set
  set<int,greater<int> >AG; //an ordered set
  char ch='Y';
  int x,choice,ele,pwrsetsize,indicator,yes;
  while((ch=='Y')||(ch=='y'))
  {
  cout<<"enter element of set(integers):\t";
  cin>>x;
  AU.insert(x);
  AG.insert(x);
  cout<<"more?<Y/N>";
  cin>>ch;
  }
  unordered_set<int>::iterator itru;
  set<int,greater<int> >::iterator itrg;
  cout<<"the set AU is:";
  for(itru=AU.begin();itru!=AU.end();++itru)
  cout<<"\t"<<*itru;
  cout<<"\n";
  cout<<"the set AG is:";
  for(itrg=AG.begin();itrg!=AG.end();++itrg)
  cout<<"\t"<<*itrg;
  cout<<"\ncardinality of set= "<<AU.size()<<"\n";
  cout<<"\n-------------------------\n";
  while(choice!=3)
  {
   cout<<"\n 1.test membership\n";
   cout<<" 2.show powerset\n";
   cout<<"3.quit\t\t";
   cin>>choice;
   switch(choice)
   {
   case 1:cout<<"element?\t";
   cin>>ele;
   itru=AU.find(ele);
   if(itru==AU.end())
    cout<<ele<<"is not a member\n";
    else
    cout<<ele<<"is a member\n";
    break;
   case 2:cout<<"powerset of set is:\n{";
   pwrsetsize=pow(2,AU.size());
   for(int k=0;k<pwrsetsize;k++)
   {
   cout<<"{";
   indicator=k;
   itru=AU.begin();
   while(indicator>0)
   {
   yes=indicator%2;
   if(yes==1)
    if(indicator>2)//to remove the redundant ,after last element
    cout<<*itru<<",";
    else
    cout<<*itru;
    indicator=indicator/2;
    advance(itru,1);
   }
   if(k<pwrsetsize-1)//just to remove redundant ','in end
   cout<<"},";
   else
   cout<<"}";
   }
   cout<<"}\n";
   break;
   case 3:break;
   default: ;
   }
   }
   return 1;
  }
