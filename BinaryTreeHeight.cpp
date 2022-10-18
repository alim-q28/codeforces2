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

int height(treeNode<int>* root)
{
	if(root==NULL)
		return 0;
		
	int lh=height(root->left);
	int rh=height(root->right);
	
	if(lh>rh)
	return lh+1;
	
	else
	return rh+1;
}

int main()
{
	treeNode<int>* root=takeInput();
	cout<<height(root);
	
	return 0;
}
