//I have represented double black node with a node who's value/info/key is -1
//Tested example from website https://www.csee.umbc.edu/courses/undergraduate/341/spring04/hood/notes/red_black/
#include <iostream>
using namespace std;
struct node{				//node structure
	int info;
	node* left;				//left pointer
	node* right;			//right pointer
	node* p;				//parent
	bool red;				//boolean to determine whether node is black(red=false) or red(red=true)
};

node* root=new node;		//root node
node* lastnode=new node;	//to find last attached node
node* temp=new node;

node* newnode(int key){		//to create a new node with value/key
	node* p=new node;	p->info=key;	p->left=NULL;	p->right=NULL;	p->red=true;	p->p=NULL;
	return p;
}
void rotleft(node* x){		//left rotation of node x
	node* y=new node;
	y=x->right;
	if(y!=NULL && y->left)
	{
		x->right=y->left;
		if(y->left->p!=NULL)
			y->left->p=x;
	}
	else
		x->right=NULL;

	if(y!=NULL)
		y->p=x->p;

	if (x->p==NULL)
		root=y;

	else if(x->p->left && x==x->p->left)
		x->p->left=y;

	else if(x->p->right && x==x->p->right)
		x->p->right=y;

	y->left=x;
	x->p=y;
	// y=x;
}
void rotright(node* y){		//right rotation of node x
	node* x=new node;
	x=y->left;
	if(x!=NULL){
		y->left=x->right;
		if(x->right)
			x->right->p=y;
		x->p=y->p;
	}
	if (y->p==NULL)
		root=x;

	else if (y->p!=NULL && y->p->left && y==y->p->left)
		y->p->left=x;

	else if (y->p!=NULL && y->p->right && y==y->p->right)
		y->p->right=x;

	x->right=y;
	y->p=x;
}
node* treemin(node* root){	//to find leftmost node from a root
	while (root->left){
		if(root->left->info!=-1)
			root=root->left;
		else
			break;
	}
	return root;
}
node* treesuc(node* x){		//to find successor of node x according to inorder traversal
	if(x->right){
		return treemin(x);
	}
	node* y=new node;
	y=x->p;
	while(y && x==y->right){
		x=y;
		if(y->p!=NULL)
			y=y->p;
	}
	return y;
}
void delfix(node* x){		//to fix/balance rb tree after deletion of a node
	node* w=new node;
	while(x!=root && x->red==false){
		if(x==x->p->left){
			w=x->p->right;
			if(w!=NULL){
				if(w->red==true){
					w->red=false;
					x->p->red=true;
					rotleft(x->p);
					w=x->p->right;
				}
				if((w->left==NULL || w->left->red==false )&& (w->right==NULL || w->right->red==false)){
					w->red=true;
					x=x->p;
				}
				else if( w->right && w->right->red==false){
					w->left->red=false;
					w->red=true;
					rotright(w);
					if(x->p)
						w=x->p->right;
				}
				else{
					w->red=x->p->red;
					x->p->red=false;
					if(w->right)
						w->right->red=false;
					rotleft(x->p);
					x=root;
				}
			}
		}
		else{
			if(x==x->p->right){
				w=x->p->left;
				if(w!=NULL){
					if(w->red==true){
						w->red=false;
						x->p->red=true;
						rotright(x->p);
						w=x->p->left;
					}
					if((w->left==NULL || w->left->red==false )&& (w->right==NULL || w->right->red==false)){
						w->red=true;
						x=x->p;
					}
					else if(w->left!=NULL && w->left->red==false){
						w->right->red=false;
						w->red=true;
						rotleft(w);
						if(x->p)
							w=x->p->left;
					}
					else{
						w->red=x->p->red;
						x->p->red=false;
						w->left->red=false;
						rotright(x->p);
						x=root;
					}
				}
			}
		}
	}
	x->red=false;
}
node* del(node* z){			//to delete node from rb tree
	if(root==NULL){
		cout<<"\nPlease create tree first";
		return NULL;
	}
	node* y=new node;
	node* x=new node;
	if((z->left==NULL || z->left->info==-1) || (z->right==NULL || z->right->info==-1))
		y=z;

	else
		y=treesuc(z);		//to find successor of node to be deleted

	if(y->left && y->left->info!=-1)
		x=y->left;

	else
		x=y->right;


	if(x==NULL){		//creation of double black node and it is assigned value -1
		x=newnode(-1);
		x->red=false;
	}


	x->p=y->p;

	if(y->p==NULL)
		root=x;

	else if(y==y->p->left)
		y->p->left=x;

	else
		y->p->right=x;


	if(y!=z)
		z->info=y->info;


	if (y->red==false)
		if(x->info!=-1)
			delfix(x);
	return y;
}
void colfix(node* x){		//to fix/balance rb tree after insertion of a node
	node* temp=new node;
	while(x->p!=NULL && x->p->red==true){
		if(x->p==(x->p->p->left)){
			temp=x->p->p->right;
			if(temp!=NULL && temp->red==true){
				x->p->red=false;
				temp->red=false;
				if(x->p->p!=NULL){
					x->p->p->red=true;
					x=x->p->p;
				}
			}
			else if(x==x->p->right){
				x=x->p;
				rotleft(x);
				// x->p->red=false;
				// if(x->p->p){
				// 	x->p->p->red=true;
				// 	rotright(x->p->p);
				// }
			}
			else if(x==x->p->left){

				x->p->red=false;
				x->p->p->red=true;
				rotright(x->p->p);
			}
		}
		else{
			temp=x->p->p->left;
			if( temp!=NULL && temp->red==true ){
				x->p->red=false;
				temp->red=false;
				if(x->p->p!=NULL)
					x->p->p->red=true;
					x=x->p->p;
			}
			else if(x==x->p->left){
				x=x->p;
				rotright(x);

				// if(x->p){
				// 	x->p->red=false;
				// 	if(x->p->p)
				// 		x->p->p->red=true;
				// }
				// if(x->p->p)
				// 	rotleft(x->p->p);
			}
			else if(x==x->p->right){

				x->p->red=false;
				x->p->p->red=true;
				rotleft(x->p->p);
			}
		}
	}
	root->red=false;
}
void add(node *t2,int x){	//to insert a node in rb tree
	if(root==NULL)
	{
		root=newnode(x);
		root->red=false;
		return;
	}
	else
	{
		if(t2->info>x)
		{
			if(t2->left!=NULL)
				add(t2->left,x);
			else{
				t2->left=newnode(x);
				t2->left->p=t2;
				// lastnode=t2->left;
				if(t2->left->p->p!=NULL){
					colfix(t2->left);
				}
			}
		}
		else if(t2->info<x)
		{
			if(t2->right!=NULL)
				add(t2->right,x);
			else{
				t2->right=newnode(x);
				t2->right->p=t2;
				// lastnode=t2->right;
				if(t2->right->p->p!=NULL){
					colfix(t2->right);
				}
			}
		}
	}
}
void inorder(node* temp){	//inorder traversal of rb tree
	if(root==NULL){
		cout<<"\n Create tree first";
		return;
	}
	else if(root->info==-1){
		cout<<"\n Create tree first";
		root=NULL;
		return;
	}

	if(temp==NULL)
		return;

	inorder(temp->left);
	if(temp==root)
		cout<<"\nroot: "<<temp->info;
	else if(temp->info==-1)
		return;

	else
		cout<<"\n"<<temp->info;

	if(temp->red )
		cout<<" color:red";
	else
		cout<<" color:black";
	inorder(temp->right);
}
node* found=NULL;			//to save found/searched node
node* search(node* temp,int x){		//to search a node in rb tree

	if(root==NULL){
		return NULL;
	}
	else if(root->info==-1){
		return NULL;
	}
	if(temp==NULL)
		return temp;

	search(temp->left,x);
	if(temp->info==x){
		found=temp;
	}
	search(temp->right,x);
	return found;
}
int main()					// main driver function
{

	root=NULL;
	temp=NULL;
	char ch='y';

	int x=0;
	while(ch=='y'){
		cout<<"\nMenu For RB-tree Actions:\n1.Insertion\n2.Deletion\n3.Search\n\nEnter your Choice:";
		int choice=0;
		cin>>choice;		//input for action
		switch(choice)
		{
			case 1:{
				int n=0;
				cout<<"Enter no. of elements:";
				cin>>n;
				cout<<"\nEnter elements:";
				for (int i = 0; i < n; ++i)
				{
					cin>>x;
					add(root,x);
				}
				break;
			}
			case 2:{

				cout<<"\nEnter node to be deleted:";
				cin>>x;
				temp=search(root,x);
				if(temp)
					cout<<"\nFound:"<<temp->info;
				node* deleted=NULL;
				if(temp)
					deleted=del(temp);
				if(deleted!=NULL)
				{
					if(deleted!=root){
						cout<<"\nNode deleted:"<<deleted->info;
					}
					else if(deleted==root){
						cout<<"\nRoot Deleted!";
						root=NULL;
					}
					delete deleted;
				}
				break;
			}
			case 3:{
				cout<<"\nEnter node to be searched:";
				cin>>x;
				temp=search(root,x);
				if(temp){
					cout<<"\nFound:"<<temp->info;
					if(temp->red==false)
						cout<<" color:black\n";
					else
						cout<<" color:red\n";
				}
				else
					cout<<"\nNode not found\n";
				break;
			}

			default: cout<<"\nWrong input";
		}
		cout<<"\n	Status after action(s)	";
		inorder(root);
		cout<<"\nDo wish to continue? (y/n)";
		cin>>ch;
	}
}
