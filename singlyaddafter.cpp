#include<iostream>
using namespace std;
struct node{
int val;
node *next;
};
int main()
{
int i,v;
node *head=new node;
node *t=new node;
cout<<"Enter first value\n";
cin>>v;
head->val=v;
head->next=NULL;
t=head;
char ch='y';
while(ch=='y'||ch=='Y')
{
node *p=new node;
cout<<"Enter next value\n";
cin>>v;
p->val=v;
p->next=NULL;
t->next=p;
t=p;
cout<<"Enter more(y/n)\n";
cin>>ch;
}
t=head;
cout<<"After linked\n";
while(t!=NULL)
{
    cout<<t->val<<" ";
    t=t->next;
}
cout<<"Enter value of node which u want to add after it\n";
cin>>v;
bool found=false;
t=head;
while((t!=NULL)&&(!found))
{
    if(t->val==v)
        found=true;
    else
        t=t->next;

}
if(!found)
    cout<<"Value is not found\n";
else
{
node *r=new node;
r=t->next;
node *newnode=new node;
cout<<"\nEnter value of new node\n";
cin>>v;
newnode->val=v;
newnode->next=NULL;
t->next=newnode;
newnode->next=r;
}
t=head;
while(t!=NULL)
{
    cout<<t->val<<" ";
    t=t->next;
}
return 0;
}
