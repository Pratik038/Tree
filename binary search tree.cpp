#include<iostream>
using namespace std;

struct BstNode{
	int data;
	BstNode *left;
	BstNode *right;
};

BstNode* createNode(int data){
	BstNode *temp = new BstNode;
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

BstNode* insert(BstNode* root,int data){
	
	if(root==NULL) //Empty tree
		root=createNode(data);
	else if(data <= root->data)
		root->left=insert(root->left,data);
	else 
		root->right=insert(root->right,data);
	return root;
}

bool search(BstNode* root,int sk){
	if(root==NULL) return false;
	
	else if(root->data ==sk) return true;
	
	else if(sk <= root->data)	return search(root->left,sk);
	
	else return search(root->right,sk);
}

int main(){
	BstNode *root=NULL;//creating an empty tree.
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	
	int n;
	cout<<"Enter a number to be searched:";
	cin>>n;
	if(search(root,n)) cout<<"Found";
	else cout<<"Not Found";
	return 0;
}
