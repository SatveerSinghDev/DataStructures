#include<iostream>
using namespace std;
struct node
{
    int val;
    node *next;
    node *prev;
};
int main()
{int v;
node *head=new node;
node *t=new node;
cout<<"Enter a value of head\n";
cin>>v;
head->val=v;
head->next=NULL;
head->prev=NULL;
t=head;
char ch='y';
while(ch=='y'||ch=='Y')
{
    node *p=new node;
    cout<<"Enter next value\n";
    cin>>v;
    p->val=v;
    p->next=NULL;
    p->prev=NULL;
    t->next=p;
    p->prev=t;
    t=p;
    cout<<"Enter more (Y/N)\n";
    cin>>ch;
}
t=head;
while(t!=NULL)
{
    cout<<t->val<<" ";
    t=t->next;
}
cout<<"\nEnter a value which u want to before it\n";
cin>>v;
t=head;
node *q=new node;
q=head;
bool found=false;
if(t->val!=v)
    t=t->next;
while((t!=NULL)&&(!found))
{
    if(t->val==v)
    {
        found=true;
    }
    else
    {
        t=t->next;
       q=q->next;
    }

}
if(!found)
    cout<<"Value not found\n";
else
{ node *newnode=new node;
    cout<<"Enter a new value\n";
    cin>>v;
    newnode->val=v;
    newnode->next=NULL;
    newnode->prev=NULL;
    (q->next)->prev=newnode;
    newnode->next=t;
    q->next=newnode;
    newnode->prev=q;
}
t=head;
while(t!=NULL)
{

    cout<<t->val<<" ";
    t=t->next;
}
return 0;
}
