#include<iostream>
using namespace std;
struct node
{
    int val;
    node *prev;
    node *next;
};
int main()
{
    int v;
    node *head=new node;
    node *t=new node;
    cout<<"Enter the value of head\n";
    cin>>v;
    head->val=v;
    head->prev=NULL;
    head->next=NULL;
    t=head;
    char ch='y';
    while(ch=='Y'||ch=='y')
    {
        node *p=new node;
        cout<<"Enter the value of next node\n";
        cin>>v;
        p->val=v;
        p->prev=NULL;
        p->next=NULL;
        t->next=p;
        p->prev=t;
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
    int x,y;
    cout<<"\nEnter two values\n";
    cin>>x>>y;
    t=head;
    node *q=new node;
    q=head;
    node *newnode=new node;
    cout<<"Enter new value for new node\n";
    cin>>v;
    newnode->val=v;
    newnode->next=NULL;
    newnode->prev=NULL;
    while(t!=NULL)
    {
        if((t->val==x)&&((t->next)->val==y))
        {(t->next)->prev=newnode;
        newnode->next=t->next;
        t->next=newnode;
        newnode->prev=t;
        }
        else
            {
            t=t->next;

            }

    }
    t=head;
    while(t!=NULL)
    {

        cout<<t->val<<" ";
        t=t->next;
    }
    return 0;
}
