#include <iostream>
using namespace std;
struct node	
{
	int val;
	node *next;
};

node *head=new node;
node *t=new node;
node *top=(node*)malloc(sizeof(node));
int n;
void traverse()	
{
	if(head!=NULL)
	{
		cout<<"\nLinked List:\t";
		while(t!=NULL)
		{
			cout<<t->val<<'\t';
			t=t->next;
		}
		t=head;
		cout<<'\n';
	}
	else
	{
		cout<<"\nStackis Empty";
	}
	
}

void pop()
{
	if(head!=top)
	{
		node *s=new node;
		s=head;
		while(s->next->next!=NULL)
			s=s->next;
		int x=s->next->val;
		delete s->next;
		s->next=NULL;
		top=s;
		cout<<"\n"<<x<<" is Popped\n";
		n--;
		traverse();
	}
	else
	{
		int x=head->val;
		n--;
		cout<<"\n"<<x<<" is Popped\n";
		top=NULL;
		head=NULL;
		cout<<"\nStack is Empty\n";
	}	
} 
void push(int i)	
{	
	cout<<"Hello";
	node *n2=(node*) malloc(sizeof(node));
	//if(n2!=NULL)
	//{
		if(head==NULL)
		{
			head=n2;
			head->val=i;
			head->next=NULL;
			top=head;
			t=head;
			cout<<"\n"<<i<<" is Pushed in Stack \n";
			n++;
			traverse();
		
		}
		else
		{
			n2->val=i;
			n2->next=NULL;
			top->next=n2;
			top=n2;
			cout<<"\n"<<i<<" is Pushed in Stack \n";
			n++;
			traverse();
		}
	//}
	
	//else
	//{
		//cout<<"\nStackOverflow\n";
		//exit(0);
	//}
}

//--------------------MAIN LOOP------------------------------

int main()
{
	
	cout<<"\nEnter no. of elements of the Linked List:";
	cin>>n;
	int a[n];
	
	
	cout<<"\nEnter Elements:";
	for (int i = 0; i <n ; i++)
	{	
		cin>>a[i];
	}
	head->val=a[0];
	head->next=NULL;
	t=head;			
	int i=1;
	while(i<n)
	{
		node *p=new node;
		t->next=p;
		p->val=a[i];
		p->next=NULL;
		t=p;
		++i;
	}
	cout<<"\nYour Linked list\n";
	
	top=t;
	t=head;
	push(45);
	for (int i = 0; i <n ; i++)
	{
			pop();
	}
	//push(23);
	//traverse();
	
}
