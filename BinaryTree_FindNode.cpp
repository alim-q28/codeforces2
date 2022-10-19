#include<bits/stdc++.h>
using namespace std;

template <typename T>
class treeNode
{
	public:
	int data;
	treeNode<int>* left;
	treeNode<int>* right;
	
	treeNode(int data)
	{
		this->data=data;
		left=NULL;
		right=NULL;
	}		
	
	~treeNode()
	{
		delete left;
		delete right;
	}
};

treeNode<int>* takeInput()
{
	queue<treeNode<int>*> q;
	int d;
	cout<<"Enter Root Data: "<<endl;
	cin>>d;
	if(d==-1)
	return NULL;
	treeNode<int>* root=new treeNode<int>(d);
	q.push(root);
	
	while(!q.empty())
	{
		treeNode<int>* f;
		f=q.front();
		q.pop();
		
		int l,r;
		
		cout<<"Enter left child of "<<f->data<<": ";
		cin>>l;
		cout<<"Enter right child of "<<f->data<<": ";
		cin>>r;
		
		if(l!=-1)
		{
			treeNode<int>* child=new treeNode<int>(l);
			f->left=child;
			q.push(child);
		}
		
		if(r!=-1)
		{
			treeNode<int>* child=new treeNode<int>(r);
			f->right=child;
			q.push(child);
		}
			
	} 
	
	return root;
}

bool check(treeNode<int>* root, int x)
{
	if(root==NULL)
	return false;
	
	if(root->data==x)
	return true;
	
	queue<treeNode<int>*> q;
	q.push(root);
	
	while(!q.empty())
	{
		treeNode<int>* f;
		f=q.front();
		
		if(f->data==x)
		return true;
		
		q.pop();
		
		
		if(f->left!=NULL)
		{
			q.push(f->left);
		}
		
		if(f->right!=NULL)
		{
			q.push(f->right);
		}
	} 
	
	return false;
}

int main()
{
	treeNode<int>* root=takeInput();
	int x;
	cout<<"Enter key: ";
	cin>>x;
	int c=check(root,x);
	if(c==1)
	cout<<"True";
	else
	cout<<"False";
	return 0;
}
