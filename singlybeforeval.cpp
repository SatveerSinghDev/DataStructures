#include<iostream>
using namespace std;
struct node
{   int val;
    node *next;
};
int main()
{
    node *head=new node;
    node *temp=new node;
    int v;
    cout<<"Enter the value\n";
    cin>>v;
    head->val=v;
    head->next=NULL;
    temp=head;
    char ch='y';
while(ch=='Y'||ch=='y')
{
    node *n=new node;
    cout<<"Enter the next value\n";
    cin>>v;
    n->val=v;
    n->next=NULL;
    temp->next=n;
    temp=n;
    cout<<"Enter more(Y/N)\n";
    cin>>ch;
}
temp=head;
cout<<"After linked\n";
while(temp->next!=NULL)
{
    cout<<temp->val<<" ";
    temp=temp->next;
}
cout<<temp->val;
temp=head;
bool found=false;
node *prev=new node;
node *newnode=new node;
prev=head;
cout<<"\nEnter the value\n";
cin>>v;
if(temp->val!=v)
    temp=temp->next;
while((temp!=NULL)&&(!found))
{
    if(temp->val==v)
        found=true;
    else
    {
        temp=temp->next;
        prev=prev->next;
    }
}
if(!found)
    cout<<"Value not found\n";
else
{
    cout<<"Enter the value a new node\n";
    cin>>v;
    newnode->val=v;
    newnode->next=NULL;
    prev->next=newnode;
    newnode->next=temp;
}
temp=head;
while(temp->next!=NULL)
{
    cout<<temp->val<<" ";
    temp=temp->next;
}
cout<<temp->val;
return 0;


}
