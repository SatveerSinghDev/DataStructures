#include <iostream>
using namespace std;

template <class T>
class node	
{
	public:
		T val;
		node<T> *next;
};

node<int> *t=new node<int>;
node<int> *rear=(node<int>*)malloc(sizeof(node<int>));
node<int> *front=(node<int>*)malloc(sizeof(node<int>));
int n;


void traverse()	
{
	if(front!=NULL)
	{
		cout<<"\nLinked List:\t";
		cout<<t->val<<'\t';
		t=t->next;
		if(t!=NULL)
		{
			while(t!=front)
			{
				cout<<t->val<<'\t';
				t=t->next;
			}
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
		node<int> *s=new node<int>;
		int i=front->val;
		front=t->next;
		s=t;
		t=front;
		delete s;
		rear->next=front;
		cout<<"\n"<<i<<" is Popped\n";
		traverse();
		n--;
	}
	else
	{
		int x=front->val;
		cout<<"\n"<<x<<" is Popped\n";
		
		cout<<"\nQueue is Empty\n";
		front=NULL;
		rear=NULL;
	}
}
void push(int i)	
{	
	node<int> *n2=(node<int>*) malloc(sizeof(node<int>));
	//if(n2!=NULL)
	//{
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
			n2->next=front;
			rear->next=n2;
			rear=n2;
			cout<<"\n"<<i<<" is Pushed in Queue \n";
			traverse();
		}
		n++;
	
	
	//else
	//{
		//cout<<"\nQueue Overflow\n";
		//exit(0);
	//}
}

//--------------------MAIN LOOP------------------------------

int main()
{
	
	cout<<"\nEnter no. of elements of the Linked List:";
	cin>>n;
	int a[n+2];
	
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
		node<int> *p=new node<int>;
		t->next=p;
		p->val=a[i];
		p->next=NULL;
		t=p;
		++i;
	}
	cout<<"\nYour Linked list\n";
	
	rear=t;
	rear->next=front;
	
	t=front;
	traverse();
	
	//cout<<rear->next->val;
	
	push(45);
	//pop();
	int l=n;
	for (int i = 0; i <l ; i++)
	{
			pop();
	}
	//////traverse();
	push(69);
	//while(true)
	//{
		//push(69);
	//}
}

