//We are given an array using which we have to create a tree in level order traversal.
//left child of node will be arr[2*i+1] and right child will be arr[2*i+2]

#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left=NULL,*right=NULL;
};
node* my_tree(int arr[],int i,int n){  //create the tree in levelorder from given array using recursion
    if(i>n)
    return NULL;
    node* root=new node();
    root->val = arr[i];
    root->left=my_tree(arr,2*i+1,n);
    root->right=my_tree(arr,2*i+2,n);
    return root;
}
void inorder(node* root){  //to get the inorder traversal of formed tree
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}
int main() {
    int n;
    cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	node* root=my_tree(arr,0,n-1);
	inorder(root);
	return 0;
}