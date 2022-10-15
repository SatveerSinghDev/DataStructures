#include<iostream>
#include<iterator>
#include<set>
#include<unordered_set>
using namespace std;
int main()
{
unordered_set<int> u,ua;
set<int,greater<int>> s,sa,sb,s1,s2,s3,s4,s5,s6,s9;

int x,y,n,n1,count=0,c=0;
char ch='Y',ch1='y';
while(n!=1)
{
    cout<<"1.Input elements for set 1 and set 2\n";
    cout<<"Press 1 for input:";
    cin>>n;
switch(n)
{case 1:    while((ch=='Y')||(ch=='y'))
            {cout<<"Enter the element of set 1:";
            cin>>x;
            u.insert(x);
            s.insert(x);
            cout<<"More? for set 1 (y/n):";
            cin>>ch;
            }


case 2:    cout<<"\n";
            while((ch1=='Y')||(ch1=='y'))
            {
            cout<<"Enter the elements of set 2:";
            cin>>y;
            ua.insert(y);
            sa.insert(y);
            cout<<"More? for set 2 (y/n):";
            cin>>ch1;
            }

default:  break;

}
}
unordered_set<int>::iterator itu;
set<int,greater<int>>::iterator its,i,j,it;
cout<<"\nUnordered set 1: ";
for(itu=u.begin();itu!=u.end();itu++)
cout<<*itu<<" ";
cout<<"\nUnordered set 2: ";
for(itu=ua.begin();itu!=ua.end();itu++)
cout<<*itu<<" ";
cout<<"\nOrdered set 1: ";
for(its=s.begin();its!=s.end();its++)
cout<<*its<<" ";
cout<<"\nOrdered set 2: ";
for(its=sa.begin();its!=sa.end();its++)
cout<<*its<<" ";
cout<<"\nCardinality of set 1 is="<<s.size();
cout<<"\nCardinality of set 2 is="<<sa.size();
cout<<"\n............................................\n";
while(n1!=8)
{   cout<<"\nSelect one of them";
    cout<<"\n1.Subset.Check whether one set is subset of other or not";
    cout<<"\n2.Union of set 1 and set 2";
    cout<<"\n3.Intersection of set 1 and set 2";
    cout<<"\n4.Complement of set Assume universal set as per the inputs elements of sets";
    cout<<"\n5.Set difference of two sets";
    cout<<"\n6.Symmteric difference of two sets";
    cout<<"\n7.Cartesian product of two sets";
    cout<<"\n8.Quit";
    cout<<"\n.....................................................\n";
    cout<<"\nEnter your choice:";
    cin>>n1;


    switch(n1)
    {
        case 1:         cout<<"Ordered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                        cout<<*its<<" ";
                if(s.size()<sa.size())
                  {

                   for(i=s.begin();i!=s.end();i++)
                    {for(j=sa.begin();j!=sa.end();j++)
                        if(*i==*j)
                        count++;
                    }
                    if(count==s.size())
                        cout<<"\nSet 1 is the subset of Set 2";
                        else
                            cout<<"\nSet 1 is not the subset of Set 2";
                    cout<<"\n..............................................\n";
                  }
            else if(s.size()>sa.size())
                  {

                      for(i=sa.begin();i!=sa.end();i++)
                    {for(j=s.begin();j!=s.end();j++)
                        if(*i==*j)
                        c++;
                    }
                    if(c==sa.size())
                        cout<<"\nSet 2 is the subset of Set 1";
                        else
                            cout<<"\nSet 2  is not the subset of Set 1";
                    cout<<"\n..............................................\n";
                  }
                  else
                  {
                      for(i=s.begin();i!=s.end();i++)
                      {
                          for(j=sa.begin();j!=sa.end();j++)
                            if(*i==*j)
                            c=1;
                          else
                            c=0;
                      }
                      if(c==1)
                        cout<<"\nTwo Sets are equivalence and equal sets";
                      else
                        cout<<"\nTwo Sets are equivalence but not equal sets";
                  }
                  cout<<"\n.....................................................\n";
                  break;

    case 2:       for(its=s.begin();its!=s.end();its++)
                        {
                            sb.insert(*its);

                        }
                    for(its=sa.begin();its!=sa.end();its++)
                    {
                        sb.insert(*its);
                    }
                        cout<<"\nUnion has "<<sb.size()<<" elements\n";
                        cout<<"Union of Set 1 and Set 2:";
                        for(its=sb.begin();its!=sb.end();its++)
                            cout<<*its<<" ";
                            cout<<"\n...............................\n";
                    break;
        case 3 :     cout<<"Ordered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                        cout<<*its<<" ";
                    for(i=s.begin();i!=s.end();i++)
                        {for(j=sa.begin();j!=sa.end();j++)
                            if(*i==*j)
                                s1.insert(*i);
                                else
                                    c++;
                        }
                        if((s.size()*sa.size())==c)
                            cout<<"\nDoes not have any common element in both sets";
                        else
                        {
                            cout<<"\nIntersection of two sets are:";
                        for(its=s1.begin();its!=s1.end();its++)
                        cout<<*its<<" ";
                        }
                    cout<<"\n.........................................\n";
                    break;
        case 4:
                    cout<<"\nEnter the set number for complement(1/2)";
                    int p;
                    cin>>p;
                    if(p==1)
                    {
                        cout<<"Ordered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                        cout<<*its<<" ";
                         for(its=s.begin();its!=s.end();its++)
                        {
                            sb.insert(*its);
                        }
                    for(its=sa.begin();its!=sa.end();its++)
                    {
                        sb.insert(*its);
                    }
                    cout<<"\nUniversal set U=";
                      for(its=sb.begin();its!=sb.end();its++)
                        cout<<*its<<" ";
                        for(its=s.begin();its!=s.end();its++)
                            sb.erase(*its);
                        cout<<"\nComplement of Set 1 is=";
                        for(its=sb.begin();its!=sb.end();its++)
                        cout<<*its<<" ";

                    }
                    else if(p==2)
                    {
                        cout<<"\nOrdered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                        cout<<*its<<" ";
                         for(its=s.begin();its!=s.end();its++)
                        {
                            sb.insert(*its);
                        }
                    for(its=sa.begin();its!=sa.end();its++)
                    {
                        sb.insert(*its);
                    }
                    cout<<"\nUniversal set U=";
                        for(its=sb.begin();its!=sb.end();its++)
                            cout<<*its<<" ";
                        for(its=sa.begin();its!=sa.end();its++)
                            sb.erase(*its);
                            if(sb.size()==0)
                            {
                                cout<<"\nComplement of Set 2 is=Null";

                            }
                            else
                            {cout<<"\nComplement of Set 2 is=";
                        for(its=sb.begin();its!=sb.end();its++)
                            cout<<*its<<" ";
                    }
                    }
                    else
                        cout<<"Wrong choice!!";
                        cout<<"\n.............................\n";
                    break;

    case 5:         int k;
                    while(k!=3)
                    {cout<<"\nEnter option once at a time";
                    cout<<"\n1.Set 1 - Set 2\n";
                    cout<<"2.Set 2 - Set 1\n";
                    cout<<"3.Quit\n";
                    cout<<"Enter your choice for Set Difference:\n";
                    cin>>k;
                    if(k==1)
                            {  cout<<"Ordered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            s1.insert(*its);
                        for(its=s1.begin();its!=s1.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                            s2.insert(*its);
                        for(its=s2.begin();its!=s2.end();its++)
                        cout<<*its<<" ";

                            for(its=s2.begin();its!=s2.end();its++)
                            s1.erase(*its);
                            cout<<"\nSet difference for (Set 1 - Set 2) is=";
                            if(s1.size()==0)
                                cout<<"Null";
                            else
                            {
                            for(its=s1.begin();its!=s1.end();its++)
                            cout<<*its<<" ";
                            }
                            }
                    else if(k==2)
                            {
                                  cout<<"Ordered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            s3.insert(*its);
                        for(its=s3.begin();its!=s3.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                        s4.insert(*its);
                        for(its=s4.begin();its!=s4.end();its++)
                        cout<<*its<<" ";

                            for(its=s3.begin();its!=s3.end();its++)
                            s4.erase(*its);
                            cout<<"\nSet Difference for (Set 2 - Set 1) is=";
                            if(s4.size()==0)
                                cout<<"Null";
                            else
                            {
                                for(its=s4.begin();its!=s4.end();its++)
                                cout<<*its<<" ";
                            }

                            }
                        else
                        cout<<"\nEnter again";
                        cout<<"\n..............................................\n";
                        }
    case 6:         cout<<"Ordered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            s5.insert(*its);
                            for(its=s5.begin();its!=s5.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                        cout<<*its<<" ";
                        for(its=sa.begin();its!=sa.end();its++)
                            s5.erase(*its);
                        for(its=s.begin();its!=s.end();its++)
                            sa.erase(*its);
                        for(its=s5.begin();its!=s5.end();its++)
                            s6.insert(*its);
                        for(its=sa.begin();its!=sa.end();its++)
                            s6.insert(*its);
                    cout<<"\nSymmetric difference is=";
                    for(its=s6.begin();its!=s6.end();its++)
                        cout<<*its<<" ";
                    cout<<"\n........................................\n";
                    break;
    case 7:        cout<<"Ordered set 1: ";
                        for(its=s.begin();its!=s.end();its++)
                            cout<<*its<<" ";
                        cout<<"\nOrdered set 2: ";
                        for(its=sa.begin();its!=sa.end();its++)
                        cout<<*its<<" ";
                        for(i=s.begin();i!=s.end();i++)
                        {for(j=sa.begin();j!=sa.end();j++)
                                s9.insert((*i)*(*j));
                        }
                    cout<<"\nCartesian product is=";
                    for(its=s9.begin();its!=s9.end();its++)
                    cout<<*its<<" ";
                    cout<<"\n.....................................\n";
                    break;
        case 8:        cout<<"\nThank You";
                            break;

        default:        cout<<"\nWrong choice!!!!!!";
                            cout<<"\nEnter again";
                            break;

    }

}
return 0;
}
