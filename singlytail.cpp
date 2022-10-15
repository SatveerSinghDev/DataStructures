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
    while(t!=NULL)
    {
        cout<<t->val<<" ";
        t=t->next;
    }
     node *n=new node;
            cout<<"\nEnter the value of new node which u want to add on tail\n";
            cin>>v;
            n->val=v;
            n->next=NULL;
    t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->next=n;
    t=head;
    while(t!=NULL)
    {

        cout<<t->val<<" ";
        t=t->next;
    }
    return 0;
}
