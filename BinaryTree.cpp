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
	int d;
	cout<<"Enter Data: "<<endl;
	cin>>d;
	if(d==1)
	return NULL;
	
	treeNode<int>* root=new treeNode<int>(d);
	
	root->left=takeInput();
	root->right=takeInput();
	
	return root;
}

void print(treeNode<int>* root)
{
	if(root==NULL)
		return;
	
	cout<<root->data<<":";
	if(root->left!=NULL)
	{
		cout<<"L"<<root->left->data;
	}
	if(root->right!=NULL)
	{
		cout<<"R"<<root->right->data;
	}
	
	cout<<endl;
	
	print(root->left);
	print(root->right);
}

int main()
{
	treeNode<int>* root=takeInput();
	print(root);
	
	return 0;
}
