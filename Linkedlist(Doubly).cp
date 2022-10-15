#include <iostream>
using namespace std;
struct node		//creation of structure for node for linking
{
	int val;
	node *next;
	node *prev;
};
int found=0;	//to check whether the input is valid or invalid
void traverse_next(node *n)	//to traverse via next pointer 
{
	cout<<"Using next pointer:\t";
	while(n!=NULL)
	{
		
		cout<<n->val<<'\t';
		n=n->next;
	}
	cout<<'\n';
}
void traverse_prev(node *n)	//to traverse via prev pointer
{
	cout<<"Using prev pointer:\t";
		
	while(n!=NULL)
	{
		cout<<n->val<<'\t';
		n=n->prev;
	}
	cout<<'\n';
}
node* Del(node *n,int x)	//to Delete an element from the linked list which would be input by the user
{
	node* Delf(node *n);
	node* Dell(node *n);
	if(n->val==x)
	{
		found=1;
		return Delf(n);
	}
	
	node *s=new node;
	s=n;
	while(n->next!=NULL)
	{
		n=n->next;
	}
	
	if(n->val==x)
	{
		found=1;
		n=s;
		return Dell(s);
	}
	n=s;
	while(n->next!=NULL)
	{
		if(n->next->val==x)
		{
			found=1;
			node *p=new node;
			p=n->next->next;
			n->next->next->prev=n;
			delete n->next;
			n->next=p;	
		}
		n=n->next;
	}
	
	if(found){
		traverse_next(s);
		traverse_prev(n);
	}
	else
		cout<<"Invalid Input";
	return s;
}
node* Delf(node *n)	//to delete first element from the list
{
	node *s=new node;
	s=n->next;
	s->prev=NULL;
	delete n;
	node *p=new node;
	p=s;
	while(s->next!=NULL)
		s=s->next;
	traverse_next(p);
	traverse_prev(s);
	return p;
}
node* Dell(node *n)	//to delete last element from the list 
{
	node *s=new node;
	s=n;
	node *p=new node;
	while(s->next!=NULL)
		s=s->next;
	p=s->prev;;
	p->next=NULL;
	delete s;
	
	traverse_next(n);
	traverse_prev(p);
	return n;
}

