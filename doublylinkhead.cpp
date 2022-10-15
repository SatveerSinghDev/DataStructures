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
t=head;
node *newnode=new node;
cout<<"\nEnter value for new head node\n";
cin>>v;
newnode->val=v;
newnode->next=NULL;
newnode->prev=NULL;
head=newnode;
head->next=t;
t->prev=head;
t=head;
while(t!=NULL)
{
    cout<<t->val<<" ";
    t=t->next;
}
return 0;
}
