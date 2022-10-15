#include <iostream>
#include <cstdlib>
using namespace std;
struct node	
{
	int val;
	node *next;
};



node *t=new node;
node *rear=(node*)malloc(sizeof(node));
node *front=(node*)malloc(sizeof(node));

void traverse()	
{
	if(front!=NULL)
	{
		cout<<"\nLinked List:\t";
		while(t!=NULL)
		{
			cout<<t->val<<'\t';
			t=t->next;
		}
		t=front;
		cout<<'\n';
	}
	else
	{
		cout<<"\nQueue is Empty";
	}
	
}

void pop()
{
	if(front!=rear)
	{
		node *s=new node;
		front=t->next;
		int i=front->val;
		s=t;
		t=front;
		delete s;
		cout<<"\n"<<i<<" is Popped\n";
		traverse();
	}
	else
	{
		int x=front->val;
		cout<<"\n"<<x<<" is Popped\n";
		front=NULL;
		rear=NULL;
		cout<<"\nQueue is Empty\n";
		
	}
	
}
void push(int i)	
{	
	node *n2=(node*) malloc(sizeof(node));
	if(n2!=NULL)
	{
		if(front==NULL)
		{
			front=n2;
			front->val=i;
			front->next=NULL;
			rear=front;
			t=front;
			cout<<"\n"<<i<<" is Pushed in Queue \n";
			traverse();
		}
		else
		{
			n2->val=i;
			n2->next=NULL;
			rear->next=n2;
			rear=n2;
			cout<<"\n"<<i<<" is Pushed in Queue \n";
			traverse();
		}
	}
	
	else
	{
		cout<<"\nQueue Overflow\n";
		exit(0);
	}
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
	front->val=a[0];
	front->next=NULL;
	t=front;			
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
	
	rear=t;
	t=front;
	//traverse();
	push(45);
	//pop();
	for (int i = 0; i <6 ; i++)
	{
			pop();
	}
	//traverse();
	push(69);
	//push(71);
	//while(true)
	//{
		//push(69);
	//}
}

