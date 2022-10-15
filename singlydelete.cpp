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
    cout<<"\nEnter value which u want to delete\n";
    cin>>v;
    t=head;
    bool found=false;
    node *q=new node;
    q=head;
    if(t->val!=v)
    t=t->next;
    while((t!=NULL)&&(!found))
    {
        if(t->val==v)
        found=true;
        else
        {
        t=t->next;
        q=q->next;
        }
    }
    if(!found)
    cout<<"\nValue is not found\n";
    else
   { q->next=t->next;
   delete(t);
   }
   t=head;
   while(t!=NULL)
   {cout<<t->val<<" ";
   t=t->next;
   }
   return 0;
   }
