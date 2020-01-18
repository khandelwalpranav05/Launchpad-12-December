#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* buildTree(node* root){
	int data;
	cin>>data;

	if(data==-1){
		return NULL;
	}

	if(root==NULL){
		root = new node(data);
	}

	root->left = buildTree(root->left);
	root->right = buildTree(root->right);

	return root;
}

void preOrder(node*root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(node*root){
	if(root==NULL){
		return;
	}

	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

int countNodes(node* root){
	if(root==NULL){
		return 0;
	}

	int leftCount = countNodes(root->left);
	int rightCount = countNodes(root->right);

	int totalCount = leftCount + 1 + rightCount;
	return totalCount;
}

// L R N
void postOrder(node* root){
	if(root==NULL){
		return;
	}

	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

int sumOfNodes(node* root){
	if(root==NULL){
		return 0;
	}

	int leftSum = sumOfNodes(root->left);
	int rightSum = sumOfNodes(root->right);

	int totalSum = leftSum + root->data + rightSum;
	return totalSum;
}

int height(node* root){



}

bool search(node* root,int item){



}

int main(){

	node* root = NULL;
	root = buildTree(root);

	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	postOrder(root);
	cout<<endl;

	// cout<<countNodes(root)<<endl;
	// cout<<sumOfNodes(root)<<endl;

	return 0;
}

// Input Tree
// 4 2 1 -1 -1 3 -1 -1 6 5 -1 -1 7 -1 -1

// 1 -1 2 3 -1 5 6 -1 -1 7 -1 -1 4 -1 -1