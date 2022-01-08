#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
   int val;
   TreeNode *left=NULL;
   TreeNode *right=NULL;
};

TreeNode* my_bst(TreeNode* root,int key){  //constructing bst
    if(root==NULL){ //when we reach NULL means the new node has to be inserted here
        TreeNode *new_node=new TreeNode;
        new_node->val=key;
        return new_node;
    }
    if(key>root->val)
        root->right=my_bst(root->right,key);
    else
        root->left=my_bst(root->left,key);
    return root;
}
void inorder(TreeNode* root){  //inorder for a bst is sorted in ascending order
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main() {
    int n;
    cin>>n;
	int arr[n];
	TreeNode* root=NULL;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	    root=my_bst(root,arr[i]);
	}
	inorder(root);
	return 0;
}
