#include<iostream>
using namespace std;
class Relation
{public:
    int arr[10][10];
    int r=1,tr=1,ans=1,s=1,i,j,k,n;
    int relation();
    int reflexive();
    int symmetric();
    int antisymmetric();
    int transitive();
    int order();
};
int Relation::reflexive()
{
    for(i=0;i<n;i++)
    {
    if(arr[i][i]!=1)
    r=0;
    }
}
int Relation::symmetric()
{
    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
    {if(arr[i][j]!=arr[j][i])
    s=0;
    }
    }
}
int Relation::antisymmetric()
{
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {if((arr[i][j]==arr[j][i])&&(i!=j))
    ans=0;
    }
}
int Relation::transitive()
{
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    for(k=0;k<n;k++)
    {
        if((arr[i][j]==arr[j][k])&&(arr[j][k]!=arr[i][k]))
        tr=0;
    }
}
int Relation::order()
{
    cout<<"Enter the order of square matrix: ";
    cin>>n;
}
int Relation::relation()
{
    cout<<"\nEnter the relation in matrix(0/1)\n";
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>arr[i][j];
    cout<<"Your relation are in matrix notation(0/1)\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main()
{ int R,S,ANS,TR;
Relation a1;
a1.order();
a1.relation();
a1.reflexive();
R=a1.r;
if(R==1)
cout<<"\nRelation is reflexive";
else
cout<<"\nRelation is not reflexive";
a1.symmetric();
S=a1.s;
if(S==1)
cout<<"\nRelation is symmetric";
else
cout<<"\nRelation is not symmetric";
a1.antisymmetric();
ANS=a1.ans;
if(ANS==1)
cout<<"\nRelation is antisymmetric";
else
cout<<"\nRelation is not antisymmetric";
a1.transitive();
TR=a1.tr;
if(TR==1)
cout<<"\nRelation is transitive";
else
    cout<<"\nRelation is not transitive";
if((R==1)&&(S==1)&&(TR==1))
cout<<"\nEquivalence relation";
else
    cout<<"\nRelation is not equivalence";
if((R==1)&&(ANS==1)&&(TR==1))
cout<<"\nPartial order relation";
else
    cout<<"\nRealtion is not partial order";
return 0;
}
