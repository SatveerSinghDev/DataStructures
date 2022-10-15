#include<iostream>
#include<set>
#include<unordered_set>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{
unordered_set<int>AU;
set<int,greater<int>>AG;
char ch='Y';
int x,choice,ele,pwrsetsize,indicator,yes;
while((ch=='Y')||(ch=='y'))
{
cout<<"Enter element of the set(only integers): ";
cin>>x;
AU.insert(x);
AG.insert(x);
cout<<"More?<Y/N>";
cin>>ch;
}
unordered_set<int>::iterator itru;
set<int,greater<int> >::iterator itrg;
cout<<"The Set of AU is:";
for(itru=AU.begin();itru!=AU.end();++itru)
cout<<" "<<*itru;
cout<<"\n";
cout<<"The Set of AG is:";
for(itrg=AG.begin();itrg!=AG.end();++itrg)
cout<<" "<<*itrg;
cout<<"\nCardinality of set ="<<AU.size()<<"\n";
cout<<"\n...................................\n";
while(choice!=3)
{
cout<<"\n1.Test Membership\n";
cout<<"2.Show Powerset\n";
cout<<"3.Quit\n";
cout<<"Enter your choice:";
cin>>choice;
switch(choice)
{
case 1:cout<<"Element?:";
        cin>>ele;
        itru=AU.find(ele);
        if(itru==AU.end())
        cout<<ele<<" is not a member of set.\n";
        else
        cout<<ele<<" is a member of a set.\n";
        break;
case 2:cout<<"Powerset of the set is:\n{";
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
            if(indicator>2)
                cout<<*itru<<", ";
                else
                cout<<*itru;
            indicator=indicator/2;
            advance(itru,1);
        }
        if(k<pwrsetsize-1)
        cout<<"}, ";
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
