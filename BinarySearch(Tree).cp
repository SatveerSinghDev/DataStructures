#include <iostream>
using namespace std;
struct node
{
	int info;
	node *right;
	node *left;
	node *thread;
};

node *root=new node;
node *t;
node *delt=new node;

bool found=false;
bool leftmost=false;
void add2(int x,node *t2)
{
	if(root==NULL)
	{
		node *p=new node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;

		root=p;
		return;
	}
	else
	{
		if(t2->info>x)
		{
			if(t2->left!=NULL)
				add2(x,t2->left);
			else
			{
				node *p=new node;
				p->info=x;
				p->left=NULL;
				p->right=NULL;

				t2->left=p;
				p->thread=t2;
			}
		}
		else if(t2->info<x)
		{
			if(t2->right!=NULL)
				add2(x,t2->right);
			else
			{
				node *p=new node;
				p->info=x;
				p->left=NULL;
				p->right=NULL;
				t2->right=p;
				p->thread=t2;
			}
		}
	}
}
void preorder(node *temp3)
{
	if(temp3==NULL)
		return;
	cout<<temp3->info<<"\t";
	preorder(temp3->left);
	preorder(temp3->right);
}
void inorder(node * temp3)
{
	if(temp3==NULL)
		return;

	inorder(temp3->left);

	if(t==NULL)
	{
		t=temp3;
	}
	else
	{
		t->thread=temp3;
		cout<<"\nThread:"<<t->info<<" Successor:"<<t->thread->info;
		t=temp3;
	}
	inorder(temp3->right);
	cout<<"\n";
}

node *leftm=new node;

void inorder2(node * temp3)
{
	if(temp3==NULL)
		return;
	inorder2(temp3->left);
	if(leftmost==false)
	{
		leftm=temp3;
		leftmost=true;
	}
	cout<<temp3->info<<"\t";
	inorder2(temp3->right);
}

void postorder(node * temp3)
{
	if(temp3==NULL)

	return;
	postorder(temp3->left);
	postorder(temp3->right);
	cout<<temp3->info<<"\t";
}

node* min2=NULL;

node* search2(node* p)
{
	if(min2==NULL)
		min2=p;
	if(p->info<min2->info)
	{
		min2=p;
	}
	else
	{
		if(p->left!=NULL)
			p=search2(p->left);
	}
	return min2;
}
bool del2(int x)
{
	while(leftm!=t)
	{
		if(leftm->info==x)
		{
			leftm=leftm->thread;
			return true;
		}
 		else if(leftm->thread->info==x)
		{
			leftm->thread=leftm->thread->thread;
			return true;
		}
		leftm=leftm->thread;
	}
	return false;
}

bool del(node *tree,int x)
{
	if(x==root->info)
	{
		if(root->left!=NULL && root->right!=NULL)
		{
			node* y=new node;
			node* temp=new node;
			y=root->left;
			root=root->right;
			temp=root;
			while(temp->left!=NULL)
				temp=temp->left;
			temp->left=y;
		}
		else if(root->left!=NULL && root->right==NULL)
			root=root->left;

		else if(root->left==NULL && root->right!=NULL)
			root=root->right;

		else if(root->right==NULL && root->left==NULL)
			root=0;
		return true;
	}
	if(tree==NULL)
		return found;


	if(tree->info==x)
	{
		if(tree->left==NULL && tree->right==NULL)
		{
			found=del2(x);
			//cout<<"\ndelt->info:"<<delt->info<<" tree->info="<<tree->info;
			if(delt->left==tree)
			{
				delt->left=NULL;
			}
			else if(delt->right==tree)
			{
				delt->right=NULL;
			}
		}

		else if(tree->left!=NULL && tree->right==NULL)
		{

			found=del2(x);
			cout<<"\nleft!=NULL  delt->info:"<<delt->info<<" tree->info="<<tree->info;

			if(delt->left==tree)
			{
				delt->left=delt->left->left;
			}

			else if(delt->right==tree)
			{
				node *temp;
				temp=delt->right->left;
				delete delt->right;
				delt->right=temp;
			}
			return found;
		}
		else if(tree->left==NULL && tree->right!=NULL)
		{

			found=del2(x);
			cout<<"\nright!=NULL :delt->info:"<<delt->info<<" tree->info="<<tree->info;

			if(delt->left==tree)
			{
				node *temp;
				temp=delt->left->right;
				delete delt->left;
				delt->left=temp;
			}
			else if(delt->right==tree)	
			{
				node *temp;
				temp=delt->right->right;
				delete delt->right;
				delt->right=temp;
			}
			return found;
		}

		else if(tree->left!=NULL && tree->right!=NULL)
		{
			found=del2(x);
			cout<<"\nright!=NULL  left!=NULL:delt->info:"<<delt->info<<" tree->info="<<tree->info;

			if(delt->left==tree)						//Done
			{
				node *temp;
				temp=delt->left->right;
				delete delt->left;
				delt->left=temp;
			}
			else if(delt->right==tree)
			{
				node *temp;
				temp=delt->right->right;
				while(temp->left!=NULL)
					temp=temp->left;
				cout<<"\ntemp:"<<temp->info<<endl;

				if((temp->right)!=(NULL))
				{
					delt->right->right->left=temp->right;
				}
				temp->right=delt->right->right;
				
				delete delt->right;
				delt->right=temp;
				
			}
			return found;
		}
	}

	if(tree!=NULL)
	{
		delt=tree;
		del(tree->left,x);
		delt=tree;
		del(tree->right,x);
	}
	return found;
}

int main()
{
	int n;
	cout<<"Enter no. of Elements:";

	cin>>n;
	int a[n];
	cout<<"\nEnter Elements:\n";
	root=NULL;
	//t=root;
	for (int i = 0; i <n ; i++)
	{
		cin>>a[i];
		//add(a[i]);
		add2(a[i],root);
	}
	cout<<"\n";


	inorder2(root);

	cout<<"\nINORDER\n -------";
	inorder(root);
	t->thread=t;


	found=false;
	int x;
	cout<<"\n Enter value to be Deleted:";
	cin>>x;
	if(del(root,x))
		cout<<"\nNode Deleted!!\n";
	else
		cout<<"\nNode Not found!!\n";
	
	inorder2(root);

	return 0;
}
