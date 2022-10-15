#include<iostream>
using namespace std;
struct node
{   int val;
node *next;
};
int main()
{   int v,i;
    node *head=new node;
    node *t=new node;
    cout<<"Enter the value of head\n";
    cin>>v;
    head->val=v;
    head->next=NULL;
    t=head;
    char ch='y';
    while(ch=='Y'||ch=='y')
    {
       node *p=new node;
       cout<<"Enter the next value\n";
       cin>>v;
       p->val=v;
       p->next=NULL;
       t->next=p;
       t=p;
       cout<<"Enter more (Y/N)\n";
       cin>>ch;
    }
    cout<<"After linked\n";
    t=head;
    int count=0;
    while(t!=NULL)
    {
        cout<<t->val<<" ";
        t=t->next;
        count++;
    }
    cout<<"\nTotal number of nodes is="<<count;
    return 0;
    }