node* addlast(node *n)	//to add an element at last position
{
	node *s=new node;
	s=n;
	int i;
	cout<<"\nEnter the element you want to add at last:";
	cin>>i;
	while(n->next!=NULL)
		n=n->next;		
	node *p=new node;
	p->val=i;
	n->next=p;
	p->prev=n;
	p->next=NULL;
	traverse_next(s);
	traverse_prev(p);
	return s;
}
node* addfirst(node *n)	//to add an element at first position
{
	int i;
	cout<<"\nEnter the element you want to add at first:";
	cin>>i;
	cout<<"After Adding "<<i<<" at first\n";
	node *p=new node;
	p->val=i;
	p->prev=NULL;
	p->next=n;
	n->prev=p;

	while(n->next!=NULL)
	{
		n=n->next;
	}
	traverse_next(p);
	traverse_prev(n);
	return p;
}
node* insert(node *n,int x)	//to insert an element after a specified element
{
	node* addlast(node *n);
	node *s=new node;
	s=n;
	found=0;
	while(n->next!=NULL)
	{
		n=n->next;
	}
	
	if(n->val==x)
	{
		found=1;
		n=s;
		return addlast(n);
	}
	
	node *p=new node;
	n=s;	
	while(n->next!=NULL)
	{
		if(n->val==x)
		{
			int y;
			cout<<"\nEnter element you want to insert:";
			cin>>y;
			found=1;
			p->val=y;
			p->next=n->next;
			n->next->prev=p;
			n->next=p;
			p->prev=n;
		}
		n=n->next;
	}
	if(found)
	{
		traverse_next(s);
		traverse_prev(n);
	}
	else
		cout<<"Invalid Input";
	return s;
}
node* insertn(node *n,int x)	//to insert an element after a specified position
{
	found=0;
	node *s=new node;
	node* addlast(node *n);
	s=n;
	int count=1;

	while(n->next!=NULL)
	{
		++count;
		n=n->next;
	}
	
	if(count==x)
	{
		found=1;
		n=s;
		return addlast(n);
	}
	n=s;	
	count=0;
	while(n->next!=NULL)
	{
		++count;
		if(count==x)
		{
			int y;
			cout<<"\nEnter element you want to insert:";
			cin>>y;
			found=1;
			node *p=new node;
			p->val=y;
			p->prev=n;
			n->next->prev=p;
			p->next=n->next;
			n->next=p;
		}
		n=n->next;
	}

	if(found)
	{
		traverse_next(s);
		traverse_prev(n);
	}
	else
		cout<<"Invalid Input";
	return s;
	
}
node* insertn2(node *n,int x)	//to insert an element at a specified position
{
	found=0;
	node *s=new node;
	s=n;
	int count=1;
	if(x==1)
	{
		found=1;
		return addfirst(n);
	}
	while(n->next!=NULL)
	{
		++count;
		n=n->next;
	}	
	if(count==x)
	{
		found=1;
		return insertn(s,x-1);
	}
	if(count+1==x)
	{
		found=1;
		n=s;
		return addlast(s);
	}
	
	n=s;	
	count=0;
	while(n->next!=NULL)
	{
		++count;
		if(count==x)
		{
			int y;
			cout<<"\nEnter element you want to insert:";
			cin>>y;
			found=1;
			node *p=new node;
			p->val=y;
			p->next=n;
			p->prev=n->prev;
			n->prev->next=p;
			n->prev=p;
		}
		n=n->next;
	}

	if(found)
	{
		traverse_next(s);
		traverse_prev(n);
	}
	else
		cout<<"Invalid Input";
	return s;
	
}
//--------------------MAIN LOOP------------------------------
int main()
{
	int n;
	cout<<"\nEnter no. of elements of the Linked List:";
	cin>>n;
	int a[n];
	cout<<"\nEnter Elements:";
	for (int i = 0; i <n ; i++)
	{	
		cin>>a[i];
	}
	node *head=new node;	//creation of head
	node *tail=new node;	//creation of tail
	node *t=new node;
	head->val=a[0];
	head->next=NULL;
	head->prev=NULL;
	t=head;					//creation of copy of head
	int i=1;
	while(i<n)
	{
		node *p=new node;
		p->val=a[i];
		p->next=NULL;
		p->prev=t;
		t->next=p;
		t=p;
		i++;
	}
	tail=t;
	cout<<"\nYour Linked list\n";	//Linked list After Construction
	t=head;
	traverse_next(t);
	traverse_prev(tail);
	
//---------------------------------------------MENU DRIVEN LOOP---------------------------------------------
	int c;
	char ch='Y';
	while(ch=='Y' || ch=='y')
	{
		cout<<"\n\nBelow are the actions you can perform on your Linked List\n\n"<<"1.Add at first\n2.Add at last\n3.Insert after x(Specify x)\n4.Insert after xth position\n5.Insert at xth position\n6.Delete x(specify x)\n7.Delete first element\n8.Delete last element\n0.To exit\n";
		cout<<"\nEnter Your choice:";
		cin>>c;
		if(c==1){
			t=addfirst(t);
		}
		else if(c==2)
		{
			t=addlast(t);
		}
		
		else if(c==3)
		{
			int x;
			cout<<"\nEnter x:";
			cin>>x;
			t=insert(t,x);
		}
		else if(c==4)
		{
			int x;
			cout<<"\nEnter x:";
			cin>>x;
			t=insertn(t,x);	
		}
		else if(c==5)
		{
			int x;
			cout<<"\nEnter x:";
			cin>>x;
			t=insertn2(t,x);	
		}
		else if(c==6)
		{
			int x;
			cout<<"\nEnter x:";
			cin>>x;
			t=Del(t,x);
		}
		
		else if(c==7)
		{
			t=Delf(t)	;
		}
		else if(c==8)
		{
			t=Dell(t)	;
		}
		else if(c==0)
		{
			cout<<"THANK YOU FOR USING THIS PROGRAM";
			ch='N';
		}
		else
			cout<<"Wrong input for choice";
	}
}
