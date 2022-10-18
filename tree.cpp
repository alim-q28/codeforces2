#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
		int data;
		node* lc=NULL;
		node *rc=NULL;
		
		node(int n)
		{
			data=n;
		}
};

node *root=NULL;

void create()
{
	cout<<"Enter root value: ";
	int n;
	cin>>n;
	root=new node(n);
	queue<node*> q;
	q.push(root);
	while(q.size()!=0)
	{
		node* nd=q.front();
		q.pop();
		cout<<"Enter left child of "<<nd->data<<": ";
		cin>>n;
		if(n!=-1)
		{
		nd->lc=new node(n);
		q.push(nd->lc);	
		}
		cout<<"Enter right child of "<<nd->data<<": ";
		cin>>n;
		if(n!=-1)
		{
		nd->rc=new node(n);
		q.push(nd->rc);	
		}
	}
}

void preorder(node *t)
{
	if(t==NULL)
	return;
	cout<<t->data<<" ";
	preorder(t->lc);
	preorder(t->rc);
}

int height(node *t)
{
	if(t==NULL)
	return 0;
	return 1+max(height(t->lc),height(t->rc));
}

int diameter(node *t)
{
	if(t==NULL)
	return 0;
	int o1=1+height(t->lc)+height(t->rc);
	int o2=diameter(t->lc);
	int o3=diameter(t->rc);
	return max(o1,max(o2,o3));
}

int leaf(node *t)
{
	if(t==NULL)
	return 0;
	if(t->lc==NULL and t->rc==NULL)
	return 1;
	return leaf(t->lc)+leaf(t->rc);	
}

int nodes(node *t)
{
	if(t==NULL)
	return 0;
	return 1+nodes(t->lc)+nodes(t->rc);
}

int main()
{
	create();
	preorder(root);
	cout<<endl<<"height is "<<height(root);
	cout<<endl<<"diameter is "<<diameter(root);
	cout<<endl<<"no of leaf nodes are "<<leaf(root);
	cout<<endl<<"no of nodes are "<<nodes(root);
}
