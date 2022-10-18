#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
	public:
	T data;
	BinaryTreeNode* left;
	BinaryTreeNode* right;

	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

	~BinaryTreeNode() {
		delete left;
		delete right;
	}
};

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) 
{
	if (root == NULL) {
		return NULL;
	}
	
	if (root->data == data) {
		vector<int>* output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	
	vector<int>* leftOutput = getRootToNodePath(root->left, data);
	if (leftOutput != NULL) {
		leftOutput->push_back(root->data);
		return leftOutput;
	}

	vector<int>* rightOutput = getRootToNodePath(root->right, data);
	if (rightOutput != NULL) {
			rightOutput->push_back(root->data);
			return rightOutput;
	}
	
	else 
	{
		return NULL;
	}
}

void print(vector<int>* V)
{
	int n=V->size();
	for(int i=0;i<n;i++)
	{
		cout<<V->at(i)<<" ";
	}
	return;
}

int main() 
{
    BinaryTreeNode<int>* root = takeInputLevelWise();
    int x;
    cout<<"Enter key: "<<endl;
    cin>>x;
    vector<int>* V=getRootToNodePath(root,x);
    print(V);
    delete root;
}
